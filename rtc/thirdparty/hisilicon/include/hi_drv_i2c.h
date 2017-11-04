/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : priv_i2c.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2007/01/23
  Description   :
  History       :
  1.Date        : 2007/01/23
    Author      : j37987
    Modification: Created file

******************************************************************************/

#ifndef __HI_DRV_I2C_H__
#define __HI_DRV_I2C_H__

#include "hi_type.h"
#include "hi_debug.h"

#define HI_FATAL_I2C(fmt...) \
    HI_FATAL_PRINT(HI_ID_I2C, fmt)

#define HI_ERR_I2C(fmt...) \
    HI_ERR_PRINT(HI_ID_I2C, fmt)

#define HI_WARN_I2C(fmt...) \
    HI_WARN_PRINT(HI_ID_I2C, fmt)

#define HI_INFO_I2C(fmt...) \
    HI_INFO_PRINT(HI_ID_I2C, fmt)

#define HI_I2C_SPACE_SIZE 0x1000

#define HI_I2C_REG_REMAP(pvAddr, u32RegAddr)   \
    do {\
        pvAddr = ioremap_nocache(u32RegAddr, HI_I2C_SPACE_SIZE);\
        if (NULL == pvAddr)\
        {\
            HI_ERR_I2C("ioremap REG_ADDR[0x%x] failure!\n", u32RegAddr);\
            return HI_FAILURE;\
        }\
    } while (0)

#define HI_I2C_REG_UNMAP(pvAddr)   iounmap(pvAddr)

#if    defined (CHIP_TYPE_hi3716h)  \
    || defined (CHIP_TYPE_hi3716c)  \
    || defined (CHIP_TYPE_hi3716m)	\
    || defined (CHIP_TYPE_hi3712)
 #define HI_STD_I2C_NUM (5)
#elif  defined (CHIP_TYPE_hi3716cv200es) || defined (CHIP_TYPE_hi3716cv200) \
	|| defined (CHIP_TYPE_hi3719cv100) || defined (CHIP_TYPE_hi3718cv100)
 #define HI_STD_I2C_NUM 6
#elif defined (CHIP_TYPE_hi3719mv100) || defined (CHIP_TYPE_hi3719mv100_a) \
   || defined (CHIP_TYPE_hi3718mv100) 
 #define HI_STD_I2C_NUM 2
#elif defined (CHIP_TYPE_hi3751v100) || defined (CHIP_TYPE_hi3751v100b)
 #define HI_STD_I2C_NUM 8
#elif defined(CHIP_TYPE_hi3751v600) || defined(CHIP_TYPE_hi3751lv500) \
    || defined(CHIP_TYPE_hi3751v500) || defined(CHIP_TYPE_hi3751v300)
 #define HI_STD_I2C_NUM 7
#else
 #error YOU MUST DEFINE  CHIP_TYPE!
#endif

//#define HI_I2C_MAX_NUM_USER      15
//#define HI_STD_I2C_MAX_NUM 5
#define HI_I2C_MAX_NUM_RESERVE 1
#define HI_I2C_MAX_NUM (HI_I2C_MAX_NUM_USER + HI_I2C_MAX_NUM_RESERVE)

#define HI_I2C_MAX_LENGTH  1024

HI_S32  HI_DRV_I2C_Init(HI_VOID);
HI_VOID HI_DRV_I2C_DeInit(HI_VOID);

HI_S32 HI_DRV_I2C_WriteConfig(HI_U32 I2cNum, HI_U8 I2cDevAddr);
HI_S32 HI_DRV_I2C_Write(HI_U32 I2cNum, HI_U8 I2cDevAddr, HI_U32 I2cRegAddr, HI_U32 I2cRegAddrByteNum, HI_U8 * pData,
                        HI_U32 DataLen);
HI_S32 HI_DRV_I2C_Read(HI_U32 I2cNum, HI_U8 I2cDevAddr, HI_U32 I2cRegAddr, HI_U32 I2cRegAddrByteNum, HI_U8 * pData,
                       HI_U32 DataLen);
HI_S32 HI_DRV_I2C_Read_SiLabs(HI_U32 I2cNum, HI_U8 I2cDevAddr, HI_U32 I2cRegAddr, HI_U32 I2cRegAddrByteNum, HI_U8 * pData,
                       HI_U32 DataLen);
HI_S32 HI_I2C_Write_sony(HI_U32 I2cNum, HI_U8 I2cDevAddr, HI_U32 I2cRegAddr, HI_U32 I2cRegAddrByteNum, HI_U8 *pData, HI_U32 DataLen, HI_U8 u8Mode);
HI_S32 HI_I2C_Read_sony(HI_U32 I2cNum, HI_U8 I2cDevAddr, HI_U32 I2cRegAddr, HI_U32 I2cRegAddrByteNum, HI_U8 *pData, HI_U32 DataLen, HI_U8 u8Mode);
HI_S32 HI_DRV_I2C_ReadDirectly(HI_U32 I2cNum, HI_U8 I2cDevAddr, HI_U32 I2cRegAddr, HI_U32 I2cRegAddrByteNum,
                               HI_U8 *pData, HI_U32 DataLen);
HI_S32 HI_DRV_I2C_Write_NoSTOP(HI_U32 I2cNum, HI_U8 I2cDevAddr, HI_U32 I2cRegAddr, HI_U32 I2cRegAddrByteNum,
                               HI_U8 *pData, HI_U32 DataLen);

#endif
