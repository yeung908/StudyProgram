#include <string.h>
#include <sys/time.h>

#include <pthread.h>
#include <sys/wait.h>
#include <semaphore.h>

#include "hi_common.h"
#include "hi_error_mpi.h"
#include "hi_unf_common.h"

#include "hi_unf_tvd.h"
#include "hi_unf_hddec.h"
#include "hi_unf_hdmirx.h"

#include "hi_unf_demux.h"
#include "hi_unf_avplay.h"
#include "hi_unf_vi.h"
#include "hi_unf_vo.h"
#include "hi_unf_sound.h"
#include "hi_unf_ai.h"
#include "hi_unf_disp.h"
#include "hi_unf_panel.h"
#include "hi_unf_pq.h"
#include "hi_unf_mdbg.h"


#include "hi_audio_codec.h"


#ifdef HI_MCE_SUPPORT
#include "hi_unf_mce.h"
#endif

#include "hi_adp_mpi.h"
#include "hi_adp.h"
#include "hi_adp_data.h"
#include "hi_adp_audio.h"
//#include "hi_adp_hdmi.h"
#include "hi_adp_boardcfg.h"

#include "HA.AUDIO.G711.codec.h"
#include "HA.AUDIO.MP3.decode.h"
#include "HA.AUDIO.MP2.decode.h"
#include "HA.AUDIO.AAC.decode.h"
#include "HA.AUDIO.DRA.decode.h"
#include "HA.AUDIO.PCM.decode.h"
#include "HA.AUDIO.AMRNB.codec.h"
#include "HA.AUDIO.AMRWB.codec.h"
#include "HA.AUDIO.TRUEHDPASSTHROUGH.decode.h"
#include "HA.AUDIO.DOLBYTRUEHD.decode.h"
#include "HA.AUDIO.DTSHD.decode.h"
#if defined (DOLBYPLUS_HACODEC_SUPPORT)
 #include "HA.AUDIO.DOLBYPLUS.decode.h"
#endif
#include "HA.AUDIO.AC3PASSTHROUGH.decode.h"
#include "HA.AUDIO.DTSM6.decode.h"

#include "HA.AUDIO.DTSPASSTHROUGH.decode.h"
#include "HA.AUDIO.FFMPEG_DECODE.decode.h"
#include "HA.AUDIO.AAC.encode.h"

#define MPI_DEMUX_NUM 5
#define MPI_DEMUX_PLAY 0
#define MPI_DEMUX_REC_0 1
#define MPI_DEMUX_REC_1 2
#define MPI_DEMUX_TIMETHIFT 3
#define MPI_DEMUX_PLAYBACK 4

#define FIRST_TUNER   0
#define SECOND_TUNER  1
#define THIRD_TUNER   2
#define FOURTH_TUNER  3


/* 
big-endian pcm output format, if extword is 1, choose normal pcm decoder,
                                            if extword is 2, choose wifidsp_lpcm decoder(Frame Header:0xA0,0x06)
                                            if others, fail to decode.
*/
#define NORMAL_PCM_EXTWORD    1
#define WIFIDSP_LPCM_EXTWORD  2

sem_t bin_sem;
static pthread_t            s_stMonitorThrd;
static volatile HI_BOOL     s_bMonitorEn    = HI_FALSE;
static volatile HI_BOOL     s_bStopPlay     = HI_TRUE;
HI_HANDLE                   s_hWindow       = 0;
HI_HANDLE                   s_hVi           = 0;
HI_HANDLE                   s_hAi           = 0;    
HI_HANDLE                   s_hTrackVir     = 0;
HI_HANDLE                   s_hTrackSlave   = 0;
static volatile HI_BOOL     s_bSourceChange = HI_FALSE;
HI_UNF_INPUT_SOURCE_TYPE_E  volatile s_enAtvSrc = HI_UNF_INPUT_SOURCE_BUTT;
HI_UNF_VIDEO_FRAME_PACKING_TYPE_E enVi3DFmtType = HI_UNF_FRAME_PACKING_TYPE_BUTT;
HI_U8 u8DecOpenBuf[1024];
HI_U8 u8EncOpenBuf[1024];

static HI_CHAR *g_pDispFmtString[HI_UNF_ENC_FMT_BUTT+1] = {
    "1080P_60","1080P_50","1080P_30","1080P_25",
    "1080P_24","1080i_60","1080i_50",        
    "720P_60","720P_50","576P_50","480P_60",         
    "PAL","PAL_N","PAL_Nc",          
    "NTSC","NTSC_J","NTSC_PAL_M",      
    "SECAM_SIN","SECAM_COS",
    "BUTT"};

#if defined (DOLBYPLUS_HACODEC_SUPPORT)

DOLBYPLUS_STREAM_INFO_S g_stDDpStreamInfo;

/*dolby Dual Mono type control*/
HI_U32  g_u32DolbyAcmod = 0;
HI_BOOL g_bDrawChnBar = HI_TRUE;

HI_BOOL                     g_bMonitorOutEn = HI_FALSE;
HI_HANDLE                   s_hWindow0       = 0;

#endif

/************************************DISPLAY Common Interface*******************************/
HI_S32 HIADP_SetMonitorOutEn(HI_BOOL bEnable)
{
    g_bMonitorOutEn = bEnable;
    return HI_SUCCESS;
}

HI_BOOL HIADP_GetMonitorOutEn()
{
    return g_bMonitorOutEn;
}


HI_S32 HIADP_Disp_StrToFmt(HI_CHAR *pszFmt)
{
    HI_S32 i;
    HI_UNF_ENC_FMT_E fmtReturn = HI_UNF_ENC_FMT_BUTT;

    if (NULL == pszFmt)
    {
        return HI_UNF_ENC_FMT_BUTT;
    }

    for (i = 0; i < HI_UNF_ENC_FMT_BUTT; i++)
    {
        if (strcasestr(pszFmt, g_pDispFmtString[i]))
        {
            fmtReturn = i;        
            break;
        }
    }

    if (i >= HI_UNF_ENC_FMT_BUTT)
    {
        i = HI_UNF_ENC_FMT_720P_50;
        fmtReturn = i;   
        printf("\n!!! Can NOT match format, set format to is '%s'/%d.\n\n", g_pDispFmtString[i], i);
    }
    else
    {
        printf("\n!!! The format is '%s'/%d.\n\n", g_pDispFmtString[i], i);
    }
    
    return fmtReturn;
}

HI_S32 HIADP_Disp_Init(HI_UNF_ENC_FMT_E enFormat)
{
    HI_S32                      Ret;
    HI_UNF_DISP_BG_COLOR_S      BgColor;
    HI_UNF_DISP_INTF_S          stIntf;
    HI_UNF_DISP_OFFSET_S        offset;

    Ret = HI_UNF_DISP_Init();
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_DISP_Init failed, Ret=%#x.\n", Ret);
        return Ret;
    }

    stIntf.enIntfType     = HI_UNF_DISP_INTF_TYPE_PANEL;
    stIntf.unIntf.enPanel = HI_UNF_DISP_PANEL_0;
    stIntf.unIntf.stYPbPr.u8DacPb    = DAC_YPBPR_PB;
    stIntf.unIntf.stYPbPr.u8DacPr    = DAC_YPBPR_PR;

    Ret = HI_UNF_DISP_AttachIntf(HI_UNF_DISPLAY1, &stIntf, 1);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_DISP_AttachIntf failed, Ret=%#x.\n", Ret);
        HI_UNF_DISP_DeInit();
        return Ret;
    } 

    Ret = HI_UNF_DISP_SetVirtualScreen(HI_UNF_DISPLAY1, 1920, 1080);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_DISP_SetVirtualScreen failed, Ret=%#x.\n", Ret);
        HI_UNF_DISP_DeInit();
        return Ret;          
    }

    offset.u32Left      = 0;
    offset.u32Top       = 0;
    offset.u32Right     = 0;
    offset.u32Bottom    = 0;   
    /*set display1 screen offset*/
    Ret = HI_UNF_DISP_SetScreenOffset(HI_UNF_DISPLAY1, &offset);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_DISP_SetBgColor failed, Ret=%#x.\n", Ret);
        HI_UNF_DISP_DeInit();
        return Ret;
    }

    /*set display0 screen offset*/
    Ret = HI_UNF_DISP_SetScreenOffset(HI_UNF_DISPLAY0, &offset);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_DISP_SetBgColor failed, Ret=%#x.\n", Ret);
        HI_UNF_DISP_DeInit();
        return Ret;          
    }

    BgColor.u8Red   = 0;
    BgColor.u8Green = 0;
    BgColor.u8Blue  = 0;
    Ret = HI_UNF_DISP_SetBgColor(HI_UNF_DISPLAY1, &BgColor);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_DISP_SetBgColor failed, Ret=%#x.\n", Ret);
        HI_UNF_DISP_DeInit();
        return Ret;          
    }
    Ret = HI_UNF_PANEL_Init();
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_PANEL_Init failed, Ret=%#x.\n", Ret);
        HI_UNF_DISP_DeInit();
        return Ret;
    }
#if 0
    Ret = HI_UNF_PANEL_SetIndex(10);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_PANEL_SetIndex failed, Ret=%#x.\n", Ret);
        HI_UNF_PANEL_DeInit();
        HI_UNF_DISP_DeInit();
        return Ret;
    }
#endif
    Ret = HI_UNF_DISP_Open(HI_UNF_DISPLAY1);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_DISP_Open DISPLAY1 failed, Ret=%#x.\n", Ret);
        HI_UNF_DISP_DeInit();
        return Ret;
    }

    Ret = HI_UNF_DISP_Open(HI_UNF_DISPLAY0);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_DISP_Open DISPLAY0 failed, Ret=%#x.\n", Ret);
        HI_UNF_DISP_Close(HI_UNF_DISPLAY1);
        HI_UNF_DISP_DeInit();
        return Ret;
    }


    return HI_SUCCESS;
}


HI_S32 HIADP_Disp_DeInit(HI_VOID)
{
    HI_S32                      Ret;

    Ret = HI_UNF_DISP_Close(HI_UNF_DISPLAY1);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_DISP_Close failed, Ret=%#x.\n", Ret);
        return Ret;
    }

    Ret = HI_UNF_DISP_Close(HI_UNF_DISPLAY0);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_DISP_Close failed, Ret=%#x.\n", Ret);
        return Ret;
    }


    Ret = HI_UNF_DISP_DeInit();
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_DISP_DeInit failed, Ret=%#x.\n", Ret);
        return Ret;
    }
    
    Ret = HI_UNF_PANEL_DeInit();
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_PANEL_DeInit failed, Ret=%#x.\n", Ret);
        return Ret;
    }


    return HI_SUCCESS;
}

/****************************VO Common Interface********************************************/
HI_S32 HIADP_VO_Init(HI_UNF_VO_DEV_MODE_E enDevMode)
{
    HI_S32             Ret;


    Ret = HI_UNF_VO_Init(enDevMode);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_VO_Init failed.\n");
        return Ret;
    }

    return HI_SUCCESS;
}    

HI_S32 HIADP_VO_CreatWin(HI_RECT_S *pstWinRect,HI_HANDLE *phWin)
{
    HI_S32 Ret;
    HI_UNF_WINDOW_ATTR_S   WinAttr;
    memset(&WinAttr, 0, sizeof(HI_UNF_WINDOW_ATTR_S));
    WinAttr.enDisp = HI_UNF_DISPLAY1;
    WinAttr.bVirtual = HI_FALSE;
    WinAttr.stWinAspectAttr.enAspectCvrs = HI_UNF_VO_ASPECT_CVRS_CUSTOM;
    WinAttr.stWinAspectAttr.bUserDefAspectRatio = HI_FALSE;
    WinAttr.stWinAspectAttr.u32UserAspectWidth  = 0;
    WinAttr.stWinAspectAttr.u32UserAspectHeight = 0;
    WinAttr.bUseCropRect = HI_FALSE;
    WinAttr.stInputRect.s32X = 0;
    WinAttr.stInputRect.s32Y = 0;
    WinAttr.stInputRect.s32Width = 0;
    WinAttr.stInputRect.s32Height = 0;

    if (HI_NULL == pstWinRect)
    {
        memset(&WinAttr.stOutputRect, 0x0, sizeof(HI_RECT_S));
    }
    else
    {
        memcpy(&WinAttr.stOutputRect,pstWinRect,sizeof(HI_RECT_S));
    }

    Ret = HI_UNF_VO_CreateWindow(&WinAttr, phWin);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_VO_CreateWindow failed.\n");
        return Ret;
    }

    return HI_SUCCESS;
}

