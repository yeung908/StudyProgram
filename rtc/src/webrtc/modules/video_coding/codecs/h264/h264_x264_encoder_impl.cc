/*
 *  Copyright (c) 2015 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 *
 */

#include "webrtc/modules/video_coding/codecs/h264/h264_x264_encoder_impl.h"

#include <limits>
#include <string>
#include <fstream>
#include "webrtc/base/checks.h"
#include "webrtc/base/logging.h"
#include "webrtc/common_video/libyuv/include/webrtc_libyuv.h"
#include "webrtc/media/base/mediaconstants.h"
#include "webrtc/system_wrappers/include/metrics.h"
#include "webrtc/common_video/h264/h264_common.h"

namespace webrtc {

	namespace {

		const bool kOpenH264EncoderDetailedLogging = false;

		// Used by histograms. Values of entries should not be changed.
		enum H264EncoderImplEvent {
			kH264EncoderEventInit = 0,
			kH264EncoderEventError = 1,
			kH264EncoderEventMax = 16,
		};

		int NumberOfThreads(int width, int height, int number_of_cores) {
			// TODO(hbos): In Chromium, multiple threads do not work with sandbox on Mac,
			// see crbug.com/583348. Until further investigated, only use one thread.
		  //  if (width * height >= 1920 * 1080 && number_of_cores > 8) {
		  //    return 8;  // 8 threads for 1080p on high perf machines.
		  //  } else if (width * height > 1280 * 960 && number_of_cores >= 6) {
		  //    return 3;  // 3 threads for 1080p.
		  //  } else if (width * height > 640 * 480 && number_of_cores >= 3) {
		  //    return 2;  // 2 threads for qHD/HD.
		  //  } else {
		  //    return 1;  // 1 thread for VGA or less.
		  //  }
		  // TODO(sprang): Also check sSliceArgument.uiSliceNum om GetEncoderPrams(),
		  //               before enabling multithreading here.
			return 1;
		}

		FrameType ConvertToVideoFrameType(int type) {
			switch (type) {
			case X264_TYPE_KEYFRAME:
				return kVideoFrameKey;
			default:
				return kVideoFrameDelta;
			}
			RTC_NOTREACHED() << "Unexpected/invalid frame type: " << type;
			return kEmptyFrame;
		}

	}  // namespace

