/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_mpi_tvd.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/11/19
  Description   : 
  History       :
  1.Date        : 2013/11/19
    Author      : w00184692
    Modification: Created file
******************************************************************************/
#ifndef __HI_MPI_TVD_H__
#define __HI_MPI_TVD_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define TVD_MPI_GET_CTX()   (&s_stTvdMpiCtx)
#define TVD_MPI_GET_QTCTEMP()   (&s_stTvdMpiQtcTemp)

#define TVD_MPI_CHECK_INITED()      \
    do {\
        if (HI_TRUE != s_stTvdMpiCtx.bInited)\
        {\
            return HI_FAILURE;\
        }\
    } while(0)

#define TVD_MPI_CHECK_CONNECTED()   \
    do {\
        if (HI_TRUE != s_stTvdMpiCtx.bConnected)\
        {\
            return HI_FAILURE;\
        }\
    } while(0)

HI_S32 HI_MPI_TVD_Init(HI_VOID);
HI_S32 HI_MPI_TVD_DeInit(HI_VOID);
HI_S32 HI_MPI_TVD_Connect(HI_UNF_TVD_SRC_ATTR_S *pstSrcAttr);
HI_S32 HI_MPI_TVD_DisConnect(HI_VOID);
HI_S32 HI_MPI_TVD_GetSigStatus(HI_UNF_SIG_STATUS_E *penSignalStatus);
HI_S32 HI_MPI_TVD_GetStdTimingInfo(HI_UNF_TVD_TIMING_INFO_S *pstTimingInfo);
HI_S32 HI_MPI_TVD_SetColorSys(HI_UNF_COLOR_SYS_E enColorSys);
HI_S32 HI_MPI_TVD_GetColorSys(HI_UNF_COLOR_SYS_E *penColorSys);
HI_S32 HI_MPI_TVD_GetSignalLock(HI_BOOL *pbLock);
HI_S32 HI_MPI_TVD_GetNoiseLevel(HI_U32 *pu32Level);
HI_S32 HI_MPI_TVD_GetMacrovisionStatus(HI_BOOL *pbStatus);
HI_S32 HI_MPI_TVD_GetNstdInfo(HI_UNF_VIDEO_NONSTD_INFO_S *pstNstdInfo);
HI_S32 HI_MPI_TVD_GetRange(HI_UNF_TVD_POS_TYPE_E enType, HI_RANGE_S *pstRange);
HI_S32 HI_MPI_TVD_GetPos(HI_UNF_TVD_POS_TYPE_E enType, HI_U32 *pu32Pos);
HI_S32 HI_MPI_TVD_SetPos(HI_UNF_TVD_POS_TYPE_E enType, HI_U32 u32Pos);
HI_S32 HI_MPI_TVD_GetOfflineDetStatus(HI_UNF_TVD_OFFLINE_S *pstOffline, HI_BOOL *pbStatus);
HI_S32 HI_MPI_TVD_SetPedestal(HI_BOOL bEnable);
HI_S32 HI_MPI_TVD_SetColorSysFilter(HI_UNF_TVD_SYS_FILTER_S *pstSysFilter);
HI_S32 HI_MPI_TVD_GetColorSysFilter(HI_UNF_TVD_SYS_FILTER_S *pstSysFilter);
HI_S32 HI_MPI_TVD_EnMonitor(HI_BOOL bPause);
HI_S32 HI_MPI_TVD_SetCombMode(HI_UNF_TVD_COMB_MODE_E enMode);
HI_S32 HI_MPI_TVD_Get625Mode(HI_BOOL *pbIs625);
HI_S32 HI_MPI_TVD_SetWorkMode(HI_UNF_TVD_WORK_MODE_E enWorkMode);
HI_S32 HI_MPI_TVD_HandleCmd(HI_U32 u32Cmd, HI_U32 *pu32Attr1, HI_U32 *pu32Attr2);
HI_S32 HI_MPI_TVD_SetInkMode(TVD_INKMODE_E enInkMode);
HI_S32 HI_MPI_TVD_GetInkMode(TVD_INKMODE_E *penInkMode);
HI_S32 HI_MPI_TVD_SetQtcEn(TVD_SELECT_QTCDATA_E enQtcData);
HI_S32 HI_MPI_TVD_GetQtcState(HI_BOOL *pbState);
HI_S32 HI_MPI_TVD_GetQtcBufVirAddr(HI_U16 **ppu16QtcStartVirAddr);

typedef struct hiMPI_TVD_CTX_S
{
    HI_BOOL bInited;
    HI_BOOL bConnected;
    HI_S32  s32Fd;
} HI_MPI_TVD_CTX_S;

typedef enum hiTVD_QTC_Data_Bitnum_E
{
    TVD_QTC_DATA_10BIT = 0,
    TVD_QTC_DATA_12BIT,
    TVD_QTC_DATA_30BIT,
    TVD_QTC_DATA_60BIT,

    TVD_QTC_DATA_BUTT,
}TVD_QTC_DATA_BITNUM_E;

typedef struct hiMPI_TVD_QTC_TEMP_S
{
	HI_BOOL bIsSaveFile;
    HI_BOOL bState;
    TVD_QTC_DATA_BITNUM_E enBitNum;
    HI_BOOL bMonitorEn;
    HI_U32 u32Size;
    HI_U32 *pu32QtcVirAddr;
} HI_MPI_TVD_QTC_TEMP_S;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif

