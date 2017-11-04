/*----------------------------------------------------------------------------*
 * Copyright Statement:                                                       *
 *                                                                            *
 *   This software/firmware and related documentation ("MediaTek Software")   *
 * are protected under international and related jurisdictions'copyright laws *
 * as unpublished works. The information contained herein is confidential and *
 * proprietary to MediaTek Inc. Without the prior written permission of       *
 * MediaTek Inc., any reproduction, modification, use or disclosure of        *
 * MediaTek Software, and information contained herein, in whole or in part,  *
 * shall be strictly prohibited.                                              *
 * MediaTek Inc. Copyright (C) 2010. All rights reserved.                     *
 *                                                                            *
 *   BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND     *
 * AGREES TO THE FOLLOWING:                                                   *
 *                                                                            *
 *   1)Any and all intellectual property rights (including without            *
 * limitation, patent, copyright, and trade secrets) in and to this           *
 * Software/firmware and related documentation ("MediaTek Software") shall    *
 * remain the exclusive property of MediaTek Inc. Any and all intellectual    *
 * property rights (including without limitation, patent, copyright, and      *
 * trade secrets) in and to any modifications and derivatives to MediaTek     *
 * Software, whoever made, shall also remain the exclusive property of        *
 * MediaTek Inc.  Nothing herein shall be construed as any transfer of any    *
 * title to any intellectual property right in MediaTek Software to Receiver. *
 *                                                                            *
 *   2)This MediaTek Software Receiver received from MediaTek Inc. and/or its *
 * representatives is provided to Receiver on an "AS IS" basis only.          *
 * MediaTek Inc. expressly disclaims all warranties, expressed or implied,    *
 * including but not limited to any implied warranties of merchantability,    *
 * non-infringement and fitness for a particular purpose and any warranties   *
 * arising out of course of performance, course of dealing or usage of trade. *
 * MediaTek Inc. does not provide any warranty whatsoever with respect to the *
 * software of any third party which may be used by, incorporated in, or      *
 * supplied with the MediaTek Software, and Receiver agrees to look only to   *
 * such third parties for any warranty claim relating thereto.  Receiver      *
 * expressly acknowledges that it is Receiver's sole responsibility to obtain *
 * from any third party all proper licenses contained in or delivered with    *
 * MediaTek Software.  MediaTek is not responsible for any MediaTek Software  *
 * releases made to Receiver's specifications or to conform to a particular   *
 * standard or open forum.                                                    *
 *                                                                            *
 *   3)Receiver further acknowledge that Receiver may, either presently       *
 * and/or in the future, instruct MediaTek Inc. to assist it in the           *
 * development and the implementation, in accordance with Receiver's designs, *
 * of certain softwares relating to Receiver's product(s) (the "Services").   *
 * Except as may be otherwise agreed to in writing, no warranties of any      *
 * kind, whether express or implied, are given by MediaTek Inc. with respect  *
 * to the Services provided, and the Services are provided on an "AS IS"      *
 * basis. Receiver further acknowledges that the Services may contain errors  *
 * that testing is important and it is solely responsible for fully testing   *
 * the Services and/or derivatives thereof before they are used, sublicensed  *
 * or distributed. Should there be any third party action brought against     *
 * MediaTek Inc. arising out of or relating to the Services, Receiver agree   *
 * to fully indemnify and hold MediaTek Inc. harmless.  If the parties        *
 * mutually agree to enter into or continue a business relationship or other  *
 * arrangement, the terms and conditions set forth herein shall remain        *
 * effective and, unless explicitly stated otherwise, shall prevail in the    *
 * event of a conflict in the terms in any agreements entered into between    *
 * the parties.                                                               *
 *                                                                            *
 *   4)Receiver's sole and exclusive remedy and MediaTek Inc.'s entire and    *
 * cumulative liability with respect to MediaTek Software released hereunder  *
 * will be, at MediaTek Inc.'s sole discretion, to replace or revise the      *
 * MediaTek Software at issue.                                                *
 *                                                                            *
 *   5)The transaction contemplated hereunder shall be construed in           *
 * accordance with the laws of Singapore, excluding its conflict of laws      *
 * principles.  Any disputes, controversies or claims arising thereof and     *
 * related thereto shall be settled via arbitration in Singapore, under the   *
 * then current rules of the International Chamber of Commerce (ICC).  The    *
 * arbitration shall be conducted in English. The awards of the arbitration   *
 * shall be final and binding upon both parties and shall be entered and      *
 * enforceable in any court of competent jurisdiction.                        *
 *---------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 * $RCSfile: mtperipheral.h,v $
 * $Revision: #2 $
 * $Date: 2014/11/25 $
 * $Author: yongchao.lee $
 *
 * Description: Peripherals, such as NOR/NAND/SIF/RTC/PWM/GPIO (and others), are centralized in
 *                   this file
 *---------------------------------------------------------------------------*/

/** @file mtperipheral.h
 *  This header file declares exported APIs of Peripherals, such as NOR/NAND/SIF/RTC/PWM/GPIO.
 */

#ifndef _PERIPHERAL_H_
#define _PERIPHERAL_H_

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include "mttype.h"
#include <asm-generic/ioctl.h>
//#include "x_pwr_ctrl.h"

//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------
#define SMC_SLOT_NO1            (0)
#define SMC_SLOT_NO2            (1)

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------
/*!
* smart card 协议类型定义
*/
typedef enum 
{
    MTAL_SMC_PROTOCOL_T0,
    MTAL_SMC_PROTOCOL_T0_DVN,
    MTAL_SMC_PROTOCOL_T1,
    MTAL_SMC_PROTOCOL_T14 = 14
} mtal_smc_protocol_t;

typedef struct  {
    UINT8 u1Magic1;         ///< MTK fix value = 0x53.
    UINT8 u1Magic2;         ///< MTK fix value = 0x81.
//    UINT8 u1PanelIdx;       ///< MTK internal setting value.
    UINT8 u1Flags;			///< MTK internal setting value.
//    UINT32 u4Skip;          // NIM configuration.
    UINT8 u1Upgrade;
    UINT8 u1Upgrade_Ext;
    UINT8 u1Flags2;
    UINT8 u1Flags3;    
    UINT8 u1Flags4;        
    UINT8 u1Checksum;
} EEPDTVCFG_T;
typedef struct
{
     UINT8  ui2SrcStatus_av1;
     UINT8  ui2SrcStatus_av2;
	 UINT8  ui2SrcStatus_ypbpr1;	 
	 UINT8  ui2SrcStatus_vga;
	 UINT8  ui2SrcStatus_hdmi1;
	 UINT8  ui2SrcStatus_hdmi2;
	 UINT8  ui2SrcStatus_hdmi3;
	 UINT8  ui2SrcStatus_hdmi4;
} LNVTV_SOURCE_DETECT_STATUS_T;

/* Device ID */
typedef struct 
{
    UINT8   aui1_dev_id[8];    
} MTPC_DEV_ID_T;	//_PC_DEV_ID_T

//T8032
typedef struct
{
    UINT8 u1Cmd;
    UINT8 u1SubCmd;    
    UINT8 au1Data[4];        
} MTPDWNC_T8032_CMD_T;

typedef struct
{
    UINT8 u1Ack;
    UINT8 au1Data[3];        
} MTPDWNC_T8032_RESPONSE_T;

//PDWNC
typedef struct 
{
    UINT32 u4Reason;
    UINT32 u4Btn;
} MTPDWNC_SET_POWER_DOWN_REASON_T;

//wakeup reason
typedef enum {
    MT_WAKE_UP_REASON_UNKNOWN = 0,
    MT_WAKE_UP_REASON_VGA,
    MT_WAKE_UP_REASON_RTC,
    MT_WAKE_UP_REASON_FP,
    MT_WAKE_UP_REASON_IRRC,
    MT_WAKE_UP_REASON_UART,
    MT_WAKE_UP_REASON_AC_POWER,
    MT_WAKE_UP_REASON_HDMI,
    MT_WAKE_UP_REASON_UART_NORMAL,
    MT_WAKE_UP_REASON_RC_DIGIT_0,
    MT_WAKE_UP_REASON_RC_DIGIT_1,
    MT_WAKE_UP_REASON_RC_DIGIT_2,
    MT_WAKE_UP_REASON_RC_DIGIT_3,
    MT_WAKE_UP_REASON_RC_DIGIT_4,
    MT_WAKE_UP_REASON_RC_DIGIT_5,
    MT_WAKE_UP_REASON_RC_DIGIT_6,
    MT_WAKE_UP_REASON_RC_DIGIT_7,
    MT_WAKE_UP_REASON_RC_DIGIT_8,
    MT_WAKE_UP_REASON_RC_DIGIT_9,
    MT_WAKE_UP_REASON_RC_PRG_UP,
    MT_WAKE_UP_REASON_RC_PRG_DOWN,
    MT_WAKE_UP_REASON_RC_INP_SRC,
    MT_WAKE_UP_REASON_RC_ANALOG,
    MT_WAKE_UP_REASON_RC_DIGITAL,
    MT_WAKE_UP_REASON_RC_DIGITAL_ANALOG,
    MT_WAKE_UP_REASON_FP_PRG_UP,
    MT_WAKE_UP_REASON_FP_PRG_DOWN,
    MT_WAKE_UP_REASON_FP_INP_SRC,
    MT_WAKE_UP_REASON_DVD,
    MT_WAKE_UP_REASON_CUSTOM_1 = 61, 
    MT_WAKE_UP_REASON_CUSTOM_2 = 62, 
    MT_WAKE_UP_REASON_CUSTOM_3 = 63, 
    MT_WAKE_UP_REASON_CUSTOM_4 = 64,
    } MT_WAKE_UP_REASON_T;

// GPIO
typedef enum {
  GPIO_IN = 0,
  GPIO_OUT=1,
  } MTGPIO_DIR_T;

typedef VOID (* MTPFN_GPIO_CALLBACK)(INT32 i4Gpio, BOOL fgStatus, VOID* pvArg);
//maybe defined in mt5881_driver/inc/x_gpio.h
#ifndef GPIO_THREAD_ENABLE
#define GPIO_THREAD_ENABLE 1
#endif

typedef enum {
    MTGPIO_TYPE_NONE = 0,
    MTGPIO_TYPE_INTR_RISE = 1,        
    MTGPIO_TYPE_INTR_FALL = 2,
    MTGPIO_TYPE_INTR_BOTH = 3,
    MTGPIO_TYPE_INTR_LEVEL_HIGH = 4,    
    MTGPIO_TYPE_INTR_LEVEL_LOW = 8,
#if GPIO_THREAD_ENABLE
    MTGPIO_TYPE_POLL_FALL = 9,
    MTGPIO_TYPE_POLL_RISE = 10,
    MTGPIO_TYPE_POLL_BOTH = 11,
#endif /* GPIO_THREAD_ENABLE */
    MTGPIO_TYPE_LAST = 12,
    MTGPIO_TYPE_INTR_LEVEL = 13
} MTGPIO_TYPE_T;

#define OPCTRL0                 (200)       ///< define gpio macro for OPCTRL0
#define OPCTRL1                 (201)       ///< define gpio macro for OPCTRL1
#define OPCTRL2                 (202)       ///< define gpio macro for OPCTRL2
#define OPCTRL3                 (203)       ///< define gpio macro for OPCTRL3
#define OPCTRL4                 (204)       ///< define gpio macro for OPCTRL4
#define OPCTRL5                 (205)       ///< define gpio macro for OPCTRL5
#define OPCTRL6                 (206)       ///< define gpio macro for OPCTRL6
#define OPCTRL7                 (207)       ///< define gpio macro for OPCTRL7
#define OPCTRL8                 (208)       ///< define gpio macro for OPCTRL8
#define OPCTRL9                 (209)       ///< define gpio macro for OPCTRL9
#define OPCTRL10                (210)       ///< define gpio macro for OPCTRL10
#define OPCTRL11                (211)       ///< define gpio macro for OPCTRL11

/** GPIO callback parameter */
typedef struct 
{
    INT32 i4Gpio;
    BOOL fgStatus;
    UINT32 u4Pfn;
    UINT32 u4Arg;
}MTGPIO_CB_T;


//  RTC
typedef VOID (*MTPFN_RTC_ALERT_HANDLER_T)(VOID);
typedef VOID (*MTPFN_RTC_WEAKEUP_HANDLER_T)(VOID);
/** RTC date time structure
 */
typedef struct
{
    UINT8   u1Year;
    UINT8   u1Month;
    UINT8   u1Day;
    UINT8   u1Hour;
    UINT8   u1Minute;
    UINT8   u1Second;
    UINT8   u1Week;    
} MTRTC_T;

//PWM
typedef enum
{
    PWM_SRC0=0,
    PWM_SRC1,
    PWM_SRC2,
} MTPWMSRC_TYPE_T;

