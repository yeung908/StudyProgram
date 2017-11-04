#include <webrtc/system_wrappers/include/logging.h>
#include "webrtc/modules/video_capture/android/video_capture_android.h"
#include "webrtc/base/arraysize.h"
namespace webrtc
{
namespace videocapturemodule
{
    static const char* AndroidVideoCaptureClass = "org/webrtc/CameraVideoCapturer";
    static const char* ObserverClass = "org/webrtc/VideoCapturer$AndroidVideoTrackSourceObserver";

    std::unique_ptr<NativeRegistration> VideoCaptureAndroid::j_native_registration_ = nullptr;
    std::unique_ptr<NativeRegistration> VideoCaptureAndroid::j_observer_registration_ = nullptr;
    jmethodID VideoCaptureAndroid::start_ = nullptr;
    jmethodID VideoCaptureAndroid::stop_ = nullptr;
    jmethodID VideoCaptureAndroid::initialize_ = nullptr;
    jmethodID VideoCaptureAndroid::switch_method_ = nullptr;

    VideoCaptureAndroid::VideoCaptureAndroid()
        :capturing_(false), capturer_(nullptr), info_(nullptr)
        , observer_(nullptr)
    {
        thread_checker_java_.DetachFromThread();
    }

    int32_t VideoCaptureAndroid::Init(const char *deviceUniqueIdUTF8)
    {
        int32_t ret = -1;
        RTC_DCHECK(thread_checker_.CalledOnValidThread());
        do {
            CheckNativeRegistation();

            info_.reset(DeviceInfoAndroid::Create());
            if (!info_) {
                LOG(LS_ERROR)<< "Can't create deviceinfo";
                break;
            }
            jobject  obj = info_->CreateCapture(deviceUniqueIdUTF8);
            if (!obj) {
                LOG(LS_ERROR)<< "Create capturer failed.";
                break;
            }

            JNIEnv *jni = GetEnv(JVM::GetInstance()->jvm());
            capturer_.reset(new GlobalRef(jni, obj));

            observer_ = j_observer_registration_->NewObject("<init>", "(J)V", PointerTojlong(this));
            if(!observer_) {
                LOG(LS_ERROR)<< "New AndroidVideoTrackSourceObserver object failed";
                break;
            }

            jstring tname = jni->NewStringUTF(deviceUniqueIdUTF8);
            surface_texture_helper_ = SurfaceTextureHelper::create(tname, JVM::GetInstance()->localEGLContext());

            capturer_->CallVoidMethod(initialize_, surface_texture_helper_->GetJavaSurfaceTextureHelper()
                    , JVM::GetInstance()->context(), observer_->GetRawObject());
            size_t nameLength = strlen(deviceUniqueIdUTF8);
            _deviceUniqueId = new char[nameLength + 1];
            strncpy(_deviceUniqueId, deviceUniqueIdUTF8, nameLength);
            _deviceUniqueId[nameLength] = '\0';
            ret = 0;
            if (tname) jni->DeleteLocalRef(tname);
        }while(0);

        return ret;
    }

    int32_t VideoCaptureAndroid::StartCapture(const VideoCaptureCapability &capability) {
        int32_t ret = -1;
        RTC_DCHECK(thread_checker_.CalledOnValidThread());
        if(capturing_ ) {
            ret = 0;
        }else if (capturer_ && start_) {
            _requestedCapability = capability;
            info_->GetBestMatchedCapability(_deviceUniqueId, capability, usedCapabitlity_);
            jint width = usedCapabitlity_.width;
            jint height = usedCapabitlity_.height;
            jint fps = usedCapabitlity_.maxFPS;
            capturer_->CallVoidMethod(start_, width, height, fps);
            capturing_ = true;
            ret = 0;
        }
        return ret;
    }

    int32_t VideoCaptureAndroid::StopCapture() {
        int32_t ret = -1;
        RTC_DCHECK(thread_checker_.CalledOnValidThread());
        if (!capturing_) {
            ret = 0;
        } else if (capturer_ && stop_) {
            capturer_->CallVoidMethod(stop_);
            ret = 0;
        }
        thread_checker_java_.DetachFromThread();
        return ret;
    }

    void VideoCaptureAndroid::SwitchCamera(void *handler) {
        RTC_DCHECK(thread_checker_.CalledOnValidThread());
        if(capturing_ ) {
            capturer_->CallVoidMethod(switch_method_, handler);
        }
    }

