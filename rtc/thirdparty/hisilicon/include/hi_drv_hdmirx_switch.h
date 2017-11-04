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
#ifndef __HI_DRV_HDMIRX_SWITCH_H__
#define __HI_DRV_HDMIRX_SWITCH_H__

#include <linux/ioctl.h>
#include "hi_type.h"
#include "hi_unf_switch.h"
//#include "drv_hdmirx_switch_ext.h"

typedef struct hiDRV_SWITCH_INFO_S
{
    HI_U8 u8SwitchId;
    HI_UNF_SWITCH_PORT_E enSwitchPort;
}HI_DRV_SWITCH_INFO_S;

typedef struct hiDRV_SWITCH_MAP_S
{
    HI_U8 u8HdmiPort;
    HI_U8 u8SwitchId;
    HI_UNF_SWITCH_PORT_E enSwitchPort;
}HI_DRV_SWITCH_MAP_S;

typedef struct hiDRV_SWITCH_EDID_S
{
    HI_U8 u8SwitchId;
    HI_UNF_SWITCH_PORT_E enSwitchPort;
    HI_U32          u32EdidLength;
    HI_U32          au32Edid[256];       /**<SWITCH EDID Value*//**<CNcomment:SWITCH EDID 值 */
    HI_U32          u32CecAddr;      // 该port口对应的CEC地址
}HI_DRV_SWITCH_EDID_S;
 
 /**the config parameter of OffLineDetect Status interface*/
 /**CNcomment:离线检测 接口参数配置 */
 typedef struct hiDRV_SWITCH_OFF_LINE_DET_S
 {
     HI_U8 u8SwitchId;
     HI_UNF_SWITCH_PORT_E enSwitchPort;
     HI_BOOL                         bConnected;     /**<SWITCH OffLineDetect Status for callback*/ /**<CNcomment:HDMIRX 离线检测状态，用于返回值 */
 }HI_DRV_SWITCH_OFF_LINE_DET_S;
 
typedef struct hiDRV_SWITCH_HDMIOUT_S
{
    HI_U8 u8hdmioutmode;
}HI_DRV_SWITCH_HDMIOUT_S;
#define HIIOC_SWITCH_CONNECT        _IOW('H', 30, HI_DRV_SWITCH_INFO_S)  /* connect switch and select switch port */
#define HIIOC_SWITCH_DISCONNECT     _IO('H',  31)                            /* disconnect hdmirx */

#define HIIOC_SWITCH_MAP_PORT       _IOWR('H', 32, HI_UNF_SIG_STATUS_E)       /* Get the signal status */

#define HIIOC_SWITCH_S_UPDATE_EDID      _IOW('H', 33, HI_DRV_SWITCH_EDID_S)  /* update the edid */

#define HIIOC_SWITCH_G_OFF_LINE_DET_STA   _IOWR('H', 34, HI_DRV_SWITCH_OFF_LINE_DET_S)                   /* detect other port connect to tx or not */

#define HIIOC_SWITCH_SET_HDMIOUT_MODE   _IOW('H', 35, HI_DRV_SWITCH_HDMIOUT_S)                   /* set hdmiout hdcp */
#endif

