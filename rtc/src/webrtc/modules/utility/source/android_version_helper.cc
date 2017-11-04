#include "webrtc/modules/utility/include/jvm_android.h"
#include "webrtc/modules/utility/include/android_version_helper.h"

namespace webrtc
{
    int AndroidSDKVersion() {
        int sdk_version = 0;
        
        AttachCurrentThreadIfNeeded();
        JavaVM *vm = JVM::GetInstance()->jvm();
        JNIEnv *jni = GetEnv(vm);
        if (jni) {
            jclass version_class = jni->FindClass("android/os/Build$VERSION");
            jfieldID fid = (jni)->GetStaticFieldID(version_class, "SDK_INT", "I");
            sdk_version = (jni)->GetStaticIntField(version_class, fid);
            (jni)->DeleteLocalRef(version_class);
        }
        return sdk_version;
    }

    std::string GetAndroidBoardName()
    {
        std::string boardType;
        AttachCurrentThreadIfNeeded attach_if_needed;
        JavaVM *vm = JVM::GetInstance()->jvm();
        JNIEnv *jni = GetEnv(vm);
        jclass systemPropertyClass = jni->FindClass("android/os/SystemProperties");
        if (systemPropertyClass==NULL){
            jni->ExceptionClear(); //very important.
        }
        jmethodID getMethodID = jni->GetStaticMethodID(systemPropertyClass,"get","(Ljava/lang/String;)Ljava/lang/String;");
        if (getMethodID != NULL){
            jstring propertyStr = (jni)->NewStringUTF("ro.cvte.ic");
            jstring ret = (jstring)jni->CallStaticObjectMethod(systemPropertyClass, getMethodID, propertyStr);
            boardType = (jni)->GetStringUTFChars(ret, NULL);
            jni->DeleteLocalRef(propertyStr);
            jni->DeleteLocalRef(ret);

            if (jni->ExceptionCheck()) {
                jni->ExceptionDescribe();
                jni->ExceptionClear();
            }
        } else {
            jni->ExceptionClear(); //very important.
        }
        jni->DeleteLocalRef(systemPropertyClass);
        return boardType;
    }
}