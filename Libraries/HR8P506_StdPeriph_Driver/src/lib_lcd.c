/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_gpio.c
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  LCDģ��⺯��
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#include "lib_lcd.h"

/***************************************************************
  ��������LCD_Init
  ��  ����LCD���ܳ�ʼ������
  ����ֵ��LCD_InitStruct ��ʼ���ṹ��
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus LCD_Init(LCD_InitStruType * LCD_InitStruct)
{

	if(	LCD_InitStruct ->LCD_COMS > LCD_COMS_MAX
			|| LCD_InitStruct ->LCD_SEG > LCD_SEG_MAX
			|| LCD_InitStruct ->LCD_VLCD > LCD_VLCD_MAX
			|| LCD_InitStruct ->LCD_WFS > LCD_WFS_MAX
			|| LCD_InitStruct ->LCD_CLK > LCD_CLK_MAX
			|| LCD_InitStruct ->LCD_PRS > LCD_PRS_MAX
			|| LCD_InitStruct ->LCD_BVS > LCD_BVS_MAX
			|| LCD_InitStruct ->LCD_BIAS > LCD_BIAS_MAX
			|| LCD_InitStruct ->LCD_RT > LCD_RT_MAX
			|| LCD_InitStruct ->LCD_RS > LCD_RS_MAX
			|| LCD_InitStruct ->LCD_FLIK > LCD_FLIK_MAX
			|| LCD_InitStruct ->LCD_TOFF > LCD_TOFF_MAX
			|| LCD_InitStruct ->LCD_TON > LCD_TON_MAX) {
		return ERROR;
	}

	LCD_Reset();

	LCD->CON1.SEL = LCD_SEL_LCD; /* ѡ��LCD������ */

	LCD->CON0.COMS = LCD_InitStruct->LCD_COMS;/* ����LCD�����˿�*/
	LCD->SEL.SEG = LCD_InitStruct->LCD_SEG;

	LCD->CON0.VLCDEN = LCD_InitStruct ->LCD_VLCD;
	LCD ->CON0.WFS = LCD_InitStruct->LCD_WFS;

	LCD ->CON0.CLK_SEL = LCD_InitStruct ->LCD_CLK;
	LCD ->CON0.PRS = LCD_InitStruct->LCD_PRS;

	LCD ->CON0.BIAS = LCD_InitStruct->LCD_BIAS;
	LCD ->CON0.BVS = LCD_InitStruct->LCD_BVS;

	if(LCD_InitStruct->LCD_RS== LCD_RS_60K_225K || LCD_InitStruct->LCD_RS== LCD_RS_60K_900K) {
		LCD ->CON0.RT = LCD_InitStruct->LCD_RT;
		LCD ->CON0.RS = LCD_InitStruct->LCD_RS;
	}
	else {
		LCD ->CON0.RS = LCD_InitStruct->LCD_RS;
	}


	if(LCD_InitStruct ->LCD_FLIK == LCD_FLIK_YES) {
		LCD->TWI.TOFF = LCD_InitStruct ->LCD_TOFF;
		LCD->TWI.TON = LCD_InitStruct ->LCD_TON;
		LCD->CON0.FLIK = LCD_FLIK_YES;
	}
	else {
		LCD->CON0.FLIK = LCD_FLIK_NO;
	}

	LCD_EN();

	return SUCCESS;

}

