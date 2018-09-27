/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_timer.h
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  Timerģ��⺯��ͷ�ļ�
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#ifndef __LIB_TIMER_H__
#define __LIB_TIMER_H__

#include <stdint.h>
#include "HR8P506.h"
#include "type.h"
#include "system_HR8P506.h"


/* ʱ��Դѡ�� */
typedef enum
{

	T16Nx_ClkS_PCLK = 0x0 , //ʱ��Դѡ��:�ڲ�PCLK
	T16Nx_ClkS_CK0 = 0x1 ,  //ʱ��Դѡ��:�ⲿCK0ʱ������
	T16Nx_ClkS_CK1 = 0x2 ,  //ʱ��Դѡ��:�ⲿCK1ʱ������
}T16Nx_TYPE_CLKS;

/* �ⲿʱ�Ӽ�������ѡ�� */
typedef enum
{
	T16Nx_EDGE_Rise = 0x0 , //�ⲿʱ�Ӽ�������ѡ��:������
	T16Nx_EDGE_Fall = 0x1 , //�ⲿʱ�Ӽ�������ѡ��:�½���
	T16Nx_EDGE_All = 0x2 ,  //�ⲿʱ�Ӽ�������ѡ��:����
}T16Nx_TYPE_EDGE;


/* ����ģʽѡ�� */
typedef enum
{
	T16Nx_Mode_TC0 = 0x0 , //����ģʽ:��ʱ������ģʽ
	T16Nx_Mode_TC1 = 0x1 , //����ģʽ:��ʱ������ģʽ
	T16Nx_Mode_CAP = 0x2 , //����ģʽ:��׽ģʽ
	T16Nx_Mode_PWM = 0x3 , //����ģʽ:����ģʽ
}T16Nx_TYPE_MODE;

/* T16Nx��ʼ�����ýṹ�嶨�� */
typedef struct
{
	T16Nx_TYPE_CLKS   T16Nx_ClkS; //ʱ��Դѡ��

	TYPE_FUNCEN       T16Nx_SYNC;   //�ⲿʱ��ͬ��

	T16Nx_TYPE_EDGE   T16Nx_EDGE; //�ⲿʱ�Ӽ�������ѡ��

	T16Nx_TYPE_MODE   T16Nx_Mode; //����ģʽѡ��

	unsigned int      T16Nx_PREMAT;  //����Ԥ��Ƶ�ȣ���Χ ��1-256


}T16Nx_BaseInitStruType;

/* ��׽�������� */
typedef enum
{
	T16Nx_CapTime_1 = 0x0 , //��׽��������:1
	T16Nx_CapTime_2 = 0x1 , //��׽��������:2
	T16Nx_CapTime_3 = 0x2 , //��׽��������:3
	T16Nx_CapTime_4 = 0x3 , //��׽��������:4
	T16Nx_CapTime_5 = 0x4 , //��׽��������:5
	T16Nx_CapTime_6 = 0x5 , //��׽��������:6
	T16Nx_CapTime_7 = 0x6 , //��׽��������:7
	T16Nx_CapTime_8 = 0x7 , //��׽��������:8
	T16Nx_CapTime_9 = 0x8 , //��׽��������:9
	T16Nx_CapTime_10 = 0x9 , //��׽��������:10
	T16Nx_CapTime_11 = 0xA , //��׽��������:11
	T16Nx_CapTime_12 = 0xB , //��׽��������:12
	T16Nx_CapTime_13 = 0xC , //��׽��������:13
	T16Nx_CapTime_14 = 0xD , //��׽��������:14
	T16Nx_CapTime_15 = 0xE , //��׽��������:15
	T16Nx_CapTime_16 = 0xF , //��׽��������:16
} T16Nx_TYPE_CAPT;

