#pragma once

#include <stdint.h>

namespace vcs
{
enum MediaStatus
{
    STATUS_NONE = 0,
    STATUS_MUTE_MIC = 1,
    STATUS_MUTE_SPEAKER = 1 << 1,
    STATUS_SEND_AUDIO = 1 << 2,
    STATUS_SEND_VIDEO = 1 << 3,
    STATUS_SEND_DESKTOP = 1 << 4,
    STATUS_RECV_AUDIO = 1 << 5,
    STATUS_RECV_VIDEO = 1 << 6,
    STATUS_RECV_DESKTOP = 1 << 7
};

inline void AppendStatus(int32_t &status, MediaStatus ms) { status |= ms; }
inline void SubstractStatus(int32_t &status, MediaStatus ms) { status &= ~ms; }

inline void AppendAudioSendingStatus(int32_t &status) { AppendStatus(status, STATUS_SEND_AUDIO); }
inline void AppendVideoSendingStatus(int32_t &status) { AppendStatus(status, STATUS_SEND_VIDEO); }
inline void AppendDesktopSendingStatus(int32_t &status) { AppendStatus(status, STATUS_SEND_DESKTOP); }
inline void AppendAudioReceivingStatus(int32_t &status) { AppendStatus(status, STATUS_RECV_AUDIO); }
inline void AppendVideoReceivingStatus(int32_t &status) { AppendStatus(status, STATUS_RECV_VIDEO); }
inline void AppendDesktopReceivingStatus(int32_t &status) { AppendStatus(status, STATUS_RECV_DESKTOP); }

inline void SubstractAudioSendingStatus(int32_t &status) { SubstractStatus(status, STATUS_SEND_AUDIO); }
inline void SubstractVideoSendingStatus(int32_t &status) { SubstractStatus(status, STATUS_SEND_VIDEO); }
inline void SubstractDesktopSendingStatus(int32_t &status) { SubstractStatus(status, STATUS_SEND_DESKTOP); }
inline void SubstractAudioReceivingStatus(int32_t &status) { SubstractStatus(status, STATUS_RECV_AUDIO); }
inline void SubstractVideoReceivingStatus(int32_t &status) { SubstractStatus(status, STATUS_RECV_VIDEO); }
inline void SubstractDesktopReceivingStatus(int32_t &status) { SubstractStatus(status, STATUS_RECV_DESKTOP); }

inline bool AudioSending(int32_t status) { return (status&STATUS_SEND_AUDIO) != 0; }
inline bool VideoSending(int32_t status) { return (status&STATUS_SEND_VIDEO) != 0; }
inline bool DesktopSending(int32_t status) { return (status&STATUS_SEND_DESKTOP) != 0; }
inline bool AudioReceiving(int32_t status) { return (status&STATUS_RECV_AUDIO) != 0; }
inline bool VideoReceiving(int32_t status) { return (status&STATUS_RECV_VIDEO) != 0; }
inline bool DesktopReceiving(int32_t status) { return (status&STATUS_RECV_DESKTOP) != 0; }

inline bool AudioEnable(int32_t status) { return AudioSending(status) || AudioReceiving(status); }
inline bool VideoEnable(int32_t status) { return VideoSending(status) || VideoReceiving(status); }
inline bool DesktopEnable(int32_t status) { return DesktopSending(status) || DesktopReceiving(status); }
}
