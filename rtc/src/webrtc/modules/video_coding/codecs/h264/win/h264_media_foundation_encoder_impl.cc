#include <chrono>
#include <thread>
#include <windows.h>
#include <objbase.h>
#include <mfapi.h>
#include <VersionHelpers.h>
#include <mfapi.h>
#include <mferror.h>
#include <codecapi.h>
#include "webrtc/modules/video_coding/codecs/h264/win/h264_media_foundation_encoder_impl.h"
#include "webrtc/modules/video_coding/codecs/h264/win/mfhelper.h"
#include "webrtc/modules/video_coding/codecs/h264/win/macros_utils.h"
#include "webrtc/base/checks.h"
#include "webrtc/base/logging.h"
#include "webrtc/common_video/libyuv/include/webrtc_libyuv.h"
#include "webrtc/media/base/mediaconstants.h"
#include "webrtc/system_wrappers/include/metrics.h"
#include "webrtc/common_video/h264/h264_common.h"

namespace webrtc
{
    constexpr int TIME_UNIT_IN_MF_PER_SECOND = 10 * 1000 * 1000;

	static FrameType ConvertToVideoFrameType(H264::NaluType type)
	{
		switch (type) {
		case H264::kIdr:
		case H264::kI:
		case H264::kSps:
		case H264::kPps:
			return kVideoFrameKey;
		case H264::kB:
			break;
		default:
			return kVideoFrameDelta;
		}
		RTC_NOTREACHED() << "Unexpected/invalid frame type: " << type;
		return kEmptyFrame;
	}

    static void RtpFragmentize(EncodedImage* encoded_image,
        std::unique_ptr<uint8_t[]>* encoded_image_buffer,
        const VideoFrameBuffer& frame_buffer,
        IMFMediaBuffer* imb,
        RTPFragmentationHeader* frag_header)
    {
        DWORD len = 0, maxLen = 0;
        imb->GetCurrentLength(&len);
        size_t required_size = len;

        if (encoded_image->_size < required_size) {
            encoded_image->_size =
                CalcBufferSize(kI420, frame_buffer.width(), frame_buffer.height());
            if (encoded_image->_size < required_size) {
                LOG(LS_WARNING) << "Encoding produced more bytes than the original image "
                    << "data! Original bytes: " << encoded_image->_size
                    << ", encoded bytes: " << required_size << ".";
                encoded_image->_size = required_size;
            }
            encoded_image->_buffer = new uint8_t[encoded_image->_size];
            encoded_image_buffer->reset(encoded_image->_buffer);
        }

        struct nalInfo
        {
            size_t offset;
            size_t len;
        };
		static const unsigned char AUD [] = { 0x0,0x0,0x0,0x1,0x9};
		const static unsigned int AUD_SIZE = sizeof(AUD) + 1;
        std::vector<nalInfo> nals;
		BYTE* buffer = nullptr;
        imb->Lock(&(buffer), &maxLen, &len);
		if (0 == memcmp(AUD, buffer, sizeof(AUD) )) {
			buffer += AUD_SIZE;
			len -= AUD_SIZE;
		}
		memcpy(encoded_image->_buffer, buffer, len);
        encoded_image->_length = len;
        uint8_t *buf = encoded_image->_buffer;
        nalInfo info;
        size_t lastOffset = 0;
        for (auto i = 0; i < len; i++) {
            if (0 == buf[i] && 0 == buf[i+1]) {
                if (1 == buf[i + 2]) {
					if (0 != lastOffset) {
						info.len = i - lastOffset;
						nals.push_back(info);
					}
                    info.offset = i + 3;
                    

                    lastOffset = info.offset;
                } else if (0 == buf[i + 2] && 1 == buf[i + 3]) {
					if (0 != lastOffset) {
						info.len = i - lastOffset;
						nals.push_back(info);
					}
                    info.offset = i + 4;
                    
					i++;

                    lastOffset = info.offset;
                }
            }
        }

        // The last nal
        info.len = len - info.offset;
        nals.push_back(info);

        imb->Unlock();

        frag_header->VerifyAndAllocateFragmentationHeader(nals.size());

        for (auto i = 0; i < nals.size(); i++) {
            frag_header->fragmentationOffset[i] = nals[i].offset;
            frag_header->fragmentationLength[i] = nals[i].len;
        }
		H264::NaluType nalu_type = H264::ParseNaluType(encoded_image->_buffer[4]);
		
		encoded_image->_frameType = ConvertToVideoFrameType(nalu_type);
    }

    

