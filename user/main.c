#include "led.h"
#include "beep.h"
#include "button.h"
#include "delay.h"
#include "eint.h"

void h0 (void) //按键0按下之后具体做的业务逻辑
{
	led_on (0);
}

void h1 (void)//按键1按下之后具体做的业务逻辑
{
  led_on (1);
}

void h2 (void)//按键2按下之后具体做的业务逻辑
{
	led_off (0);
	led_off (1);
}

int main(void)
{
	
#if 0 //条件编译
	int j = 0;
#endif
	
	led_init ();
	beep_init ();
	button_init ();
	delay_init ();
	eint_init ();
	
	set_eint_handler (h0, h1, h2);
	
	while (1)
	{
		beep_on ();
		delay_ms (500);
		beep_off ();
    delay_ms (500);
	}
}


/*
注意:
1.自己创建的.c或者.h文件,需要在文件最后的位置多加几个空行
2.Keil使用的时候没有必要使用最新的版本
3.汉字的编码
4.Keil不注册也可以正常使用
*/


















