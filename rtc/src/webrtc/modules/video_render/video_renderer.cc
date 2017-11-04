/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
#include "webrtc/modules/video_render/video_renderer.h"

// TODO(pbos): Android renderer

#include "webrtc/typedefs.h"

namespace webrtc {

webrtc::VideoRenderObserver * VideoRenderer::cb_ = NULL;
bool VideoRenderer::present_ = true;

class NullRenderer : public VideoRenderer {
  void OnFrame(const VideoFrame& video_frame) override {}
};

VideoRenderer* VideoRenderer::Create(
void* window, size_t width, size_t height, uint32_t ssrc, uint32_t id) {
  VideoRenderer* renderer = CreatePlatformRenderer(window, width, height);
  if (renderer != nullptr) {
      renderer->SetSsrc(ssrc);
      renderer->SetId(id);
      return renderer;
  }

  return new NullRenderer();
}

void VideoRenderer::RegisterVideoRenderCallback(VideoRenderObserver *cb)
{
    cb_ = cb;
}

}  // namespace webrtc
