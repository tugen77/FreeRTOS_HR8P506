/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_uart.c
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  UARTģ��⺯��
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#include "lib_uart.h"
#include "system_HR8P506.h"

/*************************************
  ��������UART_Init
  ��  ����UART��ʼ��
  ����ֵ��UART0/UART1
  ��ʼ���ṹ��
  ����ֵ����
 **************************************/
void UART_Init(UART_TypeDef *UARTx, UART_InitStruType *UART_InitStruct)
{
	float tmp;
	uint32_t baud;
	
		tmp = 0;
	if (UART_InitStruct->UART_ClockSet == UART_Clock_1) {
		tmp  = (float)SystemCoreClock / (float)(16 * UART_InitStruct->UART_BaudRate);
	}
	else if (UART_InitStruct->UART_ClockSet == UART_Clock_2) {
		tmp  = (float)SystemCoreClock / (float)(32 * UART_InitStruct->UART_BaudRate);
	}
	else if (UART_InitStruct->UART_ClockSet == UART_Clock_3) {
		tmp  = (float)SystemCoreClock / (float)(64 * UART_InitStruct->UART_BaudRate);
	}
	else if (UART_InitStruct->UART_ClockSet == UART_Clock_4) {
		tmp  = (float)SystemCoreClock / (float)(128 * UART_InitStruct->UART_BaudRate);
	}

	tmp = tmp < 1.0 ? 1.0 : tmp;
	baud = (uint32_t)(tmp * 16);

	UARTx->CON1.BCS   = UART_InitStruct->UART_ClockSet;
	UARTx->BRR.Word   = baud;
	UARTx->CON0.TXFS  = UART_InitStruct->UART_StopBits;
	UARTx->CON0.TXMOD = UART_InitStruct->UART_TxMode;
	UARTx->CON0.TXP   = UART_InitStruct->UART_TxPolar;
	UARTx->CON0.RXMOD = UART_InitStruct->UART_RxMode;
	UARTx->CON0.RXP   = UART_InitStruct->UART_RxPolar;

	return;
}

/*************************************
  ��������UART_AutoBaudConfig
  ��  ����UART�Զ����ò����ʲ����ز�����
  ����ֵ��UART0/UART1
	  mode:���ģʽѡ��
  ����ֵ����⵽�Ĳ����ʵ�ֵ�����Ϊ0��������ʧ��
 **************************************/
void UART_AutoBaudConfig(UART_TypeDef *UARTx,UART_AUTO_BAUD_MODE mode)
{
	UARTx->CON1.BDM = mode;
	UARTx->CON0.BDEN = 1;
}

/*************************************
  ��������UART_BaudFreeConfig
  ��  ����UART���м��
  ����ֵ��UART0/UART1
	  mode:���ģʽѡ��
  ����ֵ����⵽�Ĳ����ʵ�ֵ�����Ϊ0��������ʧ��
 **************************************/
void UART_BaudFreeConfig(UART_TypeDef *UARTx,UART_AUTO_BAUD_FREE_MODE mode)
{
    UART0->CON0.IDEN = 1;               //ʹ�ܿ��м��
    UART0->CON1.IDM = mode;
}

/*************************************
  ��������UART_ITConfig
  ��  �����ж�����
  ����ֵ��UART0/UART1
  �ж�����
  ʹ��/��ֹ
  ����ֵ����
 **************************************/
void UART_ITConfig(UART_TypeDef *UARTx, UART_TYPE_IT UART_IT, TYPE_FUNCEN NewState)
{
	if (NewState == Enable)
		UARTx->IE.Word |= (uint32_t)UART_IT;
	else
		UARTx->IE.Word &= ~(uint32_t)UART_IT;

	return;
}

/*************************************
  ��������UART_TBIMConfig
  ��  �������ͻ��������ж�����
  ����ֵ��UART0/UART1
  �ж�����
  ����ֵ����
 **************************************/
void UART_TBIMConfig(UART_TypeDef *UARTx, UART_TYPE_TRBIM Type)
{
	UARTx->CON1.TBIM = Type;
	return;
}