#define    PWM_PHASE_0      (0x00)
#define    PWM_PHASE_90     (0x40)
#define    PWM_PHASE_180    (0x80)
#define    PWM_PHASE_270    (0xC0)

typedef struct __MtPwmSetting {
    MTPWMSRC_TYPE_T ePwmSrc;
    UINT32          u4DutyOn;
} MTPWMSET_TYPE_T;

//SIF
typedef enum
{
    SIF_PORT_0=0,
    SIF_PORT_1,
    SIF_PORT_TUNER,
    SIF_PORT_PDWNC,
    SIF_PORT_PDWNC_1,
} MTSIFPORT_TYPE_T;

// IRRX
typedef enum {
  MTIR_TYPE_NEC = 0,
  MTIR_TYPE_RC56 = 1,
  MTIR_TYPE_SHARP = 2,
  MTIR_TYPE_USR = 3,  
  MTIR_TYPE_DEFAULT = 0xff  
} MTIR_TYPE_T;


typedef enum
{
    MTIRRX_RAW_DATA_NONE = 0,
    MTIRRX_RAW_DATA_NEC,
    MTIRRX_RAW_DATA_RC5,
    MTIRRX_RAW_DATA_RC6,
    MTIRRX_RAW_DATA_FACTORY,    
}   MTIRRX_RAW_DATA_TYPE_T;


#define MTIR_IRRX_MAX_RAW_DATA_SIZE                  ((UINT8) 11) /* byte */
typedef struct 
{
    UINT8     u1Protocol;
    UINT32              u4Len; /* byte */
    UINT8               au1Data[MTIR_IRRX_MAX_RAW_DATA_SIZE];
}   MTIR_IRRX_RAW_DATA_T;


//PINMUX
#ifdef CC_MT5363                                            // Physical
#define MX0                     (32*0)
#define MX1                     (32*1)
#define MX2                     (32*2)
#define MX3                     (32*3)
#define MX4                     (32*5)
#define PDMX                    (32*6)
#define PDGPIO                  (32*6)
#define PINMUX_NO_PIN           (30 + MX0)  // no pin
#define JTDO                                        (0 + MX0)   // GPIO 0
#define JTMS                    (0 + MX0)   // GPIO 1
#define JTDI                    (0 + MX0)   // GPIO 2
#define JTDI_I                          (0 + MX0)   // GPIO 2, alias
#define JTCK                    (0 + MX0)   // GPIO 3
#define JTRST                   (0 + MX0)   // GPIO 4
#define POCE1                   (2 + MX0)   // GPIO 5
#define PARB                    (3 + MX0)   // GPIO 6
#define POWE                              (3 + MX0)     // GPIO 7
#define PAALE                             (3 + MX0)     // GPIO 8
#define PACLE                           (3 + MX0)   // GPIO 9
#define PDD2                      (6 + MX0)   // GPIO 10
#define PDD3                    (6 + MX0)   // GPIO 11
#define PDD4                    (6 + MX0)   // GPIO 12
#define PDD5                                        (6 + MX0)   // GPIO 13
#define PDD6                        (6 + MX0)   // GPIO 14
#define PDD7                        (6 + MX0)   // GPIO 15

#define OSDA0                                       (10 + MX0)  // GPIO 17
#define OSCL0                                       (10 + MX0)  // GPIO 18
#define OSDA1                                       (12 + MX0)  // GPIO 19
#define OSCL1                                       (12 + MX0)  // GPIO 20
#define OSDA2                                       (14 + MX0)  // GPIO 21
#define OSCL2                                       (14 + MX0)  // GPIO 22
#define OPWM0                                       (16 + MX0)  // GPIO 23
#define OPWM1                                       (18 + MX0)  // GPIO 24
#define OPWM2                                       (20 + MX0)  // GPIO 25
#define U1RX                                        (21 + MX0)  // GPIO 26
#define U1TX                                        (21 + MX0)  // GPIO 27
#define ALIN                                        (20 + MX2)  // GPIO 28
#define ASPDIFO                                 (24 + MX2)  // GPIO 29
#define AOMCLK                                  (0 + MX2)       // GPIO 30
#define AOLRCK                                  (0 + MX2)       // GPIO 31
#define AOBCK                                       (0 + MX2)       // GPIO 32
#define AOSDATA0                                (0 + MX2)       // GPIO 33
#define AOSDATA1                                (2 + MX2)       // GPIO 34
#define AOSDATA2                                (3 + MX2)       // GPIO 35
#define AOSDATA3                                (4 + MX2)       // GPIO 36
#define AOSDATA4                                (6 + MX2)       // GPIO 37
#define TUNER_CLK                               (26 + MX2)  // GPIO 38
#define TUNER_DATA                          (26 + MX2)  // GPIO 39
#define IF_AGCO                                 (28 + MX2)  // GPIO 40
#define RF_AGCO                                 (29 + MX2)  // GPIO 41
#define CI_MDO0                                 (8 + MX2)       // GPIO 42
#define CI_MCLKO                                (8 + MX2)       // GPIO 43
#define CI_MOVAL                                (8 + MX2)       // GPIO 44
#define CI_MOSTRT                               (8 + MX2)       // GPIO 45
#define CI_MDI0                                 (11 + MX2)  // GPIO 46
#define CI_MCLKI                                (11 + MX2)  // GPIO 47
#define CI_MIVAL                                (11 + MX2)  // GPIO 48
#define CI_MISTRT                               (11 + MX2)  // GPIO 49
#define VCXO                                        (22 + MX0)  // GPIO 50


#define PINMUX_GPIO_00                  (0 + MX1)       // GPIO 51
#define PINMUX_GPIO_01                  (2 + MX1)       // GPIO 52
#define PINMUX_GPIO_02                  (4 + MX1)       // GPIO 53
#define PINMUX_GPIO_03                  (27 + MX1)  // GPIO 54
#define PINMUX_GPIO_04                  (6 + MX1)       // GPIO 55
#define PINMUX_GPIO_05                  (6 + MX1)       // GPIO 56
#define PINMUX_GPIO_06                  (6 + MX1)       // GPIO 57
#define PINMUX_GPIO_07                  (6 + MX1)       // GPIO 58
#define PINMUX_GPIO_08                  (6 + MX1)       // GPIO 59
#define PINMUX_GPIO_09                  (6 + MX1)       // GPIO 60
#define PINMUX_GPIO_10                  (8 + MX1)       // GPIO 61
#define PINMUX_GPIO_11                  (8 + MX1)       // GPIO 62
#define PINMUX_GPIO_12                  (8 + MX1)       // GPIO 63
#define PINMUX_GPIO_13                  (8 + MX1)       // GPIO 64
#define PINMUX_GPIO_14                  (8 + MX1)       // GPIO 65
#define PINMUX_GPIO_15                  (8 + MX1)       // GPIO 66
#define PINMUX_GPIO_16                  (11 + MX1)  // GPIO 67
#define PINMUX_GPIO_17                  (11 + MX1)  // GPIO 68
#define PINMUX_GPIO_18                  (11 + MX1)  // GPIO 69
#define PINMUX_GPIO_19                  (11 + MX1)  // GPIO 70
#define PINMUX_GPIO_20                  (11 + MX1)  // GPIO 71
#define PINMUX_GPIO_21                  (11 + MX1)  // GPIO 72
#define PINMUX_GPIO_22                  (14 + MX1)  // GPIO 73
#define PINMUX_GPIO_23                  (14 + MX1)  // GPIO 74
#define PINMUX_GPIO_24                  (14 + MX1)  // GPIO 75
#define PINMUX_GPIO_25                  (14 + MX1)  // GPIO 76
#define PINMUX_GPIO_26                  (16 + MX1)  // GPIO 77
#define PINMUX_GPIO_27                  (16 + MX1)  // GPIO 78
#define PINMUX_GPIO_28                  (16 + MX1)  // GPIO 79
#define PINMUX_GPIO_29                  (16 + MX1)  // GPIO 80
#define PINMUX_GPIO_30                  (16 + MX1)  // GPIO 81
#define PINMUX_GPIO_31                  (16 + MX1)  // GPIO 82
#define PINMUX_GPIO_32                  (16 + MX1)  // GPIO 83
#define PINMUX_GPIO_33                  (18 + MX1)  // GPIO 84
#define PINMUX_GPIO_34                  (18 + MX1)  // GPIO 85
#define PINMUX_GPIO_35                  (18 + MX1)  // GPIO 86
#define PINMUX_GPIO_36                  (18 + MX1)  // GPIO 87
#define PINMUX_GPIO_37                  (20 + MX1)  // GPIO 88
#define PINMUX_GPIO_38                  (20 + MX1)  // GPIO 89
#define PINMUX_GPIO_39                  (20 + MX1)  // GPIO 90
#define PINMUX_GPIO_40                  (22 + MX1)  // GPIO 91
#define PINMUX_GPIO_41                  (22 + MX1)  // GPIO 92
#define PINMUX_GPIO_42                  (22 + MX1)  // GPIO 93
#define PINMUX_GPIO_43                  (22 + MX1)  // GPIO 94
#define PINMUX_GPIO_44                  PINMUX_NO_PIN   // GPIO 95, only gpio function, no sel, set to a reveresd bit field
#define AOL0_ADAC                               (0 + MX3)       // GPIO 96
#define AOR0_ADAC                               (2 + MX3)       // GPIO 97
#define AOL1_ADAC                               (4 + MX3)       // GPIO 98
#define AOR1_ADAC                               (8 + MX3)       // GPIO 99
#define AOL2_ADAC                               (11 + MX3)  // GPIO 100
#define AOR2_ADAC                               (14 + MX3)  // GPIO 101

#define O0P                                         (26 + MX3)  // GPIO 103
#define O0N                                         (26 + MX3)  // GPIO 104
#define O1P                                         (26 + MX3)  // GPIO 105
#define O1N                                         (26 + MX3)  // GPIO 106
#define O2P                                         (26 + MX3)  // GPIO 107
#define O2N                                         (26 + MX3)  // GPIO 108
#define OCKP                                        (26 + MX3)  // GPIO 109
#define OCKN                                        (26 + MX3)  // GPIO 110
#define O3P                                         (26 + MX3)  // GPIO 111
#define O3N                                         (26 + MX3)  // GPIO 112
#define O4P                                         (26 + MX3)  // GPIO 113
#define O4N                                         (26 + MX3)  // GPIO 114
#define E0P                                         (28 + MX3)  // GPIO 115
#define E0N                                         (28 + MX3)  // GPIO 116
#define E1P                                         (28 + MX3)  // GPIO 117
#define E1N                                         (28 + MX3)  // GPIO 118
#define E2P                                         (28 + MX3)  // GPIO 119
#define E2N                                         (28 + MX3)  // GPIO 120
#define ECKP                                        (28 + MX3)  // GPIO 121
#define ECKN                                        (28 + MX3)  // GPIO 122
#define E3P                                         (28 + MX3)  // GPIO 123
#define E3N                                         (28 + MX3)  // GPIO 124
#define E4P                                         (28 + MX3)  // GPIO 125
#define E4N                                         (28 + MX3)  // GPIO 126
#define TP_VPLL                                 (30 + MX3)  // GPIO 127
#define MII_PHY_TXCLK                       (2 + MX4)       // GPIO 128
#define MII_PHY_TXD0                        (0 + MX4)       // GPIO 129
#define MII_PHY_TXD1                        (0 + MX4)       // GPIO 130
#define MII_PHY_TXD2                        (4 + MX4)       // GPIO 131
#define MII_PHY_TXD3                        (6 + MX4)       // GPIO 132
#define MII_PHY_RXCLK                       (8 + MX4)       // GPIO 133
#define MII_PHY_RXD0                        (0 + MX4)       // GPIO 134
#define MII_PHY_RXD1                        (0 + MX4)       // GPIO 135
#define MII_PHY_RXD2                        (10 + MX4)  // GPIO 136
#define MII_PHY_RXD3                        (12 + MX4)  // GPIO 137
#define MII_PHY_COL                         (14 + MX4)  // GPIO 138
#define MII_PHY_CRS                         (16 + MX4)  // GPIO 139
#define MII_PHY_TXEN                        (0 + MX4)       // GPIO 140
#define MII_PHY_RXDV                        (0 + MX4)       // GPIO 141
#define MII_PHY_TXER                        (18 + MX4)  // GPIO 142
#define MII_PHY_RXER                        (0 + MX4)       // GPIO 143
#define MII_MDC_O                               (0 + MX4)       // GPIO 144
#define MII_MDIO                                (0 + MX4)       // GPIO 145
#define MII_PHY_REFCLK                  (20 + MX4)  // GPIO 146
#define AIL0_AADC                               (24 + MX0)  // GPIO 147
#define AIN_L1_AADC                         (25 + MX0)  // GPIO 148
#define AIN_L2_AADC                         (26 + MX0)  // GPIO 149
#define AIN_L3_AADC                         (27 + MX0)  // GPIO 150
#define AIN_L4_AADC                         (28 + MX0)  // GPIO 151
#define AIN_L5_AADC                         (29 + MX0)  // GPIO 152
#define AIR0_AADC                               (24 + MX0)  // GPIO 153
#define AIN_R1_AADC                         (25 + MX0)  // GPIO 154
#define AIN_R2_AADC                         (26 + MX0)  // GPIO 155
#define AIN_R3_AADC                         (27 + MX0)  // GPIO 156
#define AIN_R4_AADC                         (28 + MX0)  // GPIO 157
#define AIN_R5_AADC                         (29 + MX0)  // GPIO 158