	// Helper method used by H264EncoderImpl::Encode.
	// Copies the encoded bytes from |info| to |encoded_image| and updates the
	// fragmentation information of |frag_header|. The |encoded_image->_buffer| may
	// be deleted and reallocated if a bigger buffer is required.
	//
	// After OpenH264 encoding, the encoded bytes are stored in |info| spread out
	// over a number of layers and "NAL units". Each NAL unit is a fragment starting
	// with the four-byte start code {0,0,0,1}. All of this data (including the
	// start codes) is copied to the |encoded_image->_buffer| and the |frag_header|
	// is updated to point to each fragment, with offsets and lengths set as to
	// exclude the start codes.
	static void RtpFragmentize(EncodedImage* encoded_image,
		std::unique_ptr<uint8_t[]>* encoded_image_buffer,
		const VideoFrameBuffer& frame_buffer,
		x264_nal_t* nal_data, int nal_count,
		RTPFragmentationHeader* frag_header) {
        const uint8_t start_code[4] = { 0, 0, 0, 1 };
		// Calculate minimum buffer size required to hold encoded data.
		size_t required_size = 0;
		size_t fragments_count = 0;
        int sei_count = 0;
		for (int nal = 0; nal < nal_count; ++nal, ++fragments_count) {
			RTC_CHECK_GE(nal_data[nal].i_payload, 0);
			// Ensure |required_size| will not overflow.
			RTC_CHECK_LE(nal_data[nal].i_payload,
				std::numeric_limits<size_t>::max() - required_size);
            H264::NaluType nalu_type = H264::ParseNaluType(nal_data[nal].p_payload[sizeof(start_code)]);
            if (H264::kSei == nalu_type)
            {
                sei_count++;
                continue;
            }
			required_size += nal_data[nal].i_payload;
		}
        fragments_count -= sei_count;
		if (encoded_image->_size < required_size) {
			// Increase buffer size. Allocate enough to hold an unencoded image, this
			// should be more than enough to hold any encoded data of future frames of
			// the same size (avoiding possible future reallocation due to variations in
			// required size).
			encoded_image->_size =
				CalcBufferSize(kI420, frame_buffer.width(), frame_buffer.height());
			if (encoded_image->_size < required_size) {
				// Encoded data > unencoded data. Allocate required bytes.
				LOG(LS_WARNING) << "Encoding produced more bytes than the original image "
					<< "data! Original bytes: " << encoded_image->_size
					<< ", encoded bytes: " << required_size << ".";
				encoded_image->_size = required_size;
			}
			encoded_image->_buffer = new uint8_t[encoded_image->_size];
			encoded_image_buffer->reset(encoded_image->_buffer);
		}

		// Iterate layers and NAL units, note each NAL unit as a fragment and copy
		// the data to |encoded_image->_buffer|.
		
		frag_header->VerifyAndAllocateFragmentationHeader(fragments_count);
		encoded_image->_length = 0;
		for (int nal = 0, frag=0; nal < nal_count; ++nal) {
			H264::NaluType nalu_type = H264::ParseNaluType(nal_data[nal].p_payload[sizeof(start_code)]);
			if (H264::kSei == nalu_type) {
				continue;
			}
			unsigned int nal_size = nal_data[nal].i_payload - sizeof(start_code);
			frag_header->fragmentationOffset[frag] = encoded_image->_length + sizeof(start_code);
			frag_header->fragmentationLength[frag] = nal_size;

			// Copy the entire layer's data (including start codes).
			memcpy(encoded_image->_buffer + encoded_image->_length, start_code, sizeof(start_code));
			encoded_image->_length += sizeof(start_code);
			memcpy(encoded_image->_buffer + encoded_image->_length,
				nal_data[nal].p_payload+ sizeof(start_code),
				nal_size);
			encoded_image->_length += nal_size;
            frag++;
		}
	}

	H264X264EncoderImpl::H264X264EncoderImpl(const cricket::VideoCodec& codec)
		: x264_encoder_(nullptr),
		width_(0),
		height_(0),
		max_frame_rate_(0.0f),
		target_bps_(0),
		max_bps_(0),
		mode_(kRealtimeVideo),
		frame_dropping_on_(false),
		key_frame_interval_(0),
		packetization_mode_(H264PacketizationMode::SingleNalUnit),
		max_payload_size_(0),
		number_of_cores_(0),
		encoded_image_callback_(nullptr),
		has_reported_init_(false),
		has_reported_error_(false) {
		RTC_CHECK(cricket::CodecNamesEq(codec.name, cricket::kH264CodecName));
		std::string packetization_mode_string;
		if (codec.GetParam(cricket::kH264FmtpPacketizationMode,
			&packetization_mode_string) &&
			packetization_mode_string == "1") {
			packetization_mode_ = H264PacketizationMode::NonInterleaved;
		}
	}

	H264X264EncoderImpl::~H264X264EncoderImpl() {
		Release();
	}

