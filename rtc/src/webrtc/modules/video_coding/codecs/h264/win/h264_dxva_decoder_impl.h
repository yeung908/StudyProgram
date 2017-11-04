#ifndef WEBRTC_MODULES_VIDEO_CODING_CODEC_H264_WIN_H264_DXVA_DECODER_IMPL_H
#define WEBRTC_MODULES_VIDEO_CODING_CODEC_H264_WIN_H264_DXVA_DECODER_IMPL_H

#include <mfapi.h>
#include <mftransform.h>
#include <d3d9.h>
#include <dxva2api.h>
#include "webrtc/modules/video_coding/codecs/h264/win/com_ptr.h"
#include "webrtc/modules/video_coding/codecs/h264/include/h264.h"
#include "webrtc/modules/video_coding/include/video_coding.h"

namespace webrtc
{
    class H264DxvaDecoderImpl : public H264Decoder
    {
    public:
        explicit H264DxvaDecoderImpl();
        virtual ~H264DxvaDecoderImpl() override;
        virtual int32_t InitDecode(const VideoCodec* codec_settings, int32_t number_of_cores) override;

        virtual int32_t Decode(const EncodedImage& input_image, bool missing_frames, const RTPFragmentationHeader* fragmentation, const CodecSpecificInfo* codec_specific_info = NULL, int64_t render_time_ms = -1) override;

        virtual int32_t RegisterDecodeCompleteCallback(DecodedImageCallback* callback) override;

        virtual int32_t Release() override;

        virtual const char* ImplementationName() const override;
    private:
        bool InitializeDXVA2Decoder();
        bool InitializeInputOutputType();
        bool ProcessInput(const EncodedImage& input_image);
        bool ProcessOutput();

        bool IsInitialized() const;

        ComPtr<IMFTransform> decoder_;
        DecodedImageCallback* decoded_image_callback_;
        uint32_t    time_stamp_;
		uint32_t w_;
		uint32_t h_;
    };
}

#endif