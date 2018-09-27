/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_euart.c
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  EUARTģ��⺯��
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#include "lib_euart.h"
#include "system_HR8P506.h"

/*************************************
  ��������EUART_ModeConfig
  ��  ����EUART����ģʽѡ��
  ����ֵ������ģʽö�����ͱ���
  ����ֵ����
 **************************************/
void EUART_ModeConfig(EUART_TYPE_MODE Mode)
{
	EUART0->CON2.MOD = Mode;
	return;
}

/*************************************
  ��������EUART_Init
  ��  ����ͨ��UARTģʽ��ʼ��
  ����ֵ����ʼ���ṹ��
  ����ֵ����
 **************************************/
void EUART_Init(EUART_InitStruType *EUART_InitStruct)
{
	EUART_BaudConfig(EUART_InitStruct->EUART_BaudRate, EUART_InitStruct->EUART_ClockSet);

	EUART0->CON0.TXFS  = EUART_InitStruct->EUART_StopBits;
	EUART0->CON0.TXMOD = EUART_InitStruct->EUART_TxMode;
	EUART0->CON0.TXP   = EUART_InitStruct->EUART_TxPolar;
	EUART0->CON0.RXMOD = EUART_InitStruct->EUART_RxMode;
	EUART0->CON0.RXP   = EUART_InitStruct->EUART_RxPolar;

	return;
}

/*************************************
  ��������EUART_BaudConfig
  ��  ��������������
  ����ֵ��������
  ʱ��ѡ��
  ����ֵ����
 **************************************/
void EUART_BaudConfig(uint32_t BaudRate, EUART_TYPE_BCS ClockSet)
{
	uint32_t tmp  = 0;
	uint32_t baud = 0;

	if(ClockSet == EUART_Clock_1) {
		tmp =  (SystemCoreClock / 16) % BaudRate;
		if(BaudRate >= (2 * tmp)) 
			baud = (SystemCoreClock / 16 / BaudRate) - 1;
		else
			baud = SystemCoreClock / 16 / BaudRate;
	}
	else if(ClockSet == EUART_Clock_2) {
		tmp =  (SystemCoreClock / 32) % BaudRate;
		if(BaudRate >= (2 * tmp))
			baud = (SystemCoreClock / 32 / BaudRate) - 1;
		else
			baud = SystemCoreClock / 32 / BaudRate;
	}
	else if(ClockSet == EUART_Clock_3){
		tmp =  (SystemCoreClock / 64) % BaudRate;
		if(BaudRate >= (2 * tmp))
			baud = (SystemCoreClock / 64 / BaudRate) - 1;
		else
			baud = SystemCoreClock / 64 / BaudRate;
	}
	else if(ClockSet == EUART_Clock_4) {
		tmp =  (SystemCoreClock / 128) % BaudRate;
		if(BaudRate >= (2 * tmp))
			baud = (SystemCoreClock / 128 / BaudRate) - 1;
		else
			baud = SystemCoreClock / 128 / BaudRate;
	}

	baud = baud > 2046 ? 2047 : baud;
	EUART0->CON1.BCS = ClockSet;
	EUART0->BRR.BRR  = baud;

	return;
}

/*************************************
  ��������EUART_ITConfig
  ��  ����ͨ��UART�ж�ʹ��
  ����ֵ���ж�����ö�ٱ���
  ʹ�ܻ��ֹ
  ����ֵ����
 **************************************/
void EUART_ITConfig(EUART_TYPE_IT EUART_IT, TYPE_FUNCEN NewState)
{
	if (NewState != Disable)
		EUART0->IE.Word |= (uint32_t)EUART_IT;
	else
		EUART0->IE.Word &= ~((uint32_t)EUART_IT);

	return;
}

/*************************************
  ��������EUART_TBIMConfig
  ��  �������ͻ�����ж���������
  ����ֵ���ж�����ö�ٱ���
  ����ֵ����
 **************************************/
void EUART_TBIMConfig(EUART_TYPE_TRBIM Type)
{
	EUART0->CON1.TBIM = Type;
	return;
}

/*************************************
  ��������EUART_RBIMConfig
  ��  �������ջ������ж���������
  ����ֵ���ж�����ö�ٱ���
  ����ֵ����
 **************************************/
void EUART_RBIMConfig(EUART_TYPE_TRBIM Type)
{
	EUART0->CON1.RBIM = Type;
	return;
}

/*************************************
  ��������EUART_GetFlagStatus
  ��  ������ȡ�жϱ�־λ״̬
  ����ֵ���ж�����ö�ٱ���
  ����ֵ��SET/RESET
 **************************************/
FlagStatus EUART_GetFlagStatus(EUART_TYPE_FLAG EUART_Flag)
{
	FlagStatus status = RESET;

	if (EUART0->IF.Word & (uint32_t)EUART_Flag)
		status = SET;

	return status;
}

