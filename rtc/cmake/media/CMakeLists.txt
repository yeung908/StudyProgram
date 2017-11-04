INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}
					${webrtc_SOURCE_DIR}/src
					${webrtc_SOURCE_DIR}/thirdparty/libyuv/include)

LIST(APPEND RTC_MEDIA_BASE_SOUCES
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/adaptedvideotracksource.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/adaptedvideotracksource.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/audiosource.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/codec.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/codec.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/cryptoparams.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/device.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/fakemediaengine.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/fakenetworkinterface.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/fakertp.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/fakevideocapturer.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/fakevideorenderer.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/mediachannel.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/mediaconstants.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/mediaconstants.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/mediaengine.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/mediaengine.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/rtpdataengine.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/rtpdataengine.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/rtputils.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/rtputils.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/streamparams.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/streamparams.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/turnutils.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/turnutils.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videoadapter.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videoadapter.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videobroadcaster.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videobroadcaster.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videocapturer.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videocapturer.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videocapturerfactory.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videocommon.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videocommon.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videoframe.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videosinkinterface.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videosourcebase.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videosourcebase.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/base/videosourceinterface.h
)

LIST(APPEND RTC_MEDIA_ENGINE_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/constants.h
	# ${webrtc_SOURCE_DIR}/src/webrtc/media/engine/fakewebrtccall.cc
	# ${webrtc_SOURCE_DIR}/src/webrtc/media/engine/fakewebrtccall.h
	# ${webrtc_SOURCE_DIR}/src/webrtc/media/engine/fakewebrtcdeviceinfo.h
	# ${webrtc_SOURCE_DIR}/src/webrtc/media/engine/fakewebrtcvcmfactory.h
	# ${webrtc_SOURCE_DIR}/src/webrtc/media/engine/fakewebrtcvideocapturemodule.h
	# ${webrtc_SOURCE_DIR}/src/webrtc/media/engine/fakewebrtcvideoengine.h
	# ${webrtc_SOURCE_DIR}/src/webrtc/media/engine/fakewebrtcvoiceengine.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/internaldecoderfactory.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/internaldecoderfactory.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/internalencoderfactory.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/internalencoderfactory.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/nullwebrtcvideoengine.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/payload_type_mapper.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/payload_type_mapper.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/simulcast.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/simulcast.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/videodecodersoftwarefallbackwrapper.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/videodecodersoftwarefallbackwrapper.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/videoencodersoftwarefallbackwrapper.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/videoencodersoftwarefallbackwrapper.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtccommon.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcmediaengine.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcmediaengine.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvideocapturer.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvideocapturer.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvideocapturerfactory.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvideocapturerfactory.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvideodecoderfactory.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvideoencoderfactory.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvideoencoderfactory.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvideoengine2.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvideoengine2.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvideoframe.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvoe.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvoiceengine.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/engine/webrtcvoiceengine.h
)

LIST(APPEND RTC_MEIDA_SOURCES ${RTC_MEDIA_BASE_SOUCES} ${RTC_MEDIA_ENGINE_SOURCES}
	# ${webrtc_SOURCE_DIR}/src/webrtc/media/sctp/sctptransport.cc
	# ${webrtc_SOURCE_DIR}/src/webrtc/media/sctp/sctptransport.h
	# ${webrtc_SOURCE_DIR}/src/webrtc/media/sctp/sctptransportinternal.h
)

IF(ANDROID)
LIST(APPEND RTC_MEDIA_CODEC_SOURCES
	${webrtc_SOURCE_DIR}/src/webrtc/media/mediacodec/androidmediacodeccommon.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/mediacodec/androidmediadecoder_jni.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/mediacodec/androidmediadecoder_jni.h
	${webrtc_SOURCE_DIR}/src/webrtc/media/mediacodec/androidmediaencoder_jni.cc
	${webrtc_SOURCE_DIR}/src/webrtc/media/mediacodec/androidmediaencoder_jni.h
)

IF(SCREEN_STREAM_SDK)
	INCLUDE_DIRECTORIES(
		${webrtc_SOURCE_DIR}/thirdparty/hisilicon/include
	)

	LINK_DIRECTORIES(${webrtc_SOURCE_DIR}/thirdparty/hisilicon/lib)

	ADD_LIBRARY(libcutils SHARED IMPORTED)
	ADD_LIBRARY(libhi_common SHARED IMPORTED)
	ADD_LIBRARY(libhi_msp SHARED IMPORTED)
	ADD_LIBRARY(libhi_sample_common SHARED IMPORTED)

	SET_PROPERTY(TARGET libcutils PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/hisilicon/lib/libcutils.so)
	SET_PROPERTY(TARGET libhi_common PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/hisilicon/lib/libhi_common.so)
	SET_PROPERTY(TARGET libhi_msp PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/hisilicon/lib/libhi_msp.so)
	SET_PROPERTY(TARGET libhi_sample_common PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/thirdparty/hisilicon/lib/libhi_sample_common.so)

	LIST(APPEND RTC_MEDIA_CODEC_SOURCES
		${webrtc_SOURCE_DIR}/src/webrtc/media/mediacodec/androidencoder_hisilicon.cc
		${webrtc_SOURCE_DIR}/src/webrtc/media/mediacodec/androidencoder_hisilicon.h
	)
ENDIF(SCREEN_STREAM_SDK)

LIST(APPEND RTC_MEIDA_SOURCES ${RTC_MEDIA_CODEC_SOURCES})
ENDIF(ANDROID)

SOURCE_GROUP(base FILES ${RTC_MEDIA_BASE_SOUCES})
SOURCE_GROUP(engine FILES  ${RTC_MEDIA_ENGINE_SOURCES})

ADD_LIBRARY(rtc_media STATIC ${RTC_MEIDA_SOURCES})

IF(SCREEN_STREAM_SDK)
	TARGET_LINK_LIBRARIES(rtc_media libcutils libhi_common libhi_msp libhi_sample_common)
ENDIF(SCREEN_STREAM_SDK)

SET_TARGET_PROPERTIES(rtc_media PROPERTIES FOLDER "webrtc")