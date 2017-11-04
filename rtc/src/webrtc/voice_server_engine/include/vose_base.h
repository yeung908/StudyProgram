#ifndef WEBRTC_VOICE_SERVER_ENGING_VOSE_BASE_H
#define WEBRTC_VOICE_SERVER_ENGING_VOSE_BASE_H

#include "webrtc/base/scoped_ref_ptr.h"
#include "webrtc/modules/audio_coding/codecs/audio_decoder_factory.h"
#include "webrtc/modules/audio_coding/include/audio_coding_module.h"
#include "webrtc/common_types.h"

namespace webrtc
{
    // VoiceServerEngineObserver
    class WEBRTC_DLLEXPORT VoiceServerEngineObserver
    {
    public:
        // This method will be called after the occurrence of any runtime error
        // code, or warning notification, when the observer interface has been
        // installed using VosEBase::RegisterVoiceServerEngineObserver().
        virtual void CallbackOnError(int channel, int errCode) = 0;

    protected:
        virtual ~VoiceServerEngineObserver() {}
    };

    class WEBRTC_DLLEXPORT VoiceServerEngine
    {
    public:
        // Creates a VoiceEngine object, which can then be used to acquire
        // sub-APIs. Returns NULL on failure.
        static VoiceServerEngine* Create();

        // Deletes a created VoiceEngine object and releases the utilized resources.
        // Note that if there are outstanding references held via other interfaces,
        // the voice engine instance will not actually be deleted until those
        // references have been released.
        static bool Delete(VoiceServerEngine*& voiceEngine);

        // Specifies the amount and type of trace information which will be
        // created by the VoiceEngine.
        static int SetTraceFilter(unsigned int filter);

        // Sets the name of the trace file and enables non-encrypted trace messages.
        static int SetTraceFile(const char* fileNameUTF8,
            bool addFileCounter = false);

        // Installs the TraceCallback implementation to ensure that the user
        // receives callbacks for generated trace messages.
        static int SetTraceCallback(TraceCallback* callback);

        static std::string GetVersionString();

    protected:
        VoiceServerEngine() {}
        ~VoiceServerEngine() {}
    };

    class WEBRTC_DLLEXPORT VosEBase
    {
    public:
        struct ChannelConfig
        {
            AudioCodingModule::Config acm_config;
            bool enable_voice_pacing = false;
        };

        // Factory for the VosEBase sub-API. Increases an internal reference
        // counter if successful. Returns NULL if the API is not supported or if
        // construction fails.
        static VosEBase* GetInterface(VoiceServerEngine* voiceEngine);

        // Releases the VosEBase sub-API and decreases an internal reference
        // counter. Returns the new reference count. This value should be zero
        // for all sub-APIs before the VoiceEngine object can be safely deleted.
        virtual int Release() = 0;

        // Installs the observer class to enable runtime error control and
        // warning notifications. Returns -1 in case of an error, 0 otherwise.
        virtual int RegisterEngineObserver(VoiceServerEngineObserver& observer) = 0;

        // Removes and disables the observer class for runtime error control
        // and warning notifications. Returns 0.
        virtual int DeRegisterEngineObserver() = 0;

        // Initializes all common parts of the VoiceEngine; e.g. all
        // encoders/decoders, the sound card and core receiving components.
        // This method also makes it possible to install some user-defined external
        // modules:
        // - The Audio Device Module (ADM) which implements all the audio layer
        // functionality in a separate (reference counted) module.
        // - The AudioProcessing module handles capture-side processing. VoiceEngine
        // takes ownership of this object.
        // - An AudioDecoderFactory - used to create audio decoders.
        // If NULL is passed for any of these, VoiceEngine will create its own.
        // Returns -1 in case of an error, 0 otherwise.
        // TODO(ajm): Remove default NULLs.
        virtual int Init(
            const rtc::scoped_refptr<AudioDecoderFactory>&
            decoder_factory = nullptr) = 0;

        // Terminates all VoiceEngine functions and releases allocated resources.
        // Returns 0.
        virtual int Terminate() = 0;

        virtual int CreateServerMixer() = 0;

        virtual int DeleteServerMixer(int mixer) = 0;

        virtual int AddChannel2Mixer(int channel, int mixer) = 0;

        virtual int RemoveChannel4Mixer(int channel) = 0;

        // Creates a new channel and allocates the required resources for it.
        // The second version accepts a |config| struct which includes an Audio Coding
        // Module config and an option to enable voice pacing. Note that the
        // decoder_factory member of the ACM config will be ignored (the decoder
        // factory set through Init() will always be used).
        // Returns channel ID or -1 in case of an error.
        virtual int CreateChannel() = 0;
        virtual int CreateChannel(const ChannelConfig& config) = 0;

        // Deletes an existing channel and releases the utilized resources.
        // Returns -1 in case of an error, 0 otherwise.
        virtual int DeleteChannel(int channel) = 0;

        // Prepares and initiates the VoiceEngine for reception of
        // incoming RTP/RTCP packets on the specified |channel|.
        virtual int StartReceive(int channel) = 0;

        // Stops receiving incoming RTP/RTCP packets on the specified |channel|.
        virtual int StopReceive(int channel) { return 0; }

        // Starts sending packets to an already specified IP address and
        // port number for a specified |channel|.
        virtual int StartSend(int channel) = 0;

        // Stops sending packets from a specified |channel|.
        virtual int StopSend(int channel) = 0;

        // Gets the version information for VoiceEngine and its components.
        virtual int GetVersion(char version[1024]) = 0;

        // Gets the last VoiceEngine error code.
        virtual int LastError() = 0;

        // Associate a send channel to a receive channel.
        // Used for obtaining RTT for a receive-only channel.
        // One should be careful not to crate a circular association, e.g.,
        // 1 <- 2 <- 1.
        virtual int AssociateSendChannel(int channel, int accociate_send_channel) = 0;

    protected:
        VosEBase() {}
        virtual ~VosEBase() {}
    };
}


#endif //WEBRTC_VOICE_SERVER_ENGING_VOSE_BASE_H