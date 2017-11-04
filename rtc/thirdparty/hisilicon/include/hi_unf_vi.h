/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_drv_vi.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/11/15
  Description   : 
  History       :
  1.Date        : 2013/11/15
    Author      : c00186004/w00248302
    Modification: Created file
******************************************************************************/
/** 
 * \file
 * \brief Describes the information about the video input (VI) module.
          CNcomment:提供VI的相关信息 CNend
 */
#ifndef __HI_UNF_VI_H__
#define __HI_UNF_VI_H__

#include "hi_unf_atv.h"
#include "hi_unf_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*************************** Macro Definition ****************************/
/** \addtogroup     VI */
/** @{ */  /** <!-- [VI] */

/** @} */  /*! <!-- Macro Definition End */

/*************************** Structure Definition ****************************/
/** \addtogroup     VI */
/** @{ */  /** <!-- [VI] */

/**Defines the vi type required in a VI.*/
/**CNcomment:定义VI类型枚举 */
typedef enum hiUNF_VI_TYPE_E
{
    HI_UNF_VI_MAIN,  /**<The main vi*//**<CNcomment: 主通路 */
    HI_UNF_VI_SUB,   /**<The main vi*//**<CNcomment: 次通路， 一屏双显时使用 */
    HI_UNF_VI_VIRTUAL,/* 虚拟VI标志*/

    HI_UNF_VI_BUTT                        
} HI_UNF_VI_TYPE_E;
/**Defines the Interface mode required in a VI.*/
/**CNcomment:定义VI对接时序 */
typedef enum hiUNF_VI_INTF_MODE_E
{
    HI_UNF_VI_INTF_FVHDE = 0,/**<The FVHDE*//**<CNcomment: FVHDE时序 */
    HI_UNF_VI_INTF_BT601,   /**<The BT601*//**<CNcomment: BT601时序 */  
    HI_UNF_VI_INTF_BT656,  /**<The BT656*//**<CNcomment: BT656时序 */
    HI_UNF_VI_INTF_BT1120, /**<The BT1120*//**<CNcomment: BT1120时序 */
    
    HI_UNF_VI_INTF_BUTT
} HI_UNF_VI_INTF_MODE_E;
/**Defines the access type required in a VI.*/
/**CNcomment:定义VI对接接口 */
typedef enum hiUNF_VI_ACCESS_TYPE_E
{
    HI_UNF_VI_ACCESS_TVD = 0,  /**<The access of TVD*//**<CNcomment: TVD接口 */
    HI_UNF_VI_ACCESS_HDDEC,    /**<The access of HDDEC*//**<CNcomment: HDDEC接口 */
    HI_UNF_VI_ACCESS_HDMI,     /**<The access of HDMI*//**<CNcomment: HDMI接口 */
    HI_UNF_VI_ACCESS_EXTERN,   /**<The BT1120*//**<CNcomment: 外部接口，例如:CAMERA */
    
    HI_UNF_VI_ACCESS_BUTT
} HI_UNF_VI_ACCESS_TYPE_E;

/**Defines the attribute of video frame format detect.*/
/**CNcomment: 定义视频帧格式检测属性结构体*/
typedef struct hiUNF_VI_3D_DETECT_ATTR_S
{
    HI_BOOL               bEnable;  /**<Is 3d detect enable or not*//**<CNcomment: 3d格式检测是否使能*/
}HI_UNF_VI_3D_DETECT_ATTR_S;


/**Defines the type of VI csc type.*/
/**CNcomment: 定义VI的输入的Csc类型*/
typedef enum hiUNF_VI_SOURCE_CSC_TYPE_E
{
    HI_UNF_VI_SOURCE_CSC_TYPE_AUTO,                   /**< Auto Type:what type in and what type out */
    HI_UNF_VI_SOURCE_CSC_TYPE_RGB_FULL,               /**< Full Range:force full range in rgb csc*/
    HI_UNF_VI_SOURCE_CSC_TYPE_RGB_LIMIT,              /**< Limit Range:force limit range in rgb csc*/
    
    HI_UNF_VI_SOURCE_CSC_TYPE_BUTT
}HI_UNF_VI_SOURCE_CSC_TYPE_E;