    void VideoCaptureAndroid::CheckNativeRegistation() {
        if (!j_native_registration_) {
            j_native_registration_ = JVM::GetInstance()->environment()
                    ->RegisterNatives(AndroidVideoCaptureClass, NULL, 0);

            start_ = j_native_registration_->GetMethodId("startCapture", "(III)V");
            if (!start_) {
                LOG(LS_ERROR)<< "Get startCapture method failed";
            }
            stop_ = j_native_registration_->GetMethodId("stopCapture", "()V");
            if (!stop_) {
                LOG(LS_ERROR)<< "Get stopCapture method failed";
            }

            initialize_ = j_native_registration_->GetMethodId("initialize"
                    , "(Lorg/webrtc/SurfaceTextureHelper;"
                                                                      "Landroid/content/Context;"
                                                                      "Lorg/webrtc/VideoCapturer$CapturerObserver;)V");
            if(!initialize_) {
                LOG(LS_ERROR)<< "Get VideoCapturer initilizeMethod failed";
            }

            switch_method_ = j_native_registration_->GetMethodId(
                    "switchCamera", "(Lorg/webrtc/CameraVideoCapturer$CameraSwitchHandler;)V");
        }
        if(!j_observer_registration_) {
            JNINativeMethod observer_methods[] = {
                    {"nativeOnByteBufferFrameCaptured",
                            "(J[BIIIIJ)V",
                            reinterpret_cast<void *>(&nativeOnByteBufferFrameCaptured)
                    },
                    {"nativeOnTextureFrameCaptured",
                            "(JIII[FIJ)V",
                            reinterpret_cast<void *>(&nativeOnTextureFrameCaptured)
                    },
                    {"nativeCapturerStarted",
                            "(JZ)V",
                            reinterpret_cast<void *>(&nativeCapturerStarted)
                    },
                    {"nativeCapturerStopped",
                            "(J)V",
                            reinterpret_cast<void *>(&nativeCapturerStopped)
                    }


            };
            j_observer_registration_ = JVM::GetInstance()->environment()->
                    RegisterNatives(ObserverClass, observer_methods, arraysize(observer_methods));
        }
    }

    bool VideoCaptureAndroid::CaptureStarted() {
        return capturing_;
    }

    int32_t VideoCaptureAndroid::CaptureSettings(VideoCaptureCapability &settings) {
        settings = usedCapabitlity_;
        return 0;
    }

    void VideoCaptureAndroid::OnByteBufferFrameCaptured(const void *frame_data, int length,
                                                        int width, int height, int rotation,
                                                        int64_t timestamp_ns)
    {
        RTC_DCHECK(thread_checker_java_.CalledOnValidThread());
        RTC_DCHECK(rotation == 0 || rotation == 90 || rotation == 180 || rotation == 270);
        VideoCaptureCapability capability = usedCapabitlity_;
        capability.width = width;
        capability.height = height;

        int64_t camera_time_us = timestamp_ns / rtc::kNumNanosecsPerMicrosec;
        int64_t translated_camera_time_us =
                timestamp_aligner_.TranslateTimestamp(camera_time_us, rtc::TimeMicros());

        const VideoType commonVideoType =RawVideoTypeToCommonVideoVideoType(capability.rawType);

        size_t expectLength =  CalcBufferSize(commonVideoType, width, abs(height));
        if (capability.rawType != kVideoMJPEG && expectLength < length) {
            length = expectLength;
        }

        SetCaptureRotation((VideoRotation)rotation);
        IncomingFrame((uint8_t*)frame_data, length, capability, translated_camera_time_us);
    }

    void VideoCaptureAndroid::SetCapturing(bool work) {
        capturing_ = work;
    }

    void VideoCaptureAndroid::OnTextureFrameCaptured(int width, int height, int rotation,
                                                     int64_t timestamp_ns,
                                                     const NativeHandleImpl &handle) {
        RTC_DCHECK(thread_checker_java_.CalledOnValidThread());
        LOG(LS_WARNING)<< "captured frame";
        VideoCaptureCapability capability = usedCapabitlity_;
        capability.width = width;
        capability.height = height;

        RTC_DCHECK(rotation == 0 || rotation == 90 || rotation == 180 ||
                   rotation == 270);
        
        int64_t camera_time_us = timestamp_ns / rtc::kNumNanosecsPerMicrosec;
        int64_t translated_camera_time_us =
                timestamp_aligner_.TranslateTimestamp(camera_time_us, rtc::TimeMicros());
        
        NativeHandleImpl nativeHandleImpl = NativeHandleImpl(handle.oes_texture_id, handle.sampling_matrix);
        
        if(rotation != 0)
        {
            nativeHandleImpl.sampling_matrix.Rotate(static_cast<webrtc::VideoRotation>(rotation));
            rotation = 0;
        }

        DeliverCapturedFrame(webrtc::VideoFrame(
                surface_texture_helper_->CreateTextureFrame(
                        width, height, nativeHandleImpl),
                static_cast<webrtc::VideoRotation>(rotation), translated_camera_time_us));
    }

    VideoCaptureAndroid::~VideoCaptureAndroid() {
    }

    void VideoCaptureAndroid::OnOutputFormatRequest(int width, int height, int fps) {
        usedCapabitlity_.width = width;
        usedCapabitlity_.height = height;
        usedCapabitlity_.maxFPS = fps;
    }
}
}



