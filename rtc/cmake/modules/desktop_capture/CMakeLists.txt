INCLUDE_DIRECTORIES(${webrtc_SOURCE_DIR}/src
					${CMAKE_SOURCE_DIR}/util/inc
					${webrtc_SOURCE_DIR}/thirdparty/libyuv/include
					${webrtc_SOURCE_DIR}/thirdparty/libvpx/source/libvpx)

LIST(APPEND DESKTOP_PRIMITIVES_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_capture_types.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_frame.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_frame.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_geometry.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_geometry.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_region.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_region.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/shared_desktop_frame.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/shared_desktop_frame.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/shared_memory.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/shared_memory.h
)

LIST(APPEND DESKTOP_RGBA_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/rgba_color.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/rgba_color.h
)

LIST(APPEND DESKTOP_SCREEN_DRAWER_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/screen_drawer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/screen_drawer.h
)

IF(CMAKE_SYSTEM_NAME MATCHES Linux)
LIST(APPEND DESKTOP_SCREEN_DRAWER_SOURCES 
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/screen_drawer_linux.cc
)
ENDIF()

IF(WIN32)
LIST(APPEND DESKTOP_SCREEN_DRAWER_SOURCES 
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/screen_drawer_win.cc
)
ENDIF(WIN32)

IF(CMAKE_SYSTEM_NAME MATCHES Darwin)
LIST(APPEND DESKTOP_SCREEN_DRAWER_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/screen_drawer_mac.cc
)
ENDIF()


LIST(APPEND DESKTOP_CAPTURE_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/cropped_desktop_frame.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/cropped_desktop_frame.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/cropping_window_capturer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/cropping_window_capturer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_and_cursor_composer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_and_cursor_composer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_capture_options.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_capture_options.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_capturer.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_capturer.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_capturer_differ_wrapper.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_capturer_differ_wrapper.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_frame_rotation.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_frame_rotation.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/differ_block.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/differ_block.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mouse_cursor.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mouse_cursor.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mouse_cursor_monitor.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/screen_capture_frame_queue.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/screen_capturer_helper.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/screen_capturer_helper.h
)


IF(WIN32)
LIST(APPEND DESKTOP_CAPTURE_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mouse_cursor_monitor_win.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/screen_capturer_win.cc 
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/window_capturer_win.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/cursor.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/cursor.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/d3d_device.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/d3d_device.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/desktop.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/desktop.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/dxgi_adapter_duplicator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/dxgi_adapter_duplicator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/dxgi_duplicator_controller.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/dxgi_duplicator_controller.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/dxgi_output_duplicator.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/dxgi_output_duplicator.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/dxgi_texture.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/dxgi_texture.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/dxgi_texture_mapping.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/dxgi_texture_mapping.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/dxgi_texture_staging.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/dxgi_texture_staging.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/scoped_gdi_object.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/scoped_thread_desktop.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/scoped_thread_desktop.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/screen_capture_utils.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/screen_capture_utils.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/screen_capturer_win_directx.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/screen_capturer_win_directx.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/screen_capturer_win_gdi.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/screen_capturer_win_gdi.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/screen_capturer_win_magnifier.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/screen_capturer_win_magnifier.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/window_capture_utils.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/win/window_capture_utils.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_frame_win.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/desktop_frame_win.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/cropping_window_capturer_win.cc
)
ENDIF(WIN32)

IF(CMAKE_SYSTEM_NAME MATCHES Darwin)
LIST(APPEND DESKTOP_CAPTURE_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/window_capturer_mac.mm
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/screen_capturer_mac.mm
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mouse_cursor_monitor_mac.mm
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mac/desktop_configuration.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mac/desktop_configuration.mm
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mac/desktop_configuration_monitor.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mac/desktop_configuration_monitor.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mac/full_screen_chrome_window_detector.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mac/full_screen_chrome_window_detector.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mac/scoped_pixel_buffer_object.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mac/scoped_pixel_buffer_object.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mac/window_list_utils.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mac/window_list_utils.h
)
ENDIF()


IF((CMAKE_SYSTEM_PROCESSOR STREQUAL "X86") OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
	OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86") OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "ia32")
	OR (CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64"))
	
	LIST(APPEND DESKTOP_CAPTURE_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/differ_vector_sse2.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/differ_vector_sse2.h
	)

	IF(NOT WIN32)
		SET(CMAKE_CFLAGS -msse2 ${CMAKE_CFLAGS})
	ENDIF(NOT WIN32)
ENDIF()

INCLUDE(FindX11)

IF(X11_FOUND)
	LIST(APPEND DESKTOP_CAPTURE_SOURCES
				${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/screen_drawer_linux.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/mouse_cursor_monitor_x11.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/screen_capturer_x11.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/window_capturer_x11.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/x11/shared_x_display.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/x11/shared_x_display.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/x11/x_error_trap.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/x11/x_error_trap.h
				${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/x11/x_server_pixel_buffer.cc
				${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/x11/x_server_pixel_buffer.h
	)
ENDIF(X11_FOUND)

IF(ANDROID)
	LIST(APPEND DESKTOP_CAPTURE_SOURCES
		${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/uwst/air2sharex.cc
		${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/uwst/air2sharex.h
		${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/uwst/cirbuf.cc
		${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/uwst/cirbuf.h
		${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/screen_capturer_uwst.cc
		${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/screen_capturer_uwst.h
	)

	IF(SCREEN_STREAM_SDK)
		LIST(APPEND DESKTOP_CAPTURE_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/screen_capturer_android_hisilicon.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/screen_capturer_android_hisilicon.cc
		)
	ELSE(SCREEN_STREAM_SDK)
		INCLUDE_DIRECTORIES(
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/mtal/include
		)
		
		LINK_DIRECTORIES(${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/mtal/lib)

		ADD_LIBRARY(libmtal STATIC IMPORTED)
		SET_PROPERTY(TARGET libmtal PROPERTY IMPORTED_LOCATION ${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/mtal/lib/libmtal.a)

		LIST(APPEND DESKTOP_CAPTURE_SOURCES
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/android_capturer_utils.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/android_capturer_utils.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/desktop_frame_android_5508.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/desktop_frame_android_5508.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/screen_capturer_android.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/screen_capturer_android.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/screen_capturer_mtal.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/screen_capturer_mtal.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/screen_capturer_android_5508.cc
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/screen_capturer_android_5508.h
			${webrtc_SOURCE_DIR}/src/webrtc/modules/desktop_capture/android/android_capturer.cc
		)
	ENDIF(SCREEN_STREAM_SDK)

ENDIF(ANDROID)

ADD_LIBRARY(rtc_desktop_capture STATIC 
				${DESKTOP_PRIMITIVES_SOURCES} 
				${DESKTOP_RGBA_SOURCES} 
				${DESKTOP_SCREEN_DRAWER_SOURCES} 
				${DESKTOP_CAPTURE_SOURCES}
)

IF(ANDROID)
	IF(NOT SCREEN_STREAM_SDK)
		TARGET_LINK_LIBRARIES(rtc_desktop_capture rtc_api libmtal)
	ENDIF(NOT SCREEN_STREAM_SDK)
ENDIF(ANDROID)

SET_TARGET_PROPERTIES(rtc_desktop_capture PROPERTIES FOLDER webrtc)
