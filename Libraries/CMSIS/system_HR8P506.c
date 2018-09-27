/******************************************************************************************
* Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd
* �ļ���:  system_HR8P506.c
* ��  ��:  ESM Application Team in
* ��  ��:  V1.00
* ��  ��:  2015/10/27
* ��  ��:  HR8P506ϵ��оƬ��ʼ���ļ�
* ��  ע:  ������HR8P506ϵ��оƬ
*          ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
*******************************************************************************************/

//#include "system_HR8P506.h"
//#include "HR8P506.h"
//#include "lib_scu.h"
//#include "lib_gpio.h"

#include "system_HR8P506.h"
#include "HR8P506.h"
#include "lib_scu.h"
#include "lib_gpio.h"
#include "lib_scs.h"
#include "type.h"

const uint32_t SystemCoreClock = 48000000;

void SystemInit(void)
{
//	GPIO_InitSettingType GPIO_InitTmp;							//����ṹ�����
//	SYSTICK_InitStruType SYSTICK_InitTmp;

	//����������ʱ��
	DeviceClockAllEnable();

	//����������ʱ��
	DeviceClockAllEnable();
	//ԭʼʱ��Դѡ��Ϊ�ⲿ����
	SCU_SysClkSelect(SCU_CLK_XTAL);
	//��PLL���໷,����Ϊ�ڲ�HRC 16M,���Ϊ48M,ϵͳʱ��ʹ��PLL
	PLLClock_Config(Enable,SCU_PLL_OUT8M,SCU_PLL_48M,Enable);
	//ϵͳʱ�Ӻ��ƵΪ1:1
	SCU_RegUnLock();
	SCU_SysClk_Div1();
	SCU_RegLock();

#if 0
	GPIO_InitTmp.Func	= GPIO_Reuse_Func0;				//�ܽŹ��ܶ���Ϊ����0
	GPIO_InitTmp.Dir 	= GPIO_Direction_Output;		//����Ϊ���
	GPIO_InitTmp.DS		= GPIO_DS_Output_Normal;		//��ͨ����
	GPIO_InitTmp.ODE	= GPIO_ODE_Output_Disable;		//��©��ֹ
	GPIO_InitTmp.PDE	= GPIO_PDE_Input_Disable;		//��������ֹ
	GPIO_InitTmp.PUE	= GPIO_PUE_Input_Disable;		//��������ֹ
	GPIO_InitTmp.Signal = GPIO_Pin_Signal_Digital;		//�ܽ�����Ϊ����ģʽ
	GPIO_Init(GPIO_Pin_B0,&GPIO_InitTmp);				//��ʼ���ܽ�
	GPIO_Init(GPIO_Pin_B1,&GPIO_InitTmp);

	SYSTICK_InitTmp.SysTick_ClkSource = SysTick_ClkS_Cpu;			//ʱ��ԴΪϵͳʱ��
	SYSTICK_InitTmp.SysTick_ITEnable = Enable;						//�ж�ʹ��
	SYSTICK_InitTmp.SysTick_Value = 48000000;						// 1S	
	SysTick_Init(&SYSTICK_InitTmp);									// ����ϵͳ��ʱ��
	SysTick_Enable();
#endif
}

#if 0
//�жϺ���
void SysTick_IRQHandler(void)
{
//	GPIO_ToggleBit(GPIO_Pin_B1);
}
#endif

void NMI_IRQHandler(void)
{
    
}

void HardFault_IRQHandler(void)
{
    while(1)
    {
    }
}

void SVC_IRQHandler(void)
{
    
}

void PendSV_IRQHandler(void)
{
    
}
