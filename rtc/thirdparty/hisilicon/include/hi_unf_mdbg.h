/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : mpi_mdbg.h
  Version       : Initial Draft
  Author        : l00212594
  Created       : 2013/10/15
  Description   :

******************************************************************************/

#ifndef __HI_UNF_MDBG_H__
#define __HI_UNF_MDBG_H__

#include "hi_type.h"
#include <asm/ioctl.h>

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/**
 \brief Debug模块初始化 ;
 \attention \n
  无

 \param[in] none

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_UNF_MDBG_Init();

/**
 \brief Debug模块去初始化  ;
 \attention \n
  无

 \param[in] none

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_UNF_MDBG_DeInit();

/**
 \brief 进入调试模式  ;
 \attention \n
  无

 \param[in] bOnOff

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_UNF_MDBG_EnterDebugMode(HI_BOOL bOnOff);

/**
 \brief 获取调试模式  ;
 \attention \n
  无

 \param[in] none

 \retval ::HI_BOOL

 */
extern HI_BOOL  HI_UNF_MDBG_GetDebugMode();

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_UNF_MDBG_H__ */
