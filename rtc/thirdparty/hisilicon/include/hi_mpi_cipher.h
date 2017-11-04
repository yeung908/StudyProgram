/******************************************************************************
 
  Copyright (C), 2010-2020, Huawei Tech. Co., Ltd.
 
******************************************************************************
  File Name     : hi_mpi_cipher.h
  Version       : Initial Draft
  Author        : 
  Created       : 
  Last Modified :
  Description   : 
  Function List :
******************************************************************************/
#ifndef __HI_MPI_CIPHER_H__
#define __HI_MPI_CIPHER_H__

#include "hi_unf_hdcp.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */


HI_S32 HI_MPI_CIPHER_EncryptHDCPKey(HI_UNF_HDCP_HDCPKEY_S *pstHdcpKey, HI_BOOL bIsUseOTPRootKey, HI_U8 u8OutEncryptKey[332]);
HI_S32 HI_MPI_CIPHER_LoadHDCPKey(HI_U8 *pu8EncryptedHDCPKey, HI_U32 u32Len);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* __HI_MPI_CIPHER_H__ */

