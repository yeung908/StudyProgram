/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_vi_ext.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2014/02/26
  Description   : 
  History       :
  1.Date        : 2014/02/26
    Author      : w00248302/c00186004
    Modification: Created file
******************************************************************************/
#ifndef __DRV_VI_EXT_H__
#define __DRV_VI_EXT_H__

#include "hi_type.h"
#include "hi_drv_vi.h"

typedef HI_S32  (*FN_VI_ReleaseFrame)(HI_HANDLE hVi, HI_DRV_VIDEO_FRAME_S *pstViFrame);
typedef HI_S32  (*FN_VI_ChangeWinInfo)(HI_HANDLE hPath, HI_DRV_PRE_PROCESS_INFO_S *pstWinInfo);

typedef struct
{
    FN_VI_ReleaseFrame    pfnViReleaseFrame;
    FN_VI_ChangeWinInfo   pfnViChangeWinInfo;  
} VI_EXPORT_FUNC_S;

HI_S32 __init VI_DRV_ModInit(HI_VOID);
HI_VOID __exit VI_DRV_ModExit(HI_VOID);

#endif
