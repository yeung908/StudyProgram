INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND RTC_VOICE_ENGINGE_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/coder.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/coder.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/file_player.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/file_player.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/file_recorder.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/file_recorder.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/channel.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/channel.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/channel_manager.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/channel_manager.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/channel_proxy.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/channel_proxy.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/include/voe_audio_processing.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/include/voe_base.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/include/voe_codec.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/include/voe_errors.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/include/voe_external_media.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/include/voe_file.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/include/voe_hardware.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/include/voe_neteq_stats.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/include/voe_network.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/include/voe_rtp_rtcp.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/include/voe_video_sync.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/include/voe_volume_control.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/monitor_module.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/monitor_module.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/output_mixer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/output_mixer.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/shared_data.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/shared_data.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/statistics.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/statistics.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/transmit_mixer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/transmit_mixer.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/transport_feedback_packet_loss_tracker.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/transport_feedback_packet_loss_tracker.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/utility.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/utility.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_audio_processing_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_audio_processing_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_base_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_base_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_codec_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_codec_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_external_media_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_external_media_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_file_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_file_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_hardware_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_hardware_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_neteq_stats_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_neteq_stats_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_network_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_network_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_rtp_rtcp_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_rtp_rtcp_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_video_sync_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_video_sync_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_volume_control_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voe_volume_control_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voice_engine_defines.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voice_engine_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/voice_engine_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/level_indicator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/level_indicator.h
)

LIST(APPEND RTC_VOE_CHN_TRANSPORT_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/channel_transport.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/channel_transport.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/server_channel_transport.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/server_channel_transport.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_socket_manager_wrapper.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_socket_manager_wrapper.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_socket_wrapper.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_socket_wrapper.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_transport.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_transport_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_transport_impl.h
)

IF(WIN32)
ADD_DEFINITIONS(/DWEBRTC_DRIFT_COMPENSATION_SUPPORTED /wd4373 /wd4302)
LIST(APPEND RTC_VOE_CHN_TRANSPORT_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_socket2_manager_win.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_socket2_manager_win.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_socket2_win.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_socket2_win.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/traffic_control_win.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/traffic_control_win.h
)
ELSE()
LIST(APPEND RTC_VOE_CHN_TRANSPORT_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_socket_manager_posix.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_socket_manager_posix.h
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_socket_posix.cc
			${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/test/channel_transport/udp_socket_posix.h
)
ENDIF()

ADD_LIBRARY(rtc_voice_engine STATIC ${RTC_VOICE_ENGINGE_SOURCES})
ADD_LIBRARY(rtc_chn_transport STATIC ${RTC_VOE_CHN_TRANSPORT_SOURCES})
SET_TARGET_PROPERTIES(rtc_voice_engine PROPERTIES FOLDER "webrtc")
SET_TARGET_PROPERTIES(rtc_chn_transport PROPERTIES FOLDER "webrtc")