/*************************************
  ��������EUART_GetITStatus
  ��  ������ȡ�ж�ʹ��״̬
  ����ֵ���ж�����ö�ٱ���
  ����ֵ��SET/RESET
 **************************************/
ITStatus EUART_GetITStatus(EUART_TYPE_IT EUART_Flag)
{
	ITStatus status = RESET;

	if (EUART0->IE.Word & (uint32_t)EUART_Flag)
		status = SET;

	return status;
}

/*************************************
  ��������EUART_ClearITPendingBit
  ��  ��������жϱ�־λ
  ����ֵ���ж�����ö�ٱ���
  ����ֵ����
 **************************************/
void EUART_ClearITPendingBit(EUART_CLR_IF EUART_Flag)
{
	EUART0->IF.Word = (uint32_t)EUART_Flag;
	return;
}

/*************************************
  ��������U7816_Init
  ��  ����7816ģʽ��ʼ��
  ����ֵ����ʼ���ṹ��
  ����ֵ����
 **************************************/
void U7816_Init(U7816_InitStruType *U7816_InitStruct)
{
	EUART_BaudConfig(U7816_InitStruct->U7816_BaudRate, U7816_InitStruct->U7816_ClockSet);

	EUART0->CON2.CK0E = U7816_InitStruct->U7816_ECK0;
	EUART0->CON2.CK1E = U7816_InitStruct->U7816_ECK1;
	EUART0->CON2.CHS  = U7816_InitStruct->U7816_EIOCh;
	EUART0->CON2.IOC  = U7816_InitStruct->U7816_EIODir;
	EUART0->CON2.DAS  = U7816_InitStruct->U7816_DataForm;
	EUART0->CON2.PS   = U7816_InitStruct->U7816_DataVerify;
	EUART0->CON2.ARTE = U7816_InitStruct->U7816_AutoRetryTx;
	EUART0->CON2.ARRE = U7816_InitStruct->U7816_AutoRetryRx;
	EUART0->CON2.TNAS = U7816_InitStruct->U7816_NACK_Width;
	EUART0->CON2.ARTS = U7816_InitStruct->U7816_RetryTimes;
	EUART0->CON2.CKS  = U7816_InitStruct->U7816_CLKS;
	EUART0->CON2.ETUS = U7816_InitStruct->U7816_ETUTime;

	return;
}

/*************************************
  ��������EUART_EIOChConfig
  ��  ��������EIOͨ��
  ����ֵ��EIOͨ��
  ����ֵ����
 **************************************/
void EUART_EIOChConfig(U7816_TYPE_CHS U7816_IO)
{
	EUART0->CON2.CHS = U7816_IO;
	return;
}

/*************************************
  ��������EUART_EIODirection
  ��  ��������EIO����
  ����ֵ��EIO����
  ����ֵ����
 **************************************/
void EUART_EIODirection(U7816_TYPE_IOC Dir)
{
	EUART0->CON2.IOC = Dir;
	return;
}

/*************************************
  ��������EUART_SendByte
  ��  ��������һ���ֽ�
  ����ֵ����Ҫ�ķ�������
  ����ֵ����
 **************************************/
void EUART_SendByte(uint8_t ByteData)
{
	EUART0->TBW.Byte[0] = ByteData;
	return;
}

/*************************************
  ��������EUART_SendHalfWord
  ��  �������Ͱ���
  ����ֵ����Ҫ�ķ�������
  ����ֵ����
 **************************************/
void EUART_SendHalfWord(uint16_t HalfWordData)
{
	EUART0->TBW.HalfWord[0] = HalfWordData;
	return;
}

/*************************************
  ��������EUART_SendWord
  ��  ����������
  ����ֵ����Ҫ�ķ�������
  ����ֵ����
 **************************************/
void EUART_SendWord(uint32_t WordData)
{
	EUART0->TBW.Word = WordData;
	return;
}

/*************************************
  ��������EUART_RecByte
  ��  ��������һ���ֽ�
  ����ֵ����
  ����ֵ�����յ�������
 **************************************/
uint8_t EUART_RecByte(void)
{
	return EUART0->RBR.Byte[0];
}

/*************************************
  ��������EUART_RecHalfWord
  ��  �������հ���
  ����ֵ����
  ����ֵ�����յ�������
 **************************************/
uint16_t EUART_RecHalfWord(void)
{
	return EUART0->RBR.HalfWord[0];
}

/*************************************
  ��������EUART_RecWord
  ��  ����������
  ����ֵ����
  ����ֵ�����յ�������
 **************************************/
uint32_t EUART_RecWord(void)
{
	return EUART0->RBR.Word;
}



