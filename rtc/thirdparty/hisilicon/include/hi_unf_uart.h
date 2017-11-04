#ifndef  __HI_UNF_UART_H__
#define  __HI_UNF_UART_H__

#include "hi_unf_common.h"
#include "hi_error_mpi.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/**
\brief  get working uart NO. CNcomment:获取当前工作的是哪个串口 CNend
\retval uart NO success. CNcomment:串口号 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
*/
HI_S32 HI_UNF_UART_GetUart(HI_VOID);


/**
\brief switch to specific uart. CNcomment:切换到指定串口 CNend
\param[in] ttyAMA   spec uart. CNcomment:指定串口号 CNend
\retval HI_SUCCESS success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
CNcomment:无 CNend
*/
HI_S32 HI_UNF_UART_Switch(HI_S32 ttyAMA);


/**
\brief initialize uart. CNcomment:打开并初始化串口 CNend
\retval HI_SUCCESS success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
\attention
\brief uart1 operation will not be effective until initialization except HI_UNF_UART_Switch and HI_UNF_UART_GetUart
 CNcomment:操作串口1之前要先初始化，切换串口和获取串口操作除外 CNend
\brief default received buff size of uart is 1000B, you can change it with -DHI_UART_BUFLEN=XXX in Makefile
 CNcomment:默认的uart接收缓存为1000字节，可以通过在Makefie中设置大小-DHI_UART_BUFLEN=XXX CNend
*/
HI_S32 HI_UNF_UART_Init(HI_VOID);


/**
\brief get uart attribute. CNcomment:获取串口属性 CNend
\param[out] databits   data bits. CNcomment:数据位 CNend
\param[out] stopbits   stop bits. CNcomment:停止位 CNend
\param[out] parity   parity. CNcomment:奇偶位 CNend
\retval HI_SUCCESS success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
*/
HI_S32 HI_UNF_UART_GetAttribute(HI_S32 *databits, HI_S32 *stopbits, HI_CHAR *parity);


/**
\brief set uart attribute. CNcomment:设置串口属性 CNend
\param[in] databits   data bits. CNcomment:数据位 CNend
\param[in] stopbits   stop bits. CNcomment:停止位 CNend
\param[in] parity   parity. CNcomment:奇偶位 CNend
\retval HI_SUCCESS success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
*/
HI_S32 HI_UNF_UART_SetAttribute(HI_S32 databits, HI_S32 stopbits, HI_CHAR parity);


/**
\brief get uart baud speed. CNcomment:获取串口波特率 CNend
\param[out] speed   baud speed. CNcomment:波特率 CNend
\retval HI_SUCCESS success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
*/
HI_S32 HI_UNF_UART_GetSpeed(HI_S32 *speed);


/**
\brief set uart baud speed. CNcomment:设置串口波特率 CNend
\param[in] speed   baud speed. CNcomment:波特率 CNend
\retval HI_SUCCESS success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
*/
HI_S32 HI_UNF_UART_SetSpeed(HI_S32 speed);


/**
\brief set interval of reading data.
 CNcomment:接收数据超时值 CNend
\param[in] tmout   interval(ms). CNcomment:超时值 CNend
\retval HI_SUCCESS success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
*/
HI_S32 HI_UNF_UART_SetTimeOut(HI_S32 tmout);


/**
\brief read data from uart. CNcomment:读取串口数据 CNend
\param[out] buff   data buffer. CNcomment:数据缓存 CNend
\param[in] len   buffer length. CNcomment:缓存大小 CNend
\retval number of read data success. CNcomment:返回读取到的数据大小 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
*/
HI_S32 HI_UNF_UART_Read(HI_PCHAR buff, HI_U32 len);


/**
\brief get total number of received. CNcomment:获取串口接收数据总数 CNend
\retval number of received data success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
*/
HI_S32 HI_UNF_UART_GetTotal(HI_VOID);


/**
\brief reset total number of received. CNcomment:串口接收总数清零 CNend
\retval HI_SUCCESS success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
*/
HI_S32 HI_UNF_UART_ResetTotal(HI_VOID);


/**
\brief discard uart data in FIFO and reset total number. CNcomment:丢弃串口缓存中的数据并清零计数 CNend
\retval HI_SUCCESS success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
*/
HI_S32 HI_UNF_UART_Flush(HI_VOID);


/**
\brief wirte data to uart. CNcomment:写入数据至串口 CNend
\param[in] buff   data buffer. CNcomment:数据缓存 CNend
\param[in] len   buffer length. CNcomment:发送大小 CNend
\retval number of written data success. CNcomment:成功发送数据大小 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
*/
HI_S32 HI_UNF_UART_Write(HI_PCHAR buff, HI_U32 len);


/**
\brief de-initialize uart. CNcomment:关闭并清空串口 CNend
\retval HI_SUCCESS success. CNcomment:成功 CNend
\retval please refer to the err code definitino of mpi.CNcomment:请参考MPI错误码 CNend
*/
HI_S32 HI_UNF_UART_DeInit(HI_VOID);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif  /*__HI_UNF_AI_H__*/
