#include "webrtc/modules/audio_conference_mixer/source/audio_conference_mixer_multistream_impl.h"
#include "webrtc/audio/utility/audio_frame_operations.h"
#include "webrtc/modules/audio_conference_mixer/include/audio_conference_mixer_defines.h"
#include "webrtc/modules/audio_conference_mixer/include/audio_conference_mixer_multistream_expandation.h"
#include "webrtc/modules/audio_conference_mixer/source/audio_conference_mixer_impl.h"
#include "webrtc/modules/audio_conference_mixer/source/audio_frame_manipulator.h"
#include "webrtc/modules/audio_processing/include/audio_processing.h"
#include "webrtc/system_wrappers/include/critical_section_wrapper.h"
#include "webrtc/system_wrappers/include/trace.h"

namespace webrtc
{
    size_t MaxNumChannels(const AudioFrameList* list)
    {
        size_t max_num_channels = 1;
        for (AudioFrameList::const_iterator iter = list->begin();
            iter != list->end();
            ++iter) {
            max_num_channels = std::max(max_num_channels, (*iter).frame->num_channels_);
        }
        return max_num_channels;
    }

    AudioConferenceMixer* AudioConferenceMixerMultiStreamExpandation::Create(int id)
    {
        WEBRTC_TRACE(kTraceInfo, kTraceAudioMixerServer, id,
            "Create AudioConferenceMixerMultiStreamImpl");
        AudioConferenceMixerMultiStreamImpl* mixer = new AudioConferenceMixerMultiStreamImpl(id);
        if (!mixer->Init()) {
            delete mixer;
            return NULL;
        }
        return mixer;
    }

    AudioConferenceMixerMultiStreamImpl::AudioConferenceMixerMultiStreamImpl(int32_t id)
        :AudioConferenceMixerImpl(id)
    {}

