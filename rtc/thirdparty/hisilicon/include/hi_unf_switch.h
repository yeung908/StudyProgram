/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_hdmirx.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/09/27
  Description   : 
  History       :
  1.Date        : 2013/09/27
  Author        : t00202585
  Modification  : Created file
******************************************************************************/
#ifndef __HI_UNF_SWITCH_H__
#define __HI_UNF_SWITCH_H__

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

/*************************** Structure Definition ****************************/
/** \addtogroup      HDMI */
/** @{ */  /** <!-- [HDMI] */
/**HDMI port ID *//**CNcomment:HDMI port口ID  */
typedef enum hiUNF_SWITCH_PORT_E
{
    HI_UNF_SWITCH_PORT0,					       /**<SWITCH port 0*/ /**<CNcomment:HDMIRX port0 */
    HI_UNF_SWITCH_PORT1,					       /**<SWITCH port 1*/ /**<CNcomment:HDMIRX port1 */						
    HI_UNF_SWITCH_PORT2,					       /**<SWITCH port 2*/ /**<CNcomment:HDMIRX port2 */
    HI_UNF_SWITCH_PORT3,					       /**<SWITCH port 3*/ /**<CNcomment:HDMIRX port3 */
    HI_UNF_SWITCH_PORT_BUTT
}HI_UNF_SWITCH_PORT_E;

/**the config parameter of EDID interface*/
/**CNcomment:EDID 接口参数配置 */
typedef struct hiUNF_SWITCH_EDID_S
{
    HI_U8 u8SwitchId;
    HI_UNF_SWITCH_PORT_E enSwitchPort;
    HI_U32			u32EdidLength;
    HI_U32   		*pu32Edid;	     /**<HDMIRX EDID Value*//**<CNcomment:HDMIRX EDID 值 */ 				
    HI_U32   		u32CecAddr;	     // 该port口对应的CEC地址	
}HI_UNF_SWITCH_EDID_S;

/** 
\brief the whole initialization of the switch. CNcomment:SWITCH接口驱动软件初始化 CNend
\attention  this func should be called before vo_init and after disp_init. CNcomment:必须在DISP驱动Setup之后和VO驱动Setup之前打开 CNend
\param CNcomment:无 CNend
\retval HI_SUCCESS  success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_SWITCH_Init(HI_VOID);

/** 
\brief deinit the switch. CNcomment:SWITCH接口去初始化 CNend
\attention  this must be called after vo exited and before disp  exited . CNcomment:必须在VO驱动Exit之后和DISP驱动Exit之前打开 CNend
\param CNcomment:无 CNend
\retval HI_SUCCESS      success.CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_SWITCH_DeInit(HI_VOID);

/** 
\brief create SWITCH device.Select the switch ID and input port. CNcomment:创建SWITCH设备,选择输入的SWITCH ID 和连接的 port口 CNend
\attention \n
\param[in] HI_U8                 switch id. CNcomment:要打开的switch ID CNend
\param[in] HI_UNF_SWITCH_PORT_E  switch device id. CNcomment:要打开的switch port口 ID CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_SWITCH_Connect(HI_U8 u8SwitchId,HI_UNF_SWITCH_PORT_E enSwitchPort);

/** 
\brief  set hdmiout mode end
\attention \n
\param[in] HI_UNF_HDMIRX_PORT_E  The port ID  CNcomment: HDMIRX port口ID
\param[in] *HI_BOOL  callback the port OffLineDetect Status CNcomment:回调函数，返回当前口离线检测状态 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_SWITCH_SetHDMIOutmode(HI_U8 u8hdmiout);
/** 
\brief disConnect the handler created by  HI_UNF_SWITCH_Connect. CNcomment:销毁由HI_UNF_SWITCH_Connect创建的句柄 CNend
\attention \n
\param CNcomment:无 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_SWITCH_DisConnect(HI_VOID);

/** 
\brief Set the Map bewteen HDMI Port and Switch id and port. CNcomment:设置HDMI Port 口和Switch ID 建立关联
\attention \n
\param[in] HI_U8                 Hdmi Port. CNcomment:HDMI Port CNend
\param[in] HI_U8                 switch id. CNcomment:switch ID CNend
\param[in] HI_UNF_SWITCH_PORT_E  switch port id. CNcomment:要打开的switch port口 ID CNend
\retval HI_SUCCESS   success.   CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_SWITCH_SetMapPort(HI_U8 u8HdmiPort,HI_U8 u8SwitchId,HI_UNF_SWITCH_PORT_E enSwitchPort);

/** 
\brief Update the EDID in SRAM. CNcomment:更新EDID 至SRAM中 CNend
\attention \n
\param[in] *HI_UNF_HDMIRX_EDID_S  key struct point CNcomment: key的结构指针
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_SWITCH_UpdateEdid(HI_UNF_SWITCH_EDID_S *pstEdid);

/** 
\brief  Get the port OffLineDetect Status CNcomment:获取port口离线检测状态 CNend
\attention \n
\param[in] HI_UNF_HDMIRX_PORT_E  The port ID  CNcomment: HDMIRX port口ID
\param[in] *HI_BOOL  callback the port OffLineDetect Status CNcomment:回调函数，返回当前口离线检测状态 CNend
\retval HI_SUCCESS     success.  CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_SWITCH_GetOffLineDetStatus(HI_U8 u8SwitchId,HI_UNF_SWITCH_PORT_E enPort, HI_BOOL *pbConnected);

/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif

