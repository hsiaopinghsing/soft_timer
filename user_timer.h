#ifndef _USER_TIMER_H
#define _USER_TIMER_H


//��ʱʱ��
//��ʱ��ģʽ������+���ڡ�
//��ʱ��״̬��δʹ��+ֹͣ+����+��ɡ�
//�ص�����
//�ص�����������ʹ��ָ�����ʹ��ݡ�

typedef void (*timeout)(void *parameter);

typedef struct 
{
	  uint8_t mode;
	  uint8_t state;
	  
	  uint32_t time
		
	
	  timeout timeout_func;   // ==  void(* timeout_func)(void *parameter)  //�ص�����
    void *               parameter;                                       //�ص���������
	 
	
}user_tmr_t; 





//API
//1.init
//2.creat
//3.start
//4.stop
//5.delete











#endif /*_USER_TIMER_H*/