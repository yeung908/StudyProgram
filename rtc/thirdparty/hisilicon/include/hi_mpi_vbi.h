/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_mpi_vbi.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2015/02/11
  Description   :
  History       :
  1.Date        : 2015/02/11
    Author      : ywx218173
    Modification: Created file
******************************************************************************/
#ifndef __HI_MPI_VBI_H__
#define __HI_MPI_VBI_H__

#include "drv_vbi_ioctl.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define VBI_MPI_GET_CTX()   (&s_stVbiMpiCtx)

#define VBI_MPI_CHECK_INITED() \
    do {\
        if (HI_TRUE != s_stVbiMpiCtx.bInited)\
        {\
            return HI_FAILURE;\
        }\
    } while(0)

#define VBI_MPI_CHECK_CONNECTED() \
    do {\
        if (HI_TRUE != s_stVbiMpiCtx.bConnected)\
        {\
            return HI_FAILURE;\
        }\
    } while(0)

HI_S32 HI_MPI_VBI_Init(HI_VOID);
HI_S32 HI_MPI_VBI_DeInit(HI_VOID);
HI_S32 HI_MPI_VBI_Connect(HI_UNF_VBI_SRC_ATTR_S *pstSrcAttr);
HI_S32 HI_MPI_VBI_DisConnect(HI_VOID);
HI_S32 HI_MPI_VBI_GetSignalInfo(HI_UNF_VBI_SIGNALINFO_S *pstVbiAttr);
HI_S32 HI_MPI_VBI_SetAttr(HI_UNF_VBI_ATTR_S *pstVbiAttr);

HI_S32 HI_MPI_VBI_AcquireCCBuf(HI_U32 u32AcquireNum,HI_U32 *pu32AcquiredNum,HI_UNF_VBI_CC_DATA_S **ppstCCData);
HI_S32 HI_MPI_VBI_AcquireTTBuf(HI_U32 u32AcquireNum,HI_U32 *pu32AcquiredNum,HI_U8 *pu8Data);
HI_S32 HI_MPI_VBI_SetDataInvEN(HI_BOOL bDataInvEn,HI_BOOL bByteInvEn);
HI_S32 HI_MPI_VBI_GetDataInvEN(HI_BOOL *bDataInvEn,HI_BOOL *bByteInvEn);
HI_S32 HI_MPI_VBI_AcquireInfoBuf(HI_U32 u32AcquireNum,HI_U32 *pu32AcquiredNum,HI_UNF_VBI_TT_INFO_S **ppstTTInfo);

HI_S32 HI_MPI_VBI_SetQtcEn(HI_BOOL bQtcEn);
HI_S32 HI_MPI_VBI_GetQtcEn(HI_BOOL *bQtcEn);

typedef struct hiMPI_VBI_CTX_S
{
    HI_BOOL bInited;
    HI_BOOL bConnected;
    HI_S32  s32Fd;
    HI_UNF_VBI_SIG_TYPE_E enVbiType; 
} HI_MPI_VBI_CTX_S;

typedef struct hiMPI_VBI_TT_DATABUF_S
{
    HI_U32 u32ReadAddr;
    HI_U32 u32WriteAddr;
    HI_U32 u32ReadPhyAddr;
    DRV_VBI_MMZ_BUF_S  stBufAddr;
} HI_MPI_VBI_TT_DATABUF_S;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
