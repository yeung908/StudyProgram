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
 * $RCSfile: mtpmx.h,v $
 * $Revision: #1 $
 *---------------------------------------------------------------------------*/

/** @file mtpmx.h
 *  This header file declares exported APIs of PMX module.
 */

#ifndef MT_PMX_H
#define MT_PMX_H

#ifdef __cplusplus
extern "C" {
#endif
//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------

#include "mttype.h"

//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------

#define MTPMX_MAIN 	0 // VDP1
#define MTPMX_PIP  	1 // VDP2
#define MTPMX_OSD1 	3 // VDP3
#define MTPMX_OSD2 	4 // VDP4
#define MTPMX_OSD3 	2 // VDP5
#define MTPMX_ALPHA 	5 // MIX alpha
#define MTPMX_AL_11 	5 // OSD_MIX_AL_11
#define MTPMX_AL_12 	6 // OSD_MIX_AL_12
#define MTPMX_AL_2 	7 // OSD_MIX_AL_2


#define MTPMX_ORDER1 0 // top plane
#define MTPMX_ORDER2 1
#define MTPMX_ORDER3 2
#define MTPMX_ORDER4 3 // bottom plane

#define MTPMX_MAX_PLANE_NS 8 
//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------
/**Plane info structure
*/
typedef struct
{
    UINT32  u4PanelWidth;
    UINT32  u4PanelHeight;
    UINT32  u4PixelClk60Hz;
    UINT32  u4VClkMax;
    UINT32  u4VClkMin;
    UINT32  u4PanelPhysicalWidth;
    UINT32  u4PanelPhysicalHeight;
}   MTPMX_PALEL_INFO_T;

/**
  * Panel interface
  */
 typedef enum {
	MTPMX_DISP_PANEL_LVDS = 0,
	MTPMX_DISP_PANEL_HSLVDS,
 	MTPMX_DISP_PANEL_EPI,
 	MTPMX_DISP_PANEL_Vx1,
 	MTPMX_DISP_PANEL_MAX
 } MTPMX_PANEL_INTERFACE_T;

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------

/** init pmx driver and hardware status
 *  @param  VOID
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_Init(VOID);

/** get plane z-order
 *  @param  u4PlaneId               plane id:{MTPMX_MAIN, MTPMX_PIP, MTPMX_OSD1, MTPMX_OSD2}
 *  @param  pu4PlaneOrder           plane order:{MTPMX_ORDER1/2/3/4}
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_GetPlaneOrder(UINT32 u4PlaneId, UINT32* pu4PlaneOrder);

/** set plane z-order
 *  @param  u4PlaneId               plane id:{MTPMX_MAIN, MTPMX_PIP, MTPMX_OSD1, MTPMX_OSD2}
 *  @param  u4PlaneOrder            plane order:{MTPMX_ORDER1/2/3/4}
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *   Pmx can control the order of Video/Graphic planes and merge into one to output stage.
 *   The sources of Pmx are Main, PIP, OSD1, OSD2.
 *   For example, through pmx, we can assign OSD1 as top-most plane, and then OSD2, PIP, and Main as the bottom plane.
 */
EXTERN MT_RESULT_T MTPMX_SetPlaneOrder(UINT32 u4PlaneId, UINT32 u4PlaneOrder);

/** set plane z-order array
 *  @param  pu4PlaneOrder               plane order array addr
 *  @param  u4PlaneOrder            plane order:{MTPMX_ORDER1/2/3/4}
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *   Pmx can control the order of Video/Graphic planes and merge into one to output stage.
 *   The sources of Pmx are Main, PIP, OSD1, OSD2.
 *   In mt5395, OSD planes must be on top of video planes.
 *   For example, through pmx, we can assign OSD2 as top-most plane, and then OSD1, PIP, and Main as the bottom plane.
 *   Then the plane order array will be set as 
 *   const UINT32 au4PlaneArray[4] = { PMX_OSD2, PMX_OSD1, MTPMX_PIP, MTPMX_MAIN };
 */
EXTERN MT_RESULT_T MTPMX_SetPlaneOrderArray(UINT32* pu4PlaneOrder);

/** Set osd & video mix alpha
 *	@param  osd & video layout value[0,1,2,3]
 *	@param  alpha	
 *	@retval MTR_OK					Success
 *	@retval MTR_NOT_OK				Fail
 */
EXTERN MT_RESULT_T MTPMX_SetMixAlpha(UINT32 ui4_layout,UINT32* pu4PlaneOrder);

/**Get plane order
*@param pu4PlaneOrder           keep plane order information
*@retval MTR_OK                 Success
*@retval MTR_NOT_OK             Fail
*/
EXTERN MT_RESULT_T MTPMX_GetPlaneOrderArray(UINT32* pu4PlaneOrder);

/** set pmx background color, HW will update color on next vsync after AP set
 *  @param  u4BgColor               background color(0xrrggbb)
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_SetBg(UINT32 u4BgColor);

/** set pmx background color
 *  @param  u4BgColor               mute color(0xrrggbb)
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_SetBlk(UINT32 u4BlkColor);

/** setup alpha value for video plane
 *  @param  u4PlaneId               plane id:{MTPMX_MAIN, MTPMX_PIP}
 *  @param  u1Alpha                 alpha value(0~255)
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_SetAlpha(UINT32 u4PlaneId, UINT8 u1Alpha);


/** mute all plane
 *  @param  fgMute                  mute=TRUE/unmute=FALSE
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_SetAllMute(BOOL fgMute);

/** Select panel 
 *  @param  u4PanelIndex             index of panel
 *  @retval MTR_OK                  Success
 */
EXTERN MT_RESULT_T MTPMX_PANEL_Select(UINT32 u4PanelIndex);

/** support panel dynamic change resolution
 *  @param  fgEnable                enable=TRUE/disable=FALSE
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_DYNAMIC_CHG(BOOL fgEnable);
/** get panel resolution
 *  @param  u4Width                 panel width (pixel
 *  @param  u4Height                panel height (line)
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_GetResolution(UINT32* pu4Width, UINT32* pu4Height);

/** output frame rate control (50/60/... Hz)
 *  @param  u4FrameRate             output frame rate
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 *  @retval MTR_NO_SUPPORT          Frame no support
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetFrameRate(UINT32 u4FrameRate);


/** get current output frame rate
 *  @param  pu4FrameRate            current output frame rate
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_GetFrameRate(UINT32* pu4FrameRate);


/**
 * @brief  MTPMX_PANEL_SetFilmMode(BOOL fgFilmOnOff)
 *       	if film mode on, input 24 => output 48
 *      	else input 24=> output 60
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetFilmMode(BOOL fgFilmOnOff);


/**
 * @brief  MTPMX_PANEL_GetFilmMode(BOOL *fgFilmOnOff)
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_GetFilmMode(BOOL *fgFilmOnOff);


/** enable LVDS power
 *  @param  fgEnable                enable=TRUE/disable=FALSE
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_EnableLVDSPower(BOOL fgEnable);


/** enable backlight power
 *  @param  fgEnable                enable=TRUE/disable=FALSE
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_EnableBacklightPower(BOOL fgEnable);


/** enable LVDS signal
 *  @param  fgEnable                enable=TRUE/disable=FALSE
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_EnableLVDSSignal(BOOL fgEnable);

/** enable Vx1 signal
 *  @param  fgEnable                enable=TRUE/disable=FALSE
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_EnableVByOneSignal(BOOL fgEnable);

/** set LVDS driving current
 *  @param  u4Current               driving current (2~15 mA)
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetDrivingCurrent(UINT32 u4Current);

/** Set panel back light dimming
 *  @param  u4Frequency           
 *  @param  u4Dimming               
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetBackltDimming(UINT32 u4Frequency, UINT32 u4Dimming);

/** Panel on/off full sequence
 *  @param  fgEnable               TRUE: Pnael on, FALSE: Panel off
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_PowerSequence(BOOL fgEnable);

/** Set LVDS spread spectrum
 *  @param  u4Period               period(us)
 *  @param  u4Range               range(0.1%)
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_SetSpreadSpectrum(UINT32 u4Period, UINT32 u4Range);

/** enable TV encoder
 *  @param  fgEnable                enable=TRUE/disable=FALSE
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_TVE_Enable(BOOL fgEnable);

/** Sync lock / Sync free-run control
 *  @param  fgEnable            TRUE: lock, FALSE: free-run
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
*/
EXTERN MT_RESULT_T MTPMX_PANEL_EnableSyncLock(BOOL fgEnable);

/** get current lock status
 *  @param  pfgLock            current lock status
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_GetLockStatus(BOOL *pfgLock);

/** Set Panel 3D Mode
 *  @param  u4Mode               1: 3D on, 0: 3D off
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_Set3DMode(UINT32 u4Mode);

/**
 * Get LR info of output (LVDS stage) 
 *
 * @param pu4Info LR info
 */
EXTERN MT_RESULT_T MTPMX_3DTV_GetOutputLR(UINT32 *pu4Info);

/**
 * Set LR polarity of output (LVDS stage) 
 *
 * @param u4LRPolarity LR polarity
 */
EXTERN MT_RESULT_T MTPMX_SetLRPolarity(UINT32 u4Polarity);

/**
 * Set panel display type 
 *
 * @param u4Display panel display type
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetDisplayType(UINT32 u4DisplayType);

/**
 * Get panel display type 
 *
 * @param peDisplayType panel display type
 */
EXTERN MT_RESULT_T MTPMX_PANEL_GetDisplayType(MTPMX_PANEL_INTERFACE_T* peDisplayType);

/**
 * Set panel color depth
 * @param u1BitRes: 0: 8 bits/1: 10 bit
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetColorDepth(UINT8 u1BitRes);

/**
 * Set lvds format
 * @param u1Format: 0:ns/1: jeida
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetLVDSSelect(UINT8 u1Format);

/**
 * Set lvds odd/even swap
 * @param u1Swap: 0:normal/1: swap
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetLVDSSwap(BOOL fgEnable);

/**
 * Set PCB lvds odd/even swap
 * @param u1Swap: 0:normal/1: swap
 */
EXTERN  MT_RESULT_T MTPMX_PANEL_SetPCBLVDSSwap(BOOL fgEnable);


/** Set panel resolution
 *  @param  pu4Width                 panel width (pixel)
 *  @param  pu4Height                panel height (line)
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetResolution(UINT32 pu4Width, UINT32 pu4Height);

 /**
 * Set lvds mode
 * @param u1Mode: 0:single/1: dual
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetLVDSPixel(UINT8 u1Mode);

/** Set panel vertical sync width
 *  @param  u2Vsync48Hz                vtotal 48hz
 *  @param  u2Vsync50Hz                vtotal 50hz
 *  @param  u2Vsync60Hz                vtotal 60hz
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetVertSyncWidth(UINT16 u2Vsync48Hz, UINT16 u2Vsync50Hz, UINT16 u2Vsync60Hz);

/** Set panel horizontal sync width
 *  @param  u2Hsync48Hz                htotal 48hz
 *  @param  u2Hsync50Hz                htotal 50hz
 *  @param  u2Hsync60Hz                htotal 60hz
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetHorizSyncWidth(UINT16 u2Hsync48Hz, UINT16 u2Hsync50Hz, UINT16 u2Hsync60Hz);

/** Set panel horizontal back porch
 *  @param  u2HbackPorch48Hz                Htotal 48hz
 *  @param  u2HbackPorch50Hz                Htotal 50hz
 *  @param  u2HbackPorch60Hz                Htotal 60hz
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetHorizBackPorch(UINT16 u2HbackPorch48Hz, UINT16 u2HbackPorch50Hz, UINT16 u2HbackPorch60Hz);

 /**
 * Set horizontal period
 * @param u2Htotal Htotal
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetHorizontalPeriod(UINT16 u2Htotal);

/** Set panel vertical period
 *  @param  u2Vtotal48Hz                vtotal 48hz
 *  @param  u2Vtotal50Hz                vtotal 50hz
 *  @param  u2Vtotal50Hz                vtotal 60hz
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetVerticalPeriod(UINT16 u2Vtotal48Hz, UINT16 u2Vtotal50Hz, UINT16 u2Vtotal60Hz);

/** Set panel vertical back porch
 *  @param  u2VbackPorch48Hz                vtotal 48hz
 *  @param  u2VbackPorch50Hz                vtotal 50hz
 *  @param  u2VbackPorch60Hz                vtotal 60hz
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_SetVertBackPorch(UINT16 u2VbackPorch48Hz, UINT16 u2VbackPorch50Hz, UINT16 u2VbackPorch60Hz);

/**Get current panel index
*@param pu4Index                     keep current panel index information
*@retval MTR_OK                      Success.
*/
EXTERN MT_RESULT_T MTPMX_PANEL_GetCurrentIndex(UINT32* pu4Index);

/**Force frame rate operation
*@param u1FrameRate                  rate value
*retval MTR_OK                       Success.
*/
EXTERN MT_RESULT_T MTPMX_PANEL_ForceFrameRate(UINT8 u1FrameRate);

/**Set 3D enable
*@param bOnOff                       enable flag
*retval MTR_OK                       Success
*/
EXTERN MT_RESULT_T MTPMX_PANEL_Set3DSyncOut(UINT8 bOnOff);

/**Set second channel on/off
*@param bOnOff                       enable/disable flag
*retval MTR_OK                       Success
*/
EXTERN MT_RESULT_T MTPMX_PANEL_Set2ndChannelOnOff(UINT8 bOnOff);

/**Set 3D glass delay
*@param u2Delay                     delay value
*retval MTR_OK                      Success
*/
EXTERN MT_RESULT_T MTPMX_PANEL_Set3DSyncOutDelay(UINT16 u2Delay);

/** init tcon driver and hardware status
 *  @param  VOID
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_TCONInit(VOID);

/** enable TCON block
 *  @param  fgEnable                enable=TRUE/disable=FALSE
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_TCONEnable(BOOL fgEnable);

/**Set Tcon power
*@param eTconPowSeq                 video tcon power seqeue
*@param fgEnable                    enable/disable flag
*@retval MTR_OK                     Success
*/
EXTERN MT_RESULT_T MTPMX_PANEL_TCONPower(UINT32 eTconPowSeq, BOOL fgEnable);

/**Set tcon table sel
*@param eTconTableSel              sel value
*@retval MTR_OK                    Success.
*/
EXTERN MT_RESULT_T MTPMX_PANEL_TCON_TABLE_SEL(UINT32 eTconTableSel);

/**Write tcon register
*@param u32Address                tcon register
*@param u32Data                    write data
*@retval MTR_OK                     Success
*/
EXTERN MT_RESULT_T MTPMX_PANEL_TCONRegWrite(UINT32 u32Address, UINT32 u32Data);

/**Read tcon register
*@param u32Address                tcon register
*@param u32Data                    data value
*@retval MTR_OK                     Success
*/
EXTERN MT_RESULT_T MTPMX_PANEL_TCONRegRead(UINT32 u32Address, UINT32 *pu32Data);

/** Show Pattern
 *  @param  u1Enable                1:enable or 0:disable
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_ShowPattern(UINT8 u1Enable);

/** Get Panel Info
 *  @param  prInfo                 Panel related information
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_PANEL_GetPanelInfo(MTPMX_PALEL_INFO_T* prInfo);

/** Get Panel Type
 *  @param  pu4Type                 Panel Type:0 (2D), 1(PR), 2(Shutter)
 *  @retval MTR_OK                  Success
 *  @retval MTR_NOT_OK              Fail
 */
EXTERN MT_RESULT_T MTPMX_Get_Panel_Type(UINT32 *pu4Type);

/**Init Panel index
*@param none
*@retval MTR_OK                    Success
*/
EXTERN MT_RESULT_T MTPMX_PANEL_LoadPanelIndex(void);

/**Set GFX type
*@param  u4Type                    GFX type: PANEL_TYPE_4K1K_60, PANEL_TYPE_4K2K_30
*@retval MTR_OK                    Success
*/
EXTERN MT_RESULT_T MTPMX_PANEL_SetGFXType(UINT32 u4Type);

/**Set GFX frame ready
*@retval MTR_OK                    Success
*/
EXTERN MT_RESULT_T MTPMX_PANEL_SetGFXFrameReady(void);

#ifdef __cplusplus
}
#endif

#endif //MT_PMX_H