/* ��׽���ܳ�ʼ���ṹ�嶨�� */
typedef struct
{
	TYPE_FUNCEN  T16Nx_CAPCAPL1;   //��׽1���ؼ�����ʹ��

	TYPE_FUNCEN  T16Nx_CAPCAPL0;   //��׽0���ؼ�����ʹ��

	TYPE_FUNCEN  T16Nx_CapRise;    //�����ز�׽ʹ��

	TYPE_FUNCEN  T16Nx_CapFall;    //�½��ز�׽ʹ��

	TYPE_FUNCEN  T16Nx_CapIS0;     //����˿�0ʹ��

	TYPE_FUNCEN  T16Nx_CapIS1;     //����˿�1ʹ��

	T16Nx_TYPE_CAPT  T16Nx_CapTime;  //��׽��������

}T16Nx_CapInitStruType;


/* ƥ��Ĵ���ֵƥ���Ĺ���ģʽ */
typedef enum
{
	T16Nx_Go_No = 0x0 ,    //ƥ��Ĵ���ֵƥ���Ĺ���ģʽ:�����������������ж�
	T16Nx_Hold_Int = 0x1 , //ƥ��Ĵ���ֵƥ���Ĺ���ģʽ:���ּ����������ж�
	T16Nx_Clr_Int = 0x2 ,  //ƥ��Ĵ���ֵƥ���Ĺ���ģʽ:���㲢���¼����������ж�
	T16Nx_Go_Int = 0x3 ,   //ƥ��Ĵ���ֵƥ���Ĺ���ģʽ:���������������ж�
}T16Nx_TYPE_MATCON;



/* �ж����� */
typedef enum
{
	T16Nx_IT_MAT0 = 0x01 ,   //ƥ��0�ж�
	T16Nx_IT_MAT1 = 0x02 ,   //ƥ��1�ж�
	T16Nx_IT_MAT2 = 0x04 ,   //ƥ��2�ж�
	T16Nx_IT_MAT3 = 0x08 ,   //ƥ��3�ж�
	T16Nx_IT_TOP0 = 0x10 ,   //T16N_CNT0ƥ���������ֵ�ж�
	T16Nx_IT_TOP1 = 0x20 ,	 //T16N_CNT1ƥ���������ֵ�ж�
	T16Nx_IT_CAP0 = 0x40 ,	 //����˿�T16NxIN0���벶׽�ж�
	T16Nx_IT_CAP1 = 0x80 ,	 //����˿�T16NxIN1���벶׽�ж�
	T16Nx_IT_PBK0 = 0x100 ,  //PWMͨ��0ɲ���ж�
	T16Nx_IT_PBK1 = 0x200 ,  //PWMͨ��1ɲ���ж�
}T16Nx_TYPE_IT;


/* PWM����������� */
typedef enum
{
	POSITIVE = 0X00,   //������
	NEGATIVE = 0X01,   //������
}T16Nx_PWMOUT_POLAR_Type;  

/* PWM����ģʽѡ�� */
typedef enum
{
	T16Nx_PWMMode_INDEP= 0x0 ,   //����ģʽ
	T16Nx_PWMMode_SYNC = 0x2 ,   //ͬ��ģʽ
	T16Nx_PWMMode_COMPLE = 0x3 , //����ģʽ
}T16Nx_PWMTYPE_MODE;


/* ���ƹ��ܳ�ʼ���ṹ�嶨�� */
typedef struct
{
	TYPE_FUNCEN  T16Nx_MOE0;   //����˿�0ʹ��

	TYPE_FUNCEN  T16Nx_MOE1;   //����˿�1ʹ��

	T16Nx_PWMOUT_POLAR_Type  T16Nx_POL0;    //T16NxOUT0�������ѡ��λ

	T16Nx_PWMOUT_POLAR_Type  T16Nx_POL1;    //T16NxOUT1�������ѡ��λ 

	T16Nx_PWMTYPE_MODE T16Nx_PWMMODE; //T16PWM���ģʽѡ��

	TYPE_FUNCEN PWMDZE; //PWM����ģʽ����ʹ��

}T16Nx_PWMInitStruType;


