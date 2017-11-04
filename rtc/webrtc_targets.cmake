ADD_LIBRARY(libavutil STATIC IMPORTED)
ADD_LIBRARY(libavcodec STATIC IMPORTED)
ADD_LIBRARY(libx264 STATIC IMPORTED)

IF(WIN32)
	IF(CMAKE_CL_64)
		SET_PROPERTY(TARGET libavutil PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/ffmpeg/lib/x64/libavutil.a)
		SET_PROPERTY(TARGET libavcodec PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/ffmpeg/lib/x64/libavcodec.a)
		# SET_PROPERTY(TARGET libx264 PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/x264/lib/x64/libx264.lib)					
	ELSE()
		SET_PROPERTY(TARGET libavutil PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/ffmpeg/lib/win32/libavutil.a)
		SET_PROPERTY(TARGET libavcodec PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/ffmpeg/lib/win32/libavcodec.a)
		# SET_PROPERTY(TARGET libx264 PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/x264/lib/win32/libx264.lib)	
	ENDIF(CMAKE_CL_64)
ENDIF(WIN32)

IF(ANDROID)
	SET_PROPERTY(TARGET libavutil PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/ffmpeg/lib/armv7/libavutil.a)
	SET_PROPERTY(TARGET libavcodec PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/ffmpeg/lib/armv7/libavcodec.a)
	# SET_PROPERTY(TARGET libx264 PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/x264/lib/armv7/libx264.a)	
ENDIF(ANDROID)

LIST(APPEND WEBRTC_AUDIO_DEPEND opus)

LIST(APPEND WEBRTC_VIDEO_DEPEND 
			x264
			oh264_enc
			oh264_proc
			oh264_common
			vp9
			vp8
			vpx
			vpx_scale
			vpx_dsp
			vpx_mem
			vpx_util
			vpx_ports
			vpx_config
			yuv
)

IF(NOT ANDROID)
	LIST(APPEND WEBRTC_VIDEO_DEPEND
				turbojpeg-static
				#jpeg-static
	)
ENDIF(NOT ANDROID)

LIST(APPEND WEBRTC_TEST_DEPEND gflags_static)

LIST(APPEND WEBRTC_COMMON_TARGETS
			rtc_call_interface
			rtc_media_file
			rtc_stats
			rtc_chn_transport
			rtc_pacing
			rtc_rtp_rtcp
			rtc_remote_bitrate_estimator
			rtc_modules_utility
			rtc_common_video
			rtc_common_audio
			rtc_logging
			rtc_comm
			rtc_system_wrappers
			rtc_base
)

LIST(APPEND WEBRTC_AUDIO_TARGETS
			rtc_audio
			rtc_voice_server_engine
			rtc_voice_engine
			rtc_acm2
			rtc_audio_codecs
			rtc_neteq
			rtc_audio_conf_mixer
			rtc_audio_mixer
			rtc_audio_network_adapt
			rtc_audio_processing
			rtc_audio_utility
)


LIST(APPEND WEBRTC_VIDEO_TARGETS
			rtc_congestion_controller
			rtc_bitrate_controller
			
)

IF(NOT (CMAKE_SYSTEM_NAME MATCHES "Linux"))
	LIST(APPEND WEBRTC_AUDIO_TARGETS rtc_audio_device)
	LIST(APPEND WEBRTC_VIDEO_TARGETS 
				rtc_video
				rtc_desktop_capture 
				rtc_video_capture 
				rtc_video_render
				rtc_video_coding
				rtc_video_processing
	)
ENDIF()

LIST(APPEND WEBRTC_MEDIA_TARGETS
			rtc_call
			rtc_media
)

LIST(APPEND WEBRTC_SDK_TARGETS
			rtc_api
			rtc_p2p
			rtc_peerconnection
)

IF(ANDROID)
	LIST(APPEND WEBRTC_SDK_TARGETS rtc_sdk)
ENDIF(ANDROID)