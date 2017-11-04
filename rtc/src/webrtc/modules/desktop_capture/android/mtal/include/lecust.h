/*-----------------------------------------------------------------------------
 * $RCSfile: lecust.h,v $
 * $Revision: #1 $
 * $Date: 2014/11/18 $
 * $Author: dtvbm11 $
 *
 * Description: lenovo custom function
 *
 *---------------------------------------------------------------------------*/

#ifndef _LECUST_H_
#define _LECUST_H_

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

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Macro definitions (IC independant)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Public functions
//-------------------------------------------------------------------------

/** 
 *  LE_MOD_GET_GROUP_SIZE() to get current model group size
 *  @param pSize	pointer to put the model group size
 *  @retval MT_RESULT_T MTR_OK for ok, otherwise for failure
 */
EXTERN MT_RESULT_T LE_MOD_GET_GROUP_SIZE(UINT32 *pSize);

/**
 *  LE_MOD_GET_MODEL_IDX_ARR() to get model index array of current model group
 *  @param uiIdx	ui index of current model
 *  @param pSize	pointer to put size of current model group
 *  @param pArr		pointer to put model index array
 */
EXTERN MT_RESULT_T LE_MOD_GET_MODEL_IDX_ARR(UINT32 uiIdx, UINT32 *pSize, UINT32 *pArr);

/**
 *  LE_MOD_GET_PANEL_IDX_ARR() to get panel index array of current model group
 *  @param uiIdx	ui index of current model
 *  @param pSize	pointer to put size of current model group
 *  @param pArr		pointer to put panel index array
 */
EXTERN MT_RESULT_T LE_MOD_GET_PANEL_IDX_ARR(UINT32 uiIdx, UINT32 *pSize, UINT32 *pArr);

/**
 *  LE_MOD_GET_PANEL_INFOSTR() to get panel info description of specified panel
 *  @param panelIdx	panel index
 *  @param pBuf		pointer to put panel description
 *  @param pSize	pointer to put string length of panel description
 */
EXTERN MT_RESULT_T LE_MOD_GET_PANEL_INFOSTR(UINT32 panelIdx, UINT32 *pBuf, UINT32 *pSize);

/**
 *  LE_MOD_GET_PANEL_SIZE() to get panel size of specified model
 *  @param uiIdx	ui index of model
 *  @param pSize	pointer to put panel size
 */
EXTERN MT_RESULT_T LE_MOD_GET_PANEL_SIZE(UINT32 uiIdx, UINT32 *pSize);

/**
 *  LE_MOD_GET_MODEL_IDX() to get model index of specified model
 *  @param uiIdx	ui index of model
 *  @param pIdx		pointer to put model index
 */
EXTERN MT_RESULT_T LE_MOD_GET_MODEL_IDX(UINT32 uiIdx, UINT32 *pIdx);

/**
 *  LE_MOD_GET_MODEL_UIIDX() to get ui index of current model
 *  @param pIdx		pointer to put ui index
 */
EXTERN MT_RESULT_T LE_MOD_GET_MODEL_UIIDX(UINT32 *pIdx);

/**
 *  LE_MOD_GET_MODEL_STR() to get model name string of specified model
 *  @param index	ui index of specified model
 *  @param pBuf		pointer to put model name string
 *  @param pSize	pointer to put string length of model name string
 */
EXTERN MT_RESULT_T LE_MOD_GET_MODEL_STR(UINT32 index, CHAR *pBuf, UINT32 *pSize);

/**
 *  LE_MOD_SET_MODEL() to set current model to specified model
 *  @param index	ui index of specified model
 */
EXTERN MT_RESULT_T LE_MOD_SET_MODEL(UINT32 index);

/**
 *  LE_MOD_GET_FEATURE_SIZE() to get size of feature table
 *  @param pSize	pointer to put size of feature table
 */
EXTERN MT_RESULT_T LE_MOD_GET_FEATURE_SIZE(UINT32 *pSize);

