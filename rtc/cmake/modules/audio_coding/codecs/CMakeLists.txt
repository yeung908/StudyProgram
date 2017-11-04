INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/cng/include
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/red
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g711/include
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g722/include
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/include
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/include
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/include
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/pcm16b/include
					${webrtc_SOURCE_DIR}/thirdparty/Opus/include					
					)


ADD_DEFINITIONS(-DWEBRTC_CODEC_ILBC
				-DWEBRTC_CODEC_OPUS
				-DWEBRTC_OPUS_SUPPORT_120MS_PTIME=0
				-DWEBRTC_CODEC_ISAC
				-DWEBRTC_CODEC_G722
				-DWEBRTC_OPUS_VARIABLE_COMPLEXITY=1)

LIST(APPEND RTC_AUDIO_CODECS_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/audio_format.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/audio_format.h
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/audio_format_conversion.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/audio_format_conversion.h
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/audio_decoder_factory.h
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/builtin_audio_decoder_factory.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/builtin_audio_decoder_factory.h
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/audio_decoder.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/audio_decoder.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/legacy_encoded_audio_frame.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/legacy_encoded_audio_frame.h
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/audio_encoder.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/audio_encoder.h
)

LIST(APPEND CNG_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/cng/audio_encoder_cng.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/cng/audio_encoder_cng.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/cng/webrtc_cng.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/cng/webrtc_cng.h
)

LIST(APPEND RED_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/red/audio_encoder_copy_red.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/red/audio_encoder_copy_red.h
)

LIST(APPEND G711_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g711/audio_decoder_pcm.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g711/audio_decoder_pcm.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g711/audio_encoder_pcm.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g711/audio_encoder_pcm.h
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g711/g711.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g711/g711.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g711/g711_interface.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g711/g711_interface.h
)

LIST(APPEND G722_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g722/audio_decoder_g722.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g722/audio_decoder_g722.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g722/audio_encoder_g722.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g722/audio_encoder_g722.h
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g722/g722_decode.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g722/g722_enc_dec.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g722/g722_encode.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g722/g722_interface.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/g722/g722_interface.h
)