/**Defines the created parameters of vi*/
/** CNcomment:定义同步状态变更参数的结构体 */
typedef struct hiUNF_VI_ATTR_S
{   
    HI_UNF_VI_TYPE_E                  enType;          /**<The type of vi*//**<CNcomment: vi类型，实体vi最多创建两路2D或则一路3D*/     
    HI_BOOL                           bBypassVpss;     /**<Is bypassvpss true or false*//**<CNcomment: 是否bypass视频处理子系统*/
    HI_UNF_VI_ACCESS_TYPE_E           enAccess;        /**<The access of vi*//**<CNcomment: 实体vi对接的输入数据源*/ 
    HI_BOOL                           bGraphicMode;    /**<Is Graphic Mode true or false*//**<CNcomment: Graphic Timing/VideoTiming*/
    HI_UNF_VIDEO_FRAME_PACKING_TYPE_E en3dFmt;         /**<The 2d/3d format*//**<CNcomment: 2D/3D 格式*/
    HI_UNF_VI_INTF_MODE_E             enIntfMode;      /**<The interface mode of vi*//**<CNcomment: 实体vi对接的接口时序类型*/
    HI_BOOL                           bInterlace;      /**<Is interlace or progressive*//**<CNcomment: 逐行隔行信息*/
    HI_RECT_S                         stInputRect;     /**<The crop rect of input window*//**<CNcomment: 输入窗口的裁减区域*/
    HI_U32                            u32Width;        /**<The width of source image*//**<CNcomment: 源图像一帧的宽度,3D格式为单眼宽高*/
    HI_U32                            u32Height;       /**<The height of source height*//**<CNcomment: 源图像一帧的高度，即隔行信号是两场的高度，逐行信号是一帧的高度，3D格式为单眼宽高*/
    HI_U32                            u32FrameRate;    /**<The input framerate*//**<CNcomment: 输入帧率 [24Hz,85]*/
    HI_UNF_COLOR_SPACE_E              enColorSpace;    /**<The color spacet*//**<CNcomment: 彩色空间*/
    HI_UNF_VIDEO_FORMAT_E             enPixFmt;        /**<The pixel of Format,for example,RGB444 YUV444/YUV422*//**<CNcomment: 输入像素格式 RGB444,YUV444/422*/
    HI_UNF_PIXEL_BITWIDTH_E           enBitWidth;      /**<The bit width,max 12bit*//**<CNcomment: 输入位宽 8/10/12BIT*/
    HI_UNF_OVERSAMPLE_MODE_E          enOverSample;    /**<The oversample mode*//**<CNcomment: 过采样模式*/     
    HI_U32                            u32Vblank;       /**<The vblank,for the framepacking*//**<CNcomment: 场消隐区宽度，用于处理3D格式FP*/
    HI_UNF_INPUT_SOURCE_TYPE_E        enSourceType;    /**<The input soure type*//**<CNcomment: 输入信源类型*/
    HI_UNF_COLOR_SYS_E                enColorSys;      /**<The color system*//**<CNcomment: ATV/CVBS信源下的彩色制式*/
    HI_BOOL                           bUserOut;        /**<Is support userout ture or false*//**<CNcomment: 是否支持用户获取帧数据*/
} HI_UNF_VI_ATTR_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      VI*/
/** @{*/  /** <!-- -VI=*/

