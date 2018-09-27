/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_gpio.h
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  GPIOģ��⺯ͷ�ļ�
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#ifndef __LIB_GPIO_H__
#define __LIB_GPIO_H__

#include <stdint.h>
#include "HR8P506.h"
#include "type.h"

/* GPIO���ű�� */
typedef enum {
	GPIO_Pin_B0 = 0,
	GPIO_Pin_B1 = 1,
	GPIO_Pin_B2 = 2,
	GPIO_Pin_B3 = 3,
	GPIO_Pin_B4 = 4,
	GPIO_Pin_B5 = 5,
	GPIO_Pin_B6 = 6,
	GPIO_Pin_B7 = 7,
	GPIO_Pin_B8 = 8,
	GPIO_Pin_B9 = 9,
	GPIO_Pin_B10 = 10,
	GPIO_Pin_B11 = 11,
	GPIO_Pin_B12 = 12,
	GPIO_Pin_B13 = 13,
	GPIO_Pin_A0 = 14,
	GPIO_Pin_A1 = 15,
	GPIO_Pin_A2 = 16,
	GPIO_Pin_A3 = 17,
	GPIO_Pin_A4 = 18,
	GPIO_Pin_A5 = 19,
	GPIO_Pin_A6 = 20,
	GPIO_Pin_A7 = 21,
	GPIO_Pin_A8 = 22,
	GPIO_Pin_A9 = 23,
	GPIO_Pin_A10 = 24,
	GPIO_Pin_A11 = 25,
	GPIO_Pin_A12 = 26,
	GPIO_Pin_A13 = 27,
	GPIO_Pin_A14 = 28,
	GPIO_Pin_A15 = 29,
	GPIO_Pin_A16 = 30,
	GPIO_Pin_A17 = 31,
	GPIO_Pin_A18 = 32,
	GPIO_Pin_A19 = 33,
	GPIO_Pin_A20 = 34,
	GPIO_Pin_A21 = 35,
	GPIO_Pin_A22 = 36,
	GPIO_Pin_A23 = 37,
	GPIO_Pin_A24 = 38,
	GPIO_Pin_A25 = 39,
	GPIO_Pin_A26 = 40,
	GPIO_Pin_A27 = 41,
	GPIO_Pin_A28 = 42,
	GPIO_Pin_A29 = 43,
	GPIO_Pin_A30 = 44,
	GPIO_Pin_A31 = 45,
} GPIO_Pin;

/* ���Ÿ��ù���ѡ�� */
typedef enum {
	GPIO_Reuse_Func0 = 0,	// ���Ÿ��ù���0
	GPIO_Reuse_Func1 = 1,	// ���Ÿ��ù���1
	GPIO_Reuse_Func2 = 2,	// ���Ÿ��ù���2
	GPIO_Reuse_Func3 = 3,	// ���Ÿ��ù���3
} GPIO_Reuse_Func;

/* ���ŷ���ѡ�� */
typedef enum {
	GPIO_Direction_Output = 0,	// �������
	GPIO_Direction_Input = 1,	// ���뷽��
} GPIO_Direction;

/* ���������©ʹ��λ */
typedef enum {
	GPIO_ODE_Output_Disable = 0,	// ��©��ֹ
	GPIO_ODE_Output_Enable = 1,	// ��©ʹ��
} GPIO_ODE_Output;

/* �������������������ѡ�� */
typedef enum {
	GPIO_DS_Output_Normal = 0,	// ��ͨ�������
	GPIO_DS_Output_Strong = 1,	// ǿ�������
} GPIO_DS_Output;

/* ��������������ʹ�� */
typedef enum {
	GPIO_PUE_Input_Disable = 0,	// ��������ֹ
	GPIO_PUE_Input_Enable = 1,	// ������ʹ��
} GPIO_PUE_Input;

/* ��������������ʹ�� */
typedef enum {
	GPIO_PDE_Input_Disable = 0,	// ��������ֹ
	GPIO_PDE_Input_Enable = 1,	// ������ʹ��
} GPIO_PDE_Input;

/* �����ź����� */
typedef enum {
	GPIO_Pin_Signal_Digital = 0,	// �����ź�����
	GPIO_Pin_Signal_Analog = 1,	// ģ���ź�����
} GPIO_Pin_Signal;	

/* GPIO��ʼ�����ýṹ���� */
typedef struct {
	GPIO_Pin_Signal Signal;		/* �����ϵ��ź����ͣ�ֻ��ģ����������� */

	GPIO_Direction Dir;		/* ��������ʱ���������롢�������ѡ�� */
	GPIO_Reuse_Func Func;		/* ��������ʱ�����Ÿ��ù���ѡ�� */

	GPIO_ODE_Output ODE;		/* �������š��������ʱ����©���ѡ�� */
	GPIO_DS_Output DS;		/* �������š��������ʱ�����������Сѡ�� */

	GPIO_PUE_Input PUE;		/* �������š����뷽��ʱ��������ѡ�� */
	GPIO_PDE_Input PDE;		/* �������š����뷽��ʱ��������ѡ�� */
} GPIO_InitSettingType;

/* �ⲿ�˿��ж�ʹ�� */
typedef enum {
	PINT_IE_Set_Disable = 0,	// �жϽ�ֹ
	PINT_IE_Set_Enable = 1,		// �ж�ʹ��
} PINT_IE_Set;

