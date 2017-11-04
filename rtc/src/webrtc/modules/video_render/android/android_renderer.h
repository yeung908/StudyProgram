#ifndef WEBRTC_MODULES_VIDEO_RENDERER_ANDROID_ANDROID_RENDERER_H_
#define WEBRTC_MODULES_VIDEO_RENDERER_ANDROID_ANDROID_RENDERER_H_

#include "webrtc/modules/video_render/video_renderer.h"
#include "webrtc/modules/utility/include/jvm_android.h"

namespace webrtc
{
class AndroidRenderer : public VideoRenderer
{
public:
	// sink is JavaVideoRendererWrapper
	explicit AndroidRenderer(void* callback);
	virtual ~AndroidRenderer();

	void OnFrame(const webrtc::VideoFrame& frame) override;
private:
	static void JNICALL freeWrappedVideoRenderer(JNIEnv*, jclass, jlong);
	static void JNICALL releaseNativeFrame(JNIEnv*, jclass, jlong);
	static void JNICALL nativeCopyPlane(
			JNIEnv *, jclass, jobject, jint, jint, jint, jobject, jint);
	static jlong JNICALL nativeWrapVideoRenderer(JNIEnv*, jclass, jobject);
private:
	static std::unique_ptr<NativeRegistration> j_video_render_registration_;
	std::unique_ptr<GlobalRef>	j_video_renderer_;
	rtc::VideoSinkInterface<webrtc::VideoFrame> *sink_;
	jmethodID  j_dispose_;
};
}

#endif