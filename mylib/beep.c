#include "beep.h"
#include "bitband.h"


void beep_init (void)
{
	GPIO_InitTypeDef Beep_Value;
	//ʹ��ʱ��
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE);
	
	//ѡ���������
	Beep_Value.GPIO_Mode = GPIO_Mode_Out_PP;
	Beep_Value.GPIO_Pin = GPIO_Pin_7;
	Beep_Value.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init (GPIOC, &Beep_Value);
}

void beep_on (void)
{
	PCOut (7) = 1;
}

void beep_off (void)
{
	PCOut (7) = 0;
}












