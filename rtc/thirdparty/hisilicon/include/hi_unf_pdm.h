/******************************************************************************

  Copyright (C), 2011-2021, HiSilicon Technologies Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_pdm.h
  Version       : Initial Draft
  Author        : HiSilicon multimedia software group
  Created       : 2011-xx-xx
  Description   : hi_unf_pdm.h header file
  History       :
  1.Date        : 2011/xx/xx
    Author      : 
    Modification: This file is created.

******************************************************************************/

#ifndef __HI_UNF_PDM_H__
#define __HI_UNF_PDM_H__

#include "hi_unf_common.h"
#include "hi_unf_mce.h"
#include "hi_unf_sound.h"
#include "hi_unf_panel.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif  /* End of #ifdef __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      PDM */
/** @{ */  /** <!-- [PDM] */

/**Defines the base config parameter*/
/** CNcomment:基本配置参数结构体*/
typedef struct hiUNF_PDM_DISP_PARAM_S
{
    HI_UNF_DISP_E               enSrcDisp;          /**<source display*//**<CNcomment: 同源display枚举*/
    HI_UNF_ENC_FMT_E            enFormat;           /**<Format*//**<CNcomment: 制式*/
    HI_U32                      u32Brightness;      /**<Brightness*//**<CNcomment: 亮度*/ 
    HI_U32                      u32Contrast;        /**<Contrast*//**<CNcomment: 对比度*/ 
    HI_U32                      u32Saturation;      /**<Saturation*//**<CNcomment: 饱和度*/
    HI_U32                      u32HuePlus;         /**<HuePlus*//**<CNcomment: 色度*/
    HI_BOOL                     bGammaEnable;       /**<Is Gamma enable*//**<CNcomment: 是否使能gamma*/   
    HI_UNF_DISP_BG_COLOR_S      stBgColor;          /**<Background Color*//**<CNcomment: 背景色*/
    HI_UNF_DISP_INTF_S          stIntf[HI_UNF_DISP_INTF_TYPE_BUTT];     /**<configuration of display interface*//**<CNcomment: 显示接口配置*/
    HI_UNF_DISP_TIMING_S        stDispTiming;       /**<Display timeing*//**<CNcomment: 显示时序*/
    
    HIGO_PF_E                   enPixelFormat;      /**<Pixel format*//**<CNcomment: 像素格式*/
    HI_UNF_DISP_OFFSET_S        stDispOffset;       /**<Display margin info*//**<CNcomment: 显示空白区域*/
    HI_U32                      u32VirtScreenWidth; /**<Virtual screen width*//**<CNcomment: 虚拟屏幕宽*/
    HI_U32                      u32VirtScreenHeight;    /**<Virtual screen height*//**<CNcomment: 虚拟屏幕高*/
    
    HI_UNF_DISP_ASPECT_RATIO_S  stAspectRatio;      /**<The device aspect ratio*//**<CNcomment: 设备宽高比*/
}HI_UNF_PDM_DISP_PARAM_S;

/**PDM sound parameters *//**CNcomment:PDM音频参数数据结构  */
typedef struct hiUNF_PDM_SOUND_PARAM_S
{
    HI_U32                    u32PortNum;  /**<Outport number attached sound*/ /**<CNcomment:绑定到Sound设备的输出端口数*/
    HI_UNF_SND_OUTPORT_S stOutport[HI_UNF_SND_OUTPUTPORT_MAX];  /**<Outports attached sound*/ /**<CNcomment:绑定到Sound设备的输出端口*/
}HI_UNF_PDM_SOUND_PARAM_S;

/**PDM base parameter's type *//**CNcomment:PDM BASE类型数据结构  */
typedef enum hiUNF_PDM_BASEPARAM_TYPE_E
{
    HI_UNF_PDM_BASEPARAM_DISP0 = 0,     /**<DISPLAY0*/ /**<CNcomment:DISPLAY0*/
    HI_UNF_PDM_BASEPARAM_DISP1,         /**<DISPLAY1*/ /**<CNcomment:DISPLAY1*/
    HI_UNF_PDM_BASEPARAM_SOUND0 = 10,   /**<SOUND0*/ /**<CNcomment:SOUND0*/
    HI_UNF_PDM_BASEPARAM_SOUND1,        /**<SOUND1*/ /**<CNcomment:SOUND1*/
    HI_UNF_PDM_BASEPARAM_SOUND2,        /**<SOUND2*/ /**<CNcomment:SOUND2*/

    HI_UNF_PDM_BASEPARAM_BUTT
}HI_UNF_PDM_BASEPARAM_TYPE_E;


