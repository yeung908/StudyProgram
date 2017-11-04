# Processing
INCLUDE_DIRECTORIES(${openh264_SOURCE_DIR}/codec/api/svc
					${openh264_SOURCE_DIR}/codec/common/inc
					${openh264_SOURCE_DIR}/codec/processing/interface
					${openh264_SOURCE_DIR}/codec/processing/src/adaptivequantization
					${openh264_SOURCE_DIR}/codec/processing/src/common
					${openh264_SOURCE_DIR}/codec/processing/src/downsample
					${openh264_SOURCE_DIR}/codec/processing/src/scrolldetection
					${openh264_SOURCE_DIR}/codec/processing/src/vaacalc
)

LIST(APPEND OPENH264_PROCESSING_SOURCES
			${openh264_SOURCE_DIR}/codec/processing/interface/IWelsVP.h
			${openh264_SOURCE_DIR}/codec/processing/src/adaptivequantization/AdaptiveQuantization.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/adaptivequantization/AdaptiveQuantization.h
			${openh264_SOURCE_DIR}/codec/processing/src/backgrounddetection/BackgroundDetection.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/backgrounddetection/BackgroundDetection.h
			${openh264_SOURCE_DIR}/codec/processing/src/common/WelsFrameWork.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/common/WelsFrameWork.h
			${openh264_SOURCE_DIR}/codec/processing/src/common/WelsFrameWorkEx.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/common/common.h
			${openh264_SOURCE_DIR}/codec/processing/src/common/memory.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/common/memory.h
			${openh264_SOURCE_DIR}/codec/processing/src/common/resource.h
			${openh264_SOURCE_DIR}/codec/processing/src/common/typedef.h
			${openh264_SOURCE_DIR}/codec/processing/src/common/util.h
			${openh264_SOURCE_DIR}/codec/processing/src/complexityanalysis/ComplexityAnalysis.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/complexityanalysis/ComplexityAnalysis.h
			${openh264_SOURCE_DIR}/codec/processing/src/denoise/denoise.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/denoise/denoise.h
			${openh264_SOURCE_DIR}/codec/processing/src/denoise/denoise_filter.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/downsample/downsample.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/downsample/downsample.h
			${openh264_SOURCE_DIR}/codec/processing/src/downsample/downsamplefuncs.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/imagerotate/imagerotate.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/imagerotate/imagerotate.h
			${openh264_SOURCE_DIR}/codec/processing/src/imagerotate/imagerotatefuncs.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/scenechangedetection/SceneChangeDetection.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/scenechangedetection/SceneChangeDetection.h
			${openh264_SOURCE_DIR}/codec/processing/src/scrolldetection/ScrollDetection.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/scrolldetection/ScrollDetection.h
			${openh264_SOURCE_DIR}/codec/processing/src/scrolldetection/ScrollDetectionFuncs.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/scrolldetection/ScrollDetectionFuncs.h
			${openh264_SOURCE_DIR}/codec/processing/src/vaacalc/vaacalcfuncs.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/vaacalc/vaacalculation.cpp
			${openh264_SOURCE_DIR}/codec/processing/src/vaacalc/vaacalculation.h
)

LIST(APPEND OPENH264_PROCESSING_SOURCES_ASM_X86
			denoisefilter.asm
			downsample_bilinear.asm
			vaa.asm
)

LIST(APPEND OPENH264_PROCESSING_SOURCES_ASM_ARM
			${openh264_SOURCE_DIR}/codec/processing/src/arm/adaptive_quantization.S
			${openh264_SOURCE_DIR}/codec/processing/src/arm/down_sample_neon.S
			${openh264_SOURCE_DIR}/codec/processing/src/arm/pixel_sad_neon.S
			${openh264_SOURCE_DIR}/codec/processing/src/arm/vaa_calc_neon.S
)

LIST(APPEND OPENH264_PROCESSING_SOURCES_ASM_ARM64
			${openh264_SOURCE_DIR}/codec/processing/src/arm64/adaptive_quantization_aarch64_neon.S
			${openh264_SOURCE_DIR}/codec/processing/src/arm64/down_sample_aarch64_neon.S
			${openh264_SOURCE_DIR}/codec/processing/src/arm64/pixel_sad_aarch64_neon.S
			${openh264_SOURCE_DIR}/codec/processing/src/arm64/vaa_calc_aarch64_neon.S
)


IF((CMAKE_SYSTEM_PROCESSOR STREQUAL "X86") OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
	OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86") OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "ia32")
	OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64"))
	ADD_DEFINITIONS(/DX86_ASM)

	IF(WIN32)
		IF(CMAKE_CL_64)
			SET(YASM_FLAGS ${YASM_FLAGS} -I${openh264_SOURCE_DIR}/codec/common/x86 -m AMD64 -fwin64 -DWIN64)
		ELSE(CMAKE_CL_64)
		SET(YASM_FLAGS ${YASM_FLAGS} -I${openh264_SOURCE_DIR}/codec/common/x86 -DPREFIX -m x86 -fwin32 -DX86_32)
		ENDIF(CMAKE_CL_64)
	ENDIF(WIN32)
	
	IF(APPLE)
		SET(YASM_FLAGS ${YASM_FLAGS} -m AMD64 -fmacho64)
	ENDIF(APPLE)

	FOREACH(ASM ${OPENH264_PROCESSING_SOURCES_ASM_X86})
		SET(ASM_SRC ${openh264_SOURCE_DIR}/codec/processing/src/x86/${ASM})
		LIST(APPEND OPENH264_PROCESSING_ASM_SOURCES ${ASM_SRC})
		LIST(APPEND OPENH264_PROCESSING_ASM_OBJS ${ASM}.obj)
		ADD_CUSTOM_COMMAND(
			OUTPUT ${ASM}.obj
			COMMAND yasm ARGS ${YASM_FLAGS} ${ASM_SRC} -o ${ASM}.obj
			DEPENDS ${ASM_SRC})
	ENDFOREACH()
ELSEIF(CMAKE_SYSTEM_PROCESSOR STREQUAL "armv7-a")
	LIST(APPEND OPENH264_PROCESSING_ASM_SOURCES ${OPENH264_PROCESSING_SOURCES_ASM_ARM})
	SET(CMAKE_CXX_FLAGS "-D__UCLIBC__ -mfpu=neon -fexceptions -frtti -fpermissive ${CMAKE_CXX_FLAGS}")
	MESSAGE(${CMAKE_CXX_FLAGS})
ELSEIF(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
	LIST(APPEND OPENH264_PROCESSING_ASM_SOURCES ${OPENH264_PROCESSING_SOURCES_ASM_ARM64})
ENDIF()




ADD_LIBRARY(oh264_proc STATIC ${OPENH264_PROCESSING_SOURCES} ${OPENH264_PROCESSING_ASM_OBJS})
