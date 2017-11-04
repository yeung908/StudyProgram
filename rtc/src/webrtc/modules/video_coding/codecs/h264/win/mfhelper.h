#ifndef WEBRTC_MODULES_VIDEO_CODING_CODEC_H264_WIN_MFHELPER_H 
#define WEBRTC_MODULES_VIDEO_CODING_CODEC_H264_WIN_MFHELPER_H

#include <stdint.h>
#include <mfapi.h>
#include <mftransform.h>
#include <d3d9.h>
#include <dxva2api.h>
#include "webrtc/modules/video_coding/codecs/h264/win/com_ptr.h"
#include "webrtc/modules/video_coding/codecs/h264/include/h264_globals.h"
#include "webrtc/base/criticalsection.h"

namespace webrtc {
    class VideoFrame;
	class MfHelper
	{
	public:
		static HRESULT createEmptySample(ComPtr<IMFSample>& sample, 
			ComPtr<IMFMediaBuffer>& buffer, DWORD length);

		static HRESULT fillSample(ComPtr<IMFSample>& sample, const uint8_t* data, uint32_t size);

        static HRESULT fillSampleWithI420(ComPtr<IMFSample>& sample, const VideoFrame &frame, uint64_t sampleDuration);
// 
// 		static HRESULT fillSampleWithH264(ComPtr<IMFSample>& sample, const H264Frame* frame);

		static HRESULT unLockAsyncCodec(ComPtr<IMFTransform>& transform);

		static HRESULT createH264Codec(ComPtr<IMFTransform>& transform,
			bool isSoft, bool isEncoder, GUID subType);

		static HRESULT createHardwareH264Encoder(ComPtr<IMFTransform>& transform);

		static HRESULT createHardwareH264Decoder(ComPtr<IMFTransform>& transform);

		static HRESULT createSoftwareH264Encoder(ComPtr<IMFTransform>& transform);

		static HRESULT createSoftwareH264Decoder(ComPtr<IMFTransform>& transform);

		// dxva2 helper function
		static HRESULT createD3dDeviceManager(ComPtr<IDirect3DDeviceManager9> d3d9Manager);

        static void InitSysEvent();

    private:
        static bool sys_inited_;
        static rtc::CriticalSection sys_init_cs_;
	};
}

#endif