/* ƥ��Ĵ���ֵƥ�������˿ڵĹ���ģʽ */
typedef enum
{
	T16Nx_Out_Hold = 0x0 ,   //ƥ��Ĵ���ֵƥ�������˿ڵĹ���ģʽ������
	T16Nx_Out_Low = 0x1 ,    //ƥ��Ĵ���ֵƥ�������˿ڵĹ���ģʽ����0
	T16Nx_Out_High = 0x2 ,   //ƥ��Ĵ���ֵƥ�������˿ڵĹ���ģʽ����1
	T16Nx_Out_Switch = 0x3 , //ƥ��Ĵ���ֵƥ�������˿ڵĹ���ģʽ��ȡ��
}T16Nx_TYPE_MATOUT;

/* PWMɲ�������ƽ */
typedef enum
{
	PWMBKOUT_Low = 0,
	PWMBKOUT_High = 1,
}T16Nx_PWMBKOUT_LEVEl; 


/* PWMɲ���źż���ѡ�� */
typedef enum
{
	PWMBKP_High = 0,
	PWMBKP_Low = 1,		
}T16Nx_PWMBKP_LEVEl;



/*PWM���ɲ������*/
typedef struct
{
	TYPE_FUNCEN T16Nx_PWMBK_EN0;                 //PWMͨ��0ɲ��ʹ��
	TYPE_FUNCEN T16Nx_PWMBK_EN1;                 //PWMͨ��0ɲ��ʹ��
	T16Nx_PWMBKOUT_LEVEl T16Nx_PWMBK_L0;         //PWMͨ��0ɲ�������ƽѡ��
	T16Nx_PWMBKOUT_LEVEl T16Nx_PWMBK_L1;				//PWMͨ��1ɲ�������ƽѡ��
	T16Nx_PWMBKP_LEVEl T16Nx_PWMBK_P0;            //PWMͨ��0ɲ���źż���ѡ��
	T16Nx_PWMBKP_LEVEl T16Nx_PWMBK_P1;            //PWMͨ��1ɲ���źż���ѡ��
}T16Nx_PWMBK_Type;



/*PWM����ģʽADC����ʹ�ܿ���*/

typedef enum
{
	T16Nx_P0MAT0 = 0x02,         //PWMͨ��0ƥ��0����ʹ��
	T16Nx_P0MAT1 = 0x04,         //PWMͨ��0ƥ��1����ʹ��
	T16Nx_P0TOP0 = 0x08,         //PWMͨ��0��ֵ0����ʹ��
	T16Nx_P1MAT2 = 0x20,         //PWMͨ��1ƥ��2����ʹ��
	T16Nx_P1MAT3 = 0x40,         //PWMͨ��1ƥ��3����ʹ��
	T16Nx_P1TOP1 = 0x80,         //PWMͨ��1��ֵ1����ʹ��
}T16Nx_PWMTRE_type;




/****************************************32Ϊʱ�����ݽṹ����*********************************/


/* ʱ��Դѡ�� */
typedef enum
{

	T32Nx_ClkS_PCLK = 0x0 , //ʱ��Դѡ��:�ڲ�PCLK
	T32Nx_ClkS_CK0 = 0x1 ,  //ʱ��Դѡ��:�ⲿCK0ʱ������
	T32Nx_ClkS_CK1 = 0x2 ,  //ʱ��Դѡ��:�ⲿCK1ʱ������
}T32Nx_TYPE_CLKS;

/* �ⲿʱ�Ӽ�������ѡ�� */
typedef enum
{
	T32Nx_EDGE_Rise = 0x0 , //�ⲿʱ�Ӽ�������ѡ��:������
	T32Nx_EDGE_Fall = 0x1 , //�ⲿʱ�Ӽ�������ѡ��:�½���
	T32Nx_EDGE_All = 0x2 ,  //�ⲿʱ�Ӽ�������ѡ��:����
}T32Nx_TYPE_EDGE;


/* ����ģʽѡ�� */
typedef enum
{
	T32Nx_Mode_TC0 = 0x0 , //����ģʽ:��ʱ������ģʽ
	T32Nx_Mode_TC1 = 0x1 , //����ģʽ:��ʱ������ģʽ
	T32Nx_Mode_CAP = 0x2 , //����ģʽ:��׽ģʽ
	T32Nx_Mode_PWM = 0x3 , //����ģʽ:����ģʽ
}T32Nx_TYPE_MODE;

