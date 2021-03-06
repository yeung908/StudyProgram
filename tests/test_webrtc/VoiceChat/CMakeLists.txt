#CMAKE_MINIMUM_REQUIRED(VERSION 3.6.0)
# 设置生成文件的路径
#SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/win/bin)
#SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/win/lib)

# CMAKE的模块路径，在FIND_PACKAGE()命令中会用到这个路径，FIND_PACKAGE必须在这个路径底下找，
# CMAKE_PREFIX_PATH 应该指到包含Bin及lib的一级
SET(CMAKE_PREFIX_PATH "D:\\Qt\\5.6\\msvc2015_64\\")
SET(CMAKE_INCLUDE_CURRENT_DIR ON)	

FIND_PACKAGE(Qt5Core)
FIND_PACKAGE(Qt5Gui)
FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5Network)

# 头文件路径
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc
					//${CMAKE_SOURCE_DIR}/tests/winpcap/Include
					${CMAKE_SOURCE_DIR}/thirdparty/Poco/poco-1.7.4-win/Net/include
					${CMAKE_SOURCE_DIR}/rtc/src
					)

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/tests/winpcap/Lib/x64)

# 所有源文件名到SRCS中
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src SRCS)

# 所有头文件名汇集到INCS和HEADERS中 并分组
FILE(GLOB INCS "inc/*.h")
FILE(GLOB HEADERS "src/*.h")
SOURCE_GROUP("Header Files" FILES ${INCS} ${HEADERS})

# 由.ui文件生成ui_文件
FILE(GLOB FORMS "form/voice_chat.ui")
QT5_WRAP_UI(FORMS_UIC ${FORMS})
SOURCE_GROUP("Form Files" FILES ${FORMS})

# 生成moc文件
FILE(GLOB MOCS "inc/voice_chat.h")
FILE(GLOB MOCSV "inc/my_transport.h")
QT5_WRAP_CPP(HEADERS_MOC ${MOCS})
QT5_WRAP_CPP(HEADERS_MOCV ${MOCSV})
MESSAGE(${HEADERS_MOC})
MESSAGE(${HEADERS_MOCV})
SOURCE_GROUP("Generated Files" FILES ${HEADERS_MOC} ${HEADERS_MOCV} ${FORMS_UIC})

INCLUDE(${webrtc_SOURCE_DIR}/webrtc_targets.cmake)

ADD_EXECUTABLE(VoiceChat WIN32 ${SRCS} ${HEADERS} ${INCS} ${HEADERS_MOC} ${HEADERS_MOCV} ${FORMS_UIC})

# 添加Qt所需的库
IF(WIN32) 
	ADD_DEFINITIONS(-DUNICODE -D_UNICODE /D"PA_WDMKS_NO_KSGUID_LIB" /D"WEBRTC_WIN" /D"NOMINMAX")   #预定义
TARGET_LINK_LIBRARIES(VoiceChat
					PocoNet
					${WEBRTC_MEDIA_TARGETS}
					${WEBRTC_SDK_TARGETS}
					${WEBRTC_VIDEO_TARGETS} 
					${WEBRTC_AUDIO_TARGETS} 
					${WEBRTC_COMMON_TARGETS} 
					${WEBRTC_VIDEO_DEPEND} 
					${WEBRTC_AUDIO_DEPEND} 
					${WEBRTC_TEST_DEPEND} 
					libavcodec libavutil libprotobuf
					PocoUtil PocoXML PocoJSON PocoFoundation PocoNet
					ssl
					Ws2_32 mfuuid mfplat mf mfreadwrite shlwapi d3d9 dxva2 winmm msdmo amstrmid wmcodecdspuuid dmoguids iphlpapi D3D11 DXGI
					Qt5::Core
					Qt5::Gui
					Qt5::Widgets
					Qt5::Network
					)
SET_TARGET_PROPERTIES(VoiceChat PROPERTIES FOLDER "tian")	
ENDIF(WIN32)				
