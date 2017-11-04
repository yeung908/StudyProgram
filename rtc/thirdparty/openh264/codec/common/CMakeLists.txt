INCLUDE_DIRECTORIES(${openh264_SOURCE_DIR}/include
					${openh264_SOURCE_DIR}/codec/api/svc
					${openh264_SOURCE_DIR}/codec/common/inc
					${openh264_SOURCE_DIR}/codec/common
					)
					

LIST(APPEND OPENH264_COMMON_SOURCES
			${openh264_SOURCE_DIR}/codec/common/inc/WelsCircleQueue.h
			${openh264_SOURCE_DIR}/codec/common/inc/WelsList.h
			${openh264_SOURCE_DIR}/codec/common/inc/WelsLock.h
			${openh264_SOURCE_DIR}/codec/common/inc/WelsTask.h
			${openh264_SOURCE_DIR}/codec/common/inc/WelsTaskThread.h
			${openh264_SOURCE_DIR}/codec/common/inc/WelsThread.h
			${openh264_SOURCE_DIR}/codec/common/inc/WelsThreadLib.h
			${openh264_SOURCE_DIR}/codec/common/inc/WelsThreadPool.h
			${openh264_SOURCE_DIR}/codec/common/inc/copy_mb.h
			${openh264_SOURCE_DIR}/codec/common/inc/cpu.h
			${openh264_SOURCE_DIR}/codec/common/inc/cpu_core.h
			${openh264_SOURCE_DIR}/codec/common/inc/crt_util_safe_x.h
			${openh264_SOURCE_DIR}/codec/common/inc/deblocking_common.h
			${openh264_SOURCE_DIR}/codec/common/inc/expand_pic.h
			${openh264_SOURCE_DIR}/codec/common/inc/golomb_common.h
			${openh264_SOURCE_DIR}/codec/common/inc/intra_pred_common.h
			${openh264_SOURCE_DIR}/codec/common/inc/ls_defines.h
			${openh264_SOURCE_DIR}/codec/common/inc/macros.h
			${openh264_SOURCE_DIR}/codec/common/inc/mc.h
			${openh264_SOURCE_DIR}/codec/common/inc/measure_time.h
			${openh264_SOURCE_DIR}/codec/common/inc/memory_align.h
			${openh264_SOURCE_DIR}/codec/common/inc/sad_common.h
			${openh264_SOURCE_DIR}/codec/common/inc/typedefs.h
			${openh264_SOURCE_DIR}/codec/common/inc/utils.h
			${openh264_SOURCE_DIR}/codec/common/inc/version.h
			${openh264_SOURCE_DIR}/codec/common/inc/welsCodecTrace.h
			${openh264_SOURCE_DIR}/codec/common/inc/wels_common_defs.h
			${openh264_SOURCE_DIR}/codec/common/inc/wels_const_common.h
			${openh264_SOURCE_DIR}/codec/common/src/WelsTaskThread.cpp
			${openh264_SOURCE_DIR}/codec/common/src/WelsThread.cpp
			${openh264_SOURCE_DIR}/codec/common/src/WelsThreadLib.cpp
			${openh264_SOURCE_DIR}/codec/common/src/WelsThreadPool.cpp
			${openh264_SOURCE_DIR}/codec/common/src/common_tables.cpp
			${openh264_SOURCE_DIR}/codec/common/src/copy_mb.cpp
			${openh264_SOURCE_DIR}/codec/common/src/cpu.cpp
			${openh264_SOURCE_DIR}/codec/common/src/crt_util_safe_x.cpp
			${openh264_SOURCE_DIR}/codec/common/src/deblocking_common.cpp
			${openh264_SOURCE_DIR}/codec/common/src/expand_pic.cpp
			${openh264_SOURCE_DIR}/codec/common/src/intra_pred_common.cpp
			${openh264_SOURCE_DIR}/codec/common/src/mc.cpp
			${openh264_SOURCE_DIR}/codec/common/src/memory_align.cpp
			${openh264_SOURCE_DIR}/codec/common/src/sad_common.cpp
			${openh264_SOURCE_DIR}/codec/common/src/utils.cpp
			${openh264_SOURCE_DIR}/codec/common/src/welsCodecTrace.cpp
)

