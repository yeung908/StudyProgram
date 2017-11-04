#include <gtest/gtest.h>
#include "webrtc/voice_server_engine/include/vose_base.h"
#include "webrtc/voice_server_engine/include/vose_codec.h"
#include "webrtc/voice_server_engine/include/vose_network.h"
#include "webrtc/voice_server_engine/include/vose_rtp_rtcp.h"
#include "webrtc/voice_server_engine/include/vose_file.h"
#include "webrtc/voice_engine/test/channel_transport/server_channel_transport.h"

using webrtc::VoiceServerEngine;
using webrtc::VosEBase;
using webrtc::VosECodec;
using webrtc::VosENetwork;
using webrtc::VosERTP_RTCP;
using webrtc::VosEFile;

namespace webrtc
{
    namespace test
    {
        void RunHarness()
        {
            VoiceServerEngine* vose = VoiceServerEngine::Create();
            ASSERT_TRUE(vose != NULL);
            VosEBase* base = VosEBase::GetInterface(vose);
            ASSERT_TRUE(base != NULL);
            VosECodec* codec = VosECodec::GetInterface(vose);
            ASSERT_TRUE(codec != NULL);
            VosENetwork* network = VosENetwork::GetInterface(vose);
            ASSERT_TRUE(network != NULL);
            VosEFile* file = VosEFile::GetInterface(vose);
            ASSERT_TRUE(file != NULL);

            ASSERT_EQ(0, base->Init());
            int mixer = base->CreateServerMixer();
            for (auto i = 0; i < 5; i++) {
                int channel = base->CreateChannel();
                ASSERT_NE(-1, channel);
                VoiceServerChannelTransport *voice_channel_transport(
                    new VoiceServerChannelTransport(network, channel));
                ASSERT_EQ(0, voice_channel_transport->SetSendDestination("127.0.0.1", 1234 + 2*i));
                ASSERT_EQ(0, voice_channel_transport->SetLocalReceiver(1234 + 2*i));
                CodecInst codec_params = { 0 };
                bool codec_found = false;
                for (int i = 0; i < codec->NumOfCodecs(); i++) {
                    ASSERT_EQ(0, codec->GetCodec(i, codec_params));
                    if (strcmp("ISAC", codec_params.plname) == 0 &&
                        16000 == codec_params.plfreq) {
                        codec_found = true;
                        break;
                    }
                }
                ASSERT_TRUE(codec_found);
                ASSERT_EQ(0, codec->SetSendCodec(channel, codec_params));

                base->AddChannel2Mixer(channel, mixer);

                // Disable all audio processing.
                ASSERT_EQ(0, base->StartReceive(channel));
                ASSERT_EQ(0, base->StartSend(channel));
                char name[32] = {0};
                sprintf(name, "channel-%d.pcm", channel);
                ASSERT_EQ(0, file->StartRecordingSend(channel, name));
            }
            // Run forever...
            while (1) {
            }
        }
    }  // namespace test
}  // namespace webrtc
int main(int argc, char** argv)
{
    //google::ParseCommandLineFlags(&argc, &argv, true);
    webrtc::test::RunHarness();
}