/* �ⲿ�˿��жϴ�����ʽ */
typedef enum {
	PINT_Trigger_Rising_Edge = 0,	// �����ش����ж�
	PINT_Trigger_Trailing_Edge = 1,	// �½��ش����ж�
	PINT_Trigger_High_Level = 2,	// �ߵ�ƽ�����ж�
	PINT_Trigger_Low_Level = 3,	// �͵�ƽ�����ж�
	PINT_Trigger_Both_Edge = 4,	// �����غ��½��ض������ж�
} PINT_Trigger_Style;

/* �ⲿ�˿ڳ�ʼ�����ýṹ���� */
typedef struct {
	PINT_IE_Set IE_Set;			// �ж��Ƿ�ʹ��
	PINT_Trigger_Style Trigger_Style;	// �жϴ�����ʽ
} PINT_InitSettingType;

/* KINT�ж�ʹ�� */
typedef enum {
	KINT_IE_Set_Disable = 0,	// �жϽ�ֹ
	KINT_IE_Set_Enable = 1,		// �ж�ʹ��
} KINT_IE_Set;

/* KINT�жϷ�ʽ */
typedef enum {
	KINT_Trigger_Rising_Edge = 0,	// �����ش����ж�
	KINT_Trigger_Trailing_Edge = 1,	// �½��ش����ж�
	KINT_Trigger_High_Level = 2,	// �ߵ�ƽ�����ж�
	KINT_Trigger_Low_Level = 3,	// �͵�ƽ�����ж�
	KINT_Trigger_Both_Edge = 4,	// �����غ��½��ض������ж�
} KINT_Trigger_Style;

/* KINT��ʼ�����ýṹ���� */
typedef struct {
	KINT_IE_Set IE_Set;			// �ж��Ƿ�ʹ��
	KINT_Trigger_Style Trigger_Style;	// �жϴ�����ʽ
} KINT_InitSettingType;

/* ������Ƶ�ƽ */
typedef enum
{
  UART_TXPLV_Low = 0x0 ,  //������Ƶ�ƽ:��
  UART_TXPLV_High = 0x1 , //������Ƶ�ƽ:��
}UART_TYPE_TXPLV;


/* ����PWM����ѡ�� */
typedef enum
{
  UART_TX0PS_NO = 0x0 ,        //����PWM����ѡ��:�ǵ������
	UART_TX0PS_T16N0Out0 = 0x1 , //����PWM����ѡ��:T16N1OUT0
	UART_TX0PS_T16N0Out1 = 0x2 , //����PWM����ѡ��:T16N1OUT1
	UART_TX0PS_BUZ = 0x3 ,       //����PWM����ѡ��:BUZ����Ҫ�̶�38K���
}UART_TYPE_TX0PS;

typedef enum
{
  UART_TX1PS_NO = 0x0 ,        //����PWM����ѡ��:�ǵ������
	UART_TX1PS_T16N1Out0 = 0x1 , //����PWM����ѡ��:T16N1OUT0
	UART_TX1PS_T16N1Out1 = 0x2 , //����PWM����ѡ��:T16N1OUT1
	UART_TX1PS_BUZ = 0x3 ,       //����PWM����ѡ��:BUZ����Ҫ�̶�38K���
}UART_TYPE_TX1PS;


/*���Ʋ�������ܽ�����*/
typedef enum
{
	UART_TYPE_E0TX0 = 0,          //E0TX0�ܽ����
	UART_TYPE_T16N1OUT0 = 1,      //T16N1OUT0�ܽ����
	UART_TYPE_T16N1OUT1 = 2,      //T16N1OUT1�ܽ����
	UART_TYPE_TX1BUZ = 3,         //BUZ�ܽ����
}UART_TYPE_TX1Sx;

typedef enum
{
	UART_TYPE_TXD0 = 0,           //TXD0�ܽ����
	UART_TYPE_T16N0OUT0 = 1,      //T16N0OUT0�ܽ����
	UART_TYPE_T16N0OUT1 = 2,      //T16N0OUT1�ܽ����
	UART_TYPE_TX0BUZ = 3,         //BUZ�ܽ����
}UART_TYPE_TX0Sx;

/********************* GPIOģ�麯������ *********************/
void GPIO_Init(GPIO_Pin Pin, GPIO_InitSettingType *InitSet);
uint32_t GPIO_ReadBit(GPIO_Pin Pin);
void GPIO_WriteBit(GPIO_Pin Pin, uint32_t value);
void GPIO_SetBit(GPIO_Pin Pin);
void GPIO_ResetBit(GPIO_Pin Pin);
void GPIO_ToggleBit(GPIO_Pin Pin);
void PINT_Init(GPIO_Pin Pin, PINT_InitSettingType *InitSet);
void PINT_ClearITFlag(GPIO_Pin Pin);
uint32_t PINT_GetITFlag(GPIO_Pin Pin);
void KINT_Init(GPIO_Pin Pin, KINT_InitSettingType *InitSet);
void KINT_ClearITFlag(GPIO_Pin Pin);
uint32_t KINT_GetITFlag(GPIO_Pin Pin);
void GPIO_TX0Config(UART_TYPE_TXPLV Plv,UART_TYPE_TX0PS Ps,UART_TYPE_TX0Sx TX0Sx,TYPE_FUNCEN NewState);
void GPIO_TX1Config(UART_TYPE_TXPLV Plv,UART_TYPE_TX1PS Ps,UART_TYPE_TX1Sx TX1Sx,TYPE_FUNCEN NewState);

#endif
