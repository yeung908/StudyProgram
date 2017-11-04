/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_MODULES_UTILITY_INCLUDE_HELPERS_ANDROID_H_
#define WEBRTC_MODULES_UTILITY_INCLUDE_HELPERS_ANDROID_H_

#include <jni.h>
#include <string>

// Abort the process if |jni| has a Java exception pending.
// TODO(henrika): merge with CHECK_JNI_EXCEPTION() in jni_helpers.h.
#define CHECK_EXCEPTION(jni)        \
  RTC_CHECK(!jni->ExceptionCheck()) \
      << (jni->ExceptionDescribe(), jni->ExceptionClear(), "")

namespace webrtc {

// Return a |JNIEnv*| usable on this thread or NULL if this thread is detached.
JNIEnv* GetEnv(JavaVM* jvm);

// Return a |jlong| that will correctly convert back to |ptr|.  This is needed
// because the alternative (of silently passing a 32-bit pointer to a vararg
// function expecting a 64-bit param) picks up garbage in the high 32 bits.
jlong PointerTojlong(void* ptr);

// JNIEnv-helper methods that wraps the API which uses the JNI interface
// pointer (JNIEnv*). It allows us to RTC_CHECK success and that no Java
// exception is thrown while calling the method.
jmethodID GetMethodID(
    JNIEnv* jni, jclass c, const char* name, const char* signature);

jmethodID GetStaticMethodID(
    JNIEnv* jni, jclass c, const char* name, const char* signature);

jfieldID GetFieldID(
    JNIEnv* jni, jclass c, const char* name, const char* signature);

jfieldID GetStaticFieldID(JNIEnv* jni,
                          jclass c,
                          const char* name,
                          const char* signature);

jclass GetObjectClass(JNIEnv* jni, jobject object);

jclass FindClass(JNIEnv* jni, const char* name);

// Throws an exception if the object field is null.
jobject GetObjectField(JNIEnv* jni, jobject object, jfieldID id);

jobject GetStaticObjectField(JNIEnv* jni, jclass c, jfieldID id);

jobject GetNullableObjectField(JNIEnv* jni, jobject object, jfieldID id);

jstring GetStringField(JNIEnv* jni, jobject object, jfieldID id);

jlong GetLongField(JNIEnv* jni, jobject object, jfieldID id);

jint GetIntField(JNIEnv* jni, jobject object, jfieldID id);

bool GetBooleanField(JNIEnv* jni, jobject object, jfieldID id);

// Returns true if |obj| == null in Java.
bool IsNull(JNIEnv* jni, jobject obj);

// Given a UTF-8 encoded |native| string return a new (UTF-16) jstring.
jstring JavaStringFromStdString(JNIEnv* jni, const std::string& native);

// Given a (UTF-16) jstring return a new UTF-8 native string.
std::string JavaToStdString(JNIEnv *jni, const jstring &j_string);

// Return the (singleton) Java Enum object corresponding to |index|;
jobject JavaEnumFromIndex(JNIEnv* jni, jclass state_class,
                          const std::string& state_class_name, int index);

// Returns the name of a Java enum.
std::string GetJavaEnumName(JNIEnv* jni,
                            const std::string& className,
                            jobject j_enum);


jobject NewGlobalRef(JNIEnv* jni, jobject o);

void DeleteGlobalRef(JNIEnv* jni, jobject o);

// Return thread ID as a string.
std::string GetThreadId();

// Return thread ID as string suitable for debug logging.
std::string GetThreadInfo();

// Attach thread to JVM if necessary and detach at scope end if originally
// attached.
class AttachThreadScoped {
 public:
  explicit AttachThreadScoped(JavaVM* jvm);
  ~AttachThreadScoped();
  JNIEnv* env();

 private:
  bool attached_;
  JavaVM* jvm_;
  JNIEnv* env_;
};

// Scoped holder for global Java refs.
template<class T>  // T is jclass, jobject, jintArray, etc.
class ScopedGlobalRef {
 public:
  ScopedGlobalRef(JNIEnv* jni, T obj)
      : jni_(jni), obj_(static_cast<T>(NewGlobalRef(jni, obj))) {}
  ~ScopedGlobalRef() {
    DeleteGlobalRef(jni_, obj_);
  }
  T operator*() const {
    return obj_;
  }
 private:
  JNIEnv* jni_;
  T obj_;
};

#define JOW(rettype, name) \
  extern "C" JNIEXPORT rettype JNICALL Java_org_webrtc_##name
}  // namespace webrtc

#endif  // WEBRTC_MODULES_UTILITY_INCLUDE_HELPERS_ANDROID_H_
