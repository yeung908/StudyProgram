/*
 *  Copyright 2015 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_MEDIA_MEDIACODEC_ANDROIDMEDIAENCODER_JNI_H_
#define WEBRTC_MEDIA_MEDIACODEC_ANDROIDMEDIAENCODER_JNI_H_

#include <vector>

#include "webrtc/media/engine/webrtcvideoencoderfactory.h"
#include "webrtc/modules/utility/include/jvm_android.h"

namespace webrtc {

// Implementation of Android MediaCodec based encoder factory.
class MediaCodecVideoEncoderFactory
    : public cricket::WebRtcVideoEncoderFactory {
 public:
  MediaCodecVideoEncoderFactory();
  virtual ~MediaCodecVideoEncoderFactory();

  void SetEGLContext(JNIEnv* jni, jobject egl_context);

  // WebRtcVideoEncoderFactory implementation.
  webrtc::VideoEncoder* CreateVideoEncoder(
      const cricket::VideoCodec& codec) override;
  const std::vector<cricket::VideoCodec>& supported_codecs() const override;
  void DestroyVideoEncoder(webrtc::VideoEncoder* encoder) override;

 private:
  // Disable overloaded virtual function warning. TODO(magjed): Remove once
  // http://crbug/webrtc/6402 is fixed.
  using cricket::WebRtcVideoEncoderFactory::CreateVideoEncoder;

  jobject egl_context_;

  // Empty if platform support is lacking, const after ctor returns.
  std::vector<cricket::VideoCodec> supported_codecs_;
};

}  // namespace cricket

#endif  // WEBRTC_MEDIA_MEDIACODEC_ANDROIDMEDIAENCODER_JNI_H_
