#ifndef WEBRTC_MODULES_DESKTOP_CAPTURE_DESKTOP_FRAME_ANDROID_5508_H_
#define WEBRTC_MODULES_DESKTOP_CAPTURE_DESKTOP_FRAME_ANDROID_5508_H_

#include "webrtc/modules/desktop_capture/desktop_frame.h"

namespace webrtc {

class DesktopFrameAndroid5508 : public DesktopFrame {
    public:
      DesktopFrameAndroid5508(DesktopSize size, uint8_t* data);
      ~DesktopFrameAndroid5508() override;

    private:
      RTC_DISALLOW_COPY_AND_ASSIGN(DesktopFrameAndroid5508);
};

} // namespace webrtc

#endif // WEBRTC_MODULES_DESKTOP_CAPTURE_DESKTOP_FRAME_ANDROID_5508_H_
