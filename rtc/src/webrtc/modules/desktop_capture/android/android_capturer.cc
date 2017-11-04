#include "webrtc/modules/desktop_capture/android/screen_capturer_android.h"
#include "webrtc/modules/desktop_capture/android/screen_capturer_android_5508.h"
#include "webrtc/modules/desktop_capture/desktop_capture_options.h"

namespace webrtc {

std::unique_ptr<DesktopCapturer> DesktopCapturer::CreateRawWindowCapturer(
      const DesktopCaptureOptions& options) {
    return nullptr;
}

std::unique_ptr<DesktopCapturer> DesktopCapturer::CreateRawScreenCapturer(
    const DesktopCaptureOptions& options) {
  if ( options.capturePlatform() == DesktopCaptureOptions::CapturePlatform::Android_5508 ) {
     std::unique_ptr<DesktopCapturer> capturer(new ScreenCapturerAndroid5508());
     return std::move(capturer);
  } else {
     std::unique_ptr<DesktopCapturer> capturer(new ScreenCapturerAndroid());
     return std::move(capturer);
  }
}

}