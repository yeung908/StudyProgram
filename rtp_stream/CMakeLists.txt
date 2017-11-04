INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc
					${CMAKE_SOURCE_DIR}/rtc/src
					${CMAKE_SOURCE_DIR}/commons/inc)
					
LIST(APPEND RTP_RECIVER_SOURCES
	inc/ServerRtpStream.h
	src/ServerRtpStreamWebrtcImpl.h
	src/ServerRtpStream.cxx
	src/ServerRtpStreamWebrtcImpl.cxx
	inc/ServerRtpTransport.h
	src/ServerRtpTransport.cxx
	)

ADD_LIBRARY(rtp_stream STATIC ${RTP_RECIVER_SOURCES})

SET_TARGET_PROPERTIES(rtp_stream PROPERTIES FOLDER "common")

IF(WIN32)
	ADD_DEFINITIONS(/D"WEBRTC_WIN" /D"NOMINMAX")
ELSE()
	ADD_DEFINITIONS(-D"WEBRTC_POSIX")
ENDIF(WIN32)

IF(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	ADD_DEFINITIONS(-D"WEBRTC_LINUX")
ENDIF()