#include "webrtc/voice_server_engine/vose_file_impl.h"

#include "webrtc/system_wrappers/include/file_wrapper.h"
#include "webrtc/system_wrappers/include/trace.h"
#include "webrtc/voice_server_engine/channel.h"
#include "webrtc/voice_engine/include/voe_errors.h"
#include "webrtc/voice_server_engine/voice_server_engine_impl.h"

namespace webrtc
{
    VosEFile* VosEFile::GetInterface(VoiceServerEngine* voiceEngine)
    {
        if (NULL == voiceEngine) {
            return NULL;
        }
        VoiceServerEngineImpl* s = static_cast<VoiceServerEngineImpl*>(voiceEngine);
        s->AddRef();
        return s;
    }

    int VosEFileImpl::Release()
    {
        throw std::logic_error("The method or operation is not implemented.");
    }

    int VosEFileImpl::StartSendingFileLocally(int channel, const char fileNameUTF8[1024], bool loop /*= false*/, FileFormats format /*= kFileFormatPcm16kHzFile*/, float volumeScaling /*= 1.0*/, int startPointMs /*= 0*/, int stopPointMs /*= 0*/)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "StartPlayingFileLocally(channel=%d, fileNameUTF8[]=%s, "
            "loop=%d, format=%d, volumeScaling=%5.3f, startPointMs=%d,"
            " stopPointMs=%d)",
            channel, fileNameUTF8, loop, format, volumeScaling, startPointMs,
            stopPointMs);
        static_assert(1024 == FileWrapper::kMaxFileNameSize, "");
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }               
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StartSendingFileLocally() failed to locate channel");
            return -1;
        }

        return channelPtr->StartSendingFileLocally(fileNameUTF8, loop, format,
            volumeScaling, startPointMs, stopPointMs);
    }

    int VosEFileImpl::StopSendingFileLocally(int channel)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "StopSendingFileLocally(channel=%d)", channel);
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StopSendingFileLocally() failed to locate channel");
            return -1;
        }

        return channelPtr->StopSendingFileLocally();
    }

    int VosEFileImpl::IsSendingFileLocally(int channel)
    {
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "IsSendingFileLocally() failed to locate channel");
            return -1;
        }

        return channelPtr->IsSendingFileLocally();
    }

    int VosEFileImpl::StartRecordingSend(int channel, const char* fileNameUTF8, CodecInst* compression /*= NULL*/, int maxSizeBytes /*= -1*/)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "StartRecordingSend(channel=%d, fileNameUTF8[]=%s," 
            "CodecInst=%x, maxSizeBytes=%d)",
            channel, fileNameUTF8, compression, maxSizeBytes);
        static_assert(1024 == FileWrapper::kMaxFileNameSize, "");
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StartRecordingSend() failed to locate channel");
            return -1;
        }

        return channelPtr->StartRecordingSend(fileNameUTF8, compression, maxSizeBytes);
    }

    int VosEFileImpl::StartRecordingSend(int channel, OutStream* stream, CodecInst* compression /*= NULL*/)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "StartRecordingSend(channel=%d, stream=%x,"
            "CodecInst=%x)", channel, stream, compression);
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StartRecordingSend() failed to locate channel");
            return -1;
        }

        return channelPtr->StartRecordingSend(stream, compression);
    }

    int VosEFileImpl::StopRecordingSend(int channel)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "StopRecordingSend(channel=%d",channel);
        static_assert(1024 == FileWrapper::kMaxFileNameSize, "");
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StopRecordingSend() failed to locate channel");
            return -1;
        }

        return channelPtr->StopRecordingSend();
    }

    int VosEFileImpl::StartRecordingRecv(int channel, const char* fileNameUTF8, CodecInst* compression /*= NULL*/, int maxSizeBytes /*= -1*/)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "StartRecordingSend(channel=%d, fileNameUTF8[]=%s,"
            "CodecInst=%x)", channel, fileNameUTF8, compression);
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StartRecordingSend() failed to locate channel");
            return -1;
        }

        return channelPtr->StartRecordingRecv(fileNameUTF8, compression);
    }

    int VosEFileImpl::StopRecordingRecv(int channel)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "StopRecordingRecv(channel=%d)", channel);
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StartRecordingSend() failed to locate channel");
            return -1;
        }

        return channelPtr->StopRecordingRecv();
    }

    VosEFileImpl::VosEFileImpl(vose::SharedData* shared)
        :_shared(shared)
    {
        WEBRTC_TRACE(kTraceMemory, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "VosEFileImpl::VosEFileImpl() - ctor");
    }

    VosEFileImpl::~VosEFileImpl()
    {
        WEBRTC_TRACE(kTraceMemory, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "VosEFileImpl::~VosEFileImpl() - dtor");
    }

    int VosEFileImpl::StartRecordingRecv(int channel, OutStream* stream, CodecInst* compression /*= NULL*/)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "StartRecordingSend(channel=%d, OutStream=%x,"
            "CodecInst=%x)", channel, stream, compression);
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StartRecordingSend() failed to locate channel");
            return -1;
        }

        return channelPtr->StartRecordingRecv(stream, compression);
    }

    int VosEFileImpl::StartSendingFileLocally(int channel, InStream* stream, FileFormats format /*= kFileFormatPcm16kHzFile*/, float volumeScaling /*= 1.0*/, int startPointMs /*= 0*/, int stopPointMs /*= 0*/)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice, VoEId(_shared->instance_id(), -1),
            "StartPlayingFileLocally(channel=%d, InStream=%x, "
            " format=%d, volumeScaling=%5.3f, startPointMs=%d,"
            " stopPointMs=%d)",channel, stream, format, volumeScaling, startPointMs,
            stopPointMs);
        static_assert(1024 == FileWrapper::kMaxFileNameSize, "");
        if (!_shared->statistics().Initialized()) {
            _shared->SetLastError(VE_NOT_INITED, kTraceError);
            return -1;
        }
        vose::ChannelOwner ch = _shared->channel_manager().GetChannel(channel);
        vose::Channel* channelPtr = ch.channel();
        if (channelPtr == NULL) {
            _shared->SetLastError(VE_CHANNEL_NOT_VALID, kTraceError,
                "StartSendingFileLocally() failed to locate channel");
            return -1;
        }

        return channelPtr->StartSendingFileLocally(stream, format, volumeScaling, startPointMs, stopPointMs);
    }

}