	int32_t H264X264EncoderImpl::InitEncode(const VideoCodec* codec_settings,
		int32_t number_of_cores,
		size_t max_payload_size) {
		ReportInit();
		if (!codec_settings ||
			codec_settings->codecType != kVideoCodecH264) {
			ReportError();
			return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
		}
		if (codec_settings->maxFramerate == 0) {
			ReportError();
			return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
		}
		if (codec_settings->width < 1 || codec_settings->height < 1) {
			ReportError();
			return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
		}

		int32_t release_ret = Release();
		if (release_ret != WEBRTC_VIDEO_CODEC_OK) {
			ReportError();
			return release_ret;
		}
		RTC_DCHECK(!x264_encoder_);

        _qpMax = codec_settings->qpMax;
        _mode = codec_settings->mode;
		number_of_cores_ = number_of_cores;
		// Set internal settings from codec_settings
		width_ = codec_settings->width;
		height_ = codec_settings->height;
		max_frame_rate_ = static_cast<float>(codec_settings->maxFramerate);
		mode_ = codec_settings->mode;
		frame_dropping_on_ = codec_settings->H264().frameDroppingOn;
		key_frame_interval_ = codec_settings->H264().keyFrameInterval;
		max_payload_size_ = max_payload_size;

		// Codec_settings uses kbits/second; encoder uses kbits/second.
		max_bps_ = codec_settings->maxBitrate;
		if (codec_settings->targetBitrate == 0)
			target_bps_ = codec_settings->startBitrate;
		else
			target_bps_ = codec_settings->targetBitrate;
        LOG(INFO) << "init x264 " << (codec_settings->mode == kScreensharing ? "screen" : "camera") << " encoder " << "width:"<< codec_settings->width<<" height:"<< codec_settings->height\
            <<" bitrate:"<<(codec_settings->targetBitrate == 0? codec_settings->startBitrate: codec_settings->targetBitrate)<<" framerate:"<< static_cast<int>(codec_settings->maxFramerate) <<" gop:"<< codec_settings->H264().keyFrameInterval;
		x264_param_t encoder_params = CreateEncoderParams();


		// Create encoder.
		if (x264_encoder_ = x264_encoder_open(&encoder_params), !x264_encoder_) {
			// Failed to create encoder.
			LOG(LS_ERROR) << "Failed to create X264 encoder";
			RTC_DCHECK(!x264_encoder_);
			ReportError();
			return WEBRTC_VIDEO_CODEC_ERROR;
		}
		RTC_DCHECK(x264_encoder_);
        x264_picture_init(&pic);
        pic.img.i_csp = X264_CSP_I420;
        pic.img.i_plane = 3;
		pic.i_type = X264_TYPE_AUTO;
		// Initialize encoded image. Default buffer size: size of unencoded data.
		encoded_image_._size =
			CalcBufferSize(kI420, codec_settings->width, codec_settings->height);
		encoded_image_._buffer = new uint8_t[encoded_image_._size];
		encoded_image_buffer_.reset(encoded_image_._buffer);
		encoded_image_._completeFrame = true;
		encoded_image_._encodedWidth = 0;
		encoded_image_._encodedHeight = 0;
		encoded_image_._length = 0;
#if defined(WEBRTC_WIN)
        time_t rawtime;
        time(&rawtime);
        tm * timeinfo;
        timeinfo = localtime(&rawtime);
        char timebuffer[MAX_PATH];
        strftime(timebuffer, MAX_PATH, "%Y_%m_%d_%H_%M_%S", timeinfo);
        std::stringstream stream;
        char tempFileName[MAX_PATH] = { 0 };
        GetTempPathA(MAX_PATH, tempFileName);
        stream << tempFileName << "maxhub_x264_" << (codec_settings->mode == kScreensharing ? "screen" : "camera") << "_" << timebuffer << width_ << "_" << height_ << ".264";
        dumpfile_.open(stream.str(), std::ios::binary | std::ios::out);
#endif
		return WEBRTC_VIDEO_CODEC_OK;
	}

	int32_t H264X264EncoderImpl::Release() {
		if (x264_encoder_) {
			x264_encoder_close(x264_encoder_);			
			x264_encoder_ = nullptr;
		}
#if defined(WEBRTC_WIN)
        dumpfile_.close();
#endif
		encoded_image_._buffer = nullptr;
		encoded_image_buffer_.reset();
		return WEBRTC_VIDEO_CODEC_OK;
	}

	int32_t H264X264EncoderImpl::RegisterEncodeCompleteCallback(
		EncodedImageCallback* callback) {
		encoded_image_callback_ = callback;
		return WEBRTC_VIDEO_CODEC_OK;
	}

