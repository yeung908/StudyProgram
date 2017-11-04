#include "webrtc/modules/desktop_capture/android/desktop_frame_android_5508.h"

namespace webrtc {

DesktopFrameAndroid5508::DesktopFrameAndroid5508(DesktopSize size, uint8_t* data)
  : DesktopFrame(size, kBytesPerPixel * size.width(), data, NULL) {

}

DesktopFrameAndroid5508::~DesktopFrameAndroid5508() {

}

} // namespace webrtc