#define PINMUX_OPCTRL_0         (8 + PDMX)  // GPIO 200
#define PINMUX_OPCTRL_1         (10 + PDMX) // GPIO 201
#define PINMUX_OPCTRL_2         (12 + PDMX) // GPIO 202
#define PINMUX_OPCTRL_3         (14 + PDMX) // GPIO 203
#define PINMUX_OPCTRL_4         (26 + PDMX) // GPIO 204
#define PWR5V_2                   (30 + PDMX) // GPIO 205
#define HDMI_SDA2                 (28 + PDMX) // GPIO 206
#define HDMI_SCL2                 (22 + PDMX) // GPIO 207
#define HDMI_HPD1                 (6 + PDMX)    // GPIO 208 only gpio (no other function), bit6 of PDMX is not defined
#define PWR5V_1                   (4 + PDMX)    // GPIO 209
#define HDMI_SDA1                 (24 + PDMX) // GPIO 210
#define HDMI_SCL1                 (25 + PDMX) // GPIO 211

#define OIRI                          (20 + PDMX) // GPIO 215
#define HDMI_CEC                  (0 + PDMX)    // GPIO 216
#define U0RX                        (16 + PDMX) // GPIO 217
#define U0TX                        (16 + PDMX) // GPIO 218
#define HDMI_HPD2                   (2 + PDMX)  // GPIO 219

#endif



//////////////////////////////////////////////

#ifdef CC_MT5391
#define MX0                     (32*0)
#define MX1                     (32*1)
#define MX2                     (32*2)
#define MX3                     (32*3)
#define MX4                     (32*5)
#define PDMX                    (32*6)
#define PDGPIO                  (32*6)

#define POCE0_O                 (2 + MX0)   // GPIO 28
#define POCE1_O                 (4 + MX0)   // GPIO 29
#define POOE_O                  (6 + MX0)   // GPIO 30
#define PARB_I                  (8 + MX0)   // GPIO 31
#define POWE_O                  (10 + MX0)  // GPIO 32
#define PALE_O                  (10 + MX0)  // GPIO 33
#define PCLE_O                  (10 + MX0)  // GPIO 34
#define PDD0_IO                 (12 + MX0)  // GPIO 35
#define PDD1_IO                 (12 + MX0)  // GPIO 36
#define PDD2_IO                 (14 + MX0)  // GPIO 37
#define PDD3_IO                 (14 + MX0)  // GPIO 38
#define PDD4_IO                 (14 + MX0)  // GPIO 39
#define PDD5_IO                 (14 + MX0)  // GPIO 40
#define PDD6_IO                 (14 + MX0)  // GPIO 41
#define PDD7_IO                 (14 + MX0)  // GPIO 42
#define U0RX_I                  (6 + PDMX)  // no gpio
#define U0RX_O                  (6 + PDMX)  // no gpio
#define U2RX_I                  (16 + MX0)  // GPIO 43
#define U2TX_O                  (16 + MX0)  // GPIO 44
#define U2CTS_I                 (18 + MX0)  // GPIO 45
#define U2RTS_O                 (18 + MX0)  // GPIO 46
#define OSDA0_IO                (20 + MX0)  // GPIO 47
#define OSCL0_O                 (20 + MX0)  // GPIO 48
#define OSDA1_IO                (22 + MX0)  // GPIO 49
#define OSCL1_I                 (22 + MX0)  // GPIO 50
#define OPWM0_O                 (4 + PDMX)  // OPCTRL 12
#define OPWM1_O                 (26 + MX0)  // GPIO 54
#define OPWM2_O                 (28 + MX0)  // GPIO 55
#define PINMUX_OPCTRL_0         (0 + PDMX)  // OPCTRL 0 and CEC_IO
#define PINMUX_OPCTRL_6         (PDGPIO)    // OPCTRL 6 and U2RTS_O
#define PINMUX_OPCTRL_7         (PDGPIO)    // OPCTRL 7 and USCRS_I
#define OPWR0_5V                (1 + PDMX)  // OPCTRL 9
#define OPWR1_5V                (2 + PDMX)  // OPCTRL 10
#define OPWR2_5V                (3 + PDMX)  // OPCTRL 11
#define SDIOCLK_O               (30 + MX0)  // GPIO 56
#define SDIOCMD_O               (30 + MX0)  // GPIO 57
#define SDIOD0_O                (30 + MX0)  // GPIO 58
#define SDIOD1_O                (30 + MX0)  // GPIO 59
#define SDIOD2_O                (30 + MX0)  // GPIO 60
#define SDIOD3_O                (30 + MX0)  // GPIO 61
#define TUNER_CLK_O             (0 + MX1)   // GPIO 62
#define TUNER_DATA_IO           (0 + MX1)   // GPIO 63
#define IF_AGC_O                (2 + MX1)   // GPIO 64
#define TS0_CLK_I               (4 + MX1)   // GPIO 65
#define TS0_VALID_I             (4 + MX1)   // GPIO 66
#define TS0_SYNC_I              (4 + MX1)   // GPIO 67
#define TS0_DATA_I              (4 + MX1)   // GPIO 68
#define AO0P                    (6 + MX1)   // GPIO 69
#define AO0N                    (6 + MX1)   // GPIO 70
#define AO1P                    (6 + MX1)   // GPIO 71
#define AO1N                    (6 + MX1)   // GPIO 72
#define AO2P                    (6 + MX1)   // GPIO 73
#define AO2N                    (6 + MX1)   // GPIO 74
#define AOCKP                   (6 + MX1)   // GPIO 75
#define AOCKN                   (6 + MX1)   // GPIO 76
#define AO3P                    (6 + MX1)   // GPIO 77
#define AO3N                    (6 + MX1)   // GPIO 78
#define AO4P                    (6 + MX1)   // GPIO 79
#define AO4N                    (6 + MX1)   // GPIO 80
#define AE0P                    (8 + MX1)   // GPIO 81
#define AE0N                    (8 + MX1)   // GPIO 82
#define AE1P                    (8 + MX1)   // GPIO 83
#define AE1N                    (8 + MX1)   // GPIO 84
#define AE2P                    (8 + MX1)   // GPIO 85
#define AE2N                    (8 + MX1)   // GPIO 86
#define AECKP                   (8 + MX1)   // GPIO 87
#define AECKN                   (8 + MX1)   // GPIO 88
#define AE3P                    (8 + MX1)   // GPIO 89
#define AE3N                    (8 + MX1)   // GPIO 90
#define AE4P                    (8 + MX1)   // GPIO 91
#define AE4N                    (8 + MX1)   // GPIO 92
#define BO0P                    (10 + MX1)  // GPIO 93
#define BO0N                    (10 + MX1)  // GPIO 94
#define BO1P                    (10 + MX1)  // GPIO 95
#define BO1N                    (10 + MX1)  // GPIO 96
#define BO2P                    (12 + MX1)  // GPIO 97
#define BO2N                    (12 + MX1)  // GPIO 98
#define BOCKP                   (12 + MX1)  // GPIO 99
#define BOCKN                   (12 + MX1)  // GPIO 100
#define BO3P                    (12 + MX1)  // GPIO 101
#define BO3N                    (12 + MX1)  // GPIO 102
#define BO4P                    (12 + MX1)  // GPIO 103
#define BO4N                    (12 + MX1)  // GPIO 104
#define BE0P                    (14 + MX1)  // GPIO 105
#define BE0N                    (14 + MX1)  // GPIO 106
#define BE1P                    (14 + MX1)  // GPIO 107
#define BE1N                    (14 + MX1)  // GPIO 108
#define BE2P                    (14 + MX1)  // GPIO 109
#define BE2N                    (14 + MX1)  // GPIO 110
#define BECKP                   (14 + MX1)  // GPIO 111
#define BECKN                   (14 + MX1)  // GPIO 112
#define BE3P                    (14 + MX1)  // GPIO 113
#define BE3N                    (14 + MX1)  // GPIO 114
#define BE4P                    (14 + MX1)  // GPIO 115
#define BE4N                    (14 + MX1)  // GPIO 116
#define ONDA_00_O               (16 + MX1)  // GPIO 117
#define ONDA_01_O               (16 + MX1)  // GPIO 118
#define ONDA_02_O               (16 + MX1)  // GPIO 119
#define ONDA_03_O               (16 + MX1)  // GPIO 120
#define ONDA_04_O               (16 + MX1)  // GPIO 121
#define ONDA_05_O               (16 + MX1)  // GPIO 122
#define ONDA_06_O               (20 + MX1)  // GPIO 123
#define ONDA_07_O               (20 + MX1)  // GPIO 124
#define ONDA_08_O               (24 + MX1)  // GPIO 125
#define ONDA_09_O               (28 + MX1)  // GPIO 126
#define ONDA_10_O               (28 + MX1)  // GPIO 127
#define ONDA_11_O               (0 + MX2)   // GPIO 128
#define ONDA_12_O               (0 + MX2)   // GPIO 129
#define ONDA_13_O               (0 + MX2)   // GPIO 130
#define ONDD_08_IO              (28 + MX1)  // GPIO 131
#define ONDD_09_IO              (28 + MX1)  // GPIO 132
#define ONDD_10_IO              (0 + MX2)   // GPIO 133
#define ONDD_11_IO              (0 + MX2)   // GPIO 134
#define ONDD_12_IO              (28 + MX1)  // GPIO 135
#define ONDD_13_IO              (28 + MX1)  // GPIO 136
#define ONDD_14_IO              (0 + MX2)   // GPIO 137
#define ONDD_15_IO              (28 + MX1)  // GPIO 138
#define ONDOE_O                 (4 + MX2)   // GPIO 139
#define ONDCE0_O                (8 + MX2)   // GPIO 140
#define ONDCE1_O                (12 + MX2)  // GPIO 141
#define ADPDIF_OUT_O            (17 + MX3)  // GPIO 142
#define VCXO_I                  (18 + MX3)  // GPIO 143
#define JTMS_I                  (0 + MX0)   // GPIO 187
#define JTDI_I                  (0 + MX0)   // GPIO 188
#define JTDO_O                  (0 + MX0)   // GPIO 189
#define JTCK_I                  (0 + MX0)   // GPIO 190
#define JTRST_I                 (0 + MX0)   // GPIO 191

#endif




#if (defined CC_MT5365)||defined(CC_MT5395)//||defined(CC_MT5389)


//=====================================================================
// IC information
#define TOTAL_PIN_REG           (9)

//=====================================================================
// Register definitions
#define MX0                     ((1U << 5) | BASIC_MASK)
#define MX1                     ((2U << 5) | BASIC_MASK)
#define MX2                     ((3U << 5) | BASIC_MASK)
#define MX3                     ((4U << 5) | BASIC_MASK)
#define MX4                     ((5U << 5) | BASIC_MASK)
#define MX5                     ((6U << 5) | BASIC_MASK)
#define PDMX                    ((7U << 5) | BASIC_MASK)
#define PHMX                    ((8U << 5) | BASIC_MASK)
#define PMISC                   ((9U << 5) | BASIC_MASK)