	int32_t H264X264EncoderImpl::SetRateAllocation(
		const BitrateAllocation& bitrate_allocation,
		uint32_t framerate) {
		if (bitrate_allocation.get_sum_bps() <= 0 || framerate <= 0)
			return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;
        LOG(INFO) << "modify x264 "<< (_mode == kScreensharing ? "screen" : "camera")<<" encode bitrate " << bitrate_allocation.get_sum_bps();
		target_bps_ = bitrate_allocation.get_sum_bps()/1000;
		max_frame_rate_ = static_cast<float>(framerate);
		x264_param_t encoder_params;
		x264_encoder_parameters(x264_encoder_, &encoder_params);
		encoder_params.rc.i_bitrate = target_bps_;
		encoder_params.i_fps_num = max_frame_rate_;
        x264_encoder_reconfig(x264_encoder_, &encoder_params);
		return WEBRTC_VIDEO_CODEC_OK;
	}

	int32_t H264X264EncoderImpl::Encode(const VideoFrame& input_frame,
		const CodecSpecificInfo* codec_specific_info,
		const std::vector<FrameType>* frame_types) {
		if (!IsInitialized()) {
			ReportError();
			return WEBRTC_VIDEO_CODEC_UNINITIALIZED;
		}
		if (!encoded_image_callback_) {
			LOG(LS_WARNING) << "InitEncode() has been called, but a callback function "
				<< "has not been set with RegisterEncodeCompleteCallback()";
			ReportError();
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
		pic.i_type = X264_TYPE_AUTO;
		if (force_key_frame) {
			// API doc says ForceIntraFrame(false) does nothing, but calling this
			// function forces a key frame regardless of the |bIDR| argument's value.
			// (If every frame is a key frame we get lag/delays.)
			pic.i_type = X264_TYPE_KEYFRAME;;
		}
		rtc::scoped_refptr<const VideoFrameBuffer> frame_buffer =
			input_frame.video_frame_buffer();
		// EncodeFrame input.

		pic.img.i_plane = 3;
		pic.img.plane[0] = const_cast<uint8_t*>(frame_buffer->DataY());
		pic.img.plane[1] = const_cast<uint8_t*>(frame_buffer->DataU());
		pic.img.plane[2] = const_cast<uint8_t*>(frame_buffer->DataV());
		pic.img.plane[3] = 0;
		pic.img.i_stride[0] = frame_buffer->StrideY();
		pic.img.i_stride[1] = frame_buffer->StrideU();
		pic.img.i_stride[2] = frame_buffer->StrideV();

		x264_picture_t pic_out;
		x264_nal_t *nal;
		int i_nal = 0; // nal count

		// Encode!
#if defined(WEBRTC_WIN)
        auto t1 = GetTickCount();
#endif
		int enc_ret = x264_encoder_encode(x264_encoder_, &nal, &i_nal, &pic, &pic_out);
		if (enc_ret <= 0) {
			LOG(LS_ERROR) << "X264 frame encoding failed, EncodeFrame returned "
				<< enc_ret << ".";
			ReportError();
			return WEBRTC_VIDEO_CODEC_ERROR;
		}

		encoded_image_._encodedWidth = frame_buffer->width();
		encoded_image_._encodedHeight = frame_buffer->height();
		encoded_image_._timeStamp = input_frame.timestamp();
		encoded_image_.ntp_time_ms_ = input_frame.ntp_time_ms();
		encoded_image_.capture_time_ms_ = input_frame.render_time_ms();
		encoded_image_.rotation_ = input_frame.rotation();
		encoded_image_._frameType = ConvertToVideoFrameType(pic_out.i_type);

		// Split encoded image up into fragments. This also updates |encoded_image_|.
		RTPFragmentationHeader frag_header;
		RtpFragmentize(&encoded_image_, &encoded_image_buffer_, *frame_buffer, nal, i_nal,
			&frag_header);        
#if defined(WEBRTC_WIN)
        LOG(INFO) << "x264 encode frame cost:" << GetTickCount() - t1 << " ms, RtpFragmentize:" << encoded_image_._length;
        if (dumpfile_)
        {
            dumpfile_.write((char*)encoded_image_._buffer, encoded_image_._length);
            dumpfile_.flush();
        }
#endif        
		// Encoder can skip frames to save bandwidth in which case
		// |encoded_image_._length| == 0.
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

	const char* H264X264EncoderImpl::ImplementationName() const {
		return "X264";
	}

	bool H264X264EncoderImpl::IsInitialized() const {
		return x264_encoder_ != nullptr;
	}

	// Initialization parameters.
	// There are two ways to initialize. There is SEncParamBase (cleared with
	// memset(&p, 0, sizeof(SEncParamBase)) used in Initialize, and SEncParamExt
	// which is a superset of SEncParamBase (cleared with GetDefaultParams) used
	// in InitializeExt.
	x264_param_t H264X264EncoderImpl::CreateEncoderParams() const {        
		x264_param_t encoder_params;
        if (_mode == kScreensharing)
        {
            x264_param_default_preset(&encoder_params, "veryfast", "grain+zerolatency");
        }
        else
        {
            x264_param_default_preset(&encoder_params, "veryfast", "zerolatency");
        }   
        encoder_params.i_threads = 1;
        encoder_params.rc.i_qp_min = 20;
        encoder_params.rc.i_qp_max = _qpMax;
        encoder_params.rc.i_qp_step = 2;		
		encoder_params.i_csp = X264_CSP_I420;
		encoder_params.b_annexb = 0;
		encoder_params.i_width = width_;
		encoder_params.i_height = height_;
		encoder_params.rc.i_bitrate = target_bps_;
		encoder_params.rc.i_vbv_max_bitrate = max_bps_;
		// Rate Control mode
		encoder_params.rc.i_rc_method = X264_RC_ABR;
		encoder_params.i_fps_num = max_frame_rate_;
		encoder_params.i_fps_den = 1;

		encoder_params.i_bframe_adaptive = X264_B_ADAPT_NONE;
		// |uiIntraPeriod|    - multiple of GOP size
		// |keyFrameInterval| - number of frames
		encoder_params.i_keyint_max = key_frame_interval_;
		//使用加权预测后wertc不能解析，所以禁用加权预测
		encoder_params.analyse.i_weighted_pred = 0;
		switch (packetization_mode_) {
		case H264PacketizationMode::SingleNalUnit:
			// Limit the size of the packets produced.
			encoder_params.i_slice_max_size =
				static_cast<unsigned int>(max_payload_size_);
			break;
		default:
			break;
		}
		return encoder_params;
	}

	void H264X264EncoderImpl::ReportInit() {
		if (has_reported_init_)
			return;
		RTC_HISTOGRAM_ENUMERATION("WebRTC.Video.H264X264EncoderImpl.Event",
			kH264EncoderEventInit,
			kH264EncoderEventMax);
		has_reported_init_ = true;
	}

	void H264X264EncoderImpl::ReportError() {
		if (has_reported_error_)
			return;
		RTC_HISTOGRAM_ENUMERATION("WebRTC.Video.H264X264EncoderImpl.Event",
			kH264EncoderEventError,
			kH264EncoderEventMax);
		has_reported_error_ = true;
	}

	int32_t H264X264EncoderImpl::SetChannelParameters(
		uint32_t packet_loss, int64_t rtt) {
		return WEBRTC_VIDEO_CODEC_OK;
	}

	int32_t H264X264EncoderImpl::SetPeriodicKeyFrames(bool enable) {
		return WEBRTC_VIDEO_CODEC_OK;
	}

	VideoEncoder::ScalingSettings H264X264EncoderImpl::GetScalingSettings() const {
		return VideoEncoder::ScalingSettings(true);
	}

}  // namespace webrtc