HI_S32 HIADP_VO_DeInit()
{
    HI_S32         Ret;

    Ret = HI_UNF_VO_DeInit();
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_VO_DeInit failed.\n");
        return Ret;
    }

    return HI_SUCCESS;
}

/*****************************************SOUND Common Interface************************************/
HI_S32 HIADP_Snd_Init(HI_VOID)
{
    HI_S32                  Ret;
    HI_UNF_SND_ATTR_S       stAttr;

    Ret = HI_UNF_SND_Init();
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_SND_Init failed.\n");
        return Ret;
    }
    Ret = HI_UNF_SND_GetDefaultOpenAttr(HI_UNF_SND_0, &stAttr);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_SND_GetDefaultOpenAttr failed.\n");
        return Ret;
    }

    Ret = HI_UNF_SND_Open(HI_UNF_SND_0, &stAttr);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_SND_Open failed.\n");
        return Ret;
    }
    
    return HI_SUCCESS;
}

HI_S32 HIADP_Snd_DeInit(HI_VOID)
{
    HI_S32                  Ret;

    Ret = HI_UNF_SND_Close(HI_UNF_SND_0);
    if (Ret != HI_SUCCESS )
    {
        printf("call HI_UNF_SND_Close failed.\n");
        return Ret;
    }

    Ret = HI_UNF_SND_DeInit();
    if (Ret != HI_SUCCESS )
    {
        printf("call HI_UNF_SND_DeInit failed.\n");
        return Ret;
    }
    
    return HI_SUCCESS;
}

/*****************************************AI Common Interface************************************/
HI_S32 HIADP_AI_Init(HI_UNF_AI_E enAISrc, HI_HANDLE *pAIHandle, HI_HANDLE *pTrackSlave, HI_HANDLE *pATrackVir)
{
    HI_S32                  Ret;
    HI_UNF_AI_ATTR_S        stAitAttr = {0};
    HI_UNF_AUDIOTRACK_ATTR_S  stTrackAttr;

    printf("Enter Ai Init\n");

    Ret = HI_UNF_AI_Init();
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_AI_Init failed.\n");
    }
    
    Ret = HI_UNF_AI_GetDefaultAttr(enAISrc,&stAitAttr);
    stAitAttr.u32PcmFrameMaxNum = 16;
    //stAitAttr.u32PcmSamplesPerFrame = 10240;
    if(HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_AI_GetDefaultAttr Failed \n");
        return Ret;
    }
    
    Ret = HI_UNF_AI_Create(enAISrc, &stAitAttr, pAIHandle);
    if(HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_AI_Create Failed \n");
        return Ret;
    }
    

    Ret = HI_UNF_SND_GetDefaultTrackAttr(HI_UNF_SND_TRACK_TYPE_SLAVE, &stTrackAttr);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_SND_GetDefaultTrackAttr failed.\n");
        return Ret;
    }
    Ret = HI_UNF_SND_CreateTrack(HI_UNF_SND_0,&stTrackAttr, pTrackSlave);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_SND_CreateTrack failed.\n");
        return Ret;
    }

    Ret = HI_UNF_SND_Attach(*pTrackSlave, *pAIHandle);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_SND_Attach failed.\n");
        return Ret;
    }

    Ret = HI_UNF_SND_GetDefaultTrackAttr(HI_UNF_SND_TRACK_TYPE_VIRTUAL, &stTrackAttr);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_SND_GetDefaultTrackAttr failed.\n");
        return Ret;
    }

    Ret = HI_UNF_SND_CreateTrack(HI_UNF_SND_0,&stTrackAttr,pATrackVir);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_SND_CreateTrack failed.\n");
        return Ret;
    }

    Ret = HI_UNF_SND_Attach(*pATrackVir, *pAIHandle);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_SND_Attach failed.\n");
        return Ret;
    }

    Ret = HI_UNF_AI_SetEnable(*pAIHandle, HI_TRUE);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_AI_SetEnable failed.\n");
        return Ret;        
    }

    
    return HI_SUCCESS;
}

HI_S32 HIADP_AI_DeInit(HI_HANDLE hAI, HI_HANDLE hAISlave, HI_HANDLE hAIVir)
{
    HI_S32                  Ret;

    printf("Enter Ai DeInit\n");
    Ret = HI_UNF_AI_SetEnable(hAI, HI_FALSE);    
    if (Ret != HI_SUCCESS )
    {
        printf("call HI_UNF_AI_SetEnable failed.\n");
        return Ret;
    }

    HI_UNF_SND_Detach(hAIVir, hAI);
    HI_UNF_SND_DestroyTrack(hAIVir);
    HI_UNF_SND_Detach(hAISlave, hAI);
    HI_UNF_SND_DestroyTrack(hAISlave);
    
    HI_UNF_AI_Destroy(hAI);
    if (Ret != HI_SUCCESS )
    {
        printf("call HI_UNF_AI_Destroy failed.\n");
        return Ret;
    }
        
    HI_UNF_AI_DeInit();
    if (Ret != HI_SUCCESS )
    {
        printf("call HI_UNF_AI_DeInit failed.\n");
        return Ret;
    }
    
    return HI_SUCCESS;
}


HI_S32 HIADP_Snd_RegAefAuthLib()
{
    HI_S32 Ret = HI_SUCCESS;

    Ret = HI_UNF_SND_RegisterAefAuthLib("libHA.AUDIO.SRS.effect.auth.so");

    if (Ret != HI_SUCCESS)
    {
        printf("\n\n!!! some audio effect authorize lib NOT found. you may NOT able to realize some audio effect process.\n\n");
    }
    
    return HI_SUCCESS;
}    

HI_S32 HIADP_AVPlay_RegADecLib()
{
    HI_S32 Ret = HI_SUCCESS;


    Ret = HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.AMRWB.codec.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.MP3.decode.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.MP2.decode.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.AAC.decode.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.DOLBYTRUEHD.decode.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.DRA.decode.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.TRUEHDPASSTHROUGH.decode.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.AMRNB.codec.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.COOK.decode.so");
#ifdef DOLBYPLUS_HACODEC_SUPPORT
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.DOLBYPLUS.decode.so");
#endif
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.DTSHD.decode.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.DTSHDXA.HW.decode.so");

    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.DTSM6.decode.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.DTSPASSTHROUGH.decode.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.AC3PASSTHROUGH.decode.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.PCM.HW.decode.so");
    Ret |= HI_UNF_AVPLAY_RegisterAcodecLib("libHA.AUDIO.PCM.decode.so");

    if (Ret != HI_SUCCESS)
    {
        printf("\n\n!!! some audio codec NOT found. you may NOT able to decode some audio type.\n\n");
    }
    
    return HI_SUCCESS;
}

HI_S32 HIADP_AVPlay_Init()
{
    HI_S32 Ret;
    Ret = HIADP_AVPlay_RegADecLib();
    Ret |= HI_UNF_AVPLAY_Init();
    return Ret;
}

HI_S32 HIADP_AVPlay_Create(HI_HANDLE *avplay,HI_U32 u32DemuxId,
    HI_UNF_AVPLAY_STREAM_TYPE_E streamtype,HI_UNF_VCODEC_CAP_LEVEL_E vdeccap, HI_U32 channelflag)
{
    HI_UNF_AVPLAY_ATTR_S attr;
    HI_HANDLE avhandle;
    HI_UNF_AVPLAY_OPEN_OPT_S maxCapbility;

    if(avplay == HI_NULL)
        return HI_FAILURE;
    
    if ((u32DemuxId != MPI_DEMUX_PLAY) && (u32DemuxId != MPI_DEMUX_PLAYBACK))
    {
        printf("%d is not a play demux , please select play demux \n", u32DemuxId);
        return HI_FAILURE;
    }

    if(streamtype >= HI_UNF_AVPLAY_STREAM_TYPE_BUTT)
        return HI_FAILURE;

    if(vdeccap >= HI_UNF_VCODEC_CAP_LEVEL_BUTT)
        return HI_FAILURE;

    HIAPI_RUN_RETURN(HI_UNF_AVPLAY_GetDefaultConfig(&attr, streamtype));

    attr.u32DemuxId = u32DemuxId;
    attr.stStreamAttr.u32VidBufSize = 0x300000;
    HIAPI_RUN_RETURN(HI_UNF_AVPLAY_Create(&attr, &avhandle));
    maxCapbility.enDecType = HI_UNF_VCODEC_DEC_TYPE_NORMAL;
    maxCapbility.enCapLevel = vdeccap;
    maxCapbility.enProtocolLevel = HI_UNF_VCODEC_PRTCL_LEVEL_H264;
        
    if(channelflag&HI_UNF_AVPLAY_MEDIA_CHAN_AUD)
        HIAPI_RUN_RETURN(HI_UNF_AVPLAY_ChnOpen(avhandle, HI_UNF_AVPLAY_MEDIA_CHAN_AUD, NULL));

    if(channelflag&HI_UNF_AVPLAY_MEDIA_CHAN_VID)
        HIAPI_RUN_RETURN(HI_UNF_AVPLAY_ChnOpen(avhandle, HI_UNF_AVPLAY_MEDIA_CHAN_VID, &maxCapbility));

    *avplay = avhandle;

    printf("demux %d create avplay 0x%x  \n", u32DemuxId, avhandle);

    return HI_SUCCESS;
}

HI_S32 HIADP_AVPlay_SetVdecAttr(HI_HANDLE hAvplay,HI_UNF_VCODEC_TYPE_E enType,HI_UNF_VCODEC_MODE_E enMode)
{
    HI_S32 Ret;
    HI_UNF_VCODEC_ATTR_S        VdecAttr;
    
    Ret = HI_UNF_AVPLAY_GetAttr(hAvplay, HI_UNF_AVPLAY_ATTR_ID_VDEC, &VdecAttr);
    if (HI_SUCCESS != Ret)
    {
        printf("HI_UNF_AVPLAY_GetAttr failed:%#x\n",Ret);        
        return Ret;
    }

    VdecAttr.enType = enType;
    VdecAttr.enMode = enMode;
    VdecAttr.u32ErrCover = 100;
    VdecAttr.u32Priority = 3;

    Ret = HI_UNF_AVPLAY_SetAttr(hAvplay, HI_UNF_AVPLAY_ATTR_ID_VDEC, &VdecAttr);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_AVPLAY_SetAttr failed.\n");
        return Ret;
    }

    return Ret;
}

#if defined (DOLBYPLUS_HACODEC_SUPPORT)

static HI_VOID DDPlusCallBack(DOLBYPLUS_EVENT_E Event, HI_VOID *pUserData)
{
    DOLBYPLUS_STREAM_INFO_S *pstInfo = (DOLBYPLUS_STREAM_INFO_S *)pUserData;
#if 0
    printf( "DDPlusCallBack show info:\n \
                s16StreamType          = %d\n \
                s16Acmod               = %d\n \
                s32BitRate             = %d\n \
                s32SampleRateRate      = %d\n \
                Event                  = %d\n", 
                pstInfo->s16StreamType, pstInfo->s16Acmod, pstInfo->s32BitRate, pstInfo->s32SampleRateRate,Event);
#endif                
    g_u32DolbyAcmod = pstInfo->s16Acmod;

    if (HA_DOLBYPLUS_EVENT_SOURCE_CHANGE == Event)
    {
        g_bDrawChnBar = HI_TRUE;
        //printf("DDPlusCallBack enent !\n");
    }
    return;
}

