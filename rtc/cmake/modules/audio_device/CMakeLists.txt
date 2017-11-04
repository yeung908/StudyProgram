INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/include
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/dummy
					${webrtc_SOURCE_DIR}/src/webrtc/modules/include
)


LIST(APPEND RTC_AUDIO_DEVICE_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/audio_device_buffer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/audio_device_buffer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/audio_device_config.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/audio_device_generic.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/audio_device_generic.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/dummy/audio_device_dummy.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/dummy/audio_device_dummy.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/dummy/file_audio_device.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/dummy/file_audio_device.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/fine_audio_buffer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/fine_audio_buffer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/include/audio_device.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/include/audio_device_defines.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/audio_device_impl.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/audio_device_impl.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/dummy/file_audio_device_factory.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/dummy/file_audio_device_factory.h
)

IF(WIN32)
	INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/win)
	LIST(APPEND RTC_AUDIO_DEVICE_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/win/audio_device_core_win.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/win/audio_device_core_win.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/win/audio_device_wave_win.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/win/audio_device_wave_win.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/win/audio_mixer_manager_win.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/win/audio_mixer_manager_win.h
	)
ENDIF(WIN32)

IF(${CMAKE_SYSTEM_NAME} MATCHES Linux)
	INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux)
	LIST(APPEND RTC_AUDIO_DEVICE_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/alsasymboltable_linux.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/alsasymboltable_linux.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/audio_device_alsa_linux.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/audio_device_alsa_linux.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/audio_mixer_manager_alsa_linux.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/audio_mixer_manager_alsa_linux.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/latebindingsymboltable_linux.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/latebindingsymboltable_linux.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/audio_device_pulse_linux.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/audio_device_pulse_linux.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/audio_mixer_manager_pulse_linux.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/audio_mixer_manager_pulse_linux.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/pulseaudiosymboltable_linux.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/linux/pulseaudiosymboltable_linux.h
	)
	
	ADD_DEFINITIONS(-DLINUX_ALSA _DLINUX_PULSE)
ENDIF()

IF(ANDROID)
	INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android)
	
	LIST(APPEND RTC_AUDIO_DEVICE_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/audio_device_template.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/audio_manager.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/audio_manager.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/audio_record_jni.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/audio_record_jni.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/audio_track_jni.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/audio_track_jni.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/build_info.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/build_info.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/opensles_common.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/opensles_common.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/opensles_player.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/opensles_player.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/opensles_recorder.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/android/opensles_recorder.h
	)
ENDIF(ANDROID)

IF(APPLE)
	IF(WEBRTC_BUILD_IOS)
		INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios)
		
		LIST(APPEND RTC_AUDIO_DEVICE_SOURCES
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/audio_device_ios.h
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/audio_device_ios.mm
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/audio_device_not_implemented_ios.mm
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/audio_session_observer.h
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/objc/RTCAudioSession+Configuration.mm
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/objc/RTCAudioSession+Private.h
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/objc/RTCAudioSession.h
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/objc/RTCAudioSession.mm
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/objc/RTCAudioSessionConfiguration.h
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/objc/RTCAudioSessionConfiguration.m
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/objc/RTCAudioSessionDelegateAdapter.h
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/objc/RTCAudioSessionDelegateAdapter.mm
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/voice_processing_audio_unit.h
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/ios/voice_processing_audio_unit.mm
		)
	ELSE(WEBRTC_BUILD_IOS)
	SET(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -Wno-thread-safety-analysis)
		INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/mac)
		LIST(APPEND RTC_AUDIO_DEVICE_SOURCES
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/mac/audio_device_mac.cc
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/mac/audio_device_mac.h
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/mac/audio_mixer_manager_mac.cc
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/mac/audio_mixer_manager_mac.h
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/mac/portaudio/pa_memorybarrier.h
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/mac/portaudio/pa_ringbuffer.c
					${webrtc_SOURCE_DIR}/src/webrtc/modules/audio_device/mac/portaudio/pa_ringbuffer.h
		)
	ENDIF(WEBRTC_BUILD_IOS)
ENDIF(APPLE)

ADD_LIBRARY(rtc_audio_device STATIC ${RTC_AUDIO_DEVICE_SOURCES})
SET_TARGET_PROPERTIES(rtc_audio_device PROPERTIES FOLDER "webrtc")