    H264MediaFoundationEncoderImpl::H264MediaFoundationEncoderImpl(const cricket::VideoCodec& codec)
        :encoder_(nullptr),
        codecApi_(nullptr),
        eventGenerator_(nullptr),
        width_(0),
        height_(0),
        max_frame_rate_(0.0f),
        target_bps_(0),
        max_bps_(0),
        mode_(kRealtimeVideo),
        frame_dropping_on_(false),
        key_frame_interval_(0),
        packetization_mode_(H264PacketizationMode::NonInterleaved),
        max_payload_size_(0),
        number_of_cores_(0),
        encoded_image_callback_(nullptr),
        input_frame_(nullptr),
		outputRequests_(0),
		inputRequests_(0)
    {
        RTC_CHECK(cricket::CodecNamesEq(codec.name, cricket::kH264CodecName));
        std::string packetization_mode_string;
        if (codec.GetParam(cricket::kH264FmtpPacketizationMode, &packetization_mode_string) &&
            packetization_mode_string == "1") {
            packetization_mode_ = H264PacketizationMode::NonInterleaved;
        }
    }

    H264MediaFoundationEncoderImpl::~H264MediaFoundationEncoderImpl()
    {
        Release();
    }

    int32_t H264MediaFoundationEncoderImpl::InitEncode(const VideoCodec* codec_settings, int32_t number_of_cores, size_t max_payload_size)
    {
        if (!codec_settings ||
            codec_settings->codecType != kVideoCodecH264) {
            return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
        }
        if (codec_settings->maxFramerate == 0) {
            return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
        }
        if (codec_settings->width < 1 || codec_settings->height < 1) {
            return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
        }

        int32_t release_ret = Release();
        if (release_ret != WEBRTC_VIDEO_CODEC_OK) {
            return release_ret;
        }
        RTC_DCHECK(!encoder_);

        MfHelper::InitSysEvent();

        // Create encoder.
        RTC_DCHECK(S_OK == MfHelper::createHardwareH264Encoder(encoder_));

        //Init codecAPI
        {
            HRESULT hr = encoder_->QueryInterface(&codecApi_);
            VARIANT var;

            var.vt = VT_UI4;
            var.ulVal = eAVEncCommonRateControlMode_Quality;

            EXECUTE_IF_SUCCEEDED(hr, codecApi_->SetValue(&CODECAPI_AVEncCommonRateControlMode, &var));

            VARIANT var1;
            var1.vt = VT_BOOL;
            var1.ullVal = VARIANT_TRUE;
            EXECUTE_IF_SUCCEEDED(hr, codecApi_->SetValue(&CODECAPI_AVLowLatencyMode, &var1));

            RTC_DCHECK(S_OK == hr);
        }

        //Init Event Generator
        RTC_CHECK(S_OK == encoder_->QueryInterface(&eventGenerator_));

        number_of_cores_ = number_of_cores;
        // Set internal settings from codec_settings
        width_ = codec_settings->width;
        height_ = codec_settings->height;
        max_frame_rate_ = static_cast<float>(codec_settings->maxFramerate);
        mode_ = codec_settings->mode;
        frame_dropping_on_ = codec_settings->H264().frameDroppingOn;
        key_frame_interval_ = codec_settings->H264().keyFrameInterval;
        max_payload_size_ = max_payload_size;

        // Codec_settings uses kbits/second; encoder uses bits/second.
        max_bps_ = codec_settings->maxBitrate * 1000;
        if (codec_settings->targetBitrate == 0)
            target_bps_ = codec_settings->startBitrate * 1000;
        else
            target_bps_ = codec_settings->targetBitrate * 1000;

        // Initialize encoded image. Default buffer size: size of unencoded data.
        encoded_image_._size =
            CalcBufferSize(kNV12, codec_settings->width, codec_settings->height);
        encoded_image_._buffer = new uint8_t[encoded_image_._size];
        encoded_image_buffer_.reset(encoded_image_._buffer);
        encoded_image_._completeFrame = true;
        encoded_image_._encodedWidth = 0;
        encoded_image_._encodedHeight = 0;
        encoded_image_._length = 0;

        RTC_DCHECK(ApplySettings());
        RTC_DCHECK(S_OK == encoder_->ProcessMessage(MFT_MESSAGE_NOTIFY_BEGIN_STREAMING, NULL));
        RTC_DCHECK(S_OK == encoder_->ProcessMessage(MFT_MESSAGE_NOTIFY_START_OF_STREAM, NULL));

        return WEBRTC_VIDEO_CODEC_OK;
    }

