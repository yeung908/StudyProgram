INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

ADD_SUBDIRECTORY(utility)

LIST(APPEND RTC_AUDIO_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/audio/audio_receive_stream.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/audio/audio_receive_stream.h
    ${webrtc_SOURCE_DIR}/src/webrtc/audio/audio_send_stream.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/audio/audio_send_stream.h
    ${webrtc_SOURCE_DIR}/src/webrtc/audio/audio_state.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/audio/audio_state.h
    ${webrtc_SOURCE_DIR}/src/webrtc/audio/audio_transport_proxy.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/audio/audio_transport_proxy.h
    ${webrtc_SOURCE_DIR}/src/webrtc/audio/conversion.h
    ${webrtc_SOURCE_DIR}/src/webrtc/audio/scoped_voe_interface.h
)

ADD_LIBRARY(rtc_audio STATIC ${RTC_AUDIO_SOURCES})
SET_TARGET_PROPERTIES(rtc_audio PROPERTIES FOLDER "webrtc")