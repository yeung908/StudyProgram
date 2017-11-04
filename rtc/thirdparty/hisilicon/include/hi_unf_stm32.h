/******************************************************************************

   Copyright (C), 2005-2015, CVTE.

 ******************************************************************************
  File Name     : 
  Version       : Initial Draft
  Author        : qiuweibo
  Created       : 2016/7/28
  Last Modified :
  Description   : driver stm32 interface
  Function List :
  History       :
  1.Date        : 2016/7/28
    Author      : qiuweibo
    Modification: Created file

******************************************************************************/
#ifndef __HI_UNF_STM32_H__
#define __HI_UNF_STM32_H__

/* add include here */
//#include <linux/ioctl.h>
//#include "hi_sdk_comm.h"
//#include "hi_module.h"
#include "hi_unf_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */



#define STM32_I2C_PACKET_DATA_LEN_MAX            28

typedef struct hiSTM32_I2C_RW_S
{
    HI_U8 u8Cmd;
    HI_U8 u8SubCmd;
    HI_U8 u8DataLen;
    HI_U8 u8DataBuffer[STM32_I2C_PACKET_DATA_LEN_MAX];
    HI_U8 u8CheckSum;
} STM32_I2C_RW_S, *STM32_I2C_RW_S_PTR;


typedef struct hiSTM32_GPIO_RW_S
{
    HI_U8 u8GpioNb;
    HI_U8 u8GpioValue;
} STM32_GPIO_RW_S, *STM32_GPIO_RW_S_PTR;


#define STM32_I2C_STARTUP_CMD                   0x01
#define STM32_I2C_STARTUP_SUBCMD_EDID           0x00
#define STM32_I2C_STARTUP_SUBCMD_DP_STATUS      0x01




#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_STM32_H__ */

