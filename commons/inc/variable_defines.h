#pragma once

#include <stdint.h>

namespace vcs
{
// time related
const uint32_t HEARTBEAT_TIMEOUT_IN_MICRO = 15000000;
const uint32_t HEARTBEAT_SEND_INTERVAL_IN_MICRO = 2000000;
const uint32_t RPC_CALL_TIMEOUT_IN_SECOND = 6;
const uint32_t RPC_CALL_TIMEOUT_IN_MILLI = 6000;

const int64_t STATISTICS_INTERVAL = 5000000; // micro seconds.

const std::string STATISTIC_DB = "vcs_statistics";
const std::string ROOM_MEASURE_POSTFIX = "room";
const std::string VOICE_MEASURE_POSTFIX = "voice";
const std::string VIDEO_MEASURE_POSTFIX = "video";
const std::string CALL_MEASURE_POSTFIX = "call";

const std::string CODEC_FIELD = "codec";
const std::string AVERAGE_JITTER_FIELD = "average_jitter";
const std::string MAX_JITTER_FIELD = "max_jitter";
const std::string FRACTION_LOST_FIELD = "fraction_lost";
const std::string CUMULATIVE_LOST_FIELD = "cumulative_lost";
const std::string RTT_FIELD = "rtt";
const std::string BYTES_SENT_FIELD = "bytes_sent";
const std::string BYTES_RECEIVED_FIELD = "bytes_received";

const std::string FRAMERATE_FIELD = "fps";
const std::string BITRATE_FIELD = "bitrate";
const std::string FEC_BITRATE_FIELD = "fec_bitrate";
const std::string LOSSRATE_FIELD = "loss_rate";
const std::string TAG_SSRC = "ssrc";
const std::string TAG_USER = "user";

//ROOM measure fields
const std::string ROOM_ID_FIELD = "id";
const std::string ROOM_NAME_FIELD = "name";
const std::string ROOM_BEGIN_TIME_FIELD = "begin_time";
const std::string ROOM_LAST_TIME_FIELD = "last_times";
const std::string ROOM_MAX_PARTIES_FIELD = "max_parties";
const std::string TAG_SERVICE_NODE = "node";

//CALL measure fields
const std::string CALL_JOIN_FIELD = "join";
const std::string CALL_LEAVE_FIELD = "leave";
}
