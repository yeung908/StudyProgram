#include <codecapi.h>
#include <mferror.h>
#include <dshow.h>
#include <thread>
#include <chrono>
#include "webrtc/modules/video_coding/codecs/h264/win/h264_dxva_decoder_impl.h"
#include "webrtc/modules/video_coding/codecs/h264/win/mfhelper.h"
#include "webrtc/modules/video_coding/codecs/h264/win/macros_utils.h"
#include "webrtc/base/logging.h"
#include "webrtc/common_video/libyuv/include/webrtc_libyuv.h"
#include "webrtc/api/video/i420_buffer.h"
#include "libyuv/convert.h"

namespace webrtc
{

    H264DxvaDecoderImpl::H264DxvaDecoderImpl()
        : decoder_(nullptr), decoded_image_callback_(nullptr), time_stamp_(0)
    {}

    H264DxvaDecoderImpl::~H264DxvaDecoderImpl()
    {
        Release();
    }

    int32_t H264DxvaDecoderImpl::InitDecode(const VideoCodec* codec_settings, int32_t number_of_cores)
    {
        MfHelper::InitSysEvent();
        if (!InitializeDXVA2Decoder() || !InitializeInputOutputType()) {
            return WEBRTC_VIDEO_CODEC_UNINITIALIZED;
        }

        if (FAILED(decoder_->ProcessMessage(MFT_MESSAGE_NOTIFY_BEGIN_STREAMING, NULL))) {
            return WEBRTC_VIDEO_CODEC_UNINITIALIZED;
        }

        if (FAILED(decoder_->ProcessMessage(MFT_MESSAGE_NOTIFY_START_OF_STREAM, NULL))) {
            return WEBRTC_VIDEO_CODEC_UNINITIALIZED;
        }

        return WEBRTC_VIDEO_CODEC_OK;
    }

    int32_t H264DxvaDecoderImpl::Decode(const EncodedImage& input_image, bool missing_frames, const RTPFragmentationHeader* fragmentation, const CodecSpecificInfo* codec_specific_info /*= NULL*/, int64_t render_time_ms /*= -1*/)
    {
        if (!IsInitialized()) {
            return WEBRTC_VIDEO_CODEC_UNINITIALIZED;
        }
        if (!decoded_image_callback_) {
            LOG(LS_WARNING) << "InitDecode() has been called, but a callback function "
                "has not been set with RegisterDecodeCompleteCallback()";
            return WEBRTC_VIDEO_CODEC_UNINITIALIZED;
        }
        if (!input_image._buffer || !input_image._length) {
            return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
        }
        if (codec_specific_info &&
            codec_specific_info->codecType != kVideoCodecH264) {
            return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
        }

        // FFmpeg requires padding due to some optimized bitstream readers reading 32
        // or 64 bits at once and could read over the end. See avcodec_decode_video2.
        RTC_CHECK_GE(input_image._size, input_image._length +
            EncodedImage::GetBufferPaddingBytes(kVideoCodecH264));
        // "If the first 23 bits of the additional bytes are not 0, then damaged MPEG
        // bitstreams could cause overread and segfault." See
        // AV_INPUT_BUFFER_PADDING_SIZE. We'll zero the entire padding just in case.
        memset(input_image._buffer + input_image._length,
            0,
            EncodedImage::GetBufferPaddingBytes(kVideoCodecH264));
		bool ret = ProcessInput(input_image);
		if (ret) {
			ProcessOutput();
		}
        return  ret ? WEBRTC_VIDEO_CODEC_OK : WEBRTC_VIDEO_CODEC_ERR_REQUEST_SLI;
    }

    int32_t H264DxvaDecoderImpl::RegisterDecodeCompleteCallback(DecodedImageCallback* callback)
    {
        decoded_image_callback_ = callback;
        return WEBRTC_VIDEO_CODEC_OK;
    }

    int32_t H264DxvaDecoderImpl::Release()
    {
        HRESULT hr = S_OK;
        if (decoder_) {
            EXECUTE_IF_SUCCEEDED(hr, decoder_->ProcessMessage(MFT_MESSAGE_NOTIFY_END_OF_STREAM, NULL));
            EXECUTE_IF_SUCCEEDED(hr, decoder_->ProcessMessage(MFT_MESSAGE_COMMAND_DRAIN, NULL));
            while (ProcessOutput()) {
                std::this_thread::sleep_for(std::chrono::milliseconds(5));
            }
        }

        return WEBRTC_VIDEO_CODEC_OK;
    }

