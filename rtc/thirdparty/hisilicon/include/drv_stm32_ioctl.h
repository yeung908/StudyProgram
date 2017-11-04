/******************************************************************************

   Copyright (C), 2005-2015, CVTE.

 ******************************************************************************
  File Name     : drv_stm32_ioctl.h
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
#ifndef __HI_DRV_STM32_H__
#define __HI_DRV_STM32_H__

#include <linux/ioctl.h>

#include "hi_unf_stm32.h"
#include "hi_module.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define HI_FATAL_STM32(fmt...) HI_FATAL_PRINT(HI_ID_STM32, fmt)
#define HI_ERR_STM32(fmt...)   HI_ERR_PRINT(HI_ID_STM32, fmt)
#define HI_WARN_STM32(fmt...)  HI_WARN_PRINT(HI_ID_STM32, fmt)
#define HI_INFO_STM32(fmt...)  HI_INFO_PRINT(HI_ID_STM32, fmt)
#define HI_DEBUG_STM32(fmt...) HI_DBG_PRINT(HI_ID_STM32, fmt)

#define CMD_STM32_SET_GPIO      _IOW(HI_ID_STM32, 0x00, STM32_GPIO_RW_S)
#define CMD_STM32_GET_GPIO      _IOW(HI_ID_STM32, 0x01, STM32_GPIO_RW_S)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __HI_DRV_STM32_H__ */

