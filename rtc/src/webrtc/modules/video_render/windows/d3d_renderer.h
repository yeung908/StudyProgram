/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
#ifndef WEBRTC_TEST_WIN_D3D_RENDERER_H_
#define WEBRTC_TEST_WIN_D3D_RENDERER_H_

#include <Windows.h>
#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")       // located in DirectX SDK

#include "webrtc/base/scoped_ref_ptr.h"
#include "webrtc/modules/video_render/video_renderer.h"
#include "webrtc/typedefs.h"

namespace webrtc
{
class D3dRenderer : public VideoRenderer
{
public:
    static D3dRenderer* Create(void* window, size_t width, size_t height);
    static void Destroy(D3dRenderer* renderer);

    virtual ~D3dRenderer();
    virtual void EnableMirror(bool enable) override;
    void OnFrame(const webrtc::VideoFrame& frame) override;
    bool RenderYUVSurface(const webrtc::VideoFrame& frame, IDirect3DSurface9 * surface,int renderWidth, int renderHeight);
    bool RenderRGBSurface(const webrtc::VideoFrame& frame, IDirect3DSurface9 * surface, int renderRidth, int renderHeight);
private:
    D3dRenderer(size_t width, size_t height);

    bool Init(void* window);
    void Resize(size_t width, size_t height);
    void Destroy();
    size_t width_;
    size_t height_;
    size_t surfaceWidth_;
    size_t surfaceHeight_;
    bool mirror_;

    HWND hwnd_;
    rtc::scoped_refptr<IDirect3D9> d3d_;
    rtc::scoped_refptr<IDirect3DDevice9> d3d_device_;
    rtc::scoped_refptr<IDirect3DSurface9> surface_;
};
}  // namespace webrtc

#endif  // WEBRTC_TEST_WIN_D3D_RENDERER_H_
