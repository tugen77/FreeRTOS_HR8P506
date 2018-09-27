/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_adc.c
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  ADCģ��⺯��
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#include "lib_adc.h"

/***************************************************************
  ��������ADC_Init
  ��  ����ADC���ܳ�ʼ������
  ����ֵ��ADC_InitStruct ��ʼ���ṹ��
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus ADC_Init(ADC_InitStruType * ADC_InitStruct)
{
	if(ADC_InitStruct->CLKS > ADC_CLKS_MAX
			||ADC_InitStruct->CLKDIV > ADC_CLKDIV_MAX
			||ADC_InitStruct->VREF_SEL > ADC_VREF_SEL_MAX
			||ADC_InitStruct->VREFP > ADC_VREFP_MAX
			||ADC_InitStruct->VREFN > ADC_VREFN_MAX
			||ADC_InitStruct->CHS > ADC_CHS_MAX
			||ADC_InitStruct->SMPS > ADC_SMPS_MAX
			||ADC_InitStruct->ST > ADC_ST_MAX) {
		return ERROR;
	}

	ADC_Reset();

	ADC->VREFCON.VREF_EN = ENABLE;
	ADC->VREFCON.IREF_EN = ENABLE;
	ADC->CON1.VCMBUF_EN = ENABLE;	
	ADC ->CON1.VCMBUF_HS = ENABLE;
	ADC->CON1.HSEN = ENABLE;

	ADC->CHS.CHS = ADC_InitStruct->CHS;
	ADC->CON1.CLKS = ADC_InitStruct->CLKS;
	ADC->CON1.CLKDIV = ADC_InitStruct->CLKDIV;
	ADC->CON1.VREFP = ADC_InitStruct->VREFP ;
	ADC->CON1.VREFN = ADC_InitStruct->VREFN;
	ADC->VREFCON.VREF_SEL=ADC_InitStruct->VREF_SEL;
	if((ADC_InitStruct->VREFP == ADC_VREFP_IO)||(ADC_InitStruct->VREFP == ADC_VREFP_VREF)) 
		ADC->CON1.VRBUF_EN = ENABLE;
	else
		ADC->CON1.VRBUF_EN = DISABLE;


	ADC->CHS.VDD5_FLAG_EN = 0;
	ADC->CON1.SMPS = ADC_InitStruct->SMPS;
	ADC->CON1.ST = ADC_InitStruct->ST;
	ADC->CON0.EN = ENABLE;
	return SUCCESS;
}

/***************************************************************
  ��������ADC_ACPConfig
  ��  ����ADC �Զ��ȽϹ��ܳ�ʼ��
  ����ֵ��ADC_ACP_InitStruct �Զ��ȽϹ��ܳ�ʼ���ṹ��
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus ADC_ACPConfig(ADC_ACP_TypeDef *ADC_ACP_InitStruct)
{

	if(ADC_ACP_InitStruct->ACPC_OVER_TIME > ADC_ACPC_OVFL_TIME_MAX
			||ADC_ACP_InitStruct->ACPC_TIMES > ADC_ACPC_TIMES_MAX
			||ADC_ACP_InitStruct->ACPC_MIN_TARGET > ADC_ACP_MIN_MAX
			||ADC_ACP_InitStruct->ACPC_MAX_TARGET > ADC_ACP_MAX_MAX) {
		return ERROR;
	}

	if(ADC_ACP_InitStruct ->ACP_EN == ENABLE) {
		if(ADC->CON1.CLKS == ADC_CLKS_PCLK) {
			ADC->ACPC.CLKS = ADC_ACPC_CLKS_PCLK;
		}
		else {
			ADC->ACPC.CLKS = ADC_ACPC_CLKS_LRC;
		}

		ADC->ACPC.OVFL_TIME = ADC_ACP_InitStruct ->ACPC_OVER_TIME;
		ADC->ACPC.TIMES = ADC_ACP_InitStruct->ACPC_TIMES;
		ADC->IE.ACPOVIE = ENABLE;

		/* �����û����߷�ֵ���ó�0(��Сֵ)�����ǿ�����Ϊ����رոù��� */
		if(ADC_ACP_InitStruct ->ACPC_MAX_TARGET ==0x0) {
			ADC->IE.ACPMAXIE = DISABLE;
		}
		else {
			ADC->ACPCMP.CMP_MAX =ADC_ACP_InitStruct ->ACPC_MAX_TARGET;
			ADC->IE.ACPMAXIE = ENABLE;
		}

		/* �����û����ͷ�ֵ���ó�0xfff(���ֵ)�����ǿ�����Ϊ����رոù��� */
		if(ADC_ACP_InitStruct ->ACPC_MIN_TARGET == 0xfff) {
			ADC->IE.ACPMINIE = DISABLE;
		}
		else {
			ADC->ACPCMP.CMP_MIN =ADC_ACP_InitStruct ->ACPC_MIN_TARGET;
			ADC->IE.ACPMINIE = ENABLE;
		}

		ADC->CON0.ACP_EN = ENABLE;

	}
	else {
		ADC->CON0.ACP_EN = DISABLE;
	}
	return SUCCESS;
}

