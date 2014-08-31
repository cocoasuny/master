#include "includes.h"
/*
 * 函数名：BSP_Init
 * 描述  ：时钟初始化、硬件初始化
 * 输入  ：无
 * 输出  ：无
 */
void BSP_Init(void)
{
    SystemInit();					/* 配置系统时钟为72M */	
    LED_GPIO_Config();    /* LED 端口初始化 */
    USART1_Config();
		Delay_Init();
}


