#ifndef _QUEUE_H_INCLUDED_
#define _QUEUE_H_INCLUDED_

typedef unsigned char uint8;
typedef unsigned int uint32;
typedef int int32;
typedef char int8;

typedef struct QUEUE_S     
{
  uint32 in_index;            //��ӵ�ַ
  uint32 out_index;           //���ӵ�ַ
  uint32 buf_size;            //����������
  uint32 *pBuffer;            //����ָ��
  volatile uint32 data_count; //�����е����ݸ���
  uint32 error;
}HQUEUE,*PHQUEUE;

void QueueCreate(PHQUEUE Q,uint32 *buffer,uint32 buf_size);

void QueueClear(PHQUEUE Q);

uint32 QueueGetSize(PHQUEUE Q);

int32 QueueInput(PHQUEUE Q,void **dat);

uint8 QueueOutput(PHQUEUE Q,uint32 *pdat);

void QueueItemFree(void *p);

#endif
