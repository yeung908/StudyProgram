//    Module     | ErrorCode Range |        备注
// -------------:|:---------------:|: -----------------------------
// MediaSDK      |   10000~19999   | 应用端自定义错误码从15000开始
// WhiteBorad    |   20000~29999   |
// Signaling     |   30000~39999   | 1~16段为gRPC错误码 应用端自定义错误码从35000开始
// Audio Service |   40000~49000   |
// Video Service |   50000~59000   |
// Application   |   80000~89999   |
// MindLink      |   90000~99999   |

#pragma  once
#include <string>

const int VCE_FAILURE = -1;
const int VCE_OK = 0;

/*
 * gRPC error code
 */
const int VCE_CANCELLED = 1;
const int VCE_UNKNOWN = 2;
const int VCE_INVALID_ARGUMENT = 3;
const int VCE_DEADLINE_EXCEEDED = 4;
const int VCE_NOT_FOUND = 5;
const int VCE_ALREADY_EXISTS = 6;
const int VCE_PERMISSION_DENIED = 7;
const int VCE_RESOURCE_EXHAUSTED = 8;
const int VCE_FAILED_PRECONDITION = 9;
const int VCE_ABORTED = 10;
const int VCE_OUT_OF_RANGE = 11;
const int VCE_UNIMPLEMENTED = 12;
const int VCE_INTERNAL = 13;
const int VCE_UNAVAILABLE = 14;
const int VCE_DATA_LOSS = 15;
const int VCE_UNAUTHENTICATED = 16;

/*
 * MediaSDK
 */
const int VCE_INITIALIZE_FAILED = 10000;
const int VCE_NOT_INITIALIZED = 10001;
const int VCE_JVM_NOT_SETTING = 10002;
const int VCE_INTERFACE_UNAVAILABLE = 10003;               ///< 接口不适用于该媒体流
const int VCE_OPEN_FILE_FAILED = 10004;

const int VCE_INVALID_DEVICE = 11000;                      ///< 无效的设备
const int VCE_NO_AVALIBLE_AUDIO_INPUT_DEVICE = 11001;     ///< 没有可用的音频采集设备
const int VCE_NO_AVALIBLE_AUDIO_OUTPUT_DEVICE = 11002;     ///< 没有可用的音频播放设备
const int VCE_NO_AVALIBLE_VIDEO_INPUT_DEVICE = 11003;      ///< 没有可用的视频摄像头
const int VCE_NO_AVALIBLE_VIDEO_OUTPUT_DEVICE = 11004;

const int VCE_NO_STREAM = 12000;                  ///< 没有找到媒体流
const int VCE_START_AUDIO_INPUT_ERR = 12001;      ///< 打开音频输入流出错
const int VCE_START_AUDIO_OUTPUT_ERR = 12002;     ///< 打开音频输出流出错
const int VCE_STOP_AUDIO_INPUT_ERR = 12003;       ///< 停止音频输入流出错
const int VCE_STOP_AUDIO_OUTPUT_ERR = 12004;      ///< 停止音频输出流出错
const int VCE_NOT_PLAYING_AUDIO = 12005;
const int VCE_NOT_RECORDING_AUDIO = 12006;
const int VCE_NOT_PLAYING_VIDEO = 12007;
const int VCE_NOT_RECORDING_VIDEO = 12008;
const int VCE_NOT_PLAYING_DESKTOP = 12009;
const int VCE_NOT_RECORDING_DESKTOP = 12010;
const int VCE_AUDIO_IS_PLAYING = 12011;
const int VCE_AUDIO_IS_RECORDING = 12012;
const int VCE_VIDEO_IS_PLAYING = 12013;
const int VCE_VIDEO_IS_RECORDING = 12014;
const int VCE_DESKTOP_IS_PLAYING = 12015;
const int VCE_DESKTOP_IS_RECORDING = 12016;
const int VCE_NO_SUCH_VIDEO_PRVIWE = 12017;
const int VCE_CANNOT_RECORD_AUDIO = 12018;
const int VCE_CANNOT_RECORD_VIDEO = 12019;
const int VCE_CANNOT_RECORD_DESKTOP = 12020;
const int VCE_CANNOT_STOP_RECORD_AUDIO = 12021;
const int VCE_CANNOT_STOP_RECORD_VIDEO = 12022;
const int VCE_CANNOT_STOP_RECORD_DESKTOP = 12023;

