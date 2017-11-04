#ifndef __DRV_PMOC_IOCTL_H__
#define __DRV_PMOC_IOCTL_H__

#include "hi_unf_pmoc.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

//#define MCU_IRKEY_MAXNUM 6

typedef struct hiC51_PmocDisp_S
{
    unsigned int mode;
    unsigned int value;
}C51_PMOC_DISP_S;

typedef struct hiC51_PmocVal_S
{
    unsigned int irnum;
    unsigned int irlVal[PMOC_WKUP_IRKEY_MAXNUM];
    unsigned int irhVal[PMOC_WKUP_IRKEY_MAXNUM];
    unsigned int keyVal;
    unsigned int timeVal;
    unsigned char usbWakeupMask;
    unsigned char ethWakeupFlag;
    unsigned char resumeResetFlag;
    unsigned int gpioPort;
    unsigned int ddrrefreshFlag;
}C51_PMOC_VAL_S;

typedef enum
{
    C51_PMOC_STAT_NORMAL = 0,   /**<NORMAL*/
    C51_PMOC_STAT_SLOW,         /**<SLOW*/
    C51_PMOC_STAT_DOZE,         /**<DOZE*/
    C51_PMOC_STAT_SLEEP         /**<SLEEP*/
}C51_PMOC_STAT_E;

typedef enum
{
    C51_PMOC_WAKEUP_IR = 0,
    C51_PMOC_WAKEUP_KEY,
    C51_PMOC_WAKEUP_TIME,
    C51_PMOC_WAKEUP_ETH,
    C51_PMOC_WAKEUP_USB,
    C51_PMOC_WAKEUP_GPIO,
    C51_PMOC_WAKEUP_LSADC,
    C51_PMOC_WAKEUP_CEC,
    C51_PMOC_WAKEUP_UART,
    C51_PMOC_WAKEUP_VGA,
    C51_PMOC_WAKEUP_HDMI,
    C51_PMOC_WAKEUP_BUTT
}C51_PMOC_WAKEUP_E;
typedef enum PMOC_SUSPEND_MODE_E
{
    PMOC_SUSPEND_OFF= 0,     /**<Power off */
    PMOC_SUSPEND_MEM,        /**<Suspend to mem */
    PMOC_SUSPEND_DISK,       /**<Suspend to disk */
    PMOC_SUSPEND_BUTT
}PMOC_SUSPEND_MODE_E;

typedef struct PMOC_TIME_S
{
    unsigned int u32Hour;            /**<Hour*/
    unsigned int u32Minute;          /**<Minute*/
    unsigned int u32Second;          /**<Second*/
}PMOC_TIME_S;
typedef enum PMOC_BREATHLED_MODE_E
{
    PMOC_BREATHLED_OFF= 0,     /**<Breathing light off */
    PMOC_BREATHLED_ON,         /**<Breathing light on */
    PMOC_BREATHLED_SMART,      /**<Smart breathing light */
    PMOC_BREATHLED_BUTT
}PMOC_BREATHLED_MODE_E;
typedef struct PMOC_SMARTLEDTIME
{
    PMOC_TIME_S stLedOntime;        /**<Smart breathing light on time */
    PMOC_TIME_S stLedOfftime;       /**<Smart breathing light off time*/
    PMOC_TIME_S stLedCurrenttime;   /**<System current time */
}PMOC_SMARTLEDTIME_S;

typedef struct hiC51_PmocDev_S
{
    unsigned int irtype;  // 0: necsample, 4: raw

#ifdef HI_KEYLED_SUPPORT
    unsigned int kltype;  // 0: std,  1: 6961
#endif

}C51_PMOC_DEV_S;

/* Ioctl definitions */
#define HI_PMOC_STANDBY_CMD              _IOW(HI_ID_PM, 0x01, C51_PMOC_DISP_S)
#define HI_PMOC_SET_WAKEUP_CMD           _IOW(HI_ID_PM, 0x02, C51_PMOC_VAL_S)
#define HI_PMOC_WAKEUP_READY_CMD         _IO (HI_ID_PM, 0x03      )
#define HI_PMOC_WAKEUP_FINISH_CMD        _IOR(HI_ID_PM, 0x04, C51_PMOC_WAKEUP_E)
#define HI_PMOC_WAKEUP_SETDEV_CMD        _IOW(HI_ID_PM, 0x05, C51_PMOC_DEV_S)
#define HI_PMOC_LOAD_MCUCODE_CMD         _IOW(HI_ID_PM, 0x06, HI_U32)
#define HI_PMOC_SET_SCENE_CMD            _IOW(HI_ID_PM, 0x07, HI_UNF_PMOC_SCENE_E)
#define HI_PMOC_SET_PWROFFGPIO_CMD       _IOW(HI_ID_PM, 0x08, HI_U32)
#define HI_PMOC_GET_PERIOD_CMD           _IOW(HI_ID_PM, 0x09, HI_U32)
#define HI_PMOC_ENTER_SMARTSTANDBY_CMD   _IOW(HI_ID_PM, 0x0A, HI_U32)
#define HI_PMOC_QUIT_SMARTSTANDBY_CMD    _IO (HI_ID_PM, 0x0B)
#define HI_PMOC_SET_BREATHLED_CMD        _IOW(HI_ID_PM, 0x0C, HI_U32)
#define HI_PMOC_GET_WAKEUP_CMD           _IOR(HI_ID_PM, 0x0D, C51_PMOC_VAL_S)
#define HI_PMOC_SETKEYPADMASK_CMD        _IOW(HI_ID_PM, 0x0E, HI_U32)
#define HI_PMOC_SET_SUSPEND_MODE_CMD     _IOW(HI_ID_PM, 0x0F, PMOC_SUSPEND_MODE_E)
#define HI_PMOC_GET_SUSPEND_MODE_CMD     _IOR(HI_ID_PM, 0x10, PMOC_SUSPEND_MODE_E)
#define HI_PMOC_SET_SMARTLEDTIME_CMD     _IOW(HI_ID_PM, 0x11, PMOC_SMARTLEDTIME_S)
#define HI_PMOC_SET_BREATHLEDMODE_CMD    _IOW(HI_ID_PM, 0x12, PMOC_BREATHLED_MODE_E)
#define HI_PMOC_GET_CHIP_TEMPERATURE_CMD _IOW(HI_ID_PM, 0x13, HI_S32)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef __DRV_PMOC_IOCTL_H__ */