/* T32Nx��ʼ�����ýṹ�嶨�� */
typedef struct
{
	T32Nx_TYPE_CLKS   T32Nx_ClkS; //ʱ��Դѡ��

	TYPE_FUNCEN       T32Nx_SYNC;   //�ⲿʱ��ͬ��

	T32Nx_TYPE_EDGE   T32Nx_EDGE; //�ⲿʱ�Ӽ�������ѡ��

	T32Nx_TYPE_MODE   T32Nx_Mode; //����ģʽѡ��

	unsigned int      T32Nx_PREMAT;  //����Ԥ��Ƶ�ȣ���Χ ��1-256


}T32Nx_BaseInitStruType;



/* ��׽�������� */
typedef enum
{
	T32Nx_CapTime_1 = 0x0 , //��׽��������:1
	T32Nx_CapTime_2 = 0x1 , //��׽��������:2
	T32Nx_CapTime_3 = 0x2 , //��׽��������:3
	T32Nx_CapTime_4 = 0x3 , //��׽��������:4
	T32Nx_CapTime_5 = 0x4 , //��׽��������:5
	T32Nx_CapTime_6 = 0x5 , //��׽��������:6
	T32Nx_CapTime_7 = 0x6 , //��׽��������:7
	T32Nx_CapTime_8 = 0x7 , //��׽��������:8
	T32Nx_CapTime_9 = 0x8 , //��׽��������:9
	T32Nx_CapTime_10 = 0x9 , //��׽��������:10
	T32Nx_CapTime_11 = 0xA , //��׽��������:11
	T32Nx_CapTime_12 = 0xB , //��׽��������:12
	T32Nx_CapTime_13 = 0xC , //��׽��������:13
	T32Nx_CapTime_14 = 0xD , //��׽��������:14
	T32Nx_CapTime_15 = 0xE , //��׽��������:15
	T32Nx_CapTime_16 = 0xF , //��׽��������:16
} T32Nx_TYPE_CAPT;

/* ��׽���ܳ�ʼ���ṹ�嶨�� */
typedef struct
{
	TYPE_FUNCEN  T32Nx_CAPCAPL1;   //��׽1���ؼ�����ʹ��

	TYPE_FUNCEN  T32Nx_CAPCAPL0;   //��׽0���ؼ�����ʹ��

	TYPE_FUNCEN  T32Nx_CapRise;    //�����ز�׽ʹ��

	TYPE_FUNCEN  T32Nx_CapFall;    //�½��ز�׽ʹ��

	TYPE_FUNCEN  T32Nx_CapIS0;     //����˿�0ʹ��

	TYPE_FUNCEN  T32Nx_CapIS1;     //����˿�1ʹ��

	T32Nx_TYPE_CAPT  T32Nx_CapTime;  //��׽��������

}T32Nx_CapInitStruType;

/* ���ƹ��ܳ�ʼ���ṹ�嶨�� */
typedef struct
{
	TYPE_FUNCEN  T32Nx_MOE0;   //����˿�0ʹ��

	TYPE_FUNCEN  T32Nx_MOE1;   //����˿�1ʹ��

}T32Nx_PWMInitStruType;

/* ƥ��Ĵ���ֵƥ���Ĺ���ģʽ */
typedef enum
{
	T32Nx_Go_No = 0x0 ,    //ƥ��Ĵ���ֵƥ���Ĺ���ģʽ:�����������������ж�
	T32Nx_Hold_Int = 0x1 , //ƥ��Ĵ���ֵƥ���Ĺ���ģʽ:���ּ����������ж�
	T32Nx_Clr_Int = 0x2 ,  //ƥ��Ĵ���ֵƥ���Ĺ���ģʽ:���㲢���¼����������ж�
	T32Nx_Go_Int = 0x3 ,   //ƥ��Ĵ���ֵƥ���Ĺ���ģʽ:���������������ж�
}T32Nx_TYPE_MATCON;

