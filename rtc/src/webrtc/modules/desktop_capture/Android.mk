LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE:= wrtc_mtal
LOCAL_SRC_FILES:= android/mtal/lib/libmtal.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/android/mtal/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := wrtc_screen_capture
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../.. 

LOCAL_SRC_FILES := cropped_desktop_frame.cc \
					desktop_and_cursor_composer.cc \
					desktop_capture_options.cc \
					desktop_capturer.cc \
					desktop_capturer_differ_wrapper.cc \
					desktop_frame.cc \
					desktop_frame_generator.cc \
					desktop_geometry.cc \
					desktop_region.cc \
					differ_block.cc \
					fake_desktop_capturer.cc \
					mouse_cursor.cc \
					mouse_cursor_monitor_null.cc \
					rgba_color.cc \
					screen_capturer_helper.cc \
					screen_capturer_null.cc \
					screen_drawer.cc \
					shared_desktop_frame.cc \
					shared_memory.cc \
					window_capturer_null.cc \
					android/screen_capture_android.cc \
					android/desktop_frame_android_5508.cc \
					android/screen_capture_mtal.cc \
					android/screen_capturer_android_5508.cc \
					android/screen_capturer_android_510.cc \
					android/uwst/air2sharex.cc \
					android/uwst/cirbuf.cc 

LOCAL_STATIC_LIBRARIES :=  	wrtc_mtal \

include $(BUILD_STATIC_LIBRARY)
