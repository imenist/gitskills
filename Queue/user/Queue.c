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
//		sys_enter_critical();            //不可中断
		Q->pBuffer[Q->in_index]=(uint32)dat;              //写入数据
		Q->in_index=(Q->in_index+1)%(Q->buf_size);//调整入口指针
		
		Q->data_count++;   //调整数据个数(此操作不可被中断)
//		sys_exit_critical();            //不可中断
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
		*pdat=Q->pBuffer[Q->out_index];  //读数据
		Q->out_index=(Q->out_index+1)%(Q->buf_size); //调整出口地址
//		sys_enter_critical();            //不可中断
		Q->data_count--;        
//		sys_exit_critical();            //不可中断
		return 1;           //读取成功，返回TRUE
	}
	else
	{
		*pdat=0;              
		return 0;          //读取失败，返回FALSE
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
		free((void *)Q->pBuffer[Q->out_index]);  //释放空间
		Q->out_index=(Q->out_index+1)%(Q->buf_size); //调整出口地址
//		sys_enter_critical();            //不可中断
		Q->data_count--;
//		sys_exit_critical();            //不可中断
	}
	
}

void QueueItemFree(void *p)
{
	free(p);
}

