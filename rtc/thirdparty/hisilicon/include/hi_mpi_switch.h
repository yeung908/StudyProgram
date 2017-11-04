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
#ifndef __HI_MPI_SWITCH_H__
#define __HI_MPI_SWITCH_H__
#include"hi_unf_switch.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
#define SWITCH_MPI_GET_CTX()   (&s_stSwitchMpiCtx)

#define SWITCH_MPI_CHECK_INITED()      \
    do {\
        if (HI_TRUE != s_stSwitchMpiCtx.bInited)\
        {\
            return HI_FAILURE;\
        }\
    } while(0)

#define SWITCH_MPI_CHECK_CONNECTED()   \
    do {\
        if (HI_TRUE != s_stSwitchMpiCtx.bConnected)\
        {\
            return HI_FAILURE;\
        }\
    } while(0)

typedef struct hiMPI_SWITCH_CTX_S
{
    HI_BOOL bInited;
    HI_BOOL bConnected;
    HI_S32  s32Fd;
} HI_MPI_SWITCH_CTX_S;

HI_S32 HI_MPI_SWITCH_Init(HI_VOID);
HI_S32 HI_MPI_SWITCH_DeInit(HI_VOID);
HI_S32 HI_MPI_SWITCH_Connect(HI_U8 u8SwitchId,HI_UNF_SWITCH_PORT_E enSwitchPort);
HI_S32 HI_MPI_SWITCH_DisConnect(HI_VOID);
HI_S32 HI_MPI_SWITCH_SetMapPort(HI_U8 u8HdmiPort,HI_U8 u8SwitchId,HI_UNF_SWITCH_PORT_E enSwitchPort);
HI_S32 HI_MPI_SWITCH_UpdateEdid(HI_UNF_SWITCH_EDID_S *pstEdid);
HI_S32 HI_MPI_SWITCH_GetOffLineDetStatus(HI_U8 u8SwitchId,HI_UNF_SWITCH_PORT_E enPort, HI_BOOL *pbConnected);
HI_S32 HI_MPI_SWITCH_SetHDMIOutmode(HI_U8 u8hdmiout);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif

