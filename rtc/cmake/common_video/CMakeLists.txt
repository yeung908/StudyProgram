INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src
					${webrtc_SOURCE_DIR}/thirdparty/libyuv/include)
					
LIST(APPEND RTC_COMMON_VIDEO_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/bitrate_adjuster.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/h264/h264_bitstream_parser.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/h264/h264_bitstream_parser.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/h264/h264_common.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/h264/h264_common.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/h264/pps_parser.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/h264/pps_parser.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/h264/profile_level_id.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/h264/profile_level_id.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/h264/sps_parser.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/h264/sps_parser.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/h264/sps_vui_rewriter.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/h264/sps_vui_rewriter.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/i420_buffer_pool.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/include/bitrate_adjuster.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/include/frame_callback.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/include/i420_buffer_pool.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/include/incoming_video_stream.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/include/video_bitrate_allocator.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/include/video_frame_buffer.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/incoming_video_stream.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/libyuv/include/webrtc_libyuv.h
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/libyuv/webrtc_libyuv.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/video_frame.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/video_frame_buffer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/video_render_frames.cc
			${webrtc_SOURCE_DIR}/src/webrtc/common_video/video_render_frames.h
)


ADD_LIBRARY(rtc_common_video STATIC ${RTC_COMMON_VIDEO_SOURCES})
SET_TARGET_PROPERTIES(rtc_common_video PROPERTIES FOLDER "webrtc")