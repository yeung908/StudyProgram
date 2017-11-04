INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc
					${CMAKE_CURRENT_SOURCE_DIR}/src
					${CMAKE_SOURCE_DIR}/tests/winpcap/Include
					${CMAKE_SOURCE_DIR}/sdk/ServiceAgent/inc
					${CMAKE_SOURCE_DIR}/thirdparty/WebRTCWithCMake/src
					${CMAKE_SOURCE_DIR}/thirdparty/Poco/poco-1.7.4-win/Net/include
					)
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/tests/winpcap/Lib)		
INCLUDE(${webrtc_SOURCE_DIR}/webrtc_targets.cmake)	
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src DIR_SRCS)

FILE(GLOB INCS "inc/*.h")
FILE(GLOB HEADERS "src/*.h")
SOURCE_GROUP("Headers Files" FILES ${INCS} ${HEADERS})

ADD_EXECUTABLE(udp_client ${DIR_SRCS} ${HEADERS} ${INCS})			 
ADD_DEFINITIONS(-DWPCAP -DHAVE_REMOTE /D"WEBRTC_WIN" /D"NOMINMAX")
TARGET_LINK_LIBRARIES(udp_client 
						ServiceAgent 
						Packet 
						wpcap 
						ws2_32
						${WEBRTC_COMMON_TARGETS} 
						Winmm
						PocoUtil 
						PocoXML 
						PocoJSON 
						PocoFoundation
						PocoNet
						)
SET_TARGET_PROPERTIES(udp_client PROPERTIES FOLDER "tian")
