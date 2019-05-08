
#include "demo.h"
#include "debug.h"
#include "stm32f10x.h"


/*****************************************************
* function: LED��ʼ��
* param:    
* return:   
* note:     
******************************************************/
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_5 | GPIO_Pin_0);            //PC13, PC14����ߵ�ƽ
}

/*****************************************************
* function: LED0��˸
* param1:   ����ָ��
* param2:   �������� 
* return:   
* note:     
******************************************************/
void LED0_Twinkling(void *argv, uint16_t argc)
{
	static uint8_t on = 1;
	
	if(on) {
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);
		on = 0;
	} else {
		GPIO_SetBits(GPIOB, GPIO_Pin_5);
		on = 1;
	}
}

/*****************************************************
* function: ����LED1
* param1:   
* param2:   
* return:   
* note:     
******************************************************/
void LED1_On(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_0);
}

/*****************************************************
* function: ��ӡ�ַ���
* param1:   ����ָ��
* param2:   ��������
* return:   
* note:     
******************************************************/
void stringPrint(void *argv, uint16_t argc)
{
	uint16_t i;
	for(i=0; i<argc; i++) {
		printf("%d", *((uint8_t*)argv + i));
	}
	printf("\r\n");
}

/*****************************************************
* function: �ղ���
* param1:   ����ָ��
* param2:   ��������
* return:   
* note:     
******************************************************/
void nop(void *argv, uint16_t argc)
{
}

