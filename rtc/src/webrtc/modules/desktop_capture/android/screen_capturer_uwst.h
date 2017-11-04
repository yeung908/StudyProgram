#ifndef WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_UWST_H_
#define WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_UWST_H_

#include "webrtc/modules/desktop_capture/desktop_capturer.h"
#include "webrtc/modules/desktop_capture/android/uwst/air2sharex.h"
#include "webrtc/base/scoped_ref_ptr.h"

namespace webrtc {

class VideoFrameBuffer;

class ScreenCapturerUWST : public DesktopCapturer {

  public:

     ScreenCapturerUWST(DesktopCapturer* sourceCapturer);
     ~ScreenCapturerUWST() override;

     // Overridden from ScreenCapturer:
     void Start(Callback* callback) override;
     void CaptureFrame() override;
  
  private:
    bool IsUWST();
    rtc::scoped_refptr<VideoFrameBuffer> GetYuvFromUWST();

  private:
    Callback* callback_ = nullptr;
    DesktopCapturer *sourceCapturer_ = nullptr;
    circle_header *circle_header_ = nullptr;

  private:
    RTC_DISALLOW_COPY_AND_ASSIGN(ScreenCapturerUWST);

};  // class ScreenCapturerUWST

}   // namespce webrtc

#endif // WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_UWST_H_