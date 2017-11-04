#ifndef WEBRTC_VOICE_SERVER_ENGINE_SHARED_DATA_H
#define WEBRTC_VOICE_SERVER_ENGINE_SHARED_DATA_H

#include <memory>

#include "webrtc/base/criticalsection.h"
#include "webrtc/base/scoped_ref_ptr.h"
#include "webrtc/modules/utility/include/process_thread.h"
#include "webrtc/voice_server_engine/channel_manager.h"
#include "webrtc/voice_server_engine/mixer_manager.h"

// use voe's defines
#include "webrtc/voice_engine/statistics.h"
#include "webrtc/voice_engine/voice_engine_defines.h"

class ProcessThread;

namespace webrtc
{
    namespace vose
    {
        class SharedData
        {
        public:
            // Public accessors.
            uint32_t instance_id() const { return _instanceId; }
            voe::Statistics& statistics() { return _engineStatistics; }
            ChannelManager& channel_manager() { return _channelManager; }
            MixerManager& mixer_manager() { return _mixerManager; }
            rtc::CriticalSection* crit_sec() { return &_apiCritPtr; }
            ProcessThread* process_thread() { return _moduleProcessThreadPtr.get(); }

            int NumOfSendingChannels();
            int NumOfRecvingChannels();

            // Convenience methods for calling statistics().SetLastError().
            void SetLastError(int32_t error) const;
            void SetLastError(int32_t error, TraceLevel level) const;
            void SetLastError(int32_t error, TraceLevel level,
                const char* msg) const;

        protected:
            const uint32_t _instanceId;
            rtc::CriticalSection _apiCritPtr;
            ChannelManager _channelManager;
            MixerManager _mixerManager;
            voe::Statistics _engineStatistics;
            std::unique_ptr<ProcessThread> _moduleProcessThreadPtr;

            SharedData();
            virtual ~SharedData();
        };
    }
}
#endif //WEBRTC_VOICE_SERVER_ENGINE_SHARED_DATA_H