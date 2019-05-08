#ifndef _USER_TIMER_H
#define _USER_TIMER_H


//定时时间
//定时器模式【单次+周期】
//定时器状态【未使用+停止+运行+完成】
//回调函数
//回调函数参数【使用指针类型传递】

typedef void (*timeout)(void *parameter);

typedef struct 
{
	  uint8_t mode;
	  uint8_t state;
	  
	  uint32_t time
		
	
	  timeout timeout_func;   // ==  void(* timeout_func)(void *parameter)  //回调函数
    void *               parameter;                                       //回调函数参数
	 
	
}user_tmr_t; 





//API
//1.init
//2.creat
//3.start
//4.stop
//5.delete











#endif /*_USER_TIMER_H*/