#endif
HI_S32 HIADP_AVPlay_SetAdecAttr(HI_HANDLE hAvplay, HI_U32 enADecType, HI_HA_DECODEMODE_E enMode, HI_S32 isCoreOnly)
{
    HI_UNF_ACODEC_ATTR_S AdecAttr;
    WAV_FORMAT_S stWavFormat;

    HIAPI_RUN_RETURN(HI_UNF_AVPLAY_GetAttr(hAvplay, HI_UNF_AVPLAY_ATTR_ID_ADEC, &AdecAttr));
    AdecAttr.enType = enADecType;

    if (HA_AUDIO_ID_PCM == AdecAttr.enType)
    {
        HI_BOOL isBigEndian;

        /* if big-endian pcm */
        isBigEndian = HI_FALSE;
        if(HI_TRUE == isBigEndian)
        {
            stWavFormat.cbSize = 4;
            stWavFormat.cbExtWord[0] = NORMAL_PCM_EXTWORD; //choose normal pcm decoder
            //stWavFormat.cbExtWord[0] = WIFIDSP_LPCM_EXTWORD; //choose wifi_dsp_lpcm decoder
        }
        
        if(stWavFormat.cbExtWord[0] == NORMAL_PCM_EXTWORD || HI_FALSE == isBigEndian)
        {
        /* 
            if choose normal pcm decoder, set attribute
            if choose wifi_dsp_lpcm decoder, need not to set attribute by follows, ignore it
        */
        /* set pcm wav format here base on pcm file */
            stWavFormat.nChannels = 2;
            stWavFormat.nSamplesPerSec = 48000;
            stWavFormat.wBitsPerSample = 16;
        }
        HA_PCM_DecGetDefalutOpenParam(&(AdecAttr.stDecodeParam),&stWavFormat);
        printf("please make sure the attributes of PCM stream is tme same as defined in function of \"HIADP_AVPlay_SetAdecAttr\"? \n");
        printf("(nChannels = 1, wBitsPerSample = 16, nSamplesPerSec = 48000, isBigEndian = HI_FALSE) \n");
    }
#if 0    
    else if (HA_AUDIO_ID_G711 == AdecAttr.enType)
    {
         HA_G711_GetDecDefalutOpenParam(&(AdecAttr.stDecodeParam));
    }
#endif    
    else if (HA_AUDIO_ID_MP2 == AdecAttr.enType)
    {
         HA_MP2_DecGetDefalutOpenParam(&(AdecAttr.stDecodeParam));
    }
    else if (HA_AUDIO_ID_AAC == AdecAttr.enType)
    {
         HA_AAC_DecGetDefalutOpenParam(&(AdecAttr.stDecodeParam));
    }
    else if (HA_AUDIO_ID_MP3 == AdecAttr.enType)
    {
         HA_MP3_DecGetDefalutOpenParam(&(AdecAttr.stDecodeParam));
    }
    else if (HA_AUDIO_ID_AMRNB== AdecAttr.enType)
    {
        AMRNB_DECODE_OPENCONFIG_S *pstConfig = (AMRNB_DECODE_OPENCONFIG_S *)u8DecOpenBuf;        
        HA_AMRNB_GetDecDefalutOpenParam(&(AdecAttr.stDecodeParam), pstConfig);
        pstConfig->enFormat = AMRNB_MIME;       
    }
    else if (HA_AUDIO_ID_AMRWB== AdecAttr.enType)
    {
        AMRWB_DECODE_OPENCONFIG_S *pstConfig = (AMRWB_DECODE_OPENCONFIG_S *)u8DecOpenBuf;
        HA_AMRWB_GetDecDefalutOpenParam(&(AdecAttr.stDecodeParam), pstConfig);
        pstConfig->enFormat = AMRWB_FORMAT_MIME;
    }
    else if (HA_AUDIO_ID_AC3PASSTHROUGH== AdecAttr.enType)
    {
        HA_AC3PASSTHROUGH_DecGetDefalutOpenParam(&(AdecAttr.stDecodeParam));
        AdecAttr.stDecodeParam.enDecMode = HD_DEC_MODE_THRU;
    }
    else if(HA_AUDIO_ID_DTSPASSTHROUGH ==  AdecAttr.enType)
    {
                HA_DTSPASSTHROUGH_DecGetDefalutOpenParam(&(AdecAttr.stDecodeParam));
             AdecAttr.stDecodeParam.enDecMode = HD_DEC_MODE_THRU;
    }
    else if (HA_AUDIO_ID_TRUEHD == AdecAttr.enType)
    {
        HA_TRUEHD_DecGetDefalutOpenParam(&(AdecAttr.stDecodeParam));
        if (HD_DEC_MODE_THRU != enMode)
        {
            printf(" MLP decoder enMode(%d) error (mlp only support hbr Pass-through only).\n", enMode);
            return -1;
        }

        AdecAttr.stDecodeParam.enDecMode = HD_DEC_MODE_THRU;        /* truehd just support pass-through */
        printf(" TrueHD decoder(HBR Pass-through only).\n");
    }
    else if (HA_AUDIO_ID_DOLBY_TRUEHD == AdecAttr.enType)
    {
        TRUEHD_DECODE_OPENCONFIG_S *pstConfig = (TRUEHD_DECODE_OPENCONFIG_S *)u8DecOpenBuf;        
        HA_DOLBY_TRUEHD_DecGetDefalutOpenConfig(pstConfig);
        HA_DOLBY_TRUEHD_DecGetDefalutOpenParam(&(AdecAttr.stDecodeParam), pstConfig);
    }
    else if (HA_AUDIO_ID_DTSHD == AdecAttr.enType)
    {
        DTSHD_DECODE_OPENCONFIG_S *pstConfig = (DTSHD_DECODE_OPENCONFIG_S *)u8DecOpenBuf;        
        HA_DTSHD_DecGetDefalutOpenConfig(pstConfig);
        HA_DTSHD_DecGetDefalutOpenParam(&(AdecAttr.stDecodeParam), pstConfig);
        AdecAttr.stDecodeParam.enDecMode = HD_DEC_MODE_SIMUL;
    }
    else if (HA_AUDIO_ID_DTSM6 == AdecAttr.enType)
    {
        DTSM6_DECODE_OPENCONFIG_S *pstConfig = (DTSM6_DECODE_OPENCONFIG_S *)u8DecOpenBuf;        
        HA_DTSM6_DecGetDefalutOpenConfig(pstConfig);
        HA_DTSM6_DecGetDefalutOpenParam(&(AdecAttr.stDecodeParam), pstConfig);
    }
#if defined (DOLBYPLUS_HACODEC_SUPPORT)
    else if (HA_AUDIO_ID_DOLBY_PLUS == AdecAttr.enType)
    {
        DOLBYPLUS_DECODE_OPENCONFIG_S *pstConfig = (DOLBYPLUS_DECODE_OPENCONFIG_S *)u8DecOpenBuf;
        HA_DOLBYPLUS_DecGetDefalutOpenConfig(pstConfig);
        pstConfig->pfnEvtCbFunc[HA_DOLBYPLUS_EVENT_SOURCE_CHANGE] = DDPlusCallBack;
        pstConfig->pAppData[HA_DOLBYPLUS_EVENT_SOURCE_CHANGE] = &g_stDDpStreamInfo;
        /* Dolby DVB Broadcast default settings */
        pstConfig->enDrcMode = DOLBYPLUS_DRC_RF; 
        pstConfig->enDmxMode = DOLBYPLUS_DMX_SRND; 
        HA_DOLBYPLUS_DecGetDefalutOpenParam(&(AdecAttr.stDecodeParam), pstConfig);
        AdecAttr.stDecodeParam.enDecMode = HD_DEC_MODE_SIMUL;
    }
#endif
    else
    {
//       HA_DRA_DecGetDefalutOpenParam(&(AdecAttr.stDecodeParam));
         HA_DRA_DecGetOpenParam_MultichPcm(&(AdecAttr.stDecodeParam));
    }

    HIAPI_RUN_RETURN(HI_UNF_AVPLAY_SetAttr(hAvplay, HI_UNF_AVPLAY_ATTR_ID_ADEC, &AdecAttr));

    return HI_SUCCESS;
}

HI_S32 HIADP_AENC_GetAttr(HI_UNF_AENC_ATTR_S *pAencAttr, HI_VOID *pstConfig)
{   
    if(NULL == pAencAttr || NULL == pstConfig)
    {
        return HI_ERR_AENC_NULL_PTR;
    }

    if (HA_AUDIO_ID_AAC == pAencAttr->enAencType)
    {       
        HA_AAC_GetEncDefaultOpenParam(&(pAencAttr->sOpenParam), pstConfig);
        printf("u32DesiredSampleRate =%d\n", pAencAttr->sOpenParam.u32DesiredSampleRate);
    }
    else
    {
        return HI_FAILURE;
    }
        
    return HI_SUCCESS;

}


HI_S32 HIADP_AVPlay_PlayProg(HI_HANDLE hAvplay,PMT_COMPACT_TBL *pProgTbl,HI_U32 ProgNum,HI_BOOL bAudPlay)
{
    HI_UNF_AVPLAY_STOP_OPT_S    Stop;
    HI_U32                  VidPid;
    HI_U32                  AudPid;
    HI_U32                  PcrPid;
    HI_UNF_VCODEC_TYPE_E    enVidType;
    HI_U32                  u32AudType;
    HI_S32                  Ret;

    Stop.enMode = HI_UNF_AVPLAY_STOP_MODE_BLACK;
    Stop.u32TimeoutMs = 0;
    Ret = HI_UNF_AVPLAY_Stop(hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_VID | HI_UNF_AVPLAY_MEDIA_CHAN_AUD, &Stop);
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_AVPLAY_Stop failed.\n");
        return Ret;
    }

    ProgNum = ProgNum % pProgTbl->prog_num;
    if (pProgTbl->proginfo[ProgNum].VElementNum > 0 )
    {
        VidPid = pProgTbl->proginfo[ProgNum].VElementPid;
        enVidType = pProgTbl->proginfo[ProgNum].VideoType;
    }
    else
    {
        VidPid = INVALID_TSPID;
        enVidType = HI_UNF_VCODEC_TYPE_BUTT;
    }

    if (pProgTbl->proginfo[ProgNum].AElementNum > 0)
    {
        AudPid  = pProgTbl->proginfo[ProgNum].AElementPid;
        u32AudType = pProgTbl->proginfo[ProgNum].AudioType;
    }
    else
    {
        AudPid = INVALID_TSPID;
        u32AudType = 0xffffffff;
    }
    
    PcrPid = pProgTbl->proginfo[ProgNum].PcrPid;
    if (INVALID_TSPID != PcrPid)
    {
        Ret = HI_UNF_AVPLAY_SetAttr(hAvplay,HI_UNF_AVPLAY_ATTR_ID_PCR_PID,&PcrPid);
        if (HI_SUCCESS != Ret)
        {
            printf("call HI_UNF_AVPLAY_SetAttr failed.\n");

            PcrPid = INVALID_TSPID;
            Ret = HI_UNF_AVPLAY_SetAttr(hAvplay,HI_UNF_AVPLAY_ATTR_ID_PCR_PID,&PcrPid);
            if (HI_SUCCESS != Ret)
            {
                printf("call HI_UNF_AVPLAY_SetAttr failed.\n");
                return Ret;
            }
        }
    }

    if (VidPid != INVALID_TSPID)
    {
        Ret = HIADP_AVPlay_SetVdecAttr(hAvplay,enVidType,HI_UNF_VCODEC_MODE_NORMAL);
        Ret |= HI_UNF_AVPLAY_SetAttr(hAvplay, HI_UNF_AVPLAY_ATTR_ID_VID_PID,&VidPid);
        if (Ret != HI_SUCCESS)
        {
            printf("call HIADP_AVPlay_SetVdecAttr failed.\n");
            return Ret;
        }

        Ret = HI_UNF_AVPLAY_Start(hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_VID, HI_NULL);
        if (Ret != HI_SUCCESS)
        {
            printf("call HI_UNF_AVPLAY_Start failed.\n");
            return Ret;
        }
    }

    if (HI_TRUE == bAudPlay && AudPid != INVALID_TSPID)
    {
        //u32AudType = HA_AUDIO_ID_DTSHD;
        //printf("u32AudType = %#x\n",u32AudType);
        Ret  = HIADP_AVPlay_SetAdecAttr(hAvplay, u32AudType, HD_DEC_MODE_RAWPCM, 1);
        
        Ret |= HI_UNF_AVPLAY_SetAttr(hAvplay, HI_UNF_AVPLAY_ATTR_ID_AUD_PID, &AudPid);
        if (HI_SUCCESS != Ret)
        {
            printf("HIADP_AVPlay_SetAdecAttr failed:%#x\n",Ret);
            return Ret;
        }

        Ret = HI_UNF_AVPLAY_Start(hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_AUD, HI_NULL);
        if (Ret != HI_SUCCESS)
        {
            printf("call HI_UNF_AVPLAY_Start to start audio failed.\n");
            //return Ret;
        }
    }

    return HI_SUCCESS;
}

