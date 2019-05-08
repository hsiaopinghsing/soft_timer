
#include "timer.h"
#include "stm32f10x.h"


/*****************************************************
* function: 定时器4中断向量配置
* param:    
* return:   
* note:     
******************************************************/
void TIM4_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                 //中断分组1
  NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;       //主优先级：1
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;              //从优先级：2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

/*****************************************************
* function: 定时器4初始化
* param:    定时周期，单位ms
* return:   
* note:     
******************************************************/
void TIM4_Init(uint32_t period_ms)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	period_ms *= 10;
	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  TIM_TimeBaseStructure.TIM_Period = period_ms - 1;
  TIM_TimeBaseStructure.TIM_Prescaler = 7199;
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
  TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM4, ENABLE);
}

