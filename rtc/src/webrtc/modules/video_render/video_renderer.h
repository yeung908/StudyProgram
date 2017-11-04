/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
#ifndef WEBRTC_TEST_VIDEO_RENDERER_H_
#define WEBRTC_TEST_VIDEO_RENDERER_H_

#include <stddef.h>
#include <stdint.h>
#include "webrtc/media/base/videosinkinterface.h"

namespace webrtc {
class VideoFrame;

class VideoRenderObserver
{
public:
    virtual void onFrameRendered(uint32_t id, uint32_t ssrc, void* surface) = 0;
protected:
    virtual ~VideoRenderObserver() { }
};

class VideoRenderer : public rtc::VideoSinkInterface<VideoFrame> {
 public:
  // Creates a platform-specific renderer if possible, or a null implementation
  // if failing.
  static VideoRenderer* Create(void* window, size_t width, size_t height, uint32_t ssrc = 0, uint32_t=0);

  // Returns a renderer rendering to a platform specific window if possible,
  // NULL if none can be created.
  // Creates a platform-specific renderer if possible, returns NULL if a
  // platform renderer could not be created. This occurs, for instance, when
  // running without an X environment on Linux.
  static VideoRenderer* CreatePlatformRenderer(void* window,
                                               size_t width, size_t height);

  // Destroy a platform-specific renderer.
  static void Destroy(VideoRenderer* renderer);

  // Set video render callback.
  static void RegisterVideoRenderCallback(VideoRenderObserver *cb);

  // Enable render mirror.
  virtual void EnableMirror(bool enable = true) {} 
  
  // Set ssrc
  virtual void SetSsrc(uint32_t ssrc) { ssrc_ = ssrc; }

  // Set ssrc
  virtual void SetId(uint32_t id) { id_ = id; }

  // By default, VideoRenderer will present video. Through disable video 
  // present, discrete app will present video frame instead.
  static void DisableVideoPresent() { present_ = false; }

  virtual ~VideoRenderer() {}

 protected:
  VideoRenderer() {}

  static VideoRenderObserver *cb_;
  uint32_t                    ssrc_;
  uint32_t                    id_;
  static bool                 present_;
};
}  // namespace webrtc

#endif  // WEBRTC_TEST_VIDEO_RENDERER_H_