HI_S32 HIADP_AVPlay_PlayAud(HI_HANDLE hAvplay,PMT_COMPACT_TBL *pProgTbl,HI_U32 ProgNum)
{
    HI_U32                  AudPid;
    HI_U32                  u32AudType;
    HI_S32                  Ret;

    Ret = HI_UNF_AVPLAY_Stop(hAvplay,HI_UNF_AVPLAY_MEDIA_CHAN_AUD, HI_NULL);
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_AVPLAY_Stop failed.\n");
        return Ret;
    }

    ProgNum = ProgNum % pProgTbl->prog_num;
    if (pProgTbl->proginfo[ProgNum].AElementNum > 0)
    {
        AudPid  = pProgTbl->proginfo[ProgNum].AElementPid;
        u32AudType = pProgTbl->proginfo[ProgNum].AudioType;
    }
    else
    {
        AudPid = INVALID_TSPID;
        u32AudType = 0xffffffff;
    }
    
    if (AudPid != INVALID_TSPID)
    {
        Ret  = HIADP_AVPlay_SetAdecAttr(hAvplay, u32AudType, HD_DEC_MODE_RAWPCM, 1);
        Ret |= HI_UNF_AVPLAY_SetAttr(hAvplay, HI_UNF_AVPLAY_ATTR_ID_AUD_PID, &AudPid);
        if (HI_SUCCESS != Ret)
        {
            printf("HIADP_AVPlay_SetAdecAttr failed:%#x\n",Ret);
            return Ret;
        }

        Ret = HI_UNF_AVPLAY_Start(hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_AUD, HI_NULL);
        if (Ret != HI_SUCCESS)
        {
            printf("call HI_UNF_AVPLAY_Start failed.\n");
            return Ret;
        }
    }

    return HI_SUCCESS;
}

HI_S32 HIADP_AVPlay_SwitchAud(HI_HANDLE hAvplay,HI_U32 AudPid, HI_U32 u32AudType)
{
    HI_S32 Ret = HI_SUCCESS;

    if (AudPid == INVALID_TSPID)
    {
        printf("%s, audio pid is invalid!\n", __func__);
        return HI_FAILURE;
    }

    Ret = HI_UNF_AVPLAY_Stop(hAvplay,HI_UNF_AVPLAY_MEDIA_CHAN_AUD, HI_NULL);
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_AVPLAY_Stop failed.\n");
        return Ret;
    }


    Ret  = HIADP_AVPlay_SetAdecAttr(hAvplay, u32AudType, HD_DEC_MODE_RAWPCM, 1);
    Ret |= HI_UNF_AVPLAY_SetAttr(hAvplay, HI_UNF_AVPLAY_ATTR_ID_AUD_PID, &AudPid);
    if (HI_SUCCESS != Ret)
    {
        printf("HIADP_AVPlay_SetAdecAttr failed:%#x\n",Ret);
        return Ret;
    }

    Ret = HI_UNF_AVPLAY_Start(hAvplay, HI_UNF_AVPLAY_MEDIA_CHAN_AUD, HI_NULL);
    if (Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_AVPLAY_Start failed.\n");
        return Ret;
    }

    return HI_SUCCESS;
}


HI_S32 HIADP_MCE_Exit(HI_VOID)
{
#ifdef HI_MCE_SUPPORT
    HI_S32                  Ret;
    HI_UNF_MCE_STOPPARM_S   stStop;

    Ret = HI_UNF_MCE_Init(HI_NULL);
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_MCE_Init failed, Ret=%#x!\n", Ret);
        return Ret;
    }

    Ret = HI_UNF_MCE_ClearLogo();
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_MCE_ClearLogo failed, Ret=%#x!\n", Ret);
        return Ret;
    }

    stStop.enStopMode = HI_UNF_AVPLAY_STOP_MODE_STILL;
    stStop.enCtrlMode = HI_UNF_MCE_PLAYCTRL_BY_TIME;
    stStop.u32PlayTimeMs = 0;
    Ret = HI_UNF_MCE_Stop(&stStop);
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_MCE_Stop failed, Ret=%#x!\n", Ret);
        return Ret;
    }

    Ret = HI_UNF_MCE_Exit(HI_NULL);
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_MCE_Exit failed, Ret=%#x!\n", Ret);
        return Ret;
    }

    HI_UNF_MCE_DeInit();
#endif

    return HI_SUCCESS;
}    

HI_S32 HIADP_ConnectAtvSrc(HI_UNF_INPUT_SOURCE_TYPE_E enAtvSrc)
{
    HI_S32 s32Ret;
    HI_UNF_TVD_SRC_ATTR_S stSrcTvdAttr = {0};
    HI_UNF_HDDEC_SRC_ATTR_S stSrcHddecAttr = {0};

    printf("HIADP_ConnectAtvSrc Enter enAtvSrc =%d\n", enAtvSrc);
    if(HI_UNF_INPUT_SOURCE_CVBS == enAtvSrc)
    {
        s32Ret = HI_UNF_TVD_Init();
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_TVD_Init Failed \n");
        }
        
        stSrcTvdAttr.enType = HI_UNF_TVD_SRC_AV;
        stSrcTvdAttr.unMuxInfo.stCvbsMux.enCvbsMux = HI_UNF_INPUT_MUX_CVBS1;
        s32Ret = HI_UNF_TVD_Connect(&stSrcTvdAttr);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_TVD_Connect Failed \n");

            //return HI_FAILURE;
        }

        s32Ret = HIADP_AI_Init(HI_UNF_AI_ADC2, &s_hAi, &s_hTrackSlave, &s_hTrackVir);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HIADP_AI_Init Failed \n");

            return HI_FAILURE;
        }

    }
    else if(HI_UNF_INPUT_SOURCE_YPBPR == enAtvSrc)
    {

        s32Ret = HI_UNF_HDDEC_Init();
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDDEC_Init Failed \n");
        }
        
        stSrcHddecAttr.enSrcType = HI_UNF_HDDEC_SRC_YPBPR;
        stSrcHddecAttr.enRMux = HI_UNF_INPUT_MUX_PR0;
        stSrcHddecAttr.enGMux = HI_UNF_INPUT_MUX_Y0;
        stSrcHddecAttr.enBMux = HI_UNF_INPUT_MUX_PB0;
        stSrcHddecAttr.enSogMux = HI_UNF_INPUT_MUX_SOY0;
        s32Ret = HI_UNF_HDDEC_Connect(&stSrcHddecAttr);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDDEC_Connect YPBPR Failed \n");

           // return HI_FAILURE;
        }

        s32Ret = HIADP_AI_Init(HI_UNF_AI_ADC1, &s_hAi, &s_hTrackSlave, &s_hTrackVir);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HIADP_AI_Init Failed \n");

            return HI_FAILURE;
        }
    }
    else if(HI_UNF_INPUT_SOURCE_VGA == enAtvSrc)
    {
        s32Ret = HI_UNF_HDDEC_Init();
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDDEC_Init Failed \n");
        }
        
        stSrcHddecAttr.enSrcType = HI_UNF_HDDEC_SRC_VGA;
        stSrcHddecAttr.enRMux = HI_UNF_INPUT_MUX_R;
        stSrcHddecAttr.enGMux = HI_UNF_INPUT_MUX_G;
        stSrcHddecAttr.enBMux = HI_UNF_INPUT_MUX_B;
        stSrcHddecAttr.enSogMux = HI_UNF_INPUT_MUX_SOG;
        stSrcHddecAttr.enSyncMux = HI_UNF_INPUT_MUX_SYNC_HVS0;
        s32Ret = HI_UNF_HDDEC_Connect(&stSrcHddecAttr);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDDEC_Connect VGA Failed \n");

            return HI_FAILURE;
        }        

        s32Ret = HIADP_AI_Init(HI_UNF_AI_ADC1, &s_hAi, &s_hTrackSlave, &s_hTrackVir);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HIADP_AI_Init Failed \n");

            return HI_FAILURE;
        }
    }
