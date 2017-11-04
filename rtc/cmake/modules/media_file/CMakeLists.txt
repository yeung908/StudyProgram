INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src)

LIST(APPEND MEDIA_FILE_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/media_file/media_file.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/media_file/media_file_defines.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/media_file/media_file_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/media_file/media_file_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/media_file/media_file_utility.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/media_file/media_file_utility.h
)

ADD_LIBRARY(rtc_media_file ${MEDIA_FILE_SOURCES})
SET_TARGET_PROPERTIES(rtc_media_file PROPERTIES FOLDER "webrtc")