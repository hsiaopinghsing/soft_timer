
#ifndef _DEMO_H
#define _DEMO_H

#include "stdint.h"


void LED_Init(void);
void LED0_Twinkling(void *argv, uint16_t argc);
void LED1_On(void);
void stringPrint(void *argv, uint16_t argc);
void nop(void *argv, uint16_t argc);


#endif //_DEMO_H