#if 0    
    else if(HI_UNF_INPUT_SOURCE_HDMI == enAtvSrc)
    {
        printf("HI_UNF_INPUT_SOURCE_HDMI \n");
        s32Ret = HI_UNF_HDMIRX_Init();
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDMIRX_Init Failed \n");
        }
        #if 1
     
        HI_UNF_HDMIRX_EDID_S pstEdid = {{
    /*
    0x00,0xFF,0xFF,0xFF,    0xFF,0xFF,0xFF,0x00,    0x4D,0x79,0x01,0x00,    0x01,0x01,0x01,0x01,
    0x10,0x18,0x01,0x03,    0x81,0x00,0x00,0x78,    0x0A,0xEE,0x9D,0xA3,    0x54,0x4C,0x99,0x26,
    0x0F,0x47,0x4A,0xBF,    0xEF,0x00,0x01,0x01,    0x01,0x01,0x01,0x01,    0x01,0x01,0x01,0x01,
    0x01,0x01,0x01,0x01,    0x01,0x01,0x02,0x3A,    0x80,0x18,0x71,0x38,    0x2D,0x40,0x58,0x2C,
    0x45,0x00,0xC4,0x8E,    0x21,0x00,0x00,0x1E,    0x66,0x21,0x50,0xB0,    0x51,0x00,0x1B,0x30,
    0x40,0x70,0x36,0x00,    0xC4,0x8E,0x21,0x00,    0x00,0x1E,0x00,0x00,    0x00,0xFC,0x00,0x53,
    0x6B,0x79,0x77,0x6F,    0x72,0x74,0x68,0x20,    0x54,0x56,0x0A,0x20,    0x00,0x00,0x00,0xFD,
    0x00,0x30,0x4C,0x0F,    0x55,0x1E,0x00,0x0A,    0x20,0x20,0x20,0x20,    0x20,0x20,0x01,0x22,
    
    0x02,0x03,0x2F,0x74,    0x51,0x02,0x04,0x11,    0x13,0x20,0x22,0x90,    0x21,0x1F,0x06,0x15,
    0x03,0x07,0x12,0x16,    0x05,0x14,0x23,0x09,    0x07,0x07,0x83,0x01,    0x00,0x00,0x6F,0x03,
    0x0C,0x00,0x10,0x00,    0xB8,0x3C,0x20,0xA0,    0x62,0x01,0x02,0x03,    0x01,0x41,0x00,0x01,
    0x1D,0x00,0xBC,0x52,    0xD0,0x1E,0x20,0xB8,    0x28,0x55,0x40,0xC4,    0x8E,0x21,0x00,0x00,
    0x1E,0x01,0x1D,0x80,    0xD0,0x72,0x1C,0x16,    0x20,0x10,0x2C,0x25,    0x80,0xC4,0x8E,0x21,
    0x00,0x00,0x9E,0x8C,    0x0A,0xD0,0x8A,0x20,    0xE0,0x2D,0x10,0x10,    0x3E,0x96,0x00,0xC4,
    0x8E,0x21,0x00,0x00,    0x18,0x8C,0x0A,0xD0,    0x90,0x20,0x40,0x31,    0x20,0x0C,0x40,0x55,
    0x00,0xC4,0x8E,0x21,    0x00,0x00,0x18,0x00,    0x00,0x00,0x00,0x00,    0x00,0x00,0x00,0xE8 
    */ 
    0x00,	0xFF,	0xFF,	0xFF,	0xFF,	0xFF,	0xFF,	0x00,	0x21,	0x33,	0x30,	0x00,	0x01,	0x00,	0x00,	0x00,
    0x23,	0x14,	0x01,	0x03,	0x80,	0x73,	0x41,	0x78,	0x0A,	0xCF,	0x74,	0xA3,	0x57,	0x4C,	0xB0,	0x23,
    0x09,	0x48,	0x4C,	0x21,	0x08,	0x00,	0x81,	0xC0,	0x81,	0x40,	0x81,	0x80,	0x01,	0x01,	0x01,	0x01,
    0x01,	0x01,	0x01,	0x01,	0x01,	0x01,	0x02,	0x3A,	0x80,	0x18,	0x71,	0x38,	0x2D,	0x40,	0x58,	0x2C,
    0x45,	0x00,	0x80,	0x88,	0x42,	0x00,	0x00,	0x1E,	0x1B,	0x21,	0x50,	0xA0,	0x51,	0x00,	0x1E,	0x30,
    0x48,	0x88,	0x35,	0x00,	0x44,	0x4A,	0x21,	0x00,	0x00,	0x1C,	0x00,	0x00,	0x00,	0xFC,	0x00,	0x48,
    0x49,	0x53,	0x0A,	0x20,	0x20,	0x20,	0x20,	0x20,	0x20,	0x20,	0x20,	0x20,	0x00,	0x00,	0x00,	0xFD,
    0x00,	0x17,	0x55,	0x0F,	0x45,	0x1E,	0x00,	0x0A,	0x20,	0x20,	0x20,	0x20,	0x20,	0x20,	0x01,	0xFB,
    
    0x02,   0x03,   0x31,   0x74,   0x51,   0x02,   0x04,   0x11,   0x13,   0x20,   0x22,   0x90,   0x21,   0x1F,   0x06,   0x15,
    0x03,   0x07,   0x12,   0x16,   0x05,   0x14,   0x23,   0x09,   0x07,   0x07,   0x83,   0x01,   0x00,   0x00,   0x6F,   0x03,
    0x0C,   0x00,   0x10,   0x00,   0xB8,   0x3C,   0x20,   0xA0,   0x62,   0x01,   0x02,   0x03,   0x01,   0x41,   0xE2,   0x00,
    0x40,   0x01,   0x1D,   0x00,   0xBC,   0x52,   0xD0,   0x1E,   0x20,   0xB8,   0x28,   0x55,   0x40,   0xC4,   0x8E,   0x21,
    0x00,   0x00,   0x1E,   0x01,   0x1D,   0x80,   0xD0,   0x72,   0x1C,   0x16,   0x20,   0x10,   0x2C,   0x25,   0x80,   0xC4,
    0x8E,   0x21,   0x00,   0x00,   0x9E,   0x8C,   0x0A,   0xD0,   0x8A,   0x20,   0xE0,   0x2D,   0x10,   0x10,   0x3E,   0x96,
    0x00,   0xC4,   0x8E,   0x21,   0x00,   0x00,   0x18,   0x8C,   0x0A,   0xD0,   0x90,   0x20,   0x40,   0x31,   0x20,   0x0C,
    0x40,   0x55,   0x00,   0xC4,   0x8E,   0x21,   0x00,   0x00,   0x18,   0x00,   0x00,   0x00,   0x00,   0x00,   0x00,   0xC4,
    
},{0x10,0x20,0x30,0x40}};   
        s32Ret = HI_UNF_HDMIRX_UpdateEdid(&pstEdid);
        if (HI_SUCCESS != s32Ret)
        {
            printf("LoadEDID Failed \n");
        }
        else
        {
            printf("LoadEDID SUCCESS \n");
        }
        HI_UNF_HDMIRX_HDCP_S pstHdcp={{ 
        0x80, 0x00, 0x48, 0x49, 0xcf, 0x57, 0x5c, 0xc7, 0xfc, 0x7e, 0x07, 0x14, 0x58, 0x3d, 0x1e, 0xb6,
        0x02, 0xbe, 0x2e, 0xf5, 0xff, 0xe4, 0x2a, 0x30, 0x11, 0xcc, 0xe9, 0x0e, 0x33, 0xaa, 0x87, 0xa4,
        0x95, 0xc0, 0xf3, 0x9d, 0xce, 0xab, 0x10, 0x3a, 0x71, 0x7d, 0x2a, 0xa8, 0xf1, 0x13, 0x0a, 0xa4,
        0x6e, 0x5c, 0x6e, 0x38, 0xf2, 0xbb, 0x1e, 0xbe, 0xcd, 0x65, 0xca, 0x10, 0x7d, 0x0a, 0x8b, 0xdb,
        0x50, 0x49, 0x71, 0x38, 0xad, 0x7b, 0x7b, 0x19, 0x9a, 0xbc, 0x91, 0xdd, 0x0e, 0x11, 0xd5, 0x03,
        0x7b, 0x29, 0x09, 0x6d, 0x66, 0x79, 0x99, 0x8f, 0x2e, 0x62, 0xe2, 0x2f, 0x35, 0xcc, 0x84, 0x2d,
        0x1a, 0xcb, 0x42, 0x8f, 0x30, 0xc1, 0x59, 0x4d, 0x09, 0xb3, 0x53, 0x5c, 0xdd, 0xfd, 0xca, 0xf7,
        0x3a, 0x04, 0xeb, 0x5d, 0xbb, 0x73, 0x17, 0xee, 0xf8, 0x32, 0x90, 0xd9, 0x48, 0x25, 0x8a, 0x93,
        0x8e, 0x77, 0x28, 0xaf, 0x96, 0x80, 0x1f, 0x2e, 0x50, 0x87, 0x47, 0xaf, 0x11, 0x20, 0xb0, 0x9d,
        0x39, 0xea, 0x66, 0x83, 0x6a, 0xa7, 0x27, 0x09, 0xd8, 0x64, 0x20, 0x5c, 0xab, 0x10, 0x54, 0xbb,
        0x55, 0xb9, 0x4d, 0x9a, 0xac, 0x61, 0xb4, 0xc3, 0xcf, 0x1a, 0x12, 0xcd, 0xbe, 0x4a, 0x20, 0xa5,
        0x95, 0x31, 0x03, 0x06, 0x88, 0x54, 0x1b, 0x3d, 0xb9, 0x73, 0xb9, 0x22, 0x8c, 0x88, 0x6c, 0x36,
        0xec, 0xc3, 0xe2, 0x3e, 0xec, 0x03, 0xd4, 0xee, 0x6f, 0x08, 0x9b, 0x90, 0xee, 0xfc, 0xc6, 0xe8,
        0xd1, 0xca, 0x17, 0xa3, 0xc1, 0xf0, 0x39, 0x15, 0x94, 0xe9, 0xa9, 0x94, 0x34, 0x84, 0x76, 0xcd,
        0x72, 0xdd, 0x48, 0x34, 0xec, 0x87, 0xde, 0x84, 0xa5, 0xfd, 0x75, 0x47, 0x0b, 0xde, 0xef, 0x23,
        0x7d, 0x97, 0x88, 0x88, 0x76, 0x74, 0xb9, 0x65, 0xc7, 0x32, 0x08, 0x3b, 0xcc, 0x04, 0xee, 0x8c,
        0xa7, 0xfa, 0x6e, 0x35, 0x2d, 0xef, 0xb8, 0xfc, 0x11, 0x8e, 0x96, 0x29, 0x4c, 0x40, 0x18, 0xaa,
        0x76, 0x45, 0x27, 0x7d, 0xf4, 0xf2, 0x06, 0x55, 0xe4, 0x7c, 0x89, 0x2d, 0x29, 0x70, 0x7e, 0x00,
        0x40, 0xce, 0x40, 0x5f, 0x66, 0xf2, 0x7e, 0xfc, 0x53, 0x0e, 0x4d, 0x59, 0x59, 0x6e, 0x64, 0x55,
        0x2e, 0x33, 0x0c, 0x6c, 0x45, 0x14, 0xc7, 0xf3, 0x57, 0xc8, 0x29, 0x91, 0xc7, 0x75, 0xbb, 0x28,
        0xa3, 0x7e, 0x70, 0x08, 0xe0, 0x7f, 0x53, 0x0a, 0x7e, 0xe0, 0x73, 0xa4
        }};
        
        s32Ret = HI_UNF_HDMIRX_LoadHdcp(&pstHdcp);
        if (HI_SUCCESS != s32Ret)
        {
            printf("LoadHdcp Failed \n");
        }
           
        s32Ret = HI_UNF_HDMIRX_Connect(0);
         if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDMIRX_Connect HDMIRX Failed \n");

            return HI_FAILURE;
        }
        
		
        #endif

        s32Ret = HIADP_AI_Init(HI_UNF_AI_HDMI0, &s_hAi, &s_hTrackSlave, &s_hTrackVir);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HIADP_AI_Init Failed \n");

            //return HI_FAILURE;
        }
    }
#endif    
    else
    {
        printf(" Not Support enAtvSrc=%d  Now \n", enAtvSrc);
        return HI_FAILURE;
    }
    
    return HI_SUCCESS;
}



HI_S32 HIADP_DisConnectAtvSrc(HI_UNF_INPUT_SOURCE_TYPE_E enAtvSrc)
{
    HI_S32 s32Ret;

    printf("HIADP_DisConnectAtvSrc Enter enAtvSrc =%d\n", enAtvSrc);
    if(HI_UNF_INPUT_SOURCE_CVBS == enAtvSrc)
    {
        s32Ret = HI_UNF_TVD_DisConnect();
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_TVD_DisConnect Failed \n");

            return HI_FAILURE;
        }
        s32Ret = HI_UNF_TVD_DeInit();
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_TVD_DeInit Failed \n");

            return HI_FAILURE;
        }

    }
    else if(HI_UNF_INPUT_SOURCE_YPBPR == enAtvSrc)
    {
        s32Ret = HI_UNF_HDDEC_DisConnect();
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDDEC_DisConnect Failed \n");

            return HI_FAILURE;
        }

        s32Ret = HI_UNF_HDDEC_DeInit();
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDDEC_DeInit Failed \n");

            return HI_FAILURE;
        }
    }
    else if(HI_UNF_INPUT_SOURCE_VGA == enAtvSrc)
    {
        s32Ret = HI_UNF_HDDEC_DisConnect();
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDDEC_DisConnect Failed \n");

            return HI_FAILURE;
        }
        s32Ret = HI_UNF_HDDEC_DeInit();
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDDEC_DeInit Failed \n");

            return HI_FAILURE;
        }
    }
    else if(HI_UNF_INPUT_SOURCE_HDMI == enAtvSrc)
    {
        s32Ret = HI_UNF_HDMIRX_DisConnect();
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDDEC_DisConnect Failed \n");

            return HI_FAILURE;
        }
    }
    else
    {
        printf(" Not Support enAtvSrc=%d  Now \n", enAtvSrc);
        return HI_FAILURE;
    }

    HIADP_AI_DeInit(s_hAi, s_hTrackSlave, s_hTrackVir);
    return HI_SUCCESS;
}