/**PDM bootmusic parameters */
/**CNcomment:PDM开机音乐参数数据结构  */
typedef struct hiUNF_BOOT_MUSIC_PARAM_S 
{ 
    HI_BOOL                 bEnable;            /**<Whether bootmusic is enable*//**<CNcomment: 开机音乐是否使能*/
    HI_U32                  u32Volume;          /* volume of bootmusic */ /**<CNcomment: 开机音乐音量*/
    HI_U32                  u32DataLen;         /**<bootmusic data*//**<CNcomment: 开机音乐数据长度 */
    HI_U32                  u32DataPlayLen;     /**<bootmusic data len*//**<CNcomment: 开机音乐播放数据长度 */
}HI_UNF_BOOT_MUSIC_PARAM_S;

/** @} */  /*! <!-- Structure Definition end */

/******************************* API declaration *****************************/
/** \addtogroup      PDM */
/** @{ */  /** <!-- [PDM] */
/** 
\brief Obtains the basic configuration information.  CNcomment:获取BASE配置区信息 CNend
\attention \n
N/A
\param[in]  pstBaseParam   Pointer to the basic parameters.  CNcomment:参数指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetBaseParam(HI_UNF_PDM_BASEPARAM_TYPE_E enType, HI_VOID *pData);


/** 
\brief Modifies the basic configuration information.  CNcomment:更新BASE配置区信息 CNend
\attention \n
N/A
\param[in]  pstBaseParam Pointer to the basic parameters.  CNcomment:参数指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateBaseParam(HI_UNF_PDM_BASEPARAM_TYPE_E enType, HI_VOID *pData);

/** 
\brief Obtains the basic configuration information from the flash memory.  
CNcomment:获取LOGO配置区信息 CNend
\attention \n
N/A
\param[in]  pstLogoParam   Pointer to the logo parameter  CNcomment:参数指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetLogoParam(HI_UNF_MCE_LOGO_PARAM_S *pstLogoParam);

/** 
\brief Modifies the configuration of the logo parameter.  CNcomment:更新LOGO配置区信息 CNend
\attention \n
Update logo parameter, you must invoke this function befor update data of logo
\CNcomment:更新logo参数 CNend
\param[in]  pstLogoParam   Pointer to the logo parameter  CNcomment:参数指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateLogoParam(HI_UNF_MCE_LOGO_PARAM_S *pstLogoParam);


/** 
\brief Obtains the logo data from the flash memory. CNcomment:获取LOGO内容区信息 CNend
\attention \n
N/A
\param[in]  pu8Content Pointer to the logo data that is written from the flash memory CNcomment:内容buf指针 CNend
\param[in]  u32Size  Size of the logo data to be written  CNcomment:内容长度 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetLogoContent(HI_U8 *pu8Content, HI_U32 u32Size);


/** 
\brief Modifies the logo data.  CNcomment:更新LOGO内容区信息 CNend
\attention \n
Update data in logo partition, You must invoke HI_UNF_PDM_UpdateLogoParam to update logo parameter before invoke this function
\CNcomment:更新logo内容 CNend
\param[in]  pu8Content   Pointer to the logo data that is read from the flash memory  CNcomment:内容buf指针 CNend
\param[in]  u32Size   Size of the logo data to be read  CNcomment:内容长度 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateLogoContent(HI_U8 *pu8Content, HI_U32 u32Size);

/** 
\brief Obtains the basic configuration information from the flash memory.  
CNcomment:获取LOGO配置区信息 CNend
\attention \n
N/A
\param[in]  pstLogoParam   Pointer to the logo parameter  CNcomment:参数指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetLogoParamExt(HI_UNF_MCE_LOGO_PARAM_S *pstLogoParam);

/** 
\brief Modifies the configuration of the logo parameter.  CNcomment:更新LOGO配置区信息 CNend
\attention \n
Update logo parameter, you must invoke this function befor update data of logo
\CNcomment:更新logo参数 CNend
\param[in]  pstLogoParam   Pointer to the logo parameter  CNcomment:参数指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateLogoParamExt(HI_UNF_MCE_LOGO_PARAM_S *pstLogoParam);


/** 
\brief Obtains the logo data from the flash memory. CNcomment:获取LOGO内容区信息 CNend
\attention \n
N/A
\param[in]  pu8Content Pointer to the logo data that is written from the flash memory CNcomment:内容buf指针 CNend
\param[in]  u32Size  Size of the logo data to be written  CNcomment:内容长度 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetLogoContentExt(HI_U8 *pu8Content, HI_U32 u32Size);


/** 
\brief Modifies the logo data.  CNcomment:更新LOGO内容区信息 CNend
\attention \n
Update data in logo partition, You must invoke HI_UNF_PDM_UpdateLogoParam to update logo parameter before invoke this function
\CNcomment:更新logo内容 CNend
\param[in]  pu8Content   Pointer to the logo data that is read from the flash memory  CNcomment:内容buf指针 CNend
\param[in]  u32Size   Size of the logo data to be read  CNcomment:内容长度 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateLogoContentExt(HI_U8 *pu8Content, HI_U32 u32Size);


/** 
\brief Obtains the playing configuration information.  CNcomment:获取PLAY配置区信息 CNend
\attention \n
N/A
\param[in]  pstPlayParam   Playing configuration information  CNcomment:参数指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetPlayParam(HI_UNF_MCE_PLAY_PARAM_S *pstPlayParam);

/** 
\brief   Modifies the playing configuration information.  CNcomment:更新PLAY配置区信息 CNend
\attention \n 
Update play parameter, you must invoke this function befor update data of play
\CNcomment:更新play参数，在更新play内容前必须先调用此函数 CNend
\param[in]  pstPlayParam  Playing configuration information  CNcomment:参数指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdatePlayParam(HI_UNF_MCE_PLAY_PARAM_S *pstPlayParam);

/** 
\brief Obtains the data being playing from the flash memory.  CNcomment:获取PLAY内容区信息 CNend
\attention \n
N/A
\param[in]  pu8Content Pointer to the data that is read from the flash memory  CNcomment:内容buf指针 CNend
\param[in]  u32Size  Size of the data being played that is read from the flash memory  CNcomment:内容长度 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetPlayContent(HI_U8 *pu8Content, HI_U32 u32Size);


/** 
\brief Updates the playing data part. CNcomment:更新PLAY内容区信息 CNend
\attention \n
Update data in play partition, You must invoke HI_UNF_PDM_UpdatePlayParam to update plat parameter before invoke this function
\CNcomment:更新play内容，在此函数之前必须先调用HI_UNF_PDM_UpdatePlayParam函数更新play参数 CNend
\param[in]  pu8Content  Pointer to the data that is written to the flash memroy  CNcomment:内容buf指针 CNend
\param[in]  u32Size  Size of the data being played  CNcomment:内容长度 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdatePlayContent(HI_U8 *pu8Content, HI_U32 u32Size);

/** 
\brief Get panel index data. CNcomment:获取屏参索引信息 CNend
\attention \n
N/A
\param[in]  pu32Total  Pointer to the data that is the total number of panel index  CNcomment:panel index总数目数据指针 CNend
\param[in]  pu32Index  Pointer to the data that is the value of current panel index  CNcomment:当前panel index索引数据指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_GetPanelIndex(HI_U32 *pu32Total, HI_U32 *pu32Index);

/** 
\brief Set current panel index data. CNcomment:设置系统使用的屏参索引信息 CNend
\attention \n
This will effective after restart system
\CNcomment:该接口需要重启后生效 CNend
\param[in] u32Index  Panel index value  CNcomment:panel index索引值 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_SetPanelIndex(HI_U32 u32Index);

/** 
\brief Get panel param of special panel index. CNcomment:获取特定索引值的屏参数据 CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index索引值 CNend
\param[in] pstPanelParm  Pointer to the data of panel param  CNcomment:屏参数据指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_GetPanelParam(HI_U32 u32Index, HI_UNF_PANEL_INFO_S *pstPanelParm);

/** 
\brief Get panel param of special panel index. CNcomment:设置特定索引值的屏参数据 CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index索引值 CNend
\param[in] pstPanelParm  Pointer to the data of panel param  CNcomment:屏参数据指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_SetPanelParam(HI_U32 u32Index, HI_UNF_PANEL_INFO_S *pstPanelParm);

/** 
\brief Get PQ config file path of special panel index. CNcomment:获取特定索引值的PQ配置文件路径 CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index索引值 CNend
\param[in] pcPqPath  Pointer to the data of PQ config file path  CNcomment:PQ配置文件路径数据指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_GetPanelPqPath(HI_U32 u32Index, HI_CHAR *pcPqPath);

/** 
\brief Get PQ config file path of special panel index. CNcomment:设置特定索引值的PQ配置文件路径 CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index索引值 CNend
\param[in] pcPqPath  Pointer to the data of PQ config file path  CNcomment:PQ配置文件路径数据指针，路径名最大支持100 个字节 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_SetPanelPqPath(HI_U32 u32Index, HI_CHAR *pcPqPath);

/** 
\brief Get back light PWM value of special panel index. CNcomment:获取特定索引值的静态背光PWM值 CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index索引值 CNend
\param[in] pu32BlPwm  Pointer to the data of back light PWM  CNcomment:静态背光PWM数据指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_GetPanelBlPwm(HI_U32 u32Index, HI_U32 *pu32BlPwm);

/** 
\brief Set back light PWM value of special panel index. CNcomment:设置特定索引值的静态背光PWM值 CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index索引值 CNend
\param[in] u32BlPwm  back light PWM value  CNcomment:静态背光PWM值 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_SetPanelBlPwm(HI_U32 u32Index, HI_U32 u32BlPwm);

/** 
\brief Get back light PWM range value of special panel index. CNcomment:获取特定索引值的静态背光PWM范围值 CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index索引值 CNend
\param[in] pu32BlPwmUserMin  Pointer to the data that is back light PWM minimum value  CNcomment:静态背光PWM最小值数据指针 CNend
\param[in] pu32BlPwmUserMax  Pointer to the data that is back light PWM maximum value  CNcomment:静态背光PWM最大值数据指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_GetPanelBlPwmRange(HI_U32 u32Index, HI_U32 *pu32BlPwmUserMin, HI_U32 *pu32BlPwmUserMax);

/** 
\brief Get back light PWM range value of special panel index. CNcomment:设置特定索引值的静态背光PWM范围值 CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index索引值 CNend
\param[in] pu32BlPwmUserMin  Pointer to the data that is back light PWM minimum value  CNcomment:静态背光PWM最小值数据指针 CNend
\param[in] pu32BlPwmUserMax  Pointer to the data that is back light PWM maximum value  CNcomment:静态背光PWM最大值数据指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_SetPanelBlPwmRange(HI_U32 u32Index, HI_U32 u32BlPwmUserMin, HI_U32 u32BlPwmUserMax);

/** 
\brief Obtains the bootmusic configuration information from the flash memory.  
CNcomment:获取第一个开机音乐信息，在更新第一个开机音乐信息前必须调用这个函数 CNend
\attention \n
N/A
\param[in]  pstBMParam   Pointer to the bootmusic parameter  CNcomment:参数指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetBMParam(HI_UNF_BOOT_MUSIC_PARAM_S *pstBMParam);

/** 
\brief Modifies the configuration of the bootmusic parameter.  CNcomment:更新开机音乐配置区信息 CNend
\attention \n
Update bootmusic parameter, you must invoke this function befor update data of bootmusic
\CNcomment:更新第一个开机音乐参数 CNend
\param[in]  pstBMParam   Pointer to the bootmusic parameter  CNcomment:参数指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateBMParam(HI_UNF_BOOT_MUSIC_PARAM_S *pstBMParam);

/** 
\brief Obtains the bootmusic configuration information from the flash memory.  
CNcomment:获取第二个开机音乐信息，在更新第二个开机音乐时必须调用这个函数 CNend
\attention \n
N/A
\param[in]  pstBMParam   Pointer to the bootmusic parameter  CNcomment:参数指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetBMParamExt(HI_UNF_BOOT_MUSIC_PARAM_S *pstBMParam);

/** 
\brief Modifies the configuration of the bootmusic parameter.  CNcomment:更新开机音乐配置区信息 CNend
\attention \n
Update bootmusic parameter, you must invoke this function befor update data of bootmusic
\CNcomment:更新第二个开机音乐参数 CNend
\param[in]  pstBMParam   Pointer to the bootmusic parameter  CNcomment:参数指针 CNend
\retval ::HI_SUCCESS       Success. CNcomment:成功 CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:空指针 CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:获取Flash分区信息失败 CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:打开Flash分区失败 CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:分配内存失败 CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:读取Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:写Flash分区失败 CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:擦除Flash分区失败 CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:无效操作 CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateBMParamExt(HI_UNF_BOOT_MUSIC_PARAM_S *pstBMParam);

//更新开机音乐数据信息
HI_S32  HI_UNF_PDM_UpdateBootMusicContent(HI_U8 *pu8Content, HI_U32 u32Size);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif




