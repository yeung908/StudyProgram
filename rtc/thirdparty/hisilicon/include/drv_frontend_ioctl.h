/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_frontend.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/12/16
  Description   : 
  History       :
  1.Date        : 2013/12/16
    Author      : w00184692
    Modification: Created file
******************************************************************************/
#ifndef __DRV_FRONTEND_IOCTL_H__
#define __DRV_FRONTEND_IOCTL_H__

#include "hi_type.h"
#include "hi_drv_i2c.h"
#include "hi_debug.h"
#include "hi_drv_struct.h"
#include "drv_i2c_ext.h"
#include "drv_gpio_ext.h"
#include "hi_drv_frontend.h"
#include "hi_unf_frontend.h"

#ifdef __cplusplus
 #if __cplusplus
        extern "C" {
 #endif
#endif /* __cplusplus */

#define QAM_PORT0_ADDR 0xA0
#define QAM_PORT1_ADDR 0xA2
#define QAM_PORT2_ADDR 0xA0
#define QAM_PORT3_ADDR 0xA2
#define QAM_PORT4_ADDR 0xA0
#define TUNER_PORT0_ADDR 0xC0
#define TUNER_PORT1_ADDR 0xC0
#define TUNER_PORT2_ADDR 0xC0
#define TUNER_PORT3_ADDR 0xC0
#define TUNER_PORT4_ADDR 0xC0
#define XTAL_CLK 28800

#define TUNER_NUM 5
#define HI_TUNER_HI3130IQAM_TYPE_MAX  5
typedef enum hiTUNER_DATA_SRC_E
{
    TUNER_DATA_SRC_ADC = 0,
    TUNER_DATA_SRC_EQU,
    TUNER_DATA_SRC_BUTT
} TUNER_DATA_SRC_E;

typedef enum hiTUNER_QAM_TYPE_E
{
    QAM_TYPE_16 = 0,
    QAM_TYPE_32,
    QAM_TYPE_64,
    QAM_TYPE_128,
    QAM_TYPE_256,

    QAM_TYPE_BUTT
} TUNER_QAM_TYPE_E;

typedef struct hiTUNER_ACC_QAM_PARAMS_S
{
    HI_U32 u32Frequency;            /* frequency kHz*/
    union
    {
        HI_U32 u32SymbolRate;           /* symbolrate Hz */
        HI_U32 u32BandWidth;            /* BandWidth KHz */
        HI_UNF_ATV_SIF_BW_E enAtvSifBw; /* Atv sif bandwidth */
    } unSRBW;
    union
    {
        TUNER_QAM_TYPE_E                enQamType;
        HI_UNF_TUNER_FE_POLARIZATION_E  enPolar;
        HI_UNF_ATV_SYSTEM_E             enSystem;
    } unMODPOL;
    HI_BOOL bSI;              /*reverse*/
	HI_UNF_ATV_CONNECT_WORK_MODE_E enConnectWorkMode; /* atv work mode*/
} TUNER_ACC_QAM_PARAMS_S;

typedef struct  hiTUNER_DATA_S
{
    HI_U32        u32Port;
    HI_U32        u32Data;
} TUNER_DATA_S, *PTR_TUNER_DATA_S;

typedef struct  hiTUNER_DATABUF_S
{
    HI_U32         u32Port;
    HI_U32         u32DataBuf[3];
}TUNER_DATABUF_S, *PTR_TUNER_DATABUF_S;

typedef struct  hiTUNER_SIGNALINFO_S
{
    HI_U32         u32Port;
    HI_UNF_TUNER_SIGNALINFO_S stInfo;
}TUNER_SIGNALINFO_S, *PTR_TUNER_SIGNALINFO_S;

typedef struct  hiTUNER_LNBCONFIG_S
{
    HI_U32         u32Port;
    HI_UNF_TUNER_FE_LNB_CONFIG_S stLNB;
}TUNER_LNBCONFIG_S, *PTR_TUNER_LNBCONFIG_S;

#define MAX_TP_NUM (128)

typedef struct  hiTUNER_BLINDSCAN_INITPARA_S
{
    HI_U32 u32Data;                 /*For extend*/
}TUNER_BLINDSCAN_INITPARA_S, *PTR_TUNER_BLINDSCAN_INITPARA_S;

typedef struct  hiTUNER_BLINDSCAN_S
{
    HI_U32         u32Port;
    TUNER_BLINDSCAN_INITPARA_S stPara;
}TUNER_BLINDSCAN_S, *PTR_TUNER_BLINDSCAN_S;

typedef struct  hiTUNER_BLINDSCAN_PARA_S
{
    HI_U32 u32CentreFreq;           /*Blind scan centre frequency, kHz*/
    HI_U16 u16Count;                /*Channel find in this scanning */
    union
    {
        HI_UNF_TUNER_SAT_TPINFO_S astSat[MAX_TP_NUM];
    }unResult;
}TUNER_BLINDSCAN_PARA_S, *PTR_TUNER_BLINDSCAN_PARA_S;

typedef struct  hiTUNER_BLINDSCAN_INFO_S
{
    HI_U32         u32Port;
    TUNER_BLINDSCAN_PARA_S  stPara;
}TUNER_BLINDSCAN_INFO_S, *PTR_TUNER_BLINDSCAN_INFO_S;

typedef enum  hiTUNER_SETFUNC_MODE_E
{
    FunctMode_Demod = 0,
    FunctMode_BlindScan = 1
}TUNER_FUNC_MODE_E;

/* LNB out voltage enum */
typedef enum hiTUNER_LNB_OUT_E
{
    TUNER_LNB_OUT_0V = 0,
    TUNER_LNB_OUT_13V = 13,
    TUNER_LNB_OUT_14V = 14, /* 14 or 15V */
    TUNER_LNB_OUT_18V = 18,
    TUNER_LNB_OUT_19V = 19, /* 19 or 20V */
    TUNER_LNB_OUT_BUTT
}TUNER_LNB_OUT_E;

/* LNB out voltage struct */
typedef struct  hiTUNER_LNB_OUT_S
{
    HI_U32          u32Port;
    TUNER_LNB_OUT_E enOut;
}TUNER_LNB_OUT_S, *PTR_TUNER_LNB_OUT_S;

/* DiSEqC send message */
typedef struct  hiTUNER_DISEQC_SENDMSG_S
{
    HI_U32         u32Port;
    HI_UNF_TUNER_DISEQC_SENDMSG_S stSendMsg;
}TUNER_DISEQC_SENDMSG_S, *PTR_TUNER_DISEQC_SENDMSG_S;

typedef struct  hiTUNER_DISEQC_RECVMSG_S
{
    HI_U32         u32Port;
    HI_UNF_TUNER_DISEQC_RECVMSG_S  stRecvMsg;  /* Read data */
}TUNER_DISEQC_RECVMSG_S, *PTR_TUNER_DISEQC_RECVMSG_S;

typedef struct  hiTUNER_SIGNAL_S
{
    HI_UNF_TUNER_SIG_TYPE_E enSigType;
    HI_U32 u32Port;
    TUNER_ACC_QAM_PARAMS_S  stSignal;
}TUNER_SIGNAL_S, *PTR_TUNER_SIGNAL_S;

typedef struct hiTUNER_TP_VERIFY_PARAMS_S
{
    HI_U32 u32Frequency;            /**<frequency kHz*/                            /**<CNcomment:频率，单位kHz*/
    HI_U32 u32SymbolRate;           /**<symbolrate kBaud*/                         /**<CNcomment:符号率，单位kBaud*/
    HI_UNF_TUNER_FE_POLARIZATION_E enPolar; /**<TP polarization*/                    /**<CNcomment:TP的极化方式*/
    HI_U8 cbs_reliablity;                           /**<TP reliability*/             /**<CNcomment:TP的可靠度*/
    HI_S32 CBS_TH;                                   /**<blindscan threshold*/        /**<CNcomment:盲扫阈值*/
    HI_U8 fs_grade;
    HI_U32 fec_ok_cnt;                             /**<TP number of fec ok*/        /**<CNcomment:fec ok的TP数量*/
    HI_U32 fec_no_ok_cnt;                          /**<TP number of fec  not ok*/   /**<CNcomment:fec not ok的TP数量*/
}TUNER_TP_VERIFY_PARAMS_S;

typedef struct  hiTUNER_TP_VERIFY_INFO_S
{
    HI_U32 u32Port;
    TUNER_TP_VERIFY_PARAMS_S  stTPVerifyPrm;
}TUNER_TP_VERIFY_INFO_S, *PTR_TUNER_TP_VERIFY_INFO_S;

typedef struct hiTUNER_SAMPLE_DATA_PARAM_S
{
    TUNER_DATA_SRC_E enDataSrc;
    HI_U32 u32DataLen;
    HI_UNF_TUNER_SAMPLE_DATA_S stData;
}TUNER_SAMPLE_DATA_PARAM_S;

typedef struct hiTUNER_I2C_DATA_S
{       
    HI_U8* pu8SendBuf;
    HI_U32 u32SendLength;
    HI_U8* pu8ReceiveBuf;
    HI_U32 u32ReceiveLength;
} TUNER_I2C_DATA_S, *PTR_TUNER_I2C_DATA_S; 

typedef struct hiAGC_TEST_S 
{
    HI_U32      u32Port;
    HI_U32		u32Agc1;
    HI_U32		u32Agc2;
    HI_BOOL     bLockFlag; 
    HI_BOOL		bAgcLockFlag;
	HI_U32		u32Count;
    HI_U8 		u8BagcCtrl12;
}AGC_TEST_S;

typedef struct hiTUNER_STATUS_S
{
    HI_U32                      u32Port;
    HI_UNF_TUNER_LOCK_STATUS_E  enLockStatus;
} TUNER_STATUS_S;

typedef struct hiTUNER_BER_S
{
    HI_U32  u32Port;
    HI_U32  u32Ber[3];
} TUNER_BER_S;

typedef struct hiTUNER_RS_S
{
    HI_U32  u32Port;
    HI_U32  u32Rs[3];
} TUNER_RS_S;

typedef struct hiTUNER_SNR_S
{
    HI_U32  u32Port;
    HI_U32  u32SNR;
} TUNER_SNR_S;

typedef struct hiTUNER_FREQ_SYMB_OFFSET_S
{
	HI_U32  u32Port;
	HI_U32  u32Freq;
	HI_U32  u32Symb;
	HI_U32  u32Direction;
} TUNER_FREQ_SYMB_OFFSET_S;

typedef struct hiTUNER_CONNECT_TIMEOUT_S
{
    HI_U32  u32Port;
    HI_U32  u32TimeOut;
} TUNER_CONNECT_TIMEOUT_S;

typedef struct hiTUNER_CONTINUOUS_22K_S
{
    HI_U32  u32Port;
    HI_U32  u32Continuous22K;
} TUNER_CONTINUOUS_22K_S;

typedef struct hiTUNER_TONE_S
{
    HI_U32  u32Port;
    HI_U32  u32TONE;
} TUNER_TONE_S;

typedef struct hiTUNER_STANDBY_S
{
    HI_U32  u32Port;
    HI_U32  u32Standby;
} TUNER_STANDBY_S;

typedef struct hiTUNER_SETFUNCMODE_S
{
    HI_U32              u32Port;
    TUNER_FUNC_MODE_E   enFuncMode;
} TUNER_SETFUNCMODE_S;

typedef struct hiTUNER_PLPNO_S
{
    HI_U32  u32Port;
    HI_U32  u32PLPID;
} TUNER_PLPNO_S;

typedef struct hiTUNER_PLPNUM_S
{
    HI_U32  u32Port;
    HI_U32  u32PLPNum;
} TUNER_PLPNUM_S;

typedef struct hiTUNER_PLPTYPE_S
{
    HI_U32                      u32Port;
    HI_UNF_TUNER_T2_PLP_TYPE_E  enT2PLPType;
} TUNER_PLPTYPE_S;

typedef struct hiTUNER_TS_OUT_S
{
    HI_U32                      u32Port;
    HI_UNF_TUNER_TSOUT_SET_S    stTSOut;
} TUNER_TS_OUT_S;

typedef struct hiTUNER_SAT_ATTR_S
{
    HI_U32                  u32Port;
    HI_UNF_TUNER_SAT_ATTR_S stSatAttr;
} TUNER_SAT_ATTR_S;

typedef struct hiTUNER_SAMPLE_DATA_S
{
    HI_U32                      u32Port;
    TUNER_SAMPLE_DATA_PARAM_S   stSampleData;
} TUNER_SAMPLE_DATA_S;

typedef struct hiTUNER_BAND_DATA_S
{
    HI_U32                  u32Port;
    HI_U32                  u32Freq;
    HI_UNF_TUNER_ATVBAND_E  enBand;
} TUNER_BAND_DATA_S;

typedef struct hiTUNER_BAND_RANGE_S
{
    HI_U32                          u32Port;
    HI_UNF_TUNER_ATVBAND_E          enBand;
    HI_UNF_TUNER_ATV_BANDRANGE_S    stBandRange;
} TUNER_BAND_RANGE_S;

typedef struct hiTUNER_BAND_S
{
    HI_U32                  u32Port;
    HI_U32                  u32Freq;
    HI_UNF_TUNER_ATVBAND_E  enBand;
} TUNER_BAND_S;

typedef struct hiTUNER_FINE_TUNE_S
{
    HI_U32  u32Port;
    HI_S8   s8Step;
} TUNER_FINE_TUNE_S;

typedef struct hiTUNER_STEP_S
{
    HI_U32              u32Port;
    HI_UNF_TUNER_STEP_E enStep;
} TUNER_STEP_S;

typedef struct hiTUNER_TOP_ADJUST_S
{
    HI_U32         u32Port;
    HI_U32         u32Top;
} TUNER_TOP_ADJUST_S, *PTR_TUNER_TOP_ADJUST_S;

typedef struct hiTUNER_ATTR_S
{
    HI_U32              u32Port;
    HI_UNF_TUNER_ATTR_S stAttr;
} TUNER_ATTR_S;

typedef struct hiTUNER_TIMEOUT_S
{
    HI_U32 u32Port;
    HI_U32 u32TimeOut;
} TUNER_TIMEOUT_S;

typedef struct hiTUNER_BITRATE_S
{
    HI_U32 u32Port;
    HI_U32 u32BitRate;
} TUNER_BITRATE_S;

typedef struct hiTUNER_SETSIGTYPE_S
{
    HI_U32 u32Port;
    HI_U32 u32SigType;
} TUNER_SETSIGTYPE_S;


extern HI_U32 s_u32ResetGpioNo[TUNER_NUM];
extern HI_U32 g_u32ResetCruGpioNo;

/*---- TUNER COMMAND----*/
#define HI_TUNER_IOC_MAGIC 't'
#define TUNER_CONNECT_CMD               _IOW(HI_TUNER_IOC_MAGIC,  1, TUNER_SIGNAL_S)
#define TUNER_GET_STATUS_CMD            _IOWR(HI_TUNER_IOC_MAGIC, 2, TUNER_STATUS_S)
#define TUNER_GET_SIGNALSTRENGTH_CMD    _IOWR(HI_TUNER_IOC_MAGIC, 3, TUNER_DATABUF_S)
#define TUNER_GET_BER_CMD               _IOWR(HI_TUNER_IOC_MAGIC, 4, TUNER_BER_S)
#define TUNER_GET_SNR_CMD               _IOWR(HI_TUNER_IOC_MAGIC, 5, TUNER_SNR_S)
#define TUNER_SET_ATTR_CMD              _IOW(HI_TUNER_IOC_MAGIC,  6, TUNER_ATTR_S)
#define TUNER_DISCONNECT_CMD            _IOW(HI_TUNER_IOC_MAGIC,  7, HI_U32)
#define TUNER_GET_ATTR_CMD              _IOWR(HI_TUNER_IOC_MAGIC,  8, TUNER_ATTR_S)

//#define TUNER_SET_TSTYPE_CMD            _IOW(HI_TUNER_IOC_MAGIC, 6, TUNER_DATA_S)
//#define TUNER_SELECT_TYPE_CMD           _IOW(HI_TUNER_IOC_MAGIC, 7, TUNER_DATABUF_S)
//#define TUNER_SELECT_I2C_CMD            _IOW(HI_TUNER_IOC_MAGIC, 8, TUNER_I2C_S)
//#define TUNER_SELECT_RW_CMD             _IOWR(HI_TUNER_IOC_MAGIC, 9, TUNER_RegRW_S)
//#define TUNER_SET_TUNER_CMD             _IOWR(HI_TUNER_IOC_MAGIC, 10, TUNER_SET_TUNER_S)
//#define TUNER_LOW_CONS_CMD              _IO(HI_TUNER_IOC_MAGIC, 11)
//#define TUNER_NORMAL_MODE_CMD           _IO(HI_TUNER_IOC_MAGIC, 12)
//#define TUNER_SET_QAMINSIDE_CMD         _IOR(HI_TUNER_IOC_MAGIC, 13, TUNER_QAMINSIDE_E)
//#define TUNER_CONNECTUNBLOCK_CMD        _IOW(HI_TUNER_IOC_MAGIC, 14, TUNER_SIGNAL_S)
//#define TUNER_SELECT_SYMBOLRATE_CMD     _IOR(HI_TUNER_IOC_MAGIC, 15, TUNER_DATA_S)
//#define TUNER_CHECK_VALID_I2CADDR       _IOW(HI_TUNER_IOC_MAGIC, 16, TUNER_DATA_S)
#define TUNER_TEST_SINGLE_AGC           _IOWR(HI_TUNER_IOC_MAGIC, 17, AGC_TEST_S)
#define TUNER_GET_FREQ_SYMB_OFFSET      _IOWR(HI_TUNER_IOC_MAGIC, 18, TUNER_DATABUF_S)
#define TUNER_CONNECT_TIMEOUT_CMD       _IOWR(HI_TUNER_IOC_MAGIC, 19, TUNER_TIMEOUT_S)
#define TUNER_GET_SIGANLQUALITY_CMD     _IOWR(HI_TUNER_IOC_MAGIC, 20, TUNER_DATABUF_S)
#define TUNER_GET_SIGANLINFO_CMD        _IOWR(HI_TUNER_IOC_MAGIC, 21, TUNER_SIGNALINFO_S)
#define TUNER_BLINDSCAN_INIT_CMD        _IOWR(HI_TUNER_IOC_MAGIC, 22, TUNER_BLINDSCAN_S)
#define TUNER_BLINDSCAN_ACTION_CMD      _IOWR(HI_TUNER_IOC_MAGIC, 23, TUNER_BLINDSCAN_INFO_S)
#define TUNER_SET_LNBOUT_CMD            _IOWR(HI_TUNER_IOC_MAGIC, 24, TUNER_LNB_OUT_S)
#define TUNER_SEND_CONTINUOUS_22K_CMD   _IOWR(HI_TUNER_IOC_MAGIC, 25, TUNER_CONTINUOUS_22K_S)
#define TUNER_SEND_TONE_CMD             _IOWR(HI_TUNER_IOC_MAGIC, 26, TUNER_TONE_S)
#define TUNER_DISEQC_SEND_MSG_CMD       _IOWR(HI_TUNER_IOC_MAGIC, 27, TUNER_DISEQC_SENDMSG_S)
#define TUNER_DISEQC_RECV_MSG_CMD       _IOWR(HI_TUNER_IOC_MAGIC, 28, TUNER_DISEQC_RECVMSG_S)
#define TUNER_STANDBY_CMD               _IOWR(HI_TUNER_IOC_MAGIC, 29, TUNER_STANDBY_S)
//#define TUNER_DISABLE_CMD               _IOWR(HI_TUNER_IOC_MAGIC, 30, TUNER_DATA_S)
#define TUNER_SETFUNCMODE_CMD           _IOW(HI_TUNER_IOC_MAGIC, 31, TUNER_SETFUNCMODE_S)
#define TUNER_SETPLPNO_CMD              _IOW(HI_TUNER_IOC_MAGIC, 32, TUNER_PLPNO_S)
#define TUNER_GETPLPNUM_CMD             _IOWR(HI_TUNER_IOC_MAGIC, 33, TUNER_PLPNUM_S)
#define TUNER_GETCURPLPTYPE_CMD         _IOWR(HI_TUNER_IOC_MAGIC, 34, TUNER_PLPTYPE_S)
#define TUNER_SETTSOUT_CMD              _IOWR(HI_TUNER_IOC_MAGIC, 35, TUNER_TS_OUT_S)
#define TUNER_TPVERIFY_CMD              _IOWR(HI_TUNER_IOC_MAGIC, 36, TUNER_TP_VERIFY_INFO_S)
#define TUNER_SETSATATTR_CMD            _IOWR(HI_TUNER_IOC_MAGIC, 37, TUNER_SAT_ATTR_S)
#define TUNER_SAMPLE_DATA_CMD           _IOWR(HI_TUNER_IOC_MAGIC, 38, TUNER_SAMPLE_DATA_S)

/* ATV ioctl cmd */
#define TUNER_GET_BAND_RANGE_CMD  		_IOWR(HI_TUNER_IOC_MAGIC, 50, TUNER_BAND_RANGE_S)
#define TUNER_SET_STEP_CMD  			_IOWR(HI_TUNER_IOC_MAGIC, 51, TUNER_STEP_S)
#define TUNER_SET_TOP_ADJUST_CMD  		_IOWR(HI_TUNER_IOC_MAGIC, 52, TUNER_TOP_ADJUST_S)
#define TUNER_GET_BAND_CMD              _IOWR(HI_TUNER_IOC_MAGIC, 53, TUNER_BAND_S)
#define TUNER_SET_FINE_TUNE_CMD         _IOW(HI_TUNER_IOC_MAGIC, 54, TUNER_FINE_TUNE_S)
#define TUNER_GET_STEP_CMD  			_IOWR(HI_TUNER_IOC_MAGIC, 55, TUNER_STEP_S)

/*DTMB ioctl cmd*/
#define TUNER_GET_BITRATE_CMD           _IOWR(HI_TUNER_IOC_MAGIC, 60, TUNER_BITRATE_S)
#define TUNER_SET_SIG_TYPE_CMD           _IOWR(HI_TUNER_IOC_MAGIC, 61, TUNER_SETSIGTYPE_S)

extern HI_S32 tuner_i2c_send_data(HI_U32 u32I2cChannel, HI_U8 u8DevAddress, PTR_TUNER_I2C_DATA_S pstDataStruct);
extern HI_S32 tuner_i2c_receive_data(HI_U32 u32I2cChannel, HI_U8 u8DevAddress, PTR_TUNER_I2C_DATA_S pstDataStruct);
extern HI_VOID reset_special_process_flag(HI_BOOL flag);
extern HI_VOID tuner_mdelay(HI_U32 u32MS);

#endif