    const char* H264DxvaDecoderImpl::ImplementationName() const
    {
        return "DXVA h264 decoder";
    }

    bool H264DxvaDecoderImpl::InitializeDXVA2Decoder()
    {
		w_ = 1920;
		h_ = 1080;
        HRESULT hr = S_OK;
        UINT32 dxvaSupported = 0;
        ComPtr<IMFAttributes> attribute = nullptr;
        ComPtr<IDirect3DDeviceManager9> d3d9Manager;

        EXECUTE_IF_SUCCEEDED(hr, MfHelper::createSoftwareH264Decoder(decoder_));
        EXECUTE_IF_SUCCEEDED(hr, decoder_->GetAttributes(&attribute));
        EXECUTE_IF_SUCCEEDED(hr, attribute->GetUINT32(MF_SA_D3D_AWARE, &dxvaSupported));
        EXECUTE_IF_SUCCEEDED(hr, [&dxvaSupported] { return dxvaSupported ? S_OK : S_FALSE; }());
        EXECUTE_IF_SUCCEEDED(hr, attribute->SetUINT32(CODECAPI_AVDecVideoAcceleration_H264, TRUE));
        EXECUTE_IF_SUCCEEDED(hr, attribute->SetUINT32(CODECAPI_AVLowLatencyMode, TRUE));
        EXECUTE_IF_SUCCEEDED(hr, MfHelper::createD3dDeviceManager(d3d9Manager));
        EXECUTE_IF_SUCCEEDED(hr, decoder_->ProcessMessage(MFT_MESSAGE_SET_D3D_MANAGER,
            reinterpret_cast<ULONG_PTR>(d3d9Manager.Get())));

        return SUCCEEDED(hr);
    }

    bool H264DxvaDecoderImpl::InitializeInputOutputType()
    {
        HRESULT hr = S_OK;
        ComPtr<IMFMediaType> inputMediaType;
        ComPtr<IMFMediaType> outputMediaType;

        EXECUTE_IF_SUCCEEDED(hr, MFCreateMediaType(&inputMediaType));
        EXECUTE_IF_SUCCEEDED(hr, inputMediaType->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Video));
        EXECUTE_IF_SUCCEEDED(hr, inputMediaType->SetGUID(MF_MT_SUBTYPE, MFVideoFormat_H264));
        EXECUTE_IF_SUCCEEDED(hr, inputMediaType->SetUINT32(MF_MT_INTERLACE_MODE, MFVideoInterlace_Progressive));
        EXECUTE_IF_SUCCEEDED(hr, decoder_->SetInputType(0, inputMediaType, 0));

        for (uint32_t index = 0; SUCCEEDED(hr); ++index) {
            EXECUTE_IF_SUCCEEDED(hr, decoder_->GetOutputAvailableType(0, index, &outputMediaType));
            GUID outputSubType = { 0 };
            EXECUTE_IF_SUCCEEDED(hr, outputMediaType->GetGUID(MF_MT_SUBTYPE, &outputSubType));
            if (MFVideoFormat_NV12 == outputSubType) {
                EXECUTE_IF_SUCCEEDED(hr, decoder_->SetOutputType(0, outputMediaType, 0));
                break;
            }
        }

