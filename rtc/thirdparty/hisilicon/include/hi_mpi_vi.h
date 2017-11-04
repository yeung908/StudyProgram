/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_mpi_vi.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/11/15
  Description   : 
  History       :
  1.Date        : 2013/11/15
    Author      : c00186004/w00248302
    Modification: Created file
******************************************************************************/

#ifndef __HI_MPI_VI_H__
#define __HI_MPI_VI_H__

#include "hi_unf_vi.h"
#include "drv_vi_ioctl.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

HI_S32 HI_MPI_VI_Init(HI_VOID);
HI_S32 HI_MPI_VI_DeInit(HI_VOID);
HI_S32 HI_MPI_VI_Create(HI_UNF_VI_ATTR_S *pstViAttr, HI_HANDLE *phVi);
HI_S32 HI_MPI_VI_Destroy(HI_HANDLE hVi);

HI_S32 HI_MPI_VI_Attach(HI_HANDLE hVi, HI_HANDLE hDst);
HI_S32 HI_MPI_VI_Detach(HI_HANDLE hVi, HI_HANDLE hDst);

HI_S32 HI_MPI_VI_Start(HI_HANDLE hVi);
HI_S32 HI_MPI_VI_Stop(HI_HANDLE hVi);

/* 非标处理 */
HI_S32 HI_MPI_VI_UpdateNstdInfo(HI_HANDLE hVi, HI_UNF_VIDEO_NONSTD_INFO_S *pstNstdInfo);

HI_S32 HI_MPI_VI_AcquireFrame(HI_HANDLE hVi, HI_UNF_VIDEO_FRAME_INFO_S *pFrameInfo,  HI_U32 u32TimeoutMs);
HI_S32 HI_MPI_VI_ReleaseFrame(HI_HANDLE hVi, const HI_UNF_VIDEO_FRAME_INFO_S *pFrameInfo);

/* 调试接口 */
HI_S32 HI_MPI_VI_ChangeWinInfo(HI_HANDLE hVi, HI_HANDLE hDst, HI_DRV_PRE_PROCESS_INFO_S *pstWinAttr);
HI_S32 HI_MPI_VI_ChangeVencInfo(HI_HANDLE hVi, HI_HANDLE hDst, HI_U32 u32Width, HI_U32 u32Height);
HI_S32 HI_MPI_VI_ChangeDstFrmRate(HI_HANDLE hVi, HI_HANDLE hDest, HI_U32 u32DstFrmRate);
HI_S32 HI_MPI_VI_DequeueFrame(HI_HANDLE hVi, HI_DRV_VIDEO_FRAME_S *pstViFrame);
HI_S32 HI_MPI_VI_QueueFrame(HI_HANDLE hVi, HI_DRV_VIDEO_FRAME_S *pstViFrame);

/* 3D检测 */
HI_S32 HI_MPI_VI_Set3DDetect(HI_HANDLE hVi, HI_UNF_VI_3D_DETECT_ATTR_S *pst3dDetectAttr);
HI_S32 HI_MPI_VI_Get3DResult(HI_HANDLE hVi, HI_UNF_VIDEO_FRAME_PACKING_TYPE_E  *pEframeType);

/* 设置Csc类型 */
HI_S32 HI_MPI_VI_SetSrcCscType(HI_HANDLE hVi, HI_UNF_VI_SOURCE_CSC_TYPE_E *pEcscType);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __HI_MPI_VI_H__ */
