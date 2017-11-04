/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_fdmng_ext.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2014/03/27
  Description   : 
  History       :
  1.Date        : 2012/03/27
    Author      : w00248302
    Modification: Created file
******************************************************************************/

#ifndef __DRV_FDMNG_EXT_H__
#define __DRV_FDMNG_EXT_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include "hi_drv_fdmng.h"

typedef HI_S32  (*FN_FDMNG_Create)(HI_HANDLE *phFdmng,HI_HANDLE hVpss);
typedef HI_S32  (*FN_FDMNG_Destroy)(HI_HANDLE hFdmng);
typedef HI_S32  (*FN_FDMNG_Enable)(HI_HANDLE hFdmng,HI_BOOL bEnable);
typedef HI_S32  (*FN_FDMNG_QueryResult)(HI_HANDLE hFdmng,HI_DRV_FRAME_TYPE_E *pEframeType);


typedef struct
{
    FN_FDMNG_Create           pfnFdmngCreate;
    FN_FDMNG_Destroy          pfnFdmngDestroy;
    FN_FDMNG_Enable           pfnFdmngEnable;
    FN_FDMNG_QueryResult      pfnFdmngQueryResult;
} FDMNG_EXPORT_FUNC_S;


HI_S32 __init FDMNG_DRV_ModInit(HI_VOID);
HI_VOID __exit FDMNG_DRV_ModExit(HI_VOID);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __DRV_FMTDECTMNG_EXT_H__*/
