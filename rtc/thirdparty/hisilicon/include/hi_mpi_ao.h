/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name             :   hi_mpi_ao.h
  Version               :   Initial Draft
  Author                :   Hisilicon multimedia software group
  Created               :   2012/12/20
  Last Modified         :
  Description           :
  Function List         :
  History               :
  1.Date                :   2012/12/20
    Author              :   z40717
Modification            :   Created file
******************************************************************************/

#ifndef  __MPI_AO_H__
#define  __MPI_AO_H__

#include "hi_type.h"
#include "hi_unf_sound.h"
#include "hi_drv_ao.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* End of #ifdef __cplusplus */

 /* the type of Adjust Audio */
typedef enum hiHI_MPI_SND_SPEEDADJUST_TYPE_E
{
 HI_MPI_AO_SND_SPEEDADJUST_SRC,     /**<samplerate convert */
 HI_MPI_AO_SND_SPEEDADJUST_PITCH,   /**<Sola speedadjust, reversed */
 HI_MPI_AO_SND_SPEEDADJUST_MUTE,    /**<mute */
 HI_MPI_AO_SND_SPEEDADJUST_BUTT
} HI_MPI_SND_SPEEDADJUST_TYPE_E;

static inline HI_VOID AUDIO_UNFFRAME2DRVFRAME(const HI_UNF_AO_FRAMEINFO_S *pstUnfFrame, AO_FRAMEINFO_S *pstDrvFrame)
{
    pstDrvFrame->u32PtsMs        = pstUnfFrame->u32PtsMs;
    pstDrvFrame->s32BitPerSample = pstUnfFrame->s32BitPerSample;
    pstDrvFrame->bInterleaved    = pstUnfFrame->bInterleaved;
    pstDrvFrame->u32SampleRate   = pstUnfFrame->u32SampleRate;
    pstDrvFrame->u32Channels     = pstUnfFrame->u32Channels;
    pstDrvFrame->u32FrameIndex   = pstUnfFrame->u32FrameIndex;
    pstDrvFrame->u32PcmSamplesPerFrame = pstUnfFrame->u32PcmSamplesPerFrame;
    pstDrvFrame->u32BitsBytesPerFrame  = pstUnfFrame->u32BitsBytesPerFrame;
    pstDrvFrame->u32IEC61937DataType   = pstUnfFrame->u32IEC61937DataType;

    pstDrvFrame->tPcmBuffer  = (HI_VIRT_ADDR_T)((HI_U32)pstUnfFrame->ps32PcmBuffer);  //64w
    pstDrvFrame->tBitsBuffer = (HI_VIRT_ADDR_T)((HI_U32)pstUnfFrame->ps32BitsBuffer);
}

static inline HI_VOID AUDIO_DRVFRAME2UNFFRAME(AO_FRAMEINFO_S *pstDrvFrame, HI_UNF_AO_FRAMEINFO_S *pstUnfFrame)
{
    memset(pstUnfFrame, 0, sizeof(HI_UNF_AO_FRAMEINFO_S));

    pstUnfFrame->u32PtsMs        = pstDrvFrame->u32PtsMs;
    pstUnfFrame->s32BitPerSample = pstDrvFrame->s32BitPerSample;
    pstUnfFrame->bInterleaved    = pstDrvFrame->bInterleaved;
    pstUnfFrame->u32SampleRate   = pstDrvFrame->u32SampleRate;
    pstUnfFrame->u32Channels     = pstDrvFrame->u32Channels;
    pstUnfFrame->u32FrameIndex   = pstDrvFrame->u32FrameIndex;
    pstUnfFrame->u32PcmSamplesPerFrame = pstDrvFrame->u32PcmSamplesPerFrame;
    pstUnfFrame->u32BitsBytesPerFrame  = pstDrvFrame->u32BitsBytesPerFrame;
    pstUnfFrame->u32IEC61937DataType   = pstDrvFrame->u32IEC61937DataType;
}

