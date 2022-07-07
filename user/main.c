#include "led.h"
#include "beep.h"
#include "button.h"
#include "delay.h"
#include "eint.h"

void h0 (void) //����0����֮���������ҵ���߼�
{
	led_on (0);
}

void h1 (void)//����1����֮���������ҵ���߼�
{
  led_on (1);
}

void h2 (void)//����2����֮���������ҵ���߼�
{
	led_off (0);
	led_off (1);
}

int main(void)
{
	
#if 0 //��������
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
ע��:
1.�Լ�������.c����.h�ļ�,��Ҫ���ļ�����λ�ö�Ӽ�������
2.Keilʹ�õ�ʱ��û�б�Ҫʹ�����µİ汾
3.���ֵı���
4.Keil��ע��Ҳ��������ʹ��
*/


















