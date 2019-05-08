/* debug.c/h  1.0 */

#include "debug.h"


#pragma import(__use_no_semihosting)

struct __FILE
{
	int handle;
};

FILE __stdout;

void _sys_exit(int x)
{
	x = x;
}

void _ttywrch(int ch)
{
  ch = ch;
}

/* 重定向printf */
int fputc(int ch, FILE *f)
{
	while((USART1->SR & 0x40) == 0);     //可选：USART1, USART2, USART3, UART4, UART5, USART6, UART7, UART8
	USART1->DR = (unsigned char) ch;     //同上
	return ch;
}

