#include "Queue.h"
#include "stdlib.h"


void QueueCreate(PHQUEUE Q,uint32 *buffer,uint32 buf_size)
{
  Q->pBuffer=buffer;
  Q->buf_size=buf_size;
  QueueClear(Q);
}

uint32 QueueGetSize(PHQUEUE Q)
{
  return Q->data_count;
}


int32 QueueInput(PHQUEUE Q,void **dat)
{
	if(Q->data_count<Q->buf_size)
	{
//		sys_enter_critical();            //�����ж�
		Q->pBuffer[Q->in_index]=(uint32)dat;              //д������
		Q->in_index=(Q->in_index+1)%(Q->buf_size);//�������ָ��
		
		Q->data_count++;   //�������ݸ���(�˲������ɱ��ж�)
//		sys_exit_critical();            //�����ж�
		return 1;
	}
	else
	{
		if(Q->error<0xffffffff)
			Q->error++;
		return -1;
	}
}



uint8 QueueOutput(PHQUEUE Q,uint32 *pdat)
{
	if(Q->data_count>0)
	{
		*pdat=Q->pBuffer[Q->out_index];  //������
		Q->out_index=(Q->out_index+1)%(Q->buf_size); //�������ڵ�ַ
//		sys_enter_critical();            //�����ж�
		Q->data_count--;        
//		sys_exit_critical();            //�����ж�
		return 1;           //��ȡ�ɹ�������TRUE
	}
	else
	{
		*pdat=0;              
		return 0;          //��ȡʧ�ܣ�����FALSE
	}    
}

void QueueClear(PHQUEUE Q)
{

	Q->in_index=0;
	Q->out_index=0;
	Q->data_count=0;
	Q->error=0;

	while(Q->data_count>0)
	{
		Q->pBuffer[Q->out_index] = 0;
		free((void *)Q->pBuffer[Q->out_index]);  //�ͷſռ�
		Q->out_index=(Q->out_index+1)%(Q->buf_size); //�������ڵ�ַ
//		sys_enter_critical();            //�����ж�
		Q->data_count--;
//		sys_exit_critical();            //�����ж�
	}
	
}

void QueueItemFree(void *p)
{
	free(p);
}

