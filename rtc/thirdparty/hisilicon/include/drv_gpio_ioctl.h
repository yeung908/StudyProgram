/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : drv_gpio_ioctl.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2010/07/07
  Description   :
  History       :
  1.Date        : 2010/07/07
    Author      : j40671
    Modification: Created file

******************************************************************************/

#ifndef __DRV_GPIO_IOCTL_H__
#define __DRV_GPIO_IOCTL_H__

#include "hi_drv_gpio.h"

typedef struct hiGPIO_OUTPUT_TYPE_S
{
	HI_U32 u32GpioNo;
    HI_UNF_GPIO_OUTPUTTYPE_E enOutputType;
}GPIO_OUTPUT_TYPE_S;

typedef struct hiGPIO_DIRECT_S
{
    HI_U32  u32GpioNo;
    HI_BOOL bInput;
} GPIO_DIRECT_S;

typedef struct hiGPIO_VALUE_S
{
    HI_U32  u32GpioNo;
    HI_BOOL bHighVolt;
} GPIO_VALUE_S;

/* Ioctl definitions */
#define CMD_GPIO_SET_INT_TYPE   _IOW(HI_ID_GPIO, 0x1, GPIO_DATA_S)          /*set interruput condition*/
#define CMD_GPIO_SET_INT_ENABLE _IOW(HI_ID_GPIO, 0x2, GPIO_DATA_S)          /*set interruput enable or disable*/
#define CMD_GPIO_GET_INT        _IOR(HI_ID_GPIO, 0x3, GPIO_INT_S)           /*get interruput occur*/
#define CMD_GPIO_GET_GPIONUM    _IOR(HI_ID_GPIO, 0x4, GPIO_GET_GPIONUM_S)   /*get gpio max number and group number*/
#define CMD_GPIO_SET_OUTPUTTYPE _IOW(HI_ID_GPIO, 0x5, GPIO_OUTPUT_TYPE_S) 
#define CMD_GPIO_GET_OUTPUTTYPE _IOWR(HI_ID_GPIO,0x6, GPIO_OUTPUT_TYPE_S) 
#define CMD_GPIO_SET_DIRECT     _IOW(HI_ID_GPIO, 0x7, GPIO_DIRECT_S)
#define CMD_GPIO_GET_DIRECT     _IOWR(HI_ID_GPIO,0x8, GPIO_DIRECT_S)
#define CMD_GPIO_SET_VALUE      _IOW(HI_ID_GPIO, 0x9, GPIO_VALUE_S)
#define CMD_GPIO_GET_VALUE      _IOWR(HI_ID_GPIO,0xa, GPIO_VALUE_S)

#endif /* End of #ifndef __HI_DRV_GPIO_H__*/
