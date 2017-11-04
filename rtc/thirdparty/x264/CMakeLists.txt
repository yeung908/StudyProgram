PROJECT(x264)

INCLUDE_DIRECTORIES(${x264_SOURCE_DIR}
					${x264_SOURCE_DIR}/include
					${x264_SOURCE_DIR}/common
					${x264_SOURCE_DIR}/encoder
					${x264_SOURCE_DIR}/${CMAKE_SYSTEM_PROCESSOR}
					)
IF(WIN32)
	IF(CMAKE_CL_64)
		INCLUDE(win64_config.cmake)
		ADD_DEFINITIONS(-DSTACK_ALIGNMENT=16 -DARCH_X86_64=1)
	ELSE(CMAKE_CL_64)
		INCLUDE(win32_config.cmake)
		ADD_DEFINITIONS(-DSTACK_ALIGNMENT=4 -DARCH_X86_64=0 -DARCH_X86=1)
	ENDIF(CMAKE_CL_64)
	ADD_DEFINITIONS(-DSYS_WINDOWS=1)
ENDIF(WIN32)			

IF(CMAKE_SYSTEM_PROCESSOR MATCHES "arm")
	INCLUDE(arm_config.cmake)
	ADD_DEFINITIONS(-DARCH_ARM=1 -DSTACK_ALIGNMENT=4 -Dfseek=fseeko -Dftell=ftello -DPIC=1)
	# SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mthumb -fPIC -mcpu=cortex-a8 -mfpu=neon")
ENDIF()	

IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
	INCLUDE(aarch64_config.cmake)
	ADD_DEFINITIONS(-DARCH_AARCH64=1 -DSTACK_ALIGNMENT=16 -Dfseek=fseeko -Dftell=ftello -DPIC=1)
	# SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mthumb -fPIC")
ENDIF()	

IF(ANDROID)
	ADD_DEFINITIONS(-DSYS_LINUX=1)
ENDIF()


# IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "armv7-a")
	# SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=armv7-a -D__ARM_ARCH_7__ -D__ARM_ARCH_7A__ -D__ARM_ARCH_7R__ -D__ARM_ARCH_7M__ -D__ARM_ARCH_7S__")
# ENDIF()


CONFIGURE_FILE(${x264_SOURCE_DIR}/config.h.in ${x264_SOURCE_DIR}/${CMAKE_SYSTEM_PROCESSOR}/config.h)					

LIST(APPEND X264_SOURCES
			common/mc.c
			common/predict.c
			common/pixel.c
			common/macroblock.c
			common/frame.c
			common/dct.c
			common/cpu.c
			common/cabac.c
			common/common.c
			common/osdep.c
			common/rectangle.c
			common/set.c
			common/quant.c
			common/deblock.c
			common/vlc.c
			common/mvpred.c
			common/bitstream.c
			common/threadpool.c
			encoder/analyse.c
			encoder/me.c
			encoder/ratecontrol.c
			encoder/set.c
			encoder/macroblock.c
			encoder/cabac.c
			encoder/cavlc.c
			encoder/encoder.c
			encoder/lookahead.c
)

IF(NOT WIN32)
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
ENDIF()

LIST(APPEND X264_ASM_SOURCES
			const-a.asm
			cabac-a.asm
			dct-a.asm
			deblock-a.asm
			mc-a.asm
			mc-a2.asm
			pixel-a.asm
			predict-a.asm
			quant-a.asm
			cpu-a.asm
			bitstream-a.asm
			sad-a.asm
)
IF (NOT WIN32)
	IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "X86" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "ia32")
		LIST(APPEND X264_ASM_SOURCES 
				dct-32.asm
				pixel-32.asm
				x86inc.asm
				x86util.asm
	)
		LIST(APPEND X264_SOURCES 
				common/x86/mc-c.c 
				common/x86/predict-c.c
	)
	ENDIF()

	IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "x64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
		LIST(APPEND X264_ASM_SOURCES 
					x86inc.asm
					x86util.asm
					trellis-64.asm
					dct-64.asm)
		LIST(APPEND X264_SOURCES 
				common/x86/mc-c.c 
				common/x86/predict-c.c)
	ENDIF()
ELSE()
	IF(CMAKE_CL_64)
		LIST(APPEND X264_ASM_SOURCES
					x86inc.asm
					x86util.asm		
					trellis-64.asm
					dct-64.asm)
		LIST(APPEND X264_SOURCES 
				common/x86/mc-c.c 
				common/x86/predict-c.c)
	ELSE()
		LIST(APPEND X264_ASM_SOURCES 
				dct-32.asm
				pixel-32.asm
				x86inc.asm
				x86util.asm)
		LIST(APPEND X264_SOURCES 
				common/x86/mc-c.c 
				common/x86/predict-c.c)
	ENDIF()
ENDIF()

IF(CMAKE_SYSTEM_PROCESSOR MATCHES "arm")
	LIST(APPEND X264_SOURCES 
				common/arm/mc-c.c
				common/arm/predict-c.c
	)
	LIST(APPEND X264_ASM 
				common/arm/asm.S
				common/arm/cpu-a.S
				common/arm/pixel-a.S
				common/arm/mc-a.S
				common/arm/dct-a.S
				common/arm/quant-a.S
				common/arm/deblock-a.S
				common/arm/predict-a.S
				common/arm/bitstream-a.S
	)
	SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${CMAKE_C_FLAGS}")
	MESSAGE(INFO ${CMAKE_ASM_FLAGS})
ENDIF()

IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
	LIST(APPEND X264_SOURCES
				common/aarch64/asm-offsets.c
				common/aarch64/mc-c.c
				common/aarch64/predict-c.c
	)
	LIST(APPEND X264_ASM
				common/aarch64/asm.S
				common/aarch64/bitstream-a.S
				common/aarch64/cabac-a.S
				common/aarch64/dct-a.S
				common/aarch64/deblock-a.S
				common/aarch64/mc-a.S
				common/aarch64/pixel-a.S
				common/aarch64/predict-a.S
				common/aarch64/quant-a.S
	)
ENDIF()


IF(WIN32)
	LIST(APPEND X264_SOURCES common/win32thread.c)
	ADD_DEFINITIONS("/wd4244 /wd4018 /wd4996 /wd4305 /wd4267 /wd4003")
	SET (NASM_FLAGS -I ${x264_SOURCE_DIR}/common/x86/ -DBIT_DEPTH=8 -DHIGH_BIT_DEPTH=0)
	IF(CMAKE_CL_64)
		SET(NASM_FLAGS ${NASM_FLAGS} -fwin64 -DARCH_X86_64=1)
	ELSE(CMAKE_CL_64)
		SET(NASM_FLAGS ${NASM_FLAGS} -DPREFIX -fwin32 -DARCH_X86_64=0)
	ENDIF(CMAKE_CL_64)
	ADD_DEFINITIONS("/arch:AVX")

foreach(ASM ${X264_ASM_SOURCES})
	set(ASM_SRC ${x264_SOURCE_DIR}/common/x86/${ASM})
    list(APPEND X264_ASM_OBJS ${ASM}.obj)
	add_custom_command(
		OUTPUT ${ASM}.obj
		COMMAND nasm ARGS ${NASM_FLAGS} ${ASM_SRC} -o ${ASM}.obj
		DEPENDS ${ASM_SRC})
endforeach()

	LIST(APPEND X264_SOURCES ${X264_ASM_OBJS})

ENDIF(WIN32)

ADD_LIBRARY(x264 STATIC ${X264_SOURCES} ${X264_ASM})