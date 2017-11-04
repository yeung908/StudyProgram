#include "webrtc/modules/video_render/android/android_renderer.h"
#include "webrtc/base/arraysize.h"

namespace webrtc
{
	VideoRenderer* VideoRenderer::CreatePlatformRenderer(void* sink,
                                                     size_t width,
                                                     size_t height) {
		return new AndroidRenderer(sink);
	}

	std::unique_ptr<NativeRegistration> AndroidRenderer::j_video_render_registration_ = NULL;
	
	AndroidRenderer::AndroidRenderer(void* callback)
	{
		if (!j_video_render_registration_) {
			JNINativeMethod native_methods[] = {
					{"freeWrappedVideoRenderer", "(J)V",                                              reinterpret_cast<void *>(&freeWrappedVideoRenderer)},
					{"releaseNativeFrame",       "(J)V",                                              reinterpret_cast<void *>(&releaseNativeFrame)},
					{"nativeWrapVideoRenderer",  "(Lorg/webrtc/VideoRenderer$Callbacks;)J",           reinterpret_cast<void *>(&nativeWrapVideoRenderer)},
					{"nativeCopyPlane",          "(Ljava/nio/ByteBuffer;IIILjava/nio/ByteBuffer;I)V", reinterpret_cast<void *>(&nativeCopyPlane)}
			};
			j_video_render_registration_ = JVM::GetInstance()->environment()
					->RegisterNatives("org/webrtc/VideoRenderer", native_methods, arraysize(native_methods));
		}

		j_dispose_ = j_video_render_registration_->GetMethodId("dispose", "()V");
		j_video_renderer_ = j_video_render_registration_
				->NewObject("<init>", "(Lorg/webrtc/VideoRenderer$Callbacks;)V", callback);

		jfieldID nativeWrapperID = j_video_render_registration_->GetFieldId("nativeVideoRenderer", "J");
		jlong nativeWrapper = GetCurrentThreadEnv()->GetLongField(j_video_renderer_->GetRawObject(), nativeWrapperID);
		sink_ = reinterpret_cast<rtc::VideoSinkInterface<webrtc::VideoFrame>*>(nativeWrapper);
	}

	AndroidRenderer::~AndroidRenderer()
	{
		j_video_renderer_->CallVoidMethod(j_dispose_);
	}

	void AndroidRenderer::OnFrame(const webrtc::VideoFrame& frame)
	{
		if(sink_) {
			sink_->OnFrame(frame);
		}
	}
}