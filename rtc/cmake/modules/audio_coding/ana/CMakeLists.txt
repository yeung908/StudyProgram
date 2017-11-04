INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND RTC_AUDIO_NETWROK_ADAPT
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/audio_network_adaptor.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/audio_network_adaptor_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/audio_network_adaptor_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/bitrate_controller.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/bitrate_controller.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/channel_controller.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/channel_controller.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/controller.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/controller.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/controller_manager.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/controller_manager.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/debug_dump_writer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/debug_dump_writer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/dtx_controller.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/dtx_controller.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/event_log_writer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/event_log_writer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/fec_controller.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/fec_controller.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/frame_length_controller.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/frame_length_controller.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/audio_network_adaptor/include/audio_network_adaptor.h
)

ADD_LIBRARY(rtc_audio_network_adapt STATIC ${RTC_AUDIO_NETWROK_ADAPT})
SET_TARGET_PROPERTIES(rtc_audio_network_adapt PROPERTIES FOLDER "webrtc")