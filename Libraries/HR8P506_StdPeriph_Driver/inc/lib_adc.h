/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_adc.h
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  ADCģ��⺯��ͷ�ļ�
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#ifndef __LIBADC_H__
#define __LIBADC_H__

#include "HR8P506.h"
#include "type.h"

/* �ڲ��ο���ѹѡ�� */
typedef enum {
	ADC_VREF_SEL_1_8 = 0,	/* �ڲ��ο���ѹ1.8v*/
	ADC_VREF_SEL_2_6 = 1,	/* �ڲ��ο���ѹ2.6v*/
	ADC_VREF_SEL_MAX = 1,
}ADC_TYPE_VREF_SEL;

/* CHOP_CLK����ѡ��*/
typedef enum {
	ADC_CHOP_CLK_SEL_1K = 0,	/* 1K */
	ADC_CHOP_CLK_SEL_2K = 1,	/* 2K */
	ADC_CHOP_CLK_SEL_4K = 2,	/* 4K */
	ADC_CHOP_CLK_SEL_8K = 3,	/* 8K */
	ADC_CHOP_CLK_SEL_16K = 4,	/* 16K */
	ADC_CHOP_CLK_SEL_32K = 5,	/* 32K */
	ADC_CHOP_CLK_SEL_MAX = 5,
}ADC_TYPE_CHOP_CLK_SEL;

/* ����˲�ʱ��ѡ�� */
typedef enum {
	ADC_FILTERCLK_SEL_32K = 0,		/* ����˲�ʱ�� 32K*/
	ADC_FILTERCLK_SEL_64K = 1,		/* ����˲�ʱ�� 64K*/
	ADC_FILTERCLK_SEL_128K = 2,	/* ����˲�ʱ�� 128K*/
	ADC_FILTERCLK_SEL_256K = 3,	/* ����˲�ʱ�� 256K*/
	ADC_FILTERCLK_SEL_MAX = 3,
}ADC_TYPE_FILTERCLK_SEL;

/* CHOP CLK ʱ��ԴԤ��Ƶѡ��*/
typedef enum {
	ADC_CHOP_CLK_DIV_1_1 = 0,		/* �ر� */
	ADC_CHOP_CLK_DIV_1_4 =1,		/* 1:4 */
	ADC_CHOP_CLK_DIV_1_8 =2,		/* 1:8 */
	ADC_CHOP_CLK_DIV_1_16 =3,		/* 1:16 */
	ADC_CHOP_CLK_DIV_1_32 =4,		/* 1:32 */
	ADC_CHOP_CLK_DIV_1_64 =5,		/* 1:64 */
	ADC_CHOP_CLK_DIV_1_128 =6,		/* 1:128 */
	ADC_CHOP_CLK_DIV_1_256 =7,		/* 1:256 */
	ADC_CHOP_CLK_DIV_MAX = 7,
}ADC_TYPE_CHOP_CLK_DIV;

typedef FuncState ADC_TYPE_CHOP_EN1, ADC_TYPE_CHOP_EN;
typedef FuncState ADC_TYPE_VREF_EN,ADC_TYPE_IREF_EN;
typedef FuncState ADC_TYPE_EN,ADC_TYPE_ACP_EN;

/* A/Dʱ��ԴԤ��Ƶѡ�� */
typedef enum {
	ADC_CLKDIV_1_1 = 0,	/* 1:1 */
	ADC_CLKDIV_1_2 = 1,	/* 1:2 */
	ADC_CLKDIV_1_4 = 2,	/* 1:4 */
	ADC_CLKDIV_1_8 = 3,	/* 1:8 */
	ADC_CLKDIV_1_16 = 4,	/* 1:16 */
	ADC_CLKDIV_1_32 = 5,	/* 1:32 */
	ADC_CLKDIV_1_64 = 6,	/* 1:64 */
	ADC_CLKDIV_1_256 = 7,	/* 1:256 */
	ADC_CLKDIV_MAX = 7,
}ADC_TYPE_CLKDIV;

/* A/Dʱ��Դѡ�� */
typedef enum {
	ADC_CLKS_PCLK = 0,		/* PCLK */
	ADC_CLKS_LRC= 1,	/* LRC(32KHz) */
	ADC_CLKS_MAX = 1,
}ADC_TYPE_CLKS;

/* A/D����ο���ѹѡ�� */
typedef enum {
	ADC_VREFP_VDD = 0,		/* ѡ��AD�Ĺ�����ѹ */
	ADC_VREFP_IO = 1,		/* ѡ���ڲ��ο���ѹ AVREFP,�˿ڸ�������ͨI/O�˿�*/
	ADC_VREFP_VREF = 2,	/* ѡ���ڲ��ο���ѹ AVREFP,�˿�����ڲ��ο���ѹVREF*/
	ADC_VREFP_AVREFP = 3,	/* �ⲿ�ο���ѹAVREFP,��ѹ���ܸ���AD�Ĺ�����ѹ */
	ADC_VREFP_MAX = 3,
}ADC_TYPE_VREFP;

