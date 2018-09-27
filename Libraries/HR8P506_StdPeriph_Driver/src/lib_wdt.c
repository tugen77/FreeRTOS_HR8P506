/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_wdt.c
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  WDTģ��⺯��
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#include "lib_wdt.h"
#include "system_HR8P506.h"

/*************************************
  ��������WDT_Init
  ��  ����UART��ʼ��
  ����ֵ����ʼ���ṹ��
  ����ֵ����
 **************************************/
void WDT_Init(WDT_InitStruType *WDT_InitStruct)
{
	uint32_t tmp;

	if (WDT_InitStruct->WDT_Clock != WDT_CLOCK_PCLK)
		tmp = (uint32_t)(32 * WDT_InitStruct->WDT_Tms);
	else
		tmp = SystemCoreClock / 1000 * WDT_InitStruct->WDT_Tms;

	WDT->LOAD.Word = tmp;
	WDT->CON.CLKS = WDT_InitStruct->WDT_Clock;
	WDT->CON.IE = WDT_InitStruct->WDT_IE;
	WDT->CON.RSTEN = WDT_InitStruct->WDT_Rst;

	return;
}

/*************************************
  ��������WDT_SetReloadValue
  ��  ��������WDT���صĳ�ֵ
  ����ֵ����ʼֵ��32-bit�޷�������
  ����ֵ����
 **************************************/
void WDT_SetReloadValue(uint32_t Value)
{
	WDT->LOAD.Word = Value;
	return;
}

/*************************************
  ��������WDT_GetValue
  ��  ������ȡWDT��ǰֵ
  ����ֵ����
  ����ֵ����ǰֵ
 **************************************/
uint32_t WDT_GetValue(void)
{
	return (uint32_t)WDT->VALUE.Word;
}

/*************************************
  ��������WDT_GetFlagStatus
  ��  ������ȡWDT�ж�״̬
  ����ֵ����
  ����ֵ��SET/RESET
 **************************************/
FlagStatus WDT_GetFlagStatus(void)
{
	FlagStatus bitstatus = RESET;

	if (WDT->RIS.WDTIF != RESET)
		bitstatus = SET;

	return  bitstatus;
}
