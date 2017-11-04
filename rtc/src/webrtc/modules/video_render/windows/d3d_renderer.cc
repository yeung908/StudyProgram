/*
*  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
*
*  Use of this source code is governed by a BSD-style license
*  that can be found in the LICENSE file in the root of the source
*  tree. An additional intellectual property rights grant can be found
*  in the file PATENTS.  All contributing project authors may
*  be found in the AUTHORS file in the root of the source tree.
*/
#include "webrtc/modules/video_render/windows/d3d_renderer.h"
#include "webrtc/base/checks.h"
#include "webrtc/common_video/libyuv/include/webrtc_libyuv.h"
#include "webrtc/api/video/i420_buffer.h"
#include "../thirdparty/libyuv/include/libyuv.h"
namespace webrtc
{
VideoRenderer* VideoRenderer::CreatePlatformRenderer(void* window,
                                                     size_t width,
                                                     size_t height)
{
    return D3dRenderer::Create(window, width, height);
}

void VideoRenderer::Destroy(VideoRenderer* renderer)
{
    return D3dRenderer::Destroy(dynamic_cast<D3dRenderer*>(renderer));
}

D3dRenderer::D3dRenderer(size_t width, size_t height)
    : width_(width),
    height_(height),
    hwnd_(NULL),
    d3d_(NULL),
    d3d_device_(NULL),
    mirror_(false),
    surface_(NULL)
{
    RTC_DCHECK_GT(width, 0);
    RTC_DCHECK_GT(height, 0);
}

D3dRenderer::~D3dRenderer() { Destroy(); }

void D3dRenderer::EnableMirror(bool enable)
{
    mirror_ = enable;
}

void D3dRenderer::Destroy()
{
    d3d_device_ = NULL;
    d3d_ = NULL;
    hwnd_ = NULL;
}

bool D3dRenderer::Init(void* window)
{
    if ((hwnd_ = (HWND)window) == NULL)
    {
        Destroy();
        return false;
    }

    d3d_ = Direct3DCreate9(D3D_SDK_VERSION);
    if (d3d_ == NULL)
    {
        Destroy();
        return false;
    }

    D3DCAPS9 caps;
    DWORD vertexProcessing;
    d3d_->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);
    if ((caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) == D3DDEVCAPS_HWTRANSFORMANDLIGHT)
    {
        vertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
    }
    else
    {
        vertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
    }

    D3DPRESENT_PARAMETERS d3d_params = {};
    d3d_params.Windowed = TRUE;
    d3d_params.SwapEffect = D3DSWAPEFFECT_COPY;
    d3d_params.BackBufferWidth = width_;
    d3d_params.BackBufferHeight = height_;
    d3d_params.BackBufferFormat = D3DFMT_A8R8G8B8;
    d3d_params.hDeviceWindow = hwnd_;
    if (SUCCEEDED(d3d_->CheckDeviceMultiSampleType(D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL, D3DFMT_R8G8B8, FALSE,
        D3DMULTISAMPLE_2_SAMPLES, NULL)))
    {
        d3d_params.MultiSampleType = D3DMULTISAMPLE_2_SAMPLES;
    }

    IDirect3DDevice9* d3d_device;
    if (d3d_->CreateDevice(D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hwnd_,
        vertexProcessing | D3DCREATE_MULTITHREADED | D3DCREATE_FPU_PRESERVE,
        &d3d_params,
        &d3d_device) != D3D_OK)
    {
        Destroy();
        return false;
    }
    d3d_device_ = d3d_device;
    d3d_device->Release();
    Resize(width_, height_);

    if (present_)
    {
        ShowWindow(hwnd_, SW_SHOWNOACTIVATE);
        d3d_device_->Present(NULL, NULL, NULL, NULL);
    }

    return true;
}

D3dRenderer * D3dRenderer::Create(void * window, size_t widht, size_t height)
{
    D3dRenderer* d3d_renderer = new D3dRenderer(widht, height);
    if (!d3d_renderer->Init(window))
    {
        delete d3d_renderer;
        return NULL;
    }

    return d3d_renderer;;
}

void D3dRenderer::Destroy(D3dRenderer * renderer)
{
    delete renderer;
}

void D3dRenderer::Resize(size_t width, size_t height)
{
    surfaceWidth_ = width;
    surfaceHeight_ = height;
    IDirect3DSurface9* surface = nullptr;
    D3DFORMAT format;
    if (present_)
    {
        format = (D3DFORMAT)MAKEFOURCC('Y', 'V', '1', '2');
        d3d_device_->CreateOffscreenPlainSurface(surfaceWidth_, surfaceHeight_, format, D3DPOOL_DEFAULT, &surface, NULL);
    }
    else
    {
        format = D3DFMT_A8R8G8B8;
        d3d_device_->CreateRenderTarget(surfaceWidth_, surfaceHeight_, format, D3DMULTISAMPLE_NONE, 0, TRUE, &surface, NULL);
    }

    surface_ = surface;
    surface->Release();
}

