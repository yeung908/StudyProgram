
#ifndef WEBRTC_VOICE_ENGINE_CHANNEL_H_
#define WEBRTC_VOICE_ENGINE_CHANNEL_H_

#include <memory>

#include "webrtc/api/audio/audio_mixer.h"
#include "webrtc/api/call/audio_sink.h"
#include "webrtc/api/call/transport.h"
#include "webrtc/base/criticalsection.h"
#include "webrtc/base/optional.h"
#include "webrtc/common_audio/resampler/include/push_resampler.h"
#include "webrtc/common_types.h"
#include "webrtc/modules/audio_coding/acm2/codec_manager.h"
#include "webrtc/modules/audio_coding/acm2/rent_a_codec.h"
#include "webrtc/modules/audio_coding/include/audio_coding_module.h"
#include "webrtc/modules/audio_conference_mixer/include/audio_conference_mixer_defines.h"
#include "webrtc/modules/audio_processing/rms_level.h"
#include "webrtc/modules/rtp_rtcp/include/remote_ntp_time_estimator.h"
#include "webrtc/modules/rtp_rtcp/include/rtp_header_parser.h"
#include "webrtc/modules/rtp_rtcp/include/rtp_rtcp.h"
#include "webrtc/voice_engine/file_player.h"
#include "webrtc/voice_engine/file_recorder.h"
//#include "webrtc/voice_engine/include/voe_audio_processing.h"
#include "webrtc/voice_server_engine/include/vose_base.h"
#include "webrtc/voice_server_engine/include/vose_network.h"
#include "webrtc/voice_server_engine/shared_data.h"
#include "webrtc/voice_engine/level_indicator.h"
#include "webrtc/voice_engine/voice_engine_defines.h"

namespace rtc
{
    class TimestampWrapAroundHandler;
}

namespace webrtc
{
    class FileWrapper;
    class PacketRouter;
    class ProcessThread;
    class RateLimiter;
    class ReceiveStatistics;
    class RemoteNtpTimeEstimator;
    class RtcEventLog;
    class RTPPayloadRegistry;
    class RtpReceiver;
    class RTPReceiverAudio;
    class RtpRtcp;
    class TelephoneEventHandler;
    class VosERTPObserver;
    class VoiceServerEngineObserver;

    struct CallStatistics;
    struct ReportBlock;
    struct SenderInfo;

    namespace voe
    {
        class Statistics;
    }

    namespace vose
    {
        class RtcEventLogProxy;
        class RtcpRttStatsProxy;
        class RtpPacketSenderProxy;
        class StatisticsProxy;
        class TransportFeedbackProxy;
        class TransportSequenceNumberProxy;
        class VosERtcpObserver;
        class ServerConferenceMixer;

        // Helper class to simplify locking scheme for members that are accessed from
        // multiple threads.
        // Example: a member can be set on thread T1 and read by an internal audio
        // thread T2. Accessing the member via this class ensures that we are
        // safe and also avoid TSan v2 warnings.
        class ChannelState
        {
        public:
            struct State
            {
                bool recving = false;
                bool sending = false;
            };

            ChannelState() {}
            virtual ~ChannelState() {}

            void Reset()
            {
                rtc::CritScope lock(&lock_);
                state_ = State();
            }

            State Get() const
            {
                rtc::CritScope lock(&lock_);
                return state_;
            }

            void SetRecving(bool enable)
            {
                rtc::CritScope lock(&lock_);
                state_.recving = enable;
            }

            void SetSending(bool enable)
            {
                rtc::CritScope lock(&lock_);
                state_.sending = enable;
            }

        private:
            rtc::CriticalSection lock_;
            State state_;
        };

