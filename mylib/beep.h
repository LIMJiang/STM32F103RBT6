#ifndef __BEEP_H_
#define __BEEP_H_

#include "stm32f10x_conf.h"
/*
BEEP ---> PC7
输出高电平  响
输出低电平	不响
*/
extern void beep_init (void);
extern void beep_on (void);
extern void beep_off (void);

#endif






