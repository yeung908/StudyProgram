#include "webrtc/modules/audio_conference_mixer/include/audio_conference_mixer.h"
#include "webrtc/modules/audio_conference_mixer/include/audio_conference_mixer_multistream_expandation.h"
#include "webrtc/media/engine/webrtcvoiceengine.h"
#include "webrtc/media/engine/webrtcvideoengine2.h"
#include "webrtc/media/engine/webrtcmediaengine.h"
#include "webrtc/system_wrappers/include/field_trial_default.h"


using namespace webrtc;
using namespace cricket;


int main(int argc, char **argv)
{
    webrtc::field_trial::InitFieldTrialsFromString("WebRTC-FlexFEC-03/Enabled/");
    MediaEngineInterface *engine_ = WebRtcMediaEngineFactory::Create(nullptr, nullptr, nullptr);
    engine_->Init();

    char cmd;
    while (true) {
        cmd = getchar();
    }
    return 0;
}
