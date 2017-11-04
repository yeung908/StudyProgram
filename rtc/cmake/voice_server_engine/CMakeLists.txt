INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND RTC_VOSE_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/include/vose_base.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/include/vose_codec.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/include/vose_file.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/include/vose_neteq_stats.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/include/vose_network.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/include/vose_rtp_rtcp.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/channel.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/channel.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/channel_manager.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/channel_manager.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/voice_server_engine_impl.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/voice_server_engine_impl.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/vose_base_impl.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/vose_base_impl.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/vose_codec_impl.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/vose_codec_impl.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/vose_file_impl.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/vose_file_impl.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/vose_neteq_stats_impl.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/vose_neteq_stats_impl.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/vose_network_impl.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/vose_network_impl.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/vose_rtp_rtcp_impl.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/vose_rtp_rtcp_impl.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/shared_data.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/shared_data.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/mixer_manager.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/mixer_manager.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/server_conference_mixer.h
	${webrtc_SOURCE_DIR}/src/webrtc/voice_server_engine/server_conference_mixer.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/statistics.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/utility.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/level_indicator.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/file_player.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/file_recorder.cc
	${webrtc_SOURCE_DIR}/src/webrtc/voice_engine/coder.cc)
	
ADD_LIBRARY(rtc_voice_server_engine STATIC ${RTC_VOSE_SOURCES})
SET_TARGET_PROPERTIES(rtc_voice_server_engine PROPERTIES FOLDER "webrtc")