/* A/D����ο���ѹѡ��*/
typedef enum {
	ADC_VREFN_VSS = 0,		/* �ڲ��ص�ѹVSS */
	ADC_VREFN_AVREFN = 1,	/* �ⲿ�ο���ѹAVREFN */
	ADC_VREFN_MAX = 2,
}ADC_TYPE_VREFN;

/* A/D����ģʽѡ��*/
typedef enum {
	ADC_SMPS_SOFT = 0,		/* ������� */
	ADC_SMPS_HARD = 1,	/* Ӳ������ */
	ADC_SMPS_MAX = 1,
}ADC_TYPE_SMPS;

/* A/D�����������λ*/
typedef enum {
	ADC_SMPON_STOP = 0,	/* �ر�AD���� */
	ADC_SMPON_START = 1,	/* ����AD���� */
	ADC_SMPON_MAX = 1,
}ADC_TYPE_SMPON;

/* A/D����ʱ��ѡ�� (Ӳ��������Ч)*/
typedef enum {
	ADC_ST_MAX = 31,	/* �����������ʱ�� */
}ADC_TYPE_ST;
typedef FuncState ADC_TYPE_VRBUF_EN,ADC_TYPE_HS_EN,ADC_TYPE_VCMBUF_EN,ADC_TYPE_VCMBUF_HS_EN;

/* �Զ��Ƚϵͷ�ֵ ѡ��*/
typedef enum {
	ADC_ACP_MIN_MIN = 0x0,		/* �������С�ͷ�ֵ*/
	ADC_ACP_MIN_MAX = 0xfff,	/* ��������ͷ�ֵ*/
}ADC_TYPE_ACP_MIN;

/* �Զ��Ƚϸ߷�ֵ ѡ��*/
typedef enum {
	ADC_ACP_MAX_MIN = 0x0,	/* �������С�߷�ֵ*/
	ADC_ACP_MAX_MAX = 0xfff,	/* ��������߷�ֵ*/
}ADC_TYPE_ACP_MAX;
#if 0
/* A/Dת���ٶȿ���λ */
typedef enum {
	ADC_SPEED_LOW = 0,		/* ���� */
	ADC_SPEED_HIGH = 1,		/* ���� */
	ADC_SPEED_MAX = 1,
}ADC_TYPE_SPEED;
#endif
/* A/Dģ��ͨ��ѡ��λ */
typedef enum {
	ADC_CHS_AIN0 = 0,		/* ͨ�� 0 */
	ADC_CHS_AIN1 = 1,		/* ͨ�� 1 */
	ADC_CHS_AIN2 = 2,		/* ͨ�� 2 */
	ADC_CHS_AIN3 = 3,		/* ͨ�� 3 */
	ADC_CHS_AIN4 = 4,		/* ͨ�� 4 */
	ADC_CHS_AIN5 = 5,		/* ͨ�� 5 */
	ADC_CHS_AIN6 = 6,		/* ͨ�� 6 */
	ADC_CHS_AIN7 = 7,		/* ͨ�� 7 */
	ADC_CHS_AIN8 = 8,		/* ͨ�� 8 */
	ADC_CHS_AIN9 = 9,		/* ͨ�� 9 */
	ADC_CHS_AIN10 = 10,	/* ͨ�� 10 */
	ADC_CHS_AIN11 = 11,	/* ͨ�� 11 */
	ADC_CHS_AIN12 = 12,	/* ͨ�� 12 */
	ADC_CHS_AIN13 = 13,	/* ͨ�� 13 */
	ADC_CHS_AIN14 = 14,	/* ͨ�� 14 */
	ADC_CHS_AIN15 = 15,	/* ͨ�� 15 */
	ADC_CHS_OC = 16,		/*�¶ȴ���ͨ��*/
	ADC_CHS_MAX = 16,
}ADC_TYPE_CHS;

typedef FuncState ADC_TYPE_INTR_EN,ADC_TYPE_ACP_MIN_INTR_EN,ADC_TYPE_ACP_MAX_INTR_EN,ADC_TYPE_ACP_OVER_INTR_EN;

/* ÿ���Զ�ת���Ƚ����ʱ��ѡ�� */
typedef enum {
	ADC_ACPC_OVFL_TIME_MAX = 0x9c3,	/* �����������ʱ�� */
}ADC_TYPE_ACPC_OVFL_TIME;

/* �Զ�ת���Ƚϴ��� */
typedef enum {
	ADC_ACPC_TIMES_1 = 0,	/* 1�� */
	ADC_ACPC_TIMES_2 = 1,	/* 2�� */
	ADC_ACPC_TIMES_4 = 2,	/* 4�� */
	ADC_ACPC_TIMES_8 = 3,	/* 8�� */
	ADC_ACPC_TIMES_MAX = 3,
}ADC_TYPE_ACPC_TIMES;

