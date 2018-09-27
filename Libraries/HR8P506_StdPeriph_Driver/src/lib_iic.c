/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_iic.c
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  IICģ��⺯��
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#include "lib_iic.h"
#include "system_HR8P506.h"

/*************************************
  ��������IIC_Init
  ��  ����IIC��ʼ��
  ����ֵ��I2C0/I2C1
  ��ʼ���ṹ��
  ����ֵ����
 **************************************/
void IIC_Init(I2C_TypeDef *IICx, IIC_InitStruType *IIC_InitStruct)
{
	uint32_t tmp;

	if (IIC_InitStruct->IIC_Mode == IIC_Mode_Master) {
		if (IIC_InitStruct->IIC_16XSamp != Disable)
			tmp = SystemCoreClock / 24 /IIC_InitStruct->IIC_Clk - 1;
		else
			tmp = SystemCoreClock / 16 /IIC_InitStruct->IIC_Clk - 1;

		tmp = tmp > 255 ? 255 : tmp;
		IICx->CON.TJP = tmp;
		IICx->CON.TJE = 0x1;
	}

	IICx->CON.SDASE = IIC_InitStruct->IIC_16XSamp;
	IICx->CON.SCLSE = IIC_InitStruct->IIC_16XSamp;
	IICx->CON.SCLOD = IIC_InitStruct->IIC_SckOd;
	IICx->CON.SDAOD = IIC_InitStruct->IIC_SdaOd;
	IICx->MOD.MS   = IIC_InitStruct->IIC_Mode;
	IICx->MOD.SPAE = IIC_InitStruct->IIC_AutoStop;
	IICx->MOD.SRAE = IIC_InitStruct->IIC_AutoCall;

	return;
}

/*************************************
  ��������IIC_ITConfig
  ��  �����ж�ʹ��
  ����ֵ��I2C0/I2C1
  �ж�����
  ʹ��/��ֹ
  ����ֵ����
 **************************************/
void IIC_ITConfig(I2C_TypeDef *IICx, IIC_TYPE_IT IIC_IT, TYPE_FUNCEN NewState)
{
	if (NewState == Enable)
		IICx->IE.Word |= (uint32_t)IIC_IT;
	else
		IICx->IE.Word &= ~((uint32_t)IIC_IT);

	return;
}

/*************************************
  ��������IIC_SendAddress
  ��  �������ʹӻ���ַ
  ����ֵ��I2C0/I2C1
  �ӻ���ַ
  ����ģʽ:��/д
  ����ֵ����
 **************************************/
void IIC_SendAddress(I2C_TypeDef *IICx, uint8_t IIC_Address, IIC_TYPE_RWMODE Mode)
{
	IICx->CON.SA = IIC_Address >> 1;
	IICx->CON.RW = Mode;

	return;
}

/*************************************
  ��������IIC_SetAddress
  ��  �������ôӻ���ַ
  ����ֵ��I2C0/I2C1
  �ӻ���ַ
  ����ֵ����
 **************************************/
void IIC_SetAddress(I2C_TypeDef *IICx, uint8_t IIC_Address)
{
	IICx->CON.SA = IIC_Address >> 1;
	return;
}

/*************************************
  ��������IIC_RecModeConfig
  ��  ��������ģʽ����
  ����ֵ��I2C0/I2C1
  ����ģʽ
  ����ֵ����
 **************************************/
void IIC_RecModeConfig(I2C_TypeDef *IICx, IIC_TYPE_RECMODE RecType)
{
	IICx->MOD.RDM = RecType;
	return;
}

/*************************************
  ��������IIC_TBIMConfig
  ��  �������ͻ��������ж�����
  ����ֵ��I2C0/I2C1
  �ж�����
  ����ֵ����
 **************************************/
void IIC_TBIMConfig(I2C_TypeDef *IICx, IIC_TYPE_TRBIM Type)
{
	IICx->IE.TBIM = Type;
	return;
}

/*************************************
  ��������IIC_RBIMConfig
  ��  �������ջ��������ж�����
  ����ֵ��I2C0/I2C1
  �ж�����
  ����ֵ����
 **************************************/
void IIC_RBIMConfig(I2C_TypeDef *IICx, IIC_TYPE_TRBIM Type)
{
	IICx->IE.RBIM = Type;
	return;
}

/*************************************
  ��������IIC_AckDelay
  ��  ���������ӳ�Ӧ��
  ����ֵ��I2C0/I2C1
  �ӳ�ʱ��
  ʹ��/��ֹ
  ����ֵ����
 **************************************/
void IIC_AckDelay(I2C_TypeDef *IICx, IIC_TYPE_ADLY Type, TYPE_FUNCEN NewStatus)
{
	IICx->MOD.ADLY = Type;
	IICx->MOD.ADE  = NewStatus;
	return;
}

