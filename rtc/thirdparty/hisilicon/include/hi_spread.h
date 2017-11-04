#ifndef __HI_UNF_SPREAD_H__
#define __HI_UNF_SPREAD_H__

#include "hi_common.h"

#define HI_REG_WriteBits(u32RegAddr, u32Value, u32Mask)\
do{\
    HI_U32 u32RegValue = 0;\
    HI_SYS_ReadRegister(u32RegAddr, &u32RegValue);\
    u32RegValue &= ~u32Mask;\
    u32RegValue |= u32Value & u32Mask;\
    HI_SYS_WriteRegister(u32RegAddr, u32RegValue);\
}while(0)

#define HI_REG_ReadBits(u32RegAddr, u32OffSet, u32Mask, pu32Value)\
do{\
	HI_U32 u32RegValue = 0;\
	HI_SYS_ReadRegister(u32RegAddr, &u32RegValue);\
    *pu32Value = (u32RegValue >> u32OffSet) & u32Mask ;\
}while(0)

/* ---------------------------------------展频相关功能------------------------------------------ */
#define SS_FREQ_MASK                0x0F    /* (0x0F << 9) */
#define SS_FREQ_OFFSET              0x09       

#define SS_RATIO_MASK               0x1F     /* (0x1F << 4) */
#define SS_RATIO_OFFSET             0x04     

#define SS_DOWN_MASK                0x01      /* (0x01 << 3) */
#define SS_DOWN_OFFSET              0x03      

#define SS_ENABLE_MASK              0x01      /* (0x01 << 2) */
#define SS_ENABLE_OFFSET            0x02      

#define SS_RST_MASK                 0x01      /* (0x01 << 1) */
#define SS_RST_OFFSET               0x01      /* (0x01 << 1) */

#define SS_CLK_MASK                 0x01      /* (0x01 << 0) */
#define SS_CLK_OFFSET               0x00      

/* 打开/关闭时钟、撤销复位/复位 */
#define HI_SS_SetClkEn(u32RegAddr, bEnable)\
do{\
    if (bEnable)\
    {\
        HI_REG_WriteBits(u32RegAddr, (HI_TRUE << SS_CLK_OFFSET), (SS_CLK_MASK << SS_CLK_OFFSET));\
        HI_REG_WriteBits(u32RegAddr, (HI_FALSE << SS_RST_OFFSET), (SS_RST_MASK << SS_RST_OFFSET));\
    }\
    else\
    {\
        HI_REG_WriteBits(u32RegAddr, (HI_TRUE << SS_RST_OFFSET), (SS_RST_MASK << SS_RST_OFFSET));\
        HI_REG_WriteBits(u32RegAddr, (HI_FALSE << SS_CLK_OFFSET), (SS_CLK_MASK << SS_CLK_OFFSET));\
    }\
}while(0)

/* 1. 关闭ssmod时钟、复位 */
/* 2. config 展频开关 */
/* 3. 打开ssmod时钟、撤销复位 */
#define HI_SS_SetSpreadEn(u32RegAddr, bEnable)\
do{\
    HI_SS_SetClkEn(u32RegAddr, HI_FALSE);\
    HI_REG_WriteBits(u32RegAddr, (~bEnable << SS_ENABLE_OFFSET), (SS_ENABLE_MASK << SS_ENABLE_OFFSET));\
    HI_SS_SetClkEn(u32RegAddr, HI_TRUE);\
}while(0)

/* 1. 关闭ssmod时钟、复位 */
/* 2. config 展频DOWN模式 */
/* 3. 打开ssmod时钟、撤销复位 */
#define HI_SS_SetSpreadDown(u32RegAddr, bEnable)\
do{\
    HI_U32 u32RegValue = 0;\
    HI_BOOL bSpreadDisable;\
    HI_SYS_ReadRegister(u32RegAddr, &u32RegValue);\
    bSpreadDisable = (u32RegValue & (SS_ENABLE_MASK << SS_ENABLE_OFFSET)) ? HI_TRUE : HI_FALSE;\
    HI_REG_WriteBits(u32RegAddr, (HI_TRUE << SS_ENABLE_OFFSET), (SS_ENABLE_MASK << SS_ENABLE_OFFSET));\
    HI_SS_SetClkEn(u32RegAddr, HI_FALSE);\
    HI_REG_WriteBits(u32RegAddr, (bEnable << SS_DOWN_OFFSET), (SS_DOWN_MASK << SS_DOWN_OFFSET));\
    HI_REG_WriteBits(u32RegAddr, (bSpreadDisable << SS_ENABLE_OFFSET), (SS_ENABLE_MASK  << SS_ENABLE_OFFSET));\
    HI_SS_SetClkEn(u32RegAddr, HI_TRUE);\
}while(0)

/* 1. 禁用spread、关闭ssmod时钟、复位 */
/* 2. config 展频幅度 */
/* 3. 恢复spread使能状态、打开ssmod时钟、撤销复位 */
#define HI_SS_SetSpreadRatio(u32RegAddr, u32SpreadRatio)\
do{\
    HI_U32 u32RegValue = 0;\
    HI_BOOL bSpreadDisable;\
    HI_SYS_ReadRegister(u32RegAddr, &u32RegValue);\
    bSpreadDisable = (u32RegValue & (SS_ENABLE_MASK << SS_ENABLE_OFFSET)) ? HI_TRUE : HI_FALSE;\
    HI_REG_WriteBits(u32RegAddr, (HI_TRUE << SS_ENABLE_OFFSET), (SS_ENABLE_MASK << SS_ENABLE_OFFSET));\
    HI_SS_SetClkEn(u32RegAddr, HI_FALSE);\
    HI_REG_WriteBits(u32RegAddr, (u32SpreadRatio << SS_RATIO_OFFSET), (SS_RATIO_MASK << SS_RATIO_OFFSET));\
    HI_REG_WriteBits(u32RegAddr, (bSpreadDisable << SS_ENABLE_OFFSET), (SS_ENABLE_MASK  << SS_ENABLE_OFFSET));\
    HI_SS_SetClkEn(u32RegAddr, HI_TRUE);\
}while(0)

/* 1. 禁用spread、关闭ssmod时钟、复位 */
/* 2. config 展频频率 */
/* 3. 恢复spread使能状态、打开ssmod时钟、撤销复位 */
#define HI_SS_SetSpreadFreq(u32RegAddr, u32SpreadFreq)\
do{\
    HI_U32 u32RegValue = 0;\
    HI_BOOL bSpreadDisable;\
    HI_SYS_ReadRegister(u32RegAddr, &u32RegValue);\
    bSpreadDisable = (u32RegValue & (SS_ENABLE_MASK << SS_ENABLE_OFFSET)) ? HI_TRUE : HI_FALSE;\
    HI_REG_WriteBits(u32RegAddr, (HI_TRUE << SS_ENABLE_OFFSET), (SS_ENABLE_MASK << SS_ENABLE_OFFSET));\
    HI_SS_SetClkEn(u32RegAddr, HI_FALSE);\
    HI_REG_WriteBits(u32RegAddr, (u32SpreadFreq << SS_FREQ_OFFSET), (SS_FREQ_MASK << SS_FREQ_OFFSET));\
    HI_REG_WriteBits(u32RegAddr, (bSpreadDisable << SS_ENABLE_OFFSET), (SS_ENABLE_MASK << SS_ENABLE_OFFSET));\
    HI_SS_SetClkEn(u32RegAddr, HI_TRUE);\
}while(0)

#define DDR_SS_CTRL_ADDR    0xF8A22130  /* DDR 展频控制寄存器 */
#define GMAC_SS_CTRL_ADDR   0xF8A22134  /* GMAC 展频控制寄存器 */
#define GMAC_CLK_CTRL_ADDR  0xF8A220CC  /* GMAC 时钟选择寄存器 */