    int32_t H264MediaFoundationEncoderImpl::RegisterEncodeCompleteCallback(EncodedImageCallback* callback)
    {
        encoded_image_callback_ = callback;
        return WEBRTC_VIDEO_CODEC_OK;
    }

    int32_t H264MediaFoundationEncoderImpl::Release()
    {
        if (encoder_ && codecApi_ && eventGenerator_) {
            encoder_->ProcessMessage(MFT_MESSAGE_NOTIFY_END_OF_STREAM, NULL);
            encoder_->ProcessMessage(MFT_MESSAGE_COMMAND_DRAIN, NULL);
            while (ProcessOutput()) {
                std::this_thread::sleep_for(std::chrono::microseconds(5));
            }
        }

        ComPtr<IMFShutdown> shutdown;
        if (encoder_ && SUCCEEDED(encoder_->QueryInterface(&shutdown))) {
            shutdown->Shutdown();
            encoder_ = nullptr;
            codecApi_ = nullptr;
            eventGenerator_ = nullptr;
        }

        encoded_image_._buffer = nullptr;
        encoded_image_buffer_.reset();
        return WEBRTC_VIDEO_CODEC_OK;
    }

    int32_t H264MediaFoundationEncoderImpl::Encode(const VideoFrame& frame, const CodecSpecificInfo* codec_specific_info, const std::vector<FrameType>* frame_types)
    {
        if (!IsInitialized()) {
            return WEBRTC_VIDEO_CODEC_UNINITIALIZED;
        }
        if (!encoded_image_callback_) {
            LOG(LS_WARNING) << "InitEncode() has been called, but a callback function "
                << "has not been set with RegisterEncodeCompleteCallback()";
            return WEBRTC_VIDEO_CODEC_UNINITIALIZED;
        }

        bool force_key_frame = false;
        if (frame_types != nullptr) {
            // We only support a single stream.
            RTC_DCHECK_EQ(frame_types->size(), 1);
            // Skip frame?
            if ((*frame_types)[0] == kEmptyFrame) {
                return WEBRTC_VIDEO_CODEC_OK;
            }
            // Force key frame?
            force_key_frame = (*frame_types)[0] == kVideoFrameKey;
        }

        if (force_key_frame) {
            if (IsWindows8OrGreater()) {
                VARIANT var;
                var.vt = VT_UI4;
                var.ulVal = 1;
                codecApi_->SetValue(&CODECAPI_AVEncVideoForceKeyFrame, &var);
            }
        }

        ProcessInput(frame);

        return  WEBRTC_VIDEO_CODEC_OK;
    }

    int32_t H264MediaFoundationEncoderImpl::SetChannelParameters(uint32_t packet_loss, int64_t rtt)
    {
		return  WEBRTC_VIDEO_CODEC_OK;
    }

