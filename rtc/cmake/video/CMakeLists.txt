INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND RTC_VIDEO_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/video/call_stats.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/call_stats.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/encoder_rtcp_feedback.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/encoder_rtcp_feedback.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/overuse_frame_detector.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/overuse_frame_detector.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/payload_router.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/payload_router.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/quality_threshold.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/quality_threshold.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/receive_statistics_proxy.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/receive_statistics_proxy.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/report_block_stats.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/report_block_stats.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/rtp_stream_receiver.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/rtp_stream_receiver.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/rtp_streams_synchronizer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/rtp_streams_synchronizer.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/send_delay_stats.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/send_delay_stats.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/send_statistics_proxy.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/send_statistics_proxy.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/stats_counter.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/stats_counter.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/stream_synchronization.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/stream_synchronization.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/transport_adapter.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/transport_adapter.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/video_receive_stream.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/video_receive_stream.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/video_send_stream.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/video_send_stream.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/video_stream_decoder.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/video_stream_decoder.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/vie_encoder.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/vie_encoder.h
			${webrtc_SOURCE_DIR}/src/webrtc/video/vie_remb.cc
			${webrtc_SOURCE_DIR}/src/webrtc/video/vie_remb.h
)
	
ADD_LIBRARY(rtc_video STATIC ${RTC_VIDEO_SOURCES})
SET_TARGET_PROPERTIES(rtc_video PROPERTIES FOLDER "webrtc")