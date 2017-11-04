/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_vbi_ioctl.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2015/02/28
  Description   : 
  History       :
  1.Date        : 2015/02/28
    Author      : ywx218173
    Modification: Created file
******************************************************************************/
#ifndef __DRV_VBI_IOCTL_H__
#define __DRV_VBI_IOCTL_H__

#include <linux/ioctl.h>
#include "hi_unf_vbi.h"
#include "hi_type.h"
#include "hi_drv_vbi.h"

typedef enum hiVBI_INKMODE_E
{
	VBI_INKMODE_OFF = 0,
	VBI_INKMODE_2D_UP_BURST,
	VBI_INKMODE_2D_DOWN_BURST,
	VBI_INKMODE_2D_3LINES_BURST,
	VBI_INKMODE_2D_HORIZONTAL_DIFF ,
	VBI_INKMODE_2D_VERTICAL_UP_DIFF,
	VBI_INKMODE_2D_VERTICAL_DOWN_DIFF,
	VBI_INKMODE_2D_HORIZONTAL_LUMA_CORING_DIFF,
	VBI_INKMODE_2D_HORIZONTAL_CHROMA_CORING_DIFF,

	VBI_INKMODE_BUTT
} VBI_INKMODE_E;

typedef enum hiVBI_SELECT_QTCDATA_E
{
	VBI_QTC_OFF = 0,
	VBI_QTCDATA_LUMAGAIN,
	VBI_QTCDATA_AGC_ERROR_LINEAR,
	VBI_QTCDATA_TIP_LEVEL,
	VBI_QTCDATA_BLANK_LEVEL,
	VBI_QTCDATA_CDTO_ERR,
	VBI_QTCDATA_PHASE_ERR,
	VBI_QTCDATA_DEMOD_PALNC,
	VBI_QTCDATA_DEMOD_PALM,
	VBI_QTCDATA_DEMOD_358,
	VBI_QTCDATA_DEMOD_443,

	VBI_QTCDATA_EQUATOR_CVBS_12BIT,
	VBI_QTCDATA_EQUATOR_CVBS_60BIT,

	VBI_QTCDATA_BUTT
} VBI_SELECT_QTCDATA_E;


typedef struct
{
    HI_U32  u32BufPhyAddr;            /*Physical address of a buffer.*/
    HI_U32  u32BufKerVirAddr;         /*Kernel virtual address of a buffer.*/
    HI_U32  u32BufUsrVirAddr;       /*User virtual address of a buffer.*/
    HI_U32  u32BufSize ;             /*Buffer size, in the unit of byte.*/
} VBI_MMZ_BUF_S;

typedef struct hiDRV_VBI_ACQUIUEBUF_S
{
   	HI_U32 u32AcquireNum;
  
    HI_U32 u32AcquiredNum;

   union
   {
      // HI_UNF_VBI_CC_DATA_S stCCData[VBI_DATA_MAX];
      HI_UNF_VBI_CC_DATA_S *pstCCData;
      HI_UNF_VBI_TT_DATA_S *pstTTData;
	  HI_UNF_VBI_TT_INFO_S *pstTTInfo;
   }unstData;
   
}DRV_VBI_ACQUIUEBUF_S;

typedef struct hiDRV_VBI_ACQUIUEINFO_S
{
   	HI_U32 u32AcquireNum;
  
    HI_U32 u32AcquiredNum;

   union
   {
	  HI_UNF_VBI_TT_INFO_S *pstTTInfo;
   }unstData;
   
}DRV_VBI_ACQUIUEINFO_S;


typedef struct hiDRV_VBI_MMZ_BUF_S
{
    HI_U32  u32BufPhyAddr;            /*Physical address of a buffer.*/     
    HI_U32  u32BufUsrVirAddr;         /*User virtual address of a buffer.*/
    HI_U32  u32BufSize;               /*Buffer size, in the unit of byte.*/
	
} DRV_VBI_MMZ_BUF_S;

typedef struct hiDRV_VBI_DATA_INV_S
{
    HI_BOOL bDataInvEn;

	HI_BOOL bByteInvEn;
} DRV_VBI_DATA_INV_S;


/*---- VBI COMMAND----*/
#define HIIOC_VBI_CONNECT           _IOW('V', 0, HI_UNF_VBI_SRC_ATTR_S)     /* 连接VBI */

#define HIIOC_VBI_DISCONNECT        _IO('V',  1)                            /* 断开VBI */

#define HIIOC_VBI_G_SIGNALINFO      _IOWR('V', 2, HI_UNF_VBI_SIGNALINFO_S *)  /* 获取VBI信号信息 */

#define HIIOC_VBI_S_ATTR            _IOW('V', 3, HI_UNF_VBI_ATTR_S)         /* 设置VBI信号属性 */

#define HIIOC_VBI_G_DATABUF         _IOWR('V', 4, DRV_VBI_ACQUIUEBUF_S)     /* 获取VBI  DATA */

#define HIIOC_VBI_G_DATABUF_ADDR    _IOR('V', 5, DRV_VBI_MMZ_BUF_S)         /* 获取VBI  DATA buf ADDR*/

#define HIIOC_VBI_S_DATAINVEN       _IOW('V', 6, DRV_VBI_DATA_INV_S)

#define HIIOC_VBI_G_DATAINVEN       _IOR('V', 7, DRV_VBI_DATA_INV_S)

#define HIIOC_VBI_G_INFOBUF         _IOWR('V', 8, DRV_VBI_ACQUIUEINFO_S)     /* 获取VBI  DATA */

#define HIIOC_VBI_S_QTCEN           _IOW('V', 9, HI_BOOL)

#define HIIOC_VBI_G_QTCEN           _IOR('V', 10, HI_BOOL)


#endif

