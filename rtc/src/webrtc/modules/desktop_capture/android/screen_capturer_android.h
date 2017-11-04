#ifndef WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_ANDROID_H_
#define WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_ANDROID_H_

#include "webrtc/modules/desktop_capture/desktop_capturer.h"

namespace webrtc {

class ScreenCapturerAndroid : public DesktopCapturer {

  public:

     ScreenCapturerAndroid();
     ~ScreenCapturerAndroid() override;

     // Overridden from ScreenCapturer:
     void Start(Callback* callback) override;
     void CaptureFrame() override;
  
  private:
      int Init();
      void UnInit();

  private:

    int width_ = 0;
    int height_ = 0;
    int bytesPerPix_ = 0;
    Callback* callback_ = nullptr;

    int graphics_fd_ = -1;
    size_t map_size_ = 0;
    char *graphics_framebuffer_ = nullptr;

  private:
      int ScreenShot(uint8_t *pFrame, int frameSize);

      RTC_DISALLOW_COPY_AND_ASSIGN(ScreenCapturerAndroid);

};  // class ScreenCapturerAndroid

}   // namespace webrtc

#endif // WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_ANDROID_H_
