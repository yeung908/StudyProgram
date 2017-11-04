# Encoder
INCLUDE_DIRECTORIES(
			${openh264_SOURCE_DIR}/codec/api/svc
			${openh264_SOURCE_DIR}/codec/common/inc
			${openh264_SOURCE_DIR}/codec/encoder/core/inc
			${openh264_SOURCE_DIR}/codec/encoder/plus/inc
			${openh264_SOURCE_DIR}/codec/processing/interface
)

LIST(APPEND OPENH264_ENCODER_SOURCES
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/as264_common.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/au_set.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/deblocking.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/decode_mb_aux.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/dq_map.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/encode_mb_aux.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/encoder.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/encoder_context.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/extern.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/get_intra_predictor.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/mb_cache.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/md.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/mt_defs.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/mv_pred.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/nal_encap.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/param_svc.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/parameter_sets.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/paraset_strategy.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/picture.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/picture_handle.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/rc.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/ref_list_mgr_svc.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/sample.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/set_mb_syn_cabac.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/set_mb_syn_cavlc.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/slice.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/slice_multi_threading.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/stat.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/svc_base_layer_md.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/svc_enc_frame.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/svc_enc_golomb.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/svc_enc_macroblock.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/svc_enc_slice_segment.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/svc_encode_mb.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/svc_encode_slice.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/svc_mode_decision.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/svc_motion_estimate.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/svc_set_mb_syn.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/svc_set_mb_syn_cavlc.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/vlc_encoder.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/wels_common_basis.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/wels_const.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/wels_func_ptr_def.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/wels_preprocess.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/wels_task_base.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/wels_task_encoder.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/wels_task_management.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/inc/wels_transpose_matrix.h
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/au_set.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/deblocking.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/decode_mb_aux.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/encode_mb_aux.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/encoder.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/encoder_data_tables.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/encoder_ext.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/get_intra_predictor.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/md.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/mv_pred.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/nal_encap.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/paraset_strategy.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/picture_handle.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/ratectl.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/ref_list_mgr_svc.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/sample.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/set_mb_syn_cabac.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/set_mb_syn_cavlc.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/slice_multi_threading.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/svc_base_layer_md.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/svc_enc_slice_segment.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/svc_encode_mb.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/svc_encode_slice.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/svc_mode_decision.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/svc_motion_estimate.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/svc_set_mb_syn_cabac.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/svc_set_mb_syn_cavlc.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/wels_preprocess.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/wels_task_base.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/wels_task_encoder.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/core/src/wels_task_management.cpp
  ${openh264_SOURCE_DIR}/codec/encoder/plus/inc/welsEncoderExt.h
  ${openh264_SOURCE_DIR}/codec/encoder/plus/src/welsEncoderExt.cpp

  # Note: Purposefully excluded: 'src/codec/encoder/plus/DllEntry.cpp',
  # This file is not built by the OpenH264 original build files.
)

LIST(APPEND OPENH264_ENCODER_SOURCES_ASM_X86
			coeff.asm
			dct.asm
			intra_pred.asm
			matrix_transpose.asm
			memzero.asm
			quant.asm
			sample_sc.asm
			score.asm
)

LIST(APPEND OPENH264_ENCODER_SOURCES_ASM_ARM
  ${openh264_SOURCE_DIR}/codec/encoder/core/arm/intra_pred_neon.S
  ${openh264_SOURCE_DIR}/codec/encoder/core/arm/intra_pred_sad_3_opt_neon.S
  ${openh264_SOURCE_DIR}/codec/encoder/core/arm/memory_neon.S
  ${openh264_SOURCE_DIR}/codec/encoder/core/arm/pixel_neon.S
  ${openh264_SOURCE_DIR}/codec/encoder/core/arm/reconstruct_neon.S
  ${openh264_SOURCE_DIR}/codec/encoder/core/arm/svc_motion_estimation.S
)

LIST(APPEND OPENH264_ENCODER_SOURCES_ASM_ARM64
  ${openh264_SOURCE_DIR}/codec/encoder/core/arm64/intra_pred_aarch64_neon.S
  ${openh264_SOURCE_DIR}/codec/encoder/core/arm64/intra_pred_sad_3_opt_aarch64_neon.S
  ${openh264_SOURCE_DIR}/codec/encoder/core/arm64/memory_aarch64_neon.S
  ${openh264_SOURCE_DIR}/codec/encoder/core/arm64/pixel_aarch64_neon.S
  ${openh264_SOURCE_DIR}/codec/encoder/core/arm64/reconstruct_aarch64_neon.S
  ${openh264_SOURCE_DIR}/codec/encoder/core/arm64/svc_motion_estimation_aarch64_neon.S
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

	FOREACH(ASM ${OPENH264_ENCODER_SOURCES_ASM_X86})
		SET(ASM_SRC ${openh264_SOURCE_DIR}/codec/encoder/core/x86/${ASM})
		LIST(APPEND OPENH264_ENCODER_ASM_SOURCES ${ASM_SRC})
		LIST(APPEND OPENH264_ENCODER_ASM_OBJS ${ASM}.obj)
		ADD_CUSTOM_COMMAND(
			OUTPUT ${ASM}.obj
			COMMAND yasm ARGS ${YASM_FLAGS} ${ASM_SRC} -o ${ASM}.obj
			DEPENDS ${ASM_SRC})
	ENDFOREACH()
ELSEIF(CMAKE_SYSTEM_PROCESSOR STREQUAL "armv7-a")
	LIST(APPEND OPENH264_ENCODER_ASM_SOURCES ${OPENH264_ENCODER_SOURCES_ASM_ARM})
	SET(CMAKE_CXX_FLAGS "-D__UCLIBC__ -mfpu=neon -fexceptions -frtti -fpermissive ${CMAKE_CXX_FLAGS}")
	MESSAGE(${CMAKE_CXX_FLAGS})
ELSEIF(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
	LIST(APPEND OPENH264_ENCODER_ASM_SOURCES ${OPENH264_ENCODER_SOURCES_ASM_ARM64})
ENDIF()


ADD_LIBRARY(oh264_enc STATIC ${OPENH264_ENCODER_SOURCES} ${OPENH264_ENCODER_ASM_OBJS})

