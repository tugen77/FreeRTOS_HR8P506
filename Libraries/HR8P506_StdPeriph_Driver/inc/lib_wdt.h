/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_wdt.h
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  WDTģ��⺯��ͷ�ļ�
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#ifndef __LIBWDT_H__
#define __LIBWDT_H__

#include "HR8P506.h"
#include "type.h"

/* WDTʱ��ѡ�� */
typedef enum {
	WDT_CLOCK_PCLK = 0x0,	//PCLK
	WDT_CLOCK_WDT  = 0x1,	//WDTʱ��Դ��32kHz
} WDT_TYPE_CLKS;

/* ��ʼ���ṹ�� */
typedef struct {
	uint32_t WDT_Tms;		//��ʱʱ�䣬��λms 
	TYPE_FUNCEN WDT_IE;		//�ж�ʹ��
	TYPE_FUNCEN WDT_Rst;	//��λʹ��
	WDT_TYPE_CLKS WDT_Clock;//ʱ��ѡ��
} WDT_InitStruType;


#define WDT_RegUnLock()		(WDT->LOCK.Word = 0x1ACCE551)
#define WDT_RegLock()		(WDT->LOCK.Word = 0x0)

#define WDT_Enable()		(WDT->CON.EN = 1)
#define WDT_Disable()		(WDT->CON.EN = 0)

#define WDT_Clear()			{WDT_RegUnLock();WDT->INTCLR.Word = 0;WDT_RegLock();}

#define WDT_ITEnable()		(WDT->CON.IE = 1)
#define WDT_ITDisable()		(WDT->CON.IE = 0)

#define WDT_RstEnable()		(WDT->CON.RSTEN = 1)
#define WDT_RstDisable()	(WDT->CON.RSTEN = 0)

#define WDT_CLOCK_PCLK()	(WDT->CON.CLKS = 0)
#define WDT_CLOCK_WDT()		(WDT->CON.CLKS = 1)


void WDT_Init(WDT_InitStruType *WDT_InitStruct);
void WDT_SetReloadValue(uint32_t Value);
uint32_t WDT_GetValue(void);
FlagStatus WDT_GetFlagStatus(void);

#endif