/**
 *  LE_MOD_GET_FEATURE_IDX() to get feature index of current feature
 *  @param pIdx		pointer to put feature index of current feature
 */
EXTERN MT_RESULT_T LE_MOD_GET_FEATURE_IDX(UINT32 *pIdx);

/**
 *  LE_MOD_GET_FEATURE_STR() to get feature description of specified feature
 *  @param idx		index of feature
 *  @param pBuf		pointer to put feature description
 *  @param pLen		pointer to put string length of feature description
 */
EXTERN MT_RESULT_T LE_MOD_GET_FEATURE_STR(UINT32 idx, CHAR *pBuf, UINT32 *pLen);

/**
 *  LE_MOD_SET_FEATURE() to change current feature
 *  @param index	index of specified feature
 */
EXTERN MT_RESULT_T LE_MOD_SET_FEATURE(UINT32 index);

/**
 *  LE_MOD_GET_SMT_FACTORY_SIZE() to get size of smt factory table
 *  @param pSize	pointer to put size of smt factory table
 */
EXTERN MT_RESULT_T LE_MOD_GET_SMT_FACTORY_SIZE(UINT32 *pSize);

/**
 *  LE_MOD_GET_SMT_FACTORY_IDX() to get index of current smt factory
 *  @param pIdx		pointer to put index of current smt factory
 */
EXTERN MT_RESULT_T LE_MOD_GET_SMT_FACTORY_IDX(UINT32 *pIdx);

/**
 *  LE_MOD_GET_SMT_FACTORY_STR() to get smt factory name of specified factory
 *  @param idx		index of specified factory
 *  @param pBuf		pointer to put smt factory name
 *  @param pLen		pointer to put length of smt factory name
 */
EXTERN MT_RESULT_T LE_MOD_GET_SMT_FACTORY_STR(UINT32 idx, CHAR *pBuf, UINT32 *pLen);

/**
 *  LE_MOD_SET_SMT_FACTORY() to change smt factory
 *  @param idx		index of specified factory
 */
EXTERN MT_RESULT_T LE_MOD_SET_SMT_FACTORY(UINT32 idx);

/**
 *  LE_MOD_GET_ODM_FACTORY_SIZE() to get size of odm factory table
 *  @param pSize	pointer to put size of odm factory table
 */
EXTERN MT_RESULT_T LE_MOD_GET_ODM_FACTORY_SIZE(UINT32 *pSize);

/**
 *  LE_MOD_GET_ODM_FACTORY_IDX() to get index of current odm factory
 *  @param pIdx		pointer to put index of current odm factory
 */
EXTERN MT_RESULT_T LE_MOD_GET_ODM_FACTORY_IDX(UINT32 *pIdx);

/**
 *  LE_MOD_GET_ODM_FACTORY_STR() to get odm factory name of specified factory
 *  @param idx		index of specified factory
 *  @param pBuf		pointer to put odm factory name
 *  @param pLen		pointer to put string length of odm factory name
 */
EXTERN MT_RESULT_T LE_MOD_GET_ODM_FACTORY_STR(UINT32 idx, CHAR *pBuf, UINT32 *pLen);

/**
 *  LE_MOD_SET_ODM_FACTORY() to change odm factory
 *  @param idx		index of odm facotry
 */
EXTERN MT_RESULT_T LE_MOD_SET_ODM_FACTORY(UINT32 idx);

/**
 *  LE_MOD_GET_AUD_AMP_SIZE() to get size of audio amplifier table
 *  @param pSize	pointer to put size of audio amplifier table
 */
EXTERN MT_RESULT_T LE_MOD_GET_AUD_AMP_SIZE(UINT32 *pSize);

/**
 *  LE_MOD_GET_AUD_AMP_IDX() to get index of current audio amplifier
 *  @param pIdx		pointer to put index of current audio amplifier
 */
