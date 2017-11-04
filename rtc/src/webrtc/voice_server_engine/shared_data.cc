#include "webrtc/voice_server_engine/shared_data.h"

#include "webrtc/modules/audio_processing/include/audio_processing.h"
#include "webrtc/system_wrappers/include/trace.h"
#include "webrtc/voice_server_engine/channel.h"
#include "webrtc/voice_server_engine/server_conference_mixer.h"

namespace webrtc
{
    namespace vose
    {
        static int32_t _gInstanceCounter = 0;

        SharedData::SharedData()
            : _instanceId(++_gInstanceCounter),
            _channelManager(_gInstanceCounter),
            _mixerManager(_gInstanceCounter, this),
            _engineStatistics(_gInstanceCounter),
            _moduleProcessThreadPtr(ProcessThread::Create("VoiceProcessThread"))
        {
            Trace::CreateTrace();
        }

        SharedData::~SharedData()
        {
            _moduleProcessThreadPtr->Stop();
            Trace::ReturnTrace();
        }

        int SharedData::NumOfSendingChannels()
        {
            ChannelManager::Iterator it(&_channelManager);
            int sending_channels = 0;

            for (ChannelManager::Iterator it(&_channelManager); it.IsValid();
                it.Increment()) {
                if (it.GetChannel()->Sending())
                    ++sending_channels;
            }

            return sending_channels;
        }

        int SharedData::NumOfRecvingChannels()
        {
            ChannelManager::Iterator it(&_channelManager);
            int recving_channels = 0;

            for (ChannelManager::Iterator it(&_channelManager); it.IsValid();
                it.Increment()) {
                if (it.GetChannel()->Recving())
                    ++recving_channels;
            }

            return recving_channels;
        }

        void SharedData::SetLastError(int32_t error) const
        {
            _engineStatistics.SetLastError(error);
        }

        void SharedData::SetLastError(int32_t error,
            TraceLevel level) const
        {
            _engineStatistics.SetLastError(error, level);
        }

        void SharedData::SetLastError(int32_t error, TraceLevel level,
            const char* msg) const
        {
            _engineStatistics.SetLastError(error, level, msg);
        }

    }  // namespace voe

}  // namespace webrtc
