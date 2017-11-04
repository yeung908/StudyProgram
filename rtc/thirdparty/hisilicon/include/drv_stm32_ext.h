/******************************************************************************

   Copyright (C), 2005-2015, CVTE.

 ******************************************************************************
  File Name     : drv_stm32_ext.h
  Version       : Initial Draft
  Author        : qiuweibo
  Created       : 2016/7/28
  Last Modified :
  Description   : 
  Function List :
  History       :
  1.Date        : 2016/7/28
    Author      : qiuweibo
    Modification: Created file

******************************************************************************/
#ifndef __DRV_STM32_EXT_H__
#define __DRV_STM32_EXT_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include "hi_type.h"
#include "hi_unf_stm32.h"


typedef HI_S32 (*FN_STM32_INTF_SetGPIOValue)(HI_U8 u8GPIOno, HI_BOOL bValue);
typedef HI_S32 (*FN_STM32_INTF_GetGPIOValue)(HI_U8 u8GPIOno, HI_U8 *pu8Value);
typedef HI_S32 (*FN_STM32_INTF_WriteByI2C)(STM32_I2C_RW_S_PTR pPacket);
typedef HI_S32 (*FN_STM32_INTF_ReadByI2C)(STM32_I2C_RW_S_PTR pPacket);
typedef HI_U8  (*FN_STM32_INTF_GetI2CPacketCheckSum)(STM32_I2C_RW_S *pPacket);

typedef struct
{    
    FN_STM32_INTF_SetGPIOValue          pfnSTM32_INTF_SetGPIOValue;
    FN_STM32_INTF_GetGPIOValue          pfnSTM32_INTF_GetGPIOValue;
    FN_STM32_INTF_WriteByI2C            pfnSTM32_INTF_WriteByI2C;
    FN_STM32_INTF_ReadByI2C             pfnSTM32_INTF_ReadByI2C;
    FN_STM32_INTF_GetI2CPacketCheckSum  pfnSTM32_INTF_GetI2CPacketCheckSum;
} STM32_EXPORT_FUNC_S;

HI_S32 __init STM32_DRV_ModuleInit(HI_VOID);
HI_VOID __exit STM32_DRV_ModuleExit(HI_VOID);





#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __DRV_STM32_EXT_H__ */