void D3dRenderer::OnFrame(const webrtc::VideoFrame& frame)
{
    if (present_)
    {
        if (!RenderYUVSurface(frame, surface_.get(), width_, height_))
        {
            return;
        }
        d3d_device_->BeginScene();
        {
            rtc::scoped_refptr<IDirect3DSurface9> backSurface;
            IDirect3DSurface9* tempBackSurface;
            if (d3d_device_->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &tempBackSurface) != D3D_OK)
            {
                d3d_device_->EndScene();
                return;
            }
            backSurface = tempBackSurface;
            tempBackSurface->Release();
            d3d_device_->StretchRect(surface_, NULL, backSurface.get(), NULL, D3DTEXF_POINT);
            //d3d_device_->UpdateSurface(surface_, NULL, backSurface.get(), NULL);
        }

        d3d_device_->EndScene();
        d3d_device_->Present(NULL, NULL, NULL, NULL);
    }
    else
    {
        if (cb_)
        {
            if (frame.width() != surfaceWidth_ || frame.height() != surfaceHeight_)
            {
                Resize(frame.width(), frame.height());
            }
            if (RenderRGBSurface(frame, surface_.get(), frame.width(), frame.height()))
            {
                cb_->onFrameRendered(id_, ssrc_, surface_.get());
            }
        }
    }
}
bool D3dRenderer::RenderYUVSurface(const webrtc::VideoFrame & frame, IDirect3DSurface9 * surface, int renderWidth, int renderHeight)
{
    D3DLOCKED_RECT lock_rect;
    if (surface_->LockRect(&lock_rect, NULL, D3DLOCK_DONOTWAIT) != D3D_OK)
    {
        return false;
    }
    int frameW = frame.width();
    int frameH = frame.height();

    rtc::scoped_refptr<webrtc::VideoFrameBuffer> storebuffer = frame.video_frame_buffer();
    if (renderWidth != frame.width() || renderHeight != frame.height())
    {
        rtc::scoped_refptr<webrtc::I420Buffer> buffer =
            webrtc::I420Buffer::Create(renderWidth, renderHeight);
        libyuv::I420Scale(frame.video_frame_buffer()->DataY(),
                          frame.video_frame_buffer()->StrideY(),
                          frame.video_frame_buffer()->DataU(),
                          frame.video_frame_buffer()->StrideU(),
                          frame.video_frame_buffer()->DataV(),
                          frame.video_frame_buffer()->StrideV(),
                          frame.width(), frame.height(),
                          buffer->MutableDataY(), buffer->StrideY(),
                          buffer->MutableDataU(), buffer->StrideU(),
                          buffer->MutableDataV(), buffer->StrideV(), renderWidth, renderHeight, libyuv::kFilterBox);
        storebuffer = buffer;
    }
    if (mirror_)
    {
        rtc::scoped_refptr<webrtc::I420Buffer> buffer =
            webrtc::I420Buffer::Create(renderWidth, renderHeight);
        I420ToMirror(storebuffer->DataY(),
                     storebuffer->StrideY(),
                     storebuffer->DataU(),
                     storebuffer->StrideU(),
                     storebuffer->DataV(),
                     storebuffer->StrideV(),
                     buffer->MutableDataY(), buffer->StrideY(),
                     buffer->MutableDataU(), buffer->StrideU(),
                     buffer->MutableDataV(), buffer->StrideV(),
                     renderWidth, renderHeight);
        storebuffer = buffer;
    }

    char * pDest = reinterpret_cast<char*>(lock_rect.pBits);
    const char * pSrc = reinterpret_cast<const char*>(storebuffer->DataY());

    int deststride = lock_rect.Pitch;
    int srcstride = storebuffer->StrideY();
    int width = renderHeight * frameW / frameH;
    int fillSize = (renderWidth - width) / 2;
    int height = renderHeight;
    int fillSizeUV = fillSize / 2;

    for (unsigned int i = 0; i < height; i++)
    {
        memcpy(pDest + fillSize, pSrc, width);
        pDest += deststride;
        pSrc += srcstride;
    }

    pSrc = reinterpret_cast<const char*>(storebuffer->DataV());
    deststride = lock_rect.Pitch / 2;
    srcstride = storebuffer->StrideV();

    height = renderHeight / 2;
    for (int i = 0; i < height; i++)
    {
        memset(pDest, 128, fillSizeUV);
        memcpy(pDest + fillSizeUV, pSrc, width / 2);
        memset(pDest + fillSizeUV + width / 2, 128, fillSizeUV);
        pDest += deststride;
        pSrc += srcstride;
    }

    //拷贝V通道的数据
    pSrc = reinterpret_cast<const char*>(storebuffer->DataU());
    srcstride = storebuffer->StrideU();
    for (int i = 0; i < height; i++)
    {
        memset(pDest, 128, fillSizeUV);
        memcpy(pDest + fillSizeUV, pSrc, width / 2);
        memset(pDest + fillSizeUV + width / 2, 128, fillSizeUV);

        pDest += deststride;
        pSrc += srcstride;
    }
    surface_->UnlockRect();
    return true;
}

