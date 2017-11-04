INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND RTC_SYSTEM_WRAPPERS_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/aligned_array.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/aligned_malloc.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/atomic32.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/clock.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/cpu_features_wrapper.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/cpu_info.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/critical_section_wrapper.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/event_wrapper.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/field_trial.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/file_wrapper.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/fix_interlocked_exchange_pointer_win.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/logging.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/metrics.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/ntp_time.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/rtp_to_ntp_estimator.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/rw_lock_wrapper.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/sleep.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/static_instance.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/stringize_macros.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/timestamp_extrapolator.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/trace.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/utf_util_win.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/aligned_malloc.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/clock.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/cpu_features.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/cpu_info.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/event.cc			
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/file_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/logging.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/rtp_to_ntp_estimator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/rw_lock.cc			
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/sleep.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/timestamp_extrapolator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/trace_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/trace_impl.h			
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/field_trial_default.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/field_trial_default.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/metrics_default.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/metrics_default.cc
)

IF(WIN32)
	LIST(APPEND RTC_SYSTEM_WRAPPERS_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/atomic32_win.cc
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/condition_variable_event_win.cc
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/condition_variable_event_win.h
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/event_timer_win.cc
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/event_timer_win.h
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/rw_lock_win.cc
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/rw_lock_win.h
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/rw_lock_winxp_win.cc
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/rw_lock_winxp_win.h
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/trace_win.cc
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/trace_win.h
	)
	ADD_DEFINITIONS(/wd4334)
ENDIF()

IF(NOT WIN32)
LIST(APPEND RTC_SYSTEM_WRAPPERS_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/trace_posix.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/trace_posix.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/rw_lock_posix.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/rw_lock_posix.h
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/event_timer_posix.cc
			${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/event_timer_posix.h

)
ENDIF(NOT WIN32)

IF(ANDROID)
	LIST(APPEND RTC_SYSTEM_WRAPPERS_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/include/logcat_trace_context.h
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/logcat_trace_context.cc
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/cpu_features_android.c
	)
	
	
ENDIF(ANDROID)

IF(ANDROID OR CMAKE_SYSTEM_NAME MATCHES "Linux")
	LIST(APPEND RTC_SYSTEM_WRAPPERS_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/atomic32_non_darwin_unix.cc
	)
	
	ADD_DEFINITIONS(-DWEBRTC_THREAD_RR)
ENDIF()

IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
	LIST(APPEND RTC_SYSTEM_WRAPPERS_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/cpu_features_linux.c)
ENDIF()

IF(APPLE)
	LIST(APPEND RTC_SYSTEM_WRAPPERS_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/system_wrappers/source/atomic32_darwin.cc
	)
	
	ADD_DEFINITIONS(-DWEBRTC_THREAD_RR)
ENDIF(APPLE)


ADD_LIBRARY(rtc_system_wrappers STATIC ${RTC_SYSTEM_WRAPPERS_SOURCES})
SET_TARGET_PROPERTIES(rtc_system_wrappers PROPERTIES FOLDER "webrtc")