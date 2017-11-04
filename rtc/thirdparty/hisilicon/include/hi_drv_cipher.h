/******************************************************************************

  Copyright (C), 2011-2021, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     :hi_drv_cipher.h
  Version       : Initial Draft
  Author        : Hisilicon hisecurity team
  Created       : 
  Last Modified :
  Description   : 
  Function List :
  History       :
******************************************************************************/

#ifndef __HI_DRV_CIPHER_H__
#define __HI_DRV_CIPHER_H__

#include "hi_type.h"
#include "hi_unf_cipher.h"

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

#define CIPHER_SOFT_CHAN_NUM      CIPHER_CHAN_NUM
#define CIPHER_INVALID_CHN        (0xffffffff)

#define HI_FATAL_CIPHER(fmt...)             HI_FATAL_PRINT(HI_ID_CIPHER, fmt)
#define HI_ERR_CIPHER(fmt...)               HI_ERR_PRINT(HI_ID_CIPHER, fmt)
#define HI_WARN_CIPHER(fmt...)              HI_WARN_PRINT(HI_ID_CIPHER, fmt)
#define HI_INFO_CIPHER(fmt...)              HI_INFO_PRINT(HI_ID_CIPHER, fmt)
#define HI_DEBUG_CIPHER(fmt...)             HI_DBG_PRINT(HI_ID_CIPHER, fmt)

typedef struct hiCIPHER_DATA_INFO_S
{
    HI_U32  u32src;
    HI_U32  u32dest;
    HI_U32  u32length;
    HI_BOOL bDecrypt;
    HI_U32  u32DataPkg[4];
}HI_DRV_CIPHER_DATA_INFO_S;

typedef struct hiCIPHER_TASK_S
{
    HI_DRV_CIPHER_DATA_INFO_S stData2Process;
    HI_U32 u32CallBackArg;
}HI_DRV_CIPHER_TASK_S;

typedef enum hiCIPHER_HDCP_MODE_E
{
    CIPHER_HDCP_MODE_NO_HDCP_KEY                = 0x0,
    CIPHER_HDCP_MODE_HDCP_KEY,
    CIPHER_HDCP_MODE_BUTT,
}HI_DRV_CIPHER_HDCP_KEY_MODE_E;

typedef enum hiCIPHER_HDCP_KEY_TARGET
{
    CIPHER_HDCP_KEY_TARGET_TX = 0,
    CIPHER_HDCP_KEY_TARGET_RX,
    CIPHER_HDCP_KEY_TARGET_BUTT = 0xFFFFFFFF,
}HI_DRV_CIPHER_HDCP_KEY_TARGET_E;

typedef enum hiCIPHER_HDCP_KEY_RAM_MODE_E
{
    CIPHER_HDCP_KEY_RAM_MODE_READ         		= 0x0,
    CIPHER_HDCP_KEY_RAM_MODE_WRITE,
    CIPHER_HDCP_KEY_RAM_MODE_BUTT,
}HI_DRV_CIPHER_HDCP_KEY_RAM_MODE_E;

typedef enum hiCIPHER_HDCP_KEY_RX_SELECT_E
{
    CIPHER_HDCP_KEY_SELECT_TX         		= 0x0,
    CIPHER_HDCP_KEY_SELECT_RX,
    CIPHER_HDCP_KEY_SELECT_BUTT,
}HI_DRV_CIPHER_HDCP_KEY_RX_SELECT_E;

typedef enum hiCIPHER_HDCP_KEY_RX_READ_E
{
    CIPHER_HDCP_KEY_WR_RX_RAM         		= 0x0,
    CIPHER_HDCP_KEY_RD_RX_RAM,
    CIPHER_HDCP_KEY_RX_READ_BUTT,
}HI_DRV_CIPHER_HDCP_KEY_RX_READ_E;

typedef enum hiCIPHER_HDCP_KEY_TYPE_E
{
    CIPHER_HDCP_KEY_TYPE_OTP_ROOT_KEY           = 0x0,
    CIPHER_HDCP_KEY_TYPE_HISI_DEFINED,
    CIPHER_HDCP_KEY_TYPE_HOST_ROOT_KEY,
    CIPHER_HDCP_KEY_TYPE_BUTT,
}HI_DRV_CIPHER_HDCP_ROOT_KEY_TYPE_E;

typedef struct
{
    HI_U8 u8Key[332];   // 332bytes for HDCP1.X, unknown for other.
}HI_DRV_CIPHER_FLASH_ENCRYPT_HDCPKEY_S;