#define PIN_ALIN                (MX1 | 3)
#define PIN_ASPDIF              ((MX1 | OFFSETMASK(2,0)) | MULTI_GPIO_FLAG)
#define PIN_AOMCLK              (MX1 | OFFSETMASK(26,24))
#define PIN_AOLRCK              (MX1 | OFFSETMASK(26,24)) // aomclk
#define PIN_AOBCK               (MX1 | OFFSETMASK(26,24)) // aomclk
#define PIN_AOSDATA0            (MX1 | OFFSETMASK(26,24)) // aomclk
#define PIN_AOSDATA1            (MX4 | OFFSETMASK(17,16))
#define PIN_AOSDATA2            (MX0 | OFFSETMASK(1,0))
#define PIN_AOSDATA3            (MX0 | OFFSETMASK(5,4))
#define PIN_AOSDATA4            (MX1 | OFFSETMASK(7,6))
#define PIN_AIN0_L              (MX1 | 15)
#define PIN_AIN0_R              (MX1 | 15)
#define PIN_AIN1_L              (MX1 | 19)
#define PIN_AIN1_R              (MX1 | 19)
#define PIN_AIN2_L              (MX3 | 23)
#define PIN_AIN2_R              (MX3 | 23)
#define PIN_AIN3_L              (MX3 | 27)
#define PIN_AIN3_R              (MX3 | 27)
#define PIN_AIN4_L              (MX3 | 31)
#define PIN_AIN4_R              (MX3 | 31)
#define PIN_AIN5_L              (MX1 | 31)
#define PIN_AIN5_R              (MX1 | 31)
#define PIN_AIN6_L              (MX4 | 15)
#define PIN_AIN6_R              (MX4 | 15)
#define PIN_AR0                 (MX1 | OFFSETMASK(14,12))
#define PIN_AL0                 (MX1 | OFFSETMASK(14,12))
#define PIN_AR1                 (MX1 | OFFSETMASK(10,8))
#define PIN_AL1                 (MX1 | OFFSETMASK(10,8))
#define PIN_AR2                 (MX1 | 27)
#define PIN_AL2                 (MX1 | 27)
#define PIN_AR3                 (MX4 | 31)
#define PIN_AL3                 (MX4 | 31)
#define PIN_ETMDC               (MX2 | OFFSETMASK(1,0))
#define PIN_ETMDIO              (MX2 | OFFSETMASK(3,2))
#define PIN_ETRXDV              (MX2 | OFFSETMASK(5,4))
#define PIN_ETRXD0              (MX2 | OFFSETMASK(7,6))
#define PIN_ETRXD1              (MX2 | OFFSETMASK(9,8))
#define PIN_ETRXD2              (MX2 | OFFSETMASK(11,10))
#define PIN_ETRXD3              (MX2 | OFFSETMASK(13,12))
#define PIN_ETRXCLK             (MX2 | OFFSETMASK(15,14))
#define PIN_ETTXCLK             (MX2 | OFFSETMASK(17,16))
#define PIN_ETTXD0              (MX2 | OFFSETMASK(19,18))
#define PIN_ETTXD1              (MX2 | OFFSETMASK(21,20))
#define PIN_ETTXD2              (MX2 | OFFSETMASK(23,22))
#define PIN_ETTXD3              (MX2 | OFFSETMASK(25,24))
#define PIN_ETTXEN              (MX2 | OFFSETMASK(27,26))
#define PIN_ETCOL               (MX2 | OFFSETMASK(29,28))
#define PIN_ETPHYCLK            (MX2 | OFFSETMASK(31,30))
#define PIN_GPIO0               ((MX1 | OFFSETMASK(30,28)) | MUXHIB(PMISC | 19))
#define PIN_GPIO1               (MX3 | OFFSETMASK(6,4))
#define PIN_GPIO2               (MX3 | OFFSETMASK(14,12))
#define PIN_GPIO3               (MX4 | OFFSETMASK(6,4))
#define PIN_GPIO4               ((MX4 | OFFSETMASK(3,0)) | MULTI_GPIO_FLAG)
#define PIN_GPIO5               ((MX4 | OFFSETMASK(19,18)) | MULTI_GPIO_FLAG)
#define PIN_GPIO6               (MX4 | OFFSETMASK(11,8))
#define PIN_GPIO7               (MX4 | OFFSETMASK(23,20))
#define PIN_GPIO8               (MX0 | OFFSETMASK(19,16))
#define PIN_GPIO9               ((MX0 | OFFSETMASK(11,10)) | MULTI_GPIO_FLAG)
#define PIN_GPIO10              (MX3 | OFFSETMASK(18,16))
#define PIN_GPIO11              (MX3 | OFFSETMASK(2,0))
#define PIN_GPIO12              (MX1 | OFFSETMASK(23,20))
#define PIN_GPIO13              ((MX3 | OFFSETMASK(26,24)) | MUXHIB(PMISC | 16))
#define PIN_GPIO14              ((MX3 | OFFSETMASK(10,8)) | MUXHIB(PMISC | 20) | MULTI_GPIO_FLAG)
#define PIN_GPIO15              ((MX5 | 3) | MUXHIB(PMISC | 17))
#define PIN_GPIO16              (MX1 | 4)
#define PIN_GPIO19              (MX3 | 30)
#define PIN_GPIO20              (MX5 | 11)
#define PIN_GPIO21              (MX5 | 11) // gpio20
#define PIN_GPIO22              (MX5 | 11) // gpio20
#define PIN_GPIO23              (MX5 | 11) // gpio20
#define PIN_GPIO24              ((MX5 | 15) | MUXHIB(PMISC | 18))
#define PIN_GPIO25              (MX5 | 10)
#define PIN_OSDA0               (MX0 | OFFSETMASK(7,6))
#define PIN_OSCL0               (MX0 | OFFSETMASK(7,6)) // osda0
#define PIN_OSDA1               (MX0 | OFFSETMASK(3,2))
#define PIN_OSCL1               (MX0 | OFFSETMASK(3,2)) // osda1
#define PIN_GPIO26              (MX4 | OFFSETMASK(25,24))
#define PIN_GPIO27              (MX1 | 11)
#define PIN_IF_AGC              (MX0 | OFFSETMASK(13,12))
#define PIN_RF_AGC              (MX0 | OFFSETMASK(9,8))
#define PIN_OSDA2               (MX0 | OFFSETMASK(15,14))
#define PIN_OSCL2               (MX0 | OFFSETMASK(15,14)) // osda2
#define PIN_DEMOD_TSCLK         (MX1 | OFFSETMASK(17,16))
#define PIN_DEMOD_TSVAL         (MX3 | OFFSETMASK(29,28))
#define PIN_DEMOD_TSSYNC        (MX4 | OFFSETMASK(27,26))
#define PIN_DEMOD_TSDATA0       (MX4 | OFFSETMASK(27,26)) // demod_tssync
#define PIN_CI_TSCLK            ((MX4 | OFFSETMASK(30,28)) | MULTI_GPIO_FLAG)
#define PIN_CI_TSVAL            ((MX5 | OFFSETMASK(2,0)) | MULTI_GPIO_FLAG)
#define PIN_CI_TSSYNC           ((MX4 | OFFSETMASK(30,28)) | MULTI_GPIO_FLAG)
#define PIN_CI_TSDATA0          ((MX4 | OFFSETMASK(30,28)) | MULTI_GPIO_FLAG)
#define PIN_PVR_TSCLK           (MX5 | OFFSETMASK(6,4))
#define PIN_PVR_TSVAL           (MX5 | OFFSETMASK(6,4)) // pvr_tsclk
#define PIN_PVR_TSSYNC          (MX5 | OFFSETMASK(6,4)) // pvr_tsclk
#define PIN_PVR_TSDATA0         (MX3 | OFFSETMASK(21,20))
#define PIN_PVR_TSDATA1         (MX1 | 5)
#define PIN_SPI_CLK             (MX5 | OFFSETMASK(9,8))
#define PIN_SPI_DATA            (MX5 | OFFSETMASK(9,8)) // spi_clk
#define PIN_SPI_CLE             (MX0 | OFFSETMASK(31,30))
#define PIN_CI_INT              (MX4 | OFFSETMASK(14,13))
#define PIN_JTDO                (MX5 | 7)
#define PIN_JTCK                (MX5 | 7) // jtdo
#define PIN_JTMS                (MX5 | 7) // jtdo
#define PIN_JTDI                (MX5 | 7) // jtdo
#define PIN_JTRST_              (MX5 | 7) // jtdo
#define PIN_OPWM0               (MX0 | OFFSETMASK(21,20))
#define PIN_OPWM1               (MX0 | OFFSETMASK(23,22))
#define PIN_OPWM2               (MX0 | OFFSETMASK(25,24))
#define PIN_VGA_SCL             (PDMX | OFFSETMASK(22,20))
#define PIN_U0RX                (PDMX | OFFSETMASK(13,12))
#define PIN_VGA_SDA             (PDMX | OFFSETMASK(22,20))
#define PIN_U0TX                (PDMX | OFFSETMASK(13,12))
#define PIN_OIRI                (PDMX | 14)
#define PIN_OPWRSB              (PDMX | 15)
#define PIN_OPCTRL0             (PDMX | OFFSETMASK(1,0))
#define PIN_OPCTRL1             (PDMX | OFFSETMASK(3,2))
#define PIN_OPCTRL2             (PDMX | OFFSETMASK(6,4))
#define PIN_OPCTRL3             (PDMX | OFFSETMASK(19,18))
#define PIN_OPCTRL4             (PDMX | OFFSETMASK(9,8))
#define PIN_OPCTRL5             (PDMX | OFFSETMASK(11,10))
#define PIN_POCE0_              (MX3 | 7)
#define PIN_POOE_               (MX3 | 7) // poce0
#define PIN_POCE1_              (MX3 | 11)
#define PIN_PARB_               (MX5 | OFFSETMASK(14,12))
#define PIN_POWE_               (MX5 | OFFSETMASK(18,16))
#define PIN_PAALE               (MX5 | OFFSETMASK(22,20))
#define PIN_PACLE               (MX5 | OFFSETMASK(25,23))
#define PIN_PDD0                (MX0 | OFFSETMASK(27,26))
#define PIN_PDD1                (MX0 | OFFSETMASK(27,26)) // ==PDD0
#define PIN_PDD2                (MX5 | OFFSETMASK(28,26))
#define PIN_PDD3                (MX5 | OFFSETMASK(28,26)) // ==PDD2
#define PIN_PDD4                (MX5 | OFFSETMASK(28,26)) // ==PDD2
#define PIN_PDD5                (MX5 | OFFSETMASK(28,26)) // ==PDD2
#define PIN_PDD6                ((MX5 | OFFSETMASK(31,29)) | MULTI_GPIO_FLAG)
#define PIN_PDD7                ((MX5 | OFFSETMASK(31,29)) | MULTI_GPIO_FLAG)
#define PIN_ADIN2               (PDMX | 28)
#define PIN_ADIN3               (PDMX | 29)
#define PIN_ADIN4               ((PDMX | 30) | MUXHIB(PDMX | 27))
#define PIN_ADIN5               (PDMX | 31)
#define PIN_HDMI_CEC            (PDMX | OFFSETMASK(17,16))
#define PIN_HDMI_SCL            (PHMX | OFFSETMASK(2,0))
#define PIN_HDMI_SDA            (PHMX | OFFSETMASK(6,4))
#define PIN_PWR5V               (PHMX | OFFSETMASK(10,8))
#define PIN_HDMI_HPD            (PHMX | OFFSETMASK(14,12))
#define PIN_TP_VPLL             (MX1 | 18)
#define PIN_AE0P                (MX0 | 28)
#define PIN_AE0N                (MX0 | 28)
#define PIN_AE1P                (MX0 | 28)
#define PIN_AE1N                (MX0 | 28)
#define PIN_AE2P                (MX0 | 28)
#define PIN_AE2N                (MX0 | 28)
#define PIN_AECKP               (MX0 | 28)
#define PIN_AECKN               (MX0 | 28)
#define PIN_AE3P                (MX0 | 28)
#define PIN_AE3N                (MX0 | 28)
#define PIN_AE4P                (MX0 | 28)
#define PIN_AE4N                (MX0 | 28)
#define PIN_AE5P                (MX0 | 28)
#define PIN_AE5N                (MX0 | 28)
#define PIN_AO0P                (MX0 | 29)
#define PIN_AO0N                (MX0 | 29)
#define PIN_AO1P                (MX0 | 29)
#define PIN_AO1N                (MX0 | 29)
#define PIN_AO2P                (MX0 | 29)
#define PIN_AO2N                (MX0 | 29)
#define PIN_AOCKP               (MX0 | 29)
#define PIN_AOCKN               (MX0 | 29)
#define PIN_AO3P                (MX0 | 29)
#define PIN_AO3N                (MX0 | 29)
#define PIN_AO4P                (MX0 | 29)
#define PIN_AO4N                (MX0 | 29)
#define PIN_AO5P                (MX0 | 29)
#define PIN_AO5N                (MX0 | 29)
#define PIN_U1RX                (MX4 | 12)
#define PIN_U1TX                (MX4 | 12) // u1rx

// gpio pin without pinmux
#define PIN_GPIO17              (PMISC | 31) // no pinmux
#define PIN_GPIO18              (PMISC | 31) // no pinmux
#define PIN_DEMOD_RST           (PMISC | 31) // no pinmux
#define PIN_ORESET_             (PMISC | 31) // no pinmux
#define PIN_ADIN0               (PMISC | 31) // no pinmux
#define PIN_ADIN1               (PMISC | 31) // no pinmux
#define PIN_VSYNC               (PMISC | 31) // no pinmux
#define PIN_HSYNC               (PMISC | 31) // no pinmux

// backward compatible
#define PINMUX_OPCTRL_0         PIN_OPCTRL0

