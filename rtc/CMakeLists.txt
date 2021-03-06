CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

PROJECT(webrtc)

IF(ANDROID)
	SET(CAN_USE_ASSEMBLER TRUE)
	ENABLE_LANGUAGE(ASM)
ENDIF(ANDROID)

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

# Add thirdparty modules
SET(CMAKE_FILES_DIR ${webrtc_SOURCE_DIR}/cmake)

IF(NOT (CMAKE_SYSTEM_NAME MATCHES "Linux"))
	IF(WIN32)
		ADD_SUBDIRECTORY(thirdparty/libjpeg-turbo)
		SET_TARGET_PROPERTIES(jpeg-static PROPERTIES FOLDER "thirdparty/libjpeg")
		SET_TARGET_PROPERTIES(simd PROPERTIES FOLDER "thirdparty/libjpeg")
		SET_TARGET_PROPERTIES(turbojpeg-static PROPERTIES FOLDER "thirdparty/libjpeg")
	ENDIF(WIN32)
	
	ADD_SUBDIRECTORY(thirdparty/libyuv)
	SET_TARGET_PROPERTIES(yuv PROPERTIES FOLDER "thirdparty/libyuv")

	ADD_SUBDIRECTORY(thirdparty/libvpx)
	SET_TARGET_PROPERTIES(vp8  PROPERTIES FOLDER "thirdparty/libvpx")
	SET_TARGET_PROPERTIES(vp9  PROPERTIES FOLDER "thirdparty/libvpx")
	SET_TARGET_PROPERTIES(vpx  PROPERTIES FOLDER "thirdparty/libvpx")
	SET_TARGET_PROPERTIES(vpx_config  PROPERTIES FOLDER "thirdparty/libvpx")
	SET_TARGET_PROPERTIES(vpx_dsp  PROPERTIES FOLDER "thirdparty/libvpx")
	SET_TARGET_PROPERTIES(vpx_mem  PROPERTIES FOLDER "thirdparty/libvpx")
	SET_TARGET_PROPERTIES(vpx_ports  PROPERTIES FOLDER "thirdparty/libvpx")
	SET_TARGET_PROPERTIES(vpx_scale  PROPERTIES FOLDER "thirdparty/libvpx")
	SET_TARGET_PROPERTIES(vpx_util  PROPERTIES FOLDER "thirdparty/libvpx")

	ADD_SUBDIRECTORY(thirdparty/openh264)
	SET_TARGET_PROPERTIES(oh264_common  PROPERTIES FOLDER "thirdparty/openh264")
	SET_TARGET_PROPERTIES(oh264_proc  PROPERTIES FOLDER "thirdparty/openh264")
	SET_TARGET_PROPERTIES(oh264_enc  PROPERTIES FOLDER "thirdparty/openh264")
	IF(WIN32)
		INCLUDE_EXTERNAL_MSPROJECT(directshow_baseclasses ${webrtc_SOURCE_DIR}/thirdparty/winsdk_samples/directshow_baseclasses.vcxproj)
		SET_TARGET_PROPERTIES(directshow_baseclasses PROPERTIES FOLDER "thirdparty/dshow")
	ENDIF(WIN32)
	
	IF(ANDROID)
		ADD_SUBDIRECTORY(thirdparty/libevent)
	ENDIF(ANDROID)
	
	ADD_SUBDIRECTORY(thirdparty/x264)
	SET_TARGET_PROPERTIES(x264 PROPERTIES FOLDER "thirdparty/x264")
ENDIF()

ADD_SUBDIRECTORY(thirdparty/Opus)
SET_TARGET_PROPERTIES(opus PROPERTIES FOLDER "thirdparty/opus")

# Add pre-defines
ADD_DEFINITIONS(-DWEBRTC_RESTRICT_LOGGING 
				-DWEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE 
				-DEXPAT_RELATIVE_PATH 
				-DHAVE_WEBRTC_VIDEO 
				-DHAVE_WEBRTC_VOICE
				-DLOGGING_INSIDE_WEBRTC
				-D__STDC_CONSTANT_MACROS
				-D__STDC_FORMAT_MACROS
				-DNOMINMAX
				-DWEBRTC_INTELLIGIBILITY_ENHANCER=1)

IF(WIN32)
	ADD_DEFINITIONS(-DWEBRTC_WIN -D_CRT_SECURE_NO_WARNINGS -DWIN32_LEAN_AND_MEAN -DUNICODE -D_UNICODE /wd4244 /wd4267 /wd4996) 
ENDIF(WIN32)

