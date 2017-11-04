#ifndef WEBRTC_MODULES_VIDEO_CAPTURE_MAIN_SOURCE_ANDROID_VIDEO_CAPTURE_ANDROID_H_
#define WEBRTC_MODULES_VIDEO_CAPTURE_MAIN_SOURCE_ANDROID_VIDEO_CAPTURE_ANDROID_H_

#include <atomic>
#include <webrtc/base/timestampaligner.h>
#include <webrtc/common_video/include/i420_buffer_pool.h>
#include "webrtc/modules/video_capture/android/device_info_android.h"
#include "webrtc/modules/video_capture/video_capture_impl.h"
#include "webrtc/modules/utility/include/surfacetexturehelper_jni.h"

namespace webrtc {
namespace videocapturemodule {
    class VideoCaptureAndroid : public VideoCaptureImpl {
    public:
        VideoCaptureAndroid();

        ~VideoCaptureAndroid();

        virtual int32_t Init(const char *deviceUniqueIdUTF8) ;

        virtual int32_t StartCapture(const VideoCaptureCapability &capability) override;

        virtual int32_t StopCapture() override ;

        virtual bool CaptureStarted() override;

        virtual int32_t CaptureSettings(VideoCaptureCapability &settings) override;

        void OnByteBufferFrameCaptured(const void* frame_data,
                                       int length,
                                       int width,
                                       int height,
                                       int rotation,
                                       int64_t timestamp_ns);

        void OnTextureFrameCaptured(int width,
                                    int height,
                                    int rotation,
                                    int64_t timestamp_ns,
                                    const NativeHandleImpl& handle);

        void OnOutputFormatRequest(int width, int height, int fps);

        void SetCapturing(bool work);

        virtual void SwitchCamera(void* handler) override;

    private:
        static void CheckNativeRegistation();
        static void JNICALL nativeOnByteBufferFrameCaptured(JNIEnv *jni,
                                                            jclass,
                                                            jlong j_source,
                                                            jbyteArray j_frame,
                                                            jint length,
                                                            jint width,
                                                            jint height,
                                                            jint rotation,
                                                            jlong timestamp);
        static void JNICALL nativeOnTextureFrameCaptured(JNIEnv* jni,
                                                         jclass,
                                                         jlong j_source,
                                                         jint j_width,
                                                         jint j_height,
                                                         jint j_oes_texture_id,
                                                         jfloatArray j_transform_matrix,
                                                         jint j_rotation,
                                                         jlong j_timestamp);
        static void JNICALL nativeCapturerStarted(JNIEnv* jni, jclass, jlong j_source, jboolean j_success);
        static void JNICALL nativeCapturerStopped(JNIEnv* jni, jclass, jlong j_source);
        static void JNICALL VideoSource_nativeAdaptOutputFormat(JNIEnv* jni, jclass, jlong j_source, jint j_width, jint j_height, jint j_fps);

    private:
        VideoCaptureCapability                          usedCapabitlity_;
        std::atomic_bool                                capturing_;
        std::unique_ptr<GlobalRef>                      capturer_;
        std::unique_ptr<GlobalRef>                      observer_;
        std::unique_ptr<GlobalRef>                      egl_;
        std::unique_ptr<DeviceInfoAndroid>              info_;
        rtc::ThreadChecker                              thread_checker_;
        rtc::ThreadChecker                              thread_checker_java_;
        AttachCurrentThreadIfNeeded                     attach_thread_if_needed_;
        rtc::scoped_refptr<SurfaceTextureHelper>        surface_texture_helper_;
        rtc::TimestampAligner                           timestamp_aligner_;
        static std::unique_ptr<NativeRegistration>      j_native_registration_;
        static std::unique_ptr<NativeRegistration>      j_observer_registration_;
        static jmethodID                                start_;
        static jmethodID                                stop_;
        static jmethodID                                initialize_;
        static jmethodID                                switch_method_;
    };
}
}

#endif