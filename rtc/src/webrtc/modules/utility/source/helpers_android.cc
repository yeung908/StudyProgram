/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */


#include "webrtc/base/checks.h"
#include "webrtc/modules/utility/include/helpers_android.h"

#include <android/log.h>
#include <assert.h>
#include <pthread.h>
#include <stddef.h>
#include <unistd.h>
#include <vector>

#define TAG "HelpersAndroid"
#define ALOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)

namespace webrtc {

JNIEnv* GetEnv(JavaVM* jvm) {
  void* env = NULL;
  jint status = jvm->GetEnv(&env, JNI_VERSION_1_6);
  RTC_CHECK(((env != NULL) && (status == JNI_OK)) ||
            ((env == NULL) && (status == JNI_EDETACHED)))
      << "Unexpected GetEnv return: " << status << ":" << env;
  return reinterpret_cast<JNIEnv*>(env);
}

// Return a |jlong| that will correctly convert back to |ptr|.  This is needed
// because the alternative (of silently passing a 32-bit pointer to a vararg
// function expecting a 64-bit param) picks up garbage in the high 32 bits.
jlong PointerTojlong(void* ptr) {
  static_assert(sizeof(intptr_t) <= sizeof(jlong),
                "Time to rethink the use of jlongs");
  // Going through intptr_t to be obvious about the definedness of the
  // conversion from pointer to integral type.  intptr_t to jlong is a standard
  // widening by the static_assert above.
  jlong ret = reinterpret_cast<intptr_t>(ptr);
  RTC_DCHECK(reinterpret_cast<void*>(ret) == ptr);
  return ret;
}

jmethodID GetMethodID (
    JNIEnv* jni, jclass c, const char* name, const char* signature) {
  jmethodID m = jni->GetMethodID(c, name, signature);
  CHECK_EXCEPTION(jni) << "Error during GetMethodID: " << name << ", "
                       << signature;
  RTC_CHECK(m) << name << ", " << signature;
  return m;
}

jmethodID GetStaticMethodID (
    JNIEnv* jni, jclass c, const char* name, const char* signature) {
  jmethodID m = jni->GetStaticMethodID(c, name, signature);
  CHECK_EXCEPTION(jni) << "Error during GetStaticMethodID: " << name << ", "
                       << signature;
  RTC_CHECK(m) << name << ", " << signature;
  return m;
}

jclass FindClass(JNIEnv* jni, const char* name) {
  jclass c = jni->FindClass(name);
  CHECK_EXCEPTION(jni) << "Error during FindClass: " << name;
  RTC_CHECK(c) << name;
  return c;
}

jobject NewGlobalRef(JNIEnv* jni, jobject o) {
  jobject ret = jni->NewGlobalRef(o);
  CHECK_EXCEPTION(jni) << "Error during NewGlobalRef";
  RTC_CHECK(ret);
  return ret;
}

void DeleteGlobalRef(JNIEnv* jni, jobject o) {
  jni->DeleteGlobalRef(o);
  CHECK_EXCEPTION(jni) << "Error during DeleteGlobalRef";
}

std::string GetThreadId() {
  char buf[21];  // Big enough to hold a kuint64max plus terminating NULL.
  int thread_id = gettid();
  RTC_CHECK_LT(snprintf(buf, sizeof(buf), "%i", thread_id),
               static_cast<int>(sizeof(buf)))
      << "Thread id is bigger than uint64??";
  return std::string(buf);
}

std::string GetThreadInfo() {
  return "@[tid=" + GetThreadId() + "]";
}

jclass GetObjectClass(JNIEnv* jni, jobject object) {
  jclass c = jni->GetObjectClass(object);
  CHECK_EXCEPTION(jni) << "error during GetObjectClass";
  RTC_CHECK(c) << "GetObjectClass returned NULL";
  return c;
}

AttachThreadScoped::AttachThreadScoped(JavaVM* jvm)
    : attached_(false), jvm_(jvm), env_(NULL) {
  env_ = GetEnv(jvm);
  if (!env_) {
    // Adding debug log here so we can track down potential leaks and figure
    // out why we sometimes see "Native thread exiting without having called
    // DetachCurrentThread" in logcat outputs.
    ALOGD("Attaching thread to JVM%s", GetThreadInfo().c_str());
    jint res = jvm->AttachCurrentThread(&env_, NULL);
    attached_ = (res == JNI_OK);
    RTC_CHECK(attached_) << "AttachCurrentThread failed: " << res;
  }
}

AttachThreadScoped::~AttachThreadScoped() {
  if (attached_) {
    ALOGD("Detaching thread from JVM%s", GetThreadInfo().c_str());
    jint res = jvm_->DetachCurrentThread();
    RTC_CHECK(res == JNI_OK) << "DetachCurrentThread failed: " << res;
    RTC_CHECK(!GetEnv(jvm_));
  }
}

JNIEnv* AttachThreadScoped::env() { return env_; }

jfieldID GetFieldID(
        JNIEnv* jni, jclass c, const char* name, const char* signature) {
  jfieldID f = jni->GetFieldID(c, name, signature);
  CHECK_EXCEPTION(jni) << "error during GetFieldID";
  RTC_CHECK(f) << name << ", " << signature;
  return f;
}

jfieldID GetStaticFieldID(JNIEnv* jni,
                          jclass c,
                          const char* name,
                          const char* signature) {
  jfieldID f = jni->GetStaticFieldID(c, name, signature);
  CHECK_EXCEPTION(jni) << "error during GetStaticFieldID";
  RTC_CHECK(f) << name << ", " << signature;
  return f;
}

jobject GetObjectField(JNIEnv* jni, jobject object, jfieldID id) {
  jobject o = jni->GetObjectField(object, id);
  CHECK_EXCEPTION(jni) << "error during GetObjectField";
  RTC_CHECK(!IsNull(jni, o)) << "GetObjectField returned NULL";
  return o;
}

jobject GetStaticObjectField(JNIEnv* jni, jclass c, jfieldID id) {
  jobject o = jni->GetStaticObjectField(c, id);
  CHECK_EXCEPTION(jni) << "error during GetStaticObjectField";
  RTC_CHECK(!IsNull(jni, o)) << "GetStaticObjectField returned NULL";
  return o;
}

jobject GetNullableObjectField(JNIEnv* jni, jobject object, jfieldID id) {
  jobject o = jni->GetObjectField(object, id);
  CHECK_EXCEPTION(jni) << "error during GetObjectField";
  return o;
}

jstring GetStringField(JNIEnv* jni, jobject object, jfieldID id) {
  return static_cast<jstring>(GetObjectField(jni, object, id));
}

jlong GetLongField(JNIEnv* jni, jobject object, jfieldID id) {
  jlong l = jni->GetLongField(object, id);
  CHECK_EXCEPTION(jni) << "error during GetLongField";
  return l;
}

jint GetIntField(JNIEnv* jni, jobject object, jfieldID id) {
  jint i = jni->GetIntField(object, id);
  CHECK_EXCEPTION(jni) << "error during GetIntField";
  return i;
}

bool GetBooleanField(JNIEnv* jni, jobject object, jfieldID id) {
  jboolean b = jni->GetBooleanField(object, id);
  CHECK_EXCEPTION(jni) << "error during GetBooleanField";
  return b;
}

bool IsNull(JNIEnv* jni, jobject obj) {
  return jni->IsSameObject(obj, nullptr);
}

// Given a UTF-8 encoded |native| string return a new (UTF-16) jstring.
jstring JavaStringFromStdString(JNIEnv* jni, const std::string& native) {
  jstring jstr = jni->NewStringUTF(native.c_str());
  CHECK_EXCEPTION(jni) << "error during NewStringUTF";
  return jstr;
}

// Given a jstring, reinterprets it to a new native string.
std::string JavaToStdString(JNIEnv* jni, const jstring& j_string) {
  // Invoke String.getBytes(String charsetName) method to convert |j_string|
  // to a byte array.
  const jclass string_class = GetObjectClass(jni, j_string);
  const jmethodID get_bytes =
          GetMethodID(jni, string_class, "getBytes", "(Ljava/lang/String;)[B");
  const jstring charset_name = jni->NewStringUTF("ISO-8859-1");
  CHECK_EXCEPTION(jni) << "error during NewStringUTF";
  const jbyteArray j_byte_array =
          (jbyteArray)jni->CallObjectMethod(j_string, get_bytes, charset_name);
  CHECK_EXCEPTION(jni) << "error during CallObjectMethod";

  const size_t len = jni->GetArrayLength(j_byte_array);
  CHECK_EXCEPTION(jni) << "error during GetArrayLength";
  std::vector<char> buf(len);
  jni->GetByteArrayRegion(j_byte_array, 0, len,
                          reinterpret_cast<jbyte*>(&buf[0]));
  CHECK_EXCEPTION(jni) << "error during GetByteArrayRegion";

  if (string_class) jni->DeleteLocalRef(string_class);
  if (charset_name) jni->DeleteLocalRef(charset_name);
  if (j_byte_array) jni->DeleteLocalRef(j_byte_array);

  return std::string(buf.begin(), buf.end());
}

// Return the (singleton) Java Enum object corresponding to |index|;
jobject JavaEnumFromIndex(JNIEnv* jni, jclass state_class,
                          const std::string& state_class_name, int index) {
  jmethodID state_values_id = GetStaticMethodID(
          jni, state_class, "values", ("()[L" + state_class_name  + ";").c_str());
  jobjectArray state_values = static_cast<jobjectArray>(
          jni->CallStaticObjectMethod(state_class, state_values_id));
  CHECK_EXCEPTION(jni) << "error during CallStaticObjectMethod";
  jobject ret = jni->GetObjectArrayElement(state_values, index);
  CHECK_EXCEPTION(jni) << "error during GetObjectArrayElement";
  return ret;
}

std::string GetJavaEnumName(JNIEnv* jni,
                            const std::string& className,
                            jobject j_enum) {
  jclass enumClass = FindClass(jni, className.c_str());
  jmethodID nameMethod =
          GetMethodID(jni, enumClass, "name", "()Ljava/lang/String;");
  jstring name =
          reinterpret_cast<jstring>(jni->CallObjectMethod(j_enum, nameMethod));
  CHECK_EXCEPTION(jni) << "error during CallObjectMethod for " << className
                       << ".name";
  return JavaToStdString(jni, name);
}


}  // namespace webrtc