        return SUCCEEDED(hr);
    }

    bool H264DxvaDecoderImpl::ProcessInput(const EncodedImage& input_image)
    {
        HRESULT hr = S_OK;
        ComPtr<IMFSample> inputSample = nullptr;

        EXECUTE_IF_SUCCEEDED(hr, MfHelper::fillSample(inputSample, input_image._buffer, input_image._length));
        EXECUTE_IF_SUCCEEDED(hr, decoder_->ProcessInput(0, inputSample, 0));
        if (MF_E_NOTACCEPTING == hr) {
            hr = S_OK;
            time_stamp_ = input_image._timeStamp;
            while (ProcessOutput());
            EXECUTE_IF_SUCCEEDED(hr, decoder_->ProcessInput(0, inputSample, 0));
        }

        return SUCCEEDED(hr);
    }

    bool H264DxvaDecoderImpl::ProcessOutput()
    {
        HRESULT hr = S_OK;
        ComPtr<IMFSample> outputSample = nullptr;
        ComPtr<IMFMediaBuffer> mediaBuffer = nullptr;
        ComPtr<IMFMediaType> mediaType = nullptr;
        MFT_OUTPUT_DATA_BUFFER outputBuffer = { 0 };
        MFT_OUTPUT_STREAM_INFO outputStream = { 0 };

        BYTE* buffer = nullptr;
        DWORD outputStatus = 0;
        DWORD bufferSize = 0;
        bool createSample = false;

        EXECUTE_IF_SUCCEEDED(hr, decoder_->GetOutputStreamInfo(0, &outputStream));

        if (SUCCEEDED(hr)) {
            createSample = !(outputStream.dwFlags & (MFT_OUTPUT_STREAM_PROVIDES_SAMPLES |
                MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES));

            if (createSample) {
                EXECUTE_IF_SUCCEEDED(hr, MfHelper::createEmptySample(outputSample,
                    mediaBuffer, outputStream.cbSize));
                EXECUTE_IF_SUCCEEDED(hr, [&]()->HRESULT {
                    outputBuffer.pSample = outputSample;
                    return S_OK;
                }());
            }
        }

        EXECUTE_IF_SUCCEEDED(hr, decoder_->ProcessOutput(0, 1, &outputBuffer, &outputStatus));
        if (outputBuffer.pEvents) {
            outputBuffer.pEvents->Release();
            outputBuffer.pEvents = NULL;
        }

        if (MF_E_TRANSFORM_NEED_MORE_INPUT == hr) {
            return false;
        }

        if (MF_E_TRANSFORM_STREAM_CHANGE == hr) {
            hr = S_OK;
            DWORD i = 0;
            ComPtr<IMFMediaType>  tmpType = NULL;
            GUID subtype;
            while (SUCCEEDED(hr)) {
                hr = decoder_->GetOutputAvailableType(0, i++, &tmpType);
                if (SUCCEEDED(hr)) {
                    tmpType->GetGUID(MF_MT_SUBTYPE, &subtype);
                    if (!mediaType && subtype == MFVideoFormat_NV12) {
                        mediaType = tmpType;
                    } else if (subtype == MFVideoFormat_IYUV || subtype == MFVideoFormat_I420) {
                        mediaType = tmpType;
                        break;
                    }
                }
            }

            EXECUTE_IF_SUCCEEDED(hr, decoder_->SetOutputType(0, mediaType, 0));
            MFGetAttributeSize(mediaType, MF_MT_FRAME_SIZE, &w_, &h_);

            if (SUCCEEDED(hr)) {
                ProcessOutput();
            }
            return false;
        }

        if (!createSample) {
            outputSample = outputBuffer.pSample;
        }

        if (SUCCEEDED(hr)) {
            hr = outputSample->ConvertToContiguousBuffer(&mediaBuffer);
        }

        if (SUCCEEDED(hr)) {
            mediaBuffer->Lock(&buffer, 0, &bufferSize);
            decoder_->GetOutputCurrentType(0, &mediaType);
            GUID subtype;
            mediaType->GetGUID(MF_MT_SUBTYPE, &subtype);
			rtc::scoped_refptr<I420Buffer> frame_buffer; 
            if (MFVideoFormat_I420 == subtype || MFVideoFormat_IYUV == subtype) {
                frame_buffer = I420Buffer::Copy(w_, h_, buffer, w_,
                    buffer + w_*h_, w_/2,
                    buffer + w_*h_ * 5 / 4, w_/2);
            } else if (MFVideoFormat_NV12 == subtype) {
				frame_buffer = I420Buffer::Create(w_, h_);
                libyuv::NV12ToI420(buffer, w_, buffer + w_*h_, w_,
                    frame_buffer->MutableDataY(), frame_buffer->StrideY(),
                    frame_buffer->MutableDataU(), frame_buffer->StrideU(),
                    frame_buffer->MutableDataV(), frame_buffer->StrideV(), w_, h_);
            }

            VideoFrame frame(frame_buffer, kVideoRotation_0, time_stamp_);
            decoded_image_callback_->Decoded(frame);

            mediaBuffer->Unlock();
        }

        return SUCCEEDED(hr);
    }

    bool H264DxvaDecoderImpl::IsInitialized() const
    {
        return nullptr != decoder_;
    }

}