HI_S32 HIADP_StartVo(HI_HANDLE *ps_hWindow)
{
    HI_S32                  s32Ret;
    HI_UNF_DISP_E           enDisp = HI_UNF_DISPLAY1;
    HI_UNF_DISP_INTF_S      stIntf;
    HI_U32                  u32PanelIndex = 0;
    HI_UNF_WINDOW_ATTR_S    stWinAttr;

    printf("call HIADP_VDP_Init Enter");
    
    s32Ret = HI_UNF_DISP_Init();
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_DISP_Init Failed \n");
    }

    s32Ret = HI_UNF_PANEL_Init();
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_PANEL_Init Failed \n");
    }

    //s32Ret = HI_UNF_PANEL_SetPowerOn(HI_FALSE);
    //if (HI_SUCCESS != s32Ret)
    //{
    //    printf("call HI_UNF_PANEL_SetPowerOn Failed \n");
    //}
#if 1 
    s32Ret = HI_UNF_PANEL_SetIndex(u32PanelIndex);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_PANEL_SetIndex Failed \n");
    }
#endif

    //s32Ret = HI_UNF_PANEL_SetPowerOn(HI_TRUE);
    //if (HI_SUCCESS != s32Ret)
    //{
     //   printf("call HI_UNF_PANEL_SetPowerOn Failed \n");
    //}

    s32Ret = HI_UNF_DISP_SetVirtualScreen(enDisp, 1920, 1080);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_DISP_SetVirtualScreen Failed \n");
    }

    stIntf.enIntfType = HI_UNF_DISP_INTF_TYPE_PANEL;
    stIntf.unIntf.enPanel = HI_UNF_DISP_PANEL_0;
    s32Ret = HI_UNF_DISP_AttachIntf(enDisp, &stIntf, 1);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_DISP_AttachIntf Failed \n");
    }

    s32Ret = HI_UNF_DISP_Open(enDisp);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_DISP_Open Failed \n");
    }

    s32Ret = HI_UNF_VO_Init(HI_UNF_VO_DEV_MODE_NORMAL);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VO_Init Failed \n");
    }
    s32Ret = HI_UNF_PQ_Init(NULL);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_PQ_Init Failed \n");
    }
    s32Ret = HI_UNF_MDBG_Init();
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_MDBG_Init Failed \n");
    }

    stWinAttr.enDisp = enDisp;
    stWinAttr.enPriority = HI_UNF_VO_WIN_PRIORITY_MAIN;
    stWinAttr.bVirtual = HI_FALSE;
    stWinAttr.stWinAspectAttr.enAspectCvrs = HI_UNF_VO_ASPECT_CVRS_CUSTOM;
    stWinAttr.bUseCropRect = HI_TRUE;
    stWinAttr.stCropRect.u32BottomOffset = 0;
    stWinAttr.stCropRect.u32LeftOffset = 0;
    stWinAttr.stCropRect.u32RightOffset = 0;
    stWinAttr.stCropRect.u32TopOffset = 0;

    stWinAttr.stOutputRect.s32X = 0;
    stWinAttr.stOutputRect.s32Y = 0;
    stWinAttr.stOutputRect.s32Width  = 1920;
    stWinAttr.stOutputRect.s32Height = 1080;

    stWinAttr.stWinAspectAttr.stVideoRect.s32X = 0;
    stWinAttr.stWinAspectAttr.stVideoRect.s32Y = 0;
    stWinAttr.stWinAspectAttr.stVideoRect.s32Width  = 1920;
    stWinAttr.stWinAspectAttr.stVideoRect.s32Height = 1080;

    stWinAttr.stWinAspectAttr.stNonLinearInfo.bEnable = HI_FALSE;
    
    s32Ret = HI_UNF_VO_CreateWindow(&stWinAttr, ps_hWindow);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VO_CreateWindow Failed \n");
    }
    
    s_hWindow = *ps_hWindow;

    if(HIADP_GetMonitorOutEn())
    {
/**************************monitor out**************************************/
#if 1
        memset(&stIntf, 0, sizeof(HI_UNF_DISP_INTF_S));
        stIntf.enIntfType = HI_UNF_DISP_INTF_TYPE_AVOUT;
        stIntf.unIntf.stAvout.u8Dac = 0;//Video Out2
        stIntf.unIntf.stAvout.enAvoutSrc = HI_UNF_AVOUT_SOURC_CVBS;
        s32Ret = HI_UNF_DISP_AttachIntf(HI_UNF_DISPLAY0, &stIntf, 1);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_DISP_AttachIntf Failed \n");
        }
        
        s32Ret = HI_UNF_DISP_SetFormat(HI_UNF_DISPLAY0,HI_UNF_ENC_FMT_NTSC );
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_DISP_SetFormat failed, Ret=%#x.\n", s32Ret);
        }

        s32Ret = HI_UNF_DISP_Open(HI_UNF_DISPLAY0);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_DISP_Open Failed \n");
        }

    
        memset(&stWinAttr, 0, sizeof(HI_UNF_WINDOW_ATTR_S));
        stWinAttr.enDisp = HI_UNF_DISPLAY0;
        stWinAttr.enPriority = HI_UNF_VO_WIN_PRIORITY_MAIN;
        stWinAttr.bVirtual = HI_FALSE;
        stWinAttr.stWinAspectAttr.enAspectCvrs = HI_UNF_VO_ASPECT_CVRS_CUSTOM;
        stWinAttr.stWinAspectAttr.bUserDefAspectRatio = HI_FALSE;
        stWinAttr.stWinAspectAttr.u32UserAspectWidth  = 0;
        stWinAttr.stWinAspectAttr.u32UserAspectHeight = 0;
        stWinAttr.bUseCropRect = HI_FALSE;
        stWinAttr.stInputRect.s32X = 0;
        stWinAttr.stInputRect.s32Y = 0;
        stWinAttr.stInputRect.s32Width = 0;
        stWinAttr.stInputRect.s32Height = 0;
        memset(&stWinAttr.stOutputRect, 0x0, sizeof(HI_RECT_S));

        s32Ret = HI_UNF_VO_CreateWindow(&stWinAttr, &s_hWindow0);
        if (s32Ret != HI_SUCCESS)
        {
            printf("call HI_UNF_VO_CreateWindow0 failed.\n");
            return s32Ret;
        }
#endif        
/************************bypass out***************************************/ 
#if 0
        memset(&stIntf, 0, sizeof(HI_UNF_DISP_INTF_S));
        stIntf.enIntfType = HI_UNF_DISP_INTF_TYPE_AVOUT;
        stIntf.unIntf.stAvout.u8Dac = 0;//Video Out1
        stIntf.unIntf.stAvout.enAvoutSrc = HI_UNF_AVOUT_SOURC_CVBS;
        s32Ret = HI_UNF_DISP_AttachIntf(HI_UNF_DISPLAY2, &stIntf, 1);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_DISP_AttachIntf Failed \n");
        }

        s32Ret = HI_UNF_DISP_Open(HI_UNF_DISPLAY2);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_DISP_Open Failed \n");
        }
#endif		
    }

/*********************************************************************/    
    sem_init(&bin_sem, 0, 1);
    if(s32Ret != HI_SUCCESS)
    {
        printf("sem_init Failed \n");
    }
    return s32Ret;
}


HI_S32 HIADP_StopVo(HI_HANDLE s_hWindow)
{
    HI_S32 s32Ret;
    HI_UNF_DISP_E enDisp = HI_UNF_DISPLAY1;
    HI_UNF_DISP_INTF_S stIntf;

    printf("call HIADP_VDP_DeInit Enter");
    
    s_bMonitorEn = HI_FALSE;
    pthread_join(s_stMonitorThrd, NULL);

    stIntf.enIntfType = HI_UNF_DISP_INTF_TYPE_PANEL;
    stIntf.unIntf.enPanel = HI_UNF_DISP_PANEL_0;
    s32Ret = HI_UNF_DISP_DetachIntf(enDisp, &stIntf, 1);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_DISP_DetachIntf Failed \n");
    }

    s32Ret = HI_UNF_VO_DestroyWindow(s_hWindow);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VO_DestroyWindow Failed \n");
    }

    s32Ret = HI_UNF_VO_DeInit();
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VO_DeInit Failed \n");
    }
    
    s32Ret = HI_UNF_DISP_Close(enDisp);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_DISP_Close Failed \n");
    }

    s32Ret = HI_UNF_DISP_DeInit();
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_DISP_DeInit Failed \n");
    }

    s32Ret = HI_UNF_PANEL_DeInit();
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_PANEL_Init Failed \n");
    }

    s32Ret = HI_UNF_PQ_DeInit();
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_PQ_DeInit Failed \n");
    }
    s32Ret = HI_UNF_MDBG_DeInit();
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_MDBG_DeInit Failed \n");
    }
    return s32Ret;
}


HI_S32 HIADP_StartPlay(HI_HANDLE hWindow, HI_HANDLE hVi)
{
    HI_S32 s32Ret;
    HI_U32 u32VideoDelay;
    HI_UNF_AI_DELAY_S stDelayCompensation;

    printf("call HIADP_StartPlay Enter \n");

    s32Ret = HI_UNF_VO_AttachWindow(hWindow, hVi);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VO_AttachWindow Failed \n");
    }
    
    s32Ret = HI_UNF_VO_QueryVideoDelay(hWindow, &u32VideoDelay);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VO_QueryVideoDelay Failed \n");
    }
    
    if(HIADP_GetMonitorOutEn())
    {
        s32Ret = HI_UNF_VO_AttachWindow(s_hWindow0, hVi);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_VO_AttachWindow Failed \n");
        }
        
        s32Ret = HI_UNF_VO_QueryVideoDelay(s_hWindow0, &u32VideoDelay);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_VO_QueryVideoDelay Failed \n");
        }
    }

    
    printf("u32VideoDelay = %d\n", u32VideoDelay);


    stDelayCompensation.bDelayMsAutoHold = HI_FALSE;
    stDelayCompensation.u32DelayMs = u32VideoDelay;
    
    s32Ret = HI_UNF_AI_SetEnable(s_hAi, HI_FALSE);
    if (s32Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_AI_SetEnable failed.\n");
    }

    s32Ret = HI_UNF_AI_SetDelay(s_hAi, &stDelayCompensation);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_AI_SetDelayCompensation Failed \n");
    }

    s32Ret = HI_UNF_AI_SetEnable(s_hAi, HI_TRUE);
    if (s32Ret != HI_SUCCESS)
    {
        printf("call HI_UNF_AI_SetEnable failed.\n");
    }
    
    s32Ret = HI_UNF_VI_Start(hVi);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VI_Start Failed \n");
    }
    
    s32Ret = HI_UNF_VO_SetWindowEnable(hWindow, HI_TRUE);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VO_SetWindowEnable Failed \n");
    }
    
    s32Ret = HI_UNF_VO_FreezeWindow(hWindow, HI_FALSE, HI_UNF_WINDOW_FREEZE_MODE_BLACK);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VO_FreezeWindow Failed \n");
    }

    if(HIADP_GetMonitorOutEn())
    {
        s32Ret = HI_UNF_VO_SetWindowEnable(s_hWindow0, HI_TRUE);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_VO_SetWindowEnable Failed \n");
        }
        
        s32Ret = HI_UNF_VO_FreezeWindow(s_hWindow0, HI_FALSE, HI_UNF_WINDOW_FREEZE_MODE_BLACK);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_VO_FreezeWindow Failed \n");
        }
    }

    
    s_bStopPlay = HI_FALSE;
    
    return s32Ret;
}