EXTERN MT_RESULT_T LE_MOD_GET_AUD_AMP_IDX(UINT32 *pIdx);

/**
 *  LE_MOD_GET_AUD_AMP_STR() to get description of specified audio amplifier
 *  @param idx		index of specified audio amplifier
 *  @param pBuf		pointer to put description string
 *  @param pLen		pointer to put length of description string
 */
EXTERN MT_RESULT_T LE_MOD_GET_AUD_AMP_STR(UINT32 idx, CHAR *pBuf, UINT32 *pLen);

/**
 *  LE_MOD_SET_AUD_AMP() to change audio amplifier
 *  @param idx		index of audio amplifier
 */
EXTERN MT_RESULT_T LE_MOD_SET_AUD_AMP(UINT32 idx);

/**
 *  LE_MOD_GET_FLIP_MIRROR() to get flip mirror of specified model
 *  @param uiIdx	ui index of model
 *  @param pFlip	pointer to put flip status
 *  @param pMirror	pointer to put mirror status
 */
EXTERN MT_RESULT_T LE_MOD_GET_FLIP_MIRROR(UINT32 uiIdx, UINT32 *pFlip, UINT32 *pMirror);

/**
 *  LE_MOD_WRITE_SERIAL() to write serial number into eeprom
 *  @param pBuf		string buffer of serial number
 *  @param len		length of serial number
 */
EXTERN MT_RESULT_T LE_MOD_WRITE_SERIAL(CHAR *pBuf, UINT32 len);

/**
 *  LE_MOD_READ_SERIAL() to read serial number from eeprom
 *  @param pBuf		pointer to put serial number
 *  @param len		length of buff
 */
EXTERN MT_RESULT_T LE_MOD_READ_SERIAL(CHAR *pBuf, UINT32 len);

/**
 *  LE_MOD_GET_PANEL_NAME() to get current model panel name
 *  @param uiIdx	model ui index
 *  @param pBuf		string buffer of panel name
 *  @param len		length of buffer
 */
EXTERN MT_RESULT_T LE_MOD_GET_PANEL_NAME(UINT32 uiIdx, CHAR *pBuf, UINT32 len);

/**
 *  LE_MOD_CHECK_MAC_CHKSUM() to check MAC checksum status
 *  @param num		number of MAC address to check
 *  @param pChkOk	buffer to put checksum verify result
 */
EXTERN MT_RESULT_T LE_MOD_CHECK_MAC_CHKSUM(UCHAR num, UCHAR *pChkOk);

/**
 *  LE_MOD_GET_HDMI_PORT_NUM() to get number of HDMI port of current model
 *  @param pNum		buffer to put number of HDMI port
 */
EXTERN MT_RESULT_T LE_MOD_GET_HDMI_PORT_NUM(UINT32 *pNum);

/**
 *  LE_MOD_GET_HDMI_PORT_MAP() to get HDMI port map of current model
 *  @param pMap		buffer to put HDMI port map
 */
EXTERN MT_RESULT_T LE_MOD_GET_HDMI_PORT_MAP(UCHAR *pMap);

/**
 *  LE_MOD_GET_SMARTCARD_INPUT() to get smart card input of current model
 *  @param pPort	buffer to put smartcard input hdmi port
 */
EXTERN MT_RESULT_T LE_MOD_GET_SMARTCARD_INPUT(UINT32 *pPort);

/**
 *  LE_VID_SET_RGBGAIN() to set rgb gain
 *  @param color	specified color e.g. 'r'/'g'/'b'
 *  @param gain		color gain
 */
EXTERN MT_RESULT_T LE_VID_SET_RGBGAIN(CHAR color, UINT16 gain);

/**
 *  LE_VID_GET_RGBGAIN() to get rgb gain
 *  @param color	specified color
 *  @param pGain	pointer to put color gain
 */
EXTERN MT_RESULT_T LE_VID_GET_RGBGAIN(CHAR color, UINT16 *pGain);

