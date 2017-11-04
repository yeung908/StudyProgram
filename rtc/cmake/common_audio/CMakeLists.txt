INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND RTC_COMMON_AUDIO_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/common_audio/audio_converter.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/audio_converter.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/audio_ring_buffer.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/audio_ring_buffer.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/audio_util.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/blocker.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/blocker.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/channel_buffer.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/channel_buffer.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/fir_filter.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/fir_filter.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/fir_filter_neon.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/fir_filter_sse.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/include/audio_util.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/lapped_transform.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/lapped_transform.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/real_fourier.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/real_fourier.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/real_fourier_ooura.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/real_fourier_ooura.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/resampler/include/push_resampler.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/resampler/include/resampler.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/resampler/push_resampler.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/resampler/push_sinc_resampler.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/resampler/push_sinc_resampler.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/resampler/resampler.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/resampler/sinc_resampler.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/resampler/sinc_resampler.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/smoothing_filter.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/smoothing_filter.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/sparse_fir_filter.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/sparse_fir_filter.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/vad/include/vad.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/vad/vad.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/wav_file.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/wav_file.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/wav_header.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/wav_header.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/window_generator.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/window_generator.h
	${webrtc_SOURCE_DIR}/src/webrtc/common_audio/fft4g.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/fft4g.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/ring_buffer.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/ring_buffer.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/auto_corr_to_refl_coef.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/auto_correlation.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/complex_fft_tables.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/copy_set_operations.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/cross_correlation.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/division_operations.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/dot_product_with_scale.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/downsample_fast.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/energy.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/filter_ar.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/filter_ma_fast_q12.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/get_hanning_window.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/get_scaling_square.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/ilbc_specific_functions.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/include/real_fft.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/include/signal_processing_library.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/include/spl_inl.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/levinson_durbin.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/lpc_to_refl_coef.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/min_max_operations.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/randomization_functions.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/real_fft.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/refl_coef_to_lpc.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/resample.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/resample_48khz.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/resample_by_2.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/resample_by_2_internal.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/resample_by_2_internal.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/resample_fractional.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/spl_init.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/spl_inl.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/spl_sqrt.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/splitting_filter.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/sqrt_of_one_minus_x_squared.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/vector_scaling_operations.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/vad/include/webrtc_vad.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/vad/vad_core.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/vad/vad_core.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/vad/vad_filterbank.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/vad/vad_filterbank.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/vad/vad_gmm.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/vad/vad_gmm.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/vad/vad_sp.c
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/vad/vad_sp.h
    ${webrtc_SOURCE_DIR}/src/webrtc/common_audio/vad/webrtc_vad.c
	${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/complex_fft.c
)

MESSAGE("system_processor is " ${CMAKE_SYSTEM_PROCESSOR})


IF((CMAKE_SYSTEM_PROCESSOR STREQUAL "X86") OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
	OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86") OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "ia32")
	OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64"))

	LIST(APPEND RTC_COMMON_AUDIO_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/complex_bit_reverse.c
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/filter_ar_fast_q12.c
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/spl_sqrt_floor.c
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/fir_filter_sse.cc
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/resampler/sinc_resampler_sse.cc
	)
	
ENDIF()

IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "armv5te") 
	LIST(APPEND RTC_COMMON_AUDIO_SOURCES
					${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/complex_bit_reverse_arm.S
					${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/spl_sqrt_floor_arm.S
					${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/filter_ar_fast_q12.c
		)
ENDIF()

IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "armv7-a" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
	LIST(APPEND RTC_COMMON_AUDIO_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/complex_bit_reverse_arm.S
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/spl_sqrt_floor_arm.S
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/filter_ar_fast_q12.c
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/filter_ar_fast_q12_armv7.S
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/fir_filter_neon.cc
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/resampler/sinc_resampler_neon.cc
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/cross_correlation_neon.c
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/downsample_fast_neon.c
				${webrtc_SOURCE_DIR}/src/webrtc/common_audio/signal_processing/min_max_operations_neon.c
	)
ENDIF()

IF(WIN32)
	ADD_DEFINITIONS(/wd4334)
ENDIF(WIN32)

ADD_LIBRARY(rtc_common_audio STATIC ${RTC_COMMON_AUDIO_SOURCES})
SET_TARGET_PROPERTIES(rtc_common_audio PROPERTIES FOLDER "webrtc")