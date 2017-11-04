#ifndef  __HI_DRV_PMOC_H__
#define  __HI_DRV_PMOC_H__

#include "hi_unf_pmoc.h"
#include "hi_debug.h"

/* add register macro */
#define C51_BASE             0xf8400000
#define C51_SIZE             0x10000
#define C51_DATA             0xe000
#define MCU_CODE_MAXSIZE     0x5000

#define HI_FATAL_PM(fmt...) HI_FATAL_PRINT(HI_ID_PM, fmt)

#define HI_ERR_PM(fmt...)   HI_ERR_PRINT(HI_ID_PM, fmt)

#define HI_WARN_PM(fmt...)  HI_WARN_PRINT(HI_ID_PM, fmt)

#define HI_INFO_PM(fmt...)  HI_INFO_PRINT(HI_ID_PM, fmt)

HI_S32 HI_DRV_PMOC_Init(HI_VOID);
HI_S32 HI_DRV_PMOC_DeInit(HI_VOID);
HI_S32 HI_DRV_PMOC_SwitchSystemMode(HI_UNF_PMOC_MODE_E enSystemMode, HI_UNF_PMOC_ACTUAL_WKUP_E * penWakeUpStatus);
HI_S32 HI_DRV_PMOC_SetWakeUpAttr(HI_UNF_PMOC_WKUP_S_PTR pstAttr);
HI_S32 HI_DRV_PMOC_SetStandbyDispMode(HI_UNF_PMOC_STANDBY_MODE_S_PTR pstStandbyMode);
HI_S32 HI_DRV_PMOC_SetScene(HI_UNF_PMOC_SCENE_E eScene);
HI_S32 HI_DRV_PMOC_SetDevType(HI_UNF_PMOC_DEV_TYPE_S_PTR pdevType);

#endif  /*  __HI_DRV_PMOC_H__ */

