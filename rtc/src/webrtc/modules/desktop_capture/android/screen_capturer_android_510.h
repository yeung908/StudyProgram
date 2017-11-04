
#ifndef WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_ANDROID_510_H_
#define WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_ANDROID_510_H_

#include "webrtc/modules/desktop_capture/desktop_capturer.h"
#include "webrtc/base/scoped_ref_ptr.h"

#include "hi_unf_common.h"
#include "hi_unf_ecs.h"
#include "hi_unf_disp.h"
#include "hi_unf_vo.h"
#include "hi_mpi_mem.h"

namespace webrtc {

class VideoFrameBuffer;

class ScreenCapturerAndroid510 : public DesktopCapturer {

  public:

     ScreenCapturerAndroid510();
     ~ScreenCapturerAndroid510() override;

     // Overridden from ScreenCapturer:
     void Start(Callback* callback) override;
     void CaptureFrame() override;

  private:
    rtc::scoped_refptr<VideoFrameBuffer> AcquireVideoFrame();
    void ReleaseVideoFrame();
    int InitDISP();
    void DeInitDISP();

  private:

    int width_;
    int height_;
    int bytesPerPix_;
    Callback* callback_ = nullptr;

    HI_HANDLE dispCast_;
    HI_UNF_VIDEO_FRAME_INFO_S videoFrameInfo_;
    bool isInitDISP_;

    RTC_DISALLOW_COPY_AND_ASSIGN(ScreenCapturerAndroid510);

};  // class ScreenCapturerAndroid510

}   // namespace webrtc

#endif  // WEBRTC_MODULES_DESKTOP_CAPTURE_ANDROID_SCREEN_CAPTURER_ANDROID_510_H_