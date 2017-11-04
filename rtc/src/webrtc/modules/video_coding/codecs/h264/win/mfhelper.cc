#include <codecapi.h>
#include <iostream>
#include "libyuv/convert.h"
#include "libyuv/convert_from.h"
#include "webrtc/modules/video_coding/codecs/h264/win/mfhelper.h"
#include "webrtc/modules/video_coding/codecs/h264/win/macros_utils.h"
#include "webrtc/api/video/video_frame.h"
#include "webrtc/common_video/libyuv/include/webrtc_libyuv.h"

namespace webrtc
{
    HRESULT MfHelper::createEmptySample(ComPtr<IMFSample>& sample,
        ComPtr<IMFMediaBuffer> &buffer, DWORD length)
    {
        HRESULT hr = MFCreateSample(&sample);

        EXECUTE_IF_SUCCEEDED(hr, MFCreateMemoryBuffer(length, &buffer));
        EXECUTE_IF_SUCCEEDED(hr, buffer->SetCurrentLength(0));
        EXECUTE_IF_SUCCEEDED(hr, sample->AddBuffer(buffer));

        return hr;
    }

    HRESULT MfHelper::fillSample(ComPtr<IMFSample>& sample, const uint8_t* data, uint32_t size)
    {
        HRESULT hr = S_OK;
        ComPtr<IMFMediaBuffer> mediaBuffer;
        BYTE* bufferData = nullptr;

        EXECUTE_IF_SUCCEEDED(hr, createEmptySample(sample, mediaBuffer, size));
        EXECUTE_IF_SUCCEEDED(hr, mediaBuffer->Lock(&bufferData, NULL, NULL));
        EXECUTE_IF_SUCCEEDED(hr, [&]()->HRESULT {
            memcpy(bufferData, data, size);
            return mediaBuffer->Unlock();
        }());
        EXECUTE_IF_SUCCEEDED(hr, mediaBuffer->SetCurrentLength(size));

        return hr;
    }

    HRESULT MfHelper::fillSampleWithI420(ComPtr<IMFSample>& sample, const VideoFrame &frame, uint64_t sampleDuration)
    {
        HRESULT hr = S_OK;
        uint32_t w = frame.width();
        uint32_t h = frame.height();
        size_t size = CalcBufferSize(kI420, w, h);
        BYTE* nv12Data = new BYTE[size];

        rtc::scoped_refptr<VideoFrameBuffer> frame_buffer = frame.video_frame_buffer();

        libyuv::I420ToNV12(frame_buffer->DataY(), frame_buffer->StrideY(),
                            frame_buffer->DataU(), frame_buffer->StrideU(), 
                            frame_buffer->DataV(), frame_buffer->StrideV(),
                            nv12Data, w, nv12Data + w*h, w, w, h);

        EXECUTE_IF_SUCCEEDED(hr, fillSample(sample, nv12Data, size));
        EXECUTE_IF_SUCCEEDED(hr, sample->SetSampleTime(frame.ntp_time_ms()));
        EXECUTE_IF_SUCCEEDED(hr, sample->SetSampleDuration(sampleDuration));

        delete[] nv12Data;

        return hr;
    }

//     HRESULT MfHelper::fillSampleWithH264(ComPtr<IMFSample>& sample, const H264Frame* frame)
//     {
//         return fillSample(sample, frame->data(), frame->size());
//     }

    HRESULT MfHelper::unLockAsyncCodec(ComPtr<IMFTransform>& transform)
    {
        HRESULT hr = S_OK;
        ComPtr<IMFAttributes> attribtes;

        EXECUTE_IF_SUCCEEDED(hr, transform->GetAttributes(&attribtes));
        EXECUTE_IF_SUCCEEDED(hr, attribtes->SetUINT32(MF_TRANSFORM_ASYNC_UNLOCK, TRUE));

        return hr;
    }

