#include <jni.h>
#include <webrtc/system_wrappers/include/logging.h>
#include "webrtc/modules/video_capture/android/video_capture_android.h"


namespace webrtc {
namespace videocapturemodule {
    void VideoCaptureAndroid::nativeOnByteBufferFrameCaptured
    (JNIEnv *jni,
     jclass,
     jlong j_source,
     jbyteArray j_frame,
     jint length,
     jint width,
     jint height,
     jint rotation,
     jlong timestamp) {
        auto capture = reinterpret_cast<VideoCaptureAndroid *>(j_source);
        jbyte *bytes = jni->GetByteArrayElements(j_frame, nullptr);
        capture->OnByteBufferFrameCaptured(bytes, length, width, height, rotation,
                                          timestamp);
        jni->ReleaseByteArrayElements(j_frame, bytes, JNI_ABORT);
    }

    void VideoCaptureAndroid::nativeOnTextureFrameCaptured
    (JNIEnv* jni,
     jclass,
     jlong j_source,
     jint j_width,
     jint j_height,
     jint j_oes_texture_id,
     jfloatArray j_transform_matrix,
     jint j_rotation,
     jlong j_timestamp) {
        auto capture = reinterpret_cast<VideoCaptureAndroid *>(j_source);
        capture->OnTextureFrameCaptured(
                j_width, j_height, j_rotation, j_timestamp,
                NativeHandleImpl(jni, j_oes_texture_id, j_transform_matrix));
    }

    void VideoCaptureAndroid::nativeCapturerStarted
    (JNIEnv* jni, jclass, jlong j_source, jboolean j_success) {
        LOG(LS_INFO) << "AndroidVideoTrackSourceObserve_nativeCapturerStarted";
        auto capture = reinterpret_cast<VideoCaptureAndroid *>(j_source);
        capture->SetCapturing(j_success);
    }

    void VideoCaptureAndroid::nativeCapturerStopped
    (JNIEnv* jni, jclass, jlong j_source) {
        LOG(LS_INFO) << "AndroidVideoTrackSourceObserve_nativeCapturerStopped";
        auto capture = reinterpret_cast<VideoCaptureAndroid *>(j_source);
        capture->SetCapturing(false);
    }

    void VideoCaptureAndroid::VideoSource_nativeAdaptOutputFormat
    (JNIEnv* jni, jclass, jlong j_source, jint j_width, jint j_height, jint j_fps) {
        LOG(LS_INFO) << "VideoSource_nativeAdaptOutputFormat";
        auto capture = reinterpret_cast<VideoCaptureAndroid *>(j_source);
        capture->OnOutputFormatRequest(j_width, j_height, j_fps);
    }
}
}