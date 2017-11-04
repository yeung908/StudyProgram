#include "error.h"
#include <Poco/NumberFormatter.h>

std::string ErrorToString(const int error)
{
    switch (error)
    {
    case VCE_FAILURE:
        return "VCE_FAILURE";
        break;
    case VCE_OK:
        return "VCE_OK";
        break;
    case VCE_CANCELLED:
        return "VCE_CANCELLED";
        break;
    case VCE_UNKNOWN:
        return "VCE_UNKNOWN";
        break;
    case VCE_INVALID_ARGUMENT:
        return "VCE_INVALID_ARGUMENT";
        break;
    case VCE_DEADLINE_EXCEEDED:
        return "VCE_DEADLINE_EXCEEDED";
        break;
    case VCE_NOT_FOUND:
        return "VCE_NOT_FOUND";
        break;
    case VCE_ALREADY_EXISTS:
        return "VCE_ALREADY_EXISTS";
        break;
    case VCE_PERMISSION_DENIED:
        return "VCE_PERMISSION_DENIED";
        break;
    case VCE_RESOURCE_EXHAUSTED:
        return "VCE_RESOURCE_EXHAUSTED";
        break;
    case VCE_FAILED_PRECONDITION:
        return "VCE_FAILED_PRECONDITION";
        break;
    case VCE_ABORTED:
        return "VCE_ABORTED";
        break;
    case VCE_OUT_OF_RANGE:
        return "VCE_OUT_OF_RANGE";
        break;
    case VCE_UNIMPLEMENTED:
        return "VCE_UNIMPLEMENTED";
        break;
    case VCE_INTERNAL:
        return "VCE_INTERNAL";
        break;
    case VCE_UNAVAILABLE:
        return "VCE_UNAVAILABLE";
        break;
    case VCE_DATA_LOSS:
        return "VCE_DATA_LOSS";
        break;
    case VCE_UNAUTHENTICATED:
        return "VCE_UNAUTHENTICATED";
        break;
    case VCE_INITIALIZE_FAILED:
        return "VCE_INITIALIZE_FAILED";
        break;
    case VCE_NOT_INITIALIZED:
        return "VCE_NOT_INITIALIZED";
        break;
    case VCE_JVM_NOT_SETTING:
        return "VCE_JVM_NOT_SETTING";
        break;
    case VCE_INTERFACE_UNAVAILABLE:
        return "VCE_INTERFACE_UNAVAILABLE";
        break;
    case VCE_OPEN_FILE_FAILED:
        return "VCE_OPEN_FILE_FAILED";
        break;
    case VCE_INVALID_DEVICE:
        return "VCE_INVALID_DEVICE";
        break;
    case VCE_NO_AVALIBLE_AUDIO_INPUT_DEVICE:
        return "VCE_NO_AVALIBLE_AUDIO_INPUT_DEVICE";
        break;
    case VCE_NO_AVALIBLE_AUDIO_OUTPUT_DEVICE:
        return "VCE_NO_AVALIBLE_AUDIO_OUTPUT_DEVICE";
        break;
    case VCE_NO_AVALIBLE_VIDEO_INPUT_DEVICE:
        return "VCE_NO_AVALIBLE_VIDEO_INPUT_DEVICE";
        break;
    case VCE_NO_AVALIBLE_VIDEO_OUTPUT_DEVICE:
        return "VCE_NO_AVALIBLE_VIDEO_OUTPUT_DEVICE";
        break;
    case VCE_NO_STREAM:
        return "VCE_NO_STREAM";
        break;
    case VCE_START_AUDIO_INPUT_ERR:
        return "VCE_START_AUDIO_INPUT_ERR";
        break;
    case VCE_START_AUDIO_OUTPUT_ERR:
        return "VCE_START_AUDIO_OUTPUT_ERR";
        break;
    case VCE_STOP_AUDIO_INPUT_ERR:
        return "VCE_STOP_AUDIO_INPUT_ERR";
        break;
    case VCE_STOP_AUDIO_OUTPUT_ERR:
        return "VCE_STOP_AUDIO_OUTPUT_ERR";
        break;
    case VCE_NOT_PLAYING_AUDIO:
        return "VCE_NOT_PLAYING_AUDIO";
        break;
    case VCE_NOT_RECORDING_AUDIO:
        return "VCE_NOT_RECORDING_AUDIO";
        break;
    case VCE_NOT_PLAYING_VIDEO:
        return "VCE_NOT_PLAYING_VIDEO";
        break;
    case VCE_NOT_RECORDING_VIDEO:
        return "VCE_NOT_RECORDING_VIDEO";
        break;
    case VCE_NOT_PLAYING_DESKTOP:
        return "VCE_NOT_PLAYING_DESKTOP";
        break;
    case VCE_NOT_RECORDING_DESKTOP:
        return "VCE_NOT_RECORDING_DESKTOP";
        break;
    case VCE_AUDIO_IS_PLAYING:
        return "VCE_AUDIO_IS_PLAYING";
        break;
    case VCE_AUDIO_IS_RECORDING:
        return "VCE_AUDIO_IS_RECORDING";
        break;
    case VCE_VIDEO_IS_PLAYING:
        return "VCE_VIDEO_IS_PLAYING";
        break;
    case VCE_VIDEO_IS_RECORDING:
        return "VCE_VIDEO_IS_RECORDING";
        break;
    case VCE_DESKTOP_IS_PLAYING:
        return "VCE_DESKTOP_IS_PLAYING";
        break;
    case VCE_DESKTOP_IS_RECORDING:
        return "VCE_DESKTOP_IS_RECORDING";
        break;
    case VCE_NO_SUCH_VIDEO_PRVIWE:
        return "VCE_NO_SUCH_VIDEO_PRVIWE";
        break;
    case VCE_CANNOT_RECORD_AUDIO:
        return "VCE_CANNOT_RECORD_AUDIO";
        break;
    case VCE_CANNOT_RECORD_VIDEO:
        return "VCE_CANNOT_RECORD_VIDEO";
        break;
    case VCE_CANNOT_RECORD_DESKTOP:
        return "VCE_CANNOT_RECORD_DESKTOP";
        break;
    case VCE_CANNOT_STOP_RECORD_AUDIO:
        return "VCE_CANNOT_STOP_RECORD_AUDIO";
        break;
    case VCE_CANNOT_STOP_RECORD_VIDEO:
        return "VCE_CANNOT_STOP_RECORD_VIDEO";
        break;
    case VCE_CANNOT_STOP_RECORD_DESKTOP:
        return "VCE_CANNOT_STOP_RECORD_DESKTOP";
        break;
    case VCE_VERIFY_CHN_FAILED:
        return "VCE_VERIFY_CHN_FAILED";
        break;
    case VCE_VERIFY_ROOM_FAILED:
        return "VCE_VERIFY_ROOM_FAILED";
        break;
    case VCE_CHNS_NOT_IN_SAME_ROOM:
        return "VCE_CHNS_NOT_IN_SAME_ROOM";
        break;
    case VCE_LOCK_SUCCESS:
        return "VCE_LOCK_SUCCESS";
        break;
    case VCE_LOCK_CONFLICT:
        return "VCE_LOCK_CONFLICT";
        break;
    case VCE_LOCK_REPEAT:
        return "VCE_LOCK_REPEAT";
        break;
    case VCE_UNLOCK_SUCCESS:
        return "VCE_UNLOCK_SUCCESS";
        break;
    case VCE_UNLOCK_CONFLICT:
        return "VCE_UNLOCK_CONFLICT";
        break;
    case VCE_UNLOCK_UNKNOW:
        return "VCE_UNLOCK_UNKNOW";
        break;
    case VCE_LOCK_FAIL:
        return "VCE_LOCK_FAIL";
        break;
    case VCE_UNLOCK_FAIL:
        return "VCE_UNLOCK_FAIL";
        break;
    case VCE_NO_OTHERS_IN_ROOM:
        return "VCE_NO_OTHERS_IN_ROOM";
        break;
    case VCE_DES_NO_AVALIBLE_DATA_API:
        return "VCE_DES_NO_AVALIBLE_DATA_API";
        break;
    case VCE_DES_DATASEVER_ADDR_ERROR:
        return "VCE_DES_DATASEVER_ADDR_ERROR";
        break;
    case VCE_DES_SEND_BUFFER_FULL:
        return "VCE_DES_SEND_BUFFER_FULL";
        break;
    case VCE_DES_SOCKET_CLOSE:
        return "VCE_DES_SOCKET_CLOSE";
        break;
    case VCE_DES_HEARTBEAT_TIMEOUT:
        return "VCE_DES_HEARTBEAT_TIMEOUT";
        break;
    case VCE_DES_SOCKET_FD_ERROR:
        return "VCE_DES_SOCKET_FD_ERROR";
        break;
    case VCE_AUTH_FAILED:
        return "VCE_AUTH_FAILED";
        break;
    case VCE_AUTH_NEEDED:
        return "VCE_AUTH_NEEDED";
        break;
    case VCE_LOGINED_ON_OTHER:
        return "VCE_LOGINED_ON_OTHER";
        break;
    case VCE_NO_SUCH_USER:
        return "VCE_NO_SUCH_USER";
        break;
    case VCE_AUTH_PWD_WRONG:
        return "VCE_AUTH_PWD_WRONG";
        break;
    case VCE_NEW_ROOM_FAILED:
        return "VCE_NEW_ROOM_FAILED";
        break;
    case VCE_NO_SUCH_ROOM:
        return "VCE_NO_SUCH_ROOM";
        break;
    case VCE_HAS_IN_OTHER_ROOM:
        return "VCE_HAS_IN_OTHER_ROOM";
        break;
    case VCE_NOT_IN_ANY_ROOM:
        return "VCE_NOT_IN_ANY_ROOM";
        break;
    case VCE_PHONE_HAS_REGISTED:
        return "VCE_PHONE_HAS_REGISTED";
        break;
    case VCE_DB_FAILURE:
        return "VCE_DB_FAILURE";
        break;
    case VCE_SEVICE_BUSY:
        return "VCE_SEVICE_BUSY";
        break;
    case VCE_DESKTOP_IN_SHARING:
        return "VCE_DESKTOP_IN_SHARING";
        break;
    case VCE_DESKTOP_NOT_IN_SHARING:
        return "VCE_DESKTOP_NOT_IN_SHARING";
        break;
    case VCE_CANNOT_ENABLE_AUDIO:
        return "VCE_CANNOT_ENABLE_AUDIO";
        break;
    case VCE_CANNOT_ENABLE_VIDEO:
        return "VCE_CANNOT_ENABLE_VIDEO";
        break;
    case VCE_NO_SUCH_OBJ:
        return "VCE_NO_SUCH_OBJ";
        break;
    case VCE_NO_SUCH_MIXER:
        return "VCE_NO_SUCH_MIXER";
        break;
    case VCE_NO_SUCH_CHN:
        return "VCE_NO_SUCH_CHN";
        break;
    case VCE_MIXER_EXIST:
        return "VCE_MIXER_EXIST";
        break;
    case VCE_CHN_EXIST:
        return "VCE_CHN_EXIST";
        break;
    case VCE_ADDR_ERROR:
        return "VCE_ADDR_ERROR";
        break;
    case VCE_SIZE_NOT_ENOUGH:
        return "VCE_SIZE_NOT_ENOUGH";
        break;
    case VCE_SEND_BUFFER_FULL:
        return "VCE_SEND_BUFFER_FULL";
        break;
    case VCE_SOCKET_CLOSE:
        return "VCE_SOCKET_CLOSE";
        break;
    case VCE_HEARTBEAT_TIMEOUT:
        return "VCE_HEARTBEAT_TIMEOUT";
        break;
    case VCE_NOT_LOGIN:
        return "VCE_NOT_LOGIN";
        break;
    case VCE_NOT_CONNECT:
        return "VCE_NOT_CONNECT";
        break;
    case VCE_NOT_IN_MEETING:
        return "VCE_NOT_IN_MEETING";
        break;
    case VCE_PROXY_FAIL:
        return "VCE_PROXY_FAIL";
        break;
    case VCE_PROXY_ERROR:
        return "VCE_PROXY_ERROR";
        break;
    case VCE_LOGIN_SOCKET_CLOSE:
        return "VCE_LOGIN_SOCKET_CLOSE";
        break;
    case VCE_LOGIN_HEARTBEAT_TIMEOUT:
        return "VCE_LOGIN_HEARTBEAT_TIMEOUT";
        break;
    case VCE_TRANS_SOCKET_CLOSE:
        return "VCE_TRANS_SOCKET_CLOSE";
        break;
    case VCE_TRANS_HEARTBEAT_TIMEOUT:
        return "VCE_TRANS_HEARTBEAT_TIMEOUT";
        break;
    default:
        break;
    }
    return Poco::NumberFormatter::format(error);
}
