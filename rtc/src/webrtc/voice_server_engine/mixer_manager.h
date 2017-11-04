#ifndef WEBRTC_VOICE_SERVER_ENGINE_MIXER_MANANGER_H
#define WEBRTC_VOICE_SERVER_ENGINE_MIXER_MANANGER_H

#include "webrtc/base/constructormagic.h"
#include "webrtc/base/criticalsection.h"
#include "webrtc/base/scoped_ref_ptr.h"
#include "webrtc/system_wrappers/include/atomic32.h"
#include "webrtc/typedefs.h"

namespace webrtc
{
    namespace vose
    {
        class ServerConferenceMixer;
        class SharedData;

        class MixerOwner
        {
        public:
            explicit MixerOwner(ServerConferenceMixer* mixer);
            MixerOwner(const MixerOwner& mixer_owner);

            ~MixerOwner();

            MixerOwner& operator=(const MixerOwner& other);

            ServerConferenceMixer* mixer() const { return mixer_ref_->mixer.get(); }
            bool IsValid() { return mixer_ref_->mixer.get() != NULL; }
            int use_count() const { return mixer_ref_->ref_count.Value(); }
        private:
            // Shared instance of a Channel. Copying ChannelOwners increase the reference
            // count and destroying ChannelOwners decrease references. Channels are
            // deleted when no references to them are held.
            struct MixerRef
            {
                MixerRef(ServerConferenceMixer* mixer);
                const std::unique_ptr<ServerConferenceMixer> mixer;
                Atomic32 ref_count;
            };

            MixerRef* mixer_ref_;
        };

        class MixerManager
        {
        public:
            MixerManager(int32_t instanceId, SharedData *shared);

            class Iterator
            {
            public:
                explicit Iterator(MixerManager* channel_manager);

                ServerConferenceMixer* GetMixer();
                bool IsValid();
                void Increment();
            private:
                size_t iterator_pos_;
                std::vector<MixerOwner> mixers_;

                RTC_DISALLOW_COPY_AND_ASSIGN(Iterator);
            };

            // CreateChannel will always return a valid ChannelOwner instance.
            MixerOwner CreateMixer();

            // ChannelOwner.channel() will be NULL if channel_id is invalid or no longer
            // exists. This should be checked with ChannelOwner::IsValid().
            MixerOwner GetMixer(int32_t mixer_id);
            void GetAllMixers(std::vector<MixerOwner>* mixers);

            void DestroyMixer(int32_t mixer_id);
            void DestroyAllMixers();

            size_t NumOfMixers() const;
        private:
            uint32_t instance_id_;
            SharedData *shared_;
            Atomic32 last_mixer_id_;

            rtc::CriticalSection lock_;
            std::vector<MixerOwner> mixers_;

            RTC_DISALLOW_COPY_AND_ASSIGN(MixerManager);
        };
    }
}

#endif //WEBRTC_VOICE_SERVER_ENGINE_MIXER_MANANGER_H