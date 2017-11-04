#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>    
#include <fcntl.h> 
#include <unistd.h>
#include "air2sharex.h"

#define SHM_NAME "/tmp/shareX.log"
#define SHM_SIZE  (1024 * 1024 * 24)
#define PROTO_VERSION 1

static void *mapAddr  = NULL;
static int shmid = -1 ;

void circle_Uninit(int flag)
{
    if(mapAddr != NULL) {
        int iRet = munmap(mapAddr , SHM_SIZE);
        mapAddr = NULL;
    }

    if(shmid>0) {
        close(shmid);
    }
    shmid = -1 ;
}

// seewo air(flag = 1) , shareX(flag = 0)
circle_header *circleInit(int flag) 
{
    shmid = open(SHM_NAME , O_RDWR|O_CREAT , 0666);
    if(shmid < 0)
    {
        return NULL;
    }
    else
    {
        int  prot =  PROT_READ | PROT_WRITE ;
        ftruncate(shmid , SHM_SIZE);
        void *addr = mmap(NULL , SHM_SIZE , prot , MAP_SHARED, shmid , 0) ; 
        circle_header * header ;
        if(addr == NULL)
        {
            return NULL;
        }

        mapAddr = addr ;
        header = (circle_header *)addr;
        if(flag == 0)
            circle_init(header , SHM_SIZE-sizeof(circle_header));
        return header;
    }
}

int ctrlYuvData(circle_header * header, int cmd)
{
    if( (int)circle_freesize(header) > sizeof(StAppHeader))
    {
        StAppHeader appHeader;
        appHeader.commHeader.version = PROTO_VERSION;
        appHeader.commHeader.cmd = cmd;
        appHeader.picHeader.width = 0;
        appHeader.picHeader.height = 0;
        circle_put(header, &appHeader, sizeof(StAppHeader));
        return sizeof(StAppHeader) ;
    }
    else 
    {
        return -1;
    }
}

int putYuvData(circle_header * header , unsigned char * y ,  unsigned char *u , unsigned char *v , int width , int height, int cmd)
{
    static unsigned int fps = 0 ;
    if(fps++ % 3 != 0)    //seewoAir帧率25fps，这样会导致cvtouch机器cpu升高，在此做个简单的降帧率
       return 0 ;

    int y_size = width * height ;
    int u_size = width/2 * height/2 ;

    if( (int)circle_freesize(header) > (y_size * 3 / 2 + sizeof(StAppHeader)))
    {
        StAppHeader appHeader;
        appHeader.commHeader.version = PROTO_VERSION;
        appHeader.commHeader.cmd = cmd;
        appHeader.picHeader.width = width;
        appHeader.picHeader.height = height;

        circle_put(header , &appHeader , sizeof(StAppHeader));
        circle_put(header , y , y_size);
        circle_put(header , u , u_size);
        circle_put(header , v , u_size);

        return y_size * 3 / 2  + sizeof(StAppHeader) ;
    }
    else 
    {
        return -1;
    }
        
}

int getScrennInfo(circle_header *header, int *width, int *height) {

    StAppHeader appHeader;
    if(circle_size(header) > sizeof(StAppHeader)) {
        circle_peek(header , &appHeader , sizeof(StAppHeader));
        int size = appHeader.picHeader.width * appHeader.picHeader.height * 3 / 2 ;
        if(circle_size(header) >= (size + sizeof(StAppHeader))) {
            *width = appHeader.picHeader.width;
            *height = appHeader.picHeader.height;
            return -1;
       }
    }
    return 0;
}

int getYuvData(circle_header *header , void *yuvFrame , int *data_type)
{
    StAppHeader appHeader;
    if(circle_size(header) > sizeof(StAppHeader))
    {
        int size ;
        circle_peek(header , &appHeader , sizeof(StAppHeader));
        size = appHeader.picHeader.width * appHeader.picHeader.height * 3 / 2 ;
        if(circle_size(header) >= (size + sizeof(StAppHeader)))
        {
            *data_type = appHeader.commHeader.cmd;

            circle_get(header , &appHeader, sizeof(StAppHeader));
            circle_get(header , yuvFrame , size);

            return size;
       }
    }
    return 0;
}
