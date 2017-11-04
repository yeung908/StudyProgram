INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src
					${webrtc_SOURCE_DIR}/thirdparty/libyuv/include)

LIST(APPEND RTC_API_SOUCES
	${webrtc_SOURCE_DIR}/src/webrtc/api/datachannel.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/datachannelinterface.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/dtmfsenderinterface.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/jsep.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/jsepicecandidate.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/jsepsessiondescription.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/mediaconstraintsinterface.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/api/mediaconstraintsinterface.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/mediacontroller.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/mediastream.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/mediastreaminterface.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/api/mediastreaminterface.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/mediastreamproxy.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/mediastreamtrack.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/mediastreamtrackproxy.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/mediatypes.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/api/mediatypes.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/notifier.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/ortcfactoryinterface.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/peerconnectionfactoryproxy.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/peerconnectioninterface.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/peerconnectionproxy.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/proxy.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/rtpparameters.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/rtpreceiverinterface.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/rtpsender.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/rtpsenderinterface.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/statstypes.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/api/statstypes.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/streamcollection.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/trackmediainfomap.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/api/trackmediainfomap.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/udptransportinterface.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/umametrics.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/videosourceproxy.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/videotracksource.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/webrtcsdp.h
	${webrtc_SOURCE_DIR}/src/webrtc/api/stats/rtcstats.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/stats/rtcstats_objects.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/stats/rtcstatscollectorcallback.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/stats/rtcstatsreport.h
	${webrtc_SOURCE_DIR}/src/webrtc/api/audio/audio_mixer.h
	${webrtc_SOURCE_DIR}/src/webrtc/api/call/transport.h
	${webrtc_SOURCE_DIR}/src/webrtc/api/video/i420_buffer.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/api/video/i420_buffer.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/video/video_frame.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/api/video/video_frame.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/video/video_frame_buffer.h
    ${webrtc_SOURCE_DIR}/src/webrtc/api/video/video_rotation.h
)

ADD_LIBRARY(rtc_api STATIC ${RTC_API_SOUCES})
SET_TARGET_PROPERTIES(rtc_api PROPERTIES FOLDER "webrtc")