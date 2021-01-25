#include "key.h"
#include "sys.h"
#include "stm32f10x.h"


void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//ʹ��PORTA,PORTEʱ��

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_3;//KEY0-KEY1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOE, &GPIO_InitStructure);//��ʼ��GPIOE4,3
	
	//��ʼ�� WK_UP-->GPIOA.0	  ��������
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0���ó����룬Ĭ������	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.0
}
//�����ɿ�Ϊ key_up=1
//mode=1Ϊ����ģʽ
u8 KEY_Press(u8 mode)
{
	static u8 key_up=1; 
	if(mode==1) key_up=1;
	if(key_up==1&&(KEY0==0||KEY1==0||WK_UP==1))
	{
		key_up=0;
		if(KEY0==0) return 1;
		else if(KEY1==0) return 2;
		else if(WK_UP==1) return 3;
	}
	else return 0;
}