/* ƥ��Ĵ���ֵƥ�������˿ڵĹ���ģʽ */
typedef enum
{
	T32Nx_Out_Hold = 0x0 ,   //ƥ��Ĵ���ֵƥ�������˿ڵĹ���ģʽ������
	T32Nx_Out_Low = 0x1 ,    //ƥ��Ĵ���ֵƥ�������˿ڵĹ���ģʽ����0
	T32Nx_Out_High = 0x2 ,   //ƥ��Ĵ���ֵƥ�������˿ڵĹ���ģʽ����1
	T32Nx_Out_Switch = 0x3 , //ƥ��Ĵ���ֵƥ�������˿ڵĹ���ģʽ��ȡ��
}T32Nx_TYPE_MATOUT;


/* �ж����� */
typedef enum
{
	T32Nx_IT_MAT0 = 0x01 ,   //ƥ��0�ж�
	T32Nx_IT_MAT1 = 0x02 ,   //ƥ��1�ж�
	T32Nx_IT_MAT2 = 0x04 ,   //ƥ��2�ж�
	T32Nx_IT_MAT3 = 0x08 ,   //ƥ��3�ж�
	T32Nx_IT_IT   = 0x10 ,    //T32Nƥ��0xFFFFFFFF�ж�ʹ��λ
	T32Nx_IT_CAP0 = 0x20 ,	 //T32N_CNT0ƥ���������ֵ�ж�
	T32Nx_IT_CAP1 = 0x40 ,	 //T32N_CNT0ƥ���������ֵ�ж�
}T32Nx_TYPE_IT;


/*********************T16Nxģ�麯������ *********************/
void T16Nx_BaseInit(T16N_TypeDef* T16Nx,T16Nx_BaseInitStruType* T16Nx_BaseInitStruct);
void T16Nx_CapInit(T16N_TypeDef* T16Nx,T16Nx_CapInitStruType* T16Nx_CapInitStruct);
void T16Nx_PMWOutInit(T16N_TypeDef* T16Nx,T16Nx_PWMInitStruType* T16Nx_PWMInitStruct);
void T16Nx_PWMPDZ_Config(T16N_TypeDef* T16Nx,unsigned int PWM_PDZ_data);
void T16Nx_MAT0ITConfig(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATCON Type);
void T16Nx_MAT1ITConfig(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATCON Type);
void T16Nx_MAT2ITConfig(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATCON Type);
void T16Nx_MAT3ITConfig(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATCON Type);
void T16Nx_MAT0Out0Config(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATOUT Type);
void T16Nx_MAT1Out0Config(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATOUT Type);
void T16Nx_MAT2Out1Config(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATOUT Type);
void T16Nx_MAT3Out1Config(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATOUT Type);
void T16Nx_ITConfig(T16N_TypeDef* T16Nx,T16Nx_TYPE_IT Type,TYPE_FUNCEN NewState);
void T16Nx_SetCNT0(T16N_TypeDef* T16Nx,uint16_t Value);
void T16Nx_SetCNT1(T16N_TypeDef* T16Nx,uint16_t Value);
void T16Nx_SetPREMAT(T16N_TypeDef* T16Nx,uint8_t Value);
void T16Nx_SetPRECNT(T16N_TypeDef* T16Nx,uint8_t Value);
void T16Nx_SetMAT0(T16N_TypeDef* T16Nx,uint16_t Value);
void T16Nx_SetMAT1(T16N_TypeDef* T16Nx,uint16_t Value);
void T16Nx_SetMAT2(T16N_TypeDef* T16Nx,uint16_t Value);
void T16Nx_SetMAT3(T16N_TypeDef* T16Nx,uint16_t Value);
void T16Nx_SetTOP0(T16N_TypeDef* T16Nx,uint16_t Value);
void T16Nx_SetTOP1(T16N_TypeDef* T16Nx,uint16_t Value);
uint16_t T16Nx_GetMAT0(T16N_TypeDef* T16Nx);
uint16_t T16Nx_GetMAT1(T16N_TypeDef* T16Nx);
uint16_t T16Nx_GetMAT2(T16N_TypeDef* T16Nx);
uint16_t T16Nx_GetMAT3(T16N_TypeDef* T16Nx);
uint16_t T16Nx_GetTOP0(T16N_TypeDef* T16Nx);
uint16_t T16Nx_GetTOP1(T16N_TypeDef* T16Nx);
uint16_t T16Nx_GetCNT0(T16N_TypeDef* T16Nx);
uint16_t T16Nx_GetCNT1(T16N_TypeDef* T16Nx);
FlagStatus T16Nx_GetFlagStatus(T16N_TypeDef* T16Nx,T16Nx_TYPE_IT T16Nx_Flag);
void T16Nx_ClearITPendingBit(T16N_TypeDef* T16Nx,T16Nx_TYPE_IT TIM_Flag);
void T16Nx_Enable(T16N_TypeDef* T16Nx);
void T16Nx_Disable(T16N_TypeDef* T16Nx);
void T16Nx_PWMBK_Config(T16N_TypeDef* T16Nx,T16Nx_PWMBK_Type* type);
FlagStatus T16Nx_GetPWMBKF(T16N_TypeDef* T16Nx);
void T16Nx_ResetPWMBKF(T16N_TypeDef* T16Nx);
void T16Nx_PTR_Config(T16N_TypeDef* T16Nx,T16Nx_PWMTRE_type Type,TYPE_FUNCEN NewState );

