#include "stm32f10x.h"
#include "led.h"
#include "beep.h"
#include "delay.h"
#include "sys.h"
#include "key.h"

int main(void)
{
	delay_init();
	Init_LED();
	BEEP_Init();
  KEY_Init();
	while(1)
	{
		u8 key_op;
		key_op=KEY_Press(1);
		if(key_op!=0)
		{
			if(key_op==1) LED0=0;
			else if(key_op==2) LED1=0;
			else BEEP=1;
			delay_ms(300);
			delay_ms(200);
		}
		LED0=1;
		LED1=1;
		BEEP=0;
	}
}
