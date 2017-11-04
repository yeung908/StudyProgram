#include "webrtc/base/checks.h"
#include "webrtc/modules/audio_coding/include/audio_coding_module.h"
#include "webrtc/system_wrappers/include/trace.h"
#include "webrtc/voice_server_engine/voice_server_engine_impl.h"

namespace webrtc
{

    // Counter to be ensure that we can add a correct ID in all static trace
    // methods. It is not the nicest solution, especially not since we already
    // have a counter in VoEBaseImpl. In other words, there is room for
    // improvement here.
    static int32_t gVoiceServerEngineInstanceCounter = 0;

    VoiceServerEngine* GetVoiceServerEngine()
    {
        VoiceServerEngineImpl* self = new VoiceServerEngineImpl();
        if (self != NULL) {
            self->AddRef();  // First reference.  Released in VoiceServerEngine::Delete.
            gVoiceServerEngineInstanceCounter++;
        }
        return self;
    }

    int VoiceServerEngineImpl::AddRef()
    {
        return ++_ref_count;
    }

    // This implements the Release() method for all the inherited interfaces.
    int VoiceServerEngineImpl::Release()
    {
        int new_ref = --_ref_count;
        assert(new_ref >= 0);
        if (new_ref == 0) {
            WEBRTC_TRACE(kTraceApiCall, kTraceVoice, -1,
                "VoiceServerEngineImpl self deleting (VoiceServerEngine=0x%p)", this);

            // Clear any pointers before starting destruction. Otherwise worker-
            // threads will still have pointers to a partially destructed object.
            // Example: AudioDeviceBuffer::RequestPlayoutData() can access a
            // partially deconstructed |_ptrCbAudioTransport| during destruction
            // if we don't call Terminate here.
            Terminate();
            delete this;
        }

        return new_ref;
    }

    VoiceServerEngine* VoiceServerEngine::Create()
    {
        return GetVoiceServerEngine();
    }

    int VoiceServerEngine::SetTraceFilter(unsigned int filter)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice,
            VoEId(gVoiceServerEngineInstanceCounter, -1),
            "SetTraceFilter(filter=0x%x)", filter);

        // Remember old filter
        uint32_t oldFilter = Trace::level_filter();
        Trace::set_level_filter(filter);

        // If previous log was ignored, log again after changing filter
        if (kTraceNone == oldFilter) {
            WEBRTC_TRACE(kTraceApiCall, kTraceVoice, -1, "SetTraceFilter(filter=0x%x)",
                filter);
        }

        return 0;
    }

    int VoiceServerEngine::SetTraceFile(const char* fileNameUTF8, bool addFileCounter)
    {
        int ret = Trace::SetTraceFile(fileNameUTF8, addFileCounter);
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice,
            VoEId(gVoiceServerEngineInstanceCounter, -1),
            "SetTraceFile(fileNameUTF8=%s, addFileCounter=%d)", fileNameUTF8,
            addFileCounter);
        return (ret);
    }

    int VoiceServerEngine::SetTraceCallback(TraceCallback* callback)
    {
        WEBRTC_TRACE(kTraceApiCall, kTraceVoice,
            VoEId(gVoiceServerEngineInstanceCounter, -1),
            "SetTraceCallback(callback=0x%x)", callback);
        return (Trace::SetTraceCallback(callback));
    }

    bool VoiceServerEngine::Delete(VoiceServerEngine*& VoiceServerEngine)
    {
        if (VoiceServerEngine == NULL)
            return false;

        VoiceServerEngineImpl* s = static_cast<VoiceServerEngineImpl*>(VoiceServerEngine);
        // Release the reference that was added in GetVoiceServerEngine.
        int ref = s->Release();
        VoiceServerEngine = NULL;

        if (ref != 0) {
            WEBRTC_TRACE(
                kTraceWarning, kTraceVoice, -1,
                "VoiceServerEngine::Delete did not release the very last reference.  "
                "%d references remain.",
                ref);
        }

        return true;
    }

    std::string VoiceServerEngine::GetVersionString()
    {
        std::string version = "VoiceServerEngine 4.1.0";
#ifdef WEBRTC_EXTERNAL_TRANSPORT
        version += " (External transport build)";
#endif
        return version;
    }

}  // namespace webrtc