    HRESULT MfHelper::createH264Codec(ComPtr<IMFTransform>& transform,
        bool isSoft, bool isEncoder, GUID subType)
    {
        IMFActivate **active = nullptr;
        UINT32 activeCount = 0;
        UINT32 flags = (isSoft ? MFT_ENUM_FLAG_SYNCMFT : MFT_ENUM_FLAG_HARDWARE)
            | MFT_ENUM_FLAG_SORTANDFILTER;
        GUID codecCategory = isEncoder ? MFT_CATEGORY_VIDEO_ENCODER : MFT_CATEGORY_VIDEO_DECODER;
        GUID inputSubType = isEncoder ? subType : MFVideoFormat_H264;
        GUID outputSubType = isEncoder ? MFVideoFormat_H264 : subType;
        MFT_REGISTER_TYPE_INFO inputType = { MFMediaType_Video, inputSubType };
        MFT_REGISTER_TYPE_INFO outputType = { MFMediaType_Video, outputSubType };

        HRESULT hr = MFTEnumEx(codecCategory, flags, &inputType, &outputType,
            &active, &activeCount);

        if (SUCCEEDED(hr) && activeCount == 0) {
            return false;
        }

        for (UINT32 index = 0; index < activeCount; ++index) {
            hr = active[index]->ActivateObject(IID_IMFTransform, (void**)&transform);
            if (SUCCEEDED(hr)) {
                break;
            }
        }

        if (NULL != active) {
            for (UINT32 index = 0; index < activeCount; ++index) {
                active[index]->Release();
                active[index] = nullptr;
            }
            CoTaskMemFree(active);
            active = nullptr;
        }

        return hr;
    }

    HRESULT MfHelper::createHardwareH264Encoder(ComPtr<IMFTransform>& transform)
    {
        HRESULT hr = S_OK;
        EXECUTE_IF_SUCCEEDED(hr, createH264Codec(transform, false, true, MFVideoFormat_NV12));
        EXECUTE_IF_SUCCEEDED(hr, unLockAsyncCodec(transform));

        return hr;
    }

    HRESULT MfHelper::createHardwareH264Decoder(ComPtr<IMFTransform>& transform)
    {
        HRESULT hr = S_OK;
        EXECUTE_IF_SUCCEEDED(hr, createH264Codec(transform, false, false, MFVideoFormat_NV12));
        EXECUTE_IF_SUCCEEDED(hr, unLockAsyncCodec(transform));

        return hr;
    }

    HRESULT MfHelper::createSoftwareH264Encoder(ComPtr<IMFTransform>& transform)
    {
        return createH264Codec(transform, true, true, MFVideoFormat_NV12);
    }

    HRESULT MfHelper::createSoftwareH264Decoder(ComPtr<IMFTransform>& transform)
    {
        return createH264Codec(transform, true, false, MFVideoFormat_NV12);
    }

    HRESULT MfHelper::createD3dDeviceManager(ComPtr<IDirect3DDeviceManager9> d3d9Manager)
    {
        HRESULT hr = S_OK;
        UINT resetToken = 0;
        ComPtr<IDirect3D9Ex> d3d9 = nullptr;
        ComPtr<IDirect3DDevice9Ex> d3d9Device = nullptr;
        ComPtr<IDirect3DQuery9> d3d9Query = nullptr;

        EXECUTE_IF_SUCCEEDED(hr, Direct3DCreate9Ex(D3D_SDK_VERSION, &d3d9));
        D3DPRESENT_PARAMETERS params = { 0 };
        params.BackBufferWidth = 1;
        params.BackBufferHeight = 1;
        params.BackBufferFormat = D3DFMT_UNKNOWN;
        params.BackBufferCount = 1;
        params.SwapEffect = D3DSWAPEFFECT_DISCARD;
        params.hDeviceWindow = ::GetShellWindow();
        params.Windowed = TRUE;
        params.Flags = D3DPRESENTFLAG_VIDEO;
        params.FullScreen_RefreshRateInHz = 0;
        params.PresentationInterval = 0;

        EXECUTE_IF_SUCCEEDED(hr, d3d9->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
            ::GetShellWindow(), D3DCREATE_FPU_PRESERVE | D3DCREATE_SOFTWARE_VERTEXPROCESSING |
            D3DCREATE_DISABLE_PSGP_THREADING | D3DCREATE_MULTITHREADED, &params, NULL, &d3d9Device));
        EXECUTE_IF_SUCCEEDED(hr, DXVA2CreateDirect3DDeviceManager9(&resetToken, &d3d9Manager));
        EXECUTE_IF_SUCCEEDED(hr, d3d9Manager->ResetDevice(d3d9Device, resetToken));
        EXECUTE_IF_SUCCEEDED(hr, d3d9Device->CreateQuery(D3DQUERYTYPE_EVENT, &d3d9Query));

        return hr;
    }

    void MfHelper::InitSysEvent()
    {
        rtc::CritScope cs(&sys_init_cs_);
        if (!sys_inited_) {
            RTC_DCHECK(S_OK == CoInitializeEx(NULL, COINIT_APARTMENTTHREADED));
            RTC_DCHECK(S_OK == MFStartup(MF_VERSION));
            sys_inited_ = true;
        }
    }


    bool MfHelper::sys_inited_ = false;
    rtc::CriticalSection MfHelper::sys_init_cs_;

}