#ifndef WEBRTC_VOICE_SERVER_ENGINE_VOSE_FILE_H
#define WEBRTC_VOICE_SERVER_ENGINE_VOSE_FILE_H

#include "webrtc/common_types.h"

namespace webrtc
{
    class VoiceServerEngine;

    class WEBRTC_DLLEXPORT VosEFile
    {
    public:
        // Factory for the VoEFile sub-API. Increases an internal
        // reference counter if successful. Returns NULL if the API is not
        // supported or if construction fails.
        static VosEFile* GetInterface(VoiceServerEngine* voiceEngine);

        // Releases the VoEFile sub-API and decreases an internal
        // reference counter. Returns the new reference count. This value should
        // be zero for all sub-API:s before the VoiceEngine object can be safely
        // deleted.
        virtual int Release() = 0;

        // Starts read voice data from local file and sending to remote
        virtual int StartSendingFileLocally(
            int channel,
            const char fileNameUTF8[1024],
            bool loop = false,
            FileFormats format = kFileFormatPcm16kHzFile,
            float volumeScaling = 1.0,
            int startPointMs = 0,
            int stopPointMs = 0) = 0;

        // Starts read voice data from local file and sending to remote
        virtual int StartSendingFileLocally(
            int channel,
            InStream* stream,
            FileFormats format = kFileFormatPcm16kHzFile,
            float volumeScaling = 1.0,
            int startPointMs = 0,
            int stopPointMs = 0) = 0;

        // Stops playback of a file on a specific |channel|.
        virtual int StopSendingFileLocally(int channel) = 0;

        // Returns the current file playing state for a specific |channel|.
        virtual int IsSendingFileLocally(int channel) = 0;

        // Starts recording the voice data send to remote.
        virtual int StartRecordingSend(int channel,
            const char* fileNameUTF8,
            CodecInst* compression = NULL,
            int maxSizeBytes = -1) = 0;

        // Stops recording the voice data send to remote.
        virtual int StopRecordingSend(int channel) = 0;

        virtual int StartRecordingSend(int channel,
            OutStream* stream,
            CodecInst* compression = NULL) = 0;

        // Starts recording the microphone signal to a file.
        virtual int StartRecordingRecv(int channel, 
            const char* fileNameUTF8,
            CodecInst* compression = NULL,
            int maxSizeBytes = -1) = 0;

        // Starts recording the microphone signal to a stream.
        virtual int StartRecordingRecv(int channel,
            OutStream* stream,
            CodecInst* compression = NULL) = 0;

        // Stops recording the microphone signal.
        virtual int StopRecordingRecv(int channel) = 0;

    protected:
        VosEFile() {}
        virtual ~VosEFile() {}
    };

}  // namespace webrtc

#endif  // WEBRTC_VOICE_ENGINE_VOE_FILE_H