//-----------------------------------------------------------------------------
// Macro definitions (IC independant)
//-----------------------------------------------------------------------------
#define PINMUX_FUNCTION0        0
#define PINMUX_FUNCTION1        1
#define PINMUX_FUNCTION2        2
#define PINMUX_FUNCTION3        3
#define PINMUX_FUNCTION4        4
#define PINMUX_FUNCTION5        5
#define PINMUX_FUNCTION6        6
#define PINMUX_FUNCTION7        7
#define PINMUX_FUNCTION8        8
#define PINMUX_FUNCTION9        9
#define PINMUX_FUNCTION10       10
#define PINMUX_FUNCTION11       11
#define PINMUX_FUNCTION12       12
#define PINMUX_FUNCTION13       13
#define PINMUX_FUNCTION14       14
#define PINMUX_FUNCTION15       15

#define IS_VALID_MUX_REG(pin)   (((pin) & (0x0fU << 5)) != 0)
#define OFFSETMASK(ebit, sbit)  ((BITNUM_TO_MASK((ebit) - (sbit)) << 12) | (sbit))
#define MUXHIB(x)               ((x) << 16)
#define MAX_FUNC(pin)           (LO_MAX_FUNC(pin) | (HI_MAX_FUNC(pin) << (MASK_TO_BITNUM(LO_MAX_FUNC(pin))+1)))
#define BITNUM_TO_MASK(m)       (((m) > 1) ? (((m)==2) ? 7 : 15) : (((m)==1) ? 3 : 1))
#define MASK_TO_BITNUM(m)       (((m) > 3) ? (((m)==7) ? 2 : 3) : (((m)==1) ? 0 : 1))
#define MULTI_GPIO_FLAG         (1U << 10)
#define BASIC_MASK              (1U << 12)

#define LO_BIT_OFFSET(pin)      ((pin >> 0) & 0x1fU)
#define LO_MUX_REG(pin)         (((pin) >> 5) & 0x0fU)
#define LO_MAX_FUNC(pin)        (((pin) >> 12) & 0x0fU)
#define LO_MASK(pin)            (LO_MAX_FUNC(pin))
#define HI_BIT_OFFSET(pin)      (((pin) >> 16) & 0x1fU)
#define HI_MUX_REG(pin)         (((pin) >> 21) & 0x0fU)
#define HI_MAX_FUNC(pin)        (((pin) >> 28) & 0x0fU)
#define HI_MASK(pin)            (HI_MAX_FUNC(pin))


#endif

#if defined(CC_MT5389)
#define PDMX                    (32*6)
#define BASIC_MASK              (1U << 12)
#define MX0                     ((1U << 5) | BASIC_MASK)

#define OPWM0_O                 (4 + PDMX)  // OPCTRL 12
#define OPWM1_O                 (26 + MX0)  // GPIO 54
#define OPWM2_O                 (28 + MX0)  // GPIO 55

#endif





#define MTPOWER_WAK_GPIO0       (1U << 0)
#define MTPOWER_WAK_GPIO1       (1U << 1)
#define MTPOWER_WAK_GPIO2       (1U << 2)
#define MTPOWER_WAK_GPIO3       (1U << 3)
#define MTPOWER_WAK_GPIO4       (1U << 4)
#define MTPOWER_WAK_GPIO5       (1U << 5)
#define MTPOWER_WAK_GPIO6       (1U << 6)
#define MTPOWER_WAK_GPIO7       (1U << 7)
#define MTPOWER_WAK_IRRX        (1U << 8)
#define MTPOWER_WAK_VGA         (1U << 9)
#define MTPOWER_WAK_RTC         (1U << 15)    
#define MTPOWER_WAK_UART         (1U << 16)        
#define MTPOWER_WAK_CEC         (1U << 17)
#define MTPOWER_WAK_HDMI        (1U << 18)
#define MTPOWER_WAK_UNOR        (1U << 19)
#define MTPOWER_WAK_SERVOAD0       (1U << 20)
#define MTPOWER_WAK_SERVOAD1       (1U << 21)
#define MTPOWER_WAK_SERVOAD2       (1U << 22)
#define MTPOWER_WAK_SERVOAD3       (1U << 23)
#define MTPOWER_WAK_SERVOAD4       (1U << 24)
#define MTPOWER_WAK_SERVOAD5       (1U << 25)
#define MTPOWER_WAK_SERVOAD6       (1U << 26)

/** GPIO callback parameter */
typedef struct 
{
    UINT8 u1Status;
}MTSMC_CB_T;

/**This callback function for Smart Card module.
*/
typedef VOID (*MTSMC_PFN_CB_T) (UINT8 u1Status);

/** EEPROM property */
typedef struct 
{
    UINT32 u4Size;
    UINT32 u4MwOffset;
}MTEEPROM_PROPERTY_T;

//Set BW Parameter
typedef enum
{
    BM_MODULE_OSD1=0,
    BM_MODULE_OSD2,
    MAX_BW_MODULE_NUM,
} MTSET_BW_MODULE_TYPE_T;

typedef enum
{
    SBWP_OSD_CONT_REQ_LMT0=0,
    SBWP_OSD_PAUSE_CNT,
    SBWP_OSD_VAC_TH,
    SBWP_OSD_FIFO_SIZE,
    SBWP_OSD_CONT_REQ_LMT,
} MTSET_BW_PARAMETER_OSD_T;

//-----------------------------------------------------------------------------
#define MTGSPI_CPHA		(0x01)
#define MTGSPI_CPOL		(0x02)
#define MTGSPI_MODE_0		(0|0)
#define MTGSPI_MODE_1		(0|GSPI_CPHA)
#define MTGSPI_MODE_2		(GSPI_CPOL|0)
#define MTGSPI_MODE_3		(GSPI_CPOL|GSPI_CPHA)
#define MTGSPI_LSB_FIRST	(0x08)

#define MTGSPI_READ	(1U << 0)
#define MTGSPI_WRITE	(1U << 1)

typedef struct
{
    UINT32 u4Mode;
	UINT32 uBits;
	UINT32 u4Freq;
    UINT32 u4CsLead; //The latency between CS low and valid DATA output.
	UINT32 u4CsLag;  //The latency between valid DATA output and CS high.
	UINT32 u4CsHold; //The output CS hold time.
} MTPDWNC_GSPI_MODE_T;

typedef struct
{
    UINT32 u4Arg1;
    UINT32 u4Arg2;
    UINT32 u4Arg3;
    UINT32 u4Arg4;
    UINT32 u4Arg5;
    UINT32 u4Arg6;
    UINT32 u4Arg7;
} MTPDWNC_CB_T;

typedef VOID (*MTPDWNC_PFN_RESUME_CB)(
    UINT32 u4Reason, 
    UINT32 u4Other
);

typedef struct
{
    UINT32 u4Reason;
    UINT32 u4Other;
} MTPDWNC_RESUME_REASON_T;

typedef enum
{
    MTPDWNC_CB_FUNC_RESUME
} MTPDWNC_CB_FUNC_ENUM_T;

EXTERN MT_RESULT_T MTPDWNC_RegCbFunc(MTPDWNC_CB_FUNC_ENUM_T eFuncType, UINT32 u4FuncPtr, UINT32 u4Arg1);
EXTERN MT_RESULT_T MTPDWNC_UnRegCbFunc(MTPDWNC_CB_FUNC_ENUM_T eFuncType, UINT32 u4FuncPtr, UINT32 u4Arg1);
//-----------------------------------------------------------------------------


