#include "stm32f10x.h"
#include "SysTick.h"

static unsigned char  fac_us=0;//us��ʱ������
static unsigned short fac_ms=0;//ms��ʱ������

/*******************************************************************************
* Function Name  : Delay_Init
* Description    : Configures Delay������ϵͳ�δ�ʱ�Ӷ�ʱ
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void Delay_Init(void)	 
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//ѡ���ⲿʱ��  HCLK/8
	fac_us=SystemCoreClock/8000000;	//Ϊϵͳʱ�ӵ�1/8  
	fac_ms=(unsigned short)fac_us*1000;//��ucos��,����ÿ��ms��Ҫ��systickʱ����   
}
/*******************************************************************************
* Function Name  : Delay_us
* Description    : us��ʱ����
* Input          : ��ʱʱ�䣨n us��
* Output         : None
* Return         : None
*******************************************************************************/
void Delay_us(unsigned int nus)
{		
	unsigned int temp;	    	 
	SysTick->LOAD=nus*fac_us; //ʱ�����	  		 
	SysTick->VAL=0x00;        //��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;//��ʼ����	 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;//�رռ�����
	SysTick->VAL =0X00; //��ռ�����
}
/*******************************************************************************
* Function Name  : Delay_ms
* Description    : ms��ʱ����
* Input          : ��ʱʱ��(n ms)ע����ʱnms��Χ��SysTick->LOADΪ24λ�Ĵ���,����,
*                  �����ʱΪ: nms<=0xffffff*8*1000/SYSCLK��SYSCLK��λΪHz,nms��λΪms
*                  ��8M������,nms<=16777
* Output         : None
* Return         : None
*******************************************************************************/
void Delay_ms(unsigned short nms)
{	 		  	  
	unsigned int  temp;		   
	SysTick->LOAD=(unsigned int)nms*fac_ms;//ʱ�����(SysTick->LOADΪ24bit)
	SysTick->VAL =0x00; //��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk; //��ʼ����  
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;//�رռ�����
	SysTick->VAL =0X00;//��ռ�����	 
} 








