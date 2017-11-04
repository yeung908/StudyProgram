/*
 *  Copyright 2015 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */


#include "webrtc/modules/utility/include/surfacetexturehelper_jni.h"
#include "webrtc/base/bind.h"
#include "webrtc/base/logging.h"

namespace webrtc {
const char* _SurfaceTexturehelperClass = "org/webrtc/SurfaceTextureHelper";
rtc::scoped_refptr<SurfaceTextureHelper> SurfaceTextureHelper::create(
    jstring thread_name,
    jobject j_egl_context) {
  return new rtc::RefCountedObject<SurfaceTextureHelper>(thread_name, j_egl_context);
}

SurfaceTextureHelper::SurfaceTextureHelper(jstring thread_name,
                                           jobject j_egl_context)
    : j_native_registration(JVM::GetInstance()->environment()->RegisterNatives(_SurfaceTexturehelperClass, NULL, 0))
{
  jmethodID createMethod =
          j_native_registration->GetStaticMethodId(
          "create",
          "(Ljava/lang/String;Lorg/webrtc/EglBase$Context;)"
           "Lorg/webrtc/SurfaceTextureHelper;");


  j_return_texture_method_ = j_native_registration->GetMethodId("returnTextureFrame","()V");
  j_dispose_method_ = j_native_registration->GetMethodId("dispose", "()V");

  jobject helper = GetCurrentThreadEnv()->CallStaticObjectMethod(
          j_native_registration->GetClass(), createMethod, thread_name, j_egl_context);
  j_surface_texture_helper_.reset(new GlobalRef(GetEnv(JVM::GetInstance()->jvm()), helper));
}

SurfaceTextureHelper::~SurfaceTextureHelper() {
  LOG(LS_INFO) << "SurfaceTextureHelper dtor";
  j_surface_texture_helper_->CallVoidMethod(j_dispose_method_);
}

jobject SurfaceTextureHelper::GetJavaSurfaceTextureHelper() const {
  return j_surface_texture_helper_->GetRawObject();
}

void SurfaceTextureHelper::ReturnTextureFrame() const {
  JNIEnv* jni = GetCurrentThreadEnv();
  jni->CallVoidMethod(j_surface_texture_helper_->GetRawObject(), j_return_texture_method_);
  CHECK_EXCEPTION(jni) << "error during SurfaceTextureHelper.returnTextureFrame";
}

rtc::scoped_refptr<webrtc::VideoFrameBuffer>
SurfaceTextureHelper::CreateTextureFrame(int width, int height,
    const NativeHandleImpl& native_handle) {
  return new rtc::RefCountedObject<AndroidTextureBuffer>(
      width, height, native_handle, j_surface_texture_helper_->GetRawObject(),
      rtc::Bind(&SurfaceTextureHelper::ReturnTextureFrame, this));
}

}  // namespace webrtc_jni
