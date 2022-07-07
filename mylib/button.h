#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "stm32f10x_conf.h"

/*
KEY0  PC9
KEY1  PC8
KEY0 KEY1 在没有按下的时候呈现高电平
KEY2  PA0
*/

extern void button_init (void);
extern int button_status (int num);

#endif




