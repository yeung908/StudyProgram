INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND RTC_COMM_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/common_types.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_types.h
			${webrtc_SOURCE_DIR}/src/webrtc/config.cc
			${webrtc_SOURCE_DIR}/src/webrtc/config.h
			${webrtc_SOURCE_DIR}/src/webrtc/typedefs.h
)


ADD_LIBRARY(rtc_comm STATIC ${RTC_COMM_SOURCES})
SET_TARGET_PROPERTIES(rtc_comm PROPERTIES FOLDER "webrtc")