/******************************* MPI for UNF Sound Init *****************************/
HI_S32   HI_MPI_AO_Init(HI_VOID);
HI_S32   HI_MPI_AO_DeInit(HI_VOID);

/******************************* MPI for UNF_SND *****************************/
HI_S32   HI_MPI_AO_SND_GetDefaultOpenAttr(HI_UNF_SND_E enSound, HI_UNF_SND_ATTR_S *pstAttr);
HI_S32   HI_MPI_AO_SND_Open(HI_UNF_SND_E enSound, const HI_UNF_SND_ATTR_S *pstAttr);
HI_S32   HI_MPI_AO_SND_Close(HI_UNF_SND_E enSound);
HI_S32   HI_MPI_AO_SND_SetMute(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL bMute);
HI_S32   HI_MPI_AO_SND_GetMute(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL *pbMute);
HI_S32   HI_MPI_AO_SND_SetHdmiMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort,
                                              HI_UNF_SND_HDMI_MODE_E enHdmiMode);
HI_S32   HI_MPI_AO_SND_GetHdmiMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort,
                                              HI_UNF_SND_HDMI_MODE_E *penHdmiMode);
HI_S32   HI_MPI_AO_SND_SetSpdifMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort,
                                              HI_UNF_SND_SPDIF_MODE_E enSpdifMode);
HI_S32   HI_MPI_AO_SND_GetSpdifMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort,
                                              HI_UNF_SND_SPDIF_MODE_E *penSpdifMode);
HI_S32   HI_MPI_AO_SND_SetVolume(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort,
                                 const HI_UNF_SND_GAIN_ATTR_S *pstGain);
HI_S32   HI_MPI_AO_SND_GetVolume(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort,
                                 HI_UNF_SND_GAIN_ATTR_S *pstGain);
HI_S32   HI_MPI_AO_SND_SetSpdifCategoryCode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort,
                                              HI_UNF_SND_SPDIF_CATEGORYCODE_E enSpdifCategoryCode);
HI_S32   HI_MPI_AO_SND_GetSpdifCategoryCode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort,
                                              HI_UNF_SND_SPDIF_CATEGORYCODE_E *penSpdifCategoryCode);
HI_S32   HI_MPI_AO_SND_SetSpdifSCMSMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort,
                                              HI_UNF_SND_SPDIF_SCMSMODE_E enSpdifSCMSMode);
HI_S32   HI_MPI_AO_SND_GetSpdifSCMSMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort,
                                              HI_UNF_SND_SPDIF_SCMSMODE_E *enSpdifSCMSMode);
HI_S32   HI_MPI_AO_SND_SetSampleRate(HI_UNF_SND_E enSound, HI_UNF_SAMPLE_RATE_E enSampleRate);
HI_S32   HI_MPI_AO_SND_GetSampleRate(HI_UNF_SND_E enSound, HI_UNF_SAMPLE_RATE_E *penSampleRate);
HI_S32   HI_MPI_AO_SND_SetTrackMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_TRACK_MODE_E enMode);
HI_S32   HI_MPI_AO_SND_GetTrackMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort,
                                    HI_UNF_TRACK_MODE_E *penMode);
HI_S32   HI_MPI_AO_AllTrack_SetMute(HI_UNF_SND_E enSound, HI_BOOL bMute);
HI_S32   HI_MPI_AO_AllTrack_GetMute(HI_UNF_SND_E enSound, HI_BOOL *pbMute);
HI_S32   HI_MPI_AO_SND_SetSmartVolume(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL bSmartVolume);
HI_S32   HI_MPI_AO_SND_GetSmartVolume(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL *pbSmartVolume);

HI_S32   HI_MPI_AO_SND_SetPrecisionVolume(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, const HI_UNF_SND_PRECIGAIN_ATTR_S *pstPreciGain);
HI_S32   HI_MPI_AO_SND_GetPrecisionVolume(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_PRECIGAIN_ATTR_S *pstPreciGain);
HI_S32   HI_MPI_AO_SND_SetBalance(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_S32 s32Balance);
HI_S32   HI_MPI_AO_SND_GetBalance(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_S32 *ps32Balance);

