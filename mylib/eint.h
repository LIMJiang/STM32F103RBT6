#ifndef __EINT_H__
#define __EINT_H__

#include "stm32f10x_conf.h"

/*
外设  管脚   外部中断号
KEY0   PC9		EXTI9
KEY1   PC8    EXTI8
KEY2   PA0    EXTI0
KEY0 KEY1 在默认状态下呈现高电平
*/

typedef void (* eint_handler) (void); 

//初始化函数 （时钟 gpio管脚 EXTI nvic）
extern void eint_init (void);

//设置回调函数
extern void set_eint_handler (eint_handler h0, 
			eint_handler h1, eint_handler h2);

#endif

