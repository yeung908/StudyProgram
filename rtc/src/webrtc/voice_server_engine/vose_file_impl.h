#ifndef WEBRTC_VOICE_SERVER_ENGINE_VOSE_FILE_IMPL_H_
#define WEBRTC_VOICE_SERVER_ENGINE_VOSE_FILE_IMPL_H_
#include "webrtc/voice_server_engine/include/vose_file.h"

namespace webrtc
{
    namespace vose
    {
        class SharedData;
    }
    class VosEFileImpl : public  VosEFile
    {
    public:

        virtual int Release() override;

        virtual int StartSendingFileLocally(int channel, const char fileNameUTF8[1024], bool loop = false, FileFormats format = kFileFormatPcm16kHzFile, float volumeScaling = 1.0, int startPointMs = 0, int stopPointMs = 0) override;

        virtual int StartSendingFileLocally(int channel, InStream* stream, FileFormats format = kFileFormatPcm16kHzFile, float volumeScaling = 1.0, int startPointMs = 0, int stopPointMs = 0) override;

        virtual int StopSendingFileLocally(int channel) override;

        virtual int IsSendingFileLocally(int channel) override;

        virtual int StartRecordingSend(int channel, const char* fileNameUTF8, CodecInst* compression = NULL, int maxSizeBytes = -1) override;

        virtual int StartRecordingSend(int channel, OutStream* stream, CodecInst* compression = NULL) override;

        virtual int StopRecordingSend(int channel) override;

        virtual int StartRecordingRecv(int channel, const char* fileNameUTF8, CodecInst* compression = NULL, int maxSizeBytes = -1) override;

        virtual int StartRecordingRecv(int channel, OutStream* stream, CodecInst* compression = NULL) override;

        virtual int StopRecordingRecv(int channel) override;
    protected:
        VosEFileImpl(vose::SharedData* shared);
        ~VosEFileImpl() override;

    private:
        vose::SharedData* _shared;
    };
}

#endif