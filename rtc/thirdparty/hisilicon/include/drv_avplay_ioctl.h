#ifndef __DRV_AVPLAY_IOCTL_H__
#define __DRV_AVPLAY_IOCTL_H__

#include "hi_type.h"
#include "hi_unf_audio.h"
#include "hi_unf_avplay.h"
#include "hi_drv_adec.h"
#include "hi_mpi_mem.h"
#include "hi_mpi_stat.h"
#include "hi_mpi_vdec.h"
#include "hi_mpi_adec.h"
#include "hi_mpi_demux.h"
#include "hi_mpi_sync.h"
#include "hi_mpi_win.h"
#ifndef __KERNEL__ 
#include "hi_mpi_ao.h"
#endif
#include "hi_mpi_demux.h"
#include "hi_drv_avplay.h"
#include "hi_drv_vdec.h"
#ifdef __cplusplus
#if __cplusplus
    extern "C"{
#endif
#endif

#define  AVPLAY_MAX_NUM                 16
#define  AVPLAY_MAX_DMX_AUD_CHAN_NUM    32
#define  AVPLAY_MAX_TRACK               6

#define  AVPLAY_MAX_SLAVE_FRMCHAN       2    //The max num of slave port
#define  AVPLAY_MAX_VIR_FRMCHAN         2    //The max num of virtual port


typedef    HI_S32 (*AVPLAY_EVT_CB_FN)(HI_HANDLE hAvplay, HI_UNF_AVPLAY_EVENT_E EvtMsg, HI_U32 EvtPara);

typedef enum hiAVPLAY_PROC_ID_E
{
    AVPLAY_PROC_ADEC_AO,
    AVPLAY_PROC_DMX_ADEC,
    AVPLAY_PROC_VDEC_VO,
    AVPLAY_PROC_BUTT
}AVPLAY_PROC_ID_E;

typedef struct tagAVPLAY_VID_PORT_AND_WIN_S
{
    HI_HANDLE   hWindow;
    HI_HANDLE   hPort;
}AVPLAY_VID_PORT_AND_WIN_S;

typedef struct tagAVPLAY_FRC_CTRL_S
{
	/* frame rate conversion state for progressive frame : <0-drop; ==0-natrual play; >0-repeat time */
	HI_S32 s32FrmState;  
}AVPLAY_FRC_CTRL_S;

typedef struct tagAVPLAY_FRC_CFG_S
{
	HI_U32  u32InRate;     /* unit: frame */
	HI_U32  u32OutRate;  /* fresh rate */
	HI_U32  u32PlayRate;  /* play rate*/
}AVPLAY_FRC_CFG_S;

typedef struct tagAVPLAY_ALG_FRC_S
{
	HI_U32  u32InRate;     /* unit: frame */
	HI_U32  u32OutRate;  /* fresh rate */
	HI_U32  u32PlayRate;  /* play rate*/
    HI_U32  u32CurID;     /* current insert or drop position in a FRC cycle*/
	HI_U32  u32InputCount; /* input counter */
}AVPLAY_ALG_FRC_S;

typedef struct hiAVPLAY_VIDFRM_STAT_S
{
    HI_U32      SendNum;
    HI_U32      PlayNum;
    HI_U32      RepeatNum;
    HI_U32      DiscardNum;
}AVPLAY_VIDFRM_STAT_S;

typedef struct hiAVPLAY_DEBUG_INFO_S
{
    HI_U32                     AcquireAudEsNum;
    HI_U32                     AcquiredAudEsNum;
    HI_U32                     SendAudEsNum;
    HI_U32                     SendedAudEsNum;

    HI_U32                     AcquireAudFrameNum;
    HI_U32                     AcquiredAudFrameNum;
    HI_U32                     SendAudFrameNum;
    HI_U32                     SendedAudFrameNum;

    HI_U32                     AcquireVidFrameNum;
    HI_U32                     AcquiredVidFrameNum;
    AVPLAY_VIDFRM_STAT_S       MasterVidStat;
    AVPLAY_VIDFRM_STAT_S       SlaveVidStat[AVPLAY_MAX_SLAVE_FRMCHAN];
    AVPLAY_VIDFRM_STAT_S       VirVidStat[AVPLAY_MAX_VIR_FRMCHAN];

    HI_U32                     VidOverflowNum;
    HI_U32                     AudOverflowNum;

    HI_U32                     ThreadBeginTime;
    HI_U32                     ThreadEndTime;
    HI_U32                     ThreadScheTimeOutCnt;
    HI_U32                     ThreadExeTimeOutCnt;

}AVPLAY_DEBUG_INFO_S;

typedef enum hiTHREAD_PRIO_E
{
    THREAD_PRIO_REALTIME,    /*Realtime thread, only 1 permitted*/
    THREAD_PRIO_HIGH,
    THREAD_PRIO_MID,
    THREAD_PRIO_LOW,
    THREAD_PRIO_BUTT
}THREAD_PRIO_E;

/* for 64bit */
typedef struct hiUNF_VCODEC_ATTR_32T64_S
{
    HI_UNF_VCODEC_TYPE_E        enType;          /**<Video encoding type*/ /**<CNcomment: 视频编码类型*/
    HI_UNF_VCODEC_EXTATTR_U     unExtAttr;       /**<Extra attributes related to the video encoding type*/ /**<CNcomment: 视频编码类型相关的额外属性*/
    HI_UNF_VCODEC_MODE_E        enMode;          /**<Mode of a video decoder*/ /**<CNcomment: 视频解码器模式模式*/
    HI_U32                      u32ErrCover;     /**<Error concealment threshold of the output frames of a video decoder. The value 0 indicates that no frames are output if an error occurs; the value 100 indicates that all frames are output no matter whether errors occur.*/
                                                 /**<CNcomment: 视频解码器的输出帧错误隐藏门限，0:出现错误即不输出；100:不管错误比例全部输出*/
    HI_U32                      u32Priority;     /**<Priority of a video decoder. The value range is [1, HI_UNF_VCODEC_MAX_PRIORITY]. The value 0 is a reserved value. If you set the value to 0, no error message is displayed, but the value 1 is used automatically. The smaller the value, the lower the priority.*/
                                                 /**<CNcomment: 视频解码器优先级, 取值范围: 大于等于1，小于等于HI_UNF_VCODEC_MAX_PRIORITY, 0是保留值，配置为0不会报错，但是会自动取值为1,数值越小优先级越低 */
    HI_BOOL                     bOrderOutput;    /**<Whether the videos are output by the decoding sequence. You are advised to set this parameter to HI_TRUE in VP mode, and HI_FALSE in other modes.*/
                                                 /**<CNcomment: 是否按解码序输出，VP模式下推荐配置为HI_TRUE, 一般模式下配置为HI_FALSE */    
    HI_S32                      s32CtrlOptions;  /**<The value is HI_UNF_VCODEC_CTRL_OPTION_E, or the 'or' value of several enum type*/
                                                 /**<CNcomment: 取值为HI_UNF_VCODEC_CTRL_OPTION_E，或者几个枚举的'或'  */
    //HI_VOID*                    pCodecContext;   /**<Private codec context */
    HI_U32                      u32AvplayReserved0;
}HI_UNF_VCODEC_ATTR_32T64_S;

typedef struct hiUNF_STREAM_BUF_32T64_S
{
    HI_U32  u32AvplayReserved1;
    //HI_U8   *pu8Data;        /**<Data pointer*/ /**<CNcomment: 数据指针 */
    HI_U32  u32Size;         /**<Data size*/ /**<CNcomment: 数据长度 */
} HI_UNF_STREAM_BUF_32T64_S;

typedef struct hiUNF_ES_BUF_32T64_S
{
    HI_U32 u32AvplayReserved2;
    //HI_U8 * pu8Buf;    /**<User-state virtual address of the buffer*/ /**<CNcomment: buffer的用户态虚地址*/
    HI_U32 u32BufLen;  /**<Buffer length*/ /**<CNcomment: buffer的长度*/
    HI_U32 u32PtsMs;   /**<Presentation time stamp (PTS) value corresponding to the start of the stream. The invalid value is 0xFFFFFFFF.*/
                       /**<CNcomment: 码流开始处对应的PTS值，无效为0xffffffff*/
}HI_UNF_ES_BUF_32T64_S;

typedef struct hiUNF_AO_FRAMEINFO_32T64_S
{
    HI_S32  s32BitPerSample;       /**<Data depth*/ /**<CNcomment: 数据位宽*/
    HI_BOOL bInterleaved;          /**<Whether the data is interleaved*/ /**<CNcomment: 数据是否交织*/
    HI_U32  u32SampleRate;         /**<Sampling rate*/ /**<CNcomment: 采样率*/
    HI_U32  u32Channels;           /**<Number of channels*/ /**<CNcomment: 通道数量*/
    HI_U32  u32PtsMs;              /**<Presentation time stamp (PTS)*/ /**<CNcomment: 时间戳*/
    HI_U32  u32AvplayReserved3;
    HI_U32  u32AvplayReserved4;
    //HI_S32 *ps32PcmBuffer;         /**<Pointer to the buffer for storing the pulse code modulation (PCM) data*/ /**<CNcomment: PCM数据缓冲指针*/
    //HI_S32 *ps32BitsBuffer;        /**<Pointer to the buffer for storing the stream data*/ /**<CNcomment: 码流数据缓冲指针*/
    HI_U32  u32PcmSamplesPerFrame; /**<Number of sampling points of the PCM data*/ /**<CNcomment: PCM数据采样点数量*/
    HI_U32  u32BitsBytesPerFrame;  /**<IEC61937 data size*/ /**<CNcomment: IEC61937数据长度*/
    HI_U32  u32FrameIndex;         /**<Frame ID*/ /**<CNcomment: 帧序号 */
	HI_U32  u32IEC61937DataType;      /**<IEC61937 Data Type*/ /**<CNcomment: IEC61937数据类型标识，低8bit为IEC数据类型 */
} HI_UNF_AO_FRAMEINFO_32T64_S;

#pragma pack(4)
typedef struct hiAVPLAY_S
{
    HI_UNF_AVPLAY_ATTR_S            AvplayAttr;
#ifndef __KERNEL__    
    HI_UNF_VCODEC_ATTR_S            VdecAttr;
#else
    HI_UNF_VCODEC_ATTR_32T64_S      VdecAttr;
#endif
    HI_UNF_AVPLAY_LOW_DELAY_ATTR_S  LowDelayAttr;
    HI_U32                          AdecType;
    
    HI_HANDLE                       hAvplay;
    HI_HANDLE                       hVdec;
    HI_HANDLE                       hAdec;
    HI_HANDLE                       hDmxVid;
    HI_HANDLE                       hDmxAud[AVPLAY_MAX_DMX_AUD_CHAN_NUM];
    HI_HANDLE                       hDmxPcr;
    HI_HANDLE                       hSync;
    
    HI_U32                          DmxVidPid;
    HI_U32                          DmxPcrPid; 
    HI_U32                          DmxAudPid[AVPLAY_MAX_DMX_AUD_CHAN_NUM]; 

    /*multi audio demux channel*/
    HI_U32                          CurDmxAudChn;
    HI_U32                          DmxAudChnNum;
#ifndef __KERNEL__    
    HI_UNF_ACODEC_ATTR_S            *pstAcodecAttr;
#else
    HI_U32                          u32AvplayReserved5;
#endif
    HI_HANDLE                       hSharedOrgWin;  /*Original window of homologous*/

    HI_U32                          u32ContentCount;
	HI_U32                          u32LastContentCount;
           
    /*multi video frame channel*/
    AVPLAY_VID_PORT_AND_WIN_S       MasterFrmChn;
    AVPLAY_VID_PORT_AND_WIN_S       SlaveFrmChn[AVPLAY_MAX_SLAVE_FRMCHAN];
    HI_U32                          SlaveChnNum;
    AVPLAY_VID_PORT_AND_WIN_S       VirFrmChn[AVPLAY_MAX_VIR_FRMCHAN];
    HI_U32                          VirChnNum;

    /*multi audio track channel*/
    HI_HANDLE                       hSyncTrack;
    HI_HANDLE                       hTrack[AVPLAY_MAX_TRACK];
    HI_U32                          TrackNum;

    /*frc parameters*/
    HI_BOOL                         bFrcEnable;
    AVPLAY_FRC_CFG_S                FrcParamCfg;        /* config frc param */ /*CNcomment: 配置的frc参数 */
    AVPLAY_ALG_FRC_S                FrcCalAlg;          /* frc used rate info */ /*CNcomment: frc正在使用的帧率信息 */
    AVPLAY_FRC_CTRL_S               FrcCtrlInfo;        /* frc control */ /*CNcomment: frc控制信息 */
    HI_U32                          FrcNeedPlayCnt;     /* this frame need to play time*/ /*CNcomment:该帧需要播几次 */
    HI_U32                          FrcCurPlayCnt;      /* this frame had played time*/   /*CNcomment:该帧实际播到第几次*/

    /*flush stream control*/
    HI_BOOL                         bSetEosFlag;
    HI_BOOL                         bSetAudEos;

    /*ddp test*/
    HI_BOOL                         AudDDPMode;
    HI_BOOL                         bSpeedAdjust;
    HI_U32                          u32FundTimeOutMs;

    HI_U32                          LastAudPts;

                     
#ifndef __KERNEL__    
    AVPLAY_EVT_CB_FN               EvtCbFunc[HI_UNF_AVPLAY_EVENT_BUTT];
#else
    HI_U32                         u32AvplayReserved6[HI_UNF_AVPLAY_EVENT_BUTT];
#endif

    /*play control parameters*/
    HI_BOOL                         bSendedFrmToVirWin;          /*whether this frame has send to virtual window*/   
    HI_BOOL                         VidEnable;
    HI_BOOL                         AudEnable;
    HI_BOOL                         bVidPreEnable;
    HI_BOOL                         bAudPreEnable;
	HI_BOOL                         VidPreBufThreshhold;
    HI_BOOL                         AudPreBufThreshhold;
	HI_U32							VidPreSysTime;
	HI_U32							AudPreSysTime;
    HI_UNF_AVPLAY_STATUS_E          LstStatus;                   /* last avplay status */
    HI_UNF_AVPLAY_STATUS_E          CurStatus;                   /* current avplay status */
    HI_UNF_AVPLAY_OVERFLOW_E        OverflowProc;
    HI_BOOL                         AvplayProcContinue;          /*flag for thread continue*/
    HI_BOOL                         AvplayVidProcContinue;       /*flag for video thread continue*/
	
    HI_BOOL                         AvplayProcDataFlag[AVPLAY_PROC_BUTT];

#ifndef __KERNEL__ 
    HI_UNF_STREAM_BUF_S             AvplayAudEsBuf;      /*adec buffer in es mode*/
    HI_UNF_ES_BUF_S                 AvplayDmxEsBuf;      /*audio denux buffer in ts mode*/
    HI_UNF_AO_FRAMEINFO_S           AvplayAudFrm;        /*audio frames get form adec*/
#else
    HI_UNF_STREAM_BUF_32T64_S       AvplayAudEsBuf;      /*adec buffer in es mode*/
    HI_UNF_ES_BUF_32T64_S           AvplayDmxEsBuf;      /*audio denux buffer in ts mode*/
    HI_UNF_AO_FRAMEINFO_32T64_S     AvplayAudFrm;        /*audio frames get form adec*/
#endif
    SYNC_AUD_INFO_S                 AudInfo;
    SYNC_AUD_OPT_S                  AudOpt;

    VDEC_ES_BUF_S                   AvplayVidEsBuf;      /*vdec buffer in es mode*/
    HI_DRV_VIDEO_FRAME_PACKAGE_S    CurFrmPack;
    HI_DRV_VIDEO_FRAME_PACKAGE_S    LstFrmPack;
    SYNC_VID_INFO_S                 VidInfo;
    SYNC_VID_OPT_S                  VidOpt;

    HI_DRV_VDEC_FRAME_S             stIFrame;

    HI_BOOL                         bStepMode;
    HI_BOOL                         bStepPlay;

    AVPLAY_DEBUG_INFO_S             DebugInfo;
    
    HI_U32                          PreAudEsBuf;         /*audio es buffer size when EOS happens*/
    HI_U32                          PreVidEsBuf;         /*video es buffer size when EOS happens*/
    HI_U32                          PreSystime;          /*system time when EOS happens*/
    HI_U32                          PreVidEsBufWPtr;     /*position of the video es buffer write pointer*/
    HI_U32                          PreAudEsBufWPtr;     /*position of the audio es buffer write pointer*/
    HI_U32                          PreTscnt;            /*ts count when EOS happens*/
    HI_BOOL                         CurBufferEmptyState; /*current buffer state is empty or not*/

    HI_UNF_AVPLAY_BUF_STATE_E       PreVidBufState;     /*the status of video es buffer when CheckBuf*/
    HI_UNF_AVPLAY_BUF_STATE_E       PreAudBufState;     /*the status of audio es buffer when CheckBuf*/
    HI_BOOL                         VidDiscard;

    HI_U32                          EosStartTime;        /*EOS start time*/
    HI_U32                          EosDurationTime;     /*EOS duration time*/

    HI_BOOL                         bStandBy;            /*is standby or not*/

    HI_U32                          AdecDelayMs;            /*How many mseconds in ADEC buffer*/
    ADEC_SzNameINFO_S               AdecNameInfo;

    HI_U32                          u32DispOptimizeFlag;    /*this is for pvr smooth tplay*/

    HI_U32                          ThreadID;
    HI_BOOL                         AvplayThreadRun;
    THREAD_PRIO_E                   AvplayThreadPrio;    /*the priority level of avplay thread*/

#ifndef __KERNEL__
    pthread_t                       AvplayDataThdInst;  /* run handle of avplay thread */  
    pthread_t                       AvplayVidDataThdInst;  /* run handle of avplay thread */ 
    pthread_attr_t                  AvplayThreadAttr;   /*attribute of avplay thread*/
    pthread_mutex_t                 *pAvplayThreadMutex;     /*mutex for data safety use*/
    pthread_mutex_t                 *pAvplayVidThreadMutex;     /*mutex for data safety use*/

    pthread_t                       AvplayStatThdInst;    /* run handle of avplay thread */  
#endif

    HI_U32                          u32AoUnloadTime;    
    HI_U32                          u32WinUnloadTime;
    HI_U32                          u32ThreadScheTimeOutCnt;
}AVPLAY_S;
#pragma pack()

typedef struct hiAVPLAY_CREATE_S
{
    HI_U32             AvplayId;
    HI_U32             AvplayPhyAddr;
    HI_UNF_AVPLAY_STREAM_TYPE_E    AvplayStreamtype;
}AVPLAY_CREATE_S;

typedef struct hiAVPLAY_USR_ADDR_S
{
    HI_U32     AvplayId;
    HI_U32     AvplayUsrAddr;    /* AVPLAY address in user model */ 
}AVPLAY_USR_ADDR_S;

typedef struct hiAVPLAY_INFO_S
{
    AVPLAY_S         *pAvplay;         /* AVPLAY pointer in kernel model */
    HI_U32           AvplayPhyAddr;    /* AVPLAY physical address */ 
    struct file      *File;             /*avplay file handle*//* CNcomment: AVPLAY所在进程句柄 */
    HI_U32           AvplayUsrAddr;    /* AVPLAY address in user model */ 
}AVPLAY_INFO_S;

typedef struct hiAVPLAY_GLOBAL_STATE_S
{
    AVPLAY_INFO_S  AvplayInfo[AVPLAY_MAX_NUM];
    HI_U32         AvplayCount;
    HI_U32         DestroyContentCount; /*record total count of content which destroy*/
}AVPLAY_GLOBAL_STATE_S;


typedef enum hiIOC_AVPLAY_E
{
    IOC_AVPLAY_GET_NUM = 0,

    IOC_AVPLAY_CREATE,
    IOC_AVPLAY_DESTROY,

    IOC_AVPLAY_CHECK_ID,
    IOC_AVPLAY_SET_USRADDR,

    IOC_AVPLAY_ACQUIRE_USRDATA,
    IOC_AVPLAY_RELEASE_USRDATA,

    IOC_AVPLAY_CHECK_NUM,

    IOC_AVPLAY_GETID_BYWINDOW,
    IOC_AVPLAY_SET_FRAMEPACKING,
    IOC_AVPLAY_GET_FRAMEPACKING,
    IOC_AVPLAY_GET_VIDEOFRMAEINFO,
    IOC_AVPLAY_GET_GLOBALPLAYINFO,
    IOC_AVPLAY_SET_3DDETECT,
    IOC_AVPLAY_GET_3DRESULT,
    
    IOC_AVPLAY_SET_BUTT
}IOC_AVPLAY_E;

typedef struct hiAVPLAY_FRAME_PACKING_S
{
    HI_U32     AvplayId;
    HI_UNF_VIDEO_FRAME_PACKING_TYPE_E enFramePackingType;
}AVPLAY_FRAME_PACKING_S;

typedef struct hiAVPLAY_VIDEO_FRAME_INFO_S
{
    HI_U32     AvplayId;
    HI_UNF_AVPLAY_VIDEO_FRAME_INFO_S stVideoFrameInfo;
}AVPLAY_VIDEO_FRAME_INFO_S;

typedef struct hiAVPLAY_WINDOW_INFO_S
{
    HI_U32     AvplayId;
    HI_HANDLE  hWindow;
}AVPLAY_WINDOW_INFO_S;

typedef struct hiAVPLAY_PLAY_INFO_S
{
    HI_U32     AvplayId;
    HI_UNF_AVPLAY_GLOBAL_PLAY_INFO_S stPlayInfo;
}AVPLAY_PLAY_INFO_S;

typedef struct hiAVPLAY_3D_DETECT_S
{
    HI_U32     AvplayId;
    HI_UNF_AVPLAY_3D_DETECT_ATTR_S st3DDetectAttr;
}AVPLAY_3D_DETECT_S;

typedef struct hiAVPLAY_USER_DATA_S
{
    HI_U32     AvplayId;
    HI_UNF_VIDEO_USERDATA_TYPE_E enType;
    HI_DRV_VDEC_USERDATA_S *pstUserData;
}AVPLAY_USER_DATA_S;

typedef enum hiAVPLAY_USERDATA_IDX_E
{
    AVPLAY_USERDATA_IDX_CC = 0,
    AVPLAY_USERDATA_IDX_AFD,
    AVPLAY_USERDATA_IDX_BAR,

    AVPLAY_USERDATA_IDX_BUTT,
}AVPLAY_USERDATA_IDX_E;

typedef struct hiAVPLAY_USRDATA_INFO_S
{
    HI_U8       *pu8BaseVir;
    HI_U32      u32BasePhy;
    HI_U32      u32TotalLen;

    HI_U8       *pu8Buffer;/* for release user data*/
}AVPLAY_USRDATA_INFO_S;


#define CMD_AVPLAY_CREATE            _IOWR(HI_ID_AVPLAY, IOC_AVPLAY_CREATE, AVPLAY_CREATE_S)
#define CMD_AVPLAY_DESTROY           _IOW(HI_ID_AVPLAY, IOC_AVPLAY_DESTROY, HI_U32)

#define CMD_AVPLAY_CHECK_ID       _IOWR(HI_ID_AVPLAY, IOC_AVPLAY_CHECK_ID, AVPLAY_USR_ADDR_S)
#define CMD_AVPLAY_SET_USRADDR    _IOW(HI_ID_AVPLAY, IOC_AVPLAY_SET_USRADDR, AVPLAY_USR_ADDR_S)

#define CMD_AVPLAY_ACQUIRE_USRDATA    _IOWR(HI_ID_AVPLAY, IOC_AVPLAY_ACQUIRE_USRDATA, AVPLAY_USER_DATA_S)
#define CMD_AVPLAY_RELEASE_USRDATA    _IOWR(HI_ID_AVPLAY, IOC_AVPLAY_RELEASE_USRDATA, AVPLAY_USER_DATA_S)


#define CMD_AVPLAY_CHECK_NUM      _IOWR(HI_ID_AVPLAY, IOC_AVPLAY_CHECK_NUM, HI_U32)

#define CMD_AVPLAY_GETID_BYWINDOW       _IOWR(HI_ID_AVPLAY, IOC_AVPLAY_GETID_BYWINDOW, AVPLAY_WINDOW_INFO_S)
#define CMD_AVPLAY_SET_FRAMEPACKING     _IOW(HI_ID_AVPLAY, IOC_AVPLAY_SET_FRAMEPACKING, AVPLAY_FRAME_PACKING_S)
#define CMD_AVPLAY_GET_FRAMEPACKING     _IOWR(HI_ID_AVPLAY, IOC_AVPLAY_GET_FRAMEPACKING, AVPLAY_FRAME_PACKING_S)
#define CMD_AVPLAY_GET_VIDEOFRMAEINFO   _IOWR(HI_ID_AVPLAY, IOC_AVPLAY_GET_VIDEOFRMAEINFO, AVPLAY_VIDEO_FRAME_INFO_S)
#define CMD_AVPLAY_GET_GLOBALPLAYINFO   _IOWR(HI_ID_AVPLAY, IOC_AVPLAY_GET_GLOBALPLAYINFO, AVPLAY_PLAY_INFO_S)
#define CMD_AVPLAY_SET_3DDETECT         _IOW(HI_ID_AVPLAY, IOC_AVPLAY_SET_3DDETECT, AVPLAY_3D_DETECT_S)
#define CMD_AVPLAY_GET_3DRESULT         _IOWR(HI_ID_AVPLAY, IOC_AVPLAY_GET_3DRESULT, AVPLAY_FRAME_PACKING_S)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif


