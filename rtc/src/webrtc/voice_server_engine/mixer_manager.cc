#include "webrtc/voice_server_engine/mixer_manager.h"
#include "webrtc/voice_server_engine/server_conference_mixer.h"
#include "webrtc/voice_server_engine/channel.h"
#include "webrtc/voice_server_engine/shared_data.h"

namespace webrtc
{
    namespace vose
    {
        MixerOwner::MixerOwner(ServerConferenceMixer* mixer)
            : mixer_ref_(new MixerRef(mixer))
        {}

        MixerOwner::~MixerOwner()
        {
            if (0 == --mixer_ref_->ref_count) {
                delete mixer_ref_;
            }
        }

        MixerOwner& MixerOwner::operator=(const MixerOwner& other)
        {
            if (other.mixer_ref_ == mixer_ref_)
                return *this;

            if (--mixer_ref_->ref_count == 0)
                delete mixer_ref_;

            mixer_ref_ = other.mixer_ref_;
            ++mixer_ref_->ref_count;

            return *this;
        }

        MixerOwner::MixerOwner(const MixerOwner& mixer_owner)
            :mixer_ref_(mixer_owner.mixer_ref_)
        {
            ++mixer_ref_->ref_count;
        }

        MixerOwner::MixerRef::MixerRef(class ServerConferenceMixer* mix)
            :mixer(mix), ref_count(1)
        {}

        MixerManager::MixerManager(int32_t instanceId, SharedData *shared)
            : instance_id_(instanceId), last_mixer_id_(-1), shared_(shared)
        {}

        MixerOwner webrtc::vose::MixerManager::CreateMixer()
        {
            MixerOwner owner(new ServerConferenceMixer(
                ++last_mixer_id_, instance_id_, shared_->channel_manager(), shared_->process_thread()));
            {
                rtc::CritScope cs(&lock_);
                mixers_.push_back(owner);
            }

            return owner;
        }

        MixerOwner webrtc::vose::MixerManager::GetMixer(int32_t mixer_id)
        {
            rtc::CritScope crit(&lock_);

            for (size_t i = 0; i < mixers_.size(); ++i) {
                if (mixers_[i].mixer()->MixerId() == mixer_id)
                    return mixers_[i];
            }
            return MixerOwner(NULL);
        }

        void MixerManager::GetAllMixers(std::vector<MixerOwner>* mixers)
        {
            rtc::CritScope crit(&lock_);
            *mixers = mixers_;
        }

        void MixerManager::DestroyMixer(int32_t mixer_id)
        {
            assert(mixer_id >= 0);
            MixerOwner reference(NULL);
            {
                rtc::CritScope crit(&lock_);
                

                std::vector<MixerOwner>::iterator to_delete = mixers_.end();
                for (auto it = mixers_.begin(); it != mixers_.end(); ++it) {
                    if (it->mixer()->MixerId() == mixer_id) {
                        to_delete = it;
                    }
                }

                if (to_delete != mixers_.end()) {
                    reference = *to_delete;
                    mixers_.erase(to_delete);
                }
            }
        }

        void MixerManager::DestroyAllMixers()
        {
            std::vector<MixerOwner> references;
            {
                rtc::CritScope crit(&lock_);
                references = mixers_;
                mixers_.clear();
            }
        }

        size_t MixerManager::NumOfMixers() const
        {
            rtc::CritScope crit(&lock_);
            return mixers_.size();
        }

        MixerManager::Iterator::Iterator(MixerManager* channel_manager)
            : iterator_pos_(0)
        {
            channel_manager->GetAllMixers(&mixers_);
        }

        ServerConferenceMixer* MixerManager::Iterator::GetMixer()
        {
            if (iterator_pos_ < mixers_.size()) {
                return mixers_[iterator_pos_].mixer();
            }
            return NULL;
        }

        bool MixerManager::Iterator::IsValid()
        {
            return iterator_pos_ < mixers_.size();
        }

        void MixerManager::Iterator::Increment()
        {
            ++iterator_pos_;
        }
    }
}
