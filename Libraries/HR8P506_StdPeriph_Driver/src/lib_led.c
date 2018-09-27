/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_led.c
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  LEDģ��⺯��
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#if 0
#include "lib_led.h"

/***************************************************************
  ��������LED_Init
  ��  ����LED���ܳ�ʼ������
  ����ֵ��LED_InitStruct ��ʼ���ṹ��
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus LED_Init(LED_InitStruType * LED_InitStruct)
{
	LED_Reset();

	if(LED_InitStruct->LED_MUX >LED_MUX_MAX
			|| LED_InitStruct->LED_COM >LED_COM_MAX
			|| LED_InitStruct->LED_SEG > LED_SEG_MAX
			|| LED_InitStruct->LED_CLK > LED_CLK_MAX
			|| LED_InitStruct->LED_PRS >LED_PRS_MAX) {

		return ERROR;
	}

	LED->CON1.SEL = LED_SEL_LED;

	LED->CON0.MUX= LED_InitStruct->LED_MUX;
	LED->SEL.COM = LED_InitStruct->LED_COM;
	LED->SEL.SEG = LED_InitStruct->LED_SEG;

	LED->CON0.CLK_SEL = LED_InitStruct->LED_CLK;
	LED->CON0.PRS = LED_InitStruct->LED_PRS;

	LED_EN();
	return SUCCESS;
}

/***************************************************************
��������LED_PixelWriteByte
��  ����LED һ��д8bit����
����ֵ��LED_DD 	���ؼĴ���ѡ��
				nByte 		1/4��2/4��3/4��4/4 8bitѡ��
				LED_data		д��8bit����
���ֵ����
����ֵ��SUCCESS �ɹ�
			  ERROR ʧ��
***************************************************************/
ErrorStatus  LED_PixelWriteByte(LED_TYPE_PIXEL LED_DD, LED_DD_BYTE nByte ,uint8_t LED_data)
{
	LED_DD_TypeDef *DD;
    if(nByte >LED_Byte_MAX||LED_DD>LED_Pixel_MAX)
	{
		return ERROR;
	}
	switch (LED_DD)
	{
		case LED_Pixel_LEDD0:
			DD = (LED_DD_TypeDef *)(&(LCD->D0));
			break;
		case LED_Pixel_LEDD1:
			DD = (LED_DD_TypeDef *)(&(LCD->D1));
			break;
		default:
			return	ERROR;
	}
	DD->Byte[nByte] = LED_data;
	return SUCCESS;
}

/***************************************************************
��������LED_PixelWriteHalfWord
��  ����LED һ��д16bit����
����ֵ��LED_DD 	���ؼĴ���ѡ��
				nHalfWord 	ǰ/��16bitѡ��
				LED_data		д��16bit����
���ֵ����
����ֵ��SUCCESS �ɹ�
			  ERROR ʧ��
***************************************************************/
ErrorStatus  LED_PixelWriteHalfWord(LED_TYPE_PIXEL LED_DD, LED_DD_HALFWORD nHalfWord , uint16_t LED_data)
{
	LED_DD_TypeDef *DD;
    if(!(nHalfWord>LED_HalfWord_MAX||LED_DD>LED_Pixel_MAX))
	{
		return ERROR;
	}
	switch (LED_DD)
	{
		case LED_Pixel_LEDD0:
			DD = (LED_DD_TypeDef *)(&(LCD->D0));
			break;
		case LED_Pixel_LEDD1:
			DD = (LED_DD_TypeDef *)(&(LCD->D1));
			break;		
		default:
			return 	ERROR;
	}
	DD->HalfWord[nHalfWord] = LED_data;
	return SUCCESS;
}
/***************************************************************
  ��������LED_PixelWriteWord
  ��  ����LED һ��д32bit����
  ����ֵ��LED_DD 	���ؼĴ���ѡ��
  LED_data		д��32bit����
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus  LED_PixelWriteWord(LED_TYPE_PIXEL LED_DD,uint32_t LED_data)
{
	if(LED_DD>LED_Pixel_MAX) {
		return ERROR;
	}
	switch (LED_DD)
	{
		case LED_Pixel_LEDD0:
			LED->D0.Word = LED_data;
			break;
		case LED_Pixel_LEDD1:
			LED->D1.Word = LED_data;
			break;	
		default:
			return 	ERROR;
	}
	return SUCCESS;
}

/***************************************************************
  ��������LED_Reset
  ��  ����LED��λ
  ����ֵ����
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void LED_Reset(void)
{
	LED->CON0.Word = 0xf0000000;
	LED->SEL.Word = 0x00000000;
	LED->CON1.Word = 0x00000000;

	LED->D0.Word = 0x00000000;
	LED->D1.Word = 0x00000000;
	LED_RST();
}
#endif