/**
\brief Initializes the VI module.CNcomment:初始化VI模块 CNend
\attention \n
Before calling ::HI_UNF_VI_Create to create a VI, you must call this application programming interface (API).
CNcomment 在调用VI模块其他接口前，要求首先调用本接口 CNend
\param  N/A
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Init(HI_VOID);
/**
\brief Deinitializes the VI module. CNcomment:去初始化VI模块 CNend
\attention \n
After calling ::HI_UNF_VI_Destroy, and Destroy all vi,Please call this API function. 
CNcomment: 在调用::HI_UNF_VI_Destroy接口销毁所有的VI通路后，调用本接口 CNend
\param N/A
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_DeInit(HI_VOID);
/**
\brief Obtains the default configuration of a VI. CNcomment:获取缺省的VI配置 CNend
\attention \n
It is recommended that you call this API to obtain the default vi attributes before creating a vi. This avoids creation failures due to incomplete or incorrect parameters.
CNcomment:创建VI前建议调用本接口，获取到VI默认属性，避免创建VI时由于参数不全或参数错误导致VI创建不成功现象 CNend
\param[IN] pstViAttr  Pointer to VI attributes. For details, see the description of ::HI_UNF_VI_ATTR_S. CNcomment: 指针类型，VI创建属性，请参见::HI_UNF_VI_ATTR_S. CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend

\see \n
N/A
*/
HI_S32 HI_UNF_VI_GetDefaultAttr(HI_UNF_VI_ATTR_S *pstViAttr);
/**
\brief Create a VI. CNcomment:创建VI CNend
\attention \n
 You can call this API to create a vi. input created attributes, This API return the created vi handle.
CNcomment:创建VI时调用本接口，传入创建属性，返回所创建VI的句柄 CNend
\param[in] pstViAttr  Pointer to VI attributes. For details, see the description of ::HI_UNF_VI_ATTR_S. CNcomment: 指针类型，VI创建属性，请参见::HI_UNF_VI_ATTR_S. CNend
\param[out] phVi  Pointer to VI handle. CNcomment: 指针类型，VI句柄. CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Create(HI_UNF_VI_ATTR_S *pstViAttr, HI_HANDLE *phVi);
/**
\brief Destroy a VI. CNcomment:创建VI CNend
\attention \n
 You can call this API to destroy a vi. input VI handle.
CNcomment:销毁VI时调用本接口，传入需销毁的VI句柄 CNend
\param[in] hVi  VI handle. CNcomment: 32位整数，VI句柄. CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Destroy(HI_HANDLE hVi);
/**
\brief Start a VI. CNcomment:启动VI CNend
\attention \n
 You can call this API to start a vi. input VI handle.
CNcomment:启动VI时调用本接口，传入需启动的VI句柄 CNend
\param[in] hVi  VI handle. CNcomment: 32位整数，VI句柄. CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Start(HI_HANDLE hVi);
/**
\brief Stop a VI. CNcomment:停止VI CNend
\attention \n
 You can call this API to stop a vi. input VI handle.
CNcomment:停止VI时调用本接口，传入需停止的VI句柄 CNend
\param[in] hVi  VI handle. CNcomment: 32位整数，VI句柄. CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Stop(HI_HANDLE hVi);

/**
\brief Update the no standard Information of a VI，special for TV. CNcomment:更新VI的非标信息，TV特有 CNend
\attention \n
 When you need update the no standard Information of a VI, You can call this API.
CNcomment:更新VI的非标信息 CNend
\param[in] hVi  VI handle. CNcomment: 32位整数，VI句柄. CNend
\param[in] pstNstdInfo  Pointer to VI no standard Information. For details, see the description of ::HI_UNF_VIDEO_NONSTD_INFO_S. CNcomment: 指针类型，非标信息属性，请参见::HI_UNF_VIDEO_NONSTD_INFO_S. CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_UpdateNstdInfo(HI_HANDLE hVi, HI_UNF_VIDEO_NONSTD_INFO_S *pstNstdInfo);

/**
\brief User acquired frame from vi. CNcomment:用户态从VI获取帧，一出二的情况下默认dump送给win的图像 CNend
\attention \n
 When you need acquired a frame from VI, You can call this API.
CNcomment:用户态从VI获取帧 CNend
\param[in] hVi  VI handle. CNcomment: 32位整数，VI句柄. CNend
\param[in] pFrameInfo  Pointer to VI frame Information. For details, see the description of ::HI_UNF_VIDEO_FRAME_INFO_S. CNcomment: 指针类型，帧信息属性，请参见::HI_UNF_VIDEO_FRAME_INFO_S. CNend
\param[in] u32TimeoutMs  The time of timeout. CNcomment: 用户态获取帧超时时间. CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_AcquireFrame(HI_HANDLE hVi, HI_UNF_VIDEO_FRAME_INFO_S *pFrameInfo, HI_U32 u32TimeoutMs);
/**
\brief User release frame to vi. CNcomment:用户态释放获取到的帧 CNend
\attention \n
 When you need release a frame to VI, You can call this API.
CNcomment:用户态释放获取到的帧 CNend
\param[in] hVi  VI handle. CNcomment: 32位整数，VI句柄. CNend
\param[in] pFrameInfo  Pointer to VI frame Information. For details, see the description of ::HI_UNF_VIDEO_FRAME_INFO_S. CNcomment: 指针类型，帧信息属性，请参见::HI_UNF_VIDEO_FRAME_INFO_S. CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_ReleaseFrame(HI_HANDLE hVi, const HI_UNF_VIDEO_FRAME_INFO_S *pFrameInfo);

/**
\brief Enable or disable the 3D dectect. CNcomment:使能/去使能3D检测 CNend
\attention \n
 When you need Enable or disable the 3D dectect of a VI, You can call this API.
CNcomment:使能/去使能3D检测 CNend
\param[in] hVi  VI handle. CNcomment: 32位整数，VI句柄. CNend
\param[in] pstVi3dDetectAttr  Pointer to VI 3d detect attr. For details, see the description of ::HI_UNF_VI_3D_DETECT_ATTR_S. CNcomment: 指针类型，3d检测属性，请参见::HI_UNF_VI_3D_DETECT_ATTR_S. CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Set3DDetect(HI_HANDLE hVi, HI_UNF_VI_3D_DETECT_ATTR_S *pstVi3dDetectAttr);
/**
\brief Get the 3D dectect result. CNcomment:获取3D检测结果 CNend
\attention \n
 When you need Get the 3D dectect result of a VI, You can call this API.
CNcomment:获取3D检测结果 CNend
\param[in] hVi  VI handle. CNcomment: 32位整数，VI句柄. CNend
\param[in] pEframeType  Pointer to frame type. For details, see the description of ::HI_UNF_VIDEO_FRAME_PACKING_TYPE_E. CNcomment: 指针类型，3d检测结果，请参见::HI_UNF_VIDEO_FRAME_PACKING_TYPE_E. CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Get3DResult(HI_HANDLE hVi, HI_UNF_VIDEO_FRAME_PACKING_TYPE_E  *pEframeType);
/** @} */  /** <!-- ==== API declaration end ==== */


/**
\brief Set VI source csc type. CNcomment:设置VI的Csc类型 CNend
\attention \n
 When you want to set VI Csc, You can call this API.
CNcomment:设置VI的输入源的Csc类型 CNend
\param[in] hVi  VI handle. CNcomment: 32位整数，VI句柄. CNend
\param[in] pECscType  Pointer to Csc Range type. For details, see the description of ::HI_UNF_VI_CSC_TYPE_E. CNcomment: 指针类型，Csc类型，请参见::HI_UNF_VI_CSC_TYPE_E. CNend
\retval ::HI_SUCCESS Success CNcomment:成功 CNend
\retval ::HI_FAILURE Failure. CNcomment:失败 CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_SetSrcCscType(HI_HANDLE hVi, HI_UNF_VI_SOURCE_CSC_TYPE_E *pEcscType);
/** @} */  /** <!-- ==== API declaration end ==== */


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __HI_UNF_VI_H__ */