#define MMC_BLOCK_MAJOR		179
#define MMC_IOC_PON_ON _IO(MMC_BLOCK_MAJOR, 1)
#define MMC_IOC_PON_SHORT _IO(MMC_BLOCK_MAJOR, 2)
#define MMC_IOC_PON_LONG _IO(MMC_BLOCK_MAJOR, 3)
#define MMC_IOC_GET_EXTCSD _IO(MMC_BLOCK_MAJOR, 4)
#define MMC_IOC_VENDOR_CMD _IO(MMC_BLOCK_MAJOR, 5)
#define MMC_IOC_READ_SINGLE _IO(MMC_BLOCK_MAJOR, 6)
#define MMC_IOC_GET_CID _IO(MMC_BLOCK_MAJOR, 7)
#define MMC_IOC_GEN_CMD_WR _IO(MMC_BLOCK_MAJOR, 8)
#define MMC_IOC_GEN_CMD_RD _IO(MMC_BLOCK_MAJOR, 9)
#define MMC_IOC_READ_MULTIPLE _IO(MMC_BLOCK_MAJOR, 10)
#define MMC_IOC_GEN_CMD _IO(MMC_BLOCK_MAJOR, 11)
#define MMC_IOC_CLAIM_HOST _IO(MMC_BLOCK_MAJOR, 12)
#define MMC_IOC_RELEASE_HOST _IO(MMC_BLOCK_MAJOR, 13)
#define MMC_IOC_IOS_CLK_SET  _IO(MMC_BLOCK_MAJOR, 14)
//-----------------------------------------------------------------------------
// Public functions
//-------------------------------------------------------------------------
/** MTDDI_UART_AccessReg enable/disable uart_dbg normal mode access register function
 *  @param u4CLIFlag  u4CLIFlag enable=TRUE/disable=FALSE
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T MTDDI_UART_AccessReg(UINT32 u4CLIFlag);


//-----------------------------------------------------------------------------
//GPIO
//-------------------------------------------------------------------------
/** MTGPIO_Init
 *  Initialize GPIO module.
 *  @param  VOID
 *  @return  VOID
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTGPIO_Init (VOID) ;

//-----------------------------------------------------------------------------
/** MTGPIO_SetDirection()  The GPIO Direction (in/out) setting function.
 *  @param i4GpioNum the gpio number to set.
 *  @param eDir Direction in or out
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTGPIO_SetDirection (INT32 i4GpioNum, MTGPIO_DIR_T eDir) ;

//-----------------------------------------------------------------------------
/** MTGPIO_GetDirection()  The GPIO Direction (in/out) setting function.
 *  @param i4GpioNum the gpio number to set.
 *  @retval MTGPIO_DIR_T, gpio direction
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTGPIO_GetDirection (INT32 i4GpioNum, MTGPIO_DIR_T * pdirection) ;

//-----------------------------------------------------------------------------
/** MTGPIO_QueryOutVal()  The GPIO Direction out (low/high) query function.
 *  @param i4GpioNum the gpio number to query.
 *  @retval MTGPIO_DIR_T, gpio direction
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTGPIO_QueryOutVal (INT32 i4GpioNum, INT32 * pdirection);

//-----------------------------------------------------------------------------
/** MTGPIO_Output()  The GPIO out (low/high) set function.
 *  @param i4GpioNum the gpio number to set.
 *  @param pu4Val high/low.
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTGPIO_Output (INT32 i4GpioNum, INT32 * pu4Val);

//-----------------------------------------------------------------------------
/** MTGPIO_Intrq() The GPIO interrupt enable setting functions. It will check
 *  the i4GpioNum and set to related register bit as 0 or 1.  In this
 *  function, 0 is interrupt disable mode and 1 is interrupt enable mode.
 *  @param i4GpioNum the gpio number to set or read.
 *  @param pi4Intr A integer pointer. It should not be NULL, it must
 *  reference to a integer.  If the integer is 0, this function will set the
 *  mode of the gpio number as interrupt disable mode, otherwise set as
 *  interrupt enable mode.
 *  @It return 0 or 1 (0 is interrupt disable mode,
 *          1 is interrupt enable mode.), return (*pi4Intr).
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTGPIO_Intrq (INT32 i4GpioNum, const INT32 *pi4Intr) ;

//-----------------------------------------------------------------------------
/** MTGPIO_IntrqQuery() Query the GPIO interrupt enable setting functions.
 *  @pi4Intr, it return 0 or 1 (0 is interrupt disable mode,
 *          1 is interrupt enable mode.) 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTGPIO_IntrqQuery(INT32 i4GpioNum, const INT32 *pi4Intr);

//-----------------------------------------------------------------------------
/** MTGPIO_Query()  The GPIO interrupt query  functions. It will read abd return interrupt
 *  setting register bit.
 *  @param i4Gpio the gpio number to read.
 *  @param *pi4Intr Interrupt is set (=1) or not(=0)
 *  @param *pi4Fall  Falling Edge Interrupt is set (=1) or not(=0)
 *  @param *pi4Rise  Rising Edge Interrupt is set (=1) or not(=0)
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTGPIO_Query (INT32 i4Gpio, INT32 *pi4Intr, INT32 *pi4Fall, INT32 *pi4Rise) ;

//-----------------------------------------------------------------------------
/** MTGPIO_Reg()  The GPIO Interrupt Callback register funciton. It will copy and keep callback
  * funciton pointer (pfnCallback) in data stucture.
 *  @param i4Gpio the gpio number to read.
 *  @param eType Interrupt type, such as double-edge, rising edge, and falling edge.
 *  @param u4Period Interrupt Duration (ms)
 *  @param pfnCallback  Interrupt Callback function
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 *  For this API, u4Period is used for MTGPIO_TYPE_INTR_LEVEL_HIGH or MTGPIO_TYPE_INTR_LEVEL_LOW.  
 *  For the level trigger, the system will callback the pfnCallback when the level is still on the state to trigger interrupt.  
 *  But the interrupt is not continuous, it is periodical by the u4Period parameter.  The pvArg is the callback function parameter.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTGPIO_Reg (INT32 i4Gpio, MTGPIO_TYPE_T eType, UINT32 u4Period, MTPFN_GPIO_CALLBACK pfnCallback, VOID* pvArg);

//-----------------------------------------------------------------------------
/** MTGPIO_SetOut() to set gpio output value.
 *  @param i4GpioNum
 *  @param i4Val 0 or 1.
 *  @retval to return current gpio out register setting.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTGPIO_SetOut (INT32 i4GpioNum, INT32 i4Val) ;

//-----------------------------------------------------------------------------
/** MTGPIO_GetIn()  The GPIO input setting and reading  functions. It will check the
 *  i4GpioNum, set its as an input pin,  and read its polarity register bit to return.
 *  @param i4GpioNum the gpio number to read.
 *  @retval 0 or 1.  (GPIO input value.)
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTGPIO_GetIn (INT32 i4GpioNum, UINT8 *pi4Val) ;


//PWM
//-----------------------------------------------------------------------------
/** MTPWM_SetFrequency()  This driver control the PWM0 & PWM1 output
 *  frequence and duty cycle
 *  @param eSrc      PWM source (SrcPWM0/1/2)
 *  @param u4Frequency Frequency demanded (in Hz)
 *  @param u4DutyOn  Duty cycle percentage multiple by 10, ex. u4DutyOn =367 -->36.7% Duty Cycle
 *  @param fgEnable
 *  @return MT_RESULT_T
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTPWM_SetFrequency(MTPWMSRC_TYPE_T eSrc, UINT32 u4Frequency, UINT32 u4DutyOn, BOOL fgEnable);

EXTERN MT_RESULT_T MTLNVTV_GetSignalStatus(UINT8* pu8SignalStatus);
//-----------------------------------------------------------------------------
/** MTPWM_SetPhase()  This API controls the phase between PWMs.
 *  Must the same frequency and must both enable.
 *  @param prPwm1 PWM source1 and duty
 *  @param prPwm2 PWM source2 and duty
 *  @param u4Frequency Frequency demanded (in Hz)
 *  @param u1Phase phase between src1 and src2
 *  @return MT_RESULT_T
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTPWM_SetPhase(MTPWMSET_TYPE_T *prPwm1, MTPWMSET_TYPE_T *prPwm2, UINT32 u4Frequence, UINT8 u1Phase);

//-----------------------------------------------------------------------------
/** MTPWM_SetVsyncAlign  pwm align with vsync enalbe or disable
 *  @param eSrc      PWM source (SrcPWM0/1/2)
 *  @param fgEnable enable=TRUE/disable=FALSE
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTPWM_SetVsyncAlign(MTPWMSRC_TYPE_T eSrc, BOOL fgEnable);
//-----------------------------------------------------------------------------
/** MTSYS_SetScanPWMEnable()  This driver enable the SCANPWM Function
 *  @param fgEnable
 *  @return MT_RESULT_T
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSYS_SetScanPWMEnable (BOOL fgEnable);

//-----------------------------------------------------------------------------
/** MTPWM_SetScanPWM()  This driver control the SCANPWM output
 *  duty cycle
 *  @param eSrc      PWM source (SrcPWM0/1/2)
 *  @param u4DutyOn  Duty cycle percentage multiple by 10, ex. u4DutyOn =367 -->36.7% Duty Cycle
 *  @param fgEnable
 *  @return MT_RESULT_T
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTPWM_SetScanPWM(MTPWMSRC_TYPE_T eSrc, UINT32 u4Start, UINT32 u4DutyOn, BOOL fgEnable, BOOL fgDoubleFreq, BOOL fgStepControl);

EXTERN MT_RESULT_T MTPWM_ScanPWMAutoTestEn(BOOL bOnOff, UINT8 u1Src, UINT8 u1Chg, UINT8 u1Double, INT32 i4Start, UINT32 u4Bottom, UINT32 u4Top);
//Servo ADC
//-----------------------------------------------------------------------------
/** MTPDWNC_ReadServoADCChannelValue() Read the ServoADC Channel Value
 *  @param u4Channel the channel number
 *  @retval the channel adc value (0-255).
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTPDWNC_ReadServoADCChannelValue(UINT32 u4Channel, UINT8* pu1Value);

//----------------------------------------------------------------------------
/** MTPDWNC_EnterStandby()
 *  @param i4PinSel, Pin Name
 *  @param i4Func, Pin Function Number
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTPDWNC_EnterStandby (UINT32 u4StandbyEvent);

//-------------------------------------------------------------------------
/** MTPDWNC_EnterPowerDown,MTPDWNC_RequestSuspendEvent
 *  Let ARM enter standby mode
 *  @param  _u4PowerDownEn
 *  @param  u4PowerDownType
 *  @return  VOID
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTPDWNC_EnterPowerDown (UINT32 u4PowerDownEn, UINT32 u4PowerDownEvent); 
EXTERN MT_RESULT_T  MTPDWNC_RequestSuspendEvent (UINT32 u4SuspendEn, UINT32 u4SuspendEvent); 


//----------------------------------------------------------------------------
/** MTPDWNC_EnterPowerState()
 *  @param u4PdwncEvent
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTPDWNC_EnterPowerState (UINT32 u4PdwncEvent); 

//-------------------------------------------------------------------------
/** MTPDWNC_Reboot
 *  reboot IC by watchdog
 *  @param  VOID
 *  @return  VOID
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T MTPDWNC_Reboot (VOID);

//-------------------------------------------------------------------------
/** MTPDWNC_Reboot1
 *  reboot IC by watchdog
 *  @param  VOID
 *  @return  VOID
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T MTPDWNC_Reboot1 (VOID);

//----------------------------------------------------------------------------
/** MTPDWNC_PowerDownByAcCut() 
 *  @param  u4Reason
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTPDWNC_PowerDownByAcCut (UINT32 *u4Reason);

//----------------------------------------------------------------------------
/** MTIRRC_IsPowerButtonOff() 
 *  @param  u4Reason
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTIRRC_IsPowerButtonOff (UINT32 *u4Reason);

//----------------------------------------------------------------------------
/** MTPDWNC_T8032Cmd() T8032 command/response interface 
 *  @param prCmd, Command and parameters to T8032
 *  @param prResponse, Respnose and parameters from T8032
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTPDWNC_T8032Cmd (MTPDWNC_T8032_CMD_T *prCmd, MTPDWNC_T8032_RESPONSE_T *prResponse);


//----------------------------------------------------------------------------
/** MTPDWNC_GetWakeupReason() Get system wakeup reason
 *  @param pu4Reason, Wakeup reason
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTPDWNC_GetWakeupReason (UINT32 *pu4Reason);

//----------------------------------------------------------------------------
/** MTIR_GetWakeupIrKey() Get system wakeup reason
 *  @param pu4HotKey, Wakeup IRRC Key value
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
typedef enum 
{
	MTIRRX_WAKEUPKEY_NONE 	= 0,
	MTIRRX_WAKEUPKEY_NORMAL = 1,
	MTIRRX_WAKEUPKEY_HOTKEY ,
}MTIRRC_WAKKEY_TYPE;

typedef struct _MTIRRC_WAKKEY_T
{
	UINT32 u4WakeupKey;
	MTIRRC_WAKKEY_TYPE fgIrkey;
}MTIRRC_WAKKEY_T;

EXTERN MT_RESULT_T  MTIR_GetWakeupIrKey(MTIRRC_WAKKEY_T *prWakeKey);
EXTERN MT_RESULT_T  MTIR_GetHotkeyNum(UINT8 *pu1HkNum);
EXTERN MT_RESULT_T  MTIR_GetAllHotKey(UINT32 *pau4HotKey,UINT8 u1HkNum);

//-----------------------------------------------------------------------------
/** Name: MTCheckCustomWakeupReason
 *  Description: This API implements to check the key on/off at initial time.
 */
// ----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCheckCustomWakeupReason(MT_WAKE_UP_REASON_T *_pWakeupReason);

//-----------------------------------------------------------------------------
/** MTPDWNC_SetPowerDownReason
 *  Set power down reason 
 *  @param _rSetPowerDownReason, 
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 *
 */
//-----------------------------------------------------------------------------
//
EXTERN MT_RESULT_T MTPDWNC_SetPowerDownReason(MTPDWNC_SET_POWER_DOWN_REASON_T _rSetPowerDownReason);

//----------------------------------------------------------------------------
/** MTPDWNC_EnterStandby()
 *  @param i4PinSel, Pin Name
 *  @param i4Func, Pin Function Number
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTPDWNC_SetWakeupSource (UINT32 u4WakeupSource);

//----------------------------------------------------------------------------
/** MTPDWNC_CreateWatchDogThread()
 *  Create watch dog thread in release version 
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
EXTERN MT_RESULT_T  MTPDWNC_CreateWatchDogThread (void);

//SIF
//-------------------------------------------------------------------------
/** MTSIF_Init
 *  Initialize SIF module.
 *  @param  VOID
 *  @return  VOID
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSIF_Init (VOID) ;

//-------------------------------------------------------------------------
/** MTSIF_Stop
 *  terminate SIF module.
 *  @param  VOID
 *  @return  VOID
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSIF_Stop (VOID) ;

//-------------------------------------------------------------------------
/** MTSIF_WriteMultipleSubAddr
 *  write data with word address to SIF module.
 *  @param  ePort  	SIF Port ID
 *  @param  u4ClkVal 	Demaned Sif Clock in Khz
 *  @param  u1DevAddr 	Serial interface device address.
 *  @param  pu1Addr 	Pointer to Serial interface word address
 *  @param  u2AddrCnt 	Serial interface word address count (up to 3).
 *  @param  pu1Data 		Pointer to data
 *  @param  u2DataCnt 	Number of byte to read. Max = 256 bytes.
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 *  MTSIF_WriteMultipleSubAddr() and MTSIF_ReadMultipleSubAddr() are in the same group.  
 *  In multiple sub address protocol, the device address is not only one byte.  
 *  So the pu1Addr is a pointer to the memory array of the address bytes and u2AddrCnt is the size of address array.
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSIF_WriteMultipleSubAddr (MTSIFPORT_TYPE_T ePort, UINT32 u4ClkVal, UINT8 u1DevAddr, UINT8 *pu1Addr, UINT16 u2AddrCnt, UINT8 *pu1Data, UINT16 u2DataCnt) ;

//-------------------------------------------------------------------------
/** MTSIF_ReadMultipleSubAddr
 *  read data with word address from SIF module.
 *  @param  ePort   	SIF Port ID
 *  @param  u4ClkVal 	Demaned Sif Clock in Khz
 *  @param  u1DevAddr 	Serial interface device address.
 *  @param  pu1Addr 	Pointer to Serial interface word address
 *  @param  u2AddrCnt 	Serial interface word address count (up to 3).
 *  @param  pu1Data 		Pointer to data
 *  @param  u2DataCnt 	Number of byte to read. Max = 256 bytes.
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 *  MTSIF_WriteMultipleSubAddr() and MTSIF_ReadMultipleSubAddr() are in the same group.  
 *  In multiple sub address protocol, the device address is not only one byte.  
 *  So the pu1Addr is a pointer to the memory array of the address bytes and u2AddrCnt is the size of address array.
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSIF_ReadMultipleSubAddr (MTSIFPORT_TYPE_T ePort, UINT32 u4ClkVal, UINT8 u1DevAddr, UINT8 *pu1Addr, UINT16 u2AddrCnt, UINT8 *pu1Data, UINT16 u2DataCnt) ;

//-------------------------------------------------------------------------
//SIFSW
//-------------------------------------------------------------------------
/** MTSIFSW_Init
 *  Initialize SIFSW module.
 *  @param  u4SDA/u4SCL: data_gpio_id/addr_gpio_id
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSIFSW_Init (UINT32 u4SDA, UINT32 u4SCL);

//-------------------------------------------------------------------------
/** MTSIFSW_WriteDataNoSubAddr
  * I2C write command (no ack type)
  *
  * @param bDevAddr device address
  * @param bDataCount numbber of bytes to be sent out
  * @param pbData pointer of data to be sent out
  * @param bOption options for this command
  * @param bOption bit 2-0: bit delay (us)
  * @param bOption bit 5-3: UINT8 delay (us)
  * @param bOption bit 6: need to check ACK
  * @param bOption bit 7: Reserve
  * @param bOption bit 8: halt and wait for ACK (full implementation of spec ch.7.2)
  * @param bOption bit 9: Not to send stop bit at the end of transaction
  * @param bOption bit10: Not to send start bit at the beginning of transaction
  *  @retval   MT_RESULT_T   MTR_OK for OK, MTR_PARAMETER_ERROR for wrong parameter, 
  *                MTR_NOT_OK for execution error
  */
 //-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSIFSW_WriteDataNoSubAddr (UINT8 bDevAddr, UINT8 bDataCount, UINT8 *pbData, UINT32 bOption, UINT16 u2Delay,UINT16 u2SyncTimeout);

