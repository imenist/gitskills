#ifndef _QUEUE_H_INCLUDED_
#define _QUEUE_H_INCLUDED_

typedef unsigned char uint8;
typedef unsigned int uint32;
typedef int int32;
typedef char int8;

typedef struct QUEUE_S     
{
  uint32 in_index;            //入队地址
  uint32 out_index;           //出队地址
  uint32 buf_size;            //缓冲区长度
  uint32 *pBuffer;            //队列指针
  volatile uint32 data_count; //队列中的数据个数
  uint32 error;
}HQUEUE,*PHQUEUE;

void QueueCreate(PHQUEUE Q,uint32 *buffer,uint32 buf_size);

void QueueClear(PHQUEUE Q);

uint32 QueueGetSize(PHQUEUE Q);

int32 QueueInput(PHQUEUE Q,void **dat);

uint8 QueueOutput(PHQUEUE Q,uint32 *pdat);

void QueueItemFree(void *p);

#endif
