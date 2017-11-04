INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND VIDEO_RENDER_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_render/video_renderer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_render/video_renderer.h
)

IF(WIN32)
LIST(APPEND VIDEO_RENDER_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_render/windows/d3d_renderer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_render/windows/d3d_renderer.h
)
ENDIF(WIN32)

IF(ANDROID)
LIST(APPEND VIDEO_RENDER_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_render/android/android_renderer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_render/android/android_renderer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/video_render/android/videorenderer_jni.cc		
)
ENDIF(ANDROID)

ADD_LIBRARY(rtc_video_render STATIC ${VIDEO_RENDER_SOURCES})
SET_TARGET_PROPERTIES(rtc_video_render PROPERTIES FOLDER "webrtc")