typedef struct  hiCIPHER_HANDLE_S
{
    HI_HANDLE hCIHandle;
    HI_UNF_CIPHER_ATTS_S stCipherAtts;
}CIPHER_HANDLE_S;

typedef struct  hiCIPHER_DATA_S
{
    HI_HANDLE      CIHandle;
    HI_PHYS_ADDR_T ScrPhyAddr;
    HI_PHYS_ADDR_T DestPhyAddr;
    HI_U32         u32DataLength;
}CIPHER_DATA_S;

typedef struct  hiCIPHER_DATA_EXT_S
{
    HI_HANDLE      CIHandle;
    HI_VIRT_ADDR_T ScrDataPkg;
    HI_PHYS_ADDR_T DestPhyAddr;
    HI_U32         u32DataLength;
}CIPHER_DATA_EXT_S;

typedef struct hiCIPHER_Config_CTRL
{
    HI_HANDLE CIHandle;
    HI_UNF_CIPHER_CTRL_S CIpstCtrl;
}CIPHER_Config_CTRL;

typedef enum
{
    HI_CIPHER_HMAC_KEY_FROM_CA  = 0,
    HI_CIPHER_HMAC_KEY_FROM_CPU = 1,
}CIPHER_HMAC_KEY_FROM_E;

typedef struct hiCipher_HASH_MMZ_BUFFER_S
{
    HI_VIRT_ADDR_T u32StartVirAddr;
    HI_PHYS_ADDR_T u32StartPhyAddr;    
    HI_U32 u32Size;
}HASH_MMZ_BUFFER_S;

typedef struct hiCIPHER_HASH_DATA_S
{
    HI_HANDLE                 hHandle;
    HI_UNF_CIPHER_HASH_TYPE_E enShaType;
    HI_U32                    u32TotalDataLen;
    HI_VIRT_ADDR_T            pu8InputData;      //HI_U8  *pu8InputData;    
    HI_U32                    u32InputDataLen;
    HI_U8                     u8Padding[64+8];
    HI_U32                    u32PaddingLen;
    HI_VIRT_ADDR_T            pu8HMACKey;        //HI_U8  *pu8HMACKey;
    HI_U32                    u32HMACKeyLen;
    CIPHER_HMAC_KEY_FROM_E    enHMACKeyFrom;
    HI_VIRT_ADDR_T            pu8Output;         //HI_U8  *pu8Output;
	HASH_MMZ_BUFFER_S         stMMZBuffer;
	HI_U32 u32Offset;
}CIPHER_HASH_DATA_S;

HI_S32 HI_DRV_CIPHER_CreateHandle(CIPHER_HANDLE_S *pstCIHandle);
HI_S32 HI_DRV_CIPHER_ConfigChn(HI_U32 softChnId, HI_UNF_CIPHER_CTRL_S *pConfig);
HI_S32 HI_DRV_CIPHER_GetHandleConfig(CIPHER_Config_CTRL *pstCipherConfig);
HI_S32 HI_DRV_CIPHER_DestroyHandle(HI_HANDLE hCipherchn);
HI_S32 HI_DRV_CIPHER_Encrypt(CIPHER_DATA_S *pstCIData);
HI_S32 HI_DRV_CIPHER_Decrypt(CIPHER_DATA_S *pstCIData);
HI_S32 HI_DRV_CIPHER_EncryptMulti(CIPHER_DATA_EXT_S *pstCIData);
HI_S32 HI_DRV_CIPHER_DecryptMulti(CIPHER_DATA_EXT_S *pstCIData);
HI_S32 HI_DRV_CIPHER_GetRandomNumber(HI_U32 *pu32RngRandomNumber);
HI_S32 HI_DRV_CIPHER_SoftReset(HI_VOID);
HI_S32 HI_DRV_CIPHER_LoadHdcpKey(HI_DRV_CIPHER_FLASH_ENCRYPT_HDCPKEY_S *pstFlashHdcpKey);
HI_S32 HI_DRV_CIPHER_CalcHashInit(CIPHER_HASH_DATA_S *pCipherHashData);
HI_S32 HI_DRV_CIPHER_CalcHashUpdate(CIPHER_HASH_DATA_S *pCipherHashData);
HI_S32 HI_DRV_CIPHER_CalcHashFinal(CIPHER_HASH_DATA_S *pCipherHashData);
HI_VOID HI_DRV_CIPHER_Suspend(HI_VOID);
HI_S32 HI_DRV_CIPHER_Resume(HI_VOID);

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif	/* End of #ifndef __HI_DRV_CIPHER_H__*/

