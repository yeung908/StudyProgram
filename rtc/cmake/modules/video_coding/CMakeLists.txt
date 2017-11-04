INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}
					${webrtc_SOURCE_DIR}/src
					${webrtc_SOURCE_DIR}/thirdparty/libyuv/include
					${webrtc_SOURCE_DIR}/thirdparty/ffmpeg/include
					${webrtc_SOURCE_DIR}/thirdparty/x264/include
					${webrtc_SOURCE_DIR}/thirdparty/libvpx/include
					${webrtc_SOURCE_DIR}/thirdparty/libvpx/source/config
					${webrtc_SOURCE_DIR}/thirdparty/libvpx/source/libvpx)


ADD_DEFINITIONS(-DWEBRTC_USE_H264 -DWEBRTC_INITIALIZE_FFMPEG)

LIST(APPEND VIDEO_CODING_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codec_database.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codec_database.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codec_timer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codec_timer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/decoding_state.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/decoding_state.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/encoded_frame.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/encoded_frame.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/fec_rate_table.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/frame_buffer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/frame_buffer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/frame_buffer2.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/frame_buffer2.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/frame_object.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/frame_object.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/generic_decoder.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/generic_decoder.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/generic_encoder.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/generic_encoder.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/h264_sprop_parameter_sets.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/h264_sprop_parameter_sets.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/h264_sps_pps_tracker.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/h264_sps_pps_tracker.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/histogram.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/histogram.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/include/video_codec_initializer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/include/video_coding.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/include/video_coding_defines.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/inter_frame_delay.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/inter_frame_delay.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/internal_defines.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/jitter_buffer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/jitter_buffer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/jitter_buffer_common.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/jitter_estimator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/jitter_estimator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/media_opt_util.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/media_opt_util.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/media_optimization.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/media_optimization.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/nack_fec_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/nack_module.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/nack_module.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/packet.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/packet.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/packet_buffer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/packet_buffer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/protection_bitrate_calculator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/protection_bitrate_calculator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/receiver.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/receiver.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/rtp_frame_reference_finder.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/rtp_frame_reference_finder.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/rtt_filter.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/rtt_filter.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/session_info.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/session_info.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/timestamp_map.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/timestamp_map.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/timing.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/timing.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/video_codec_initializer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/video_coding_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/video_coding_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/video_receiver.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/video_sender.cc
)

LIST(APPEND VIDEO_CODING_UTILITY_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/default_video_bitrate_allocator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/default_video_bitrate_allocator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/frame_dropper.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/frame_dropper.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/ivf_file_writer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/ivf_file_writer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/moving_average.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/moving_average.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/qp_parser.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/qp_parser.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/quality_scaler.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/quality_scaler.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/simulcast_rate_allocator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/simulcast_rate_allocator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/vp8_header_parser.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/utility/vp8_header_parser.h
)

LIST(APPEND VIDEO_CODING_H264_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/h264.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/include/h264.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/h264_decoder_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/h264_encoder_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/h264_encoder_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/h264_x264_encoder_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/h264_x264_encoder_impl.h	
)

LIST(APPEND VIDEO_CODING_I420_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/i420/i420.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/i420/include/i420.h
)

LIST(APPEND VIDEO_CODING_VP8_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/default_temporal_layers.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/default_temporal_layers.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/include/vp8.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/include/vp8_common_types.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/realtime_temporal_layers.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/reference_picture_selection.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/reference_picture_selection.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/screenshare_layers.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/screenshare_layers.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/simulcast_encoder_adapter.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/simulcast_encoder_adapter.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/temporal_layers.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/vp8_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp8/vp8_impl.h
)

LIST(APPEND VIDEO_CODING_VP9_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp9/include/vp9.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp9/screenshare_layers.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp9/screenshare_layers.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp9/vp9_frame_buffer_pool.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp9/vp9_frame_buffer_pool.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp9/vp9_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/vp9/vp9_impl.h
)

IF(WIN32)
	LIST(APPEND VIDEO_CODING_H264_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/win/h264_dxva_decoder_impl.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/win/h264_dxva_decoder_impl.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/win/h264_media_foundation_encoder_impl.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/win/h264_media_foundation_encoder_impl.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/win/mfhelper.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/win/mfhelper.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/video_coding/codecs/h264/win/com_ptr.h
	)
ENDIF(WIN32)

SOURCE_GROUP(h264 FILES ${VIDEO_CODING_H264_SOURCES})
SOURCE_GROUP(vp8 FILES ${VIDEO_CODING_VP8_SOURCES})
SOURCE_GROUP(vp9 FILES ${VIDEO_CODING_VP9_SOURCES})
SOURCE_GROUP(i420 FILES ${VIDEO_CODING_I420_SOURCES})

ADD_LIBRARY(rtc_video_coding STATIC 
			${VIDEO_CODING_SOURCES} 
			${VIDEO_CODING_H264_SOURCES} 
			${VIDEO_CODING_I420_SOURCES} 
			${VIDEO_CODING_UTILITY_SOURCES} 
			${VIDEO_CODING_VP8_SOURCES} 
			${VIDEO_CODING_VP9_SOURCES}
)
SET_TARGET_PROPERTIES(rtc_video_coding PROPERTIES FOLDER "webrtc")