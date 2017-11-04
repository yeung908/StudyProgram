#pragma once
#include <cstdint>
#include <string>

namespace vcs
{
struct EndpointAddr
{
    std::string host;
    uint16_t port;
};

enum SSRC_RESERVE
{
    SSRC_MIXER = 199,
    SSRC_RESERVE_MAX = 499
};

enum SSRC_MEDIA
{
    SSRC_AUDIO = 0,
    SSRC_VIDEO,
    SSRC_VIDEO_FEC,
    SSRC_DESKTOP,
    SSRC_DESKTOP_FEC,
    SSRC_MEDIA_NUMBER
};
}
