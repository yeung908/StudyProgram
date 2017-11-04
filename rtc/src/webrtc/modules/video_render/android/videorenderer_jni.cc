#include "webrtc/api/video/video_frame.h"
#include "webrtc/modules/utility/include/native_handle_impl.h"
#include "webrtc/media/base/videosinkinterface.h"
#include "webrtc/modules/video_render/android/android_renderer.h"

namespace webrtc {
    class JavaVideoRendererWrapper
            : public rtc::VideoSinkInterface<webrtc::VideoFrame> {
    public:
        JavaVideoRendererWrapper(JNIEnv *jni, jobject j_callbacks)
                : j_callbacks_(jni, j_callbacks),
                  j_render_frame_id_(GetMethodID(
                          jni, GetObjectClass(jni, j_callbacks), "renderFrame",
                          "(Lorg/webrtc/VideoRenderer$I420Frame;)V")),
                  j_frame_class_(jni,
                                 FindClass(jni, "org/webrtc/VideoRenderer$I420Frame")),
                  j_i420_frame_ctor_id_(GetMethodID(
                          jni, *j_frame_class_, "<init>", "(III[I[Ljava/nio/ByteBuffer;J)V")),
                  j_texture_frame_ctor_id_(GetMethodID(
                          jni, *j_frame_class_, "<init>",
                          "(IIII[FJ)V")),
                  j_byte_buffer_class_(jni, FindClass(jni, "java/nio/ByteBuffer")) {
            CHECK_EXCEPTION(jni);
        }

        virtual ~JavaVideoRendererWrapper() { }

        void OnFrame(const webrtc::VideoFrame &video_frame) override {
            ScopedLocalRefFrame local_ref_frame(jni());
            jobject j_frame =
                    (video_frame.video_frame_buffer()->native_handle() != nullptr)
                    ? CricketToJavaTextureFrame(&video_frame)
                    : CricketToJavaI420Frame(&video_frame);
            // |j_callbacks_| is responsible for releasing |j_frame| with
            // VideoRenderer.renderFrameDone().
            jni()->CallVoidMethod(*j_callbacks_, j_render_frame_id_, j_frame);
            CHECK_EXCEPTION(jni());
        }

    private:
        // Make a shallow copy of |frame| to be used with Java. The callee has
        // ownership of the frame, and the frame should be released with
        // VideoRenderer.releaseNativeFrame().
        static jlong javaShallowCopy(const webrtc::VideoFrame *frame) {
            return PointerTojlong(new webrtc::VideoFrame(*frame));
        }

        // Return a VideoRenderer.I420Frame referring to the data in |frame|.
        jobject CricketToJavaI420Frame(const webrtc::VideoFrame *frame) {
            jintArray strides = jni()->NewIntArray(3);
            jint *strides_array = jni()->GetIntArrayElements(strides, NULL);
            strides_array[0] = frame->video_frame_buffer()->StrideY();
            strides_array[1] = frame->video_frame_buffer()->StrideU();
            strides_array[2] = frame->video_frame_buffer()->StrideV();
            jni()->ReleaseIntArrayElements(strides, strides_array, 0);
            jobjectArray planes = jni()->NewObjectArray(3, *j_byte_buffer_class_, NULL);
            jobject y_buffer = jni()->NewDirectByteBuffer(
                    const_cast<uint8_t *>(frame->video_frame_buffer()->DataY()),
                    frame->video_frame_buffer()->StrideY() *
                    frame->video_frame_buffer()->height());
            size_t chroma_height = (frame->height() + 1) / 2;
            jobject u_buffer = jni()->NewDirectByteBuffer(
                    const_cast<uint8_t *>(frame->video_frame_buffer()->DataU()),
                    frame->video_frame_buffer()->StrideU() * chroma_height);
            jobject v_buffer = jni()->NewDirectByteBuffer(
                    const_cast<uint8_t *>(frame->video_frame_buffer()->DataV()),
                    frame->video_frame_buffer()->StrideV() * chroma_height);

            jni()->SetObjectArrayElement(planes, 0, y_buffer);
            jni()->SetObjectArrayElement(planes, 1, u_buffer);
            jni()->SetObjectArrayElement(planes, 2, v_buffer);
            return jni()->NewObject(
                    *j_frame_class_, j_i420_frame_ctor_id_,
                    frame->width(), frame->height(),
                    static_cast<int>(frame->rotation()),
                    strides, planes, javaShallowCopy(frame));
        }

        // Return a VideoRenderer.I420Frame referring texture object in |frame|.
        jobject CricketToJavaTextureFrame(const webrtc::VideoFrame *frame) {
            NativeHandleImpl *handle = reinterpret_cast<NativeHandleImpl *>(
                    frame->video_frame_buffer()->native_handle());
            jfloatArray sampling_matrix = handle->sampling_matrix.ToJava(jni());

            return jni()->NewObject(
                    *j_frame_class_, j_texture_frame_ctor_id_,
                    frame->width(), frame->height(),
                    static_cast<int>(frame->rotation()),
                    handle->oes_texture_id, sampling_matrix, javaShallowCopy(frame));
        }

        JNIEnv *jni() {
            return GetCurrentThreadEnv();
        }

        ScopedGlobalRef<jobject> j_callbacks_;
        jmethodID j_render_frame_id_;
        ScopedGlobalRef<jclass> j_frame_class_;
        jmethodID j_i420_frame_ctor_id_;
        jmethodID j_texture_frame_ctor_id_;
        ScopedGlobalRef<jclass> j_byte_buffer_class_;
    };

    void AndroidRenderer::freeWrappedVideoRenderer(JNIEnv *, jclass, jlong j_p) {
        delete reinterpret_cast<JavaVideoRendererWrapper *>(j_p);
    }

    void AndroidRenderer::releaseNativeFrame(
            JNIEnv *jni, jclass, jlong j_frame_ptr) {
        delete reinterpret_cast<const webrtc::VideoFrame *>(j_frame_ptr);
    }

    jlong AndroidRenderer::nativeWrapVideoRenderer (
            JNIEnv *jni, jclass, jobject j_callbacks) {
        std::unique_ptr<JavaVideoRendererWrapper> renderer(
                new JavaVideoRendererWrapper(jni, j_callbacks));
        return (jlong) renderer.release();
    }

    void AndroidRenderer::nativeCopyPlane(
            JNIEnv *jni, jclass, jobject j_src_buffer, jint width, jint height,
            jint src_stride, jobject j_dst_buffer, jint dst_stride) {
        size_t src_size = jni->GetDirectBufferCapacity(j_src_buffer);
        size_t dst_size = jni->GetDirectBufferCapacity(j_dst_buffer);
        RTC_CHECK(src_stride >= width) << "Wrong source stride " << src_stride;
        RTC_CHECK(dst_stride >= width) << "Wrong destination stride " << dst_stride;
        RTC_CHECK(src_size >= src_stride * height)
        << "Insufficient source buffer capacity " << src_size;
        RTC_CHECK(dst_size >= dst_stride * height)
        << "Insufficient destination buffer capacity " << dst_size;
        uint8_t *src =
                reinterpret_cast<uint8_t *>(jni->GetDirectBufferAddress(j_src_buffer));
        uint8_t *dst =
                reinterpret_cast<uint8_t *>(jni->GetDirectBufferAddress(j_dst_buffer));
        if (src_stride == dst_stride) {
            memcpy(dst, src, src_stride * height);
        } else {
            for (int i = 0; i < height; i++) {
                memcpy(dst, src, width);
                src += src_stride;
                dst += dst_stride;
            }
        }
    }
}