INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND RTC_AUDIO_UTILITY_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/audio/utility/audio_frame_operations.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/audio/utility/audio_frame_operations.h
)

ADD_LIBRARY(rtc_audio_utility STATIC ${RTC_AUDIO_UTILITY_SOURCES})
SET_TARGET_PROPERTIES(rtc_audio_utility PROPERTIES FOLDER "webrtc")