bool D3dRenderer::RenderRGBSurface(const webrtc::VideoFrame & frame, IDirect3DSurface9 * surface, int renderWidth, int renderHeight)
{
    D3DLOCKED_RECT lock_rect;
    HRESULT h = surface_->LockRect(&lock_rect, NULL, D3DLOCK_NO_DIRTY_UPDATE);
    if (h != D3D_OK)
    {
        return false;
    }
    int frameW = frame.width();
    int frameH = frame.height();

    rtc::scoped_refptr<webrtc::VideoFrameBuffer> storebuffer = frame.video_frame_buffer();
    if (renderWidth != frame.width() || renderHeight != frame.height())
    {
        rtc::scoped_refptr<webrtc::I420Buffer> buffer =
            webrtc::I420Buffer::Create(renderWidth, renderHeight);
        libyuv::I420Scale(frame.video_frame_buffer()->DataY(),
                          frame.video_frame_buffer()->StrideY(),
                          frame.video_frame_buffer()->DataU(),
                          frame.video_frame_buffer()->StrideU(),
                          frame.video_frame_buffer()->DataV(),
                          frame.video_frame_buffer()->StrideV(),
                          frame.width(), frame.height(),
                          buffer->MutableDataY(), buffer->StrideY(),
                          buffer->MutableDataU(), buffer->StrideU(),
                          buffer->MutableDataV(), buffer->StrideV(), renderWidth, renderHeight, libyuv::kFilterBox);
        storebuffer = buffer;
    }
    if (mirror_)
    {
        rtc::scoped_refptr<webrtc::I420Buffer> buffer =
            webrtc::I420Buffer::Create(renderWidth, renderHeight);
        I420ToMirror(storebuffer->DataY(),
                     storebuffer->StrideY(),
                     storebuffer->DataU(),
                     storebuffer->StrideU(),
                     storebuffer->DataV(),
                     storebuffer->StrideV(),
                     buffer->MutableDataY(), buffer->StrideY(),
                     buffer->MutableDataU(), buffer->StrideU(),
                     buffer->MutableDataV(), buffer->StrideV(),
                     renderWidth, renderHeight);
        storebuffer = buffer;
    }

    int width = renderHeight * frameW / frameH;
    int height = renderHeight;
    int fillSize = (renderWidth - width) / 2;
    int fillSizeUV = fillSize / 2;

    rtc::scoped_refptr<webrtc::I420Buffer> bigbuffer =
        webrtc::I420Buffer::Create(renderWidth + fillSize * 2, renderHeight + fillSize * 2);

    int deststride = bigbuffer->StrideY();
    int srcstride = storebuffer->StrideY();
    char * pDest = reinterpret_cast<char*>(bigbuffer->MutableDataY());
    const char * pSrc = reinterpret_cast<const char*>(storebuffer->DataY());

    for (unsigned int i = 0; i < height; i++)
    {
        memcpy(pDest + fillSize, pSrc, width);
        pDest += deststride;
        pSrc += srcstride;
    }

    pDest = reinterpret_cast<char*>(bigbuffer->MutableDataV());
    pSrc = reinterpret_cast<const char*>(storebuffer->DataV());
    deststride = bigbuffer->StrideV();
    srcstride = storebuffer->StrideV();

    height = renderHeight / 2;
    for (int i = 0; i < height; i++)
    {
        memset(pDest, 128, fillSizeUV);
        memcpy(pDest + fillSizeUV, pSrc, width / 2);
        memset(pDest + fillSizeUV + width / 2, 128, fillSizeUV);
        pDest += deststride;
        pSrc += srcstride;
    }

    //拷贝V通道的数据
    pDest = reinterpret_cast<char*>(bigbuffer->MutableDataU());
    pSrc = reinterpret_cast<const char*>(storebuffer->DataU());
    deststride = bigbuffer->StrideV();
    srcstride = storebuffer->StrideU();
    for (int i = 0; i < height; i++)
    {
        memset(pDest, 128, fillSizeUV);
        memcpy(pDest + fillSizeUV, pSrc, width / 2);
        memset(pDest + fillSizeUV + width / 2, 128, fillSizeUV);

        pDest += deststride;
        pSrc += srcstride;
    }

    webrtc::VideoFrame rgb(bigbuffer, frame.rotation(), frame.timestamp_us());

    webrtc::ConvertFromI420(rgb, kARGB, lock_rect.Pitch, static_cast<uint8_t*>(lock_rect.pBits));
    surface_->UnlockRect();
    return true;
}
}  // namespace webrtc
