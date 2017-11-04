/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_mpi_hdmirx.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2014/01/16
  Description   : 
  History       :
  1.Date        : 2014/01/16
    Author      : t00202585
    Modification: Created file
******************************************************************************/
#ifndef __HI_MPI_HDMIRX_H__
#define __HI_MPI_HDMIRX_H__
#include"hi_unf_sound.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
#define HDMIRX_MPI_GET_CTX()   (&s_stHdmirxMpiCtx)

#define HDMIRX_MPI_CHECK_INITED()      \
    do {\
        if (HI_TRUE != s_stHdmirxMpiCtx.bInited)\
        {\
            return HI_FAILURE;\
        }\
    } while(0)

#define HDMIRX_MPI_CHECK_CONNECTED()   \
    do {\
        if (HI_TRUE != s_stHdmirxMpiCtx.bConnected)\
        {\
            return HI_FAILURE;\
        }\
    } while(0)

typedef struct hiMPI_HDMIRX_CTX_S
{
    HI_BOOL bInited;
    HI_BOOL bConnected;
    HI_S32  s32Fd;
} HI_MPI_HDMIRX_CTX_S;

HI_S32 HI_MPI_HDMIRX_Init(HI_VOID);
HI_S32 HI_MPI_HDMIRX_DeInit(HI_VOID);
HI_S32 HI_MPI_HDMIRX_Connect(HI_UNF_HDMIRX_PORT_E enPortIdx);
HI_S32 HI_MPI_HDMIRX_DisConnect(HI_VOID);
HI_S32 HI_MPI_HDMIRX_GetHdcpStatus(HI_BOOL *pbHdcpSta);
HI_S32 HI_MPI_HDMIRX_GetTimingInfo(HI_UNF_HDMIRX_TIMING_INFO_S *pstTimingInfo);
HI_S32 HI_MPI_HDMIRX_GetAudioInfo(HI_UNF_AI_HDMI_ATTR_S *pstAudioInfo);
HI_S32 HI_MPI_HDMIRX_GetSigStatus(HI_UNF_SIG_STATUS_E *penSignalStatus);
HI_S32 HI_MPI_HDMIRX_GetAudioStatus(HI_UNF_SIG_STATUS_E *penStatus);
HI_S32 HI_MPI_HDMIRX_UpdateEdid(HI_UNF_HDMIRX_EDID_S *pstEdid);
HI_S32 HI_MPI_HDMIRX_UpdateMHLEdid(HI_UNF_HDMIRX_PORT_E enPort,HI_U32 u32Length,HI_U32 *pu32Edid);
//HI_S32 HI_MPI_HDMIRX_EnMonitor(HI_BOOL bEnable);
HI_S32 HI_MPI_HDMIRX_GetOfflineDetStatus(HI_UNF_HDMIRX_PORT_E enPortIdx, HI_BOOL *pbStatus);
HI_S32 HI_MPI_HDMIRX_GetOffLineDetFormat(HI_UNF_HDMIRX_PORT_E enPortIdx, HI_UNF_HDMIRX_FORMAT_E *penFormat);
HI_S32 HI_MPI_HDMIRX_UpdateHdcp(HI_UNF_HDMIRX_HDCPTYPE_E enType,HI_UNF_HDMIRX_HDCP_S *pstHdcp);
HI_S32 HI_MPI_HDMIRX_GetAudioInfo(HI_UNF_AI_HDMI_ATTR_S *pstAudioInfo);
HI_S32 HI_MPI_HDMIRX_SendRcpKey(HI_UNF_HDMIRX_RCP_KEY_E enKey);
HI_S32 HI_MPI_HDMIRX_ReleaseRcpKey(HI_UNF_HDMIRX_RCP_KEY_E enKey);
HI_S32 HI_MPI_HDMIRX_SetHpdValue(HI_UNF_HDMIRX_PORT_E enPort,HI_BOOL bValue);
HI_S32 HI_MPI_HDMIRX_CEC_Enable(HI_BOOL bEnable);
HI_S32 HI_MPI_HDMIRX_CEC_SetCommand(HI_UNF_HDMIRX_CEC_CMD_S *pstCECCmd);
HI_S32 HI_MPI_HDMIRX_CEC_GetCommand(HI_UNF_HDMIRX_CEC_CMD_S *pstCECCmd);
HI_S32 HI_MPI_HDMIRX_CEC_ArcEnable(HI_BOOL bEnable);
HI_S32 HI_MPI_HDMIRX_CEC_ArcEnable_Extend(HI_BOOL bEnable);
HI_S32 HI_MPI_HDMIRX_CEC_GetArcVolLev(HI_U32 *pu32VolLev);
HI_S32 HI_MPI_HDMIRX_CEC_ArcVolCtrl(HI_U32 u32KeyVal);
HI_VOID HI_MPI_HDMIRX_CEC_GetAudStat(HI_VOID);
HI_S32 HI_MPI_HDMIRX_CEC_QueryARCCap(HI_VOID);
HI_S32 HI_MPI_HDMIRX_CEC_GetARCCap(HI_UNF_SND_ARC_AUDIO_CAP_S *pstARCCap);
HI_S32 HI_MPI_HDMIRX_CEC_GetARCSupported(HI_BOOL *pbARCSupported);
HI_S32 HI_MPI_HDMIRX_CEC_GetCurCmdState(HI_UNF_HDMIRX_CEC_CMD_STATE_S *pstCmdState);
HI_S32 HI_MPI_HDMIRX_CEC_StandbyEnable(HI_BOOL bEnable);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif

