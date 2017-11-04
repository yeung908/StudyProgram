#ifndef __DRV_LSADC_IOCTL_H__
#define __DRV_LSADC_IOCTL_H__

#include "hi_type.h"


typedef struct hiLSADC_PARAM_S
{
    unsigned int u32ChannelMask;          /* Channel Mask (bit0:channel-A, bit1:channele-B 1:enable 0:disable) */
    unsigned int u32ActiveBit;            /* Active bit */
    unsigned int u32DataDelta;            /* data delta */
    unsigned int u32DeglitchBypass;       /* deglitch bypass */
    unsigned int u32LsadcReset;           /* lsadc reset */
    unsigned int u32PowerDownMod;         /* power down model */
    unsigned int u32ModelSel;             /* model sel */
    unsigned int u32LsadcZero;            /* lsadc zero */
    unsigned int u32GlitchSample;         /* glitch sample */
    unsigned int u32TimeScan;             /* time scan */ 
}LSADC_PARAM_S;


/********************************* Ioctl definitions ************/
#define CMD_LSADC_SET_CONFIG    _IOW(HI_ID_LSADC, 0x1, LSADC_PARAM_S)
#define CMD_LSADC_GET_CONFIG    _IOWR(HI_ID_LSADC, 0x2, LSADC_PARAM_S)
#define CMD_LSADC_GET_VALUE	    _IOWR(HI_ID_LSADC, 0x3, unsigned int)


#endif /* __DRV_IR_IOCTL_H__ */