IF(NOT WIN32)
	ADD_DEFINITIONS(-DWEBRTC_POSIX)
ENDIF(NOT WIN32)

IF(ANDROID)
	ADD_DEFINITIONS(-DWEBRTC_LINUX -DWEBRTC_ANDROID -DWEBRTC_BUILD_LIBEVENT -D__UCLIBC__)
	IF(NOT (CMAKE_C_COMPILER_ID MATCHES "Clang"))
		SET(CMAKE_C_FLAGS "-fno-builtin-cos -fno-builtin-sin -fno-builtin-cosf -fno-builtin-sinf ${CMAKE_C_FLAGS}")
	ENDIF()
	IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "armv7-a")
		SET(CMAKE_C_FLAGS "-mfloat-abi=softfp -mfpu=neon ${CMAKE_C_FLAGS}")
		SET(CMAKE_CXX_FLAGS "-mfloat-abi=softfp -mfpu=neon ${CMAKE_CXX_FLAGS}")
	ENDIF()
	
	# STRING(REPLACE "-mfpu=vfpv3-d16" "" FIXED_C_FLAGS ${CMAKE_C_FLAGS})
	# STRING(REPLACE "-fno-rtti" "" FIXED_C_FLAGS ${FIXED_C_FLAGS})
	# STRING(REPLACE "-fno-exceptions" "" FIXED_C_FLAGS ${FIXED_C_FLAGS})
	# SET(CMAKE_C_FLAGS ${FIXED_C_FLAGS})

	# STRING(REPLACE "-mfpu=vfpv3-d16" "" FIXED_CXX_FLAGS ${CMAKE_CXX_FLAGS})
	# STRING(REPLACE "-fno-rtti" "" FIXED_CXX_FLAGS ${FIXED_CXX_FLAGS})
	# STRING(REPLACE "-fno-exceptions" "" FIXED_CXX_FLAGS ${FIXED_CXX_FLAGS})
	# SET(CMAKE_CXX_FLAGS ${FIXED_CXX_FLAGS})
	
	SET(CMAKE_ASM_FLAGS ${CMAKE_C_FLAGS})
ENDIF(ANDROID)

IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
	ADD_DEFINITIONS(-DWEBRTC_LINUX -DWEBRTC_BUILD_LIBEVENT)
ENDIF()

IF(APPLE)
	ADD_DEFINITIONS(-DWEBRTC_MAC)
	IF(BUILD_IOS)
		ADD_DEFINITIONS(-DWEBRTC_IOS)
	ENDIF(BUILD_IOS)
ENDIF(APPLE)



# IF(NOT WIN32)
	# SET(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -Wno-strict-overflow )
	# SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Wnon-virtual-dtor -Woverloaded-virtual )
# ENDIF(NOT WIN32)

IF(CMAKE_C_COMPILER_ID EQUAL "Clang")
	SET(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -Wimplicit-fallthrough -Wthread-safety -Winconsistent-missing-override -Wundef)
ENDIF()

IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
	ADD_DEFINITIONS(-DWEBRTC_ARCH_ARM64 -DWEBRTC_HAS_NEON)
ENDIF()

IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "armv7-a")
	ADD_DEFINITIONS(-DWEBRTC_ARCH_ARM -DWEBRTC_ARCH_ARM_V7 -DWEBRTC_HAS_NEON)
ENDIF()

ADD_SUBDIRECTORY(${CMAKE_FILES_DIR})
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/api)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/audio)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/base)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/call)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/common_audio)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/common_video)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/logging)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/media)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/audio_coding)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/audio_conf_mixer)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/audio_mixer)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/audio_processing)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/bitrate_controller)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/congestion_controller)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/media_file)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/pacing)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/remote_bitrate_estimator)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/rtp_rtcp)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/utility)

ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/stats)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/system_wrappers)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/voice_engine)
ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/voice_server_engine)

# We don't support video features in linux just now.
IF(NOT (CMAKE_SYSTEM_NAME MATCHES "Linux"))
	ADD_SUBDIRECTORY(thirdparty/libsrtp)
	SET_TARGET_PROPERTIES(srtp  PROPERTIES FOLDER "thirdparty/libsrtp")
	
	ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/audio_device)
	ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/desktop_capture)
	ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/video_capture)
	ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/video_coding)
	ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/video_processing)
	ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/modules/video_render)
	ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/video)
	ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/p2p)
	ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/pc)
ENDIF()

IF(APPEND OR ANDROID)
	ADD_SUBDIRECTORY(${CMAKE_FILES_DIR}/sdk)
ENDIF()

IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	ADD_SUBDIRECTORY(src/test)
ENDIF()