/***************************32λ��ʱ����������********************************/

void T32Nx_BaseInit(T32N_TypeDef* T32Nx,T32Nx_BaseInitStruType* T32Nx_BaseInitStruct);
void T32Nx_CapInit(T32N_TypeDef* T32Nx,T32Nx_CapInitStruType* T32Nx_CapInitStruct);
void T32Nx_PMWOutInit(T32N_TypeDef* T32Nx,T32Nx_PWMInitStruType* T32Nx_PWMInitStruct);
void T32Nx_MAT0ITConfig(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATCON Type);
void T32Nx_MAT1ITConfig(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATCON Type);
void T32Nx_MAT2ITConfig(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATCON Type);
void T32Nx_MAT3ITConfig(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATCON Type);
void T32Nx_MAT0Out0Config(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATOUT Type);
void T32Nx_MAT1Out0Config(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATOUT Type);
void T32Nx_MAT2Out1Config(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATOUT Type);
void T32Nx_MAT3Out1Config(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATOUT Type);
void T32Nx_ITConfig(T32N_TypeDef* T32Nx,T32Nx_TYPE_IT Type,TYPE_FUNCEN NewState);
void T32Nx_SetCNT(T32N_TypeDef* T32Nx,uint32_t Value);
void T32Nx_SetPREMAT(T32N_TypeDef* T32Nx,uint8_t Value);
void T32Nx_SetPRECNT(T32N_TypeDef* T32Nx,uint8_t Value);
void T32Nx_SetMAT0(T32N_TypeDef* T32Nx,uint32_t Value);
void T32Nx_SetMAT1(T32N_TypeDef* T32Nx,uint32_t Value);
void T32Nx_SetMAT2(T32N_TypeDef* T32Nx,uint32_t Value);
void T32Nx_SetMAT3(T32N_TypeDef* T32Nx,uint32_t Value);
uint32_t T32Nx_GetMAT0(T32N_TypeDef* T32Nx);
uint32_t T32Nx_GetMAT1(T32N_TypeDef* T32Nx);
uint32_t T32Nx_GetMAT2(T32N_TypeDef* T32Nx);
uint32_t T32Nx_GetMAT3(T32N_TypeDef* T32Nx);
uint32_t T32Nx_GetCNT(T32N_TypeDef* T32Nx);
FlagStatus T32Nx_GetFlagStatus(T32N_TypeDef* T32Nx,T32Nx_TYPE_IT T32Nx_Flag);
void T32Nx_ClearITPendingBit(T32N_TypeDef* T32Nx,T32Nx_TYPE_IT TIM_Flag);
void T32Nx_Enable(T32N_TypeDef* T32Nx);
void T32Nx_Disable(T32N_TypeDef* T32Nx);
void BUZC_Frequence(uint32_t Frequence,TYPE_FUNCEN sys_buz);

#endif
