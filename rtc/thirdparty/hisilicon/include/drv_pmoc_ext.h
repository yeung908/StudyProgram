#ifndef __DRV_PMOC_EXT_H__
#define __DRV_PMOC_EXT_H__

#include "hi_type.h"

#define PMOC_CEC_CFG_BASE	0xf840E550
#define PMOC_CEC_CFG_LEN	0x100

HI_S32 PMOC_DRV_ModInit(HI_VOID);
HI_VOID PMOC_DRV_ModExit(HI_VOID);

#endif /* __DRV_PMOC_EXT_H__ */