        class Channel
            : public RtpData,
            public RtpFeedback,
            public FileCallback,  // receiving notification from file player &
                                  // recorder
            public Transport,
            public AudioPacketizationCallback,  // receive encoded packets from the
                                                // ACM
            public ACMVADCallback,              // receive voice activity from the ACM
            public MixerParticipant,  // supplies output mixer with audio frames
            public OverheadObserver
        {
        public:
            friend class VosERtcpObserver;

            enum { KNumSocketThreads = 1 };
            enum { KNumberOfSocketBuffers = 8 };
            virtual ~Channel();
            static int32_t CreateChannel(
                Channel*& channel,
                int32_t channelId,
                uint32_t instanceId,
                const VosEBase::ChannelConfig& config);
            Channel(int32_t channelId,
                uint32_t instanceId,
                const VosEBase::ChannelConfig& config);
            int32_t Init();
            int32_t SetEngineInformation(voe::Statistics& engineStatistics,
                ProcessThread& moduleProcessThread,
                VoiceServerEngineObserver* voiceEngineObserver,
                rtc::CriticalSection* callbackCritSect);
            int32_t SetServerConferenceMixer(ServerConferenceMixer *mixer);
            int32_t RemoveFromServerConferenceMixer();

            int32_t UpdateLocalTimeStamp();

            void SetSink(std::unique_ptr<AudioSinkInterface> sink);

            // TODO(ossu): Don't use! It's only here to confirm that the decoder factory
            // passed into AudioReceiveStream is the same as the one set when creating the
            // ADM. Once Channel creation is moved into Audio{Send,Receive}Stream this can
            // go.
            const rtc::scoped_refptr<AudioDecoderFactory>& GetAudioDecoderFactory() const;

            // API methods

            // VoEBase
            int32_t StartRecv();
            int32_t StopRecv();
            int32_t StartSend();
            int32_t StopSend();
            void ResetDiscardedPacketCount();
            int32_t RegisterVoiceEngineObserver(VoiceServerEngineObserver& observer);
            int32_t DeRegisterVoiceEngineObserver();

            // VoECodec
            int32_t GetSendCodec(CodecInst& codec);
            int32_t GetRecCodec(CodecInst& codec);
            int32_t SetSendCodec(const CodecInst& codec);
            void SetBitRate(int bitrate_bps, int64_t probing_interval_ms);
            int32_t SetVADStatus(bool enableVAD, ACMVADMode mode, bool disableDTX);
            int32_t GetVADStatus(bool& enabledVAD, ACMVADMode& mode, bool& disabledDTX);
            int32_t SetRecPayloadType(const CodecInst& codec);
            int32_t SetRecPayloadType(int payload_type, const SdpAudioFormat& format);
            int32_t GetRecPayloadType(CodecInst& codec);
            int32_t SetSendCNPayloadType(int type, PayloadFrequencies frequency);
            int SetOpusMaxPlaybackRate(int frequency_hz);
            int SetOpusDtx(bool enable_dtx);
            int GetOpusDtx(bool* enabled);
            bool EnableAudioNetworkAdaptor(const std::string& config_string);
            void DisableAudioNetworkAdaptor();
            void SetReceiverFrameLengthRange(int min_frame_length_ms,
                int max_frame_length_ms);

            // VoENetwork
            int32_t RegisterExternalTransport(Transport* transport);
            int32_t DeRegisterExternalTransport();
            int32_t ReceivedRTPPacket(const uint8_t* received_packet,
                size_t length,
                const PacketTime& packet_time);
            int32_t ReceivedRTCPPacket(const uint8_t* data, size_t length);

            // VosEFile
            // Starts read voice data from local file and sending to remote
            int StartSendingFileLocally(
                const char fileNameUTF8[1024],
                bool loop = false,
                FileFormats format = kFileFormatPcm16kHzFile,
                float volumeScaling = 1.0,
                int startPointMs = 0,
                int stopPointMs = 0);
             int StartSendingFileLocally(
                InStream* stream,
                FileFormats format = kFileFormatPcm16kHzFile,
                float volumeScaling = 1.0,
                int startPointMs = 0,
                int stopPointMs = 0);
            int StopSendingFileLocally();
            int IsSendingFileLocally();
            int StartRecordingSend(
                const char* fileNameUTF8,
                CodecInst* compression = NULL,
                int maxSizeBytes = -1);
            int StopRecordingSend();
            int StartRecordingSend(OutStream* stream,CodecInst* compression = NULL);
            int StartRecordingRecv(
                const char* fileNameUTF8,
                CodecInst* compression = NULL,
                int maxSizeBytes = -1);
            int StartRecordingRecv(OutStream* stream, CodecInst* compression = NULL);
            int StopRecordingRecv();

            // VoEExternalMediaProcessing
//             int RegisterExternalMediaProcessing(ProcessingTypes type,
//                 VoEMediaProcess& processObject);
//             int DeRegisterExternalMediaProcessing(ProcessingTypes type);
//             int SetExternalMixing(bool enabled);

            // VoEVolumeControl
            int GetSpeechRecvLevel(uint32_t& level) const;
            int GetSpeechRecvLevelFullRange(uint32_t& level) const;
            int SetInputMute(bool enable);
            bool InputMute() const;
            int SetOutputVolumePan(float left, float right);
            int GetOutputVolumePan(float& left, float& right) const;
            int SetChannelOutputVolumeScaling(float scaling);
            int GetChannelOutputVolumeScaling(float& scaling) const;

            // VoENetEqStats
            int GetNetworkStatistics(NetworkStatistics& stats);
            void GetDecodingCallStatistics(AudioDecodingCallStats* stats) const;

            // VoEVideoSync
            bool GetDelayEstimate(int* jitter_buffer_delay_ms,
                int* playout_buffer_delay_ms) const;
            uint32_t GetDelayEstimate() const;
            int LeastRequiredDelayMs() const;
            int SetMinimumPlayoutDelay(int delayMs);
            int GetPlayoutTimestamp(unsigned int& timestamp);
            int SetInitTimestamp(unsigned int timestamp);
            int SetInitSequenceNumber(short sequenceNumber);

            // VoEVideoSyncExtended
            int GetRtpRtcp(RtpRtcp** rtpRtcpModule, RtpReceiver** rtp_receiver) const;

            // DTMF
            int SendTelephoneEventOutband(int event, int duration_ms);
            int SetSendTelephoneEventPayloadType(int payload_type, int payload_frequency);

            // VoEAudioProcessingImpl
            int VoiceActivityIndicator(int& activity);

            // VosERTP_RTCP
            int SetLocalSSRC(unsigned int ssrc);
            int GetLocalSSRC(unsigned int& ssrc);
            int GetRemoteSSRC(unsigned int& ssrc);
            int SetSendAudioLevelIndicationStatus(bool enable, unsigned char id);
            int SetReceiveAudioLevelIndicationStatus(bool enable, unsigned char id);
//             int SetSendAbsoluteSenderTimeStatus(bool enable, unsigned char id);
//             int SetReceiveAbsoluteSenderTimeStatus(bool enable, unsigned char id);
            void EnableSendTransportSequenceNumber(int id);
            void EnableReceiveTransportSequenceNumber(int id);

            void RegisterSenderCongestionControlObjects(
                RtpPacketSender* rtp_packet_sender,
                TransportFeedbackObserver* transport_feedback_observer,
                PacketRouter* packet_router);
            void RegisterReceiverCongestionControlObjects(PacketRouter* packet_router);
            void ResetCongestionControlObjects();

            void SetRTCPStatus(bool enable);
            int GetRTCPStatus(bool& enabled);
            int SetRTCP_CNAME(const char cName[256]);
            int GetRemoteRTCP_CNAME(char cName[256]);
            int GetRemoteRTCPData(unsigned int& NTPHigh,
                unsigned int& NTPLow,
                unsigned int& timestamp,
                unsigned int& playoutTimestamp,
                unsigned int* jitter,
                unsigned short* fractionLost);
            int SendApplicationDefinedRTCPPacket(unsigned char subType,
                unsigned int name,
                const char* data,
                unsigned short dataLengthInBytes);
            int GetRTPStatistics(unsigned int& averageJitterMs,
                unsigned int& maxJitterMs,
                unsigned int& discardedPackets);
            int GetRemoteRTCPReportBlocks(std::vector<ReportBlock>* report_blocks);
            int GetRTPStatistics(CallStatistics& stats);
            int SetCodecFECStatus(bool enable);
            bool GetCodecFECStatus();
            void SetNACKStatus(bool enable, int maxNumberOfPackets);

            // From AudioPacketizationCallback in the ACM
            int32_t SendData(FrameType frameType,
                uint8_t payloadType,
                uint32_t timeStamp,
                const uint8_t* payloadData,
                size_t payloadSize,
                const RTPFragmentationHeader* fragmentation) override;

            // From ACMVADCallback in the ACM
            int32_t InFrameType(FrameType frame_type) override;

            // From RtpData in the RTP/RTCP module
            int32_t OnReceivedPayloadData(const uint8_t* payloadData,
                size_t payloadSize,
                const WebRtcRTPHeader* rtpHeader) override;
            bool OnRecoveredPacket(const uint8_t* packet, size_t packet_length) override;

            // From RtpFeedback in the RTP/RTCP module
            int32_t OnInitializeDecoder(int8_t payloadType,
                const char payloadName[RTP_PAYLOAD_NAME_SIZE],
                int frequency,
                size_t channels,
                uint32_t rate) override;
            void OnIncomingSSRCChanged(uint32_t ssrc) override;
            void OnIncomingCSRCChanged(uint32_t CSRC, bool added) override;

            // From Transport (called by the RTP/RTCP module)
            bool SendRtp(const uint8_t* data,
                size_t len,
                const PacketOptions& packet_options) override;
            bool SendRtcp(const uint8_t* data, size_t len) override;

            // From MixerParticipant
            MixerParticipant::AudioFrameInfo GetAudioFrameWithMuted(
                int32_t id,
                AudioFrame* audioFrame) override;
            int32_t NeededFrequency(int32_t id) const override;

            // From AudioMixer::Source.
            AudioMixer::Source::AudioFrameInfo GetAudioFrameWithInfo(
                int sample_rate_hz,
                AudioFrame* audio_frame);

            // From FileCallback
            void PlayNotification(int32_t id, uint32_t durationMs) override;
            void RecordNotification(int32_t id, uint32_t durationMs) override;
            void PlayFileEnded(int32_t id) override;
            void RecordFileEnded(int32_t id) override;

            uint32_t InstanceId() const { return _instanceId; }
            int32_t ChannelId() const { return _channelId; }
            bool Recving() const { return channel_state_.Get().recving; }
            bool Sending() const { return channel_state_.Get().sending; }
            bool ExternalTransport() const
            {
                rtc::CritScope cs(&_callbackCritSect);
                return _externalTransport;
            }
            bool ExternalMixing() const { return _externalMixing; }
            RtpRtcp* RtpRtcpModulePtr() const { return _rtpRtcpModule.get(); }
            int8_t OutputEnergyLevel() const { return _recvAudioLevel.Level(); }
            uint32_t Demultiplex(const AudioFrame& audioFrame);
            // Demultiplex the data to the channel's |_audioFrame|. The difference
            // between this method and the overloaded method above is that |audio_data|
            // does not go through transmit_mixer and APM.
            void Demultiplex(const int16_t* audio_data,
                int sample_rate,
                size_t number_of_frames,
                size_t number_of_channels);
            uint32_t PrepareEncodeAndSend(int mixingFrequency);
            uint32_t EncodeAndSend();

            // Associate to a send channel.
            // Used for obtaining RTT for a receive-only channel.
            void set_associate_send_channel(const ChannelOwner& channel);
            // Disassociate a send channel if it was associated.
            void DisassociateSendChannel(int channel_id);

            // Set a RtcEventLog logging object.
            void SetRtcEventLog(RtcEventLog* event_log);

            void SetRtcpRttStats(RtcpRttStats* rtcp_rtt_stats);
            void SetTransportOverhead(size_t transport_overhead_per_packet);

            // From OverheadObserver in the RTP/RTCP module
            void OnOverheadChanged(size_t overhead_bytes_per_packet) override;

        protected:
            void OnIncomingFractionLoss(int fraction_lost);

        private:
            bool ReceivePacket(const uint8_t* packet,
                size_t packet_length,
                const RTPHeader& header,
                bool in_order);
            bool HandleRtxPacket(const uint8_t* packet,
                size_t packet_length,
                const RTPHeader& header);
            bool IsPacketInOrder(const RTPHeader& header) const;
            bool IsPacketRetransmitted(const RTPHeader& header, bool in_order) const;
            int ResendPackets(const uint16_t* sequence_numbers, int length);
            void UpdatePlayoutTimestamp(bool rtcp);
            void RegisterReceiveCodecsToRTPModule();

            int SetSendRtpHeaderExtension(bool enable,
                RTPExtensionType type,
                unsigned char id);

            void UpdateOverheadForEncoder();

            int GetRtpTimestampRateHz() const;
            int64_t GetRTT(bool allow_associate_channel) const;

            rtc::CriticalSection _fileCritSect;
            rtc::CriticalSection _callbackCritSect;
            rtc::CriticalSection volume_settings_critsect_;
            uint32_t _instanceId;
            int32_t _channelId;

            ChannelState channel_state_;

            std::unique_ptr<vose::RtcEventLogProxy> event_log_proxy_;
            std::unique_ptr<vose::RtcpRttStatsProxy> rtcp_rtt_stats_proxy_;

            std::unique_ptr<RtpHeaderParser> rtp_header_parser_;
            std::unique_ptr<RTPPayloadRegistry> rtp_payload_registry_;
            std::unique_ptr<ReceiveStatistics> rtp_receive_statistics_;
            std::unique_ptr<StatisticsProxy> statistics_proxy_;
            std::unique_ptr<RtpReceiver> rtp_receiver_;
            TelephoneEventHandler* telephone_event_handler_;
            std::unique_ptr<RtpRtcp> _rtpRtcpModule;
            std::unique_ptr<AudioCodingModule> audio_coding_;
            acm2::CodecManager codec_manager_;
            acm2::RentACodec rent_a_codec_;
            std::unique_ptr<AudioSinkInterface> audio_sink_;
            voe::AudioLevel _recvAudioLevel;
            bool _externalTransport;
            AudioFrame _audioFrame;
            // Downsamples to the codec rate if necessary.
            PushResampler<int16_t> input_resampler_;
            std::unique_ptr<FilePlayer> local_file_player_;
            std::unique_ptr<FileRecorder> send_file_recorder_;
            std::unique_ptr<FileRecorder> recv_file_recorder_;
            bool _localFileSending;
            int _localFilePlayerId;
            int _sendFileRecorderId;
            bool _sendFileRecording;
            int _recvFileRecorderId;
            bool _recvFileRecording;
            bool _outputExternalMedia;
//             VosEMediaProcess* _inputExternalMediaCallbackPtr;
//             VosEMediaProcess* _outputExternalMediaCallbackPtr;
            uint32_t _timeStamp;

            RemoteNtpTimeEstimator ntp_estimator_ GUARDED_BY(ts_stats_lock_);

            // Timestamp of the audio pulled from NetEq.
            rtc::Optional<uint32_t> jitter_buffer_playout_timestamp_;
            uint32_t playout_timestamp_rtp_ GUARDED_BY(video_sync_lock_);
            uint32_t playout_timestamp_rtcp_;
            uint32_t playout_delay_ms_ GUARDED_BY(video_sync_lock_);
            uint32_t _numberOfDiscardedPackets;
            uint16_t send_sequence_number_;
            uint8_t restored_packet_[kVoiceEngineMaxIpPacketSizeBytes];

            rtc::CriticalSection ts_stats_lock_;

            std::unique_ptr<rtc::TimestampWrapAroundHandler> rtp_ts_wraparound_handler_;
            // The rtp timestamp of the first played out audio frame.
            int64_t capture_start_rtp_time_stamp_;
            // The capture ntp time (in local timebase) of the first played out audio
            // frame.
            int64_t capture_start_ntp_time_ms_ GUARDED_BY(ts_stats_lock_);

            // uses
            voe::Statistics* _engineStatisticsPtr;
            ServerConferenceMixer* _serverConferenceMixerPtr;
            ProcessThread* _moduleProcessThreadPtr;
            VoiceServerEngineObserver* _voiceEngineObserverPtr;  // owned by base
            rtc::CriticalSection* _callbackCritSectPtr;    // owned by base
            Transport* _transportPtr;  // WebRtc socket or external transport
            RmsLevel rms_level_;
            int32_t _sendFrameType;  // Send data is voice, 1-voice, 0-otherwise
                                     // VoEBase
            bool _externalMixing;
            // VoEVolumeControl
            bool input_mute_ GUARDED_BY(volume_settings_critsect_);
            bool previous_frame_muted_;  // Only accessed from PrepareEncodeAndSend().
            float _panLeft GUARDED_BY(volume_settings_critsect_);
            float _panRight GUARDED_BY(volume_settings_critsect_);
            float _outputGain GUARDED_BY(volume_settings_critsect_);

            // VoeRTP_RTCP
            uint32_t _lastLocalTimeStamp;
            int8_t _lastPayloadType;
            bool _includeAudioLevelIndication;
            size_t transport_overhead_per_packet_;
            size_t rtp_overhead_per_packet_;

            // VoENetwork
            AudioFrame::SpeechType _outputSpeechType;

            // VoEVideoSync
            rtc::CriticalSection video_sync_lock_;

            // VoEAudioProcessing
            bool restored_packet_in_use_;

            // RtcpBandwidthObserver
            std::unique_ptr<VosERtcpObserver> rtcp_observer_;

            // An associated send channel.
            rtc::CriticalSection assoc_send_channel_lock_;
            ChannelOwner associate_send_channel_ GUARDED_BY(assoc_send_channel_lock_);

            bool pacing_enabled_;
            PacketRouter* packet_router_ = nullptr;
            std::unique_ptr<TransportFeedbackProxy> feedback_observer_proxy_;
            std::unique_ptr<TransportSequenceNumberProxy> seq_num_allocator_proxy_;
            std::unique_ptr<RtpPacketSenderProxy> rtp_packet_sender_proxy_;
            std::unique_ptr<RateLimiter> retransmission_rate_limiter_;

            // TODO(ossu): Remove once GetAudioDecoderFactory() is no longer needed.
            rtc::scoped_refptr<AudioDecoderFactory> decoder_factory_;
        };

    }  // namespace voe
}  // namespace webrtc

#endif  // WEBRTC_VOICE_ENGINE_CHANNEL_H_
