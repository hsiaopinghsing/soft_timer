/* soft_timer.c/h  3.0 */

#ifndef _SOFT_TIMER_H
#define _SOFT_TIMER_H

#include "stdint.h"


/* �����ʱ��ʱ�ӽ��ĵ�λ */
#define TIME_BASE_MS			          1    //1ms

/* �����ʱ������ */
#define TIMER_NUM                   10

/* ��ʱ��ID */
#define TMR_STRING_PRINT            0
#define TMR_TWINKLING               1
#define TMR_DELAY_ON                2
#define TMR_xxx                     3


typedef void callback(void *argv, uint16_t argc);

typedef struct softTimer {
	uint8_t state;           //״̬
	uint8_t mode;            //ģʽ
	uint32_t match;          //����ʱ��
	uint32_t period;         //��ʱ����
	callback *cb;            //�ص�����ָ��
	void *argv;              //����ָ��
	uint16_t argc;           //��������
}softTimer;

typedef enum tmrState {
	SOFT_TIMER_STOPPED = 0,  //ֹͣ
	SOFT_TIMER_RUNNING,      //����
	SOFT_TIMER_TIMEOUT       //��ʱ
}tmrState;

typedef enum tmrMode {
	MODE_ONE_SHOT = 0,       //����ģʽ
	MODE_PERIODIC,           //����ģʽ
}tmrMode;


void tickCnt_Update(void);
uint32_t tickCnt_Get(void);
void softTimer_Init(void);
uint8_t softTimer_GetState(uint16_t id);
void softTimer_Start(uint16_t id, tmrMode mode, uint32_t delay, callback *cb, void *argv, uint16_t argc);
void softTimer_Stop(uint16_t id);
void softTimer_Update(void);

#endif //_SOFT_TIMER_H