HI_S32   HI_MPI_AO_SND_SetArcEnable(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL bEnable);
HI_S32   HI_MPI_AO_SND_GetArcEnable(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL *pbEnable);
HI_S32   HI_MPI_AO_SND_SetArcMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_ARC_AUDIO_MODE_E enArcMode);
HI_S32   HI_MPI_AO_SND_GetArcMode(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_ARC_AUDIO_MODE_E *penArcMode);
HI_S32   HI_MPI_AO_SND_SetArcCap(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_ARC_AUDIO_CAP_S *pstArcCap);
HI_S32   HI_MPI_AO_SND_GetArcCap(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_UNF_SND_ARC_AUDIO_CAP_S *pstArcCap);

HI_S32   HI_MPI_AO_SND_SetPeqAttr(HI_UNF_SND_E enSound, const HI_UNF_SND_PEQ_ATTR_S *pstPeqAttr);
HI_S32   HI_MPI_AO_SND_GetPeqAttr(HI_UNF_SND_E enSound, HI_UNF_SND_PEQ_ATTR_S *pstPeqAttr);
HI_S32   HI_MPI_AO_SetPeqEnable(HI_UNF_SND_E enSound, HI_BOOL bEnable);
HI_S32   HI_MPI_AO_GetPeqEnable(HI_UNF_SND_E enSound, HI_BOOL *pbEnable);

HI_S32   HI_MPI_AO_SND_SetGeqAttr(HI_UNF_SND_E enSound, const HI_UNF_SND_GEQ_ATTR_S *pstGeqAttr);
HI_S32   HI_MPI_AO_SND_GetGeqAttr(HI_UNF_SND_E enSound, HI_UNF_SND_GEQ_ATTR_S *pstGeqAttr);
HI_S32   HI_MPI_AO_SetGeqEnable(HI_UNF_SND_E enSound, HI_BOOL bEnable);
HI_S32   HI_MPI_AO_GetGeqEnable(HI_UNF_SND_E enSound, HI_BOOL *pbEnable);
HI_S32   HI_MPI_AO_SetGeqGain(HI_UNF_SND_E enSound, HI_U32 u32Band, HI_S32 s32Gain);
HI_S32   HI_MPI_AO_GetGeqGain(HI_UNF_SND_E enSound, HI_U32 u32Band, HI_S32 *ps32Gain);

HI_S32   HI_MPI_AO_SND_SetAllCastMute(HI_UNF_SND_E enSound, HI_BOOL bMute);
HI_S32   HI_MPI_AO_SND_GetAllCastMute(HI_UNF_SND_E enSound, HI_BOOL *pbMute);
HI_S32   HI_MPI_AO_SND_GetCastDefaultOpenAttr(HI_UNF_SND_CAST_ATTR_S *pstAttr);
HI_S32   HI_MPI_AO_SND_CreateCast(HI_UNF_SND_E enSound, HI_UNF_SND_CAST_ATTR_S *pstCastAttr, HI_HANDLE *phCast);
HI_S32   HI_MPI_AO_SND_DestroyCast(HI_HANDLE hCast);
HI_S32   HI_MPI_AO_SND_SetCastEnable(HI_HANDLE hCast, HI_BOOL bEnable);
HI_S32   HI_MPI_AO_SND_GetCastEnable(HI_HANDLE hCast, HI_BOOL *pbEnable);
HI_S32   HI_MPI_AO_SND_AcquireCastFrame(HI_HANDLE hCast, HI_UNF_AO_FRAMEINFO_S *pstCastFrame);
HI_S32   HI_MPI_AO_SND_ReleaseCastFrame(HI_HANDLE hCast, HI_UNF_AO_FRAMEINFO_S *pstCastFrame);
HI_U32   HI_MPI_AO_Cast_SetMute(HI_HANDLE hCast, HI_BOOL bMute);
HI_S32   HI_MPI_AO_Cast_GetMute(HI_HANDLE hCast, HI_BOOL *pbMute);
HI_S32   HI_MPI_AO_SND_SetCastAbsWeight (HI_HANDLE hCast, const HI_UNF_SND_ABSGAIN_ATTR_S *pstAbsWeightGain);
HI_S32   HI_MPI_AO_SND_GetCastAbsWeight(HI_HANDLE hCast, HI_UNF_SND_ABSGAIN_ATTR_S *pstAbsWeightGain);

