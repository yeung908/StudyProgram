#include "webrtc/media/mediacodec/androidencoder_hisilicon.h"

#include <algorithm>
#include <memory>
#include <list>
#include <fstream>

#include "webrtc/common_video/h264/h264_common.h"
#include "webrtc/common_video/h264/h264_bitstream_parser.h"
#include "webrtc/common_video/h264/profile_level_id.h"
#include "webrtc/modules/video_coding/codecs/h264/include/h264.h"
#include "webrtc/modules/video_coding/utility/quality_scaler.h"
#include "webrtc/base/logging.h"

#include "hi_unf_common.h"
#include "hi_unf_ecs.h"
#include "hi_unf_disp.h"
#include "hi_unf_vo.h"
#include "hi_unf_aenc.h"
#include "hi_unf_venc.h"

#define SCREENT_WIDTH       1280
#define SCREENT_HEIGHT      720
#define SCREENT_FPS         10
#define SCREEN_MIN_QP       20
#define SCREEN_MAX_QP       36
#define SCREEN_GOP          600

// #define WRITE_FILE

// January 1970, in NTP seconds.
const uint32_t kNtpJan1970 = 2208988800UL;

// Convert NTP time, in ms, to RTP timestamp.
const int kMsToRtpTimestamp = 90;

namespace webrtc {

namespace {
    FrameType ConvertToVideoFrameType(int type) {
        switch (type) {
        case HI_UNF_H264E_NALU_ISLICE:
            return kVideoFrameKey;
        default:
            return kVideoFrameDelta;
        }
    }
}

class H264AndroidScreenEncoderImpl : public webrtc::VideoEncoder {
    public:
        explicit H264AndroidScreenEncoderImpl(const cricket::VideoCodec& codec);
        ~H264AndroidScreenEncoderImpl() override;

        // |max_payload_size| is ignored.
        // The following members of |codec_settings| are used. The rest are ignored.
        // - codecType (must be kVideoCodecH264)
        int32_t InitEncode(const VideoCodec* codec_settings,
                            int32_t number_of_cores,
                            size_t max_payload_size) override;
        int32_t Release() override;

        int32_t RegisterEncodeCompleteCallback(
            EncodedImageCallback* callback) override;
        int32_t SetRateAllocation(const BitrateAllocation& bitrate_allocation,
                                    uint32_t framerate) override;

        // The result of encoding - an EncodedImage and RTPFragmentationHeader - are
        // passed to the encode complete callback.
        int32_t Encode(const VideoFrame& frame,
                        const CodecSpecificInfo* codec_specific_info,
                        const std::vector<FrameType>* frame_types) override;

        const char* ImplementationName() const override;

        VideoEncoder::ScalingSettings GetScalingSettings() const override;

        // Unsupported / Do nothing.
        int32_t SetChannelParameters(uint32_t packet_loss, int64_t rtt) override;
        int32_t SetPeriodicKeyFrames(bool enable) override;

    private:
        HI_HANDLE  	 			    disp_;
        HI_HANDLE				    encoder_;
        HI_UNF_DISP_CAST_ATTR_S     stDispCastAttr_;
        HI_UNF_VENC_CHN_ATTR_S      stVencChnAttr_;
        HI_UNF_VENC_STREAM_S        vencStream_;