/**
 *  LE_AUD_SET_SRCVOL() to set volume of source
 *  @param decId	decoder id
 *  @param strmSrc	index of stream source
 *  @param vol		volume
 */
EXTERN MT_RESULT_T LE_AUD_SET_SRCVOL(UINT8 decId, UINT8 strmSrc, INT16 vol);

/**
 *  LE_AUD_GET_SRCVOL() to get volume of source
 *  @param decId	decoder id
 *  @param strmSrc	index of stream source
 *  @param pVol		pointer to put volume
 */
EXTERN MT_RESULT_T LE_AUD_GET_SRCVOL(UINT8 decId, UINT8 strmSrc, INT16 *pVol);

/**
 *  LE_AUD_SET_VOLTBL() to change value of specified volume table item
 *  @param volTblIdx	volume table index
 *  @param volTblVal	volume
 */
EXTERN MT_RESULT_T LE_AUD_SET_VOLTBL(UINT8 volTblIdx, UINT32 volTblVal);

/**
 *  LE_AUD_GET_VOLTBL() to get value of specified volume table item
 *  @param volTblIdx	volume table index
 *  @param pVolTblVal	pointer to put volume
 */
EXTERN MT_RESULT_T LE_AUD_GET_VOLTBL(UINT8 volTblIdx, UINT32 *pVolTblVal);

/**
 *  LE_AUD_SET_LIMITER_MODE() to change limiter mode
 *  @param mode		limiter mode
 */
EXTERN MT_RESULT_T LE_AUD_SET_LIMITER_MODE(UINT8 mode);

/**
 *  LE_AUD_GET_LIMITER_MODE() to get current limiter mode
 *  @param pMode	pointer to put limiter mode
 */
EXTERN MT_RESULT_T LE_AUD_GET_LIMITER_MODE(UINT8 *pMode);

/**
 *  LE_AUD_SET_LIMITER_THRES() to set limiter threshold
 *  @param thres	limiter threshold
 */
EXTERN MT_RESULT_T LE_AUD_SET_LIMITER_THRES(UINT32 thres);

/**
 *  LE_AUD_GET_LIMITER_THRES() to get limiter threshold
 *  @param pThres	pointer to put limiter threshold
 */
EXTERN MT_RESULT_T LE_AUD_GET_LIMITER_THRES(UINT32 *pThres);

/**
 *  LE_AUD_SET_VRS_ENABLE() to set virtual surround status
 *  @param decId	decoder id
 *  @param enable	enable/disable
 */
EXTERN MT_RESULT_T LE_AUD_SET_VRS_ENABLE(UINT8 decId, UINT8 enable);

/**
 *  LE_AUD_GET_VRS_ENABLE() to get virtual surround status
 *  @param decId	decoder id
 *  @param pEnable	pointer to put vrs status
 */
EXTERN MT_RESULT_T LE_AUD_GET_VRS_ENABLE(UINT8 decId, UINT8 *pEnable);

/**
 *  LE_AUD_SET_VRS_CONFIG() to set virtual surround parameters
 *  @param type		type of parameter
 *  @param param	parameter value
 */
EXTERN MT_RESULT_T LE_AUD_SET_VRS_CONFIG(UINT8 type, UINT32 param);

/**
 *  LE_AUD_GET_VRS_CONFIG() to get virtual surround parameter value
 *  @param type		type of parameter
 *  @param pParam	pointer to put parameter value
 */
EXTERN MT_RESULT_T LE_AUD_GET_VRS_CONFIG(UINT8 type, UINT32 *pParam);

/**
 *  LE_AUD_SET_EQ_ENABLE() to set eq status
 *  @param decId	decoder id
 *  @param enable	enable/disable
 */
EXTERN MT_RESULT_T LE_AUD_SET_EQ_ENABLE(UINT8 decId, UINT8 enable);

