LIST(APPEND CELT_SOURCES
	${Opus_SOURCE_DIR}/celt/bands.c 
	${Opus_SOURCE_DIR}/celt/celt.c 
	${Opus_SOURCE_DIR}/celt/celt_encoder.c 
	${Opus_SOURCE_DIR}/celt/celt_decoder.c 
	${Opus_SOURCE_DIR}/celt/cwrs.c 
	${Opus_SOURCE_DIR}/celt/entcode.c 
	${Opus_SOURCE_DIR}/celt/entdec.c 
	${Opus_SOURCE_DIR}/celt/entenc.c 
	${Opus_SOURCE_DIR}/celt/kiss_fft.c 
	${Opus_SOURCE_DIR}/celt/laplace.c 
	${Opus_SOURCE_DIR}/celt/mathops.c 
	${Opus_SOURCE_DIR}/celt/mdct.c 
	${Opus_SOURCE_DIR}/celt/modes.c 
	${Opus_SOURCE_DIR}/celt/pitch.c 
	${Opus_SOURCE_DIR}/celt/celt_lpc.c 
	${Opus_SOURCE_DIR}/celt/quant_bands.c 
	${Opus_SOURCE_DIR}/celt/rate.c 
	${Opus_SOURCE_DIR}/celt/vq.c
)

LIST(APPEND CELT_SOURCES_SSE
	${Opus_SOURCE_DIR}/celt/x86/x86cpu.c 
	${Opus_SOURCE_DIR}/celt/x86/x86_celt_map.c 
	${Opus_SOURCE_DIR}/celt/x86/pitch_sse.c
)

LIST(APPEND CELT_SOURCES_SSE2 ${Opus_SOURCE_DIR}/celt/x86/pitch_sse2.c)

LIST(APPEND CELT_SOURCES_SSE4_1
	${Opus_SOURCE_DIR}/celt/x86/celt_lpc_sse.c 
	${Opus_SOURCE_DIR}/celt/x86/pitch_sse4_1.c
)

LIST(APPEND CELT_SOURCES_ARM
	${Opus_SOURCE_DIR}/celt/arm/armcpu.c 
	${Opus_SOURCE_DIR}/celt/arm/arm_celt_map.c
)

LIST(APPEND CELT_SOURCES_ARM_ASM  ${Opus_SOURCE_DIR}/celt/arm/celt_pitch_xcorr_arm-gnu.S)

LIST(APPEND CELT_AM_SOURCES_ARM_ASM ${Opus_SOURCE_DIR}/celt/arm/armopts.s.in)

LIST(APPEND CELT_SOURCES_ARM_NEON_INTR ${Opus_SOURCE_DIR}/celt/arm/celt_neon_intr.c)

LIST(APPEND CELT_SOURCES_ARM_NE10
	${Opus_SOURCE_DIR}/celt/arm/celt_ne10_fft.c 
	${Opus_SOURCE_DIR}/celt/arm/celt_ne10_mdct.c
)