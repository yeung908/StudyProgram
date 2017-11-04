INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND RTC_AUDIO_MIXER_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_mixer/audio_mixer_impl.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_mixer/audio_mixer_impl.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_mixer/default_output_rate_calculator.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_mixer/default_output_rate_calculator.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_mixer/output_rate_calculator.h
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_mixer/audio_frame_manipulator.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_mixer/audio_frame_manipulator.h
)

ADD_LIBRARY(rtc_audio_mixer STATIC ${RTC_AUDIO_MIXER_SOURCES})
SET_TARGET_PROPERTIES(rtc_audio_mixer PROPERTIES FOLDER "webrtc")