/*
*  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
*
*  Use of this source code is governed by a BSD-style license
*  that can be found in the LICENSE file in the root of the source
*  tree. An additional intellectual property rights grant can be found
*  in the file PATENTS.  All contributing project authors may
*  be found in the AUTHORS file in the root of the source tree.
*/

#include "webrtc/voice_engine/voe_base_impl.h"

#include "webrtc/base/format_macros.h"
#include "webrtc/base/logging.h"
#include "webrtc/common_audio/signal_processing/include/signal_processing_library.h"
#include "webrtc/modules/audio_coding/codecs/builtin_audio_decoder_factory.h"
#include "webrtc/modules/audio_coding/include/audio_coding_module.h"
#include "webrtc/modules/audio_processing/include/audio_processing.h"
#include "webrtc/system_wrappers/include/file_wrapper.h"
#include "webrtc/voice_server_engine/channel.h"
#include "webrtc/voice_engine/include/voe_errors.h"
#include "webrtc/voice_engine/utility.h"
#include "webrtc/voice_server_engine/voice_server_engine_impl.h"
#include "webrtc/voice_server_engine/mixer_manager.h"
#include "webrtc/voice_server_engine/server_conference_mixer.h"

namespace webrtc
{

    VosEBase* VosEBase::GetInterface(VoiceServerEngine* voiceEngine)
    {
        if (nullptr == voiceEngine) {
            return nullptr;
        }
        VoiceServerEngineImpl* s = static_cast<VoiceServerEngineImpl*>(voiceEngine);
        s->AddRef();
        return s;
    }

    VosEBaseImpl::VosEBaseImpl(vose::SharedData* shared)
        : engineObserverPtr_(nullptr),
        shared_(shared)
    {}

    VosEBaseImpl::~VosEBaseImpl()
    {
        TerminateInternal();
    }

    int VosEBaseImpl::RegisterEngineObserver(VoiceServerEngineObserver& observer)
    {
        rtc::CritScope cs(&callbackCritSect_);
        if (engineObserverPtr_) {
            shared_->SetLastError(
                VE_INVALID_OPERATION, kTraceError,
                "RegisterVoiceEngineObserver() observer already enabled");
            return -1;
        }

        // Register the observer in all active channels
        for (vose::ChannelManager::Iterator it(&shared_->channel_manager());
            it.IsValid(); it.Increment()) {
            it.GetChannel()->RegisterVoiceEngineObserver(observer);
        }

        //shared_->mixer_manager().RegisterVoiceEngineObserver(observer);
        engineObserverPtr_ = &observer;
        return 0;
    }

    int VosEBaseImpl::DeRegisterEngineObserver()
    {
        rtc::CritScope cs(&callbackCritSect_);
        if (!engineObserverPtr_) {
            shared_->SetLastError(
                VE_INVALID_OPERATION, kTraceError,
                "DeRegisterVoiceEngineObserver() observer already disabled");
            return 0;
        }
        engineObserverPtr_ = nullptr;

        // Deregister the observer in all active channels
        for (vose::ChannelManager::Iterator it(&shared_->channel_manager());
            it.IsValid(); it.Increment()) {
            it.GetChannel()->DeRegisterVoiceEngineObserver();
        }

        return 0;
    }

    int VosEBaseImpl::Init(
        const rtc::scoped_refptr<AudioDecoderFactory>& decoder_factory)
    {
        rtc::CritScope cs(shared_->crit_sec());
        WebRtcSpl_Init();
        if (shared_->statistics().Initialized()) {
            return 0;
        }
        if (shared_->process_thread()) {
            shared_->process_thread()->Start();
        }

        bool available = false;


//         if (!audioproc) {
//             audioproc = AudioProcessing::Create();
//             if (!audioproc) {
//                 LOG(LS_ERROR) << "Failed to create AudioProcessing.";
//                 shared_->SetLastError(VE_NO_MEMORY);
//                 return -1;
//             }
//         }
//         shared_->set_audio_processing(audioproc);
// 
//         // Set the error state for any failures in this block.
//         shared_->SetLastError(VE_APM_ERROR);
//         // Configure AudioProcessing components.
//         if (audioproc->high_pass_filter()->Enable(true) != 0) {
//             LOG_F(LS_ERROR) << "Failed to enable high pass filter.";
//             return -1;
//         }
//         if (audioproc->echo_cancellation()->enable_drift_compensation(false) != 0) {
//             LOG_F(LS_ERROR) << "Failed to disable drift compensation.";
//             return -1;
//         }
//         if (audioproc->noise_suppression()->set_level(kDefaultNsMode) != 0) {
//             LOG_F(LS_ERROR) << "Failed to set noise suppression level: "
//                 << kDefaultNsMode;
//             return -1;
//         }
//         GainControl* agc = audioproc->gain_control();
//         if (agc->set_analog_level_limits(kMinVolumeLevel, kMaxVolumeLevel) != 0) {
//             LOG_F(LS_ERROR) << "Failed to set analog level limits with minimum: "
//                 << kMinVolumeLevel << " and maximum: " << kMaxVolumeLevel;
//             return -1;
//         }
//         if (agc->set_mode(kDefaultAgcMode) != 0) {
//             LOG_F(LS_ERROR) << "Failed to set mode: " << kDefaultAgcMode;
//             return -1;
//         }
//         if (agc->Enable(kDefaultAgcState) != 0) {
//             LOG_F(LS_ERROR) << "Failed to set agc state: " << kDefaultAgcState;
//             return -1;
//         }
        shared_->SetLastError(0);  // Clear error state.

        if (decoder_factory)
            decoder_factory_ = decoder_factory;
        else
            decoder_factory_ = CreateBuiltinAudioDecoderFactory();

        return shared_->statistics().SetInitialized();
    }

