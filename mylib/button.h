#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "stm32f10x_conf.h"

/*
KEY0  PC9
KEY1  PC8
KEY0 KEY1 ��û�а��µ�ʱ����ָߵ�ƽ
KEY2  PA0
*/

extern void button_init (void);
extern int button_status (int num);

#endif