HI_S32 HIADP_StopPlay(HI_HANDLE hWindow, HI_HANDLE hVi)
{
    HI_S32 s32Ret;

    
    printf("call HIADP_Play_Stop Enter \n");
    
    //sem_wait(&bin_sem);
    if(s_bStopPlay)
    {
        //sem_post(&bin_sem);
        return HI_SUCCESS;
    }
    
    s32Ret = HI_UNF_VO_FreezeWindow(hWindow, HI_TRUE, HI_UNF_WINDOW_FREEZE_MODE_BLACK);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VO_FreezeWindow Failed \n");
    }
    if(HIADP_GetMonitorOutEn())
    {
        s32Ret = HI_UNF_VO_FreezeWindow(s_hWindow0, HI_TRUE, HI_UNF_WINDOW_FREEZE_MODE_BLACK);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_VO_FreezeWindow Failed \n");
        }
    }
    s32Ret = HI_UNF_VI_Stop(hVi);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VI_Stop Failed \n");
    }

    s32Ret = HI_UNF_VO_SetWindowEnable(hWindow, HI_FALSE);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VO_SetWindowEnable Failed \n");
    }

    s32Ret = HI_UNF_VO_DetachWindow(hWindow, hVi);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VO_DetachWindow Failed \n");
    }
    if(HIADP_GetMonitorOutEn())
    {
        s32Ret = HI_UNF_VO_SetWindowEnable(s_hWindow0, HI_FALSE);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_VO_SetWindowEnable Failed \n");
        }

        s32Ret = HI_UNF_VO_DetachWindow(s_hWindow0, hVi);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_VO_DetachWindow Failed \n");
        }
    }
    s32Ret = HI_UNF_VI_Destroy(hVi);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VI_Destroy Failed \n");
    }
    
    s_hVi = 0;
    s_bStopPlay = HI_TRUE;
    //sem_post(&bin_sem);
    
    return s32Ret;
}


HI_S32 HIADP_InitVi()
{
    HI_S32  s32Ret;
    
    s32Ret = HI_UNF_VI_Init();
    
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VI_Init Failed \n");
    }
    
    return s32Ret;
}

HI_S32 HIADP_DeInitVi()
{
    HI_S32  s32Ret;
    
    s32Ret = HI_UNF_VI_DeInit();
    
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VI_DeInit Failed \n");
    }
    
    return s32Ret;
}

HI_S32 HIADP_GetViHandle(HI_HANDLE *pViHandle)
{
    *pViHandle = s_hVi;

    return HI_SUCCESS;    
}

HI_S32 HIADP_GetWinHandle(HI_HANDLE *pWinHandle)
{
    *pWinHandle = s_hWindow;

    return HI_SUCCESS;    
}


HI_S32 HIADP_GetPlayReady(HI_BOOL *bPlay)
{
    *bPlay = !s_bStopPlay;

    return HI_SUCCESS;    
}


HI_S32 HIADP_AtvGetSigStatus(HI_UNF_INPUT_SOURCE_TYPE_E enAtvSrc, HI_UNF_SIG_STATUS_E *penSignalStatusPre)
{
    HI_S32 s32Ret;

    if(s_bSourceChange)
    {
        *penSignalStatusPre = HI_UNF_SIG_NO_SIGNAL;
        
        return HI_SUCCESS;
    }

    if ((HI_UNF_INPUT_SOURCE_ATV == enAtvSrc) || (HI_UNF_INPUT_SOURCE_CVBS == enAtvSrc))
    {
        s32Ret = HI_UNF_TVD_GetSigStatus(penSignalStatusPre);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call ATV HI_UNF_TVD_GetSigStatus Failed \n");
        }
    }
    else if((HI_UNF_INPUT_SOURCE_VGA == enAtvSrc) || (HI_UNF_INPUT_SOURCE_YPBPR == enAtvSrc))
    {
        s32Ret = HI_UNF_HDDEC_GetSigStatus(penSignalStatusPre);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call ATV HI_UNF_HDDEC_GetSigStatus Failed \n");
        }
    }
    else if(HI_UNF_INPUT_SOURCE_HDMI == enAtvSrc) 
    {
        s32Ret = HI_UNF_HDMIRX_GetSignalStatus(penSignalStatusPre);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call ATV HI_UNF_HDMIRX_GetSignalStatus Failed \n");
        }
    }
    
    return HI_SUCCESS;
}


HI_S32 HIADP_UpdateNstdInfo(HI_UNF_INPUT_SOURCE_TYPE_E  enAtvSrc, 
    HI_UNF_VIDEO_NONSTD_INFO_S  *pstCurrentNstdInfo, HI_UNF_VIDEO_NONSTD_INFO_S  *pstPreNstdInfo)
{
    HI_S32 s32Ret;

    if ((HI_UNF_INPUT_SOURCE_ATV == enAtvSrc) || (HI_UNF_INPUT_SOURCE_CVBS == enAtvSrc))
    {
        s32Ret = HI_UNF_TVD_GetNstdInfo(pstCurrentNstdInfo);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call GetNstdInfo Failed \n");
            return HI_FAILURE;
        }
    }
    else if(HI_UNF_INPUT_SOURCE_YPBPR == enAtvSrc)
    {
        s32Ret = HI_UNF_HDDEC_GetNonStdInfo(pstCurrentNstdInfo);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call GetNstdInfo Failed \n");
            return HI_FAILURE;
        }
    }
    else
    {
        printf("Current AtvSrc =%d Not Support GetNstdInfo \n", enAtvSrc);
        
        return HI_FAILURE;
    }
        
    if(memcmp(pstPreNstdInfo, pstCurrentNstdInfo, sizeof(HI_UNF_VIDEO_NONSTD_INFO_S)) != 0)
    {
        s32Ret = HI_UNF_VI_UpdateNstdInfo(s_hVi, pstCurrentNstdInfo);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_MPI_VI_UpdateNstdInfo Failed \n");
        }
        
        memcpy(pstPreNstdInfo, pstCurrentNstdInfo, sizeof(HI_UNF_VIDEO_NONSTD_INFO_S));
    }

    
    return HI_SUCCESS;
}


HI_S32 HIADP_AtvGetTimingInfo(HI_UNF_INPUT_SOURCE_TYPE_E enAtvSrc, HI_ADP_TIMING_INFO_S *pstTimingInfo)
{
    
    HI_S32                      s32Ret;
    HI_UNF_TVD_TIMING_INFO_S    stTvdTimingInfo;
    HI_UNF_HDDEC_TIMING_INFO_S  stHddecTimingInfo;
    HI_UNF_HDMIRX_TIMING_INFO_S stHdmirxTimingInfo;

    pstTimingInfo->enColorSys       = HI_UNF_COLOR_SYS_AUTO;
    pstTimingInfo->u32TimingIndex   = 0;
    pstTimingInfo->enSourceType     = enAtvSrc;
    
    pstTimingInfo->enColorSpace     = HI_UNF_COLOR_SPACE_BT601_YUV_LIMITED;
    pstTimingInfo->en3DType         = HI_UNF_FRAME_PACKING_TYPE_NONE;
    pstTimingInfo->u32Vblank        = 0;

    if((HI_UNF_INPUT_SOURCE_ATV == enAtvSrc)||(HI_UNF_INPUT_SOURCE_CVBS == enAtvSrc))
    {
        s32Ret = HI_UNF_TVD_GetStdTimingInfo(&stTvdTimingInfo);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_TVD_GetStdTimingInfo Failed \n");
            return HI_FAILURE;
        }
        
        s32Ret = HI_UNF_TVD_GetColorSys(&pstTimingInfo->enColorSys);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_TVD_GetColorSys Failed \n");
            return HI_FAILURE;
        }
        
        pstTimingInfo->enAccessType = HI_UNF_VI_ACCESS_TVD;
        pstTimingInfo->bInterlace   = stTvdTimingInfo.bInterlace;
        pstTimingInfo->enBitWidth   = stTvdTimingInfo.enBitWidth;
        pstTimingInfo->enOversample = stTvdTimingInfo.enOversample;
        pstTimingInfo->enPixelFmt   = stTvdTimingInfo.enPixelFmt;
        pstTimingInfo->u32FrameRate = stTvdTimingInfo.u32FrameRate;
        pstTimingInfo->u32Width     = stTvdTimingInfo.u32Width;
        pstTimingInfo->u32Height    = stTvdTimingInfo.u32Height;
    }
    else if((HI_UNF_INPUT_SOURCE_VGA == enAtvSrc)||(HI_UNF_INPUT_SOURCE_YPBPR == enAtvSrc))
    {
        s32Ret = HI_UNF_HDDEC_GetTimingInfo(&stHddecTimingInfo);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDDEC_GetTimingInfo Failed \n");
            return HI_FAILURE;
        }
        
        pstTimingInfo->enAccessType     = HI_UNF_VI_ACCESS_HDDEC;
        pstTimingInfo->bInterlace       = stHddecTimingInfo.bInterlace;
        pstTimingInfo->enBitWidth       = stHddecTimingInfo.enBitWidth;
        pstTimingInfo->enOversample     = stHddecTimingInfo.enOversample;
        pstTimingInfo->enPixelFmt         = stHddecTimingInfo.enPixFmt;
        pstTimingInfo->u32FrameRate     = stHddecTimingInfo.u32FrameRate;
        pstTimingInfo->u32Width         = stHddecTimingInfo.u32Width;
        pstTimingInfo->u32Height        = stHddecTimingInfo.u32Height;
        pstTimingInfo->u32TimingIndex   = stHddecTimingInfo.u32TimingIndex;
        pstTimingInfo->enColorSpace     = stHddecTimingInfo.enColorSpace;
    }
    else if(HI_UNF_INPUT_SOURCE_HDMI== enAtvSrc)
    {
        s32Ret = HI_UNF_HDMIRX_GetTimingInfo(&stHdmirxTimingInfo);
        if (HI_SUCCESS != s32Ret)
        {
            printf("call HI_UNF_HDMIRX_GetTimingInfo Failed \n");
            return HI_FAILURE;
        }
        
        pstTimingInfo->enAccessType     = HI_UNF_VI_ACCESS_HDMI;
        pstTimingInfo->bInterlace       = stHdmirxTimingInfo.bInterlace;
        pstTimingInfo->enBitWidth       = stHdmirxTimingInfo.enBitWidth;
        pstTimingInfo->enOversample     = stHdmirxTimingInfo.enOversample;
        pstTimingInfo->enPixelFmt         = stHdmirxTimingInfo.enPixelFmt;
        pstTimingInfo->u32FrameRate     = stHdmirxTimingInfo.u32FrameRate;
        pstTimingInfo->u32Width         = stHdmirxTimingInfo.u32Width;
        pstTimingInfo->u32Height        = stHdmirxTimingInfo.u32Height;
        pstTimingInfo->enColorSpace     = stHdmirxTimingInfo.enColorSpace;
        pstTimingInfo->bHdmiMode = stHdmirxTimingInfo.bHdmiMode;
        pstTimingInfo->bPcMode = stHdmirxTimingInfo.bPcMode;
        pstTimingInfo->u32Vblank = stHdmirxTimingInfo.u32Vblank;
        pstTimingInfo->en3DType = stHdmirxTimingInfo.en3dFmt;
        pstTimingInfo->u32TimingIndex = stHdmirxTimingInfo.u32TimingIdx;
        //----------------------------------------------------------------------------------------
        printf("u32Width;        %d\n", pstTimingInfo->u32Width        );
        printf("u32Height;       %d\n", pstTimingInfo->u32Height       );
        printf("u32FrameRate;    %d\n", pstTimingInfo->u32FrameRate    );
        printf("enColorSpace;0:601,1:709,2:RGB     %d\n", pstTimingInfo->enColorSpace    );
        printf("enPixelFmt;0:RGB,1:420,2:422, 3:444      %d\n", pstTimingInfo->enPixelFmt      );
        printf("enBitWidth;0:8bit,1:10bit,2:12bit      %d\n", pstTimingInfo->enBitWidth      );
        printf("bInterlace;0:Procc;1:Inter      %d\n", pstTimingInfo->bInterlace      );
        printf("enOverSampleMode;0:1X;1:2X,2:4X  %d\n", pstTimingInfo->enOversample);
        printf("en3dFmt; 0:2D        %d\n", pstTimingInfo->en3DType         );
        printf("bDviMode;        %d\n", pstTimingInfo->bHdmiMode        );
        printf("u32Vblank;       %d\n", pstTimingInfo->u32Vblank       );
        printf("bPcMode;       %d\n", pstTimingInfo->bPcMode       );
        printf("u32TimingIndex;       %d\n", pstTimingInfo->u32TimingIndex);
    }
    return HI_SUCCESS;
}

