
#include "stm32f10x.h"
#include "soft_timer.h"
#include "usart.h"
#include "timer.h"
#include "demo.h"
#include "debug.h"


static uint8_t data[] = {1,2,3,4,5,6,7,8,9,0};


int main(void)
{
	USART1_Init(115200);
	TIM4_Init(TIME_BASE_MS);
	TIM4_NVIC_Config();
	LED_Init();
	
	printf("I just grabbed a spoon.\r\n");
	
	softTimer_Start(TMR_STRING_PRINT, MODE_ONE_SHOT, 1000, stringPrint, data, 5);
	softTimer_Start(TMR_TWINKLING, MODE_PERIODIC, 500, LED0_Twinkling, NULL, 0);
	softTimer_Start(TMR_DELAY_ON, MODE_ONE_SHOT, 3000, nop, NULL, 0);
	
	while(1) {
		softTimer_Update();
		
		if(softTimer_GetState(TMR_DELAY_ON) == SOFT_TIMER_TIMEOUT) {
			LED1_On();
		}
	}
}


#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{ 
  printf("Wrong parameters value: file %s on line %d\r\n", file, line);

  while (1)
  {
  }
}
#endif

