INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

ADD_DEFINITIONS(-DBWE_TEST_LOGGING_COMPILE_TIME_ENABLE=0)

LIST(APPEND REMOTE_BITRATE_ESTIMATOR_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/aimd_rate_control.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/aimd_rate_control.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/bwe_defines.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/include/bwe_defines.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/include/remote_bitrate_estimator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/include/send_time_history.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/inter_arrival.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/inter_arrival.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/overuse_detector.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/overuse_detector.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/overuse_estimator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/overuse_estimator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/remote_bitrate_estimator_abs_send_time.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/remote_bitrate_estimator_abs_send_time.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/remote_bitrate_estimator_single_stream.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/remote_bitrate_estimator_single_stream.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/remote_estimator_proxy.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/remote_estimator_proxy.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/send_time_history.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/test/bwe_test_logging.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/remote_bitrate_estimator/test/bwe_test_logging.cc
)


ADD_LIBRARY(rtc_remote_bitrate_estimator STATIC ${REMOTE_BITRATE_ESTIMATOR_SOURCES})
SET_TARGET_PROPERTIES(rtc_remote_bitrate_estimator PROPERTIES FOLDER "webrtc")