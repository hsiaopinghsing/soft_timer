
#ifndef _TIMER_H
#define _TIMER_H

#include "stdint.h"


void TIM4_NVIC_Config(void);
void TIM4_Init(uint32_t period_ms);



#endif //_TIMER_H
