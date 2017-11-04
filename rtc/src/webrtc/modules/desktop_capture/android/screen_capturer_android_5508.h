
#ifndef WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_ANDROID_5508_H_
#define WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_ANDROID_5508_H_

#include "webrtc/modules/desktop_capture/desktop_capturer.h"
#include "webrtc/modules/desktop_capture/android/screen_capturer_mtal.h"

namespace webrtc {

class ScreenCapturerAndroid5508 : public DesktopCapturer {

  public:

     ScreenCapturerAndroid5508();
     ~ScreenCapturerAndroid5508() override;

     // Overridden from ScreenCapturer:
     void Start(Callback* callback) override;
     void CaptureFrame() override;

  private:

    int width_;
    int height_;
    int bytesPerPix_;
    Callback* callback_ = nullptr;
    ScreenCaptureMtal *screen_capture_mtal_ = nullptr;

    RTC_DISALLOW_COPY_AND_ASSIGN(ScreenCapturerAndroid5508);

};  // class ScreenCapturerAndroid5508

}   // namespace webrtc

#endif  // WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_ANDROID_5508_H_
