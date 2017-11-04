#include "webrtc/modules/desktop_capture/android/screen_capturer_android_5508.h"
#include "webrtc/modules/desktop_capture/android/android_capturer_utils.h"
#include "webrtc/modules/desktop_capture/android/desktop_frame_android_5508.h"
#include "webrtc/api/video/i420_buffer.h"
#include "webrtc/api/video/video_frame.h"
#include "RtcLoggerWrapper.h"
#include <assert.h>

namespace webrtc {

ScreenCapturerAndroid5508::ScreenCapturerAndroid5508()
 : callback_(nullptr) {

    AndroidScreenUtils::GetScreenInfo(&width_, &height_, &bytesPerPix_);
    screen_capture_mtal_ = new ScreenCaptureMtal(width_, height_, bytesPerPix_);
}

ScreenCapturerAndroid5508::~ScreenCapturerAndroid5508() {
    
    delete screen_capture_mtal_;
    screen_capture_mtal_ = nullptr;
}

void ScreenCapturerAndroid5508::Start(Callback* callback) {
    assert(!callback_);
    assert(callback);

    callback_ = callback;
}

void ScreenCapturerAndroid5508::CaptureFrame() {

    assert(callback_);

    uint8_t *pRGBFrame = nullptr;
    int iRGBFrameSize = 0;
    int iRet = screen_capture_mtal_->ScreenShot(&pRGBFrame, &iRGBFrameSize);

    if ( iRet != 0  ) {
        LOG(LS_ERROR) << "Screen shot error: " << iRet << " try reset libmatl.";
        screen_capture_mtal_->reInit();
        callback_->OnCaptureResult(Result::ERROR_TEMPORARY, nullptr);
        return;
    }

    if ( iRGBFrameSize != (width_ * height_ * bytesPerPix_) ) {
      LOG(LS_ERROR) << "Unsupported screen image depth: " << DesktopFrame::kBytesPerPixel;
      callback_->OnCaptureResult(Result::ERROR_PERMANENT, nullptr);
      return;
    }

    std::unique_ptr<DesktopFrame> frame(
      new DesktopFrameAndroid5508(DesktopSize(width_, height_), pRGBFrame));

    callback_->OnCaptureResult(Result::SUCCESS, std::move(frame));
}

}   // namespace webrtc
