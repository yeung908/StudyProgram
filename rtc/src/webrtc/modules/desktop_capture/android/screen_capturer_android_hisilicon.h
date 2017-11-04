#ifndef WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_ANDROID_510_DISP_H_
#define WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_ANDROID_510_DISP_H_

#include "webrtc/modules/desktop_capture/desktop_capturer.h"

namespace webrtc {

class ScreenCapturerAndroidDisp : public DesktopCapturer {

  public:
     ScreenCapturerAndroidDisp();
     ~ScreenCapturerAndroidDisp() override;

     // Overridden from ScreenCapturer:
     void Start(Callback* callback) override;
     void CaptureFrame() override;

  private:
    Callback* callback_ = nullptr;
    RTC_DISALLOW_COPY_AND_ASSIGN(ScreenCapturerAndroidDisp);
    int64_t last_capture_time_;

};  // class ScreenCapturerAndroidDisp

}   // namespace webrtc

#endif // WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_ANDROID_510_DISP_H_