/******************************************************************************

  Copyright (C), 2011-2021, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_cipher_ioctl.h
  Version       : Initial Draft
  Author        : Hisilicon hisecurity team
  Created       : 
  Last Modified :
  Description   : 
  Function List :
  History       :
******************************************************************************/

#ifndef __DRV_CIPHER_IOCTL_H__
#define __DRV_CIPHER_IOCTL_H__

#include "hi_type.h"
#include "hi_unf_cipher.h"
#include "hi_unf_hdcp.h"
#include "hi_drv_cipher.h"
#include "hi_debug.h"

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */


typedef struct hiCIPHER_PROC_ITEM_S
{
    HI_U32    u32Resv;
}CIPHER_PROC_ITEM_S;

typedef struct hiOTP_HDCPKEY_S
{
	HI_U8 HdcpKey[320];
}CIPHER_HDCPKEY_S;
typedef struct
{
    HI_BOOL bIsUseOTPRootKey;
    HI_UNF_HDCP_HDCPKEY_S stHdcpKey;
    HI_U8 u8FlashEncryptedHdcpKey[332];
}CIPHER_HDCP_KEY_TRANSFER_S;
typedef struct
{
    HI_U32 u32Status;
}CIPHER_HDCPKEYSTATUS_S;
/* Ioctl definitions */

#define    CMD_CIPHER_CREATEHANDLE           _IOWR(HI_ID_CIPHER, 0x1, CIPHER_HANDLE_S)
#define    CMD_CIPHER_DESTROYHANDLE          _IOW(HI_ID_CIPHER,  0x2, HI_U32)
#define    CMD_CIPHER_CONFIGHANDLE           _IOW(HI_ID_CIPHER,  0x3, CIPHER_Config_CTRL)
#define    CMD_CIPHER_ENCRYPT                _IOW(HI_ID_CIPHER,  0x4, CIPHER_DATA_S)
#define    CMD_CIPHER_DECRYPT                _IOW(HI_ID_CIPHER,  0x5, CIPHER_DATA_S)
#define    CMD_CIPHER_DECRYPTMULTI           _IOW(HI_ID_CIPHER,  0x6, CIPHER_DATA_EXT_S)
#define    CMD_CIPHER_ENCRYPTMULTI           _IOW(HI_ID_CIPHER,  0x7, CIPHER_DATA_EXT_S)
#define    CMD_CIPHER_GETRANDOMNUMBER        _IOR(HI_ID_CIPHER,  0x8, HI_U32)
#define    CMD_CIPHER_GETHANDLECONFIG        _IOWR(HI_ID_CIPHER, 0x9, CIPHER_Config_CTRL)
#define    CMD_CIPHER_CALCHASHINIT         _IOWR(HI_ID_CIPHER, 0xa, CIPHER_HASH_DATA_S)
#define    CMD_CIPHER_CALCHASHUPDATE       _IOWR(HI_ID_CIPHER, 0xb, CIPHER_HASH_DATA_S)
#define    CMD_CIPHER_CALCHASHFINAL        _IOWR(HI_ID_CIPHER, 0xc, CIPHER_HASH_DATA_S)
#define    CMD_CIPHER_LOADHDCPKEY            _IOWR(HI_ID_CIPHER, 0xd, HI_DRV_CIPHER_FLASH_ENCRYPT_HDCPKEY_S)
#define    CMD_CIPHER_ENCRYPTHDCPKEY         _IOWR(HI_ID_CIPHER, 0xe, CIPHER_HDCP_KEY_TRANSFER_S)


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* End of #ifndef __DRV_CIPHER_IOCTL_H__*/
