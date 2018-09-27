/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_spi.c
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  SPIģ��⺯��
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#include "lib_spi.h"
#include "system_HR8P506.h"

/*************************************
  ��������SPI_Init
  ��  ����SPI��ʼ��
  ����ֵ��SPI0/SPI1
  ��ʼ���ṹ��
  ����ֵ����
 **************************************/
void SPI_Init(SPI_TypeDef *SPIx, SPI_InitStruType *SPI_InitStruct)
{
	uint32_t tmp = 0;

	if (SPI_InitStruct->SPI_Freq != SystemCoreClock) {
		tmp = SystemCoreClock / (SPI_InitStruct->SPI_Freq << 1);
		tmp = tmp > 0xfe ? 0xff : tmp;
	}

	SPIx->CKS.CKS = tmp;
		SPIx->CON.DW  = SPI_InitStruct->SPI_DW;
	SPIx->CON.DFS = SPI_InitStruct->SPI_Df;
	SPIx->CON.MS  = SPI_InitStruct->SPI_Mode;
	SPIx->CON.DRE = SPI_InitStruct->SPI_DelayRec;
	SPIx->CON.TME = SPI_InitStruct->SPI_DelaySend;

	tmp = (uint32_t)SPI_InitStruct->SPI_SendDelayPeroid - 1;
	tmp = tmp > 63 ? 63 : tmp;
	SPIx->CON.TMP   = tmp;
		SPIx->CON.TXCLR = 1;
		SPIx->CON.RXCLR = 1;	

	return;
}

/*************************************
  ��������SPI_ITConfig
  ��  ���������ж�ʹ��
  ����ֵ��SPI0/SPI1
  �ж�����
  ʹ��/��ֹ
  ����ֵ����
 **************************************/
void SPI_ITConfig(SPI_TypeDef *SPIx, SPI_TYPE_IT SPI_IE, TYPE_FUNCEN NewState)
{
	if (NewState != Disable)
		SPIx->IE.Word |= (uint32_t)SPI_IE;
	else
		SPIx->IE.Word &= ~(uint32_t)SPI_IE;

	return;
}

/*************************************
  ��������SPI_DataFormatConfig
  ��  ����SPI���ݸ�ʽ
  ����ֵ��SPI0/SPI1
  ���ݸ�ʽ
  ����ֵ����
 **************************************/
void SPI_DataFormatConfig(SPI_TypeDef *SPIx, SPI_TYPE_DFS Type)
{
	SPIx->CON.DFS = Type;
	return;
}

/*************************************
  ��������SPI_SendByte
  ��  ��������һ���ֽ�
  ����ֵ��SPI0/SPI1
  ��Ҫ���͵�����
  ����ֵ����
 **************************************/
void SPI_SendByte(SPI_TypeDef *SPIx, uint8_t Temp)
{
	SPIx->TBW.Byte[0] = Temp;
	return;

}

/*************************************
  ��������SPI_SendHalfWord
  ��  �������Ͱ���
  ����ֵ��SPI0/SPI1
  ��Ҫ���͵�����
  ����ֵ����
 **************************************/
void SPI_SendHalfWord(SPI_TypeDef *SPIx, uint16_t Temp)
{
	SPIx->TBW.HalfWord[0] = Temp;
	return;
}

/*************************************
  ��������SPI_SendWord
  ��  ����������
  ����ֵ��SPI0/SPI1
  ��Ҫ���͵�����
  ����ֵ����
 **************************************/
void SPI_SendWord(SPI_TypeDef *SPIx, uint32_t Temp)
{
	SPIx->TBW.Word = Temp;
	return;
}

/*************************************
  ��������SPI_RecByte
  ��  ��������һ���ֽ�
  ����ֵ��SPI0/SPI1
  ����ֵ�����յ�������
 **************************************/
uint8_t SPI_RecByte(SPI_TypeDef *SPIx)
{
	return SPIx->RBR.Byte[0];
}

/*************************************
  ��������SPI_RecHalfWord
  ��  �������հ���
  ����ֵ��SPI0/SPI1
  ����ֵ�����յ�������
 **************************************/