#define GMAC_GSF_CLK_SEL_MASK       0x01    /* (0x01 << 18) */
#define GMAC_GSF_CLK_SEL_OFFSET     18

/* [0-31] 0：0；1：0.1%；2：0.2%3：0.3%；4：0.4%；5：0.5%；6：0.6%；7：0.7%...31：3.1% */
#define SS_SPREAD_RATIO_MAX         31

/* [2-6] 依此为93KHZ,62KHZ,46KHZ,37KHZ,31KHZ */
#define SS_SPREAD_FREQ_MIN          2
#define SS_SPREAD_FREQ_MAX          5

/* DDR展频功能 */
#if 0
/* 1. 禁用spread、关闭ssmod时钟、复位 */
/* 2. config 展频相关参数 */
/* 3. 恢复spread使能状态、打开ssmod时钟、撤销复位 */
/* 使用以上时序约束配置DDR的展频功能会出现死机现象 */
#define HI_SS_DDR_SetClkEn(bEnable)               HI_SS_SetClkEn(DDR_SS_CTRL_ADDR, bEnable)
#define HI_SS_DDR_SetSpreadEn(bEnable)            HI_SS_SetSpreadEn(DDR_SS_CTRL_ADDR, bEnable)
#define HI_SS_DDR_SetSpreadDown(bEnable)          HI_SS_SetSpreadDown(DDR_SS_CTRL_ADDR, bEnable)
#define HI_SS_DDR_SetSpreadRatio(u32SpreadRatio)  HI_SS_SetSpreadRatio(DDR_SS_CTRL_ADDR, u32SpreadRatio)
#define HI_SS_DDR_SetSpreadFreq(u32SpreadFreq)    HI_SS_SetSpreadFreq(DDR_SS_CTRL_ADDR, u32SpreadFreq)
#else
#define HI_SS_DDR_SetClkEn(bEnable)               HI_SS_SetClkEn(DDR_SS_CTRL_ADDR, bEnable)
#define HI_SS_DDR_SetSpreadEn(bEnable)\
do{\
    HI_SS_SetClkEn(DDR_SS_CTRL_ADDR, HI_TRUE);\
    HI_REG_WriteBits(DDR_SS_CTRL_ADDR, (~bEnable << SS_ENABLE_OFFSET), (SS_ENABLE_MASK << SS_ENABLE_OFFSET));\
}while(0)

#define HI_SS_DDR_SetSpreadDown(bEnable)\
do{\
    HI_SS_SetClkEn(DDR_SS_CTRL_ADDR, HI_TRUE);\
    HI_REG_WriteBits(DDR_SS_CTRL_ADDR, (bEnable << SS_DOWN_OFFSET), (SS_DOWN_MASK << SS_DOWN_OFFSET));\
}while(0)

#define HI_SS_DDR_SetSpreadRatio(u32SpreadRatio)\
do{\
    HI_SS_SetClkEn(DDR_SS_CTRL_ADDR, HI_TRUE);\
    HI_REG_WriteBits(DDR_SS_CTRL_ADDR, (u32SpreadRatio << SS_RATIO_OFFSET), (SS_RATIO_MASK << SS_RATIO_OFFSET));\
}while(0)

#define HI_SS_DDR_SetSpreadFreq(u32SpreadFreq)\
do{\
    HI_SS_SetClkEn(DDR_SS_CTRL_ADDR, HI_TRUE);\
    HI_REG_WriteBits(DDR_SS_CTRL_ADDR, (u32SpreadFreq << SS_FREQ_OFFSET), (SS_FREQ_MASK << SS_FREQ_OFFSET));\
}while(0)

#define HI_SS_DDR_GetSpreadEn(pbEnable)\
	do{\
    HI_REG_ReadBits(DDR_SS_CTRL_ADDR, SS_ENABLE_OFFSET, SS_ENABLE_MASK, pbEnable);\
    *pbEnable = !*pbEnable;\
}while(0)

#define HI_SS_DDR_GetSpreadRatio(pu32SpreadRatio)\
	do{\
    HI_REG_ReadBits(DDR_SS_CTRL_ADDR, SS_RATIO_OFFSET, SS_RATIO_MASK, pu32SpreadRatio);\
}while(0)

#define HI_SS_DDR_GetSpreadFreq(pu32SpreadFreq)\
	do{\
    HI_REG_ReadBits(DDR_SS_CTRL_ADDR, SS_FREQ_OFFSET, SS_FREQ_MASK, pu32SpreadFreq);\
}while(0)
#endif

/* GMAC展频功能 */
#define HI_SS_GMAC_SetClkEn(bEnable)              HI_SS_SetClkEn(GMAC_SS_CTRL_ADDR, bEnable)

#define HI_SS_GMAC_SetSpreadEn(bEnable) \
do {\
    HI_SS_SetSpreadEn(GMAC_SS_CTRL_ADDR, bEnable);\
    HI_REG_WriteBits(GMAC_CLK_CTRL_ADDR, (bEnable << GMAC_GSF_CLK_SEL_OFFSET), (GMAC_GSF_CLK_SEL_MASK << GMAC_GSF_CLK_SEL_OFFSET));\
} while(0)

#define HI_SS_GMAC_SetSpreadDown(bEnable)         HI_SS_SetSpreadDown(GMAC_SS_CTRL_ADDR, bEnable)
#define HI_SS_GMAC_SetSpreadRatio(u32SpreadRatio) HI_SS_SetSpreadRatio(GMAC_SS_CTRL_ADDR, u32SpreadRatio)
#define HI_SS_GMAC_SetSpreadFreq(u32SpreadFreq)   HI_SS_SetSpreadFreq(GMAC_SS_CTRL_ADDR, u32SpreadFreq)

/* ---------------------------------------CI相关功能------------------------------------------ */
#define CI_CRG_CLK_ADDR     0xF8A22188  /* CI 展频控制寄存器 */
#define CI_CLK_MASK         0x01
#define CI_CLK_OFFSET       0x04

#define CI_RST_MASK         0x01
#define CI_RST_OFFSET       0x01

/* 打开/关闭时钟、撤销复位/复位 */
#define HI_CI_SetClkEn(bEnable)\
do{\
    if (bEnable)\
    {\
        HI_REG_WriteBits(CI_CRG_CLK_ADDR, (HI_TRUE << CI_CLK_OFFSET), (CI_CLK_MASK << CI_CLK_OFFSET));\
        HI_REG_WriteBits(CI_CRG_CLK_ADDR, (HI_FALSE << CI_RST_OFFSET), (CI_RST_MASK << CI_RST_OFFSET));\
    }\
    else\
    {\
        HI_REG_WriteBits(CI_CRG_CLK_ADDR, (HI_TRUE << CI_RST_OFFSET), (CI_RST_MASK << CI_RST_OFFSET));\
        HI_REG_WriteBits(CI_CRG_CLK_ADDR, (HI_FALSE << CI_CLK_OFFSET), (CI_CLK_MASK << CI_CLK_OFFSET));\
    }\
}while(0)

/* ---------------------------------------i2c时钟控制------------------------------------------ */
#define I2C_CRG_CLK_ADDR    0xF8A2206C
#define HI_I2C_SetClkEn(u32Channel, bEnable)    \
do {    \
    HI_U32 u32Offset;   \
    HI_BOOL bChannelValid = HI_FALSE;   \
    \
    switch (u32Channel) \
    {   \
        case 0: \
        case 1: \
        case 2: \
        case 3: \
            bChannelValid = HI_TRUE;    \
            u32Offset = u32Channel;  \
            break;  \
        case 7: \
            bChannelValid = HI_TRUE;    \
            u32Offset = 10; \
            break;  \
        default:    \
            break;  \
    }\
    if (HI_TRUE == bChannelValid)   \
    {\
        HI_REG_WriteBits(I2C_CRG_CLK_ADDR, (bEnable << u32Offset), (1 << u32Offset));   \
    }\
} while(0)

#endif /* __HI_UNF_SPREAD_H__ */