HI_S32   HI_MPI_AO_SND_AttachAef(HI_UNF_SND_E enSound, HI_U32 u32AefId, HI_U32 *pu32AefProcAddr);
HI_S32   HI_MPI_AO_SND_DetachAef(HI_UNF_SND_E enSound, HI_U32 u32AefId);
HI_S32   HI_MPI_AO_SND_SetAefBypass(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL bBypass);
HI_S32   HI_MPI_AO_SND_GetAefBypass(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E enOutPort, HI_BOOL *pbBypass);
HI_S32   HI_MPI_AO_SND_GetXrunCount(HI_UNF_SND_E enSound,HI_U32 *pu32Count);
HI_BOOL  HI_MPI_AO_Track_CheckIsLowLatency(HI_HANDLE hTrack);
HI_S32   HI_MPI_AO_SND_SetLowLatency(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E eOutPort, HI_U32 u32LatecnyMs);
HI_S32   HI_MPI_AO_SND_GetLowLatency(HI_UNF_SND_E enSound, HI_UNF_SND_OUTPUTPORT_E eOutPort, HI_U32* pu32LatecnyMs);
//HI_S32   HI_MPI_AO_SND_AttachTrack(HI_UNF_SND_E enSound, HI_HANDLE hTrack);   //HI_MPI_AO_TRACK_AttachSnd
//HI_S32   HI_MPI_AO_SND_DetachTrack(HI_UNF_SND_E enSound, HI_HANDLE hTrack);
HI_S32   HI_MPI_AO_SND_SetAlsaPrescale(HI_UNF_SND_E enSound, HI_UNF_SND_PRECIGAIN_ATTR_S *pstPreciGain);
HI_S32   HI_MPI_AO_SND_TrackConfigInit(HI_UNF_SND_E enSound, const HI_UNF_SND_TRACK_CONFIG_S* pstTrackConfig);