    void AudioConferenceMixerMultiStreamImpl::Process()
    {
        size_t remainingParticipantsAllowedToMix =
            kMaximumAmountOfMixedParticipants;
        {
            CriticalSectionScoped cs(_crit.get());
            assert(_processCalls == 0);
            _processCalls++;

            // Let the scheduler know that we are running one iteration.
            _timeScheduler.UpdateScheduler();
        }

        AudioFrameList mixList;
        AudioFrameList rampOutList;
        AudioFrameList additionalFramesList;
        std::map<int, MixerParticipant*> mixedParticipantsMap;
        {
            CriticalSectionScoped cs(_cbCrit.get());

            int32_t lowFreq = GetLowestMixingFrequency();
            // SILK can run in 12 kHz and 24 kHz. These frequencies are not
            // supported so use the closest higher frequency to not lose any
            // information.
            // TODO(henrike): this is probably more appropriate to do in
            //                GetLowestMixingFrequency().
            if (lowFreq == 12000) {
                lowFreq = 16000;
            } else if (lowFreq == 24000) {
                lowFreq = 32000;
            }
            if (lowFreq <= 0) {
                CriticalSectionScoped cs(_crit.get());
                _processCalls--;
                return;
            } else {
                switch (lowFreq) {
                case 8000:
                    if (OutputFrequency() != kNbInHz) {
                        SetOutputFrequency(kNbInHz);
                    }
                    break;
                case 16000:
                    if (OutputFrequency() != kWbInHz) {
                        SetOutputFrequency(kWbInHz);
                    }
                    break;
                case 32000:
                    if (OutputFrequency() != kSwbInHz) {
                        SetOutputFrequency(kSwbInHz);
                    }
                    break;
                case 48000:
                    if (OutputFrequency() != kFbInHz) {
                        SetOutputFrequency(kFbInHz);
                    }
                    break;
                default:
                    assert(false);

                    CriticalSectionScoped cs(_crit.get());
                    _processCalls--;
                    return;
                }
            }

            UpdateToMix(&mixList, &rampOutList, &mixedParticipantsMap,
                &remainingParticipantsAllowedToMix);

            GetAdditionalAudio(&additionalFramesList);
            UpdateMixedStatus(mixedParticipantsMap);
        }  // At this, we decided which participants to mix(active)


        // The next section,we mix multistream,include all active participants to others and N(actives) stream
        // for each active participants.

        // Get an AudioFrame for mixing from the memory pool.
        AudioFrame* mixedAudio = NULL;
        AudioFrame* activeMixedAudio[kMaximumAmountOfMixedParticipants] = { NULL };
        if (_audioFramePool->PopMemory(mixedAudio) == -1) {
            WEBRTC_TRACE(kTraceMemory, kTraceAudioMixerServer, _id,
                "failed PopMemory() call");
            assert(false);
            return;
        }

        for (auto i = 0; i < kMaximumAmountOfMixedParticipants; i++) {
            if (-1 == _audioFramePool->PopMemory(activeMixedAudio[i])) {
                WEBRTC_TRACE(kTraceMemory, kTraceAudioMixerServer, _id,
                    "failed PopMemory() call");
                assert(false);
                return;
            }
        }

        {
            CriticalSectionScoped cs(_crit.get());
            AudioFrameList tomixList;
            AudioFrameList::iterator it;
            for (auto i = 0; i < kMaximumAmountOfMixedParticipants; i++) {
                tomixList = mixList;
                it = tomixList.begin();
                for (auto n = 0; n < i && it != tomixList.end(); n++) {
                    ++it; 
                }
                if (it != tomixList.end()) {
                    activeMixedAudio[i]->id_ = it->frame->id_;
                    tomixList.erase(it);
                    MixStream(activeMixedAudio[i], tomixList, additionalFramesList, rampOutList);
                }
            }

            mixedAudio->id_ = kMaximumAmountOfMixedParticipants;
            MixStream(mixedAudio, mixList, additionalFramesList, rampOutList);

            _timeStamp += static_cast<uint32_t>(_sampleSize);
        }

        {
            CriticalSectionScoped cs(_cbCrit.get());
            if (_mixReceiver != NULL) {
                AudioFrame **dummy = activeMixedAudio;
                _mixReceiver->NewMixedAudio(_id, *mixedAudio, const_cast<const AudioFrame**>(dummy), mixList.size());
            }
        }

        // Reclaim all outstanding memory.
        _audioFramePool->PushMemory(mixedAudio);
        for (auto i = 0; i < kMaximumAmountOfMixedParticipants; i++) {
            _audioFramePool->PushMemory(activeMixedAudio[i]);
        }
        ClearAudioFrameList(&mixList);
        ClearAudioFrameList(&rampOutList);
        ClearAudioFrameList(&additionalFramesList);
        {
            CriticalSectionScoped cs(_crit.get());
            _processCalls--;
        }
    }
    void AudioConferenceMixerMultiStreamImpl::MixStream(AudioFrame *mixedAudio, 
            const AudioFrameList & mixList,
            const AudioFrameList & additionalFramesList,
            const AudioFrameList & rampOutList)
    {
        // TODO(henrike): it might be better to decide the number of channels
        //                with an API instead of dynamically.

        // Find the max channels over all mixing lists.
        const size_t num_mixed_channels = std::max(MaxNumChannels(&mixList),
            std::max(MaxNumChannels(&additionalFramesList),
                MaxNumChannels(&rampOutList)));

        mixedAudio->UpdateFrame(mixedAudio->id_, _timeStamp, NULL, 0, _outputFrequency,
            AudioFrame::kNormalSpeech,
            AudioFrame::kVadPassive, num_mixed_channels);

        // We only use the limiter if it supports the output sample rate and
        // we're actually mixing multiple streams.
        use_limiter_ =
            (mixList.size() + additionalFramesList.size() + rampOutList.size()) > 1 &&
            _outputFrequency <= AudioProcessing::kMaxNativeSampleRateHz;

        MixFromList(mixedAudio, mixList);
        MixAnonomouslyFromList(mixedAudio, additionalFramesList);
        MixAnonomouslyFromList(mixedAudio, rampOutList);

        if (mixedAudio->samples_per_channel_ == 0) {
            // Nothing was mixed, set the audio samples to silence.
            mixedAudio->samples_per_channel_ = _sampleSize;
            AudioFrameOperations::Mute(mixedAudio);
        } 
    }
}