/*************************************
  ��������UART_RBIMConfig
  ��  �������ջ��������ж�����
  ����ֵ��UART0/UART1
  �ж�����
  ����ֵ����
 **************************************/
void UART_RBIMConfig(UART_TypeDef *UARTx, UART_TYPE_TRBIM Type)
{
	UARTx->CON1.RBIM = Type;
	return;
}

/*************************************
  ��������UART_SendByte
  ��  ��������һ���ֽ�
  ����ֵ��UART0/UART1
  ��Ҫ���͵�����
  ����ֵ����
 **************************************/
void UART_SendByte(UART_TypeDef *UARTx, uint8_t data08)
{
	UARTx->TBW.Byte[0] = data08;
	return;
}

/*************************************
  ��������UART_SendHalfWord
  ��  �������Ͱ���
  ����ֵ��UART0/UART1
  ��Ҫ���͵�����
  ����ֵ����
 **************************************/
void UART_SendHalfWord(UART_TypeDef *UARTx, uint16_t data16)
{
	UARTx->TBW.HalfWord[0] = data16;
	return;
}

/*************************************
  ��������UART_SendWord
  ��  ����������
  ����ֵ��UART0/UART1
  ��Ҫ���͵�����
  ����ֵ����
 **************************************/
void UART_SendWord(UART_TypeDef *UARTx, uint32_t data32)
{
	UARTx->TBW.Word = data32;
	return;
}

/*************************************
  ��������UART_RecByte
  ��  ��������һ���ֽ�
  ����ֵ��UART0/UART1
  ����ֵ�����յ�������
 **************************************/
uint8_t UART_RecByte(UART_TypeDef *UARTx)
{
	return UARTx->RBR.Byte[0];
}

/*************************************
  ��������UART_RecHalfWord
  ��  �������հ���
  ����ֵ��UART0/UART1
  ����ֵ�����յ�������
 **************************************/
uint16_t UART_RecHalfWord(UART_TypeDef *UARTx)
{
	return UARTx->RBR.HalfWord[0];
}

/*************************************
  ��������UART_RecWord
  ��  ����������
  ����ֵ��UART0/UART1
  ����ֵ�����յ�������
 **************************************/
uint32_t UART_RecWord(UART_TypeDef *UARTx)
{
	return UARTx->RBR.Word;
}

/*************************************
  ��������UART_GetStatus
  ��  ������ȡUART״̬
  ����ֵ��UART0/UART1
  ״̬����
  ����ֵ��SET/RESET
 **************************************/
FlagStatus UART_GetStatus(UART_TypeDef *UARTx, UART_TYPE_STA UART_Flag)
{
	FlagStatus bitstatus = RESET;

	if (UARTx->STA.Word & UART_Flag)
		bitstatus = SET;

	return bitstatus;
}

/*************************************
  ��������UART_GetFlagStatus
  ��  ������ȡ�жϱ�־λ״̬
  ����ֵ��UART0/UART1
  ״̬����
  ����ֵ��SET/RESET
 **************************************/
FlagStatus UART_GetFlagStatus(UART_TypeDef *UARTx, UART_TYPE_FLAG UART_Flag)
{
	FlagStatus bitstatus = RESET;

	if (UARTx->IF.Word & UART_Flag)
		bitstatus = SET;

	return bitstatus;
}

/*************************************
  ��������UART_GetITStatus
  ��  ������ȡ�ж�ʹ��״̬
  ����ֵ��UART0/UART1
  ״̬����
  ����ֵ��SET/RESET
 **************************************/
ITStatus UART_GetITStatus(UART_TypeDef *UARTx, UART_TYPE_IT UART_IT)
{
	ITStatus bitstatus = RESET;

	if (UARTx->IE.Word & UART_IT)
		bitstatus = SET;

	return bitstatus;
}

/*************************************
  ��������UART_ClearITPendingBit
  ��  ��������ж�״̬
  ����ֵ��UART0/UART1
  ״̬����
  ����ֵ����
 **************************************/
void UART_ClearITPendingBit(UART_TypeDef *UARTx, UART_CLR_IF UART_Flag)
{
	UARTx->IF.Word = (UART_Flag);
	return;
}