/******************************* MPI Track for UNF_SND/UNF_Mixer *****************************/
HI_S32   HI_MPI_AO_SND_GetTrackInfo(HI_UNF_SND_E enSound, HI_UNF_SND_TRACK_INFO_S *pstTrackInfo);
HI_S32   HI_MPI_AO_Track_GetDefaultOpenAttr(HI_UNF_SND_TRACK_TYPE_E enTrackType, HI_UNF_AUDIOTRACK_ATTR_S *pstAttr);
HI_S32   HI_MPI_AO_Track_GetAttr(HI_HANDLE hTrack, HI_UNF_AUDIOTRACK_ATTR_S    *pstAttr);
HI_S32   HI_MPI_AO_Track_SetAttr(HI_HANDLE hTrack, const HI_UNF_AUDIOTRACK_ATTR_S    *pstAttr);
HI_S32   HI_MPI_AO_Track_Create(HI_UNF_SND_E enSound, const HI_UNF_AUDIOTRACK_ATTR_S *pstAttr, HI_HANDLE *phTrack);
HI_S32   HI_MPI_AO_Track_Destroy(HI_HANDLE hTrack);
HI_S32   HI_MPI_AO_Track_Start(HI_HANDLE hTrack);
HI_S32   HI_MPI_AO_Track_Stop(HI_HANDLE hTrack);
HI_S32   HI_MPI_AO_Track_Pause(HI_HANDLE hTrack);
HI_S32   HI_MPI_AO_Track_Flush(HI_HANDLE hTrack);
HI_S32   HI_MPI_AO_Track_SetFifoBypass(HI_HANDLE hTrack, HI_BOOL bEnable);
HI_S32   HI_MPI_AO_Track_SendData(HI_HANDLE hTrack, const HI_UNF_AO_FRAMEINFO_S *pstAOFrame);
HI_S32   HI_MPI_AO_Track_SetPriority(HI_HANDLE hTrack, HI_BOOL bEnable);
HI_S32   HI_MPI_AO_Track_GetPriority(HI_HANDLE hTrack, HI_BOOL *pbEnable);
HI_S32   HI_MPI_AO_Track_SetWeight(HI_HANDLE hTrack, const HI_UNF_SND_GAIN_ATTR_S *pstTrackGain);
HI_S32   HI_MPI_AO_Track_GetWeight(HI_HANDLE hTrack, HI_UNF_SND_GAIN_ATTR_S* pstTrackGain);
#define  HI_MPI_AO_Track_Resume HI_MPI_AO_Track_Start
HI_S32   HI_MPI_AO_Track_AttachAi(const HI_HANDLE hAi, const HI_HANDLE hTrack);
HI_S32   HI_MPI_AO_Track_DetachAi(const HI_HANDLE hAi, const HI_HANDLE hTrack);
HI_S32   HI_MPI_AO_Track_SetAbsWeight(HI_HANDLE hTrack, const HI_UNF_SND_ABSGAIN_ATTR_S *pstAbsWeightGain);
HI_S32   HI_MPI_AO_Track_GetAbsWeight(HI_HANDLE hTrack, HI_UNF_SND_ABSGAIN_ATTR_S *pstAbsWeightGain);
HI_S32   HI_MPI_AO_Track_SetPrescale(HI_HANDLE hTrack, const HI_UNF_SND_PRECIGAIN_ATTR_S *pstPreciGain);
HI_S32   HI_MPI_AO_Track_GetPrescale(HI_HANDLE hTrack, HI_UNF_SND_PRECIGAIN_ATTR_S *pstPreciGain);
HI_S32   HI_MPI_AO_Track_SetMute(HI_HANDLE hTrack, HI_BOOL bMute);
HI_S32   HI_MPI_AO_Track_GetMute(HI_HANDLE hTrack, HI_BOOL *pbMute);

HI_S32   HI_MPI_AO_Track_SetChannelMode(HI_HANDLE hTrack, HI_UNF_TRACK_MODE_E enMode);
HI_S32   HI_MPI_AO_Track_GetChannelMode(HI_HANDLE hTrack, HI_UNF_TRACK_MODE_E *penMode);

// HI_UNF_SND_TRACK_TYPE_VIRTUAL only
HI_S32   HI_MPI_AO_Track_AcquireFrame(HI_HANDLE hTrack, HI_UNF_AO_FRAMEINFO_S *pstAOFrame, HI_U32 u32TimeoutMs);
HI_S32   HI_MPI_AO_Track_ReleaseFrame(HI_HANDLE hTrack, HI_UNF_AO_FRAMEINFO_S *pstAOFrame);

HI_S32   HI_MPI_AO_Track_SetSource(HI_HANDLE hTrack, HI_UNF_SND_SOURCE_E enSource);

/******************************* MPI Track for MPI_AVPlay only **********************/
HI_S32   HI_MPI_AO_Track_SetEosFlag(HI_HANDLE hTrack, HI_BOOL bEosFlag);
HI_S32   HI_MPI_AO_Track_SetSpeedAdjust(HI_HANDLE hTrack, HI_S32 s32Speed, HI_MPI_SND_SPEEDADJUST_TYPE_E enType);
HI_S32   HI_MPI_AO_Track_GetDelayMs(const HI_HANDLE hTrack, HI_U32 *pDelayMs);
HI_S32   HI_MPI_AO_Track_GetBufDelayMs(const HI_HANDLE hTrack, HI_U32 *pDelayMs);
HI_S32   HI_MPI_AO_Track_IsBufEmpty(const HI_HANDLE hTrack, HI_BOOL *pbEmpty);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* End of #ifdef __cplusplus */

#endif //__MPI_AO_H__