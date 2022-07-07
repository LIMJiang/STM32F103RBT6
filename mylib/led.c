#include "led.h"
#include "bitband.h"

void led_init (void)
{
	GPIO_InitTypeDef Led_Value;
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE);
	Led_Value.GPIO_Mode = GPIO_Mode_Out_PP;
	Led_Value.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	Led_Value.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init (GPIOC, &Led_Value);
}

void led_on (int nu)
{
	switch (nu)
	{
		case 0:
		  PCOut (1) = 1;
			break;
		case 1:
			PCOut (2) = 1; 
			break;
		case 2:
			PCOut (3) = 1;
			break;
	}
}
void led_off (int nu)
{
	switch (nu)
	{
		case 0:
			PCOut (1) = 0;
			break;
		case 1:
			PCOut (2) = 0;
			break;
		case 2:
			PCOut (3) = 0;
			break;
	}
}	





