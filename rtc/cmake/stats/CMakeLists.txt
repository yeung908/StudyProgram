INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND RTC_STATS_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/stats/rtcstats.cc
			${webrtc_SOURCE_DIR}/src/webrtc/stats/rtcstats_objects.cc
			${webrtc_SOURCE_DIR}/src/webrtc/stats/rtcstatsreport.cc
)

ADD_LIBRARY(rtc_stats STATIC ${RTC_STATS_SOURCES})
SET_TARGET_PROPERTIES(rtc_stats PROPERTIES FOLDER "webrtc")