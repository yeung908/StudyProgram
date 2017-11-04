/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_tvd_ioctl.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/10/28
  Description   : 
  History       :
  1.Date        : 2013/10/28
    Author      : t00202585/z00185248
    Modification: Created file
******************************************************************************/
#ifndef __DRV_TVD_EXT_H__
#define __DRV_TVD_EXT_H__

#include "hi_type.h"
#include "hi_unf_common.h"
#include "drv_custom_for_tvd.h"

typedef struct
{    
    HI_S32 (*pfnTVDGetNoiseLevel)(HI_U32 *pu32NoiseLevel); 
	HI_S32 (*pfnTVDGet625Mode)(HI_BOOL *pbIs625);
	HI_S32 (*pfnTVDGetTvdSigStatus)(HI_UNF_SIG_STATUS_E *penSigSta);
	
} TVD_EXPORT_FUNC_S;

HI_S32 __init TVD_DRV_ModuleInit(HI_VOID);
HI_VOID __exit TVD_DRV_ModuleExit(HI_VOID);

#endif