/* ACP���ʱ�ӵ�ʱ��Դ */
typedef enum {
	ADC_ACPC_CLKS_PCLK = 0,		/* PCLK */
	ADC_ACPC_CLKS_LRC = 1,			/* LRC(32KHz) */
	ADC_ACPC_CLKS_MAX = 1,
}ADC_TYPE_ACPC_CLKS;


typedef enum {
	ADC_IF			 = 0x01,
	ADC_IF_ACPMIN = 0x02,
	ADC_IF_ACPMAX =0x04,
	ADC_IF_ACPOVER = 0x08,
}ADC_TYPE_IF;

/* ADC IE ״̬ */
typedef enum {
	ADC_IE	= 0x01,
	ADC_IE_ACPMIN = 0x02,
	ADC_IE_ACPMAX =0x04,
	ADC_IE_ACPOVER = 0x08,
}ADC_TYPE_IE;

/* ADC ��ʼ���ṹ�� */
typedef struct {	
	ADC_TYPE_CLKS CLKS;				       /* ADCʱ��ѡ�� */	
	ADC_TYPE_CLKDIV CLKDIV;			     /* ADC Ԥ��Ƶ */
	ADC_TYPE_VREF_SEL VREF_SEL;		 	 /*�ο���ѹѡ�� */
	ADC_TYPE_VREFP VREFP;				     /* �ο���ѹ����ѡ�� */
	ADC_TYPE_VREFN VREFN;
	ADC_TYPE_CHS CHS;					       /* ģ��ͨ��ѡ�� */
	ADC_TYPE_SMPS SMPS;				       /* ����ģʽѡ�� */
	uint8_t ST;							         /* Ӳ������ʱ�� (������ģʽΪӲ��ʱ����) 0~31*/	
}ADC_InitStruType;

/* �Զ��ȽϹ��ܳ�ʼ���ṹ��*/
typedef struct {
	ADC_TYPE_ACP_EN ACP_EN;				  	/* �Զ��ȽϹ���ʹ��λ*/
	uint16_t ACPC_OVER_TIME;					/* �����Զ��Ƚ����ʱ��(��ʹ�������������ó�0) 0~0x9c3 */
	ADC_TYPE_ACPC_TIMES ACPC_TIMES;		/* �����Զ��Ƚϴ���(���ȼ��������ʱ��) */
	uint16_t ACPC_MIN_TARGET;					/* ƽ��ֵ��ͷ�ֵ (����0xfff�ر�) 0~0xfff */
	uint16_t ACPC_MAX_TARGET;					/* ƽ��ֵ��߷�ֵ (����0x0�ر�) 	0~0xfff */
}ADC_ACP_TypeDef;

#define ADC_Enable() (ADC->CON0.EN = 1)
#define ADC_Disable() (ADC->CON0.EN = 0)

/* �Զ��ȽϹ���ʹ��*/
#define ADC_ACP_Enable() (ADC->CON0.ACP_EN = 1)
#define ADC_ACP_Disable() (ADC->CON0.ACP_EN = 0)

#define ADC_IE_Enable() (ADC ->IE.IE = 1)
#define ADC_IE_Disable() (ADC ->IE.IE = 0)

#define ADC_ACPMINIE_Enable() (ADC ->IE.ACPMINIE = 1)
#define ADC_ACPMINIE_Disable() (ADC ->IE.ACPMINIE = 0)

#define ADC_ACPMAXIE_Enable() (ADC ->IE.ACPMAXIE = 1)
#define ADC_ACPMAXIE_Disable() (ADC ->IE.ACPMAXIE = 0)

#define ADC_ACPOVIE_Enable() (ADC ->IE.ACPOVIE = 1)
#define ADC_ACPOVIE_Disable() (ADC ->IE.ACPOVIE = 0)

/********************* ADCģ�麯������ *********************/
ErrorStatus ADC_Init(ADC_InitStruType * ADC_InitStruct);
ErrorStatus ADC_ACPConfig(ADC_ACP_TypeDef *ADC_ACP_InitStruct);
ErrorStatus ADC_Start(void);
ErrorStatus ADC_SoftStart(void);
ErrorStatus ADC_SoftStop(void);
uint16_t ADC_GetConvValue(void);
FlagStatus ADC_GetConvStatus(void);
uint16_t ADC_GetACPMeanValue(void);
ITStatus ADC_GetIFStatus(ADC_TYPE_IF IFName);
ITStatus ADC_GetIEStatus(ADC_TYPE_IE IEName);
ErrorStatus ADC_ClearIFStatus(ADC_TYPE_IF IFName);
void ADC_Reset(void);

#endif
