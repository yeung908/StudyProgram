INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src
					${webrtc_SOURCE_DIR}/thirdparty/libyuv/include)

LIST(APPEND VIDEO_PROCESSING
	${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/util/denoiser_filter.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/util/denoiser_filter.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/util/denoiser_filter_c.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/util/denoiser_filter_c.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/util/noise_estimation.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/util/noise_estimation.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/util/skin_detection.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/util/skin_detection.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/video_denoiser.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/video_denoiser.h
)

IF(${CMAKE_SYSTEM_PROCESSOR} EQUAL x86 OR ${CMAKE_SYSTEM_PROCESSOR} EQUAL AMD64 OR ${CMAKE_SYSTEM_PROCESSOR} EQUAL x86_64 OR ${CMAKE_SYSTEM_PROCESSOR} EQUAL ia32)
	LIST(APPEND VIDEO_PROCESSING
				${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/util/denoiser_filter_sse2.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/util/denoiser_filter_sse2.h
	)
ENDIF()

IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "armv7a" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
	LIST(APPEND VIDEO_PROCESSING
				${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/util/denoiser_filter_neon.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/video_processing/util/denoiser_filter_neon.h
		)
ENDIF()

ADD_LIBRARY(rtc_video_processing STATIC ${VIDEO_PROCESSING})
SET_TARGET_PROPERTIES(rtc_video_processing PROPERTIES FOLDER "webrtc")