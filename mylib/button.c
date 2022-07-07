#include "button.h"
#include "bitband.h"

void button_init (void)
{
	
	GPIO_InitTypeDef Button_Value;
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA 
										| RCC_APB2Periph_GPIOC, ENABLE);
	
	Button_Value.GPIO_Mode = GPIO_Mode_IPU;
	Button_Value.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_Init (GPIOC, &Button_Value);
	
	Button_Value.GPIO_Mode = GPIO_Mode_IPD;
	Button_Value.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init (GPIOA, &Button_Value);
}


int button_status (int num)
{
	//接受按键的返回值
	int  ret = 0;
	switch (num)
	{
		case 0:
			ret = PCIn (9);
			break;
		case 1:
			ret = PCIn (8);
			break;
		case 2:
			ret = PAIn (0);
		  ret = !ret;
			break;
	}
	return !ret;
}











