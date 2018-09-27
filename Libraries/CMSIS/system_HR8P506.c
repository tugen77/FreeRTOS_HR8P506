/******************************************************************************************
* Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd
* 文件名:  system_HR8P506.c
* 作  者:  ESM Application Team in
* 版  本:  V1.00
* 日  期:  2015/10/27
* 描  述:  HR8P506系列芯片初始化文件
* 备  注:  适用于HR8P506系列芯片
*          本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
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
//	GPIO_InitSettingType GPIO_InitTmp;							//定义结构体变量
//	SYSTICK_InitStruType SYSTICK_InitTmp;

	//打开所有外设时钟
	DeviceClockAllEnable();

	//打开所有外设时钟
	DeviceClockAllEnable();
	//原始时钟源选择为外部晶振
	SCU_SysClkSelect(SCU_CLK_XTAL);
	//打开PLL锁相环,输入为内部HRC 16M,输出为48M,系统时钟使用PLL
	PLLClock_Config(Enable,SCU_PLL_OUT8M,SCU_PLL_48M,Enable);
	//系统时钟后分频为1:1
	SCU_RegUnLock();
	SCU_SysClk_Div1();
	SCU_RegLock();

#if 0
	GPIO_InitTmp.Func	= GPIO_Reuse_Func0;				//管脚功能定义为功能0
	GPIO_InitTmp.Dir 	= GPIO_Direction_Output;		//设置为输出
	GPIO_InitTmp.DS		= GPIO_DS_Output_Normal;		//普通电流
	GPIO_InitTmp.ODE	= GPIO_ODE_Output_Disable;		//开漏禁止
	GPIO_InitTmp.PDE	= GPIO_PDE_Input_Disable;		//弱下拉禁止
	GPIO_InitTmp.PUE	= GPIO_PUE_Input_Disable;		//弱上拉禁止
	GPIO_InitTmp.Signal = GPIO_Pin_Signal_Digital;		//管脚类型为数字模式
	GPIO_Init(GPIO_Pin_B0,&GPIO_InitTmp);				//初始化管脚
	GPIO_Init(GPIO_Pin_B1,&GPIO_InitTmp);

	SYSTICK_InitTmp.SysTick_ClkSource = SysTick_ClkS_Cpu;			//时钟源为系统时钟
	SYSTICK_InitTmp.SysTick_ITEnable = Enable;						//中断使能
	SYSTICK_InitTmp.SysTick_Value = 48000000;						// 1S	
	SysTick_Init(&SYSTICK_InitTmp);									// 开启系统定时器
	SysTick_Enable();
#endif
}

#if 0
//中断函数
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
