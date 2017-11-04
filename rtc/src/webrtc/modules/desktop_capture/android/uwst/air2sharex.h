#ifndef __AIR2SHAREX__H_
#define __AIR2SHAREX__H_

#include "cirbuf.h"

enum CMD_TYPE{
    ENUM_PIC=0,
    ENUM_START=1,
    ENUM_END=2,
    ENUM_HEART=3,
    ENUM_UNKNOWN=1000
};

#define YUV_TIMEOUT 3

#pragma pack(1)

//应用层通用数据头
typedef struct StAppCommHeader {
    int version;    //协议版本号，默认为1
    int cmd;        //数据类型，图像数据为ENUM_PIC=0
}StAppCommHeader;

//应用层数据头
typedef struct StPicHeader {
    int width;
    int height;
}StPicHeader;

typedef struct StAppHeader {
    StAppCommHeader commHeader;
    StPicHeader picHeader;
}StAppHeader;

#pragma pack()

void circle_Uninit(int flag);
int getScrennInfo(circle_header *header, int *width, int *height);
int putYuvData(circle_header * header, unsigned  char * y,  unsigned char *u , unsigned  char *v, int width, int height, int cmd);
int getYuvData(circle_header *header, void *yuvFrame, int *data_type);
int ctrlYuvData(circle_header * header, int cmd);
circle_header *circleInit(int flag);

#endif // __AIR2SHAREX__H_
