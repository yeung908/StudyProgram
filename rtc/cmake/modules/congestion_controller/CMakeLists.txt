INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

ADD_DEFINITIONS(-DBWE_TEST_LOGGING_COMPILE_TIME_ENABLE=0)

LIST(APPEND CONGESTION_CONTROLLER_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/congestion_controller.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/delay_based_bwe.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/delay_based_bwe.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/include/congestion_controller.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/median_slope_estimator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/median_slope_estimator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/probe_bitrate_estimator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/probe_bitrate_estimator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/probe_controller.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/probe_controller.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/probing_interval_estimator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/probing_interval_estimator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/transport_feedback_adapter.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/transport_feedback_adapter.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/trendline_estimator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/congestion_controller/trendline_estimator.h
)

ADD_LIBRARY(rtc_congestion_controller STATIC ${CONGESTION_CONTROLLER_SOURCES})
SET_TARGET_PROPERTIES(rtc_congestion_controller PROPERTIES FOLDER "webrtc")