INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND RTC_CALL_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/call/bitrate_allocator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/call/bitrate_allocator.h
			${webrtc_SOURCE_DIR}/src/webrtc/call/call.cc
			${webrtc_SOURCE_DIR}/src/webrtc/call/flexfec_receive_stream_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/call/flexfec_receive_stream_impl.h
)

LIST(APPEND RTC_CALL_INTERFACE_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/call/audio_receive_stream.h
			${webrtc_SOURCE_DIR}/src/webrtc/call/audio_send_stream.cc
			${webrtc_SOURCE_DIR}/src/webrtc/call/audio_send_stream.h
			${webrtc_SOURCE_DIR}/src/webrtc/call/audio_state.h
			${webrtc_SOURCE_DIR}/src/webrtc/call/call.h
			${webrtc_SOURCE_DIR}/src/webrtc/call/flexfec_receive_stream.h
			${webrtc_SOURCE_DIR}/src/webrtc/call/syncable.cc
			${webrtc_SOURCE_DIR}/src/webrtc/call/syncable.h
)

ADD_LIBRARY(rtc_call_interface ${RTC_CALL_INTERFACE_SOURCES})
ADD_LIBRARY(rtc_call STATIC ${RTC_CALL_SOURCES})
SET_TARGET_PROPERTIES(rtc_call PROPERTIES FOLDER webrtc)
SET_TARGET_PROPERTIES(rtc_call_interface PROPERTIES FOLDER webrtc)