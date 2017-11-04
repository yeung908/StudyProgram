/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_hdmirx_ioctl.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2014/02/26
  Description   : 
  History       :
  1.Date        : 2014/02/26
    Author      : t00202585
    Modification: Created file
******************************************************************************/
#ifndef __DRV_HDMIRX_SWITCH_EXT_H__
#define __DRV_HDMIRX_SWITCH_EXT_H__

#include "hi_type.h"


typedef struct
{    
    HI_S32 (*pfnSWITCH_INTF_SetHpdValue)(HI_U8 u8HdmiPort,HI_BOOL bValue);
} SWITCH_EXPORT_FUNC_S;

HI_S32 __init SWITCH_DRV_ModuleInit(HI_VOID);
HI_VOID __exit SWITCH_DRV_ModuleExit(HI_VOID);

#endif

