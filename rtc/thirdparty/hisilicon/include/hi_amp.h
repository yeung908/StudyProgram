/******************************************************************************
  Copyright (C), 2004-2050, Hisilicon Tech. Co., Ltd.
******************************************************************************
  File Name     : hi_unf_sound.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/1/22
  Last Modified :
  Description   : header file for audio and video output control
  Function List :
  History       :
  1.Date        :
  Author        : z67193
  Modification  : Created file
******************************************************************************/
/**
 * \file
 * \brief Describes the information about the SOUND (SND) module. CNcomment:提供SOUND的相关信息 CNend
 */

#ifndef  __HI_UNF_AMP_H__
#define  __HI_UNF_AMP_H__

#include "hi_unf_common.h"
#include "hi_board.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

#ifndef HI_BOARD_AMP_TYPE
/*************************** Structure Definition ****************************/
/** \addtogroup      AMP*/
/** @{ */  /** <!--  【AMP】 */

/**Defines the info of amp config. */
/**CNcomment:定义功放的配置信息*/
typedef struct AmpInfo{
    HI_U8 u8DeviceType;      /** <device type of amp*/ /** <CNcomment:功放的型号*/
    HI_U8 u8DeviceAddr;      /** <device address of amp when communicate with i2c */ /** <CNcomment:功放使用I2C通信时使用的器件地址 */
    HI_U8 u8GPIOOutputPolarity; /**<GPIO output mode polarity,it is 0 normally*/ /**<CNcomment:GPIO配置为输出模式的配置，一般配置为0 */
    HI_U8 u8ResetGPIONum;   /** <GPIO number of amp reset pin,if it is GPIO1_5,then the result is 1*8+5=13*/ /** <CNcomment:功放的复位管脚的GPIO号，如GPIO1_5,则为1*8+5=13 */
    HI_U8 u8ResetPolarity;  /** <Polarity of reset pin when amp reset  */ /** <CNcomment:功放复位时复位管脚的电平 */
    HI_U8 u8HWMuteGPIONum;  /** <GPIO number of amp mute pin,if it is GPIO1_5, then the result is 1*8+5=13*/ /** <CNcomment:功放的静音管脚的GPIO号，如GPIO1_5,则为1*8+5=13 */
    HI_U8 u8HWMutePolarity; /** <Polarity of mute pin when amp mute is enable*/ /** <CNcomment:功放静音时复位管脚的电平 */
    HI_U8 u8I2CNum;         /** <I2C channel number that amp use */ /** <CNcomment:功放使用的I2C通道号 */
}AMP_INFO_S;
#endif

/******************************* API declaration *****************************/
/** \addtogroup      AMP */
/** @{ */  /** <!-- [AMP] */

/**
\brief Initializes an AMP device. CNcomment:初始化功放设备驱动 CNend
\attention \n
\param[in] the pointer to the infomation of amp CNcomment: 指向功放信息的指针
\retval ::HI_SUCCESS Success CNcomment:成功  CNend
\see \n
N/A
*/
#ifdef HI_BOARD_AMP_TYPE
HI_S32 HI_AMP_Init(HI_VOID);
#else
HI_S32 HI_AMP_Init(AMP_INFO_S *stAmpInfo);
#endif
/**
\brief Deinitializes an AMP device. CNcomment:去初始化功放设备驱动 CNend
\attention \n
\param N/A
\retval ::HI_SUCCESS Success CNcomment:成功  CNend
\see \n
N/A
*/
HI_S32 HI_AMP_DeInit(HI_VOID);

/**
\brief Mute an AMP device. CNcomment: 设置功放静音 CNend
\attention \n
\param[in] bMute Mute control CNcomment: 是否静音 CNend
\retval ::0 if success CNcomment: 成功 CNend
\retval ::otherwise error code CNcomment: 错误 CNend
\see \n
N/A CNcomment: 无 CNend
 */
HI_S32 HI_AMP_SetMute(HI_BOOL bMute);

/**
\brief Obtains the Mute state of an AMP device. CNcomment: 获取功放静音状态 CNend
\attention \n
\param[out] pbMute Pointer to AMP's Mute state CNcomment: 是否静音 CNend
\retval ::0 if success CNcomment: 成功 CNend
\retval ::otherwise error code CNcomment: 错误 CNend
\see \n
N/A CNcomment: 无 CNend
 */
HI_S32 HI_AMP_GetMute(HI_BOOL *pbMute);

/**
\brief Set SubWoofer volume of an AMP device. CNcomment: 设置功放SubWoofer音量 CNend
\attention \n
\param[in] u32Volume SubWoofer volume CNcomment: 音量大小 CNend
\retval ::0 if success CNcomment: 成功 CNend
\retval ::otherwise error code CNcomment: 错误 CNend
\see \n
N/A CNcomment: 无 CNend
 */
HI_S32 HI_AMP_SetSubWooferVol(HI_U32 u32Volume);

/**
\brief Obtains the SubWoofer volume of an AMP device. CNcomment: 获取功放SubWoofer音量 CNend
\attention \n
\param[out] pu32Volume Pointer to AMP's SubWoofer volume CNcomment: 音量大小 CNend
\retval ::0 if success CNcomment: 成功 CNend
\retval ::otherwise error code CNcomment: 错误 CNend
\see \n
N/A CNcomment: 无 CNend
 */
HI_S32 HI_AMP_GetSubWooferVol(HI_U32 *pu32Volume);

/**
\brief write value to AMP device's register. CNcomment: 给功放寄存器赋值 CNend
\attention \n
\param[in] u32RegAddr register address CNcomment: 寄存器地址 CNend
\param[in] u32ByteSize how many bytes to write.CNcomment:写入多少个字节 CNend
\param[in] pu8Value register value CNcomment: 寄存器值 CNend
\retval ::0 if success CNcomment: 成功 CNend
\retval ::otherwise error code CNcomment: 错误 CNend
\see \n
N/A CNcomment: 无 CNend
*/
HI_S32 HI_AMP_WriteReg(HI_U32 u32RegAddr, HI_U32 u32ByteSize, HI_U8 *pu8Value);

/**
\brief read value of AMP device's register. CNcomment: 读取功放寄存器值 CNend
\attention \n
\param[in] u32RegAddr register address CNcomment: 寄存器地址 CNend
\param[in] u32ByteSize how many bytes to read.CNcomment:读多少个字节 CNend
\param[out] pu8Value register value CNcomment: 寄存器值 CNend
\retval ::0 if success CNcomment: 成功 CNend
\retval ::otherwise error code CNcomment: 错误 CNend
\see \n
N/A CNcomment: 无 CNend
*/
HI_S32 HI_AMP_ReadReg(HI_U32 u32RegAddr, HI_U32 u32ByteSize, HI_U8 *pu8Value);

HI_S32 HI_AMP_SetAMP_EQ(HI_U8 u8AmpEqType,HI_U8 u8AmpEqValue);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif  /*__HI_UNF_AMP_H__*/

