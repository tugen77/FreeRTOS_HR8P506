/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_gpio.h
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  LCDģ��⺯��ͷ�ļ�
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#ifndef __LIBLCD_H__
#define __LIBLCD_H__

#include "HR8P506.h"
#include "type.h"

/* ������ѡ��λ*/
typedef enum {
	LCD_COMS_1 = 0,	/*  */
	LCD_COMS_2 = 4,	/* COM1~COM0*/
	LCD_COMS_3 = 6,	/* COM2~COM0*/
	LCD_COMS_4 = 1,	/* COM3~COM0*/
	LCD_COMS_6 = 2,	/* COM5~COM0*/
	LCD_COMS_8 = 3,	/* COM7~COM0*/
	LCD_COMS_MAX = 6,
}LCD_TYPE_COMS;

/* LCD������������ѡ��*/
typedef enum {
	LCD_WFS_A = 0, /* A����(��ÿһ�����������ڸı���λ)*/
	LCD_WFS_B = 1,/* B����(��ÿһ֡�߽�ı���λ)*/
	LCD_WFS_MAX = 1,
}LCD_TYPE_WFS;

/* LCDʱ��Դѡ��*/
typedef enum {
	LCD_CLK_LRC = 0,/* LRC4��Ƶ(�ڲ�ʱ��32KHz)*/
	LCD_CLK_LOSE = 1,/* LOSC4��Ƶ(�ⲿʱ��32KHz)*/
	LCD_CLK_PCLK4096 = 2,/* PCLK4096��Ƶ*/
	LCD_CLK_MAX = 2,
}LCD_TYPE_CLK;

/* LCDƫ��ѡ��*/
typedef enum {
	LCD_BIAS_1_2 = 0,/* 1/2BIAS*/
	LCD_BIAS_1_3 = 1,/* 1/3BIAS*/
	LCD_BIAS_1_4 = 3,/* 1/4BIAS*/
	LCD_BIAS_MAX = 3,
}LCD_TYPE_BIAS;

/* LCD�ڲ�ƫѹ�����ܺ�ѡ��*/
typedef enum {
	LCD_RS_225K = 0,/* 225Kŷķ*/
	LCD_RS_900K =1,/* 900Kŷķ*/
	LCD_RS_60K = 2,/* 60Kŷķ*/
	LCD_RS_60K_225K = 4,/* 60K��225Kŷķ�Զ��л�*/
	LCD_RS_60K_900K = 5,/* 60K��900Kŷķ�Զ��л�*/
	LCD_RS_MAX = 5,
}LCD_TYPE_RS;

/* LCD60K���豣��ʱ��*/
typedef enum {
	LCD_RT_1_4 = 0,/* 1/4 COM���� */
	LCD_RT_1_8 = 1,/* 1/8 COM���� */
	LCD_RT_1_16 = 2,/* 1/16 COM���� */
	LCD_RT_1_32 = 3,/* 1/32 COM���� */
	LCD_RT_1_64 = 4,/* 1/64 COM���� */
	LCD_RT_MAX = 4,
}LCD_TYPE_RT;

/* ʱ��ԴԤ��Ƶ��ѡ��*/
typedef enum {
	LCD_PRS_MAX = 63,/* �������Ԥ��Ƶ��1:64 */
}LCD_TYPE_PRS;

/* LCD��ʾ�Ҷȿ���(����VDD) */
typedef enum {
	LCD_BVS_15_30 = 0,		/* 1/2VDD*/
	LCD_BVS_16_30 = 1,		/* 16/30VDD*/
	LCD_BVS_17_30 = 2,		/* 17/30VDD*/
	LCD_BVS_18_30 = 3,		/* 18/30VDD*/
	LCD_BVS_19_30 = 4,		/* 19/30VDD*/
	LCD_BVS_20_30 = 5,		/* 20/30VDD*/
	LCD_BVS_21_30 = 6,		/* 21/30VDD*/
	LCD_BVS_22_30 = 7,		/* 22/30VDD*/
	LCD_BVS_23_30 = 8,		/* 23/30VDD*/
	LCD_BVS_24_30 = 9,		/* 24/30VDD*/
	LCD_BVS_25_30 = 10,		/* 25/30VDD*/
	LCD_BVS_26_30 = 11,		/* 26/30VDD*/
	LCD_BVS_27_30 = 12,		/* 27/30VDD*/
	LCD_BVS_28_30 = 13,		/* 28/30VDD*/
	LCD_BVS_29_30 = 14,		/* 29/30VDD*/
	LCD_BVS_30_30 = 15,		/* 30/30VDD*/
	LCD_BVS_MAX = 15,
}LCD_TYPE_BVS;

typedef enum {
	LCD_VLCD_INSIDE = 0,
	LCD_VLCD_OUTSIDE = 1,
	LCD_VLCD_MAX = 1,
}LCD_TYPE_VLCD;

typedef enum {
	LCD_FLIK_NO = 0,
	LCD_FLIK_YES = 1,
	LCD_FLIK_MAX = 1,
}LCD_TYPE_FLIK;

