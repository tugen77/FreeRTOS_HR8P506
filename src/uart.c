/*********************************Copyright (c)*********************************
  *                              jmqiu@icwiser.com
  ******************************************************************************
  * 文件名称：uart.c
  * 描    述：串口通信模块
  * 创 建 者: Eric Qiu
  * 创建日期: 2015-05-11
  * 修 改 者:
  * 修改日期: 2015-05-11
  * 版    本: v1.0.0
  ******************************************************************************
  * attention
  *
  ******************************************************************************
  */

#include "main.h"

void Uart0Init(unsigned int baudrate)
{
	GPIO_InitSettingType GPIO_InitTmp;					//定义结构体变量
	UART_InitStruType UART_InitTmp;
	
	GPIO_InitTmp.Signal = GPIO_Pin_Signal_Digital;
	GPIO_InitTmp.Func = GPIO_Reuse_Func1;
	GPIO_InitTmp.Dir = GPIO_Direction_Output;
	GPIO_InitTmp.ODE = GPIO_ODE_Output_Disable;
	GPIO_InitTmp.DS = GPIO_DS_Output_Strong;
	GPIO_Init(GPIO_Pin_A23, &GPIO_InitTmp); 				//TXD - PA23
	
	GPIO_InitTmp.Signal = GPIO_Pin_Signal_Digital;
	GPIO_InitTmp.Func = GPIO_Reuse_Func1;
	GPIO_InitTmp.Dir = GPIO_Direction_Input;
	GPIO_InitTmp.PUE = GPIO_PUE_Input_Disable;
	GPIO_InitTmp.PDE = GPIO_PDE_Input_Disable;
	GPIO_Init(GPIO_Pin_A22, &GPIO_InitTmp); 				//RXD - PA22
	
	UART_InitTmp.UART_BaudRate = baudrate; 						
	UART_InitTmp.UART_ClockSet = UART_Clock_1; 				//Pclk
	UART_InitTmp.UART_RxMode = UART_DataMode_8; 			//8Data
	UART_InitTmp.UART_RxPolar = UART_Polar_Normal; 			//
	UART_InitTmp.UART_StopBits = UART_StopBits_1; 			//
	UART_InitTmp.UART_TxMode = UART_DataMode_8; 			//8Data
	UART_InitTmp.UART_TxPolar = UART_Polar_Normal; 			//
	UART_Init(UART0, &UART_InitTmp);
	
	UART_TBIMConfig(UART0, UART_TBIM_Full);
	UART_RBIMConfig(UART0, UART_TBIM_Byte);
	UART_ITConfig(UART0, UART_IT_RB, Enable);
	UART_ITConfig(UART0, UART_IT_TB, Disable);				//发送缓冲空
	NVIC_Init(NVIC_UART0_IRQn, NVIC_Priority_1, Enable);

	UART0_TxEnable();
	UART0_RxEnable();
}

void Uart0PutChar(unsigned char data)
{
	UART_SendByte(UART0, data);
	while(UART_GetFlagStatus(UART0, UART_FLAG_TC) == RESET);
}

void UART0_IRQHandler(void)
{
	unsigned char   g_rxbuf;
	// RX
	if ((UART_GetITStatus(UART0,UART_IT_RB) != RESET) && (UART_GetFlagStatus(UART0,UART_FLAG_RB) != RESET))
	{
		g_rxbuf = UART_RecByte(UART0);
		Uart0PutChar(g_rxbuf + 1);
	}	

	if (UART_GetITStatus(UART0,UART_IT_TB) != RESET)		//发送缓冲空中断
	{
		;
	}
}