LIST(APPEND OPENH264_COMMON_SOURCES_ASM_X86
			asm_inc.asm
			cpuid.asm
			dct.asm
			deblock.asm
			expand_picture.asm
			intra_pred_com.asm
			mb_copy.asm
			mc_chroma.asm
			mc_luma.asm
			satd_sad.asm
			vaa.asm
)

LIST(APPEND OPENH264_COMMON_SOURCES_ASM_ARM
			${openh264_SOURCE_DIR}/codec/common/arm/arm_arch_common_macro.S
			${openh264_SOURCE_DIR}/codec/common/arm/copy_mb_neon.S
			${openh264_SOURCE_DIR}/codec/common/arm/deblocking_neon.S
			${openh264_SOURCE_DIR}/codec/common/arm/intra_pred_common_neon.S
			${openh264_SOURCE_DIR}/codec/common/arm/mc_neon.S
)

LIST(APPEND OPENH264_COMMON_SOURCES_ASM_ARM64
			${openh264_SOURCE_DIR}/codec/common/arm64/arm_arch64_common_macro.S
			${openh264_SOURCE_DIR}/codec/common/arm64/copy_mb_aarch64_neon.S
			${openh264_SOURCE_DIR}/codec/common/arm64/deblocking_aarch64_neon.S
			${openh264_SOURCE_DIR}/codec/common/arm64/expand_picture_aarch64_neon.S
			${openh264_SOURCE_DIR}/codec/common/arm64/intra_pred_common_aarch64_neon.S
			${openh264_SOURCE_DIR}/codec/common/arm64/mc_aarch64_neon.S
)

IF((CMAKE_SYSTEM_PROCESSOR STREQUAL "X86") OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
	OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86") OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "ia32")
	OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64"))
	ADD_DEFINITIONS(/DX86_ASM)
	IF(WIN32)
		IF(CMAKE_CL_64)
			SET(YASM_FLAGS ${YASM_FLAGS} -m AMD64 -fwin64 -DWIN64)
		ELSE(CMAKE_CL_64)
		SET(YASM_FLAGS ${YASM_FLAGS} -DPREFIX -m x86 -fwin32 -DX86_32)
		ENDIF(CMAKE_CL_64)
	ENDIF(WIN32)
	
	IF(APPLE)
		SET(YASM_FLAGS ${YASM_FLAGS} -m AMD64 -fmacho64)
	ENDIF(APPLE)

	FOREACH(ASM ${OPENH264_COMMON_SOURCES_ASM_X86})
		SET(ASM_SRC ${openh264_SOURCE_DIR}/codec/common/x86/${ASM})
		LIST(APPEND OPENH264_COMMON_ASM_SOURCES ${ASM_SRC})
		LIST(APPEND OPENH264_COMMON_ASM_OBJS ${ASM}.obj)
		ADD_CUSTOM_COMMAND(
			OUTPUT ${ASM}.obj
			COMMAND yasm ARGS ${YASM_FLAGS} ${ASM_SRC} -o ${ASM}.obj
			DEPENDS ${ASM_SRC})
	ENDFOREACH()
ELSEIF(CMAKE_SYSTEM_PROCESSOR STREQUAL "armv7-a")
	LIST(APPEND OPENH264_COMMON_ASM_SOURCES ${OPENH264_COMMON_SOURCES_ASM_ARM})
ELSEIF(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
	LIST(APPEND OPENH264_COMMON_ASM_SOURCES ${OPENH264_COMMON_SOURCES_ASM_ARM64})
ENDIF()

IF(ANDROID)
	INCLUDE_DIRECTORIES(${openh264_SOURCE_DIR}/codec/common/android)
	ADD_DEFINITIONS(-DANDROID_NDK)
	LIST(APPEND OPENH264_COMMON_SOURCES
				${openh264_SOURCE_DIR}/codec/common/android/cpu-features.h
				${openh264_SOURCE_DIR}/codec/common/android/cpu-features.c)
				
	SET(CMAKE_CXX_FLAGS "-D__UCLIBC__ -mfpu=neon -fexceptions -frtti -fpermissive ${CMAKE_CXX_FLAGS}")
	MESSAGE(${CMAKE_CXX_FLAGS})

ENDIF(ANDROID)


ADD_LIBRARY(oh264_common STATIC ${OPENH264_COMMON_SOURCES} ${OPENH264_COMMON_ASM_OBJS})