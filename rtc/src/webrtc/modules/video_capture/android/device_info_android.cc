#include "webrtc/modules/video_capture/android/device_info_android.h"
#include "webrtc/system_wrappers/include/trace.h"
#include "webrtc/modules/utility/include/android_version_helper.h"

namespace webrtc
{
namespace videocapturemodule
{
std::string DeviceInfoAndroid::_camera1ClassName("org/webrtc/Camera1Enumerator");
std::string DeviceInfoAndroid::_camera2ClassName("org/webrtc/Camera2Enumerator");

DeviceInfoAndroid::DeviceInfoAndroid()
    :j_environment_(JVM::GetInstance()->environment())
    , j_native_registration_(nullptr)
    , j_device_info_(nullptr)
{
}

DeviceInfoAndroid::~DeviceInfoAndroid() { }

DeviceInfoAndroid *DeviceInfoAndroid::Create()
{
    DeviceInfoAndroid *info = new DeviceInfoAndroid();
    if (info && 0 != info->Init())
    {
        delete info;
        info = nullptr;
    }

    return info;
}

int32_t DeviceInfoAndroid::Init()
{
    RTC_DCHECK(thread_checker_.CalledOnValidThread());
    int version = AndroidSDKVersion();

    j_native_registration_ =
        j_environment_->RegisterNatives(_camera1ClassName.c_str(), NULL, 0);
    j_device_info_.reset(new JavaDeviceInfo(j_native_registration_.get()
                                            , j_native_registration_->NewObject("<init>", "(Z)V", JNI_TRUE)));

    return 0;
}

int32_t DeviceInfoAndroid::GetDeviceName(uint32_t deviceNumber,
                                         char *deviceNameUTF8,
                                         uint32_t deviceNameLength,
                                         char *deviceUniqueIdUTF8,
                                         uint32_t deviceUniqueIdUTF8Length,
                                         char *productUniqueIdUTF8,
                                         uint32_t productUniqueIdUTF8Length)
{
    int32_t ret = -1;
    RTC_DCHECK(thread_checker_.CalledOnValidThread());

    JNIEnv *jni = GetEnv(JVM::GetInstance()->jvm());
    jobjectArray  devices = j_device_info_->getDeviceNames();
    if (devices)
    {
        int count = jni->GetArrayLength(devices);
        if (deviceNumber >= 0 && deviceNumber < count)
        {
            jstring name = (jstring)jni->GetObjectArrayElement(devices, jsize(deviceNumber));
            std::string  device = JavaToStdString(jni, name);
            if (name)
            {
                jni->DeleteLocalRef(name);
            }
            if (deviceNameLength >= device.size() && deviceNameUTF8
                && deviceUniqueIdUTF8 && deviceUniqueIdUTF8Length >= device.size())
            {
                strncpy(deviceNameUTF8, device.c_str(), device.size());
                strncpy(deviceUniqueIdUTF8, device.c_str(), device.size());
                ret = 0;
            }
            jni->DeleteLocalRef(devices);
        }
    }
    return ret;
}

uint32_t DeviceInfoAndroid::NumberOfDevices()
{
    uint32_t count = 0;
    RTC_DCHECK(thread_checker_.CalledOnValidThread());

    JNIEnv *jni = GetEnv(JVM::GetInstance()->jvm());
    jobjectArray  devices = j_device_info_->getDeviceNames();
    if (devices)
    {
        count = jni->GetArrayLength(devices);
        jni->DeleteLocalRef(devices);
    }
    return count;
}

int32_t DeviceInfoAndroid::CreateCapabilityMap(const char* deviceUniqueIdUTF8)
{
    int ret = -1;
    _captureCapabilities.clear();

    const int32_t deviceUniqueIdUTF8Length =
        (int32_t)strlen((char*)deviceUniqueIdUTF8);
    if (deviceUniqueIdUTF8Length > kVideoCaptureUniqueNameLength)
    {
        WEBRTC_TRACE(webrtc::kTraceError, webrtc::kTraceVideoCapture, 0,
                     "Device name too long");
        return -1;
    }
    WEBRTC_TRACE(webrtc::kTraceInfo, webrtc::kTraceVideoCapture, 0,
                 "CreateCapabilityMap called for device %s", deviceUniqueIdUTF8);

    RTC_DCHECK(thread_checker_.CalledOnValidThread());

    JNIEnv *jni = GetEnv(JVM::GetInstance()->jvm());
    jstring id = jni->NewStringUTF(deviceUniqueIdUTF8);
    jobject formats = j_device_info_->getSupportFormats(id);
    jni->DeleteLocalRef(id);

    jclass listClass = jni->FindClass("java/util/List");
    jmethodID listGetMethod = GetMethodID(jni, listClass, "get", "(I)Ljava/lang/Object;");
    jmethodID listSizeMethod = GetMethodID(jni, listClass, "size", "()I");

    std::unique_ptr<NativeRegistration> formatClass = j_environment_->RegisterNatives(
        "org/webrtc/CameraEnumerationAndroid$CaptureFormat", NULL, 0);
    std::unique_ptr<NativeRegistration> rateRangeClass = j_environment_->RegisterNatives(
        "org/webrtc/CameraEnumerationAndroid$CaptureFormat$FramerateRange", NULL, 0);
    jfieldID widthField = formatClass->GetFieldId("width", "I");
    jfieldID heightField = formatClass->GetFieldId("height", "I");
    jfieldID imageFormatField = formatClass->GetFieldId("imageFormat", "I");
    jfieldID rateField = formatClass->GetFieldId("framerate"
                                                 , "Lorg/webrtc/CameraEnumerationAndroid$CaptureFormat$FramerateRange;");
    jfieldID minRateField = rateRangeClass->GetFieldId("min", "I");
    jfieldID maxRateField = rateRangeClass->GetFieldId("max", "I");

    int width, height, minfps, maxfps, color;
    VideoCaptureCapability cap;
    int count = jni->CallIntMethod(formats, listSizeMethod);
    for (int i = 0; i < count; ++i)
    {
        jobject capbility = jni->CallObjectMethod(formats, listGetMethod, i);
        cap.width = jni->GetIntField(capbility, widthField);
        cap.height = jni->GetIntField(capbility, heightField);
        cap.rawType = ImageForamt2RawVideoType(jni->GetIntField(capbility, imageFormatField));
        jobject frameRate = jni->GetObjectField(capbility, rateField);
        cap.maxFPS = jni->GetIntField(frameRate, maxRateField) / 1000;
        cap.interlaced = false;
        cap.expectedCaptureDelay = kDefaultCaptureDelay;

        _captureCapabilities.push_back(cap);
        jni->DeleteLocalRef(capbility);
        jni->DeleteLocalRef(frameRate);
    }
    ret = _captureCapabilities.size();

    if (listClass) jni->DeleteLocalRef(listClass);
    if (formats) jni->DeleteLocalRef(formats);

    return ret;
}

RawVideoType DeviceInfoAndroid::ImageForamt2RawVideoType(int foramt)
{
    RawVideoType type = kVideoUnknown;
    switch (foramt)
    {
    case 256: type = kVideoMJPEG; break;
    case 16: type = kVideoNV12; break;
    case 17: type = kVideoNV21; break;
    case 4: type = kVideoRGB565; break;
    case 35: type = kVideoI420; break;
    case 20: type = kVideoYUY2; break;
    case 842094169: type = kVideoYV12; break;
    default:
        break;
    }
    return type;
}

jobject DeviceInfoAndroid::CreateCapture(const char *deviceUniqueIdUTF8)
{
    RTC_DCHECK(thread_checker_.CalledOnValidThread());
    JNIEnv *jni = GetEnv(JVM::GetInstance()->jvm());
    jstring id = jni->NewStringUTF(deviceUniqueIdUTF8);
    jobject capturer = j_device_info_->createCapture(id);
    jni->DeleteLocalRef(id);
    return capturer;
}

DeviceInfoAndroid::JavaDeviceInfo::JavaDeviceInfo(
    webrtc::NativeRegistration *native_registration,
    std::unique_ptr<webrtc::GlobalRef> enumerator)
    : enumerator_(std::move(enumerator))
    , get_devices_names_(native_registration->GetMethodId("getDeviceNames", "()[Ljava/lang/String;"))
    , get_formats_(native_registration->GetMethodId("getSupportedFormats", "(Ljava/lang/String;)Ljava/util/List;"))
    , create_capture_(native_registration->GetMethodId("createCapturer", "(Ljava/lang/String;Lorg/webrtc/CameraVideoCapturer$CameraEventsHandler;)Lorg/webrtc/CameraVideoCapturer;"))
{
}

DeviceInfoAndroid::JavaDeviceInfo::~JavaDeviceInfo()
{
}

jobjectArray DeviceInfoAndroid::JavaDeviceInfo::getDeviceNames()
{
    return (jobjectArray)enumerator_->CallObjectMethod(get_devices_names_);
}

jobject DeviceInfoAndroid::JavaDeviceInfo::getSupportFormats(jstring id)
{
    return enumerator_->CallObjectMethod(get_formats_, id);
}

jobject DeviceInfoAndroid::JavaDeviceInfo::createCapture(jstring id)
{
    return enumerator_->CallObjectMethod(create_capture_, id, nullptr);
}
}
}