    int VosEBaseImpl::Terminate()
    {
        rtc::CritScope cs(shared_->crit_sec());
        return TerminateInternal();
    }

    int VosEBaseImpl::CreateChannel()
    {
        return CreateChannel(ChannelConfig());
    }

    int VosEBaseImpl::CreateChannel(const ChannelConfig& config)
    {
        rtc::CritScope cs(shared_->crit_sec());
        if (!shared_->statistics().Initialized()) {
            shared_->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }

        ChannelConfig config_copy(config);
        config_copy.acm_config.decoder_factory = decoder_factory_;
        vose::ChannelOwner channel_owner =
            shared_->channel_manager().CreateChannel(config_copy);
        return InitializeChannel(&channel_owner);
    }

    int VosEBaseImpl::InitializeChannel(vose::ChannelOwner* channel_owner)
    {
        if (channel_owner->channel()->SetEngineInformation(
            shared_->statistics(),  *shared_->process_thread(),
            engineObserverPtr_, &callbackCritSect_) != 0) {
            shared_->SetLastError(
                VE_CHANNEL_NOT_CREATED, kTraceError,
                "CreateChannel() failed to associate engine and channel."
                " Destroying channel.");
            shared_->channel_manager().DestroyChannel(
                channel_owner->channel()->ChannelId());
            return -1;
        } else if (channel_owner->channel()->Init() != 0) {
            shared_->SetLastError(
                VE_CHANNEL_NOT_CREATED, kTraceError,
                "CreateChannel() failed to initialize channel. Destroying"
                " channel.");
            shared_->channel_manager().DestroyChannel(
                channel_owner->channel()->ChannelId());
            return -1;
        }
        return channel_owner->channel()->ChannelId();
    }

    int VosEBaseImpl::DeleteChannel(int channel)
    {
        rtc::CritScope cs(shared_->crit_sec());
        if (!shared_->statistics().Initialized()) {
            shared_->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }

        {
            vose::ChannelOwner ch = shared_->channel_manager().GetChannel(channel);
            vose::Channel* channelPtr = ch.channel();
            if (channelPtr == nullptr) {
                shared_->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                    "DeleteChannel() failed to locate channel");
                return -1;
            }
        }