/**
 *  LE_AUD_GET_EQ_ENABLE() to get eq status
 *  @param decId	decoder id
 *  @param pEnable	pointer to put eq status
 */
EXTERN MT_RESULT_T LE_AUD_GET_EQ_ENABLE(UINT8 decId, UINT8 *pEnable);

/**
 *  LE_AUD_SET_EQ_TABLE() to set eq table
 *  @param decId	decoder id
 *  @param index	index of eq table item
 *  @param value	value of eq table item
 */
EXTERN MT_RESULT_T LE_AUD_SET_EQ_TABLE(UINT8 decId, UINT8 index, INT8 value);

/**
 *  LE_AUD_GET_EQ_TABLE() to get eq table
 *  @param decId	decoder id
 *  @param index	index of eq table item
 *  @param pValue	pointer to put value of eq table item
 */
EXTERN MT_RESULT_T LE_AUD_GET_EQ_TABLE(UINT8 decId, UINT8 index, INT8 *pValue);

/**
 *  LE_AUD_SET_BB_ENABLE() set bass boost enable/disable
 *  @param decId	decoder id
 *  @param enable	enable/disable
 */
EXTERN MT_RESULT_T LE_AUD_SET_BB_ENABLE(UINT8 decId, UINT8 enable);

/**
 *  LE_AUD_GET_BB_ENABLE() get bass boost status
 *  @param decId	decoder id
 *  @param pEnable	pointer to put bass boost status
 */
EXTERN MT_RESULT_T LE_AUD_GET_BB_ENABLE(UINT8 decId, UINT8 *pEnable);

/**
 *  LE_AUD_SET_CB_ENABLE() set clear boost enable/disable
 *  @param decId	decoder id
 *  @param enable	enable/disable
 */
EXTERN MT_RESULT_T LE_AUD_SET_CB_ENABLE(UINT8 decId, UINT8 enable);

/**
 *  LE_AUD_GET_CB_ENABLE() get clear boost status
 *  @param decId	decoder id
 *  @param pEnable	pointer to put clear boost status
 */
EXTERN MT_RESULT_T LE_AUD_GET_CB_ENABLE(UINT8 decId, UINT8 *pEnable);

/**
 *  LE_AUD_SET_SB_ENABLE() set super boost enable/disable
 *  @param decId	decoder id
 *  @param enable	enable/disable
 */
EXTERN MT_RESULT_T LE_AUD_SET_SB_ENABLE(UINT8 decId, UINT8 enable);

/**
 *  LE_AUD_GET_SB_ENABLE() get super boost status
 *  @param decId	decoder id
 *  @param pEnable	pointer to put super boost status
 */
EXTERN MT_RESULT_T LE_AUD_GET_SB_ENABLE(UINT8 decId, UINT8 *pEnable);

/**
 *  LE_AUD_SET_BB_GAIN() set bass boost gain
 *  @param decId	decoder id
 *  @param gain		bass boost gain
 */
EXTERN MT_RESULT_T LE_AUD_SET_BB_GAIN(UINT8 decId, UINT8 gain);

/**
 *  LE_AUD_GET_BB_GAIN() get bass boost gain
 *  @param decId	decoder id
 *  @param pGain	pointer to put bass boost gain
 */
EXTERN MT_RESULT_T LE_AUD_GET_BB_GAIN(UINT8 decId, UINT8 *pGain);

/**
 *  LE_AUD_SET_CB_GAIN() set clear boost gain
 *  @param decId	decoder id
 *  @param gain		clear boost gain
 */
EXTERN MT_RESULT_T LE_AUD_SET_CB_GAIN(UINT8 decId, UINT8 gain);

/**
 *  LE_AUD_GET_CB_GAIN() get clear boost gain
 *  @param decId	decoder id
 *  @param pGain	pointer to put clear boost gain
 */
EXTERN MT_RESULT_T LE_AUD_GET_CB_GAIN(UINT8 decId, UINT8 *pGain);

