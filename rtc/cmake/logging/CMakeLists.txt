INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND RTC_LOGGING_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/logging/rtc_event_log/rtc_event_log.h
			${webrtc_SOURCE_DIR}/src/webrtc/logging/rtc_event_log/ringbuffer.h
			${webrtc_SOURCE_DIR}/src/webrtc/logging/rtc_event_log/rtc_event_log.cc
			${webrtc_SOURCE_DIR}/src/webrtc/logging/rtc_event_log/rtc_event_log_helper_thread.cc
			${webrtc_SOURCE_DIR}/src/webrtc/logging/rtc_event_log/rtc_event_log_helper_thread.h
)

if(ENABLE_RTC_EVENT_LOG)
	ADD_DEFINITIONS(-DENABLE_RTC_EVENT_LOG)
	INCLUDE_DIRECTORIES(${PROTOBUF_DIR})
	list(APPEND RTC_LOGGING_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/logging/rtc_event_log/rtc_event_log.pb.cc
				${webrtc_SOURCE_DIR}/src/webrtc/logging/rtc_event_log/rtc_event_log.pb.h
	)
endif()

ADD_LIBRARY(rtc_logging STATIC ${RTC_LOGGING_SOURCES})
SET_TARGET_PROPERTIES(rtc_logging PROPERTIES FOLDER "webrtc")

IF(ENABLE_RTC_EVENT_LOG)
	INCLUDE(${PROTOBUF_SCRIPT})
	protoc_gen_cpp(
		${webrtc_SOURCE_DIR}/src/webrtc/logging/rtc_event_log
		${webrtc_SOURCE_DIR}/src/webrtc/logging/rtc_event_log/rtc_event_log.proto
	)
ENDIF()