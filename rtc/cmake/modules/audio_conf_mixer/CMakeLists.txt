INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src
					${webrtc_SOURCE_DIR}/src/modules/audio_conference_mixer/include
					${webrtc_SOURCE_DIR}/src/modules/include
)

LIST(APPEND RTC_AUDIO_CONFERENCE_MIXER_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/include/audio_conference_mixer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/include/audio_conference_mixer_defines.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/source/audio_conference_mixer_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/source/audio_conference_mixer_multistream_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/source/audio_conference_mixer_multistream_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/source/audio_conference_mixer_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/source/audio_frame_manipulator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/source/audio_frame_manipulator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/source/memory_pool.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/source/memory_pool_posix.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/source/memory_pool_win.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/source/time_scheduler.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_conference_mixer/source/time_scheduler.h
)

IF(MSVC)
	ADD_DEFINITIONS(/wd4373)
ENDIF(MSVC)

ADD_LIBRARY(rtc_audio_conf_mixer STATIC ${RTC_AUDIO_CONFERENCE_MIXER_SOURCES})
SET_TARGET_PROPERTIES(rtc_audio_conf_mixer PROPERTIES FOLDER "webrtc")