/**
 *  LE_AUD_SET_AVC_PARAM() set auto volume control parameter
 *  @param decId	decoder id
 *  @param type		type of parameter
 *  @param value	value of parameter
 */
EXTERN MT_RESULT_T LE_AUD_SET_AVC_PARAM(UINT8 decId, UINT16 type, UINT16 value);

/**
 *  LE_AUD_GET_AVC_PARAM() get auto volume control parameter
 *  @param decId	decoder id
 *  @param type		type of parameter
 *  @param pValue	pointer to put parameter value
 */
EXTERN MT_RESULT_T LE_AUD_GET_AVC_PARAM(UINT8 decId, UINT16 type, UINT16 *pValue);

/**
 *  LE_AUD_SET_AMP_REG() write amplifier register
 *  @param offset	i2c data address of register
 *  @param data		new register value
 */
EXTERN MT_RESULT_T LE_AUD_SET_AMP_REG(UINT8 offset, UINT8 data);

/**
 *  LE_AUD_GET_AMP_REG() get amplifier register value
 *  @param offset	i2c data address of register
 *  @param pData	pointer to put register value
 */
EXTERN MT_RESULT_T LE_AUD_GET_AMP_REG(UINT8 offset, UINT8 *pData);

/**
 *  LE_AUD_WR_MULTI_SUBADDR() write multiple sub address
 *  @param clkDiv	divider to devide 27MHz for SCL
 *  @param devAddr	i2c device address
 *  @param wordAddrNum	i2c word address length
 *  @param wordAddr	i2c word address
 *  @param pData	pointer of data to write
 *  @param byteCnt	number of bytes to write
 */
EXTERN MT_RESULT_T LE_AUD_WR_MULTI_SUBADDR(UINT16 clkDiv, UINT8 devAddr, UINT8 wordAddrNum,
                                UINT32 wordAddr, UINT8 *pData, UINT16 byteCnt);

/**
 *  LE_AUD_RD_MULTI_SUBADDR() read multiple sub address
 *  @param clkDiv       divider to devide 27MHz for SCL
 *  @param devAddr      i2c device address
 *  @param wordAddrNum  i2c word address length
 *  @param wordAddr     i2c word address
 *  @param pData        pointer to put data read
 *  @param byteCnt      number of bytes to read
 */
EXTERN MT_RESULT_T LE_AUD_RD_MULTI_SUBADDR(UINT16 clkDiv, UINT8 devAddr, UINT8 wordAddrNum,
                                UINT32 wordAddr, UINT8 *pData, UINT16 byteCnt);

/**
 *  LE_AUD_GET_VOLTBL_CHKPNT() get number of volume table checkpoint
 *  @param tblIdx	index of checkpoint
 *  @param pChkPntIdx	table index of specified checkpoint
 */
EXTERN MT_RESULT_T LE_AUD_GET_VOLTBL_CHKPNT(UINT8 tblIdx, UINT8 *pChkPntIdx);

/**
 *  LE_AUD_SET_PEQ_ENABLE() set peq enable/disable
 *  @param enable	enable/disable flag
 */
EXTERN MT_RESULT_T LE_AUD_SET_PEQ_ENABLE(UINT8 enable);

/**
 *  LE_AUD_GET_PEQ_ENABLE() get peq enable/disable
 *  @param pEnable	pointer to put enable/disable status
 */
EXTERN MT_RESULT_T LE_AUD_GET_PEQ_ENABLE(UINT8 *pEnable);

/**
 *  LE_AUD_SET_PEQ_CONFIG() set peq configuration
 *  @param u1DecId	decoder id
 *  @param u1BandNum	peq band number
 *  @param u4Feq	frequency
 *  @param u4QValue	Q value
 *  @param i2Gain	peq gain
 */
EXTERN MT_RESULT_T LE_AUD_SET_PEQ_CONFIG(UINT8 u1DecId, UINT8 u1BandNum, UINT32 u4Freq,
				UINT32 u4QValue, INT16 i2Gain);