/***************************************************************
  ��������LCD_GrayscaleConfig
  ��  ����LCD�Ҷ�����
  ����ֵ��LCD_Grayscale	�Ҷ�����ֵ
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus LCD_GrayscaleConfig(uint8_t BVS_Sel)
{
	if(BVS_Sel>LCD_BVS_MAX) {
		return ERROR;
	}
	LCD->CON0.BVS = BVS_Sel;

	return SUCCESS;
}

/***************************************************************
  ��������LCD_FlickerTimeConfig
  ��  ����LCD��˸��������
  ����ֵ��FLIK_EN		��˸ʹ��ѡ��
  On_Time		��˸����ʱ��
  Off_Time		��˸Ϩ��ʱ��
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus LCD_FlickerTimeConfig(LCD_TYPE_FLIK Flick,uint8_t On_Time,uint8_t Off_Time)
{
	if(On_Time > LCD_TON_MAX ||Off_Time >LCD_TOFF_MAX) {
		return ERROR;
	}
	if(Flick == LCD_FLIK_YES)
	{
		LCD->TWI.TON = On_Time;
		LCD->TWI.TOFF = Off_Time;
		LCD->CON0.FLIK = LCD_FLIK_YES;
	}
	else
	{
		LCD->TWI.TON = 0;
		LCD->TWI.TOFF = 0;
		LCD->CON0.FLIK = LCD_FLIK_NO;
	}

	return SUCCESS;
}

# if 0
/***************************************************************
  ��������LCD_ResistorConfig
  ��  ����LCD�ڲ�ƫѹ��������
  ����ֵ��Rsel	�ڲ�ƫѹ����ѡ��
  Rtime	ƫѹ�����л�ѡ��
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus LCD_ResistorConfig(LCD_TYPE_RS Rsel,LCD_TYPE_RT Rtime)
{
	if(Rsel>LCD_RS_MAX ||Rtime>LCD_RT_MAX) {
		return ERROR;
	}

	LCD ->CON0.RS = Rsel;
	if(Rsel== LCD_RS_60K_225K||Rsel== LCD_RS_60K_900K) {
		LCD ->CON0.RT = Rtime;
	}

	return SUCCESS;
}
#endif

/***************************************************************
  ��������LCD_PixelWriteByte
  ��  ����LCD һ��д8bit����
  ����ֵ��LCD_DD 	���ؼĴ���ѡ��
  nByte 		1/4��2/4��3/4��4/4 8bitѡ��
  LCD_data		д��8bit����
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/

uint32_t MASK_BYTE[] = {0xff,0xff00,0xff0000,0xff000000};

ErrorStatus  LCD_PixelWriteByte(LCD_TYPE_PIXEL LCD_DD, LCD_DD_BYTE nByte ,uint8_t LCD_data)
{

	LCD_DD_TypeDef *DD;
	if(nByte >LCD_Byte_MAX || LCD_DD>LCD_Pixel_MAX )
	{
		return ERROR;
	}

	switch (LCD_DD)
	{
		case LCD_Pixel_LCDD0:
			DD = (LCD_DD_TypeDef *)(&(LCD->D0));
			break;
		case LCD_Pixel_LCDD1:
			DD = (LCD_DD_TypeDef *)(&(LCD->D1));
			break;
		case LCD_Pixel_LCDD2:
			DD = (LCD_DD_TypeDef *)(&(LCD->D2));
			break;
		case LCD_Pixel_LCDD3:
			DD = (LCD_DD_TypeDef *)(&(LCD->D3));
			break;
		case LCD_Pixel_LCDD4:
			DD = (LCD_DD_TypeDef *)(&(LCD->D4));
			break;
		case LCD_Pixel_LCDD5:
			DD = (LCD_DD_TypeDef *)(&(LCD->D5));
			break;	
		case LCD_Pixel_LCDD6:
			DD = (LCD_DD_TypeDef *)(&(LCD->D6));
			break;
		default:
			return 	ERROR;
	}
	DD->Byte[nByte] = LCD_data;
	return SUCCESS;
}

/***************************************************************
  ��������LCD_PixelWriteHalfWord
  ��  ����LCD һ��д16bit����
  ����ֵ��LCD_DD 	���ؼĴ���ѡ��
  nHalfWord 	ǰ/��16bitѡ��
  LCD_data		д��16bit����
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus  LCD_PixelWriteHalfWord(LCD_TYPE_PIXEL LCD_DD, LCD_DD_HALFWORD nHalfWord , uint16_t LCD_data)
{
	LCD_DD_TypeDef *DD;

	if( LCD_DD>LCD_Pixel_MAX || nHalfWord >LCD_HalfWord_MAX)
	{
		return ERROR;
	}
	switch (LCD_DD)
	{
		case LCD_Pixel_LCDD0:
			DD = (LCD_DD_TypeDef *)(&(LCD->D0));
			break;
		case LCD_Pixel_LCDD1:
			DD = (LCD_DD_TypeDef *)(&(LCD->D1));
			break;
		case LCD_Pixel_LCDD2:
			DD = (LCD_DD_TypeDef *)(&(LCD->D2));
			break;
		case LCD_Pixel_LCDD3:
			DD = (LCD_DD_TypeDef *)(&(LCD->D3));
			break;
		case LCD_Pixel_LCDD4:
			DD = (LCD_DD_TypeDef *)(&(LCD->D4));
			break;
		case LCD_Pixel_LCDD5:
			DD = (LCD_DD_TypeDef *)(&(LCD->D5));
			break;
		case LCD_Pixel_LCDD6:
			DD = (LCD_DD_TypeDef *)(&(LCD->D6));
			break;		
		default:
			return 	ERROR;
	}
	DD->HalfWord[nHalfWord] = LCD_data;

	return SUCCESS;
}

/***************************************************************
  ��������LCD_PixelWriteWord
  ��  ����LCD һ��д32bit����
  ����ֵ��LCD_DD 	���ؼĴ���ѡ��
  LCD_data		д��32bit����
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus  LCD_PixelWriteWord(LCD_TYPE_PIXEL LCD_DD,uint32_t LCD_data)
{
	if(LCD_DD>LCD_Pixel_MAX) {
		return ERROR;
	}
	switch (LCD_DD)
	{
		case LCD_Pixel_LCDD0:
			LCD->D0.Word = LCD_data;
			break;
		case LCD_Pixel_LCDD1:
			LCD->D1.Word = LCD_data;
			break;
		case LCD_Pixel_LCDD2:
			LCD->D2.Word = LCD_data;
			break;
		case LCD_Pixel_LCDD3:
			LCD->D3.Word = LCD_data;
			break;
		case LCD_Pixel_LCDD4:
			LCD->D4.Word = LCD_data;
			break;
		case LCD_Pixel_LCDD5:
			LCD->D5.Word = LCD_data;
			break;
		case LCD_Pixel_LCDD6:
			LCD->D6.Word = LCD_data;
			break;		
		default:
			return 	ERROR;
	}
	return SUCCESS;
}

/***************************************************************
  ��������LCD_Reset
  ��  ����LCD��λ
  ����ֵ����
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void LCD_Reset(void)
{
	LCD->CON0.Word = 0xf0000000;
	LCD->TWI.Word = 0xf0000000;
	LCD->SEL.Word = 0xf0000000;
	LCD->CON1.Word = 0xf0000000;

	LCD->D0.Word = 0x00000000;
	LCD->D1.Word = 0x00000000;
	LCD->D2.Word = 0x00000000;
	LCD->D3.Word = 0x00000000;
	LCD->D4.Word = 0x00000000;
	LCD->D5.Word = 0x00000000;
	LCD->D6.Word = 0x00000000;

	LCD->CON1.RST = 1;
}
