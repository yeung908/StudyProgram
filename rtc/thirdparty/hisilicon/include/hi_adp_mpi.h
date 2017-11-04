#ifndef  _COMMON_MPI_H
#define  _COMMON_MPI_H

#include "hi_type.h"
#include "hi_unf_common.h"
#include "hi_unf_avplay.h"
#include "hi_unf_vo.h"
#include "hi_unf_atv.h"
#include "hi_unf_vi.h"
#include "hi_adp.h"
#include "hi_adp_search.h"
#include "hi_adp_boardcfg.h"
#include "hi_unf_ai.h"

#define DOLBYPLUS_HACODEC_SUPPORT
#if  defined (CHIP_TYPE_hi3716mv300_fpga)
 #define TLV320_AUDIO_DEVICE_ENABLE
#else
 #define SLIC_AUDIO_DEVICE_ENABLE
#endif

/* ADP时序信息 */
typedef struct hiADP_TIMING_INFO_S
{
	HI_U32  u32TimingIndex;            /* Timing序号 */
    HI_BOOL bInterlace;                /* 逐隔行信息 */
	HI_U32  u32Width;                  /* 标准信号一帧的宽度 */
	HI_U32  u32Height;                 /* 标准信号一帧的高度，即隔行信号是两场的高度，逐行信号是一帧的高度 */
	HI_U32  u32FrameRate;              /* 标准的场频，如果是隔行信号则为场频，如果是逐行信号则为帧率 */
    HI_UNF_VIDEO_FORMAT_E       enPixelFmt;     /* 输入像素格式 RGB444,YUV444/422 */ 
    HI_UNF_COLOR_SPACE_E        enColorSpace; /* 彩色空间 */
	HI_UNF_OVERSAMPLE_MODE_E    enOversample; /* 过采样信息 */
	HI_UNF_PIXEL_BITWIDTH_E     enBitWidth;   /* 位宽信息 */
    HI_UNF_INPUT_SOURCE_TYPE_E  enSourceType;    /* 输入信源类型 */
    HI_UNF_COLOR_SYS_E          enColorSys;      /* ATV/CVBS信源下的彩色制式 */
    HI_UNF_VI_ACCESS_TYPE_E     enAccessType;
    HI_UNF_VIDEO_FRAME_PACKING_TYPE_E en3DType;
    HI_U32                      u32Vblank;
    HI_BOOL bPcMode;
    HI_BOOL bHdmiMode;
} HI_ADP_TIMING_INFO_S;


#if 0
HI_S32	MPI_VoInit();
HI_S32	MPI_VoDeInit();
HI_S32	MPI_SndInit(HI_VOID);
HI_S32	MPI_SndDeInit(HI_VOID);
HI_S32	MPI_DispInit(HI_VOID);
HI_S32	MPI_DispDeInit(HI_VOID);
HI_S32	MPI_AVPlayInit(HI_VOID);
HI_S32	MPI_AVPlayDeInit(HI_VOID);
HI_S32	MPI_AVPlayStart(HI_HANDLE hAvplay, DB_PROGRAM_S *psProg);
HI_S32	MPI_VoDestroyWin(HI_HANDLE hWin);
HI_S32	MPI_VoCreateWin(HI_HANDLE *phWin, HI_U8 u8WinNum);
HI_S32   MPI_SetVideoAttr(HI_HANDLE hAvplay, HI_U32 pid, HI_UNF_VCODEC_TYPE_E videotype);
HI_S32   MPI_SetAudioAttr(HI_HANDLE hAvplay, HI_U32 pid, HI_U32 audiotype);
#else
/* **********************************Demux  Common Interface********************************/
HI_S32 HIADP_Demux_Init(HI_U32 DmxPortID,HI_U32 TsPortID);
    
HI_S32 HIADP_Demux_DeInit(HI_U32 DmxPortID);

/************************************DISPLAY  Common Interface*******************************/
HI_S32 HIADP_Disp_StrToFmt(HI_CHAR *pszFmt);

HI_S32 HIADP_Disp_Init(HI_UNF_ENC_FMT_E enFormat);

HI_S32 HIADP_Disp_DeInit(HI_VOID);


/****************************VO  Common Interface********************************************/
HI_S32 HIADP_VO_Init(HI_UNF_VO_DEV_MODE_E enDevMode);

HI_S32 HIADP_VO_CreatWin(HI_RECT_S * pstWinRect, HI_HANDLE * phWin);

HI_S32 HIADP_VO_DeInit();

/*****************************************SOUND  Common Interface************************************/
HI_S32 HIADP_Snd_Init(HI_VOID);


HI_S32 HIADP_Snd_DeInit(HI_VOID);

