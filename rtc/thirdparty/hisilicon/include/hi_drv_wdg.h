/*
 *  Generic watchdog defines. Derived from..
 *
 * Berkshire PC Watchdog Defines
 * by Ken Hollis <khollis@bitgate.com>
 *
 */

#ifndef _HI_DRV_WDG_H
#define _HI_DRV_WDG_H

#include "hi_debug.h"

#define HI_FATAL_WDG(fmt...) \
    HI_FATAL_PRINT(HI_ID_WDG, fmt)

#define HI_ERR_WDG(fmt...) \
    HI_ERR_PRINT(HI_ID_WDG, fmt)

#define HI_WARN_WDG(fmt...) \
    HI_WARN_PRINT(HI_ID_WDG, fmt)

#define HI_INFO_WDG(fmt...) \
    HI_INFO_PRINT(HI_ID_WDG, fmt)

#if    defined(CHIP_TYPE_hi3716h)  \
    || defined(CHIP_TYPE_hi3716c)  \
    || defined(CHIP_TYPE_hi3716m)  \
    || defined(CHIP_TYPE_hi3712)
#define HI_WDG_NUM  (1)
#elif  defined(CHIP_TYPE_hi3716cv200es)
#define HI_WDG_NUM  (3)
#elif  defined(CHIP_TYPE_hi3716cv200)   \
    || defined(CHIP_TYPE_hi3716mv400)   \
    || defined(CHIP_TYPE_hi3718cv100)   \
    || defined(CHIP_TYPE_hi3719cv100)   \
    || defined(CHIP_TYPE_hi3718mv100)   \
    || defined(CHIP_TYPE_hi3719mv100)   \
    || defined(CHIP_TYPE_hi3719mv100_a)
#define HI_WDG_NUM  (2)
#elif  defined(CHIP_TYPE_hi3751v100) || defined(CHIP_TYPE_hi3751v100b)	\
    || defined(CHIP_TYPE_hi3751v200) || defined(CHIP_TYPE_hi3751v600)	\
    || defined(CHIP_TYPE_hi3751lv500) || defined(CHIP_TYPE_hi3751v500) \
    || defined(CHIP_TYPE_hi3751v300)
#define HI_WDG_NUM  (1)
#else
#error YOU MUST DEFINE  CHIP_TYPE!
#endif

HI_S32 WDG_DRV_ModInit(HI_VOID);
HI_VOID WDG_DRV_ModExit(HI_VOID);

#endif  /* ifndef _HI_DRV_WDG_H */
