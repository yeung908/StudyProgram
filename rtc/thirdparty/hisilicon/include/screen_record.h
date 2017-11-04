#ifndef __SCREEN_RECORD_H__
#define __SCREEN_RECORD_H__
#include "hi_drv_disp.h"
#include "hi_drv_win.h"
#include "drv_win_ioctl.h"
#include "hi_mpi_disp.h"
#include "hi_mpi_win.h"
#include <fcntl.h>

#include "hi_unf_common.h"
#include "hi_unf_ecs.h"

#include "hi_unf_disp.h"
#include "hi_unf_vo.h"

#include "hi_unf_aenc.h"
#include "hi_unf_venc.h"
#include "hi_adp.h"


#ifdef __cplusplus
extern "C" {
#endif

//libscreenrecord:
//录制屏幕并编码成H264 ES流,适用于转屏场景，android端录制ES流发送给PC等平台播放
//注意：不支持多进程使用
//目前只支持720P及以下分辨率录屏

//HI_UNF_VCODEC_CAP_LEVEL_E :分辨率级别
//目前只支持720P及以下分辨率录屏
//HI_UNF_VCODEC_CAP_LEVEL_NULL = 0, /**<Do not decode.*/ /**<CNcomment: 不需要解码 */
//HI_UNF_VCODEC_CAP_LEVEL_QCIF = 0, /**<The resolution of the picture to be decoded is less than or equal to 176x144.*/ /**<CNcomment: 解码的图像大小不超过176*144 */
//HI_UNF_VCODEC_CAP_LEVEL_CIF,      /**<The resolution of the picture to be decoded less than or equal to 352x288.*/ /**<CNcomment: 解码的图像大小不超过352*288 */
//HI_UNF_VCODEC_CAP_LEVEL_D1,       /**<The resolution of the picture to be decoded less than or equal to 720x576.*/ /**<CNcomment: 解码的图像大小不超过720*576 */
//HI_UNF_VCODEC_CAP_LEVEL_720P,     /**<The resolution of the picture to be decoded is less than or equal to 1280x720.*/ /**<CNcomment: 解码的图像大小不超过1280*720 */

//暂不支持以下分辨率，以后可能支持
//HI_UNF_VCODEC_CAP_LEVEL_FULLHD,   /**<The resolution of the picture to be decoded is less than or equal to 1920x1080.*/ /**<CNcomment: 解码的图像大小不超过1920*1080 */
//HI_UNF_VCODEC_CAP_LEVEL_1280x800, /**<The resolution of the picture to be decoded is less than or equal to 1280x800.*/ /**<CNcomment: 解码的图像大小不超过1280x800*/
//HI_UNF_VCODEC_CAP_LEVEL_800x1280, /**<The resolution of the picture to be decoded is less than or equal to 800x1280.*/ /**<CNcomment: 解码的图像大小不超过800x1280*/
//HI_UNF_VCODEC_CAP_LEVEL_1488x1280, /**<The resolution of the picture to be decoded is less than or equal to 1488x1280.*/ /**<CNcomment: 解码的图像大小不超过1488x1280 */
//HI_UNF_VCODEC_CAP_LEVEL_1280x1488, /**<The resolution of the picture to be decoded is less than or equal to 1280x1488.*/ /**<CNcomment: 解码的图像大小不超过1280x1488 */
//HI_UNF_VCODEC_CAP_LEVEL_2160x1280, /**<The resolution of the picture to be decoded is less than or equal to 2160x1280.*/ /**<CNcomment: 解码的图像大小不超过2160x1280 */
//HI_UNF_VCODEC_CAP_LEVEL_1280x2160, /**<The resolution of the picture to be decoded is less than or equal to 1280x2160.*/ /**<CNcomment: 解码的图像大小不超过1280x2160 */
//HI_UNF_VCODEC_CAP_LEVEL_2160x2160, /**<The resolution of the picture to be decoded is less than or equal to 2160x2160.*/ /**<CNcomment: 解码的图像大小不超过2160x2160 */
//HI_UNF_VCODEC_CAP_LEVEL_4096x2160, /**<The resolution of the picture to be decoded is less than or equal to 4096x2160.*/ /**<CNcomment: 解码的图像大小不超过4096x2160 */
//HI_UNF_VCODEC_CAP_LEVEL_2160x4096, /**<The resolution of the picture to be decoded is less than or equal to 2160x4096.*/ /**<CNcomment: 解码的图像大小不超过2160x4096 */
//HI_UNF_VCODEC_CAP_LEVEL_4096x4096, /**<The resolution of the picture to be decoded is less than or equal to 4096x4096.*/ /**<CNcomment: 解码的图像大小不超过4096x4096 */
//HI_UNF_VCODEC_CAP_LEVEL_8192x4096, /**<The resolution of the picture to be decoded is less than or equal to 8192x4096.*/ /**<CNcomment: 解码的图像大小不超过8192x4096 */
//HI_UNF_VCODEC_CAP_LEVEL_4096x8192, /**<The resolution of the picture to be decoded is less than or equal to 4096x8192.*/ /**<CNcomment: 解码的图像大小不超过4096x8192 */
//HI_UNF_VCODEC_CAP_LEVEL_8192x8192, /**<The resolution of the picture to be decoded is less than or equal to 8192x8192.*/ /**<CNcomment: 解码的图像大小不超过8192x8192 */

HI_BOOL screen_record_init(HI_UNF_VCODEC_CAP_LEVEL_E encodeCaptureLevel, HI_S32 width, HI_S32 height,HI_HANDLE *hDisp, HI_HANDLE *hVenc);
HI_BOOL  screen_record_finish(HI_HANDLE hDispCast, HI_HANDLE hVenc);
HI_BOOL  screen_record_acquire_stream(HI_HANDLE hVencChn, HI_UNF_VENC_STREAM_S *stVencStream);
HI_BOOL  screen_record_release_stream(HI_HANDLE hVencChn, HI_UNF_VENC_STREAM_S *stVencStream);

#ifdef __cplusplus
}
#endif

#endif /*__SCREEN_RECORD_H__*/
