#ifndef WEBRTC_VOICE_SERVER_ENGINE_VOSE_BASE_IMPL_H
#define WEBRTC_VOICE_SERVER_ENGINE_VOSE_BASE_IMPL_H

#include "webrtc/voice_server_engine/include/vose_base.h"
#include "webrtc/voice_engine/include/voe_errors.h"
#include "webrtc/base/criticalsection.h"
#include "webrtc/modules/include/module_common_types.h"
#include "webrtc/voice_server_engine/shared_data.h"

namespace webrtc
{

    class ProcessThread;

    class VosEBaseImpl : public VosEBase
    {
    public:
        int RegisterEngineObserver(VoiceServerEngineObserver& observer) override;
        int DeRegisterEngineObserver() override;

        int Init(const rtc::scoped_refptr<AudioDecoderFactory>& decoder_factory =
            nullptr) override;
//         AudioProcessing* audio_processing() override
//         {
//             return shared_->audio_processing();
//         }
       
        int Terminate() override;

        int CreateChannel() override;
        int CreateChannel(const ChannelConfig& config) override;
        int DeleteChannel(int channel) override;

        int StartReceive(int channel) override;
        int StartSend(int channel) override;
        int StopSend(int channel) override;

        int GetVersion(char version[1024]) override;

        int LastError() override;

        int AssociateSendChannel(int channel, int accociate_send_channel) override;

        virtual int CreateServerMixer() override;

        virtual int DeleteServerMixer(int mixer) override;

        virtual int AddChannel2Mixer(int channel, int mixer) override;

        virtual int RemoveChannel4Mixer(int channel) override;

        virtual int StopReceive(int channel) override;

    protected:
        VosEBaseImpl(vose::SharedData* shared);
        ~VosEBaseImpl() override;

    private:
        int32_t TerminateInternal();

        // Initialize channel by setting Engine Information then initializing
        // channel.
        int InitializeChannel(vose::ChannelOwner* channel_owner);

        VoiceServerEngineObserver* engineObserverPtr_;
        rtc::CriticalSection callbackCritSect_;
        rtc::scoped_refptr<AudioDecoderFactory> decoder_factory_;

        AudioFrame audioFrame_;
        vose::SharedData* shared_;
    };

}  // namespace webrtc

#endif //WEBRTC_VOICE_SERVER_ENGINE_VOSE_BASE_IMPL_H