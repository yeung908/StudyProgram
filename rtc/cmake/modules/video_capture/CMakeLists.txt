INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src
					${webrtc_SOURCE_DIR}/thirdparty/winsdk_samples/Samples/multimedia/directshow/baseclasses)

SET(SOURCES_DIR ${webrtc_SOURCE_DIR}/src/webrtc/modules/video_capture)

LIST(APPEND VIDEO_CAPTURE_MODULE_SOURCES
			${SOURCES_DIR}/device_info_impl.cc
			${SOURCES_DIR}/device_info_impl.h
			${SOURCES_DIR}/video_capture.h
			${SOURCES_DIR}/video_capture_config.h
			${SOURCES_DIR}/video_capture_defines.h
			${SOURCES_DIR}/video_capture_delay.h
			${SOURCES_DIR}/video_capture_factory.cc
			${SOURCES_DIR}/video_capture_factory.h
			${SOURCES_DIR}/video_capture_impl.cc
			${SOURCES_DIR}/video_capture_impl.h
)

# LIST(APPEND VIDEO_CAPTURE_SOURCES
			# ${SOURCES_DIR}/external/device_info_external.cc
			# ${SOURCES_DIR}/external/video_capture_external.cc
# )

IF(CMAKE_SYSTEM_NAME MATCHES Linux)
LIST(APPEND VIDEO_CAPTURE_IMPL_SOURCES
			${SOURCES_DIR}/linux/device_info_linux.cc
			${SOURCES_DIR}/linux/device_info_linux.h
			${SOURCES_DIR}/linux/video_capture_linux.cc
			${SOURCES_DIR}/linux/video_capture_linux.h)
ENDIF()

IF(WIN32)
LIST(APPEND VIDEO_CAPTURE_IMPL_SOURCES
			${SOURCES_DIR}/windows/device_info_ds.cc
			${SOURCES_DIR}/windows/device_info_ds.h
			${SOURCES_DIR}/windows/device_info_mf.cc
			${SOURCES_DIR}/windows/device_info_mf.h
			${SOURCES_DIR}/windows/help_functions_ds.cc
			${SOURCES_DIR}/windows/help_functions_ds.h
			${SOURCES_DIR}/windows/sink_filter_ds.cc
			${SOURCES_DIR}/windows/sink_filter_ds.h
			${SOURCES_DIR}/windows/video_capture_ds.cc
			${SOURCES_DIR}/windows/video_capture_ds.h
			${SOURCES_DIR}/windows/video_capture_factory_windows.cc
			${SOURCES_DIR}/windows/video_capture_mf.cc
			${SOURCES_DIR}/windows/video_capture_mf.h
)
ENDIF(WIN32)

IF(APPLE)
LIST(APPEND VIDEO_CAPTURE_IMPL_SOURCES
			${SOURCES_DIR}/objc/device_info.h
			${SOURCES_DIR}/objc/device_info.mm
			${SOURCES_DIR}/objc/device_info_objc.h
			${SOURCES_DIR}/objc/device_info_objc.mm
			${SOURCES_DIR}/objc/rtc_video_capture_objc.h
			${SOURCES_DIR}/objc/rtc_video_capture_objc.mm
			${SOURCES_DIR}/objc/video_capture.h
			${SOURCES_DIR}/objc/video_capture.mm
)
ENDIF(APPLE)

IF(ANDROID)
LIST(APPEND VIDEO_CAPTURE_IMPL_SOURCES
			${SOURCES_DIR}/android/device_info_android.cc
			${SOURCES_DIR}/android/device_info_android.h
			${SOURCES_DIR}/android/video_capture_android.cc
			${SOURCES_DIR}/android/video_capture_android.h
			${SOURCES_DIR}/android/video_capture_factory_android.cc
			${SOURCES_DIR}/android/video_capture_android_jni.cc
)
ENDIF(ANDROID)

ADD_LIBRARY(rtc_video_capture STATIC ${VIDEO_CAPTURE_MODULE_SOURCES} ${VIDEO_CAPTURE_SOURCES} ${VIDEO_CAPTURE_IMPL_SOURCES})
SET_TARGET_PROPERTIES(rtc_video_capture PROPERTIES FOLDER "webrtc")