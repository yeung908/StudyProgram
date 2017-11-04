#ifndef WEBRTC_MODULES_VIDEO_CODING_CODECS_H264_WIN_H264_MEDIA_FOUNDATION_ENCODER_IMPL_H
#define WEBRTC_MODULES_VIDEO_CODING_CODECS_H264_WIN_H264_MEDIA_FOUNDATION_ENCODER_IMPL_H

#include <mftransform.h>
#include <mfidl.h>
#include <dshow.h>
#include <queue>
#include <atomic>
#include "webrtc/common_video/h264/h264_bitstream_parser.h"
#include "webrtc/modules/video_coding/codecs/h264/include/h264.h"
#include "webrtc/modules/video_coding/utility/quality_scaler.h"
#include "webrtc/modules/video_coding/codecs/h264/win/com_ptr.h"

namespace webrtc
{
    class H264MediaFoundationEncoderImpl : public H264Encoder
    {
    public:
        explicit H264MediaFoundationEncoderImpl(const cricket::VideoCodec& codec);
        ~H264MediaFoundationEncoderImpl() override;

        virtual int32_t InitEncode(const VideoCodec* codec_settings, int32_t number_of_cores, size_t max_payload_size) override;

        virtual int32_t RegisterEncodeCompleteCallback(EncodedImageCallback* callback) override;

        virtual int32_t Release() override;

        virtual int32_t Encode(const VideoFrame& frame, const CodecSpecificInfo* codec_specific_info, const std::vector<FrameType>* frame_types) override;

        virtual int32_t SetChannelParameters(uint32_t packet_loss, int64_t rtt) override;

        virtual int32_t SetRates(uint32_t bitrate, uint32_t framerate) override;

        virtual int32_t SetRateAllocation(const BitrateAllocation& allocation, uint32_t framerate) override;

        virtual ScalingSettings GetScalingSettings() const override;

        virtual const char* ImplementationName() const override;

    private:
        bool IsInitialized();
        bool ApplySettings();

        bool ProcessInput(const VideoFrame &frame);
        bool ProcessOutput();
        int32_t DrainEvents();
        int32_t DrainEvent();

        ComPtr<IMFTransform>           encoder_;
        ComPtr<ICodecAPI>              codecApi_;
        ComPtr<IMFMediaEventGenerator> eventGenerator_;
        std::queue<ComPtr<IMFSample>>  inputSamples_;

        std::atomic<uint32_t>          inputRequests_;
        std::atomic<uint32_t>          outputRequests_;

        webrtc::H264BitstreamParser h264_bitstream_parser_;
        // Settings that are used by this encoder.
        int width_;
        int height_;
        float max_frame_rate_;
        uint32_t target_bps_;
        uint32_t max_bps_;
        VideoCodecMode mode_;
        // H.264 specifc parameters
        bool frame_dropping_on_;
        int key_frame_interval_;
        H264PacketizationMode packetization_mode_;

        size_t max_payload_size_;
        int32_t number_of_cores_;

        EncodedImage encoded_image_;
        std::unique_ptr<uint8_t[]> encoded_image_buffer_;
        EncodedImageCallback* encoded_image_callback_;

        const VideoFrame *input_frame_;
    };
}



#endif