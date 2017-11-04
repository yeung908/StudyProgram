INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/include)


ADD_DEFINITIONS(-DWEBRTC_CODEC_ILBC
				-DWEBRTC_CODEC_OPUS
				-DWEBRTC_OPUS_SUPPORT_120MS_PTIME=0
				-DWEBRTC_CODEC_ISAC
				-DWEBRTC_CODEC_G722)
				
IF(WIN32)
	ADD_DEFINITIONS(/wd4373)
ENDIF(WIN32)
				
LIST(APPEND RTC_ACM2_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/acm_codec_database.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/acm_codec_database.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/rent_a_codec.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/rent_a_codec.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/acm_common_defs.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/acm_receiver.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/acm_receiver.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/acm_resampler.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/acm_resampler.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/audio_coding_module.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/call_statistics.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/call_statistics.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/codec_manager.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/acm2/codec_manager.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/include/audio_coding_module.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/include/audio_coding_module_typedefs.h
)

ADD_LIBRARY(rtc_acm2 STATIC ${RTC_ACM2_SOURCES})
SET_TARGET_PROPERTIES(rtc_acm2 PROPERTIES FOLDER "webrtc")