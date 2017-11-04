#ifndef __DRV_VDEC_EXT_H__
#define __DRV_VDEC_EXT_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include "hi_type.h"
#include "drv_vdec_ioctl.h"
#include "hi_drv_vdec.h"
#include "hi_mpi_vdec.h"

#ifdef HI_PRE_ALLOC_VDEC_VDH_MMZ
#define PRE_ALLOC_VDEC_VDH_MMZ (1)
#else
#define PRE_ALLOC_VDEC_VDH_MMZ (0)
#endif
#define PRE_ALLOC_VDEC_SCD_MMZ (0)
#define PRE_ALLOC_VDEC_ESBUF_MMZ (0)

/**Compress Info*/
typedef struct hiVDEC_COMPRESS_INFO_S
{
    HI_U32 u32CompressFlag;
    HI_S32 s32CompFrameHeight;
    HI_S32 s32CompFrameWidth;
    HI_U32 u32HeadOffset;            /**<DNRInfo head offset */
    HI_U32 u32YHeadAddr;             /**<Y head info when compress is used */
    HI_U32 u32CHeadAddr;             /**<C head info when compress is used */
    HI_U32 u32HeadStride;            /**<YC head info stride when compress is used */
}HI_VDEC_COMPRESS_INFO_S;

/**VC1 Range Info*/
typedef struct hiVDEC_VC1_RANGE_INFO_S
{
    HI_U8 u8PicStructure;     /**< 0: frame, 1: top, 2: bottom, 3: mbaff, 4: field pair */
    HI_U8 u8PicQPEnable;
    HI_U8 u8ChromaFormatIdc;  /**< 0: yuv400, 1: yuv420 */
    HI_U8 u8VC1Profile;
    
    HI_S32 s32QPY;
    HI_S32 s32QPU;
    HI_S32 s32QPV;
    HI_S32 s32RangedFrm;
    
    HI_U8 u8RangeMapYFlag;
    HI_U8 u8RangeMapY;
    HI_U8 u8RangeMapUVFlag;
    HI_U8 u8RangeMapUV;
    HI_U8 u8BtmRangeMapYFlag;
    HI_U8 u8BtmRangeMapY;
    HI_U8 u8BtmRangeMapUVFlag;
    HI_U8 u8BtmRangeMapUV;
}HI_VDEC_VC1_RANGE_INFO_S;

/**BTL Info*/
typedef struct hiVDEC_BTL_INFO_S
{
    HI_U32 u32BTLImageID;
    HI_U32 u32Is1D;         /**< 0:2D, 1:1D */
    HI_U32 u32IsCompress;

    HI_U32 u32DNROpen;      /**< 0: DNR close, 1: DNR open */
    HI_U32 u32DNRInfoAddr;  /**< DNR info from BTL */
    HI_U32 u32DNRInfoStride;/**< DNR info stride from BTL */
}HI_VDEC_BTL_INFO_S;

typedef struct hiVDEC_PRIV_FRAMEINFO_S
{
    HI_U32                      u32BeVC1;
	HI_VDEC_COMPRESS_INFO_S     stCompressInfo;
    HI_VDEC_VC1_RANGE_INFO_S    stVC1RangeInfo;
    HI_VDEC_BTL_INFO_S          stBTLInfo;
    HI_UNF_VCODEC_TYPE_E        entype;
    HI_U32                      u32SeqFrameCnt;     /**<Picture ID in a video sequence. The ID of the first frame in each sequence is numbered 0*/ /**<CNcomment: 视频序列中的图像编号，每个序列中第一帧编号为0*/
	HI_U32                      u32DispTime;        /**<PVR Display time*/
	HI_U32                      image_id;
	HI_U32                      image_id_1;
	HI_S32                      s32InterPtsDelta;   /*interleaved source, VPSS module swtich field to frame, need to adjust pts*/
	HI_U8                       u8Repeat;           /**<Times of playing a video frame*/ /**<CNcomment: 视频帧播放次数.*/
    HI_U8                       u8EndFrame;         /**<0 Not end frame; 1 Current frame is the end frame; 2 Prior frame is the end frame */
    HI_U8                       u8TestFlag;         /**<VDEC_OPTMALG_INFO_S.Rwzb*/ 
    HI_U8                       u8Marker;           /**<Bit0: 1 Resolution change 
                                                        Bit1: 1 close deinterlace 
                                                    */
    HI_U32                      u32OriFrameRate;  /* 1000*rate */ 
	HI_S32                      s32GopNum;
	HI_S32                      s32FrameFormat;
	HI_S32                      s32TopFieldFrameFormat;
	HI_S32                      s32BottomFieldFrameFormat;
	HI_S32                      s32FieldFlag;
    HI_U32                      u32Usertag;
}HI_VDEC_PRIV_FRAMEINFO_S;


