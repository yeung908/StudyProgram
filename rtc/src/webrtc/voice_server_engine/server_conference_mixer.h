#ifndef WEBRTC_VOICE_SERVER_ENGINE_SERVER_CONFERENCE_MIXER_H
#define WEBRTC_VOICE_SERVER_ENGINE_SERVER_CONFERENCE_MIXER_H

#include <set>
#include "webrtc/modules/audio_conference_mixer/include/audio_conference_mixer_defines.h"
#include "webrtc/modules/audio_conference_mixer/include/audio_conference_mixer.h"
#include "webrtc/voice_server_engine/channel_manager.h"
#include "webrtc/modules/utility/include/process_thread.h"

namespace webrtc
{
    namespace vose
    {
        class ServerConferenceMixer : public AudioMixerOutputReceiver
        {
        public:
            virtual ~ServerConferenceMixer();
            int32_t AddChannel(int32_t channelId);
            int32_t RemoveChannel(int32_t channelId);
            inline int32_t MixerId() const { return mixerId_; }
        protected:
            friend class MixerManager;
            ServerConferenceMixer(int32_t mixerId, uint32_t instanceId, 
                ChannelManager &channelMangager, ProcessThread *thread);

            virtual void NewMixedAudio(const int32_t id, const AudioFrame& generalAudioFrame, const AudioFrame** uniqueAudioFrames, const uint32_t size) override;
        protected:
            AudioConferenceMixer *mixerModule_;
            std::set<int32_t> channels_;
            int32_t activeChannels_[AudioConferenceMixer::kMaximumAmountOfMixedParticipants];
            ChannelManager &channelManager_;
            int32_t mixerId_;
            rtc::CriticalSection cs_;
            ProcessThread *thread_;
        };
    }
}

#endif //WEBRTC_VOICE_SERVER_ENGINE_SERVER_CONFERENCE_MIXER_H