//-------------------------------------------------------------------------
/** MTSIFSW_ReadDataNoSubAddr
  * I2C read command (no ack type)
  *
  * @param bDevAddr device address
  * @param bDataCount numbber of bytes to be rad
  * @param pbData pointer of data to be read
  * @param bOption options for this command
  * @param bOption bit 2-0: bit delay (us)
  * @param bOption bit 5-3: UINT8 delay (us)
  * @param bOption bit 6: need to check ACK
  * @param bOption bit 7: Reserve
  * @param bOption bit 8: halt and wait for ACK (full implementation of spec ch.7.2)
  * @param bOption bit 9: Reserve
  * @param bOption bit10: Not to send start bit at the beginning of transaction
 *  @retval   MT_RESULT_T   MTR_OK for OK, MTR_PARAMETER_ERROR for wrong parameter, 
 *                MTR_NOT_OK for execution error
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSIFSW_ReadDataNoSubAddr (UINT8 bDevAddr, UINT8 bDataCount, UINT8 *pbData, UINT32 bOption, UINT16 u2Delay,UINT16 u2SyncTimeout);

//-------------------------------------------------------------------------
/** MTSIFSW_WriteDataNoSubAddr
  * I2C write command (no ack type)
  *
  * @param bDevAddr device address
  * @param bDataCount numbber of bytes to be sent out
  * @param pbData pointer of data to be sent out
  * @param bOption options for this command
  * @param bOption bit 2-0: bit delay (us)
  * @param bOption bit 5-3: UINT8 delay (us)
  * @param bOption bit 6: need to check ACK
  * @param bOption bit 7: Reserve
  * @param bOption bit 8: halt and wait for ACK (full implementation of spec ch.7.2)
  * @param bOption bit 9: Not to send stop bit at the end of transaction
  * @param bOption bit10: Not to send start bit at the beginning of transaction
  *  @retval   MT_RESULT_T   MTR_OK for OK, MTR_PARAMETER_ERROR for wrong parameter, 
  *                MTR_NOT_OK for execution error
  */
 //-------------------------------------------------------------------------
EXTERN MT_RESULT_T MTSIFSW_X_Write(UINT16 u2ClkDiv, UINT8 u1DevAddr, UINT8 u1WordAddrNum, UINT8 *subAddr,UINT8 *pu1Buf, UINT16 u2ByteCnt);

//-------------------------------------------------------------------------
/** MTSIFSW_ReadDataNoSubAddr
  * I2C read command (no ack type)
  *
  * @param bDevAddr device address
  * @param bDataCount numbber of bytes to be rad
  * @param pbData pointer of data to be read
  * @param bOption options for this command
  * @param bOption bit 2-0: bit delay (us)
  * @param bOption bit 5-3: UINT8 delay (us)
  * @param bOption bit 6: need to check ACK
  * @param bOption bit 7: Reserve
  * @param bOption bit 8: halt and wait for ACK (full implementation of spec ch.7.2)
  * @param bOption bit 9: Reserve
  * @param bOption bit10: Not to send start bit at the beginning of transaction
 *  @retval   MT_RESULT_T   MTR_OK for OK, MTR_PARAMETER_ERROR for wrong parameter, 
 *                MTR_NOT_OK for execution error
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T MTSIFSW_X_Read(UINT16 u2ClkDiv, UINT8 u1DevAddr, UINT8 u1WordAddrNum, UINT8 *subAddr, UINT8 *pu1Buf, UINT16 u2ByteCnt);

//SIFSW
//-------------------------------------------------------------------------
/** MTSIFSW_Remove
 *  terminate SIF module.
 *  @param  VOID
 *  @return  VOID
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSIFSW_Remove (VOID);
//RTC
//----------------------------------------------------------------------------
/** MTRTC_RtcToUtc() Translate RTC to UTC
 *  @param prRtc, Input, The RTC to be translated
 *  @param pu8Utc, Output, The translated UTC
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTRTC_RtcToUtc (UINT64 *pu8Utc, const MTRTC_T *prRtc) ;

//----------------------------------------------------------------------------
/** MTRTC_UtcToRtc() Translate UTC to RTC
 *  @param u8Utc, Input, The UTC to be translated
 *  @param prRtc, Output, The translated RTC
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail.
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTRTC_UtcToRtc (MTRTC_T *prRtc, UINT64 u8Utc) ;

//----------------------------------------------------------------------------
/** MTRTC_Init() Initialize RTC driver and hardware
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail.
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTRTC_Init (VOID) ;

//----------------------------------------------------------------------------
/** MTRTC_GetTimeDate() Get time from RTC
 *  @param prTime, Output, The time
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail.
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTRTC_GetTimeDate (UINT64 *prTime) ;

//----------------------------------------------------------------------------
/** MTRTC_SetTimeDate() Set time to RTC
 *  @param prTime, Input, The time to set.
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail.
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTRTC_SetTimeDate (const UINT64 *prTime) ;

//----------------------------------------------------------------------------
/** MTRTC_SetAlertTime() Set time to RTC
 *  @param prTime, Input, The time to set.
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail.
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTRTC_SetAlertTime (UINT64* pu8Utc) ;

//----------------------------------------------------------------------------
/** MTRTC_GetAlertTime() Set time to RTC
 *  @param prTime, Input, The time to set.
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail.
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTRTC_GetAlertTime (UINT64 *prTime) ;

//----------------------------------------------------------------------------
/** MTRTC_HookAlertHandler()
 *  @param pfnHandler the callback function.
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTRTC_HookAlertHandler (MTPFN_RTC_ALERT_HANDLER_T pfnHandler) ;

//----------------------------------------------------------------------------
/** MTRTC_SetWakeup()
 *  @param pfnHandler the callback function.
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTRTC_SetWakeup (MTPFN_RTC_WEAKEUP_HANDLER_T pfnHandler) ;

//----------------------------------------------------------------------------
/** MTRTC_SetWakeupEnable() set RTC wake up cap
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail.
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTRTC_SetRtcWakeupEnable (BOOL fgEnable) ;

//NOR
//-----------------------------------------------------------------------------
/** erase data to 0xff on nor flash.
 *  @param u4SectIdx  Sector Index
 *  @param u4SectNum  Sector Numer
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 *  erase start point is sector index and erase size is based on sector size.
 *  MTNOR_Erase() and MTNOR_EraseAddr() are in the same group. 
 *  What's the different is MTNOR_Erase will erase by sector index and number.
 *  Two kinds of erase method for user.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNOR_Erase(UINT32 u4SectIdx, UINT32 u4SectNum);

//-----------------------------------------------------------------------------
/** erase data to 0xff on nor flash.
 *  @param u4Offset  Offset that start to write
 *  @param u4ByteCount  Size in byte of writting
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 *  erase start point is sector index and erase size is based on sector size.
 *  MTNOR_Erase() and MTNOR_EraseAddr() are in the same group. 
 *  What's the different is MTNOR_Erase will erase by sector index and number.
 *  Two kinds of erase method for user.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNOR_EraseAddr(UINT32 u4Offset, UINT32 u4ByteCount);

//-----------------------------------------------------------------------------
/** get the size of norflash by bytes.
 *  @return Nor flash size in byte
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNOR_GetSize(UINT32 *pu4Val);

//-----------------------------------------------------------------------------
/** read data from nor flash.
 *  @param u4Offset  Position that start to read from
 *  @param pu1Buf    Pointer to storing read-back data
 *  @param u4Len     Length (i.e. size) to read in byte
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNOR_Read(UINT32 u4Offset, UINT8* pu1Buf, UINT32 u4Len);

//-----------------------------------------------------------------------------
/** write data to nor flash.
 *  @param u4Offset  Position that start to write to
 *  @param pu1Buf    Pointer to storing write-to data
 *  @param u4Len     Length (i.e. size) to read in byte
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNOR_Write(UINT32 u4Offset, UINT8* pu1Buf, UINT32 u4Len);

//-----------------------------------------------------------------------------
/** write data on nor flash and erase automaticallly if need.
 *  @param u4Offset  Position that start to write to
 *  @param pu1MemPtr    Pointer to storing write-to data
 *  @param u4Len     Length (i.e. size) to read in byte
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNOR_WrOnE(UINT32 u4Offset, UINT8* pu1MemPtr, UINT32 u4Len);

//-----------------------------------------------------------------------------
/** calculate CRC from input source
 *  @param u4Addr, Start Address
 *  @param u4Size, Size beginning from u4Addr
 *  @param pu4Checksum, Memory buffer storing check sum value
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNOR_CalCRC(UINT32 u4Addr, UINT32 u4Size, UINT32* pu4Checksum);

// NAND
//-----------------------------------------------------------------------------
/** Initialize the nand device and nand driver.
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNAND_Init(VOID);

//-----------------------------------------------------------------------------
/** Reset the nand device.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNAND_Reset(VOID);

//-----------------------------------------------------------------------------
/** Read nand chip ID.
 *  @param pu4ID, chip ID
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNAND_ReadID(UINT32* pu4ID);

//-----------------------------------------------------------------------------
/** Get NAND size.
 *  @return NAND size in page.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNAND_GetSize(UINT32* pu4Val);

//-----------------------------------------------------------------------------
/** NAND Read in block
 *  @param u4Offset, block offset to be read
 *  @param pu4Buf, data destination point
 *  @param u4Len, data destination buffer size
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 *
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNAND_ReadBlocks(UINT32 u4Offset, UINT32* pu4Buf, UINT32 u4Len);

//-----------------------------------------------------------------------------
/** NAND Write in block
 *  @param u4Offset, block offset to be read
 *  @param pu4Buf, data destination point
 *  @param u4Len, data destination buffer size
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 *
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTNAND_WriteBlocks(UINT32 u4Offset, UINT32* pu4Buf, UINT32 u4Len);

#if defined(CC_MSDC_ENABLE)
//-----------------------------------------------------------------------------
/** MTMSDC_Read 
 *  @param u4Offset, block offset to be read
 *  @param pu4Buf, data destination point
 *  @param u4Len, data destination buffer size
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 *
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTMSDC_Read(UINT32 partId,UINT32 u4Offset, UINT32* pu4Buf, UINT32 u4Len);

//-----------------------------------------------------------------------------
/** MTMSDC_Write 
 *  @param u4Offset, block offset to be read
 *  @param pu4Buf, data destination point
 *  @param u4Len, data destination buffer size
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 *
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTMSDC_Write(UINT32 partId,UINT32 u4Offset, UINT32* pu4Buf, UINT32 u4Len);

#ifdef CC_PARTITION_WP_SUPPORT
//-----------------------------------------------------------------------------
/** MTMSDC_WPconfig 
 *  @param wp,partition write protect  0:disable 1:enable
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTMSDC_WPconfig(UINT32 wp);
#endif
//-----------------------------------------------------------------------------
/** MTMSDC_MMC_Open 
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 *
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTMSDC_MMC_Open(void);


//-----------------------------------------------------------------------------
/** MTMSDC_MMC_Close 
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 *
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTMSDC_MMC_Close(void);


//-----------------------------------------------------------------------------
/** MTMSDC_MMC_Get_SMART_Report 
 *  @param buff, data destination point
 *  @param len, data destination buffer size
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 *
 */
//-----------------------------------------------------------------------------