HI_S32 HIADP_Snd_RegAefAuthLib(HI_VOID);

/*Only Support Single AI Chn*/
HI_S32 HIADP_AI_Init(HI_UNF_AI_E enAISrc, HI_HANDLE *pAIHandle, HI_HANDLE *pTrackSlave, HI_HANDLE *pATrackVir);

HI_S32 HIADP_AI_DeInit(HI_HANDLE hAI, HI_HANDLE hAISlave, HI_HANDLE hAIVir);

/*****************************************AIAO  Common Interface************************************/
HI_S32 HIADP_AIAO_Init(HI_S32 DevId, HI_S32 AI_Ch, HI_S32 AO_Ch, HI_UNF_SAMPLE_RATE_E enSamplerate, HI_U32 u32SamplePerFrame);


HI_S32 HIADP_AIAO_DeInit(HI_VOID);

HI_S32 HIADP_SLIC_Open(HI_VOID);
HI_S32 HIADP_SLIC_Close(HI_VOID);
HI_S32 HIADP_SLIC_GetHookOff(HI_BOOL *pbEnable);
HI_S32 HIADP_SLIC_GetHookOn(HI_BOOL *pbEnable);
HI_S32 HIADP_SLIC_SetRinging(HI_BOOL bEnable);


/**************************************AVPLAY  Common Interface***************************************/
HI_S32 HIADP_AVPlay_RegADecLib();

HI_S32 HIADP_AVPlay_Init();

HI_S32 HIADP_AVPlay_Create(HI_HANDLE *avplay,HI_U32 u32DemuxId,
                                 HI_UNF_AVPLAY_STREAM_TYPE_E streamtype,
                                 HI_UNF_VCODEC_CAP_LEVEL_E vdeccap,
                                 HI_U32 channelflag);

HI_S32 HIADP_AVPlay_SetVdecAttr(HI_HANDLE hAvplay,HI_UNF_VCODEC_TYPE_E enType,HI_UNF_VCODEC_MODE_E enMode);

HI_S32 HIADP_AVPlay_SetAdecAttr(HI_HANDLE hAvplay,HI_U32 enADecType,HI_HA_DECODEMODE_E enMode, HI_S32 isCoreOnly);

HI_S32 HIADP_AVPlay_PlayProg(HI_HANDLE hAvplay,PMT_COMPACT_TBL *pProgTbl,HI_U32 ProgNum,HI_BOOL bAudPlay);

HI_S32 HIADP_AVPlay_PlayAud(HI_HANDLE hAvplay,PMT_COMPACT_TBL *pProgTbl,HI_U32 ProgNum);

HI_S32 HIADP_AVPlay_SwitchAud(HI_HANDLE hAvplay,HI_U32 AudPid, HI_U32 u32AudType);


HI_S32 HIADP_AENC_GetAttr(HI_UNF_AENC_ATTR_S *pAencAttr, HI_VOID *pstConfig);

HI_S32 HIADP_MCE_Exit(HI_VOID);
#endif

HI_S32 HIADP_StartVo(HI_HANDLE *ps_hWindow);
HI_S32 HIADP_StopVo(HI_HANDLE hWindow);
HI_S32 HIADP_InitVi(HI_VOID);
HI_S32 HIADP_DeInitVi(HI_VOID);
HI_S32 HIADP_GetViHandle(HI_HANDLE *pViHandle);
HI_S32 HIADP_GetWinHandle(HI_HANDLE *pWinHandle);
HI_S32 HIADP_GetPlayReady(HI_BOOL *bPlay);
HI_S32 HIADP_StartTvd();
HI_S32 HIADP_StopTvd();
HI_S32 HIADP_SwitchAtvSrc(HI_UNF_INPUT_SOURCE_TYPE_E enAtvSrc);
HI_S32 HIADP_AtvGetTimingInfo(HI_UNF_INPUT_SOURCE_TYPE_E enAtvSrc, HI_ADP_TIMING_INFO_S *pstTimingInfo);
HI_S32 HIADP_AtvGetSigStatus(HI_UNF_INPUT_SOURCE_TYPE_E enAtvSrc, HI_UNF_SIG_STATUS_E *penSignalStatusPre);
HI_S32 HIADP_StartAtvMoniter(HI_VOID);
HI_S32 HIADP_VI_Set3DFmtType(HI_UNF_VIDEO_FRAME_PACKING_TYPE_E enVi3DFmt);
HI_VOID HIADP_VI_Clean3DFmtType(HI_VOID);
HI_S32 HIADP_DMX_AttachTSPort(HI_U32 Dmxid, HI_U32 TunerID);


#endif
