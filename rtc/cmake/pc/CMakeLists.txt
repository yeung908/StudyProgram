INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src
					${webrtc_SOURCE_DIR}/thirdparty/
					${webrtc_SOURCE_DIR}/thirdparty/libsrtp/config
					${webrtc_SOURCE_DIR}/thirdparty/libsrtp/include
					${webrtc_SOURCE_DIR}/thirdparty/libsrtp/crypto/include
)

LIST(APPEND RTC_PC_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/pc/audiomonitor.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/audiomonitor.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/bundlefilter.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/bundlefilter.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/channel.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/channel.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/channelmanager.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/channelmanager.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/currentspeakermonitor.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/currentspeakermonitor.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/mediamonitor.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/mediamonitor.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/mediasession.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/mediasession.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/rtcpmuxfilter.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/rtcpmuxfilter.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/srtpfilter.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/srtpfilter.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/voicechannel.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/audiotrack.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/audiotrack.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/datachannel.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/datachannel.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/dtmfsender.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/dtmfsender.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/jsepicecandidate.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/jsepsessiondescription.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/localaudiosource.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/localaudiosource.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/mediacontroller.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/mediacontroller.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/mediastream.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/mediastream.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/mediastreamobserver.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/mediastreamobserver.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/mediastreamtrack.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/ortcfactory.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/ortcfactory.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/peerconnection.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/peerconnection.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/peerconnectionfactory.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/peerconnectionfactory.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/remoteaudiosource.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/remoteaudiosource.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/rtcstatscollector.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/rtcstatscollector.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/rtpreceiver.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/rtpreceiver.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/rtpsender.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/rtpsender.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/sctputils.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/sctputils.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/statscollector.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/statscollector.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/streamcollection.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/videocapturertracksource.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/videocapturertracksource.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/videotrack.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/videotrack.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/videotracksource.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/videotracksource.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/webrtcsdp.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/webrtcsdp.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/webrtcsession.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/webrtcsession.h
			${webrtc_SOURCE_DIR}/src/webrtc/pc/webrtcsessiondescriptionfactory.cc
			${webrtc_SOURCE_DIR}/src/webrtc/pc/webrtcsessiondescriptionfactory.h
)
	
IF(RTC_USE_QUIC)
	LIST(APPEND RTC_PC_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/pc/quicdatachannel.cc
				${webrtc_SOURCE_DIR}/src/webrtc/pc/quicdatachannel.h
				${webrtc_SOURCE_DIR}/src/webrtc/pc/quicdatatransport.cc
				${webrtc_SOURCE_DIR}/src/webrtc/pc/quicdatatransport.h
	)
ENDIF()


ADD_DEFINITIONS(-DHAVE_SRTP)


ADD_LIBRARY(rtc_peerconnection STATIC ${RTC_PC_SOURCES})
SET_TARGET_PROPERTIES(rtc_peerconnection PROPERTIES FOLDER "webrtc")