
#include "webrtc/base/refcount.h"
#include "webrtc/base/scoped_ref_ptr.h"
#include "webrtc/modules/video_capture/android/video_capture_android.h"

namespace webrtc {
    namespace videocapturemodule {

// static
        VideoCaptureModule::DeviceInfo* VideoCaptureImpl::CreateDeviceInfo() {
            // TODO(tommi): Use the Media Foundation version on Vista and up.
            return DeviceInfoAndroid::Create();
    }

        rtc::scoped_refptr<VideoCaptureModule> VideoCaptureImpl::Create(
                const char* device_id) {
            if (device_id == nullptr)
                return nullptr;

            // TODO(tommi): Use Media Foundation implementation for Vista and up.
            rtc::scoped_refptr<VideoCaptureAndroid> capture(
                    new rtc::RefCountedObject<VideoCaptureAndroid>());
            if (capture->Init(device_id) != 0) {
                return nullptr;
            }

            return capture;
        }

    }  // namespace videocapturemodule
}  // namespace webrtc