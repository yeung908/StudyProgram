/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_drv_fdmng.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2014/03/24
  Description   : 
  History       :
  1.Date        : 2014/03/24
    Author      : w00248302
    Modification: Created file
******************************************************************************/

#ifndef __HI_DRV_FDMNG_H__
#define __HI_DRV_FDMNG_H__

#include "hi_drv_video.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

HI_S32 HI_DRV_FDMNG_Create(HI_HANDLE *phFdmng,HI_HANDLE hVpss);

HI_S32 HI_DRV_FDMNG_Destroy(HI_HANDLE hFdmng);

HI_S32 HI_DRV_FDMNG_Enable(HI_HANDLE hFdmng, HI_BOOL bEnable);

HI_S32 HI_DRV_FDMNG_QueryResult(HI_HANDLE hFdmng,HI_DRV_FRAME_TYPE_E *pEframeType);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __HI_DRV_FDMNG_H__ */