HI_S32 HIADP_VI_Set3DFmtType(HI_UNF_VIDEO_FRAME_PACKING_TYPE_E enVi3DFmt)
{
    if ((enVi3DFmt < HI_UNF_FRAME_PACKING_TYPE_NONE) || 
        (enVi3DFmt >= HI_UNF_FRAME_PACKING_TYPE_BUTT))
    {
        printf("\r\nIllegal 3D Format Type, Set failed!\r\n");
        return HI_FAILURE;
    }

    enVi3DFmtType = enVi3DFmt;
    
    return HI_SUCCESS;
}

HI_VOID HIADP_VI_Clean3DFmtType(HI_VOID)
{
    enVi3DFmtType = HI_UNF_FRAME_PACKING_TYPE_BUTT;
    
    return ;
}

HI_S32 HIADP_StarAtvCapture(HI_HANDLE *ps_hVi, HI_UNF_INPUT_SOURCE_TYPE_E enAtvSrc)
{
    HI_S32                      s32Ret;
    HI_ADP_TIMING_INFO_S        stTimingInfo;
    HI_UNF_VI_ATTR_S stViAttr = {0};
    
    printf("\n\ncall HIADP_StarAtvCapture Enter enAtvSrc=%d\n", enAtvSrc);

    s32Ret = HIADP_AtvGetTimingInfo(enAtvSrc, &stTimingInfo);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HIADP_AtvGetTimingInfo Failed \n");
        return HI_FAILURE;
    }
        
    s32Ret = HI_UNF_VI_GetDefaultAttr(&stViAttr);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VI_GetDefaultAttr Failed \n");
        return HI_FAILURE;
    }

    stViAttr.enType                 = HI_UNF_VI_MAIN;        
    stViAttr.bBypassVpss            = HI_FALSE;
    stViAttr.enIntfMode             = HI_UNF_VI_INTF_FVHDE;
    if (enAtvSrc == HI_UNF_INPUT_SOURCE_VGA)
    {
        stViAttr.bGraphicMode           = HI_TRUE;
    }
    else
    {
        stViAttr.bGraphicMode           = HI_FALSE;
    }
    if (HI_UNF_FRAME_PACKING_TYPE_BUTT != enVi3DFmtType)
    {
        stViAttr.en3dFmt            = enVi3DFmtType;
    }
    else
    {
        stViAttr.en3dFmt            = stTimingInfo.en3DType;
    }
    stViAttr.enAccess               = stTimingInfo.enAccessType;
    stViAttr.bInterlace             = stTimingInfo.bInterlace;    
    stViAttr.stInputRect.s32X       = 0;
    stViAttr.stInputRect.s32Y       = 0;
    stViAttr.stInputRect.s32Width   = stTimingInfo.u32Width;
    stViAttr.stInputRect.s32Height  = stTimingInfo.u32Height;  
    stViAttr.u32Width               = stTimingInfo.u32Width;     
    stViAttr.u32Height              = stTimingInfo.u32Height;      
    stViAttr.u32FrameRate           = stTimingInfo.u32FrameRate;  
    stViAttr.enColorSpace           = stTimingInfo.enColorSpace;  
    stViAttr.enPixFmt               = stTimingInfo.enPixelFmt;      
    stViAttr.enBitWidth             = stTimingInfo.enBitWidth;    
    stViAttr.enOverSample           = stTimingInfo.enOversample;  
    stViAttr.u32Vblank              = stTimingInfo.u32Vblank;
    stViAttr.enSourceType           = stTimingInfo.enSourceType;  
    stViAttr.enColorSys             = stTimingInfo.enColorSys;    
    stViAttr.bUserOut               = HI_TRUE;

    s32Ret = HI_UNF_VI_Create(&stViAttr, ps_hVi);
    if (HI_SUCCESS != s32Ret)
    {
        printf("call HI_UNF_VI_Create Failed \n");
        return HI_FAILURE;
    }
    
    return s32Ret;
}

static HI_VOID *HIADP_AtvMonitorProcess(HI_VOID *pdata)
{
    HI_S32                      s32Ret;
    HI_UNF_SIG_STATUS_E         enSignalStatusPre = HI_UNF_SIG_NO_SIGNAL;
    HI_UNF_SIG_STATUS_E         enSignalStatusCurrent = HI_UNF_SIG_NO_SIGNAL;
    HI_UNF_VIDEO_NONSTD_INFO_S  stPreNstdInfo, stCurrentNstdInfo;
    HI_UNF_INPUT_SOURCE_TYPE_E  enAtvSrc;
    
    memset(&stCurrentNstdInfo, 0, sizeof(HI_UNF_VIDEO_NONSTD_INFO_S));
    memset(&stPreNstdInfo, 0, sizeof(HI_UNF_VIDEO_NONSTD_INFO_S));

    while (s_bMonitorEn)
    {
        sem_wait(&bin_sem);
        enAtvSrc = s_enAtvSrc;
        sem_post(&bin_sem);
        
        if ((HI_UNF_INPUT_SOURCE_ATV == enAtvSrc) || (HI_UNF_INPUT_SOURCE_CVBS == enAtvSrc) ||
            (HI_UNF_INPUT_SOURCE_YPBPR == enAtvSrc)||(HI_UNF_INPUT_SOURCE_VGA == enAtvSrc)
            ||(HI_UNF_INPUT_SOURCE_HDMI == enAtvSrc))
        {
            s32Ret = HIADP_AtvGetSigStatus(enAtvSrc, &enSignalStatusCurrent);
            
            if (HI_SUCCESS != s32Ret)
            {
                printf("call HIADP_AtvGetSigStatus Failed \n");
            }
        }
        else
        {
            s_bMonitorEn = HI_FALSE;
            printf("Current enAtvSrc=%d Not Support \n", enAtvSrc);
            
            break;
        }
                
        if (enSignalStatusPre != enSignalStatusCurrent)
        {
            /* 1. Signal change from Support state to other state, stop play */
            if (HI_UNF_SIG_SUPPORT == enSignalStatusPre)
            {
                if (s_hVi)
                {
                    HIADP_StopPlay(s_hWindow, s_hVi);
                }
            }
            
            /* 2. Signal change from other state to Support state, start play */
            if (HI_UNF_SIG_SUPPORT == enSignalStatusCurrent)
            {
                HIADP_StarAtvCapture(&s_hVi, enAtvSrc);
                //HIADP_StarCvbstCapture(&s_hVi);
                
                if ((HI_UNF_INPUT_SOURCE_ATV == enAtvSrc) || (HI_UNF_INPUT_SOURCE_CVBS == enAtvSrc) ||
                    (HI_UNF_INPUT_SOURCE_YPBPR == enAtvSrc))
                {
                    HIADP_UpdateNstdInfo(enAtvSrc, &stCurrentNstdInfo, &stPreNstdInfo);
                }
                
                HIADP_StartPlay(s_hWindow, s_hVi);
            }
            
            /* update  enSignalStatusPre*/
            enSignalStatusPre = enSignalStatusCurrent;
        }

        /* 3. Update Non Standard Signal Info */
        if ((HI_UNF_SIG_SUPPORT == enSignalStatusCurrent))
        {
            if ((HI_UNF_INPUT_SOURCE_ATV == enAtvSrc) || (HI_UNF_INPUT_SOURCE_CVBS == enAtvSrc) ||
                (HI_UNF_INPUT_SOURCE_YPBPR == enAtvSrc))
            {
                HIADP_UpdateNstdInfo(enAtvSrc, &stCurrentNstdInfo, &stPreNstdInfo);
            }
        }
    }
    
    /* 4. Quit Moniter and Mute then stop play */
    HIADP_StopPlay(s_hWindow, s_hVi);

    s32Ret = HIADP_DisConnectAtvSrc(s_enAtvSrc);
    if (HI_SUCCESS != s32Ret)
    {
        printf("HIADP_ConnectAtvSrc Failure!\n");
    }
    s_enAtvSrc = HI_UNF_INPUT_SOURCE_BUTT;
    
    printf("call HIADP_TvdMonitorProcess Exit \n");
    return NULL;
}



HI_S32 HIADP_SwitchAtvSrc(HI_UNF_INPUT_SOURCE_TYPE_E enAtvSrc)
{
    HI_S32 s32Ret;
    
    if ((HI_UNF_INPUT_SOURCE_ATV > enAtvSrc) || (HI_UNF_INPUT_SOURCE_BUTT <= enAtvSrc))
    {
        printf("enAtvSrc =%d Should be in [%d, %d]!\n",enAtvSrc, HI_UNF_INPUT_SOURCE_ATV, HI_UNF_INPUT_SOURCE_BUTT);
    }
    sem_wait(&bin_sem);
    
    if(s_enAtvSrc != HI_UNF_INPUT_SOURCE_BUTT)
    {
        s_bSourceChange = HI_TRUE;
        
        if (s_hVi)
        {
            HIADP_StopPlay(s_hWindow, s_hVi);
        }
        s32Ret = HIADP_DisConnectAtvSrc(s_enAtvSrc);
        if (HI_SUCCESS != s32Ret)
        {
            printf("HIADP_DisConnectAtvSrc  s_enAtvSrc=%d Failure!\n", s_enAtvSrc);
            
            //return HI_FAILURE;
        }
    }

    s32Ret = HIADP_ConnectAtvSrc(enAtvSrc);
    if (HI_SUCCESS != s32Ret)
    {
        printf("HIADP_ConnectAtvSrc enAtvSrc=%d Failure!\n", enAtvSrc);
        
        //return HI_FAILURE;
    }
    
    s_bSourceChange = HI_FALSE;
    s_enAtvSrc = enAtvSrc;
    sem_post(&bin_sem);

    return HI_SUCCESS;
}


HI_S32 HIADP_StartAtvMoniter(HI_VOID)
{
    HI_S32 s32Ret;

    s_bMonitorEn = HI_TRUE;

    s32Ret = pthread_create(&s_stMonitorThrd, NULL, HIADP_AtvMonitorProcess, NULL);
    if (HI_SUCCESS != s32Ret)
    {
        printf("Create Monitor Thread Failure!\n");
        
        return HI_FAILURE;
    }

    return HI_SUCCESS;
}

HI_S32 HIADP_DMX_AttachTSPort(HI_U32 Dmxid, HI_U32 TunerID)
{
    HI_S32                      Ret;
    HI_UNF_DMX_PORT_E           DmxAttachPort;
    HI_UNF_DMX_PORT_ATTR_S      DmxAttachPortAttr;
    if (FIRST_TUNER == TunerID)
    {
        DmxAttachPort = HI_UNF_DMX_PORT_IF_0;
    }    
    else
    {
        printf("No this tuner device\n");
        return HI_FAILURE;
    }
    
    Ret = HI_UNF_DMX_GetTSPortAttr(DmxAttachPort, &DmxAttachPortAttr);
    switch (DmxAttachPort)
    {
    case HI_UNF_DMX_PORT_IF_0:
    default:
        DmxAttachPortAttr.enPortType = HI_UNF_DMX_PORT_TYPE_PARALLEL_NOSYNC_188;
        DmxAttachPortAttr.u32SerialBitSelector = 0;
        break;    
    }
    Ret |= HI_UNF_DMX_SetTSPortAttr(DmxAttachPort, &DmxAttachPortAttr);
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_DMX_SetTSPortAttr failed.\n");
        return HI_FAILURE;
    }
    Ret = HI_UNF_DMX_AttachTSPort(Dmxid, DmxAttachPort);
    if (HI_SUCCESS != Ret)
    {
        printf("call HI_UNF_DMX_AttachTSPort.\n");
        return HI_FAILURE;
    }
    return HI_SUCCESS;
}