/***************************************************************
  ��������ADC_Start
  ��  ����ADC ��������
  ����ֵ����
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus ADC_Start(void)
{
	if(ADC->CON1.SMPS == ADC_SMPS_SOFT) {
		return ERROR;
	}
	ADC->CON0.TRIG = SET;/* 40001004 BIT1*/
	return SUCCESS;
}

/***************************************************************
  ��������ADC_SampStart
  ��  ����ADC �����������-��������
  ����ֵ����
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus ADC_SoftStart(void)
{
	if(ADC->CON1.SMPS == ADC_SMPS_HARD)
	{
		return ERROR;
	}
	ADC ->CON1.SMPON = SET;/* 40001008 BIT13*/
	return SUCCESS;
}

/***************************************************************
  ��������ADC_SampStop
  ��  ����ADC �����������-ֹͣ����
  ����ֵ����
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus ADC_SoftStop(void)
{
	if(ADC->CON1.SMPS == ADC_SMPS_HARD)
	{
		return ERROR;
	}
	ADC ->CON1.SMPON = RESET;/* 40001008 BIT13*/
	return SUCCESS;
}

/***************************************************************
  ��������ADC_GetConvValue
  ��  ����ADC ��ò������ݺ���
  ����ֵ����
  ���ֵ����
  ����ֵ����������
 ***************************************************************/
uint16_t ADC_GetConvValue(void)
{
	return  ((uint16_t)ADC->DR.DR);/* 40001000 BIT15-0*/
}

/***************************************************************
  ��������ADC_GetConvStatus
  ��  ����ADC ��ô�ʱ״̬
  ����ֵ����
  ���ֵ����
  ����ֵ��SET  ���ڽ���ת��
  RESET	δ����ת������ת�����
 ***************************************************************/
FlagStatus ADC_GetConvStatus(void)
{
	if(ADC->CON0.TRIG == RESET) {/* 40001004 BIT1*/
		return RESET;
	}
	return SET;
}

/***************************************************************
  ��������ADC_GetACPMeanValue
  ��  ����ADC ��õ����Զ��Ƚ�ƽ��ֵ
  ����ֵ����
  ���ֵ����
  ����ֵ����������
 ***************************************************************/
uint16_t ADC_GetACPMeanValue(void)
{
	return  ((uint16_t)ADC->ACPMEAN.MEAN_DATA);
}

/***************************************************************
  ��������ADC_GetIFStatus
  ��  ����ADC ����ض������ж����
  ����ֵ��IFName �ж�����ѡ��
  ADC_IF			ADC�ж�
  ADC_IF_ACPMIN	�Զ�ת���ͷ�ֵ�����ж�
  ADC_IF_ACPMAX	�Զ�ת���߷�ֵ�����ж�
  ADC_IF_ACPOVER	�Զ�ת������ж�
  ���ֵ����
  ����ֵ���жϱ�־���
 ***************************************************************/
ITStatus ADC_GetIFStatus(ADC_TYPE_IF IFName)
{
	if(ADC->IF.Word & IFName) {
		return SET;
	}
	return RESET;
}

/***************************************************************
  ��������ADC_GetIEStatus
  ��  ����ADC ����ض������ж����
  ����ֵ��IFName �ж�����ѡ��
  ADC_IE ADC�ж�
  ADC_IE_ACPMIN	�Զ�ת���ͷ�ֵ�����ж�
  ADC_IE_ACPMAX	�Զ�ת���߷�ֵ�����ж�
  ADC_IE_ACPOVER	�Զ�ת������ж�
  ���ֵ����
  ����ֵ���жϱ�־���
 ***************************************************************/
ITStatus ADC_GetIEStatus(ADC_TYPE_IE IEName)
{
	if(ADC->IE.Word & IEName) {
		return SET;
	}
	return RESET;
}

/***************************************************************
  ��������ADC_ClearIFStatus
  ��  ����ADC ����ض������ж�
  ����ֵ��IFName �ж�����ѡ��
  ADC_IF			ADC�ж�
  ADC_IF_ACPMIN	�Զ�ת���ͷ�ֵ�����ж�
  ADC_IF_ACPMAX	�Զ�ת���߷�ֵ�����ж�
  ADC_IF_ACPOVER	�Զ�ת������ж�
  ���ֵ����
  ����ֵ��SUCCESS �ɹ�
  ERROR ʧ��
 ***************************************************************/
ErrorStatus ADC_ClearIFStatus(ADC_TYPE_IF IFName)
{
	ADC->IF.Word = (uint32_t)IFName;
	return SUCCESS;
}

/***************************************************************
  ��������ADC_Reset
  ��  ����ADC��λ
  ����ֵ����
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void ADC_Reset(void)
{
	ADC->CON0.Word = 0x00000000;
	ADC->CON1.Word = 0x00041000;
	ADC->CHS.Word = 0x00000100;
	ADC->IE.Word = 0x00000000; 
	ADC->IF.Word = 0x00000000;
	ADC->ACPC.Word = 0x00000000;
	ADC->ACPCMP.Word = 0x0fff0000;
	ADC->VREFCON.Word = 0x00000000; 
}