/*
 * WhiteBorad
 */

const int VCE_VERIFY_CHN_FAILED = 20001;
const int VCE_VERIFY_ROOM_FAILED = 20002;
const int VCE_CHNS_NOT_IN_SAME_ROOM = 20003;

const int VCE_LOCK_SUCCESS = 20010;
const int VCE_LOCK_CONFLICT = 20011;
const int VCE_LOCK_REPEAT = 20012;
const int VCE_UNLOCK_SUCCESS = 20013;
const int VCE_UNLOCK_CONFLICT = 20014;
const int VCE_UNLOCK_UNKNOW = 20015;

const int VCE_SYNC_FAIL = 21000;    //下面是白板数据服务器的信令错误
const int VCE_LOCK_FAIL = 21001;
const int VCE_UNLOCK_FAIL = 21002;
const int VCE_NO_OTHERS_IN_ROOM = 21003;

const int VCE_DES_NO_AVALIBLE_DATA_API = 22001;      ///< 没有可用的数据API
const int VCE_DES_DATASEVER_ADDR_ERROR = 22002;      ///< 数据服务地址出错
const int VCE_DES_SEND_BUFFER_FULL = 22003;          ///< 数据发送缓冲区满，重试后如果还出错，一般是socket出问题了
const int VCE_DES_SOCKET_CLOSE = 22004;              ///< 服务端关闭了socket
const int VCE_DES_HEARTBEAT_TIMEOUT = 22005;         ///< 心跳超时，客户端关闭了socket
const int VCE_DES_SOCKET_FD_ERROR = 22006;           ///< 心跳超时，客户端关闭了socket

/*
 * Signaling
 */
// copy from protos/confservice/errcode.proto
const int VCE_AUTH_FAILED = 30000;
const int VCE_AUTH_NEEDED = 30001;
const int VCE_LOGINED_ON_OTHER = 30002;
const int VCE_NO_SUCH_USER = 30003;
const int VCE_AUTH_PWD_WRONG = 30004;
const int VCE_NEW_ROOM_FAILED = 30005;
const int VCE_NO_SUCH_ROOM = 30006;
const int VCE_HAS_IN_OTHER_ROOM = 30007;
const int VCE_NOT_IN_ANY_ROOM = 30008;
const int VCE_PHONE_HAS_REGISTED = 30009;
const int VCE_DB_FAILURE = 30010;
const int VCE_SEVICE_BUSY = 30011;
const int VCE_DESKTOP_IN_SHARING = 30012;
const int VCE_DESKTOP_NOT_IN_SHARING = 30013;
const int VCE_CANNOT_ENABLE_AUDIO = 30014;
const int VCE_CANNOT_ENABLE_VIDEO = 30015;

/*
 * Audio Service
 */
const int VCE_NO_SUCH_OBJ = 40000;
const int VCE_NO_SUCH_MIXER = 40001;
const int VCE_NO_SUCH_CHN = 40002;
const int VCE_MIXER_EXIST = 40003;
const int VCE_CHN_EXIST = 40004;

/*
 * Mindlinker
 */
const int VCE_ADDR_ERROR = 90000;
const int VCE_SIZE_NOT_ENOUGH = 90001;
const int VCE_SEND_BUFFER_FULL = 90002;
const int VCE_SOCKET_CLOSE = 90003;
const int VCE_HEARTBEAT_TIMEOUT = 90004;
const int VCE_NOT_LOGIN = 90005;
const int VCE_NOT_CONNECT = 90006;
const int VCE_NOT_IN_MEETING = 90007;
const int VCE_PROXY_FAIL = 90008;
const int VCE_PROXY_ERROR = 90009;
const int VCE_LOGIN_SOCKET_CLOSE = 90010;
const int VCE_LOGIN_HEARTBEAT_TIMEOUT = 90011;
const int VCE_TRANS_SOCKET_CLOSE = 90012;
const int VCE_TRANS_HEARTBEAT_TIMEOUT = 90013;

// Convenient function
std::string ErrorToString(const int error);