typedef HI_S32  (*FN_VDEC_RecvFrm)(HI_S32, HI_DRV_VIDEO_FRAME_S *);
typedef HI_S32  (*FN_VDEC_RlsFrm)(HI_S32, HI_DRV_VIDEO_FRAME_S *);
typedef HI_S32  (*FN_VDEC_RlsFrmWithoutHandle)(HI_S32, HI_DRV_VIDEO_FRAME_S *);
typedef HI_S32  (*FN_VDEC_BlockToLine)(HI_S32, HI_DRV_VDEC_BTL_S *);
typedef HI_S32  (*FN_VDEC_GetEsBuf)(HI_S32,  VDEC_ES_BUF_S *);
typedef HI_S32  (*FN_VDEC_PutEsBuf)(HI_S32,  VDEC_ES_BUF_S *);
typedef HI_S32  (*FN_VDEC_SetFrmPackingType)(HI_HANDLE hVdec,HI_UNF_VIDEO_FRAME_PACKING_TYPE_E eFramePackType);
typedef HI_S32  (*FN_VDEC_GetFrmPackingType)(HI_HANDLE hVdec,HI_UNF_VIDEO_FRAME_PACKING_TYPE_E *penFramePackType);
typedef HI_S32  (*FN_VDEC_GetVideoFrameInfo)(HI_HANDLE hVdec, HI_UNF_AVPLAY_VIDEO_FRAME_INFO_S *pstVideoFrameInfo);
typedef HI_S32  (*FN_VDEC_FDMNGEnable)(HI_HANDLE hVdec, HI_BOOL bEnable);
typedef HI_S32  (*FN_VDEC_FDMNGQueryResult)(HI_HANDLE hVdec, HI_DRV_FRAME_TYPE_E *pEframeType);
typedef HI_S32 (*FN_VDEC_Chan_VOAcqFrame)(HI_HANDLE, HI_DRV_VIDEO_FRAME_S*);
typedef HI_S32 (*FN_VDEC_Chan_VORlsFrame)(HI_HANDLE, HI_DRV_VIDEO_FRAME_S*);
typedef HI_S32 (*FN_VDEC_Chan_VOChangeWinInfo)(HI_HANDLE,HI_DRV_WIN_PRIV_INFO_S*);
typedef HI_S32 (*FN_VDEC_Chan_AcquireUsrData)(HI_HANDLE,HI_UNF_VIDEO_USERDATA_TYPE_E,HI_DRV_VDEC_USERDATA_S*);
typedef HI_S32 (*FN_VDEC_Chan_ReleaseUsrData)(HI_HANDLE,HI_UNF_VIDEO_USERDATA_TYPE_E,HI_DRV_VDEC_USERDATA_S*);


typedef struct tagVDEC_EXPORT_FUNC_S
{
    FN_VDEC_RecvFrm             pfnVDEC_RecvFrm;
    FN_VDEC_RlsFrm              pfnVDEC_RlsFrm;
    FN_VDEC_RlsFrmWithoutHandle pfnVDEC_RlsFrmWithoutHandle;
    FN_VDEC_BlockToLine         pfnVDEC_BlockToLine;
    FN_VDEC_GetEsBuf            pfnVDEC_GetEsBuf;
    FN_VDEC_PutEsBuf            pfnVDEC_PutEsBuf;
	FN_VDEC_SetFrmPackingType   pfnVDEC_SetFrmPackingType;
	FN_VDEC_GetFrmPackingType   pfnVDEC_GetFrmPackingType;
	FN_VDEC_GetVideoFrameInfo   pfnVDEC_GetVideoFrameInfo;
	FN_VDEC_FDMNGEnable         pfnVDEC_FDMNGEnable;
	FN_VDEC_FDMNGQueryResult    pfnVDEC_FDMNGQueryResult;
    FN_VDEC_Chan_VOAcqFrame   pfnVDEC_VOAcqFrame;
    FN_VDEC_Chan_VORlsFrame    pfnVDEC_VORlsFrame;
    FN_VDEC_Chan_VOChangeWinInfo    pfnVDEC_VOSendWinInfo;
	FN_VDEC_Chan_AcquireUsrData     pfnVDEC_AcqUsrData;
	FN_VDEC_Chan_ReleaseUsrData     pfnVDEC_RelUsrData;
}VDEC_EXPORT_FUNC_S;


HI_S32 VDEC_DRV_ModInit(HI_VOID);
HI_VOID VDEC_DRV_ModExit(HI_VOID);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __DRV_VDEC_EXT_H__ */

