#include "main.h"

#include "leds.h"

#define PIN_RED				GPIO_Pin_B0
#define PIN_GREEN			GPIO_Pin_B1

void ledsInit(void)
{
	GPIO_InitSettingType GPIO_InitStructure;

	GPIO_InitStructure.Signal = GPIO_Pin_Signal_Digital;
	GPIO_InitStructure.Dir = GPIO_Direction_Output;
	GPIO_InitStructure.Func = GPIO_Reuse_Func0;
	GPIO_InitStructure.ODE = GPIO_ODE_Output_Disable;
	GPIO_InitStructure.DS = GPIO_DS_Output_Normal;
	GPIO_InitStructure.PUE = GPIO_PUE_Input_Disable;
	GPIO_InitStructure.PDE = GPIO_PDE_Input_Disable;

	GPIO_Init(GPIO_Pin_B0, &GPIO_InitStructure);
	GPIO_Init(GPIO_Pin_B1, &GPIO_InitStructure);
	
	GPIO_WriteBit(PIN_RED, 1);
	GPIO_WriteBit(PIN_GREEN, 1);
}

void ledsAct(unsigned char led, unsigned char act)
{
	
	switch(led)
	{
		case LED_RED:
			switch(act)
			{
				case ACT_OFF:
					GPIO_WriteBit(PIN_RED, 1);
					break;
					
				case ACT_ON:
					GPIO_WriteBit(PIN_RED, 0);
					break;
					
				case ACT_TOGGLE:
					GPIO_ToggleBit(PIN_RED);
					break;
			}
			break;
			
		case LED_GREEN:
			switch(act)
			{
				case ACT_OFF:
					GPIO_WriteBit(PIN_GREEN, 1);
					break;
					
				case ACT_ON:
					GPIO_WriteBit(PIN_GREEN, 0);
					break;
					
				case ACT_TOGGLE:
					GPIO_ToggleBit(PIN_GREEN);
					break;
			}
			break;
			
		case LED_YELLOW:
			switch(act)
			{
				case ACT_OFF:
					GPIO_WriteBit(PIN_RED, 1);
					GPIO_WriteBit(PIN_GREEN, 1);
					break;
					
				case ACT_ON:
					GPIO_WriteBit(PIN_RED, 0);
					GPIO_WriteBit(PIN_GREEN, 0);
					break;
					
				case ACT_TOGGLE:
					GPIO_ToggleBit(PIN_RED);
					GPIO_ToggleBit(PIN_GREEN);
					break;
			}
			break;
	}
}
