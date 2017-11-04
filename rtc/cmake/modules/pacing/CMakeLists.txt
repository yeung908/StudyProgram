INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND PACING_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/pacing/alr_detector.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/pacing/alr_detector.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/pacing/bitrate_prober.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/pacing/bitrate_prober.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/pacing/paced_sender.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/pacing/paced_sender.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/pacing/packet_router.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/pacing/packet_router.h
)

ADD_LIBRARY(rtc_pacing STATIC ${PACING_SOURCES})
SET_TARGET_PROPERTIES(rtc_pacing PROPERTIES FOLDER "webrtc")