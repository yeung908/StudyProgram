#ifndef WEBRTC_MODULES_AUDIO_CONFERENCE_MIXER_SOURCE_AUDIO_CONFERENCE_MIXER_MULTISTREAM_IMPL_H_
#define WEBRTC_MODULES_AUDIO_CONFERENCE_MIXER_SOURCE_AUDIO_CONFERENCE_MIXER_MULTISTREAM_IMPL_H_
#include "webrtc/modules/audio_conference_mixer/source/audio_conference_mixer_impl.h"

namespace webrtc
{
    class AudioConferenceMixerMultiStreamImpl : public AudioConferenceMixerImpl
    {
    public:
        AudioConferenceMixerMultiStreamImpl(int32_t id);
        void Process() override;
    protected:
        void MixStream(AudioFrame *mixedAudio, const AudioFrameList &mixList,
                const AudioFrameList &additionalFramesList, const AudioFrameList &rampOutList);
    };
}
#endif  //WEBRTC_MODULES_AUDIO_CONFERENCE_MIXER_SOURCE_AUDIO_CONFERENCE_MIXER_MULTISTREAM_IMPL_H_