typedef enum {
	LCD_TOFF_MAX = 255,	/* (TOFF+1)*0.25 */
}LCD_TYPE_TOFF;

typedef enum {
	LCD_TON_MAX = 255,		/* (TON+1)*0.25 */
}LCD_TYPE_TON;

/* LCD�������˿�ʹ��λ */
typedef enum {
	LCD_SEG_MAX =	0xfffffff,/* �������ֵ*/
}LCD_TYPE_SEG;

/* LCD LEDѡ�������*/
typedef enum {
	LCD_SEL_LCD = 0,/* ѡ��LCD������*/
	LCD_SEL_LED = 1,/* ѡ��LED������*/
	LCD_SEL_MAX = 1,
}LCD_TYPE_SEL;


typedef FuncState LCD_TYPE_CON1_EN;

/* LCD ���ؼĴ���ѡ��*/
typedef enum
{
	LCD_Pixel_LCDD0 = 0x0 , /* ���ؼĴ���0 */
	LCD_Pixel_LCDD1 = 0x1 , /* ���ؼĴ���1 */
	LCD_Pixel_LCDD2 = 0x2 , /* ���ؼĴ���2 */
	LCD_Pixel_LCDD3 = 0x3 , /* ���ؼĴ���3 */
	LCD_Pixel_LCDD4 = 0x4 , /* ���ؼĴ���4 */
	LCD_Pixel_LCDD5 = 0x5 , /* ���ؼĴ���5 */
	LCD_Pixel_LCDD6 = 0x6 , /* ���ؼĴ���6 */
	LCD_Pixel_MAX = 0x6,
}LCD_TYPE_PIXEL;

/* LCD�����ؼĴ������ֽ�ѡ�� */
typedef enum
{
	LCD_Byte_0 = 0x0 , 	/* �Ĵ����ڵ�0���ֽ�*/
	LCD_Byte_1 = 0x1 , 	/* �Ĵ����ڵ�1���ֽ�*/
	LCD_Byte_2 = 0x2 , 	/* �Ĵ����ڵ�2���ֽ�*/
	LCD_Byte_3 = 0x3 , 	/* �Ĵ����ڵ�3���ֽ�*/
	LCD_Byte_MAX = 0x3,
}LCD_DD_BYTE; 

/* LCD�����ؼĴ�������ѡ�� */ 
typedef enum
{
	LCD_HalfWord_0 = 0x0 , 
	LCD_HalfWord_1 = 0x1 , 
	LCD_HalfWord_MAX = 0x1,
}LCD_DD_HALFWORD; 


typedef union
{
	uint8_t Byte[4];
	uint16_t HalfWord[2];
	uint32_t Word;
}LCD_DD_TypeDef;

/* LCD��ʼ���ṹ��*/
typedef struct
{
	LCD_TYPE_COMS  LCD_COMS;    /*������ѡ��λ */
	uint32_t  LCD_SEG;          		/*��ʹ�� 0~0xfffffff (bit0~27	ÿ1λ����1 ��SEG 	) */

	LCD_TYPE_VLCD LCD_VLCD;      /*�ⲿƫ�õ�ѹʹ��λ*/
	LCD_TYPE_WFS  LCD_WFS;   /*������������ѡ��*/

	LCD_TYPE_CLK LCD_CLK;		/* ʱ��ѡ�� */
	uint8_t  LCD_PRS;           		/* ʱ��Դ��Ƶ��ѡ��λ 0~63*/

	LCD_TYPE_BVS LCD_BVS;
	LCD_TYPE_BIAS  LCD_BIAS;    	/* ƫ��ѡ��*/

	LCD_TYPE_RT LCD_RT;
	LCD_TYPE_RS LCD_RS;

	LCD_TYPE_FLIK LCD_FLIK;
	uint8_t LCD_TOFF;
	uint8_t LCD_TON;
}LCD_InitStruType;

#define LCD_EN() 		(LCD->CON1.EN = 1)
#define LCD_DIS() 		(LCD->CON1.EN = 0)
#define LCD_RST() 		(LCD->CON1.RST = 1)

/************LCDģ�麯������***********/
ErrorStatus LCD_Init(LCD_InitStruType *LCD_InitStruct);
ErrorStatus LCD_GrayscaleConfig(uint8_t BVS_Sel);
ErrorStatus LCD_FlickerTimeConfig(LCD_TYPE_FLIK Flick,uint8_t On_Time,uint8_t Off_Time);
//ErrorStatus LCD_ResistorConfig(LCD_TYPE_RS R_Sel,LCD_TYPE_RT R_Time);
ErrorStatus  LCD_PixelWriteByte(LCD_TYPE_PIXEL LCD_DD, LCD_DD_BYTE nByte ,uint8_t LCD_data);
ErrorStatus  LCD_PixelWriteHalfWord(LCD_TYPE_PIXEL LCD_DD, LCD_DD_HALFWORD nHalfWord , uint16_t LCD_data);
ErrorStatus  LCD_PixelWriteWord(LCD_TYPE_PIXEL LCD_DD,uint32_t LCD_data);
void  LCD_Reset(void);

#endif