/**
 *  LE_AUD_GET_PEQ_CONFIG() set peq configuration
 *  @param u1DecId      decoder id
 *  @param u1BandNum    peq band number
 *  @param pu4Feq       pointer to put frequency
 *  @param pu4QValue    pointer to put Q value
 *  @param pi2Gain      pointer to put peq gain
 */
EXTERN MT_RESULT_T LE_AUD_GET_PEQ_CONFIG(UINT8 u1DecId, UINT8 u1BandNum, UINT32 *pu4Freq,
				UINT32 *pu4QValue, INT16 *pi2Gain);

/**
 *  LE_AUD_SET_MIC_ENABLE() set micro-phone enable
 *  @param u1Enable	enable/disable flag
 */
EXTERN MT_RESULT_T LE_AUD_SET_MIC_ENABLE(UINT8 enable);


/**
 *  LE_TV_SET_BURNING_MODE() set burning mode on/off
 *  @param flag		on/off
 */
EXTERN MT_RESULT_T LE_TV_SET_BURNING_MODE(UINT8 flag);

/**
 *  LE_TV_SET_RGB_PATTERN() to set internal rgb pattern
 *  @param red		red color value 0~255
 *  @param green	green color value 0~255
 *  @param blue		blue color value 0~255
 */
EXTERN MT_RESULT_T LE_TV_SET_RGB_PATTERN(UINT8 red, UINT8 green, UINT8 blue);

/**
 *  LE_TV_WR_EEPROM_TEST() to write data to eeprom test byte
 *  @param u1Data	data to write to eeprom test byte
 */
EXTERN MT_RESULT_T LE_TV_WR_EEPROM_TEST(UINT8 u1Data);

/**
 *  LE_TV_RD_EEPROM_TEST() to read data from eeprom test byte
 *  @param pu1Data	pointer to put data read from eeprom test byte
 */
EXTERN MT_RESULT_T LE_TV_RD_EEPROM_TEST(UINT8 *pu1Data);

/**
 *  LE_TV_RD_TEMP_AD() to read temperature sensor AD value
 *  @param pu4Data	pointer to put AD value
 */
EXTERN MT_RESULT_T LE_TV_RD_TEMP_AD(UINT32 *pu4Data);

/**
 *  LE_TV_WR_GAMMA_POINT() to write gamma low/high point index
 *  @params avMode	av mode: dynamic (1)/non-dynamic
 *  @params point	1-low/2-high
 *  @params u1Idx	point index
 */
EXTERN MT_RESULT_T LE_TV_WR_GAMMA_POINT(UINT8 avMode, UINT8 point, UINT8 u1Idx);

/**
 *  LE_TV_RD_GAMMA_POINT() to read gamma low/high point index
 *  @params avMode	av mode: dynamic (1)/non-dynamic
 *  @params point	1-low/2-high
 *  @params pu1Idx	pointer to put point index
 */
EXTERN MT_RESULT_T LE_TV_RD_GAMMA_POINT(UINT8 avMode, UINT8 point, UINT8* pu1Idx);

/**
 *  LE_TV_WR_GAMMA_CURVE() to write gamma low/high/max point r/g/b value
 *  @params avMode	av mode: dynamic (1)/ non-dynamic
 *  @params color	'r'/'g'/'b'
 *  @params point	1-low/ 2-high/ 3-max
 *  @params u2Value	0~4095
 */
EXTERN MT_RESULT_T LE_TV_WR_GAMMA_CURVE(UINT8 avMode, CHAR color, UINT8 point, UINT16 u2Value);

/**
 *  LE_TV_RD_GAMMA_CURVE() to read gamma low/high/max point r/g/b value
 *  @params avMode	av mode: dynamic (1)/ non-dynamic
 *  @params color       'r'/'g'/'b'
 *  @params point       1-low/ 2-high/ 3-max
 *  @params pu2Value	pointer to put r/g/b value
 */
