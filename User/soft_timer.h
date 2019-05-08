/* soft_timer.c/h  3.0 */

#ifndef _SOFT_TIMER_H
#define _SOFT_TIMER_H

#include "stdint.h"


/* 软件定时器时钟节拍单位 */
#define TIME_BASE_MS			          1    //1ms

/* 软件定时器数量 */
#define TIMER_NUM                   10

/* 定时器ID */
#define TMR_STRING_PRINT            0
#define TMR_TWINKLING               1
#define TMR_DELAY_ON                2
#define TMR_xxx                     3


typedef void callback(void *argv, uint16_t argc);

typedef struct softTimer {
	uint8_t state;           //状态
	uint8_t mode;            //模式
	uint32_t match;          //到期时间
	uint32_t period;         //定时周期
	callback *cb;            //回调函数指针
	void *argv;              //参数指针
	uint16_t argc;           //参数个数
}softTimer;

typedef enum tmrState {
	SOFT_TIMER_STOPPED = 0,  //停止
	SOFT_TIMER_RUNNING,      //运行
	SOFT_TIMER_TIMEOUT       //超时
}tmrState;

typedef enum tmrMode {
	MODE_ONE_SHOT = 0,       //单次模式
	MODE_PERIODIC,           //周期模式
}tmrMode;


void tickCnt_Update(void);
uint32_t tickCnt_Get(void);
void softTimer_Init(void);
uint8_t softTimer_GetState(uint16_t id);
void softTimer_Start(uint16_t id, tmrMode mode, uint32_t delay, callback *cb, void *argv, uint16_t argc);
void softTimer_Stop(uint16_t id);
void softTimer_Update(void);

#endif //_SOFT_TIMER_H
