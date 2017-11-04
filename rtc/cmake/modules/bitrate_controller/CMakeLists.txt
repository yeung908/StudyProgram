INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)


ADD_DEFINITIONS(-DBWE_TEST_LOGGING_COMPILE_TIME_ENABLE=0 )

LIST(APPEND BITRATE_CONTROLLER_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/bitrate_controller/bitrate_controller_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/bitrate_controller/bitrate_controller_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/bitrate_controller/include/bitrate_controller.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/bitrate_controller/send_side_bandwidth_estimation.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/bitrate_controller/send_side_bandwidth_estimation.h
)

ADD_LIBRARY(rtc_bitrate_controller ${BITRATE_CONTROLLER_SOURCES})
SET_TARGET_PROPERTIES(rtc_bitrate_controller PROPERTIES FOLDER "webrtc")