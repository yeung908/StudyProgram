/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_drv_hdmirx.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2014/01/16
  Description   :
  History       :
  1.Date        : 2014/01/16
    Author      : t00202585
    Modification: Created file
******************************************************************************/
#ifndef __HI_DRV_HDMIRX_H__
#define __HI_DRV_HDMIRX_H__

#include <linux/ioctl.h>
#include "hi_type.h"
#include "hi_unf_hdmirx.h"

typedef struct hiDRV_HDMIRX_HDCP_S
{
    HI_UNF_HDMIRX_HDCPTYPE_E enHdcpType;
    HI_U32              u32HdcpLength;
    HI_U8               au8Hdcp[1024];        /**<HDMIRX HDCP Value*//**<CNcomment:HDMIRX HDCP 值 */
}HI_DRV_HDMIRX_HDCP_S;

typedef struct hiDRV_HDMIRX_EDID_S
{
    HI_UNF_HDMIRX_PORT_E enPort;
    HI_U32          u32EdidLength;
    HI_U32          au32Edid[256];       /**<HDMIRX EDID Value*//**<CNcomment:HDMIRX EDID 值 */
    HI_U32          u32CecAddr;      // 该port口对应的CEC地址
}HI_DRV_HDMIRX_EDID_S;

typedef struct hiDRV_HDMIRX_OFFLINE_DET_S
{
    HI_UNF_HDMIRX_PORT_E                enPort;         /**<HDMIRX port ID */ /**<CNcomment:HDMIRX port ID */
    HI_UNF_HDMIRX_FORMAT_E              enFormat;       /**<HDMIRX OffLineDetect Status for callback*/ /**<CNcomment:HDMIRX 离线检测状态，用于返回值 */
}HI_DRV_HDMIRX_OFFLINE_DET_S;

typedef struct hiDRV_HDMIRX_HPD_S
{
    HI_UNF_HDMIRX_PORT_E                enPort;         /**<HDMIRX port ID */ /**<CNcomment:HDMIRX port ID */
    HI_BOOL                             bValue;         /**<HDMIRX HotPlug Value*/ /**<CNcomment:HDMIRX HotPlug 值 */
}HI_DRV_HDMIRX_HPD_S;


#define HIIOC_HDMIRX_CONNECT        _IOW('H', 0, HI_UNF_HDMIRX_PORT_E)  /* connect hdmirx and select hdmirx port */
#define HIIOC_HDMIRX_DISCONNECT     _IO('H',  1)                            /* disconnect hdmirx */

#define HIIOC_HDMIRX_G_STATUS       _IOR('H', 2, HI_UNF_SIG_STATUS_E)       /* Get the signal status */
#define HIIOC_HDMIRX_G_TIMING_INFO  _IOR('H', 3, HI_UNF_HDMIRX_TIMING_INFO_S)   /*get the timing info like hactive/vactive/colorspace etc. */

#define HIIOC_HDMIRX_G_HDCP_STATUS  _IOR('H', 4, HI_BOOL)   /*get the timing info like hactive/vactive/colorspace etc. */

#define HIIOC_HDMIRX_S_UPDATE_EDID      _IOW('H', 5, HI_DRV_HDMIRX_EDID_S)  /* update the edid */

#define HIIOC_HDMIRX_S_LOAD_HDCP        _IOW('H', 6, HI_DRV_HDMIRX_HDCP_S)  /* Load HDCP */

#define HIIOC_HDMIRX_EN_MONITOR        _IOW('H', 7, HI_BOOL)                    /* enable/disable the main thread */

#define HIIOC_HDMIRX_G_OFF_LINE_DET_STA   _IOWR('H', 8, HI_UNF_HDMIRX_OFF_LINE_DET_S)                   /* detect other port connect to tx or not */

#define HIIOC_HDMIRX_G_AUDIO_INFO _IOR('H', 9, HI_UNF_AI_HDMI_ATTR_S)

#define HIIOC_HDMIRX_G_AudioSTATUS _IOR('H',10,HI_UNF_SIG_STATUS_E)

#define HIIOC_HDMIRX_S_MHL_RCPKEY  _IOW('H',11, HI_UNF_HDMIRX_RCP_KEY_E)

#define HIIOC_HDMIRX_S_CEC_CMD            _IOWR('H', 12, HI_UNF_HDMIRX_CEC_CMD_S)

#define HIIOC_HDMIRX_S_CEC_ENABLE         _IOWR('H', 13, HI_BOOL)

#define HIIOC_HDMIRX_G_CEC_CMD            _IOR('H', 14, HI_UNF_HDMIRX_CEC_CMD_S)

#define HIIOC_HDMIRX_G_ARC_VOLLEV          _IOWR('H', 15, HI_U32)

#define HIIOC_HDMIRX_G_ARC_CAP           _IOWR('H', 16, HI_UNF_SND_ARC_AUDIO_CAP_S)

#define HIIOC_HDMIRX_G_ARC_SUPPORTED          _IOWR('H', 17, HI_BOOL)

#define HIIOC_HDMIRX_G_OFF_LINE_DET_FORMAT _IOWR('H', 18, HI_DRV_HDMIRX_OFFLINE_DET_S)

#define HIIOC_HDMIRX_G_CEC_CMDSTATE          _IOWR('H', 19, HI_UNF_HDMIRX_CEC_CMD_STATE_S)

#define HIIOC_HDMIRX_S_UPDATE_MHL_EDID      _IOW('H', 20, HI_DRV_HDMIRX_EDID_S) /* update the edid */

#define HIIOC_HDMIRX_S_CEC_STANDBY_ENABLE       _IOWR('H', 21, HI_BOOL)

#define HIIOC_HDMIRX_S_MHL_RELEASE_RCPKEY  _IOW('H',22, HI_UNF_HDMIRX_RCP_KEY_E)

#define HIIOC_HDMIRX_S_HPD_VALUE           _IOWR('H', 23, HI_DRV_HDMIRX_HPD_S)

#endif

