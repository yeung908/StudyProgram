LIST(APPEND  OPUS_SOURCES 
	${Opus_SOURCE_DIR}/src/opus.c 
	${Opus_SOURCE_DIR}/src/opus_decoder.c 
	${Opus_SOURCE_DIR}/src/opus_encoder.c 
	${Opus_SOURCE_DIR}/src/opus_multistream.c 
	${Opus_SOURCE_DIR}/src/opus_multistream_encoder.c 
	${Opus_SOURCE_DIR}/src/opus_multistream_decoder.c 
	${Opus_SOURCE_DIR}/src/repacketizer.c
)

LIST(APPEND  OPUS_SOURCES_FLOAT
	${Opus_SOURCE_DIR}/src/analysis.c 
	${Opus_SOURCE_DIR}/src/mlp.c 
	${Opus_SOURCE_DIR}/src/mlp_data.c
)