        int width_;
        int height_;
        H264PacketizationMode packetization_mode_;
        EncodedImage encoded_image_;
        EncodedImageCallback* encoded_image_callback_;

#ifdef WRITE_FILE
        std::ofstream			_file;
#endif

}; // class H264AndroidScreenEncoderImpl

H264AndroidScreenEncoderImpl::H264AndroidScreenEncoderImpl(const cricket::VideoCodec& codec) 
    : width_(SCREENT_WIDTH), height_(SCREENT_HEIGHT), 
    packetization_mode_(H264PacketizationMode::SingleNalUnit) {

    std::string packetization_mode_string;
    if (codec.GetParam(cricket::kH264FmtpPacketizationMode,
        &packetization_mode_string) &&
        packetization_mode_string == "1") {
        packetization_mode_ = H264PacketizationMode::NonInterleaved;
    }
}

H264AndroidScreenEncoderImpl::~H264AndroidScreenEncoderImpl() {
    Release();
}

int32_t H264AndroidScreenEncoderImpl::InitEncode(const VideoCodec* codec_settings,
                    int32_t number_of_cores,
                    size_t max_payload_size) {

    if ( codec_settings->mode != kScreensharing ) {
        LOG(LS_ERROR) << "Unsupported codec mode.";
        return WEBRTC_VIDEO_CODEC_ERROR;
    }

    HI_S32 ret = HI_SUCCESS;

    ret = HI_UNF_DISP_Init();
    if (HI_SUCCESS != ret) {
    	LOG(LS_ERROR) << "HI_UNF_DISP_Init ret = " << ret;
        return WEBRTC_VIDEO_CODEC_ERROR;
    }
    
    ret = HI_UNF_DISP_GetDefaultCastAttr(HI_UNF_DISPLAY1, &stDispCastAttr_);
    if (HI_SUCCESS != ret) {
    	LOG(LS_ERROR) << "HI_UNF_DISP_GetDefaultCastAttr ret = " << ret;
        return WEBRTC_VIDEO_CODEC_ERROR;
    }

    stDispCastAttr_.u32Width = width_;
    stDispCastAttr_.u32Height = height_;
    stDispCastAttr_.bLowDelay = HI_TRUE;

    ret = HI_UNF_DISP_CreateCast(HI_UNF_DISPLAY1, &stDispCastAttr_, &disp_);
    if (HI_SUCCESS != ret) {
    	LOG(LS_ERROR) << "HI_UNF_DISP_CreateCast ret = " << ret;
        return WEBRTC_VIDEO_CODEC_ERROR;
    }

    ret = HI_UNF_VENC_Init();
    if (HI_SUCCESS != ret) {
    	LOG(LS_ERROR) << "HI_UNF_VENC_Init ret = " << ret;
        return WEBRTC_VIDEO_CODEC_ERROR;
    }
    ret = HI_UNF_VENC_GetDefaultAttr(&stVencChnAttr_);
    if (HI_SUCCESS != ret) {
    	LOG(LS_ERROR) << "HI_UNF_VENC_GetDefaultAttr ret = " << ret;
        return WEBRTC_VIDEO_CODEC_ERROR;
    }

    // Codec_settings uses kbits/second; encoder uses bits/second.
    int target_kbps = codec_settings->targetBitrate;
    if ( target_kbps == 0)
        target_kbps = codec_settings->startBitrate;
    else
        target_kbps = codec_settings->targetBitrate;

    stVencChnAttr_.enVencType = HI_UNF_VCODEC_TYPE_H264;
    stVencChnAttr_.enCapLevel = HI_UNF_VCODEC_CAP_LEVEL_E::HI_UNF_VCODEC_CAP_LEVEL_720P;
    stVencChnAttr_.enVencProfile = HI_UNF_H264_PROFILE_BASELINE;
    stVencChnAttr_.u32Width = width_;
    stVencChnAttr_.u32Height = height_; 
    stVencChnAttr_.u32StrmBufSize = width_ * height_ * 2;
    stVencChnAttr_.u32TargetBitRate = target_kbps * 1000;
    stVencChnAttr_.u32InputFrmRate = SCREENT_FPS;
    stVencChnAttr_.u32TargetFrmRate = SCREENT_FPS;
    stVencChnAttr_.bQuickEncode = HI_TRUE;
    stVencChnAttr_.u32MinQp = SCREEN_MIN_QP;
    stVencChnAttr_.u32MaxQp = SCREEN_MAX_QP;
    stVencChnAttr_.u32Gop = SCREEN_GOP;
    
    ret = HI_UNF_VENC_Create(&encoder_, &stVencChnAttr_);
    if (HI_SUCCESS != ret) {
    	LOG(LS_ERROR) << "HI_UNF_VENC_Create ret = " << ret;
        return WEBRTC_VIDEO_CODEC_ERROR;
    }

    ret = HI_UNF_VENC_AttachInput(encoder_, disp_);
    if (HI_SUCCESS != ret) {
    	LOG(LS_ERROR) << "HI_UNF_VENC_AttachInput ret = " << ret;
        return WEBRTC_VIDEO_CODEC_ERROR;
    }

    ret = HI_UNF_DISP_SetCastEnable(disp_, HI_TRUE);
    if (HI_SUCCESS != ret) {
    	LOG(LS_ERROR) << "HI_UNF_DISP_SetCastEnable ret = " << ret;
        return WEBRTC_VIDEO_CODEC_ERROR;
    }

    ret = HI_UNF_VENC_Start(encoder_);
    if (HI_SUCCESS != ret) {
    	LOG(LS_ERROR) << "HI_UNF_VENC_Start ret = " << ret;
        return WEBRTC_VIDEO_CODEC_ERROR;
    }

    LOG(LS_VERBOSE) << "init encode param bitrate:" << stVencChnAttr_.u32TargetBitRate 
        << " fps:" << stVencChnAttr_.u32InputFrmRate
        << " width:" << stVencChnAttr_.u32Width
        << " height:" << stVencChnAttr_.u32Height
        << " MinQp:" << stVencChnAttr_.u32MinQp
        << " MaxQp:" << stVencChnAttr_.u32MaxQp
        << " Gop:" << stVencChnAttr_.u32Gop;

#ifdef WRITE_FILE
    _file.open("/sdcard/screen.264", std::ios::out|std::ios::trunc|std::ios::binary);
#endif

    return WEBRTC_VIDEO_CODEC_OK;
}

int32_t H264AndroidScreenEncoderImpl::Release() {
    HI_S32 Ret = 0;
    Ret |= HI_UNF_DISP_SetCastEnable(disp_, HI_FALSE);
    Ret |= HI_UNF_VENC_Stop(encoder_);
    HI_UNF_DISP_SetCastEnable(disp_, HI_FALSE);
    HI_UNF_VENC_Stop(encoder_);
    HI_UNF_VENC_DetachInput(encoder_);
    HI_UNF_VENC_Destroy(encoder_);
    HI_UNF_DISP_DestroyCast(disp_);
    HI_UNF_DISP_DeInit();

#ifdef WRITE_FILE
    if (_file.is_open()) {
    	_file.close();
    }
#endif

    return WEBRTC_VIDEO_CODEC_OK;
}

int32_t H264AndroidScreenEncoderImpl::RegisterEncodeCompleteCallback(
    EncodedImageCallback* callback) {
    encoded_image_callback_ = callback;
	return WEBRTC_VIDEO_CODEC_OK;
}

int32_t H264AndroidScreenEncoderImpl::SetRateAllocation(const BitrateAllocation& bitrate_allocation,
                            uint32_t framerate) {

    if (bitrate_allocation.get_sum_bps() <= 0 || framerate <= 0)
        return WEBRTC_VIDEO_CODEC_ERR_PARAMETER;

    uint32_t target_bps = bitrate_allocation.get_sum_bps();
    uint32_t max_frame_rate = framerate;

    HI_S32 ret = HI_UNF_VENC_GetDefaultAttr(&stVencChnAttr_);
    if (HI_SUCCESS != ret) {
    	LOG(LS_ERROR) << "HI_UNF_VENC_GetDefaultAttr ret = " << ret;
        return WEBRTC_VIDEO_CODEC_ERROR;
    }

    stVencChnAttr_.u32TargetBitRate = target_bps;
    stVencChnAttr_.u32TargetFrmRate = max_frame_rate;

    HI_UNF_VENC_SetAttr(encoder_, &stVencChnAttr_);

    LOG(LS_INFO) << "update screent encoder bitrate " << stVencChnAttr_.u32TargetBitRate
                 << " fps " << max_frame_rate;
    
    return WEBRTC_VIDEO_CODEC_OK;
}

int32_t H264AndroidScreenEncoderImpl::Encode(const VideoFrame& frame,
                const CodecSpecificInfo* codec_specific_info,
                const std::vector<FrameType>* frame_types) {

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

    if ( force_key_frame ) {
        HI_UNF_VENC_RequestIFrame(encoder_);
        LOG(LS_VERBOSE) << "force request key frame.";
    }

    HI_S32 ret = HI_UNF_VENC_AcquireStream(encoder_, &vencStream_, 0);
    int count = 0;
    while ( HI_SUCCESS == ret ) {

#ifdef WRITE_FILE
        if (_file.is_open()) {
            _file.write((const char*)vencStream_.pu8Addr, (uint32_t)vencStream_.u32SlcLen);
            _file.flush();_file.flush();
            LOG(LS_VERBOSE) << "write nalu to file with size " << vencStream_.u32SlcLen 
                            << " count " << ++count;
        }
#endif // DEBUG WRITE_FILE

        uint64_t ntp_time_ms = vencStream_.u32PtsMs + kNtpJan1970;
        uint32_t timestamp = kMsToRtpTimestamp * static_cast<uint32_t>(ntp_time_ms);

        encoded_image_._size = vencStream_.u32SlcLen;
        encoded_image_._length = vencStream_.u32SlcLen;
        encoded_image_._buffer = vencStream_.pu8Addr;
        encoded_image_._encodedWidth = width_;
        encoded_image_._encodedHeight = height_;
        encoded_image_._timeStamp = timestamp;
        encoded_image_.ntp_time_ms_ = ntp_time_ms;
        encoded_image_.capture_time_ms_ = vencStream_.u32PtsMs;
        encoded_image_.rotation_ = frame.rotation();
        encoded_image_._frameType = ConvertToVideoFrameType(vencStream_.enDataType.enH264EType);

        // For H.264 search for start codes.
        const std::vector<webrtc::H264::NaluIndex> nalu_idxs = 
            webrtc::H264::FindNaluIndices(encoded_image_._buffer, encoded_image_._length);

        if ( nalu_idxs.empty() ) {
            LOG(LS_ERROR) << "nalu start code is not found!";
            return WEBRTC_VIDEO_CODEC_ERROR;
        }

        webrtc::RTPFragmentationHeader header;
        memset(&header, 0, sizeof(header));
        header.VerifyAndAllocateFragmentationHeader(nalu_idxs.size());

        for (size_t i = 0; i < nalu_idxs.size(); i++) {
            header.fragmentationOffset[i] = nalu_idxs[i].payload_start_offset;
            header.fragmentationLength[i] = nalu_idxs[i].payload_size;
            header.fragmentationPlType[i] = 0;
            header.fragmentationTimeDiff[i] = 0;
        }

        CodecSpecificInfo codec_specific;
        codec_specific.codecType = kVideoCodecH264;
        codec_specific.codecSpecific.H264.packetization_mode = packetization_mode_;

        encoded_image_callback_->OnEncodedImage(encoded_image_, &codec_specific,
                    &header);

        HI_UNF_VENC_ReleaseStream(encoder_, &vencStream_);
        ret = HI_UNF_VENC_AcquireStream(encoder_, &vencStream_, 0);
    } 

    return WEBRTC_VIDEO_CODEC_OK;
}

const char* H264AndroidScreenEncoderImpl::ImplementationName() const {
    return "h264";
}

VideoEncoder::ScalingSettings H264AndroidScreenEncoderImpl::GetScalingSettings() const {
    return VideoEncoder::ScalingSettings(true);
}

int32_t H264AndroidScreenEncoderImpl::SetChannelParameters(uint32_t packet_loss, int64_t rtt) {
    return WEBRTC_VIDEO_CODEC_OK;
}

int32_t H264AndroidScreenEncoderImpl::SetPeriodicKeyFrames(bool enable) {
    return WEBRTC_VIDEO_CODEC_OK;
}

HisiliconEncoderFactory::HisiliconEncoderFactory() {
    supported_codecs_.clear();
    cricket::VideoCodec constrained_baseline(cricket::kH264CodecName);
    const webrtc::H264::ProfileLevelId constrained_baseline_profile(
        webrtc::H264::kProfileConstrainedBaseline, webrtc::H264::kLevel3_1);
    constrained_baseline.SetParam(
        cricket::kH264FmtpProfileLevelId,
        *webrtc::H264::ProfileLevelIdToString(constrained_baseline_profile));
    constrained_baseline.SetParam(cricket::kH264FmtpLevelAsymmetryAllowed, "1");
    constrained_baseline.SetParam(cricket::kH264FmtpPacketizationMode, "1");
    supported_codecs_.push_back(constrained_baseline);
}

HisiliconEncoderFactory::~HisiliconEncoderFactory() {
  LOG(LS_VERBOSE) << "HisiliconEncoderFactory dtor";
}

webrtc::VideoEncoder* HisiliconEncoderFactory::CreateVideoEncoder(
    const cricket::VideoCodec& codec) {
  if (supported_codecs_.empty()) {
    LOG(LS_WARNING) << "No HW video encoder for codec " << codec.name;
    return nullptr;
  }
  if (FindMatchingCodec(supported_codecs_, codec)) {
    LOG(LS_VERBOSE) << "Create Hisilicon screen encoder for " << codec.name;
    return new H264AndroidScreenEncoderImpl(codec);
  }
  LOG(LS_WARNING) << "Can not find HW video encoder for type " << codec.name;
  return nullptr;
}

const std::vector<cricket::VideoCodec>&
HisiliconEncoderFactory::supported_codecs() const {
  return supported_codecs_;
}

void HisiliconEncoderFactory::DestroyVideoEncoder(
    webrtc::VideoEncoder* encoder) {
  LOG(LS_VERBOSE) << "Destroy screen encoder.";
  delete encoder;
}

} // namespace webrtc