INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND UTILITY_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/include/audio_frame_operations.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/include/process_thread.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/source/process_thread_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/source/process_thread_impl.h
)

IF(ANDROID)
LIST(APPEND UTILITY_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/include/helpers_android.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/source/helpers_android.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/include/jvm_android.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/source/jvm_android.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/include/native_handle_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/source/native_handle_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/include/surfacetexturehelper_jni.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/source/surfacetexturehelper_jni.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/source/android_version_helper.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/utility/include/android_version_helper.h
)

ENDIF(ANDROID)

ADD_LIBRARY(rtc_modules_utility STATIC ${UTILITY_SOURCES})
SET_TARGET_PROPERTIES(rtc_modules_utility PROPERTIES FOLDER "webrtc")