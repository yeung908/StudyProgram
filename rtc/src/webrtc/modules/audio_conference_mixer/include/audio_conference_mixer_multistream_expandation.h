#ifndef WEBRTC_MODULES_AUDIO_CONFERENCE_MIXER_INCLUDE_AUDIO_CONFERENCE_MIXER_MULTISTREAM_EXPANDATION_H_
#define WEBRTC_MODULES_AUDIO_CONFERENCE_MIXER_INCLUDE_AUDIO_CONFERENCE_MIXER_MULTISTREAM_EXPANDATION_H_
#include "webrtc/modules/audio_conference_mixer/include/audio_conference_mixer.h"

namespace webrtc
{
    class AudioConferenceMixerMultiStreamExpandation
    {
    public:
        static AudioConferenceMixer* Create(int id);
    };
}

#endif // WEBRTC_MODULES_AUDIO_CONFERENCE_MIXER_INCLUDE_AUDIO_CONFERENCE_MIXER_MULTISTREAM_EXPANDATION_H_