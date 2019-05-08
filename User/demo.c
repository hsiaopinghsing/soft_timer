
#include "demo.h"
#include "debug.h"
#include "stm32f10x.h"


/*****************************************************
* function: LED初始化
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
	
	GPIO_SetBits(GPIOB, GPIO_Pin_5 | GPIO_Pin_0);            //PC13, PC14输出高电平
}

/*****************************************************
* function: LED0闪烁
* param1:   参数指针
* param2:   参数长度 
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
* function: 点亮LED1
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
* function: 打印字符串
* param1:   参数指针
* param2:   参数长度
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
* function: 空操作
* param1:   参数指针
* param2:   参数长度
* return:   
* note:     
******************************************************/
void nop(void *argv, uint16_t argc)
{
}