LIST(APPEND ILBC_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/audio_decoder_ilbc.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/audio_decoder_ilbc.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/audio_encoder_ilbc.cc
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/audio_encoder_ilbc.h
	${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/abs_quant.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/abs_quant.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/abs_quant_loop.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/abs_quant_loop.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/augmented_cb_corr.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/augmented_cb_corr.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/bw_expand.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/bw_expand.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_construct.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_construct.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_mem_energy.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_mem_energy.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_mem_energy_augmentation.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_mem_energy_augmentation.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_mem_energy_calc.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_mem_energy_calc.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_search.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_search.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_search_core.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_search_core.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_update_best_index.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/cb_update_best_index.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/chebyshev.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/chebyshev.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/comp_corr.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/comp_corr.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/constants.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/constants.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/create_augmented_vec.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/create_augmented_vec.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/decode.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/decode.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/decode_residual.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/decode_residual.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/decoder_interpolate_lsf.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/decoder_interpolate_lsf.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/defines.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/do_plc.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/do_plc.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/encode.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/encode.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/energy_inverse.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/energy_inverse.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/enh_upsample.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/enh_upsample.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/enhancer.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/enhancer.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/enhancer_interface.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/enhancer_interface.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/filtered_cb_vecs.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/filtered_cb_vecs.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/frame_classify.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/frame_classify.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/gain_dequant.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/gain_dequant.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/gain_quant.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/gain_quant.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/get_cd_vec.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/get_cd_vec.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/get_lsp_poly.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/get_lsp_poly.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/get_sync_seq.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/get_sync_seq.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/hp_input.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/hp_input.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/hp_output.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/hp_output.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/ilbc.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/ilbc.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/index_conv_dec.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/index_conv_dec.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/index_conv_enc.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/index_conv_enc.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/init_decode.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/init_decode.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/init_encode.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/init_encode.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/interpolate.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/interpolate.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/interpolate_samples.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/interpolate_samples.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lpc_encode.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lpc_encode.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lsf_check.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lsf_check.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lsf_interpolate_to_poly_dec.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lsf_interpolate_to_poly_dec.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lsf_interpolate_to_poly_enc.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lsf_interpolate_to_poly_enc.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lsf_to_lsp.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lsf_to_lsp.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lsf_to_poly.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lsf_to_poly.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lsp_to_lsf.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/lsp_to_lsf.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/my_corr.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/my_corr.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/nearest_neighbor.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/nearest_neighbor.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/pack_bits.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/pack_bits.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/poly_to_lsf.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/poly_to_lsf.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/poly_to_lsp.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/poly_to_lsp.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/refiner.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/refiner.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/simple_interpolate_lsf.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/simple_interpolate_lsf.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/simple_lpc_analysis.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/simple_lpc_analysis.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/simple_lsf_dequant.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/simple_lsf_dequant.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/simple_lsf_quant.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/simple_lsf_quant.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/smooth.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/smooth.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/smooth_out_data.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/smooth_out_data.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/sort_sq.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/sort_sq.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/split_vq.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/split_vq.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/state_construct.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/state_construct.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/state_search.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/state_search.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/swap_bytes.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/swap_bytes.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/unpack_bits.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/unpack_bits.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/vq3.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/vq3.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/vq4.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/vq4.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/window32_w32.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/window32_w32.h
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/xcorr_coef.c
    ${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/ilbc/xcorr_coef.h
)

LIST(APPEND ISAC_COMMON_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/audio_encoder_isac_t.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/audio_encoder_isac_t_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/locked_bandwidth_info.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/locked_bandwidth_info.h
)

LIST(APPEND ISAC_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/include/audio_decoder_isac.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/include/audio_encoder_isac.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/audio_decoder_isac.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/audio_encoder_isac.cc
)

LIST(APPEND ISAC_C_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/include/isac.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/arith_routines.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/arith_routines.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/arith_routines_hist.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/arith_routines_logist.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/bandwidth_estimator.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/bandwidth_estimator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/codec.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/crc.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/crc.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/decode.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/decode_bwe.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/encode.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/encode_lpc_swb.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/encode_lpc_swb.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/entropy_coding.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/entropy_coding.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/fft.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/fft.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/filter_functions.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/filterbank_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/filterbank_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/filterbanks.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/intialize.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/isac.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/isac_float_type.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/lattice.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_analysis.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_analysis.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_gain_swb_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_gain_swb_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_shape_swb12_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_shape_swb12_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_shape_swb16_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_shape_swb16_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/os_specific_inline.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_estimator.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_estimator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_filter.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_gain_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_gain_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_lag_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_lag_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/settings.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/spectrum_ar_model_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/spectrum_ar_model_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/structs.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/main/source/transform.c
)

LIST(APPEND ISAC_FIX_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/audio_decoder_isacfix.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/audio_encoder_isacfix.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/codec.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/fft.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/fft.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/settings.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/include/audio_decoder_isacfix.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/include/audio_encoder_isacfix.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/include/isacfix.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/arith_routines.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/arith_routines_hist.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/arith_routines_logist.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/arith_routins.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/bandwidth_estimator.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/bandwidth_estimator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/decode.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/decode_bwe.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/decode_plc.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/encode.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/entropy_coding.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/entropy_coding.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/filterbank_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/filterbank_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/filterbanks.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/filters.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/initialize.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/isac_fix_type.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/isacfix.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/lattice.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/lattice_c.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/lpc_masking_model.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/lpc_masking_model.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/lpc_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/lpc_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_estimator.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_estimator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_estimator_c.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_filter.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_filter_c.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_gain_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_gain_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_lag_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_lag_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/spectrum_ar_model_tables.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/spectrum_ar_model_tables.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/structs.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/transform.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/transform_tables.c
)

IF(${CMAKE_SYSTEM_NAME} EQUAL "armv7a" OR ${CMAKE_SYSTEM_NAME} EQUAL arm64)
LIST(APPEND ISAC_FIX_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/lattice_armv7.S
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_filter_armv6.S
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/entropy_coding_neon.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/filterbanks_neon.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/filters_neon.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/lattice_neon.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/transform_neon.c
)
LIST(EXCLUDE ISAC_COMMON_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/lattice_c.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_filter_c.c
)

SET(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -mfpu=neon)
ENDIF()


LIST(APPEND PCM16B_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/pcm16b/audio_decoder_pcm16b.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/pcm16b/audio_decoder_pcm16b.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/pcm16b/audio_encoder_pcm16b.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/pcm16b/audio_encoder_pcm16b.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/pcm16b/pcm16b.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/pcm16b/pcm16b.h
)

LIST(APPEND OPUS_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/opus/audio_decoder_opus.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/opus/audio_decoder_opus.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/opus/audio_encoder_opus.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/opus/audio_encoder_opus.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/opus/opus_inst.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/opus/opus_interface.c
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_coding/codecs/opus/opus_interface.h
)


SOURCE_GROUP(G711 FILES ${G711_SOURCES})
SOURCE_GROUP(G722 FILES ${G722_SOURCES})
SOURCE_GROUP(L16 FILES ${PCM16B_SOURCES})
SOURCE_GROUP(opus FILES ${OPUS_SOURCES})
SOURCE_GROUP(ISAC FILES ${ISAC_COMMON_SOURCES} ${ISAC_C_SOURCES} ${ISAC_FIX_SOURCES} ${ISAC_SOURCES})
SOURCE_GROUP(ILBC FILES ${ILBC_SOURCES})
SOURCE_GROUP(RED FILES ${RED_SOURCES})
SOURCE_GROUP(CNG FILES ${CNG_SOURCES})

LIST(APPEND RTC_AUDIO_CODECS_ALL_SOURCES
			${RTC_AUDIO_CODECS_SOURCES}
			${G711_SOURCES} 
			${G722_SOURCES} 
			${PCM16B_SOURCES} 
			${OPUS_SOURCES} 
			${ISAC_COMMON_SOURCES} 
			${ISAC_C_SOURCES} 
			${ISAC_FIX_SOURCES} 
			${ISAC_SOURCES}
			${ILBC_SOURCES}
			${RED_SOURCES}
			${CNG_SOURCES}
)

ADD_LIBRARY(rtc_audio_codecs STATIC ${RTC_AUDIO_CODECS_ALL_SOURCES})
SET_TARGET_PROPERTIES(rtc_audio_codecs PROPERTIES FOLDER "webrtc")