/**
  ******************************************************************************
  * @file 	main.c 
  * @author www.arm79.com
  * @date   2010-06-24
  * @brief  This file contains the headers of the interrupt handlers.
  ******************************************************************************
  */

#include "stm32f10x.h"
#include "platform_config.h"
#include "stm32f10x_usart.h"
#include "misc.h"
#include "stdio.h"
#include "stdlib.h"
#include "Queue.h"

#ifdef __GNUC__
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

 

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(UART5, USART_FLAG_TC) == RESET)
  {}
  
  /* write a character to the USART */
  USART_SendData(UART5, (uint8_t) ch);

  return ch;
}

void UART5_Config(void);
void GPIO_Configuration(void);
void Delay(vu32 Time);

#define TQ_NUM 50
typedef struct{
	uint32 a;
	uint8 b;
}T_t, *pT_t;

int main(void)
{
 	uint32 pBuff[TQ_NUM] = NULL;
	HQUEUE TQueue;
	pT_t ptest = NULL;
	
	uint32 addr;
	pT_t ptest2 = NULL;
	uint32 i = 0;
	SystemInit();
	GPIO_Configuration();
	UART5_Config();
 
	QueueCreate(&TQueue, pBuff, TQ_NUM);
	while (1)
	{
		if((ptest = (pT_t)malloc(sizeof(T_t))) !=NULL)
		{
			ptest->a = i;
			ptest->b = i;
			QueueInput(&TQueue, (void *)ptest);
		}
		
		if((ptest = (pT_t)malloc(sizeof(T_t))) !=NULL)
		{
			ptest->a = i;
			ptest->b = i;
			QueueInput(&TQueue, (void *)ptest);
		}
		if(QueueOutput(&TQueue, &addr))
		{
			ptest2 = (pT_t)addr;
			printf("a:%d,b:%d\r\n", ptest2->a, ptest2->b);
			QueueItemFree(ptest2);
		}else{
			printf("%s\r\n", "³ö¶Ó´íÎó");
		}
		Delay(0xFFFFF);
		i++;
	}
}


void UART5_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
    USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(UART5, &USART_InitStructure); 
	USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);
	USART_ITConfig(UART5, USART_IT_TXE, ENABLE);
	USART_Cmd(UART5, ENABLE);
}


void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
                         RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
                         RCC_APB2Periph_GPIOE, ENABLE);
    
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_UART5, ENABLE);
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);					 
	
	
		       
	  /* Configure USARTx_Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	/* Configure USARTx_Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
}


void Delay(vu32 Time)
{
	for(; Time != 0; Time--);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  while (1)
  {
  }
}
#endif



/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