        shared_->channel_manager().DestroyChannel(channel);
        return 0;
    }

    int VosEBaseImpl::StartReceive(int channel)
    {
        rtc::CritScope cs(shared_->crit_sec());
        if (!shared_->statistics().Initialized()) {
            shared_->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = shared_->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == nullptr) {
            shared_->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StartReceive() failed to locate channel");
            return -1;
        }
        channelPtr->ResetDiscardedPacketCount();
        return channelPtr->StartRecv();
    }

    int VosEBaseImpl::StartSend(int channel)
    {
        rtc::CritScope cs(shared_->crit_sec());
        if (!shared_->statistics().Initialized()) {
            shared_->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = shared_->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == nullptr) {
            shared_->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StartSend() failed to locate channel");
            return -1;
        }
        if (channelPtr->Sending()) {
            return 0;
        }
        
        return channelPtr->StartSend();
    }

    int VosEBaseImpl::StopSend(int channel)
    {
        rtc::CritScope cs(shared_->crit_sec());
        if (!shared_->statistics().Initialized()) {
            shared_->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = shared_->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == nullptr) {
            shared_->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StopSend() failed to locate channel");
            return -1;
        }

        return channelPtr->StopSend();
    }

    int VosEBaseImpl::GetVersion(char version[1024])
    {
        if (version == nullptr) {
            shared_->SetLastError(VE_INVALID_ARGUMENT, kTraceError);
            return -1;
        }

        std::string versionString = VoiceServerEngine::GetVersionString();
        RTC_DCHECK_GT(1024, versionString.size() + 1);
        char* end = std::copy(versionString.cbegin(), versionString.cend(), version);
        end[0] = '\n';
        end[1] = '\0';
        return 0;
    }

    int VosEBaseImpl::LastError() { return (shared_->statistics().LastError()); }

    int32_t VosEBaseImpl::TerminateInternal()
    {
        // Delete any remaining channel objects
        shared_->channel_manager().DestroyAllChannels();
        shared_->mixer_manager().DestroyAllMixers();

        return shared_->statistics().SetUnInitialized();
    }

    int VosEBaseImpl::AssociateSendChannel(int channel,
        int accociate_send_channel)
    {
        rtc::CritScope cs(shared_->crit_sec());

        if (!shared_->statistics().Initialized()) {
            shared_->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }

        vose::ChannelOwner ch = shared_->channel_manager().GetChannel(channel);
        vose::Channel* channel_ptr = ch.channel();
        if (channel_ptr == NULL) {
            shared_->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "AssociateSendChannel() failed to locate channel");
            return -1;
        }

        ch = shared_->channel_manager().GetChannel(accociate_send_channel);
        vose::Channel* accociate_send_channel_ptr = ch.channel();
        if (accociate_send_channel_ptr == NULL) {
            shared_->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "AssociateSendChannel() failed to locate accociate_send_channel");
            return -1;
        }

        channel_ptr->set_associate_send_channel(ch);
        return 0;
    }

    int VosEBaseImpl::CreateServerMixer()
    {
        int ret = -1;
        rtc::CritScope cs(shared_->crit_sec());
        if (!shared_->statistics().Initialized()) {
            shared_->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }

        vose::MixerOwner mixer = shared_->mixer_manager().CreateMixer();
        if (mixer.IsValid()) {
            ret = mixer.mixer()->MixerId();
        }

        return ret;
    }

    int VosEBaseImpl::DeleteServerMixer(int mixer)
    {
        rtc::CritScope cs(shared_->crit_sec());
        if (!shared_->statistics().Initialized()) {
            shared_->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }

        {
            vose::MixerOwner ch = shared_->mixer_manager().GetMixer(mixer);
            vose::ServerConferenceMixer* mixerPtr = ch.mixer();
            if (mixerPtr == nullptr) {
                shared_->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                    "DeleteServerMixer() failed to locate mixer");
                return -1;
            }
        }

        shared_->mixer_manager().DestroyMixer(mixer);
        return 0;
    }


    int VosEBaseImpl::AddChannel2Mixer(int channel, int mixer)
    {
        rtc::CritScope cs(shared_->crit_sec());
        if (!shared_->statistics().Initialized()) {
            shared_->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }

        vose::ChannelOwner chn = shared_->channel_manager().GetChannel(channel);
        vose::MixerOwner mix = shared_->mixer_manager().GetMixer(mixer);
        if (chn.IsValid() && mix.IsValid()) {
            return chn.channel()->SetServerConferenceMixer(mix.mixer());
        } else {
            shared_->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "AddChannel2Mixer() failed to locate channel");
        }

        return -1;
    }

    int VosEBaseImpl::RemoveChannel4Mixer(int channel)
    {
        rtc::CritScope cs(shared_->crit_sec());
        if (!shared_->statistics().Initialized()) {
            shared_->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }

        vose::ChannelOwner chn = shared_->channel_manager().GetChannel(channel);
        if (chn.IsValid()) {
            return chn.channel()->RemoveFromServerConferenceMixer();
        } else {
            shared_->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "RemoveChannel4Mixer() failed to locate channel");
        }

        return -1;
    }


    int VosEBaseImpl::StopReceive(int channel)
    {
        int ret = -1;
        rtc::CritScope cs(shared_->crit_sec());
        if (!shared_->statistics().Initialized()) {
            shared_->SetLastError(VE_NOT_INITED, kTraceError);
            return ret;
        }

        vose::ChannelOwner chn = shared_->channel_manager().GetChannel(channel);
        if (chn.IsValid()) {
           ret = chn.channel()->StopRecv();
        } else {
            shared_->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StopReceive() failed to locate channel");
        }

        return ret;
    }

}  // namespace webrtc
