#include "webrtc/voice_server_engine/server_conference_mixer.h"
#include "webrtc/voice_server_engine/channel.h"
#include "webrtc/modules/audio_conference_mixer/include/audio_conference_mixer_multistream_expandation.h"
#include "webrtc/system_wrappers/include/trace.h"

//Attention: Should not push mixerModule_ in CriticalSection(cs_). 

webrtc::vose::ServerConferenceMixer::~ServerConferenceMixer()
{
    thread_->DeRegisterModule(mixerModule_);

    std::set<int32_t> channels = channels_;
    for (auto it = channels.begin(); it != channels.end(); ++it) {
        channelManager_.GetChannel(*it).channel()->RemoveFromServerConferenceMixer();
    }
}

webrtc::vose::ServerConferenceMixer::ServerConferenceMixer(
    int32_t mixerId, uint32_t instanceId,
    ChannelManager &channelMangager, ProcessThread *thread)
    :channelManager_(channelMangager),mixerId_(mixerId), thread_(thread)
{
    mixerModule_ = AudioConferenceMixerMultiStreamExpandation::Create(mixerId_);
    mixerModule_->RegisterMixedStreamCallback(this);
    thread_->RegisterModule(mixerModule_);
}

void webrtc::vose::ServerConferenceMixer::NewMixedAudio(const int32_t id, const AudioFrame& generalAudioFrame, const AudioFrame** uniqueAudioFrames, const uint32_t size)
{
    rtc::CritScope crit(&cs_);
    Channel *channel(NULL);
    std::set<int32_t> channels = channels_;
    for (auto i = 0; i < size; i++) {
        channels.erase(uniqueAudioFrames[i]->id_);
        channel = channelManager_.GetChannel(uniqueAudioFrames[i]->id_).channel();
        if (channel) {
            channel->Demultiplex(*(uniqueAudioFrames[i]));
            channel->PrepareEncodeAndSend(uniqueAudioFrames[i]->sample_rate_hz_);
            channel->EncodeAndSend();
        }
    }

    for (auto it = channels.begin(); it != channels.end(); it++) {
        channel = channelManager_.GetChannel(*it).channel();
        if (channel) {
            channel->Demultiplex(generalAudioFrame);
            channel->PrepareEncodeAndSend(generalAudioFrame.sample_rate_hz_);
            channel->EncodeAndSend();
        }
    }
}

int32_t webrtc::vose::ServerConferenceMixer::AddChannel(int32_t channelId)
{
    int32_t ret = -1;
    ChannelOwner chn =  channelManager_.GetChannel(channelId);
    if (chn.channel()) {
        mixerModule_->SetMixabilityStatus(chn.channel(), true);
        
        rtc::CritScope crit(&cs_);
        channels_.insert(channelId);
        WEBRTC_TRACE(kTraceInfo, kTraceAudioMixerServer, mixerId_,
            "AddChannel %d ,point:%p", channelId, dynamic_cast<MixerParticipant*>(chn.channel()));
        ret = 0;
    }
    else
    {
        WEBRTC_TRACE(kTraceInfo, kTraceAudioMixerServer, mixerId_,
            "AddChannel %d Fail,Can't Find Channel", channelId);
    }
    
    return ret;
}

int32_t webrtc::vose::ServerConferenceMixer::RemoveChannel(int32_t channelId)
{
    int32_t ret = -1;
    {
        ChannelOwner chn = channelManager_.GetChannel(channelId);
        if (chn.channel()) {
            mixerModule_->SetMixabilityStatus(chn.channel(), false);
        }

        
        rtc::CritScope cs(&cs_);
        for (auto it = channels_.begin(); it != channels_.end(); ++it) {
            if (*it == channelId) {
                channels_.erase(it);
                WEBRTC_TRACE(kTraceInfo, kTraceAudioMixerServer, mixerId_,
                    "RemoveChannel %d , %p Success", channelId, dynamic_cast<MixerParticipant*>(chn.channel()));
                ret = 0;
                break;
            }
        }
    }

    return ret;
}