/*************************************
  ��������IIC_TISConfig
  ��  ������������֡������
  ����ֵ��I2C0/I2C1
  ���ʱ��
  ����ֵ����
 **************************************/
void IIC_TISConfig(I2C_TypeDef *IICx, IIC_TYPE_TIS Time)
{
	IICx->MOD.TIS = Time;
	return;
}

/*************************************
  ��������IIC_SendByte
  ��  ��������һ���ֽ�
  ����ֵ��I2C0/I2C1
  ��Ҫ���͵�����
  ����ֵ����
 **************************************/
void IIC_SendByte(I2C_TypeDef *IICx, uint8_t Byte)
{
	IICx->TBW.Byte[0] = Byte;
	return;
}

/*************************************
  ��������IIC_SendHalfWord
  ��  �������Ͱ���
  ����ֵ��I2C0/I2C1
  ��Ҫ���͵�����
  ����ֵ����
 **************************************/
void IIC_SendHalfWord(I2C_TypeDef *IICx, uint16_t HalfWord)
{
	IICx->TBW.HalfWord[0] = HalfWord;
	return;
}

/*************************************
  ��������IIC_SendWord
  ��  �������Ͱ���
  ����ֵ��I2C0/I2C1
  ��Ҫ���͵�����
  ����ֵ����
 **************************************/
void IIC_SendWord(I2C_TypeDef *IICx, uint32_t Word)
{
	IICx->TBW.Word = Word;
	return;
}

/*************************************
  ��������IIC_RecByte
  ��  ��������һ���ֽ�
  ����ֵ��I2C0/I2C1
  ����ֵ�����յ�������
 **************************************/
uint8_t IIC_RecByte(I2C_TypeDef *IICx)
{
	return IICx->RBR.Byte[0];
}

/*************************************
  ��������IIC_RecHalfWord
  ��  �������հ���
  ����ֵ��I2C0/I2C1
  ����ֵ�����յ�������
 **************************************/
uint16_t IIC_RecHalfWord(I2C_TypeDef *IICx)
{
	return IICx->RBR.HalfWord[0];
}

/*************************************
  ��������IIC_RecWord
  ��  ����������
  ����ֵ��I2C0/I2C1
  ����ֵ�����յ�������
 **************************************/
uint32_t IIC_RecWord(I2C_TypeDef *IICx)
{
	return IICx->RBR.Word;
}

/*************************************
  ��������IIC_GetRWMode
  ��  ������ȡIIC��д״̬
  ����ֵ��I2C0/I2C1
  ����ֵ����д״̬
 **************************************/
IIC_TYPE_RWMODE IIC_GetRWMode(I2C_TypeDef *IICx)
{
	IIC_TYPE_RWMODE status;

	status = IICx->CON.RW == 0 ? IIC_Mode_Write : IIC_Mode_Read;
	return status;
}

/*************************************
  ��������IIC_GetTBStatus
  ��  ������ȡ���ͻ�����״̬��TB0-TB3ȫ�շ���SET�����򷵻�RESET
  ����ֵ��I2C0/I2C1
  ����ֵ��SET/RESET
 **************************************/
FlagStatus IIC_GetTBStatus(I2C_TypeDef *IICx)
{
	FlagStatus status;

	if ((IICx->STA.Word & (uint32_t)0xf00) != (uint32_t)0xf00)
		status = RESET;
	else
		status = SET;

	return status;
}

/*************************************
  ��������IIC_GetFlagStatus
  ��  ������ȡ�жϱ�־λ״̬
  ����ֵ��I2C0/I2C1
  �ж�����
  ����ֵ��SET/RESET
 **************************************/
FlagStatus IIC_GetFlagStatus(I2C_TypeDef *IICx, IIC_TYPE_IF IIC_Flag)
{
	FlagStatus status;

	if ((IICx->IF.Word & (uint32_t)IIC_Flag) != RESET)
		status = SET;
	else
		status = RESET;

	return status;
}

/*************************************
  ��������IIC_GetITStatus
  ��  ������ȡ�ж�ʹ��״̬
  ����ֵ��I2C0/I2C1
  �ж�����
  ����ֵ��SET/RESET
 **************************************/
FlagStatus IIC_GetITStatus(I2C_TypeDef *IICx, IIC_TYPE_IT IIC_Flag)
{
	FlagStatus status = RESET;

	if ((IICx->IE.Word & (uint32_t)IIC_Flag) == RESET)
		return status;

	if ((IICx->IF.Word & (uint32_t)IIC_Flag) != RESET)
		status = SET;

	return status;
}

/*************************************
  ��������IIC_GetITStatus
  ��  ��������ж�״̬
  ����ֵ��I2C0/I2C1
  �ж�����
  ����ֵ����
 **************************************/
void IIC_ClearITPendingBit(I2C_TypeDef *IICx, IIC_CLR_IF IIC_IT)
{
	IICx->IF.Word = (uint32_t)IIC_IT;
	return;
}
