/******************************************************************************
 * @file     lib_lcd.h
 * @brief    spi module for HR8P506
 *
 * @version  V1.0
 * @date     30.Oct.2015
 *
 * @author   hanlei
 *
 * @note
 * Copyright (C) Shanghai Eastsoft Microelectronics Co. Ltd. All rights reserved.
 *
 ******************************************************************************/
#if 0

#ifndef __LIBLED_H__
#define __LIBLED_H__

#include "HR8P506.h"
#include "type.h"
/* ������ѡ��λ*/
typedef enum {
	LED_MUX_0_0		= 0,
	LED_MUX_0_1		= 1,
	LED_MUX_0_2		= 2,
	LED_MUX_0_3		= 3,
	LED_MUX_0_4		= 4,
	LED_MUX_0_5		= 5,
	LED_MUX_0_6		= 6,
	LED_MUX_0_7		= 7,
	LED_MUX_MAX 		=7,
}LED_TYPE_MUX;

/* LED�������˿�COMʹ��λ */
typedef enum {
	LED_COM_0 = (1<<0),
	LED_COM_1 = (1<<1),
	LED_COM_2 = (1<<2),
	LED_COM_3 = (1<<3),
	LED_COM_4 = (1<<4),
	LED_COM_5 = (1<<5),
	LED_COM_6 = (1<<6),
	LED_COM_7 = (1<<7),
	LED_COM_MAX = 0xff,
}LED_TYPE_COM;

/* LED�������˿�SEGʹ��λ */
typedef enum {
	LED_SEG_0 = (1<<0),
	LED_SEG_1 = (1<<1),
	LED_SEG_2 = (1<<2),
	LED_SEG_3 = (1<<3),
	LED_SEG_4 = (1<<4),
	LED_SEG_5 = (1<<5),
	LED_SEG_6 = (1<<6),
	LED_SEG_7 = (1<<7),
	LED_SEG_MAX = 0xff,
}LED_TYPE_SEG;

/* LEDʱ��Դѡ��*/
typedef enum {
	LED_CLK_LRC		= 0,		/* LRC(�ڲ�ʱ��32KHz)*/
	LED_CLK_LOSC		= 1,		/* LOSC(�ⲿʱ��32KHz)*/
	LED_CLK_PCLK1024	= 2,		/* PCLK1024��Ƶ*/
	LED_CLK_MAX		= 3
}LED_TYPE_CLK;

/* LEDԤ��Ƶѡ��*/
typedef enum {
	LED_PRS_MAX = 63,/*�������Ԥ��Ƶ��*/
}LED_TYPE_PRS;

/* LCD LEDѡ�������*/
typedef enum {
	LED_SEL_LCD = 0,	/* ѡ��LCD������*/
	LED_SEL_LED = 1,	/* ѡ��LED������*/
	LED_SEL_MAX = 1,
}LED_TYPE_SEL;


/* LED ���ؼĴ���ѡ��*/
typedef enum {
	LED_Pixel_LEDD0 = 0x0 , /* ���ؼĴ���0 */
	LED_Pixel_LEDD1 = 0x1 , /* ���ؼĴ���1 */
	LED_Pixel_MAX = 0x1,
}LED_TYPE_PIXEL;

/* LED�����ؼĴ������ֽ�ѡ�� */
typedef enum {
	LED_Byte_0 = 0x0 , 		/* �Ĵ����ڵ�0���ֽ�*/
	LED_Byte_1 = 0x1 , 		/* �Ĵ����ڵ�1���ֽ�*/
	LED_Byte_2 = 0x2 , 		/* �Ĵ����ڵ�2���ֽ�*/
	LED_Byte_3 = 0x3 , 		/* �Ĵ����ڵ�3���ֽ�*/
	LED_Byte_MAX = 0x3,
}LED_DD_BYTE; 

typedef union
{
	uint8_t Byte[4];
	uint16_t HalfWord[2];
	uint32_t Word;
}LED_DD_TypeDef;

/* LED�����ؼĴ�������ѡ�� */ 
typedef enum {
	LED_HalfWord_0 = 0x0 , 
	LED_HalfWord_1 = 0x1 , 
	LED_HalfWord_MAX = 0x1,
}LED_DD_HALFWORD; 

/* LED��ʼ���ṹ��*/
typedef struct {
	LED_TYPE_MUX LED_MUX;	/* ������ѡ��*/
	uint8_t LED_COM;			/* SEGʹ��0~255(ÿ1bit����1��COM) */
	uint8_t LED_SEG;			/* SEGʹ��0~255(ÿ1bit����1��SEG ) */
	LED_TYPE_CLK LED_CLK;	/* ʱ��ѡ��*/
	uint8_t LED_PRS;			/* Ԥ��Ƶѡ��0~63*/
}LED_InitStruType;

#define LED_EN() 		(LED->CON1.EN = 1)
#define LED_DIS() 		(LED->CON1.EN = 0)
#define LED_RST() 		(LED->CON1.RST = 1)



/************LCDģ�麯������***********/
ErrorStatus LED_Init(LED_InitStruType * LED_InitStruct);
ErrorStatus  LED_PixelWriteByte(LED_TYPE_PIXEL LED_DD, LED_DD_BYTE nByte , uint8_t LED_data);
ErrorStatus  LED_PixelWriteHalfWord(LED_TYPE_PIXEL LED_DD, LED_DD_HALFWORD nHalfWord , uint16_t LED_data);
ErrorStatus  LED_PixelWriteWord(LED_TYPE_PIXEL LED_DD,uint32_t LED_data);

void LED_Reset(void);
#endif
#endif

