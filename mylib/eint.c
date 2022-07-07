#include "eint.h"

eint_handler e_h0, e_h1, e_h2;

//�ⲿ�жϵĳ�ʼ��
void eint_init (void)
{
	GPIO_InitTypeDef Button_Value;
	NVIC_InitTypeDef Nvic_Value; 
	EXTI_InitTypeDef Exti_Value;
	
	//ʹ��ʱ��
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC 
	| RCC_APB2Periph_AFIO, ENABLE);
	
	//��ʼ��GPIO�ܽ�
	Button_Value.GPIO_Mode = GPIO_Mode_IPU;
	Button_Value.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_Init (GPIOC, &Button_Value);
	
	Button_Value.GPIO_Mode = GPIO_Mode_IPD;
	Button_Value.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init (GPIOA, &Button_Value);
	
	//ΪEXTI9ѡ����PC9�ܽŴ���
	GPIO_EXTILineConfig (GPIO_PortSourceGPIOC, GPIO_PinSource9);
	//ΪEXTI8ѡ����PC8�ܽŴ���
	GPIO_EXTILineConfig (GPIO_PortSourceGPIOC, GPIO_PinSource8);
	//ΪEXTI0ѡ����PA0�ܽŴ���
	GPIO_EXTILineConfig (GPIO_PortSourceGPIOA, GPIO_PinSource0);
	
	NVIC_PriorityGroupConfig (NVIC_PriorityGroup_2);
	//ѡ���ⲿ�ж�5~9���жϺ�
	Nvic_Value.NVIC_IRQChannel = EXTI9_5_IRQn;
	Nvic_Value.NVIC_IRQChannelCmd = ENABLE;
	Nvic_Value.NVIC_IRQChannelPreemptionPriority = 2;
	Nvic_Value.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init (&Nvic_Value);
	
	//ѡ�����ⲿ�ж�0���жϺ�
	Nvic_Value.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_Init (&Nvic_Value);

	Exti_Value.EXTI_Line = EXTI_Line8 | EXTI_Line9;
	Exti_Value.EXTI_LineCmd = ENABLE;
	Exti_Value.EXTI_Mode = EXTI_Mode_Interrupt;
	Exti_Value.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init (&Exti_Value);
	
	Exti_Value.EXTI_Line = EXTI_Line0;
	Exti_Value.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init (&Exti_Value);
}

void EXTI9_5_IRQHandler (void)
{
	//�ж��Ƿ���EXTI9�������ж�
	if (EXTI_GetITStatus (EXTI_Line9) == SET)
	{
		e_h0(); //����KEY0��������֮�����ҵ��
		EXTI_ClearITPendingBit (EXTI_Line9);
	}
	
	//�ж��Ƿ���EXTI8�������ж�
	if (EXTI_GetITStatus (EXTI_Line8) == SET)
	{
		e_h1(); //����KEY1��������֮�����ҵ��
		EXTI_ClearITPendingBit (EXTI_Line8);
	}
}

void EXTI0_IRQHandler (void)
{
	//�ж��Ƿ���EXTI8�������ж�
	if (EXTI_GetITStatus (EXTI_Line0) == SET)
	{
		e_h2(); //����KEY2��������֮�����ҵ��
		EXTI_ClearITPendingBit (EXTI_Line0);
	}
}

void set_eint_handler (eint_handler h0, 
			eint_handler h1, eint_handler h2)
{
	//ת�� dump
	e_h0 = h0;
	e_h1 = h1;
	e_h2 = h2;
}












