#ifndef __EINT_H__
#define __EINT_H__

#include "stm32f10x_conf.h"

/*
����  �ܽ�   �ⲿ�жϺ�
KEY0   PC9		EXTI9
KEY1   PC8    EXTI8
KEY2   PA0    EXTI0
KEY0 KEY1 ��Ĭ��״̬�³��ָߵ�ƽ
*/

typedef void (* eint_handler) (void); 

//��ʼ������ ��ʱ�� gpio�ܽ� EXTI nvic��
extern void eint_init (void);

//���ûص�����
extern void set_eint_handler (eint_handler h0, 
			eint_handler h1, eint_handler h2);

#endif