EXTERN MT_RESULT_T LE_TV_RD_GAMMA_CURVE(UINT8 avMode, CHAR color, UINT8 point, UINT16 *pu2Value);

/**
 *  LE_TV_SET_GAMMA_PATTERN() to generate internal gamma pattern
 *  @params enable	enable/disable internal gamma pattern
 *  @params u2Red	red value
 *  @params u2Green	green value
 *  @params u2Blue	blue value
 */
EXTERN MT_RESULT_T LE_TV_SET_GAMMA_PATTERN(UINT8 enable, UINT16 u2Red, UINT16 u2Green, UINT16 u2Blue);

/**
 *  LE_TV_RESET_3DGLASS() to change level of 3D glass reset gpio
 *  @params UINT8	level
 */
EXTERN MT_RESULT_T LE_TV_RESET_3DGLASS(UINT8 level);

/**
 *  LE_TV_DRIVER_LOAD_GAMMA() to load gamma paramter form eeprm on the driver
 *  @params UINT8       enable, not using in this time
 */
EXTERN MT_RESULT_T LE_TV_DRIVER_LOAD_GAMMA(UINT8 enable);

/**
 *  LE_GET_DYNAMIC_BACKLIGHT() to load dynamic backlight parameter
 *  @params UINT32      dynamic backlight you want to load to.
 */
EXTERN MT_RESULT_T LE_GET_DYNAMIC_BACKLIGHT(UINT32* pui4DynamicBL);

/**
 *  LE_SET_DYNAMIC_BACKLIGHT() to set dynamic backlight parameter
 *  @params UINT32      dynamic backlight you want to set.
 */
EXTERN MT_RESULT_T LE_SET_DYNAMIC_BACKLIGHT(UINT32 ui4DynamicBL);

/**
 *  LE_GET_SHARP_HDCP_CHECK() to get Sharp special HDCP key check
 *  @params UINT32*     check array you want to load.
 */
EXTERN MT_RESULT_T LE_GET_SHARP_HDCP_CHECK(CHAR *pu1Check, UINT32 type, UINT32 len);


/**
 *  LE_SET_INPUT_SOURCE_TYPE() Set source group.
 *  @params UINT32   0: TV 1: MMP
 */
EXTERN MT_RESULT_T LE_SET_INPUT_SOURCE_TYPE(UINT32 ui4srctype);

/**
 *  LE_TV_GET_BOOT_COUNT() get boot count.
 *  @params UINT32*	buffer to put boot count
 */
EXTERN MT_RESULT_T LE_TV_GET_BOOT_COUNT(UINT32 *pu4BootCnt);

/**
 *  LE_TV_GET_BOOT_TIME_HOUR() get accumulated boot time in hour.
 *  @params UINT32*	buffer to put boot time
 */
EXTERN MT_RESULT_T LE_TV_GET_BOOT_TIME_HOUR(UINT32 *pu4BootHour);

/**
 *  LE_TV_GET_BOOT_TIME_MIN() get extra boot time in minutes.
 *  @param UINT32*	buffer to put extra boot minutes
 */
EXTERN MT_RESULT_T LE_TV_GET_BOOT_TIME_MIN(UINT32 *pu4BootMin);

/**
 *  LE_TV_RESET_BOOT_TIME() reset boot time and count
 */
EXTERN MT_RESULT_T LE_TV_RESET_BOOT_TIME(void);

/**
 *  LE_TV_SET_SCARD_POWER() set smart card power on/off
 */
EXTERN MT_RESULT_T LE_TV_SET_SCARD_POWER(INT32 enable);

/**
 *  LE_TV_GET_SCARD_DETECT() get smart card detect gpio level
 */
EXTERN MT_RESULT_T LE_TV_GET_SCARD_DETECT(INT32 *pDetected);
#ifdef __cplusplus
}
#endif

#endif //_LECUST_H_

