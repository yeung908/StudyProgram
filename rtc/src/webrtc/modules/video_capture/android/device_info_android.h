#ifndef WEBRTC_MODULES_VIDEO_CAPTURE_MAIN_SOURCE_ANDROID_DEVICE_INFO_ANDROID_H_
#define WEBRTC_MODULES_VIDEO_CAPTURE_MAIN_SOURCE_ANDROID_DEVICE_INFO_ANDROID_H_

#include "webrtc/modules/video_capture/device_info_impl.h"
#include "webrtc/modules/video_capture/video_capture_impl.h"
#include "webrtc/modules/utility/include/jvm_android.h"

namespace webrtc
{
namespace videocapturemodule
{
class DeviceInfoAndroid : public DeviceInfoImpl
{
public:
    class JavaDeviceInfo
    {
    public:
        JavaDeviceInfo(NativeRegistration* native_registration,
                       std::unique_ptr<GlobalRef> enumerator);
        ~JavaDeviceInfo();

        jobjectArray getDeviceNames();
        jobject getSupportFormats(jstring id);
        jobject createCapture(jstring id);
    private:
        std::unique_ptr<GlobalRef> enumerator_;
        jmethodID get_devices_names_;
        jmethodID get_formats_;
        jmethodID create_capture_;
    };
    static DeviceInfoAndroid* Create();

    virtual int32_t Init() override;
    virtual int32_t CreateCapabilityMap(const char* deviceUniqueIdUTF8) override;

    virtual uint32_t NumberOfDevices() override;

    /*
    * Returns the available capture devices.
    */
    virtual int32_t
        GetDeviceName(uint32_t deviceNumber,
                      char* deviceNameUTF8,
                      uint32_t deviceNameLength,
                      char* deviceUniqueIdUTF8,
                      uint32_t deviceUniqueIdUTF8Length,
                      char* productUniqueIdUTF8,
                      uint32_t productUniqueIdUTF8Length) override;

      /*
      * Display OS /capture device specific settings dialog
      */
    virtual int32_t
        DisplayCaptureSettingsDialogBox(
            const char* deviceUniqueIdUTF8,
            const char* dialogTitleUTF8,
            void* parentWindow,
            uint32_t positionX,
            uint32_t positionY) override
    {
        return -1;
    }

    ~DeviceInfoAndroid();

    jobject CreateCapture(const char* deviceUniqueIdUTF8);

private:
    DeviceInfoAndroid();
    RawVideoType ImageForamt2RawVideoType(int foramt);

    static std::string _camera1ClassName;
    static std::string _camera2ClassName;

    // Stores thread ID in constructor.
    rtc::ThreadChecker thread_checker_;

    // Stores thread ID in first call to OnDataIsRecorded() from high-priority
    // thread in Java. Detached during construction of this object.
    rtc::ThreadChecker thread_checker_java_;

    // Calls AttachCurrentThread() if this thread is not attached at construction.
    // Also ensures that DetachCurrentThread() is called at destruction.
    AttachCurrentThreadIfNeeded attach_thread_if_needed_;

    // Wraps the JNI interface pointer and methods associated with it.
    std::unique_ptr<JNIEnvironment> j_environment_;
    // Contains factory method for creating the Java object.
    std::unique_ptr<NativeRegistration> j_native_registration_;
    std::unique_ptr<DeviceInfoAndroid::JavaDeviceInfo> j_device_info_;
};
}
}

#endif
