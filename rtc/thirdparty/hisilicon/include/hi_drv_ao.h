/******************************************************************************

Copyright (C), 2009-2014, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : hi_drv_ao.h
Version       : Initial Draft
Author        : Hisilicon multimedia software group
Created       : 2012/09/22
Last Modified :
Description   : aiao
Function List :
History       :
* main\1    2012-09-22   z40717     init.
******************************************************************************/
#ifndef __HI_DRV_AO_H__
 #define __HI_DRV_AO_H__

#ifdef __cplusplus
#if __cplusplus
 extern "C"{
#endif
#endif /* __cplusplus */

#include "hi_type.h"
#include "hi_debug.h"
#include "hi_unf_sound.h"

#define  AO_MAX_VIRTUAL_TRACK_NUM  (6)
#define  AO_MAX_REAL_TRACK_NUM     (8)
#define  AO_MAX_TOTAL_TRACK_NUM    AO_MAX_REAL_TRACK_NUM

#define AO_MAX_CAST_NUM (4)

#define AO_MIN_LINEARVOLUME   (0) 
#define AO_MAX_LINEARVOLUME   (100) 
#define AO_MAX_ABSOLUTEVOLUME (0) /* max 0 dB*/
#define AO_MIN_ABSOLUTEVOLUME (-70) /* min -70 dB*/
#define AO_MAX_ABSOLUTEVOLUMEEXT (18) /* max 18 dB for S5*/   
#define AO_MIN_ABSOLUTEVOLUMEEXT (-81) /* min -81 dB for S5*/
#define AO_MIN_DECIMALVOLUME_AMPLIFICATION (1000) /*0.125dB is 125*/
#define AO_MIN_BALANCE        (-50)
#define AO_MAX_BALANCE        (50)
#define AO_MAX_ADJUSTSPEED    (100)  //verify

//TO DO
#define AO_PCM_DF_UNSTALL_THD_FRAMENUM 3    
#define AO_PCM_MAX_UNSTALL_THD_FRAMENUM 10 

#define HI_ID_MASTER_SLAVE_TRACK 0x00
#define HI_ID_LOWLATENCY_TRACK 0x01
#define HI_ID_CAST  0x01
#define HI_ID_AEF   0x02
#define AO_TRACK_CHNID_MASK 0xff
#define AO_CAST_CHNID_MASK 0xff
#define AO_AEF_CHNID_MASK 0xff

#define AEF_MAX_INSTANCE_NUM 4

//#define AO_TRACK_AIP_START_LATENCYMS 50 

#define CHECK_AO_SNDCARD_OPEN(enSound) \
    do                                                         \
    {                                                          \
        CHECK_AO_SNDCARD(enSound);                             \
        if (HI_NULL == s_stAoDrv.astSndEntity[enSound].pCard)     \
        {                                                       \
            HI_WARN_AO(" Invalid snd id %d\n", enSound);        \
            return HI_ERR_AO_SOUND_NOT_OPEN;                       \
        }                                                       \
    } while (0)

#define CHECK_AO_TRACK_ID(Track)                          \
    do {                                                    \
            if((Track & 0xffff0000) != (HI_ID_AO << 16))              \
            {                                               \
                HI_ERR_AO("track(0x%x) is not ao handle!\n", Track);  \
                return HI_ERR_AO_INVALID_PARA;                          \
            }                                               \
            if((Track & 0xff00) != (HI_ID_MASTER_SLAVE_TRACK << 8))              \
            {                                                                \
                if((Track & 0xff00) != (HI_ID_LOWLATENCY_TRACK << 8))     \
            {                                               \
                HI_ERR_AO("track(0x%x) is not track handle!\n", Track);  \
                return HI_ERR_AO_INVALID_PARA;                          \
                }                                                       \
            }    \
         } while(0)        

#define CHECK_AO_TRACK_OPEN(Track) \
    do                                                         \
    {                                                          \
        CHECK_AO_TRACK(Track);                             \
        if (0 == atomic_read(&s_stAoDrv.astTrackEntity[Track & AO_TRACK_CHNID_MASK].atmUseCnt))   \
        {                                                       \
            HI_WARN_AO(" Invalid track id 0x%x\n", Track);        \
            return HI_ERR_AO_INVALID_PARA;                       \
        }                                                       \
    } while (0)

#define CHECK_AO_AEF_HANDLE(hAef)                          \
    do {                                                    \
            if((hAef & 0xffff0000) != (HI_ID_AO << 16))              \
            {                                               \
                HI_ERR_AO("aef(0x%x) is not ao handle!\n", hAef);  \
                return HI_ERR_AO_INVALID_PARA;                          \
            }                                               \
            if((hAef & 0xff00) != (HI_ID_AEF << 8))              \
            {                                               \
                HI_ERR_AO("aef(0x%x) is not aef handle!\n", hAef);  \
                return HI_ERR_AO_INVALID_PARA;                          \
            }    \
            if((hAef & AO_AEF_CHNID_MASK) >= AEF_MAX_INSTANCE_NUM)     \
            {                                               \
                HI_ERR_AO("invalid aef(0x%x) handle!\n", hAef);  \
                return HI_ERR_AO_INVALID_PARA;                          \
            }    \
         } while(0)       
         
#define CHECK_AO_NULL_PTR(p)                                \
    do {                                                    \
            if(HI_NULL == p)                                \
            {                                               \
                HI_ERR_AO("NULL pointer \n");               \
                return HI_ERR_AO_NULL_PTR;                          \
            }                                               \
         } while(0)
         
#define CHECK_AO_CREATE(state)                              \
    do                                                      \
    {                                                       \
        if (0 > state)                                      \
        {                                                   \
            HI_WARN_AO("AO  device not open!\n");           \
            return HI_ERR_AO_DEV_NOT_OPEN;                \
        }                                                   \
    } while (0)
    
#define CHECK_AO_SNDCARD(card)                                  \
    do                                                          \
    {                                                           \
        if (HI_UNF_SND_BUTT <= card)                            \
        {                                                       \
            HI_WARN_AO(" Invalid snd id %d\n", card);           \
            return HI_ERR_AO_INVALID_ID;                       \
        }                                                       \
    } while (0)
/* master & slave only */
#define CHECK_AO_TRACK(track)                                  \
    do                                                          \
    {                                                           \
        if (AO_MAX_TOTAL_TRACK_NUM <= (track & AO_TRACK_CHNID_MASK))                            \
        {                                                       \
            HI_WARN_AO(" Invalid Snd Track 0x%x\n", track);           \
            return HI_ERR_AO_INVALID_PARA;                       \
        }                                                       \
    } while (0)
	
#define CHECK_AO_CAST(cast)                                  \
            do                                                          \
            {                                                           \
                if (AO_MAX_CAST_NUM <= (cast & AO_CAST_CHNID_MASK))                            \
                {                                                       \
                    HI_WARN_AO(" Invalid Snd Cast 0x%x\n", cast);           \
                    return HI_ERR_AO_INVALID_PARA;                       \
                }                                                       \
            } while (0)	

#define CHECK_AO_PORTNUM(num)                                   \
    do                                                          \
    {                                                           \
        if (HI_UNF_SND_OUTPUTPORT_MAX < num)                    \
        {                                                       \
            HI_WARN_AO(" Invalid outport number %d\n", num);       \
            return HI_ERR_AO_INVALID_PARA;                     \
        }                                                       \
    } while (0)

#define CHECK_AO_OUTPORT(port)                                                              \
    do                                                                                      \
    {                                                                                       \
        if (((HI_UNF_SND_OUTPUTPORT_ARC0 < port) && (HI_UNF_SND_OUTPUTPORT_EXT_DAC1 > port)) \
            || ((HI_UNF_SND_OUTPUTPORT_EXT_DAC3 < port) && (HI_UNF_SND_OUTPUTPORT_ALL != port)))    \
        {                                                                                   \
            HI_WARN_AO(" Invalid outport %d\n", port);                                      \
            return HI_ERR_AO_INVALID_PARA;                                                 \
        }                                                                                   \
    } while (0)  

#define CHECK_AO_PORTEXIST(num)                                   \
    do                                                          \
    {                                                           \
        if (0 >= num)                                           \
        {                                                       \
            HI_ERR_AO("Sound dont't attach any port!\n");       \
            return HI_FAILURE;                                  \
        }                                                       \
    } while (0)        
        
            
#define CHECK_AO_TRACKMODE(mode)                                  \
    do                                                          \
    {                                                           \
        if (HI_UNF_TRACK_MODE_BUTT <= mode)                     \
        {                                                       \
            HI_WARN_AO(" Invalid trackmode %d\n", mode);        \
            return HI_ERR_AO_INVALID_PARA;                       \
        }                                                       \
    } while (0)

#define CHECK_AO_HDMIMODE(mode)                                  \
    do                                                          \
    {                                                           \
        if (HI_UNF_SND_HDMI_MODE_BUTT <= mode)                     \
        {                                                       \
            HI_WARN_AO(" Invalid hdmimode %d\n", mode);        \
            return HI_ERR_AO_INVALID_PARA;                       \
        }                                                       \
    } while (0)     

#define CHECK_AO_SPDIFMODE(mode)                                  \
    do                                                          \
    {                                                           \
        if (HI_UNF_SND_SPDIF_MODE_BUTT <= mode)                     \
        {                                                       \
            HI_WARN_AO(" Invalid spdifmode %d\n", mode);        \
            return HI_ERR_AO_INVALID_PARA;                       \
        }                                                       \
    } while (0)

#define CHECK_AO_ARCMODE(mode)                                  \
    do                                                          \
    {                                                           \
        if (HI_UNF_SND_ARC_AUDIO_MODE_BUTT <= mode)             \
        {                                                       \
            HI_WARN_AO(" Invalid arcmode %d\n", mode);        \
            return HI_ERR_AO_INVALID_PARA;                       \
        }                                                       \
    } while (0)          


#define CHECK_AO_SPDIFSCMSMODE(scmsmode)                        \
    do                                                          \
    {                                                           \
        if (HI_UNF_SND_SPDIF_SCMSMODE_BUTT <= scmsmode)         \
        {                                                       \
            HI_WARN_AO(" Invalid spdifscmsmode %d\n", scmsmode);    \
            return HI_ERR_AO_INVALID_PARA;                      \
        }                                                       \
    } while (0)  
    
#define CHECK_AO_CATEGORYCODE(categorycode)                           \
    do                                                                \
    {                                                                 \
        switch(categorycode)                                          \
        {                                                             \
        case HI_UNF_SND_SPDIF_CATEGORY_GENERAL:                       \
        case HI_UNF_SND_SPDIF_CATEGORY_BROADCAST_JP:                  \
        case HI_UNF_SND_SPDIF_CATEGORY_BROADCAST_USA:                 \
        case HI_UNF_SND_SPDIF_CATEGORY_BROADCAST_EU:                  \
        case HI_UNF_SND_SPDIF_CATEGORY_PCM_CODEC:                     \
        case HI_UNF_SND_SPDIF_CATEGORY_DIGITAL_SNDSAMPLER:            \
        case HI_UNF_SND_SPDIF_CATEGORY_DIGITAL_MIXER:                 \
        case HI_UNF_SND_SPDIF_CATEGORY_DIGITAL_SNDPROCESSOR:          \
        case HI_UNF_SND_SPDIF_CATEGORY_SRC:                           \
        case HI_UNF_SND_SPDIF_CATEGORY_MD:                            \
        case HI_UNF_SND_SPDIF_CATEGORY_DVD:                           \
        case HI_UNF_SND_SPDIF_CATEGORY_SYNTHESISER:                   \
        case HI_UNF_SND_SPDIF_CATEGORY_MIC:                           \
        case HI_UNF_SND_SPDIF_CATEGORY_DAT:                           \
        case HI_UNF_SND_SPDIF_CATEGORY_DCC:                           \
        case HI_UNF_SND_SPDIF_CATEGORY_VCR:                           \
            break;                                                    \
        default:                                                      \
            HI_WARN_AO("Invalid category code 0x%x\n", categorycode); \
            return HI_ERR_AO_INVALID_PARA;                            \
        }                                                             \
    } while (0)

#define CHECK_AO_FRAME_NOSTANDART_SAMPLERATE(inrate)                   \
	do													\
	{													\
		if(inrate > HI_UNF_SAMPLE_RATE_192K || inrate < HI_UNF_SAMPLE_RATE_8K) 	\
		{																		\
            HI_INFO_AO("don't support this insamplerate(%d)\n", inrate);    	\
            return HI_SUCCESS;                        							\
		}																		\
	 } while (0)   	



#define CHECK_AO_FRAME_SAMPLERATE(inrate)                   \
    do                                                  \
    {                                                   \
        switch (inrate)                                \
        {                                               \
        case  HI_UNF_SAMPLE_RATE_8K:                    \
        case  HI_UNF_SAMPLE_RATE_11K:                   \
        case  HI_UNF_SAMPLE_RATE_12K:                   \
        case  HI_UNF_SAMPLE_RATE_16K:                   \
        case  HI_UNF_SAMPLE_RATE_22K:                   \
        case  HI_UNF_SAMPLE_RATE_24K:                   \
        case  HI_UNF_SAMPLE_RATE_32K:                   \
        case  HI_UNF_SAMPLE_RATE_44K:                   \
        case  HI_UNF_SAMPLE_RATE_48K:                   \
        case  HI_UNF_SAMPLE_RATE_88K:                   \
        case  HI_UNF_SAMPLE_RATE_96K:                   \
        case  HI_UNF_SAMPLE_RATE_176K:                  \
        case  HI_UNF_SAMPLE_RATE_192K:                  \
            break;                                      \
        default:                                        \
            HI_INFO_AO("don't support this insamplerate(%d)\n", inrate);    \
            return HI_SUCCESS;                        \
        }                                                       \
     } while (0)   

#define CHECK_AO_SAMPLERATE(outrate )                   \
    do                                                  \
    {                                                   \
        switch (outrate)                                \
        {                                               \
        case  HI_UNF_SAMPLE_RATE_8K:                    \
        case  HI_UNF_SAMPLE_RATE_11K:                   \
        case  HI_UNF_SAMPLE_RATE_12K:                   \
        case  HI_UNF_SAMPLE_RATE_16K:                   \
        case  HI_UNF_SAMPLE_RATE_22K:                   \
        case  HI_UNF_SAMPLE_RATE_24K:                   \
        case  HI_UNF_SAMPLE_RATE_32K:                   \
        case  HI_UNF_SAMPLE_RATE_44K:                   \
        case  HI_UNF_SAMPLE_RATE_48K:                   \
        case  HI_UNF_SAMPLE_RATE_88K:                   \
        case  HI_UNF_SAMPLE_RATE_96K:                   \
        case  HI_UNF_SAMPLE_RATE_176K:                  \
        case  HI_UNF_SAMPLE_RATE_192K:                  \
            break;                                      \
        default:                                        \
            HI_WARN_AO("invalid sample out rate %d\n", outrate);    \
            return HI_ERR_AO_INVALID_PARA;                        \
            }                                                       \
            } while (0)   


#define CHECK_AO_FRAME_BITDEPTH(inbitdepth)                 \
			do												\
			{												\
				switch (inbitdepth) 						\
				{											\
				case  HI_UNF_BIT_DEPTH_24:					\
				case  HI_UNF_BIT_DEPTH_16:					\
				case  HI_UNF_BIT_DEPTH_8:					\
					break;									\
				default:									\
					HI_INFO_AO("don't support this bit depth(%d)\n", inbitdepth);	\
					return HI_SUCCESS;						\
				}											\
			 } while (0)   

#define CHECK_AO_LINEARVOLUME(linvolume)                \
    do                                                  \
    {                                                   \
        if ((linvolume < AO_MIN_LINEARVOLUME) || (linvolume > AO_MAX_LINEARVOLUME))                   \
        {                                               \
            HI_WARN_AO("invalid LinearVolume(%d), Min(%d) Max(%d)\n", linvolume, AO_MIN_LINEARVOLUME, AO_MAX_LINEARVOLUME);   \
            return HI_ERR_AO_INVALID_PARA;            \
        }                                               \
    } while (0)

#define CHECK_AO_ABSLUTEVOLUME(absvolume)               \
    do                                                  \
    {                                                   \
        if ((absvolume < AO_MIN_ABSOLUTEVOLUME) || (absvolume > AO_MAX_ABSOLUTEVOLUME))      \
        {                                               \
            HI_WARN_AO("invalid AbsouluteVolume(%d), min(%d), max(%d)\n", absvolume, AO_MIN_ABSOLUTEVOLUME, AO_MAX_ABSOLUTEVOLUME);   \
            return HI_ERR_AO_INVALID_PARA;            \
        }                                               \
    } while (0)

#define CHECK_AO_ABSLUTEPRECIVOLUME(absintvolume, absdecvolume)               \
    do                                                  \
    {                                                   \
        if((absintvolume > 0 && absdecvolume < 0) || (absintvolume < 0 && absdecvolume > 0))        \
        {                                               \
            HI_WARN_AO("invalid precision volume decimal\n");  \
            return HI_ERR_AO_INVALID_PARA;                                           \
        }                                           \
        if ((absdecvolume < -AO_MIN_DECIMALVOLUME_AMPLIFICATION) || (absdecvolume > AO_MIN_DECIMALVOLUME_AMPLIFICATION) || (0 != absdecvolume % 125))      \
        {                                               \
            HI_WARN_AO("invalid precision volume decimal part(%d), min(%d), max(%d), step(125)\n", absdecvolume, -AO_MIN_DECIMALVOLUME_AMPLIFICATION, AO_MIN_DECIMALVOLUME_AMPLIFICATION);   \
            return HI_ERR_AO_INVALID_PARA;            \
        }     \
        if ((absintvolume < AO_MIN_ABSOLUTEVOLUMEEXT) || (absintvolume > AO_MAX_ABSOLUTEVOLUMEEXT))      \
        {                                               \
            HI_WARN_AO("invalid precision volume, min(%d), max(%d)\n", AO_MIN_ABSOLUTEVOLUMEEXT, AO_MAX_ABSOLUTEVOLUMEEXT);   \
            return HI_ERR_AO_INVALID_PARA;            \
        }                                               \
        if(absdecvolume < 0)     \
        {          \
            if (absintvolume - 1 < AO_MIN_ABSOLUTEVOLUMEEXT)      \
            {                                               \
                HI_WARN_AO("invalid precision volume, min(%d)\n", AO_MIN_ABSOLUTEVOLUMEEXT);   \
                return HI_ERR_AO_INVALID_PARA;            \
            }         \
        }   \
        if(absdecvolume > 0)     \
        {          \
            if (absintvolume + 1 > AO_MAX_ABSOLUTEVOLUMEEXT)      \
            {                                               \
                HI_WARN_AO("invalid precision volume, max(%d)\n", AO_MAX_ABSOLUTEVOLUMEEXT);   \
                return HI_ERR_AO_INVALID_PARA;            \
            }         \
        }   \
    } while (0)                 

#define CHECK_AO_ABSLUTEVOLUMEEXT(absvolume)               \
    do                                                  \
    {                                                   \
        if ((absvolume < AO_MIN_ABSOLUTEVOLUMEEXT) || (absvolume > AO_MAX_ABSOLUTEVOLUMEEXT))      \
        {                                               \
            HI_WARN_AO("invalid AbsouluteVolume(%d), min(%d), max(%d)\n", absvolume, AO_MIN_ABSOLUTEVOLUMEEXT, AO_MAX_ABSOLUTEVOLUMEEXT);   \
            return HI_ERR_AO_INVALID_PARA;            \
        }                                               \
    } while (0)

#define CHECK_AO_BALANCE(balance)               \
    do                                                  \
    {                                                   \
        if ((balance < AO_MIN_BALANCE) || (balance > AO_MAX_BALANCE))      \
        {                                               \
            HI_WARN_AO("Invalid Balance(%d), min(%d), max(%d)\n", balance, AO_MIN_BALANCE, AO_MAX_BALANCE);   \
            return HI_ERR_AO_INVALID_PARA;            \
        }                                               \
    } while (0)          

#define   CHECK_AO_SPEEDADJUST(speed)                   \
    do                                                  \
    {                                                   \
        if ((-AO_MAX_ADJUSTSPEED > speed)               \
            || (speed > AO_MAX_ADJUSTSPEED))            \
        {                                               \
            HI_WARN_AO("invalid AO SpeedAdjust(%d) min(%d), max(%d)!\n", speed, -AO_MAX_ADJUSTSPEED, AO_MAX_ADJUSTSPEED); \
            return HI_ERR_AO_INVALID_PARA;            \
        }                                               \
    } while (0)

#define   CHECK_AO_DRCATTR(pstDrcAttr)\
    do\
    {\
        if((pstDrcAttr->u32AttackTime < 20) || (pstDrcAttr->u32AttackTime > 2000))\
        {\
            HI_ERR_AO("Invalid Drc AttackTime! AttackTime(%d)!\n",pstDrcAttr->u32AttackTime);\
            return HI_ERR_AO_INVALID_PARA;\
        }    \
        if((pstDrcAttr->u32ReleaseTime < 20) || (pstDrcAttr->u32ReleaseTime > 2000))\
        {\
            HI_ERR_AO("Invalid Drc ReleaseTime! ReleaseTime(%d)!\n",pstDrcAttr->u32ReleaseTime);\
            return HI_ERR_AO_INVALID_PARA;\
        }\
        if(pstDrcAttr->s32Thrhd > pstDrcAttr->s32Limit) \
        {\
            HI_ERR_AO("s32Thrhd must less than s32Limit! Thrhd(%d),Limit(%d)!\n",pstDrcAttr->s32Thrhd,pstDrcAttr->s32Limit);\
            return HI_ERR_AO_INVALID_PARA;\
        }    \
        if((pstDrcAttr->s32Thrhd < -80) || (pstDrcAttr->s32Thrhd > -2))\
        {\
            HI_ERR_AO("Invalid Drc Thrhd! Thrhd(%d)!\n",pstDrcAttr->s32Thrhd);\
            return HI_ERR_AO_INVALID_PARA;\
        }    \
        if((pstDrcAttr->s32Limit < -79) || (pstDrcAttr->s32Limit > -1))\
        {\
            HI_ERR_AO("Invalid Drc Limit! Limit(%d)!\n",pstDrcAttr->s32Limit);\
            return HI_ERR_AO_INVALID_PARA;\
        }    \
    } while (0)       

 #define HI_FATAL_AO(fmt...) \
    HI_FATAL_PRINT(HI_ID_AO, fmt)

 #define HI_ERR_AO(fmt...) \
    HI_ERR_PRINT(HI_ID_AO, fmt)

 #define HI_WARN_AO(fmt...) \
    HI_WARN_PRINT(HI_ID_AO, fmt)

 #define HI_INFO_AO(fmt...) \
    HI_INFO_PRINT(HI_ID_AO, fmt)

#define HI_FATAL_AIAO(fmt...) HI_FATAL_PRINT  (HI_ID_AIAO, fmt)
#define HI_ERR_AIAO(fmt...)   HI_ERR_PRINT    (HI_ID_AIAO, fmt)
#define HI_WARN_AIAO(fmt...)  HI_WARN_PRINT   (HI_ID_AIAO, fmt)
#define HI_INFO_AIAO(fmt...)  HI_INFO_PRINT   (HI_ID_AIAO, fmt)

 /* the type of Adjust Audio */
typedef enum
{
 AO_SND_SPEEDADJUST_SRC,     /**<samplerate convert */
 AO_SND_SPEEDADJUST_PITCH,   /**<Sola speedadjust, reversed */
 AO_SND_SPEEDADJUST_MUTE,    /**<mute */
 AO_SND_SPEEDADJUST_BUTT 
} AO_SND_SPEEDADJUST_TYPE_E;

 /* the type of Adjust Audio */
typedef struct 
{
    HI_U32                  u32AefId;
    HI_UNF_SND_AEF_TYPE_E   enAefType;
    HI_CHAR                 szName[32];
    HI_CHAR                 szDescription[32];
    HI_BOOL                 bEnable;
} AO_AEF_PROC_ITEM_S;

typedef struct
{
 HI_U32  u32BufPhyAddr;  
 HI_U32  u32BufVirAddr;  
 HI_U32  u32BufSize;
} AO_BUF_ATTR_S;

/**CNcomment:ò??μê?3?ê?D?*/
typedef struct hiHI_TRACK_MMAPBUFATTR_S
{
    HI_U32  u32UserAddr;     /**<Track Buffer Addr*/ /**<CNcomment:Buffer μ??·*/
    HI_U32* pu32ReadPtr;     /**<The Pointer of Buffer Read addr */ /**<CNcomment:Buffer ?áμ??·μ?????*/
    HI_U32* pu32WritePtr;    /**<The Pointer of Buffer write addr */ /**<CNcomment:Buffer D′μ??·μ?????*/
    HI_U32  u32Size;        /**<Buffer size*/ /**<CNcomment:Buffer′óD?*/
} HI_TRACK_MmapBufAttr_S;

typedef struct hiHI_TRACK_MMAPATTR_S
{
    HI_U32 u32BitPerSample;                /**<Data depth*/ /**<CNcomment: êy?Y???í*/
    HI_U32 u32SampleRate;                  /**<samplerate*/ /**<CNcomment:ò??μêy?Y2é?ù?ê*/
    HI_U32 u32Channels;                    /**<Channel*/ /**<Ncomment:ò??μêy?Yéùμàêy*/
    HI_TRACK_MmapBufAttr_S stMmapBuff; /**<Buffer Attribute*/ /**<CNcomment:Buffer ê?D?*/
} HI_TRACK_MmapAttr_S;
typedef struct
{
    /** s32BitPerSample: (PCM) Data depth, and format of storing the output data
          If the data depth is 16 bits, 16-bit word memory is used.
          If the data depth is greater than 16 bits, 32-bit word memory is used, and data is stored as left-aligned data. That is, the valid data is at upper bits.
     */
    /**CNcomment: s32BitPerSample: (PCM) 数据位宽设置. 输出存放格式
          等于16bit:   占用16bit word内存
          大于16bit:   占用32bit word内存, 数据左对齐方式存放(有效数据在高位)
     */
    HI_S32  s32BitPerSample;       /**<Data depth*/ /**<CNcomment: 数据位宽*/
    HI_BOOL bInterleaved;          /**<Whether the data is interleaved*/ /**<CNcomment: 数据是否交织*/
    HI_U32  u32SampleRate;         /**<Sampling rate*/ /**<CNcomment: 采样率*/
    HI_U32  u32Channels;           /**<Number of channels*/ /**<CNcomment: 通道数量*/
    HI_U32  u32PtsMs;              /**<Presentation time stamp (PTS)*/ /**<CNcomment: 时间戳*/
    HI_VIRT_ADDR_T  tPcmBuffer;         /**<Pointer to the buffer for storing the pulse code modulation (PCM) data*/ /**<CNcomment: PCM数据缓冲指针*/
    HI_VIRT_ADDR_T  tBitsBuffer;        /**<Pointer to the buffer for storing the stream data*/ /**<CNcomment: 码流数据缓冲指针*/
    HI_U32  u32PcmSamplesPerFrame; /**<Number of sampling points of the PCM data*/ /**<CNcomment: PCM数据采样点数量*/
    HI_U32  u32BitsBytesPerFrame;  /**<IEC61937 data size*/ /**<CNcomment: IEC61937数据长度*/
    HI_U32  u32FrameIndex;         /**<Frame ID*/ /**<CNcomment: 帧序号 */
	HI_U32  u32IEC61937DataType;      /**<IEC61937 Data Type*/ /**<CNcomment: IEC61937数据类型标识，低8bit为IEC数据类型 */
    //HI_S16  aBitFrameHead[AO_BITSTREAM_HEAD_WORD_NUM * 2]; //lbr head 4 words + hbr head 4 words
} AO_FRAMEINFO_S;

/******************* Audio Effect component ID ************************/

#define HI_AEF_GET_AFLTID_CMD 0x100

#define HI_AEF_SET_OUTBUFADDR_CMD 0x1000

typedef struct hiHI_AEF_INPUTBUF_S
{
    HI_U32   u32BufAddr;             /**<Output, buffer addr*/ /**<CNcomment: */
    HI_U32   u32BufSize;                /**<Input, buffer size*/ /**<CNcomment: */
} HI_AEF_INPUTBUF_S;

typedef struct hiHI_AEF_OUTPUTBUF_S
{
    HI_U32   u32BufAddr;              /**<Output, buffer addr*/ /**<CNcomment: */
    HI_U32   u32BufSize;              /**<Output, buffer size*/ /**<CNcomment: */
    HI_U32   u32MaxBufSizePerFrame;      /**<Input, max frame size*/ /**<CNcomment: */
    HI_U32   u32OutFrameNum;             /**<Input, max frame number*/ /**<CNcomment: */
} HI_AEF_OUTPUTBUF_S;

typedef struct hiHI_AFE_INBUF_PROCESS_S
{
    HI_U32   u32BufOffsetAddr1;             /**<Output, buffer offset addr*/ /**<CNcomment: */
    HI_U32   u32BufOffsetAddr2;             /**<Output, buffer offset addr*/ /**<CNcomment: */
    HI_U32   u32BufRequestSize1;            /**<Output, buffer requeset size*/ /**<CNcomment: */
    HI_U32   u32BufRequestSize2;            /**<Output, buffer requeset size*/ /**<CNcomment: */
    HI_U32   u32RequestSize;
} HI_AFE_INBUF_PROCESS_S;

typedef struct hiHI_AEF_OUTPUT_S
{
    HI_U32 u32PcmOutBuf;
    /**HI_S32* ps32PcmOutBuf;       <Input, pointer to the decoded PCM data.
                                     Note: 1) ps32PcmOutBuf must be 32-word aligned.
                                           2) ps32PcmOutBuf is NULL when the decoder is working in HD_DEC_MODE_THRU mode.\n*/
    /**<CNcomment:IN 指向PCM 解码输出的指针. */

    HI_U32  u32PcmOutBufSize;    /**<Input, size (in byte) of the buffer for storing the decoded PCM data
                                     Note: u32PcmOutBufSize is 0 when the decoder is working in HD_DEC_MODE_THRU mode.\n*/
    /**<CNcomment:IN  PCM 解码输出缓冲区大小. unit:Byte */

    HI_U32  u32PcmOutbytesPerFrame; /**<Output, length of output PCM data is processed in byte.*/ /**<CNcomment:OUT. Pcm 输出byte数 */
    HI_U32  u32OutChannels;           /**<Output, number of output channels.*/ /**<CNcomment:OUT 输出声道数*/
    HI_U32  u32OutBitPerSample; 
    HI_U32  u32OutSampleRate;         /**<Output, output sampling rate.*/ /**<CNcomment:OUT. 输出采样频率*/
    HI_U32  u32FrameIndex;   /**<Output, output frame index.*/ /**<CNcomment:OUT. 输出帧序号*/
} HI_AEF_OUTPUT_S;

/**Configuration parameters required by an HI audio effect for creating devices.*/
/**CNcomment:HI 音效创建设备的配置参数*/
typedef struct hiAEF_OPENPARAM_S
{
    HI_BOOL  bMaster;  /**<be master aflt or not*/ /**<CNcomment:aflt 的主从模式*/
    HI_VOID*            pAudEftPrivateData;/**<Input, pointer to private data*/ /**<CNcomment:IN  指向私有配置结构体的指针*/
    HI_U32              u32AudEftPrivateDataSize;/**<Input, size of the private data. */ /**<CNcomment:IN 私有结构体大小*/
} HI_AEF_OPENPARAM_S;

/**Define the error codes of an audio effect.*/
/**CNcomment:定义audio effect 错误码*/
typedef enum hiAEF_ERRORTYPE_E
{
    AEF_ErrorNone = 0,

    AEF_ErrorInsufficientResources = (HI_S32) 0x80002000,/**<The device fails to be created due to insufficient resources.*/ /**<CNcomment:资源不够，创建设备失败 */

    AEF_ErrorInvalidParameter = (HI_S32) 0x80002001, /**<The input parameter is invalid.*/ /**<CNcomment:输入参数非法 */

    AEF_ErrorStreamCorrupt = (HI_S32) 0x80002002, /**<The effect process fails due to incorrect input streams.*/ /**<CNcomment:输入码流错误，音效处理失败 */

    AEF_ErrorNotEnoughData = (HI_S32) 0x80002003,/**<The effect process ends due to insufficient streams.*/ /**<CNcomment:输入码流不够，退出解码 */

    AEF_ErrorMax = 0x9FFFFFFF
} HI_AEF_ERRORTYPE_E;


/******************* Audio Effect Authorize API ************************/
typedef struct hiAEF_AUTHORIZE_S
{
    const HI_PCHAR szName;/**<Input, description information about an AEF, such as SRS_StudioSound3D or Dolby_Volume. */

    const HI_UNF_SND_AEF_TYPE_E enEffectID;

    const HI_U32 u32Version; /**<Input,  version.*/

    struct hiAEF_AUTHORIZE_S* pstNext;

    /**<CNcomment:隐性客户信息，寄存器可查询，不对外公布 */
    HI_VOID (*GetAuthKey)(HI_U32 *pu32CustomerAuthKey);               /* 128/256bit key */
    
    /**<CNcomment:显性客户信息，proc信息可查询 */
    const HI_PCHAR pszCustomerDescription; /**< detailed information about the user of AEF, less than 64 bytes.*/
} HI_AEF_AUTHORIZE_S;

/******************* Audio Effect component API ************************/
typedef struct 
{
    HI_PCHAR szName;/**<Input, description information about an AEF, such as SRS_StudioSound3D or Dolby_Volume. */

    HI_UNF_SND_AEF_TYPE_E enEffectID;

    HI_U32 u32Version; /**<Input,  version.*/

    const HI_PCHAR pszCustomerDescription; /**< detailed information about the user of AEF, less than 64 bytes.*/

    HI_AEF_ERRORTYPE_E (*AefCreate)(HI_AEF_AUTHORIZE_S *pstAuthEntry, HI_VOID *pstAdvAttr, HI_HANDLE *phAef);

    HI_AEF_ERRORTYPE_E (*AefDestroy)(HI_HANDLE hAef);

    HI_AEF_ERRORTYPE_E (*AefSetEnable)(HI_HANDLE hAef, HI_BOOL bEnable);

    HI_AEF_ERRORTYPE_E (*AefGetEnable)(HI_HANDLE hAef, HI_BOOL * pbEnable);
    
    HI_AEF_ERRORTYPE_E (*AefSetConfig)(HI_HANDLE hAef, HI_U32 u32ConfigIndex, const HI_VOID *pConfigStructure);

    HI_AEF_ERRORTYPE_E (*AefGetConfig)(HI_HANDLE hAef, HI_U32 u32ConfigIndex, HI_VOID *pConfigStructure);

    HI_AEF_ERRORTYPE_E (*AefSetParameter)(HI_HANDLE hAef, HI_U32 u32ParamIndex, const HI_VOID *pParameterStructure);

    HI_AEF_ERRORTYPE_E (*AefGetParameter)(HI_HANDLE hAef, HI_U32 u32ParamIndex, HI_VOID *pParameterStructure);

    HI_AEF_ERRORTYPE_E (*AefGetMaxPcmInSize)(HI_HANDLE hAef, HI_U32 *pu32InSizes);

    HI_AEF_ERRORTYPE_E (*AefGetMaxPcmOutSize)(HI_HANDLE hAef, HI_U32 *pu32OutSizes);
    
    HI_AEF_ERRORTYPE_E (*AefInbufInit)(HI_HANDLE hAef, HI_AEF_INPUTBUF_S* pstInBufAttr);

    HI_AEF_ERRORTYPE_E (*AefInBufDeInit)(HI_HANDLE hAef);

    HI_AEF_ERRORTYPE_E (*AefOutbufInit)(HI_HANDLE hAef, HI_AEF_OUTPUTBUF_S* pstOutBufAttr);

    HI_AEF_ERRORTYPE_E (*AefOutBufDeInit)(HI_HANDLE hAef);

    HI_AEF_ERRORTYPE_E (*AefGetBuf)(HI_HANDLE hAef, HI_AFE_INBUF_PROCESS_S* pstGetBuf);

    HI_AEF_ERRORTYPE_E (*AefPutBuf)(HI_HANDLE hAef, HI_AFE_INBUF_PROCESS_S* pstPutBuf);

    HI_AEF_ERRORTYPE_E (*AefReceiveFrame)(HI_HANDLE hAef, HI_AEF_OUTPUT_S* pstAOut);

    HI_AEF_ERRORTYPE_E (*AefReleaseFrame)(HI_HANDLE hAef, HI_U32 u32FrameIndex);

    HI_AEF_ERRORTYPE_E (*AefSetEosFlag)(HI_HANDLE hAef, HI_BOOL bEosFlag);
} HI_AEF_COMPONENT_S;


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

 #endif