    int32_t H264MediaFoundationEncoderImpl::SetRates(uint32_t bitrate, uint32_t framerate)
    {
        throw std::logic_error("The method or operation is not implemented.");
    }

    int32_t H264MediaFoundationEncoderImpl::SetRateAllocation(
        const BitrateAllocation& bitrate_allocation, uint32_t framerate)
    {
        if (bitrate_allocation.get_sum_bps() <= 0 || framerate <= 0)
            return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;

        target_bps_ = bitrate_allocation.get_sum_bps();
        max_frame_rate_ = static_cast<float>(framerate);

        ComPtr<IMFMediaType> mediaType;

        HRESULT hr = S_OK;
        EXECUTE_IF_SUCCEEDED(hr, encoder_->GetInputAvailableType(0, 0, &mediaType));
        EXECUTE_IF_SUCCEEDED(hr, mediaType->SetUINT32(MF_MT_AVG_BITRATE, target_bps_));
        EXECUTE_IF_SUCCEEDED(hr, MFSetAttributeRatio(mediaType, MF_MT_FRAME_RATE, max_frame_rate_, 1));
        EXECUTE_IF_SUCCEEDED(hr, encoder_->SetInputType(0, mediaType, 0));
        
        return WEBRTC_VIDEO_CODEC_OK;
    }

    VideoEncoder::ScalingSettings H264MediaFoundationEncoderImpl::GetScalingSettings() const
    {
        return VideoEncoder::ScalingSettings(true);
    }

    const char* H264MediaFoundationEncoderImpl::ImplementationName() const
    {
        return "Microsoft Media Foundation H264 Encoder.";
    }

    bool H264MediaFoundationEncoderImpl::IsInitialized()
    {
        return encoder_ != nullptr;
    }

    bool H264MediaFoundationEncoderImpl::ApplySettings()
    {
        eAVEncH264VProfile profile;
        if (IsWindows8OrGreater()) {
            profile = eAVEncH264VProfile_High;
        } else {
            profile = eAVEncH264VProfile_Main;
        }

        HRESULT hr = S_OK;
        ComPtr<IMFMediaType> inputMediaType = nullptr;
        ComPtr<IMFMediaType> outputMediaType = nullptr;

        EXECUTE_IF_SUCCEEDED(hr, MFCreateMediaType(&outputMediaType));
        EXECUTE_IF_SUCCEEDED(hr, outputMediaType->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Video));
        EXECUTE_IF_SUCCEEDED(hr, outputMediaType->SetGUID(MF_MT_SUBTYPE, MFVideoFormat_H264));
        EXECUTE_IF_SUCCEEDED(hr, outputMediaType->SetUINT32(MF_MT_AVG_BITRATE, target_bps_));
        EXECUTE_IF_SUCCEEDED(hr, MFSetAttributeRatio(outputMediaType, MF_MT_FRAME_RATE, max_frame_rate_, 1));
        EXECUTE_IF_SUCCEEDED(hr, MFSetAttributeSize(outputMediaType, MF_MT_FRAME_SIZE, width_, height_));
        EXECUTE_IF_SUCCEEDED(hr, outputMediaType->SetUINT32(MF_MT_SAMPLE_SIZE, encoded_image_._size));
        EXECUTE_IF_SUCCEEDED(hr, outputMediaType->SetUINT32(MF_MT_INTERLACE_MODE, MFVideoInterlace_Progressive));
        EXECUTE_IF_SUCCEEDED(hr, MFSetAttributeRatio(outputMediaType, MF_MT_PIXEL_ASPECT_RATIO, 1, 1));
        EXECUTE_IF_SUCCEEDED(hr, outputMediaType->SetUINT32(MF_MT_MPEG2_PROFILE, profile));
        EXECUTE_IF_SUCCEEDED(hr, outputMediaType->SetUINT32(MF_MT_MPEG2_LEVEL, (UINT32)-1));
        EXECUTE_IF_SUCCEEDED(hr, encoder_->SetOutputType(0, outputMediaType, 0));
        EXECUTE_IF_SUCCEEDED(hr, MFCreateMediaType(&inputMediaType));
        EXECUTE_IF_SUCCEEDED(hr, inputMediaType->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Video));
        EXECUTE_IF_SUCCEEDED(hr, inputMediaType->SetGUID(MF_MT_SUBTYPE, MFVideoFormat_NV12));
        EXECUTE_IF_SUCCEEDED(hr, MFSetAttributeRatio(inputMediaType, MF_MT_FRAME_RATE, max_frame_rate_, 1));
        EXECUTE_IF_SUCCEEDED(hr, MFSetAttributeSize(inputMediaType, MF_MT_FRAME_SIZE, width_, height_));
        EXECUTE_IF_SUCCEEDED(hr, inputMediaType->SetUINT32(MF_MT_INTERLACE_MODE, MFVideoInterlace_Progressive));
        EXECUTE_IF_SUCCEEDED(hr, MFSetAttributeRatio(inputMediaType, MF_MT_PIXEL_ASPECT_RATIO, 1, 1));
        EXECUTE_IF_SUCCEEDED(hr, encoder_->SetInputType(0, inputMediaType, 0));

        return SUCCEEDED(hr);
    }

    bool H264MediaFoundationEncoderImpl::ProcessInput(const VideoFrame &frame)
    {
        HRESULT hr = S_OK;
        ComPtr<IMFSample> inputSample = nullptr;

        EXECUTE_IF_SUCCEEDED(hr, MfHelper::fillSampleWithI420(inputSample, frame, TIME_UNIT_IN_MF_PER_SECOND / max_frame_rate_));
        EXECUTE_IF_SUCCEEDED(hr, DrainEvents());

        input_frame_ = &frame;

        if (SUCCEEDED(hr)) {
            while (outputRequests_ > 0 && ProcessOutput());
        }

        if (SUCCEEDED(hr)) {
            while (0 == inputRequests_) {
                hr = DrainEvent();
                if (MF_E_NO_EVENTS_AVAILABLE == hr) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                    continue;
                }
                if (SUCCEEDED(hr)) {
                    while (outputRequests_ > 0 && ProcessOutput());
                }
            }
        }

        if (SUCCEEDED(hr)) {
            if (1 == inputRequests_ && inputSamples_.empty()) {
                --inputRequests_;
                return SUCCEEDED(encoder_->ProcessInput(0, inputSample, 0));
            }
            inputSamples_.push(inputSample);
            while (inputRequests_ > 0) {
                ComPtr<IMFSample> sample = inputSamples_.front();
                inputSamples_.pop();
                --inputRequests_;
                hr = encoder_->ProcessInput(0, sample, 0);
            }
        }

        return SUCCEEDED(hr);
    }

    bool H264MediaFoundationEncoderImpl::ProcessOutput()
    {
        ComPtr<IMFSample> outputSample = nullptr;
        ComPtr<IMFMediaBuffer> mediaBuffer = nullptr;
        ComPtr<IMFMediaType> outputMediaType = nullptr;
        MFT_OUTPUT_DATA_BUFFER outputBuffer = { 0 };
        MFT_OUTPUT_STREAM_INFO outputStream = { 0 };

        BYTE* buffer = nullptr;
        DWORD outputStatus = 0;
        DWORD bufferSize = 0;
        bool createSample = false;

        HRESULT hr = DrainEvents();

        if (SUCCEEDED(hr) && outputRequests_ == 0) {
            return false;
        }

        --outputRequests_;

        if (SUCCEEDED(hr)) {
            hr = encoder_->GetOutputStreamInfo(0, &outputStream);
        }

        if (SUCCEEDED(hr)) {
            createSample = !(outputStream.dwFlags & (MFT_OUTPUT_STREAM_PROVIDES_SAMPLES |
                MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES));

            if (createSample && MfHelper::createEmptySample(outputSample,
                mediaBuffer, outputStream.cbSize)) {
                outputBuffer.pSample = outputSample;
            }
        }

        while (SUCCEEDED(hr)) {
            hr = encoder_->ProcessOutput(0, 1, &outputBuffer, &outputStatus);
            if (outputBuffer.pEvents) {
                outputBuffer.pEvents->Release();
                outputBuffer.pEvents = NULL;
            }

            if (MF_E_TRANSFORM_NEED_MORE_INPUT == hr) {
                return false;
            }

            if (MF_E_TRANSFORM_STREAM_CHANGE == hr) {
                hr = encoder_->GetOutputAvailableType(0, 0, &outputMediaType);

                if (SUCCEEDED(hr)) {
                    hr = encoder_->SetOutputType(0, outputMediaType, 0);
                }
                if (SUCCEEDED(hr) && outputRequests_ > 0) {
                    --outputRequests_;
                    continue;
                } else {
                    return false;
                }
            }

            if (FAILED(hr)) {
                return false;
            }

            break;
        }

        if (!createSample) {
            outputSample = outputBuffer.pSample;
        }

        if (SUCCEEDED(hr)) {
            hr = outputSample->ConvertToContiguousBuffer(&mediaBuffer);
        }

        if (SUCCEEDED(hr)) {
            RTPFragmentationHeader frag_header;
            if (input_frame_) {
                rtc::scoped_refptr<VideoFrameBuffer> frame_buffer = input_frame_->video_frame_buffer();
                encoded_image_._encodedWidth = frame_buffer->width();
                encoded_image_._encodedHeight = frame_buffer->height();
                encoded_image_._timeStamp = input_frame_->timestamp();
                encoded_image_.ntp_time_ms_ = input_frame_->ntp_time_ms();
                encoded_image_.capture_time_ms_ = input_frame_->render_time_ms();
                encoded_image_.rotation_ = input_frame_->rotation();

                RtpFragmentize(&encoded_image_, &encoded_image_buffer_,
                    *frame_buffer, mediaBuffer, &frag_header);

            }

            if (encoded_image_._length > 0) {
                // Deliver encoded image.
                CodecSpecificInfo codec_specific;
                codec_specific.codecType = kVideoCodecH264;
                codec_specific.codecSpecific.H264.packetization_mode = packetization_mode_;
                encoded_image_callback_->OnEncodedImage(encoded_image_, &codec_specific,
                    &frag_header);

                // Parse and report QP.
                h264_bitstream_parser_.ParseBitstream(encoded_image_._buffer,
                    encoded_image_._length);
                h264_bitstream_parser_.GetLastSliceQp(&encoded_image_.qp_);
            }
            return WEBRTC_VIDEO_CODEC_OK;
        }

        if (outputBuffer.pSample) {
            outputBuffer.pSample->Release();
            outputBuffer.pSample = nullptr;
        }

        return SUCCEEDED(hr);
    }

    int32_t H264MediaFoundationEncoderImpl::DrainEvents()
    {
        HRESULT hr = S_OK;
        while (SUCCEEDED(hr)) {
            hr = DrainEvent();
        }

        if (MF_E_NO_EVENTS_AVAILABLE == hr) {
            hr = S_OK;
        }

        return hr;
    }

    int32_t H264MediaFoundationEncoderImpl::DrainEvent()
    {
        ComPtr<IMFMediaEvent> mediaEvent;
        MediaEventType eventType;
        HRESULT eventStatus;

        HRESULT hr = eventGenerator_->GetEvent(MF_EVENT_FLAG_NO_WAIT, &mediaEvent);

        if (SUCCEEDED(hr)) {
            hr = mediaEvent->GetType(&eventType);
        }

        if (SUCCEEDED(hr)) {
            hr = mediaEvent->GetStatus(&eventStatus);
        }

        if (SUCCEEDED(hr) && SUCCEEDED(eventStatus)) {
            if (METransformNeedInput == eventType) {
                ++inputRequests_;
            } else if (METransformHaveOutput == eventType) {
                ++outputRequests_;
            }
        }

        return hr;
    }

}
