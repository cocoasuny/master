#include "includes.h"
/*
 * ��������BSP_Init
 * ����  ��ʱ�ӳ�ʼ����Ӳ����ʼ��
 * ����  ����
 * ���  ����
 */
void BSP_Init(void)
{
    SystemInit();					/* ����ϵͳʱ��Ϊ72M */	
    LED_GPIO_Config();    /* LED �˿ڳ�ʼ�� */
    USART1_Config();
		Delay_Init();
}