EXTERN MT_RESULT_T MTMSDC_MMC_Get_SMART_Report(unsigned char *buff, unsigned int *len);
#endif
//----------------------------------------------------------------------------
/** MTRTC_RtcToUtc() Translate RTC to UTC
 *  @param prRtc, Input, The RTC to be translated
 *  @param pu8Utc, Output, The translated UTC
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTIR_Init (const MTIR_TYPE_T eType);

//----------------------------------------------------------------------------
/** MTRTC_RtcToUtc() Translate RTC to UTC
 *  @param prRtc, Input, The RTC to be translated
 *  @param pu8Utc, Output, The translated UTC
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTIR_Poll (UINT32 *pu4Key, MTIR_IRRX_RAW_DATA_T *prRaw);
typedef enum 
{
	MTPDWNC_RESUME_VIA_IR = 0,
	MTPDWNC_RESUME_VIA_DEFAULT_IR,
	MTPDWNC_RESUME_VIA_OTHER
} MTPDWNC_RESUME_TYPE;
EXTERN MT_RESULT_T  MTPDWNC_TRIGGER_RESUME(MTPDWNC_RESUME_TYPE type, UINT32 u4Key);

//----------------------------------------------------------------------------
/** IR convert raw bits to event code function
 *  @param u4RawBits, Input, Ir raw bits
 *  @param pu4EvtCode, Output, event code
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTIR_RawBitToEvtCode (UINT32 u4RawBits, UINT32 *pu4EvtCode);

//----------------------------------------------------------------------------
/** MTPINMUX_Set() Pinmux setting function
 *  @param i4PinSel, Pin Name
 *  @param i4Func, Pin Function Number
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTPINMUX_Set (INT32 i4PinSel, INT32 i4Func) ;

//-----------------------------------------------------------------------------
/** MTSCRBT_Check() Check if it is secure boot IC or not
 *  @param pu4ScrBt, Output, 1: Secure boot IC; 0: Non-Secure boot IC
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTSCRBT_Check(UINT32 *pu4ScrBt);


//-----------------------------------------------------------------------------
/** MTDRAM_GetBandwidthUsage() provide the total dram bandwidth usage
 *  @param u4MonitorSecond the monitor perioid in second.
 *  @param pu4Usage the total consumption in permillage
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTDRAM_GetBandwidthUsage (UINT32 u4MonitorSecond, UINT32 *pu4Usage) ;

//-----------------------------------------------------------------------------
/** enable Set Dram Bandwidth
 *  @param  fgEnable                enable=TRUE/disable=FALSE
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSYS_SetDramBWEnable (BOOL fgEnable);

//-----------------------------------------------------------------------------
/** MTDRAM_GetBandwidthUsage() provide the total dram bandwidth usage
 *  @param u4MonitorSecond the monitor perioid in second.
 *  @param pu4Usage the total consumption in permillage
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSYS_GetDramBWInfo (UINT32 *pu4ChA_total, UINT32 *pu4ChA_percent,UINT32 *pu4ChB_total,UINT32 *pu4ChB_percent);

//-----------------------------------------------------------------------------
/** MTSMC_Init() Init smart card driver.
 *  @param  VOID
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSMC_Init(void);

//-----------------------------------------------------------------------------
/** MTSMC_GetCardPresence() send APDU to smart card and receive response APDU from card
 *  @param pfgCardPresence Smart card presence status
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSMC_GetCardPresence(UINT8 u1SlotNo, BOOL *pfgCardPresence);

//-----------------------------------------------------------------------------
/** MTSMC_Reset() reset smart card.
 *  @param void
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSMC_Reset(UINT8 u1SlotNo);

//-----------------------------------------------------------------------------
/** MTSMC_SendReceiveAPDU() send APDU to smart card and receive response APDU from card
 *  @param pu1SendAPDU the buffer pointer holds APDU data to be sent
 *  @param u1SendAPDULen the lenght of the APDU to be sent
 *  @param pu1ReceiveAPDU the buffer pointer used to holds reponse APDU data
 *  @param pu4ReceiveAPDULen the lenght of the response APDU received actually
 *  @param u4MaxReceiveAPDULen the maximum lenght of the response APDU to be received. Do not receive more than this threshold
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSMC_SendReceiveAPDU(UINT8 u1SlotNo,
                                          UINT8 *pu1SendAPDU, 
                                          UINT32 u4SendAPDULen, 
                                          UINT8 *pu1ReceiveAPDU, 
                                          UINT8 *pu4ReceiveAPDULen, 
                                          UINT8 u4MaxReceiveAPDULen);

//-----------------------------------------------------------------------------
/** MTSMC_RequestIFS() Request IFS
 *  @param u1IFSLen the requested IFS maximum length
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSMC_RequestIFS(UINT8 u1SlotNo, UINT8 u1IFSLen);

//-----------------------------------------------------------------------------
/** MTSMC_Activate() Activate the smart card including ATR sequence processing
 *  @param void
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSMC_Activate(UINT8 u1SlotNo);

//-----------------------------------------------------------------------------
/** MTSMC_Deactivate() Deactivate the smart card
 *  @param void
 *  @return MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSMC_Deactivate(UINT8 u1SlotNo);

//----------------------------------------------------------------------------
/** MTSMC_RegCb()
 *  @param pfnHandler the callback function.
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTSMC_RegCb (UINT8 u1SlotNo, MTSMC_PFN_CB_T pfnCallback);

//-------------------------------------------------------------------------
/** MTEEPROM_Init
 *  Initialize EEPROM module.
 *  @param  VOID
 *  @return  VOID
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTEEPROM_Init (VOID);

//-------------------------------------------------------------------------
/** MTEEPROM_Read
 *  read data from EEPROM
 *  @param  u4Offset 	EEPROM data read start offset
 *  @param  pu1Data	Pointer to the data buffer prepared by user
 *  @param  u4DataCnt 	Number of byte to read. Max = 256 bytes.
 *  @retval   MT_RESULT_T   MTR_OK for OK, MTR_PARAMETER_ERROR for wrong parameter, 
 *                MTR_NOT_OK for execution error
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTEEPROM_Read (UINT32 u4Offset, UINT8* pu1Data, UINT32 u4DataCnt);

//-------------------------------------------------------------------------
/** MTEEPROM_Write
 *  write data to EEPROM
 *  @param  u4Offset 	EEPROM data write start offset
 *  @param  pu1Data	Pointer to the data buffer prepared by user
 *  @param  u4DataCnt 	Number of byte to read. Max = 256 bytes.
 *  @retval   MT_RESULT_T   MTR_OK for OK, MTR_PARAMETER_ERROR for wrong parameter, 
 *                MTR_NOT_OK for execution error
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTEEPROM_Write (UINT32 u4Offset, UINT8* pu1Data, UINT32 u4DataCnt);

//-------------------------------------------------------------------------
/** MTEEPROM_GetHdcp2xOffset
 *  got the offset address of HDCP in eeprom
 *  @param  pu4HDCPoffset	Pointer to the data buffer prepared by user
 *  @retval   MT_RESULT_T   MTR_OK for OK, MTR_PARAMETER_ERROR for wrong parameter, 
 *                MTR_NOT_OK for execution error
 */
//-------------------------------------------------------------------------
MT_RESULT_T  MTEEPROM_GetHdcp2xOffset (UINT32* pu4HDCPOffset);


//-------------------------------------------------------------------------
/** MTPDWNC_SetWatchDogTimeout()
 *  @param u4Timeout, the millisecond of watchdog timeout value, 0 to disable watchdog
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTPDWNC_SetWatchDogTimeout(UINT32 u4Timeout);

//-------------------------------------------------------------------------
/** MTWD_GetWatchDogTimeout()
 *  @param pu4Timeout, the millisecond of watchdog timeout value, 0 means the watchdog is disabled
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTPDWNC_GetWatchDogTimeout(UINT32 *pu4Timeout);



//-------------------------------------------------------------------------
/** MTEEPROM_GetProperty
 *  write data to EEPROM
 *  @param  prEepromProperty	EEPROM property
 *  @retval   MT_RESULT_T   MTR_OK for OK, MTR_PARAMETER_ERROR for wrong parameter, 
 *                MTR_NOT_OK for execution error
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTEEPROM_GetProperty (MTEEPROM_PROPERTY_T *prEepromProperty);

//-------------------------------------------------------------------------
/** MTEEPDTV_GetCfg
 *  @param  rDtvCfg 	store EEPDTV cfg data 
 *  @retval   MT_RESULT_T   MTR_OK for OK, MTR_PARAMETER_ERROR for wrong parameter, 
 *                MTR_NOT_OK for execution error
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTEEPDTV_GetCfg (EEPDTVCFG_T *rDtvCfg);

//-------------------------------------------------------------------------
/** MTEEPDTV_SetCfg
 *  @param  rDtvCfg 	store EEPDTV cfg data 
 *  @retval   MT_RESULT_T   MTR_OK for OK, MTR_PARAMETER_ERROR for wrong parameter, 
 *                MTR_NOT_OK for execution error
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTEEPDTV_SetCfg (EEPDTVCFG_T *rDtvCfg);

//-------------------------------------------------------------------------
/** MTEEPHDCPInit() load EEPROM HDCP content to internal HDCP SRAM
 *  @retval MT_RESULT_T MTR_OK for ok, otherwise is failed.
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTEEP_HDCPInit (void);

//-------------------------------------------------------------------------
/** MTEEPNPTV_Read() to read EEP NPTV partition data.
 *  @param  u2Addr the offset for EEP NPTV partition to read
 *  @param  pu1Data memory pointer to put the EEP data
 *  @retval MT_RESULT_T MTR_OK for ok, otherwise is failed.
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTEEPNPTV_Read (UINT16 u2Addr, UINT8 *pu1Data);

//-----------------------------------------------------------------------------
//SSUSB port status
//-------------------------------------------------------------------------
/** MTSSUSB_Status
 *  Get SSUSB port connection status.
 *  @param pu1SSUSB_Type the port status to get
 *  @      0 no device attached
 *  @      1 Full-speed device attached
 *  @      2 Low-speed device attached
 *  @      3 High-speed device attached
 *  @      5 SuperSpeed device attached(USB3.0 speed)
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//-------------------------------------------------------------------------
EXTERN MT_RESULT_T   MTSSUSB_Status (UINT32 *pu4SSUSB_Type);

//-----------------------------------------------------------------------------
/** MTBIM_GetDeviceID()  
 *  @param pu1DeviceID the ID to get.
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTBIM_GetDeviceID (BYTE *pu1DeviceID);

//-----------------------------------------------------------------------------
/** MTPDWNC_GetPowerState()  
 *   Driver customization power state function.
 *  @param *pu4PowerState the power state to get.
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail. There is no setting.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTPDWNC_GetPowerState (UINT32 *pu4PowerState);

EXTERN MT_RESULT_T MT_SETGAMMA(UINT8 bPath, UINT8 bCmd, UINT8 *pGammaData);
/** MTAGENT_SetBandwidthParam()
 *  @param u4Module, module number to control
 *  @param u4Type, register to control
 *  @param u4Value, value to set 
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTAGENT_SetBandwidthParam( UINT32 u4Module, UINT32 u4Type, UINT32 u4Value );

//----------------------------------------------------------------------------
/** MTRTC_SetQuietBootWhenRtcWakeup() set RTC enable quiet boot
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail.
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTRTC_SetQuietBootWhenRtcWakeup (BOOL fgEnable) ;

/*
	read hdcp2.x  key from PERIPHERAL (emmc, eeprom, nandflash,  etc, )
*/
EXTERN MT_RESULT_T  MTPERIPHERAL_Read_HDCP2X_Key (UINT32 u4Offset, UINT8* pu1Data, UINT32 u4DataCnt);

//-------------------------------------------------------------------------
/** MTPDWNC_GspiInit()
 *  @param prGspiMode->u4Mode  GSPI config.
 *  @param prGspiMode->u4Freq  SPI clock, (uint:1hz,Min = 2929.6875Hz, Max = 12000000Hz).
 *  @retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTPDWNC_GspiInit(MTPDWNC_GSPI_MODE_T *prGspiMode);
//-------------------------------------------------------------------------
/** MTPDWNC_GspiReadWrite()
 *	@param fgReadWrite,  GSPI read/write flag.
 *	@param u4Size, MDATA_LEN * NDATA_LEN is 32bytes,read/write buffer size (bits,1~256).
 *	@param u1RdBuf, read buffer.
 *	@param u1WrBuf, write buffer.
 *	@retval MTR_OK, Succeed; MTR_NOT_OK, Fail
 */
//----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTPDWNC_GspiReadWrite(UINT32 fgReadWrite, UINT32 u4Nob,UINT8 *u1RdBuf, UINT8 *u1WrBuf);

typedef enum 
{
    DRIR_NTF_GETIR,
    DRIR_NFY_MAX
} MTIR_CB_ENUM;

typedef struct
{
    UINT32 u4Arg1;
    UINT32 u4Arg2;
    UINT32 u4Arg3; 
}MTDRVCUST_CB_T;
/* Notify conditions */

typedef enum
{
    MT_MISC_COND_DATA_CHG = 0,
    MT_MISC_COND_MAX
}   MTIR_COND_T;

typedef void (*MTIR_NOTIFY)(
    MTIR_COND_T e_nfy_cond, 
    UINT32 ui4_data_1,
    UINT32 ui4_data_2
    );

EXTERN MT_RESULT_T MTIR_Reg_CB(MTIR_CB_ENUM eFuncType, MTIR_NOTIFY pfCb);
MT_RESULT_T MT_DOLBY_SUPPORT(UINT8 *pu1Data);

#ifdef __cplusplus
}
#endif

#endif //_PERIPHERAL_H_
