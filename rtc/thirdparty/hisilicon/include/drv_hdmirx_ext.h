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
#ifndef __DRV_HDMIRX_EXT_H__
#define __DRV_HDMIRX_EXT_H__

#include "hi_type.h"
typedef enum hiDRV_HDMIRX_DATA_ROUTE_E 
{
    HI_DRV_HDMIRX_DATA_ROUTE_CTRL0 = 0,       // 2.0 ctrl HDMIRX data route to HDMIRX Control Core 0.
    HI_DRV_HDMIRX_DATA_ROUTE_CTRL1,           // 1.4 ctrl HDMIRX data route to HDMIRX Control Core 1.
    HI_DRV_HDMIRX_DATA_ROUTE_CTRL0_CTRL1_OE,  // HDMIRX data route to HDMIRX Control Core 0 and 1 with the data odd and even.
    HI_DRV_HDMIRX_DATA_ROUTE_CTRL0_CTRL1_LR,  // HDMIRX data route to HDMIRX Control Core 0 and 1 with the data left and right.

    HI_DRV_HDMIRX_DATA_ROUTE_BUTT,
} HI_DRV_HDMIRX_DATA_ROUTE_E;

typedef enum hiDRV_HDMIRX_VISTATUS_E
{
    HI_DRV_HDMIRX_VISTATUS_CREATE =0,
    HI_DRV_HDMIRX_VISTATUS_DESTORY ,
    HI_DRV_HDMIRX_VISTATUS_BUTT
}HI_DRV_HDMIRX_VISTATUS_E;

typedef struct
{    
    HI_U32 (*pfnHDMIRXGetDataRoute)(HI_VOID);
    HI_S32 (*pfnHDMIRX_DRV_INTF_SetStatus)(HI_U32 u32VicapId ,HI_DRV_HDMIRX_VISTATUS_E enStatus);
} HDMIRX_EXPORT_FUNC_S;

HI_S32 __init HDMIRX_DRV_ModuleInit(HI_VOID);
HI_VOID __exit HDMIRX_DRV_ModuleExit(HI_VOID);

#endif

