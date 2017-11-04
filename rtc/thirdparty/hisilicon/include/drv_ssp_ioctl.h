#ifndef __DRV_SSP_IOCTL_H__
#define __DRV_SSP_IOCTL_H__

#include <asm/ioctl.h>
#include "hi_drv_ssp.h"

#define SSPT	's'

#define SSP_READ	_IOR(SSPT, 1, ssp_info)
#define SSP_WRITE	_IOW(SSPT, 2, ssp_info)

#endif