uint16_t SPI_RecHalfWord(SPI_TypeDef *SPIx)
{
	return SPIx->RBR.HalfWord[0];
}

/*************************************
  ��������SPI_RecHalfWord
  ��  ����������
  ����ֵ��SPI0/SPI1
  ����ֵ�����յ�������
 **************************************/
uint32_t SPI_RecWord(SPI_TypeDef *SPIx)
{
	return SPIx->RBR.Word;
}

/*************************************
  ��������SPI_TBIMConfig
  ��  �������÷��ͻ��������ж�����
  ����ֵ��SPI0/SPI1
  �ж�����
  ����ֵ����
 **************************************/
void SPI_TBIMConfig(SPI_TypeDef *SPIx, SPI_TYPE_TRBIM Type)
{
	SPIx->IE.TBIM = Type;
	return;
}

/*************************************
  ��������SPI_RBIMConfig
  ��  �������ý��ջ��������ж�����
  ����ֵ��SPI0/SPI1
  �ж�����
  ����ֵ����
 **************************************/
void SPI_RBIMConfig(SPI_TypeDef *SPIx, SPI_TYPE_TRBIM Type)
{
	SPIx->IE.RBIM = Type;
	return;
}

/*************************************
  ��������SPI_GetFlagStatus
  ��  ������ȡ�жϱ�־λ״̬
  ����ֵ��SPI0/SPI1
  �ж�����
  ����ֵ��SET/RESET
 **************************************/
FlagStatus SPI_GetFlagStatus(SPI_TypeDef *SPIx, SPI_TYPE_FLAG Flag)
{
	FlagStatus status = RESET;

	if (Flag != SPI_Flag_TMS) {
		if (SPIx->IF.Word & (uint32_t)Flag)
			status = SET;
	}
	else {
		if (SPIx->CON.Word & (uint32_t)Flag)
			status = SET;
	}

	return status;
}

/*************************************
  ��������SPI_GetITStatus
  ��  ������ȡ�ж�ʹ��״̬
  ����ֵ��SPI0/SPI1
  �ж�����
  ����ֵ��SET/RESET
 **************************************/
ITStatus SPI_GetITStatus(SPI_TypeDef *SPIx, SPI_TYPE_IT Flag)
{
	ITStatus status = RESET;
    
    if ((SPIx->IF.Word & (uint32_t)Flag) == RESET)
		return status;
	if ((SPIx->IE.Word & (uint32_t)Flag) != RESET)
		status = SET;

	return status;
}

/*************************************
  ��������SPI_GetStatus
  ��  ������ȡSPI״̬
  ����ֵ��SPI0/SPI1
  ״̬����
  ����ֵ��SET/RESET
 **************************************/
FlagStatus SPI_GetStatus(SPI_TypeDef *SPIx, SPI_TYPE_STA Flag)
{
	FlagStatus status = RESET;

	if (SPIx->STA.Word & (uint32_t)Flag)
		status = SET;

	return status;
}

/*************************************
  ��������SPI_ClearITPendingBit
  ��  ��������жϱ�־
  ����ֵ��SPI0/SPI1
  ״̬����
  ����ֵ����
 **************************************/
void SPI_ClearITPendingBit(SPI_TypeDef *SPI, SPI_CLR_IF Flag)
{
	SPI->IF.Word = (uint32_t)Flag;
	return;
}

/*************************************
  ��������Clear_TBW
  ��  ������շ��ͻ�����
  ����ֵ��SPI0/SPI1
  ����ֵ����
 **************************************/
void Clear_TBW(SPI_TypeDef *SPIx)
{
	SPIx->CON.TXCLR = 1;
	return;
}

/*************************************
  ��������Clear_RBR
  ��  ������ս��ջ�����
  ����ֵ��SPI0/SPI1
  ����ֵ����
 **************************************/
void Clear_RBR(SPI_TypeDef *SPIx)
{
	SPIx->CON.RXCLR = 1;
	return;
}
