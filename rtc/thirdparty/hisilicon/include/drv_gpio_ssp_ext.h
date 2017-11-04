/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_gpio_ssp_ext.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2012/12/23
  Description   : 
  History       :
  1.Date        : 2012/12/23
    Author      : w00184692
    Modification: Created file
******************************************************************************/

#ifndef __DRV_GPIO_SSP_EXT_H__
#define __DRV_GPIO_SSP_EXT_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

typedef struct hiGPIOSSP_INFO_S
{
    HI_U32 u32CsGpioGroup;
    HI_U32 u32CsGpioBit;
    HI_U32 u32ClkGpioGroup;
    HI_U32 u32ClkGpioBit;
    HI_U32 u32DinGpioGroup;
    HI_U32 u32DinGpioBit;
    HI_U32 u32DoutGpioGroup;
    HI_U32 u32DoutGpioBit;
    HI_U32 u32Size;
    HI_U8  *pu8Data;
} GPIOSSP_INFO_S;

typedef struct hiGPIOSSP_EXT_INFO_S
{
    HI_U32 u32CsGpioGroup;
    HI_U32 u32CsGpioBit;
    HI_U32 u32ClkGpioGroup;
    HI_U32 u32ClkGpioBit;
    HI_U32 u32DinGpioGroup;
    HI_U32 u32DinGpioBit;
    HI_U32 u32DoutGpioGroup;
    HI_U32 u32DoutGpioBit;
    HI_U32 u32Addr;
    HI_U32 *pu32Data;
} GPIOSSP_EXT_INFO_S;

HI_S32 GPIOSSP_Read(GPIOSSP_INFO_S *pstInfo);
HI_S32 GPIOSSP_Write(GPIOSSP_INFO_S *pstInfo);

HI_S32 GPIOSSP_EXT_Read(GPIOSSP_EXT_INFO_S *pstInfo);
HI_S32 GPIOSSP_EXT_Write(GPIOSSP_EXT_INFO_S *pstInfo);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif

