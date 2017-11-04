#include "webrtc/modules/desktop_capture/android/screen_capturer_android_hisilicon.h"
#include "webrtc/api/video/i420_buffer.h"
#include "webrtc/api/video/video_frame.h"
#include "webrtc/base/timeutils.h"
#include "webrtc/base/logging.h"
#include <assert.h>

#define CAPTURE_FPS     11

namespace webrtc {

ScreenCapturerAndroidDisp::ScreenCapturerAndroidDisp() {
    last_capture_time_ = 0;
}

ScreenCapturerAndroidDisp::~ScreenCapturerAndroidDisp() {

}

void ScreenCapturerAndroidDisp::Start(Callback* callback) {
    assert(!callback_);
    assert(callback);
    callback_ = callback;
}

void ScreenCapturerAndroidDisp::CaptureFrame() {
    int64_t cur_time = rtc::TimeUTCMicros();
    int64_t interval = cur_time - last_capture_time_;

    if ( interval < 1000 * 1000 / CAPTURE_FPS ) {
        return;
    }

    last_capture_time_ = cur_time;
    std::unique_ptr<webrtc::VideoFrame> nullFrame(
        new webrtc::VideoFrame(I420Buffer::Create(1280, 720),
            webrtc::kVideoRotation_0, last_capture_time_));
    callback_->OnCaptureVideoFrame(Result::SUCCESS, std::move(nullFrame));
}

std::unique_ptr<DesktopCapturer> DesktopCapturer::CreateRawWindowCapturer(
      const DesktopCaptureOptions& options) {
    return nullptr;
}

std::unique_ptr<DesktopCapturer> DesktopCapturer::CreateRawScreenCapturer(
    const DesktopCaptureOptions& options) {
    std::unique_ptr<DesktopCapturer> capturer(new ScreenCapturerAndroidDisp());
    return std::move(capturer);
}

}