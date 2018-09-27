/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_timer.c
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  Timerģ��⺯��
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#include "lib_timer.h"


/***************************************************************
  ��������T16Nx_BaseInit
  ��  ����T16Nx������ʼ��,��ʼ��ʱ��ѡ���ⲿʱ��ͬ�����ⲿʱ�Ӽ�����Եѡ�񣬹���ģʽ��
  ����ֵ��T16Nx��������T16N0/1/2/3 ��T16Nx_BaseInitStruct����ʼ�����ýṹ���ַ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_BaseInit(T16N_TypeDef* T16Nx,T16Nx_BaseInitStruType* T16Nx_BaseInitStruct)
{
	T16Nx->CON0.CS = T16Nx_BaseInitStruct->T16Nx_ClkS;     //����ʱ��Դѡ��
	T16Nx->CON0.SYNC = T16Nx_BaseInitStruct->T16Nx_SYNC;   //�ⲿʱ��ͬ��ʹ��  Disable:��ͬ���ⲿʱ�ӣ�Ϊ�첽����ģʽ��Enable��ͨ��PCLK���ⲿʱ��ͬ����Ϊͬ������ģʽ���ⲿʱ�ӵĸߵ͵�ƽƽ�����ٱ���2��ʱ������
	T16Nx->CON0.EDGE = T16Nx_BaseInitStruct->T16Nx_EDGE;   //�ⲿʱ�Ӽ�������ѡ��
	T16Nx->CON0.MOD = T16Nx_BaseInitStruct->T16Nx_Mode;    //����ģʽѡ��
	T16Nx->PREMAT.PREMAT = T16Nx_BaseInitStruct->T16Nx_PREMAT-1;  //Ԥ��Ƶ�����ã���Χ��1-256
}


/***************************************************************
  ��������T16Nx_CapInit
  ��  ����T16Nx��׽��ʼ��
  ����ֵ����T16Nx��������T16N0/1/2/3�� T16Nx_CapInitStruct����ʼ�����ýṹ���ַ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_CapInit(T16N_TypeDef* T16Nx,T16Nx_CapInitStruType* T16Nx_CapInitStruct)
{

	T16Nx->CON1.CAPL0=T16Nx_CapInitStruct->T16Nx_CAPCAPL0;   //���ò�׽0���ؼ������Ƿ�ʹ��
	T16Nx->CON1.CAPL1=T16Nx_CapInitStruct->T16Nx_CAPCAPL1;   //���ò�׽1���ؼ������Ƿ�ʹ�� 
	T16Nx->CON1.CAPPE=T16Nx_CapInitStruct->T16Nx_CapRise;    //�������������벶׽�Ƿ�ʹ��
	T16Nx->CON1.CAPNE=T16Nx_CapInitStruct->T16Nx_CapFall;    //�����½������벶׽�Ƿ�ʹ��
	T16Nx->CON1.CAPIS0=T16Nx_CapInitStruct->T16Nx_CapIS0;    //���ò�׽����˿�T16NxIN0�Ƿ�ʹ��
	T16Nx->CON1.CAPIS1=T16Nx_CapInitStruct->T16Nx_CapIS1;    //���ò�׽����˿�T16NxIN1�Ƿ�ʹ��
	T16Nx->CON1.CAPT=T16Nx_CapInitStruct->T16Nx_CapTime;     //���ò�׽����

}

/***************************************************************
  ��������T16Nx_PMWOutInit
  ��  ����T16NxPWM�����ʼ��
  ����ֵ����T16Nx��������T16N0/1/2/3�� T16Nx_PWMInitStruct����ʼ�����ýṹ���ַ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_PMWOutInit(T16N_TypeDef* T16Nx,T16Nx_PWMInitStruType* T16Nx_PWMInitStruct)
{
	T16Nx->CON2.MOE0 = T16Nx_PWMInitStruct->T16Nx_MOE0;   				//��������˿�0�Ƿ�ʹ��
	T16Nx->CON2.MOE1 = T16Nx_PWMInitStruct->T16Nx_MOE1;           //��������˿�1�Ƿ�ʹ��
	T16Nx->CON2.POL0 = T16Nx_PWMInitStruct->T16Nx_POL0;           //����T16NxOut0�������
	T16Nx->CON2.POL1 = T16Nx_PWMInitStruct->T16Nx_POL1;           //����T16NxOut1�������
	T16Nx->CON2.PWMMOD = T16Nx_PWMInitStruct->T16Nx_PWMMODE;      //����PWMģʽѡ��
	T16Nx->CON2.PWMDZE = T16Nx_PWMInitStruct->PWMDZE;             //����PWM����ģʽ�����Ƿ�ʹ��
}

/***************************************************************
  ��������T16Nx_PMWPDZ_Config
  ��  ����T16NxPWM����ģʽ�����������
  ����ֵ����T16Nx��������T16N0/1/2/3�� PWM_PDZ_data��������������1-256
  ���ֵ����
  ����ֵ����
 ***************************************************************/

void T16Nx_PWMPDZ_Config(T16N_TypeDef* T16Nx,unsigned int PWM_PDZ_data)
{
	T16Nx->PDZ.PDZ = PWM_PDZ_data-1;
}

/***************************************************************
  ��������T16Nx_MATxITConfig
  ��  ����T16Nxƥ���Ĺ���ģʽ����
  ����ֵ��T16Nx��������T16N0/1/2/3�� Type��ƥ���Ĺ���ģʽ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_MAT0ITConfig(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATCON Type)
{  
	T16Nx->CON0.MAT0S=Type;
}
void T16Nx_MAT1ITConfig(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATCON Type)
{
	T16Nx->CON0.MAT1S=Type;
}
void T16Nx_MAT2ITConfig(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATCON Type)
{
	T16Nx->CON0.MAT2S=Type;
}
void T16Nx_MAT3ITConfig(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATCON Type)
{
	T16Nx->CON0.MAT3S=Type;
}


/***************************************************************
  ��������T16Nx_MATxOutxConfig
  ��  ����T16Nxƥ��������˿ڵ�ģʽ����
  ����ֵ��T16Nx��������T16N0/1/2/3 �� Type��ƥ���˿ڵĹ���ģʽ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_MAT0Out0Config(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATOUT Type)
{
	T16Nx->CON2.MOM0=Type;
}
void T16Nx_MAT1Out0Config(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATOUT Type)
{
	T16Nx->CON2.MOM1=Type;
}
void T16Nx_MAT2Out1Config(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATOUT Type)
{
	T16Nx->CON2.MOM2=Type;
}
void T16Nx_MAT3Out1Config(T16N_TypeDef* T16Nx,T16Nx_TYPE_MATOUT Type)
{
	T16Nx->CON2.MOM3=Type;
}


/***************************************************************
  ��������T16Nx_ITConfig
  ��  ����T16N�ж�����
  ����ֵ��T16Nx��������T16N0/1/2/3�� Type���ж����� �� NewState��ʹ��/ʧ��
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_ITConfig(T16N_TypeDef* T16Nx,T16Nx_TYPE_IT Type,TYPE_FUNCEN NewState)
{
	if (NewState != DISABLE)
	{
		T16Nx->IE.Word |= (uint32_t)Type;
	}
	else
	{
		T16Nx->IE.Word &= (~(uint32_t)Type);
	}
}


/***************************************************************
  ��������T16Nx_SetCNT0
  ��  ��������CNT0����ֵ
  ����ֵ��T16Nx��������T16N0/1/2/3�� Value��16λ��ֵ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_SetCNT0(T16N_TypeDef* T16Nx,uint16_t Value)
{
	T16Nx->CON0.ASYWEN = Disable;
	T16Nx->CNT0.CNT0 = Value;
	T16Nx->CON0.ASYWEN = Enable;
} 

/***************************************************************
  ��������T16Nx_SetCNT1
  ��  ��������CNT1����ֵ
  ����ֵ��T16Nx��������T16N0/1/2/3�� Value��16λ��ֵ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_SetCNT1(T16N_TypeDef* T16Nx,uint16_t Value)
{
	T16Nx->CON0.ASYWEN = Disable;
	T16Nx->CNT1.CNT1 = Value;
	T16Nx->CON0.ASYWEN = Enable;
} 



/***************************************************************
  ��������T16Nx_SetPREMAT
  ��  ��������Ԥ��Ƶ��
  ����ֵ��T16Nx��������T16N0/1/2/3�� Value��1-256
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_SetPREMAT(T16N_TypeDef* T16Nx,uint8_t Value)
{
	T16Nx->PREMAT.PREMAT = Value-1;	 
}

/***************************************************************
  ��������T16Nx_SetPRECNT
  ��  ��������Ԥ��Ƶ������
  ����ֵ��T16Nx��������T16N0/1/2/3�� Value��1-256
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_SetPRECNT(T16N_TypeDef* T16Nx,uint8_t Value)
{
	T16Nx->CON0.ASYWEN = Disable;
	T16Nx->PRECNT.PRECNT = Value;	
	T16Nx->CON0.ASYWEN = Enable;
}


/***************************************************************
  ��������T16Nx_SetMATx
  ��  ��������ƥ��Ĵ���
  ����ֵ��T16Nx��������T16N0/1/2/3�� MATx��������TIM_MAT0/1/2/3 �� Value��16λ��ֵ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_SetMAT0(T16N_TypeDef* T16Nx,uint16_t Value)
{

	T16Nx->MAT0.MAT0=Value;
}

void T16Nx_SetMAT1(T16N_TypeDef* T16Nx,uint16_t Value)
{

	T16Nx->MAT1.MAT1=Value;
}
void T16Nx_SetMAT2(T16N_TypeDef* T16Nx,uint16_t Value)
{

	T16Nx->MAT2.MAT2=Value;
}
void T16Nx_SetMAT3(T16N_TypeDef* T16Nx,uint16_t Value)
{

	T16Nx->MAT3.MAT3=Value;
}

/***************************************************************
  ��������T16Nx_SetMATx
  ��  ��������ƥ��Ĵ���
  ����ֵ��T16Nx��������T16N0/1/2/3�� MATx��������TOP0/1 �� Value��16λ��ֵ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_SetTOP0(T16N_TypeDef* T16Nx,uint16_t Value)
{

	T16Nx->TOP0.TOP0=Value;
}

void T16Nx_SetTOP1(T16N_TypeDef* T16Nx,uint16_t Value)
{

	T16Nx->TOP1.TOP1=Value;
}


/***************************************************************
  ��������T16Nx_GetMATx
  ��  ������ȡƥ��Ĵ���ֵ
  ����ֵ��T16Nx��������T16N0/1/2/3 MATx��������TIM_MAT0/1/2/3
  ���ֵ����
  ����ֵ��16λ��ֵ
 ***************************************************************/
uint16_t T16Nx_GetMAT0(T16N_TypeDef* T16Nx)
{
	return (T16Nx->MAT0.MAT0) ;

}

uint16_t T16Nx_GetMAT1(T16N_TypeDef* T16Nx)
{
	return (T16Nx->MAT1.MAT1) ;

}
uint16_t T16Nx_GetMAT2(T16N_TypeDef* T16Nx)
{
	return (T16Nx->MAT2.MAT2) ;

}
uint16_t T16Nx_GetMAT3(T16N_TypeDef* T16Nx)
{
	return (T16Nx->MAT3.MAT3) ;

}


/***************************************************************
  ��������T16Nx_GetTOPx
  ��  ������ȡƥ��Ĵ���ֵ
  ����ֵ��T16Nx��������T16N0/1/2/3 MATx��������TIM_TOP0/1
  ���ֵ����
  ����ֵ��16λ��ֵ
 ***************************************************************/
uint16_t T16Nx_GetTOP0(T16N_TypeDef* T16Nx)
{
	return (T16Nx->TOP0.TOP0) ;

}

uint16_t T16Nx_GetTOP1(T16N_TypeDef* T16Nx)
{
	return (T16Nx->TOP1.TOP1) ;

}

/***************************************************************
  ��������T16Nx_GetCNTx
  ��  ������ȡ�����Ĵ���ֵ
  ����ֵ��T16Nx��������T16N0/1/2/3��
  ����ֵ��16λ��ֵ
 ***************************************************************/
uint16_t T16Nx_GetCNT0(T16N_TypeDef* T16Nx)
{
	return (T16Nx->CNT0.CNT0) ;
}

uint16_t T16Nx_GetCNT1(T16N_TypeDef* T16Nx)
{
	return (T16Nx->CNT1.CNT1) ;
}



/***************************************************************
  ��������T16Nx_GetFlagStatus
  ��  ������ȡָ����־λ
  ����ֵ��T16Nx��������T16N0/1/2/3�� T16Nx_Flag���жϱ�־λ
  ���ֵ����
  ����ֵ��RESET/SET
 ***************************************************************/
FlagStatus T16Nx_GetFlagStatus(T16N_TypeDef* T16Nx,T16Nx_TYPE_IT T16Nx_Flag)
{
	FlagStatus bitstatus = RESET;

	if((T16Nx->IF.Word  & (uint32_t)T16Nx_Flag) != (uint32_t)RESET)
	{
		bitstatus = SET;
	}
	else   
	{
		bitstatus = RESET;
	}
	return  bitstatus;
}


/***************************************************************
  ��������T16Nx_ClearITPendingBit
  ��  �������ָ�����жϱ�־λ
  ����ֵ��T16Nx��������T16N0/1/2/3�� T16Nx_Flag���жϱ�־λ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_ClearITPendingBit(T16N_TypeDef* T16Nx,T16Nx_TYPE_IT T16Nx_Flag)
{
	T16Nx->IF.Word = (uint32_t)T16Nx_Flag;
}  


/***************************************************************
  ��������T16Nx_Enable
  ��  ����ʹ��T16Nx
  ����ֵ��T16Nx��������T16N0/1/2/3
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_Enable(T16N_TypeDef* T16Nx)
{
	T16Nx->CON0.EN = 1;
}  

/***************************************************************
  ��������T16Nx_Enable
  ��  ������ֹT16Nx
  ����ֵ��T16Nx��������T16N0/1/2/3
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_Disable(T16N_TypeDef* T16Nx)
{
	T16Nx->CON0.EN = 0;
}  


/***************************************************************
  ��������T16Nx_PWMBK_Config
  ��  ��������PWMɲ������
  ����ֵ��T16Nx��������T16N0/1/2/3 ,Type ����PWMɲ���ṹ��
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T16Nx_PWMBK_Config(T16N_TypeDef* T16Nx,T16Nx_PWMBK_Type* type)
{

	T16Nx->CON2.PWMBKL0 = type->T16Nx_PWMBK_L0;    //PWMͨ��0ɲ�������ƽѡ��
	T16Nx->CON2.PWMBKL1 = type->T16Nx_PWMBK_L1;    //PWMͨ��1ɲ�������ƽѡ��
	T16Nx->CON2.PWMBKP0 = type->T16Nx_PWMBK_P0;    //PWMͨ��0ɲ���źż���ѡ��
	T16Nx->CON2.PWMBKP1 = type->T16Nx_PWMBK_P1;    //PWMͨ��1ɲ���źż���ѡ��
	T16Nx->CON2.PWMBKE0 = type->T16Nx_PWMBK_EN0;   //PWMͨ��0ɲ��ʹ��
	T16Nx->CON2.PWMBKE1 = type->T16Nx_PWMBK_EN1;   //PWMͨ��1ɲ��ʹ��
}  
/***************************************************************
  ��������T16Nx_GetPWMBKF
  ��  ������ȡPWMBKFɲ����־λ
  ����ֵ��T16Nx��������T16N0/1/2/3 
  ���ֵ��PWMBKF��־λ��ֵ��SET������ɲ���¼���RESET��δ����ɲ���¼�
  ����ֵ����
 ***************************************************************/

FlagStatus T16Nx_GetPWMBKF(T16N_TypeDef* T16Nx)
{
	if(T16Nx->CON2.PWMBKF == 1)
		return SET;
	else
		return RESET;
}
/***************************************************************
  ��������T16Nx_ResetPWMBKF
  ��  ��: ���PWMBKF��־����־�����PWM�˿ڻָ�����shuc
  ����ֵ��T16Nx��������T16N0/1/2/3 
  ���ֵ����
  ����ֵ����
 ***************************************************************/

void T16Nx_ResetPWMBKF(T16N_TypeDef* T16Nx)
{
	T16Nx->CON2.PWMBKF = 1;
}

/***************************************************************
  ��������T16Nx_PTR_Config
  ��  ��: ����PWM����ģʽADC����ʹ��
  ����ֵ��T16Nx��������T16N0/1/2/3 
  ���ֵ����
  ����ֵ����
 ***************************************************************/

void T16Nx_PTR_Config(T16N_TypeDef* T16Nx,T16Nx_PWMTRE_type Type,TYPE_FUNCEN NewState )
{
	if (NewState != DISABLE)
	{
		T16Nx->PTR.Word |= (uint32_t)Type;
	}
	else
	{
		T16Nx->PTR.Word &= (~(uint32_t)Type);
	}
}



/***************************************************************
  ��������T32Nx_BaseInit
  ��  ����T32Nx������ʼ��,��ʼ��ʱ��ѡ���ⲿʱ��ͬ�����ⲿʱ�Ӽ�����Եѡ�񣬹���ģʽ��
  ����ֵ��T32Nx��������T32N0 ��T32Nx_BaseInitStruct����ʼ�����ýṹ���ַ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_BaseInit(T32N_TypeDef* T32Nx,T32Nx_BaseInitStruType* T32Nx_BaseInitStruct)
{

	T32Nx->CON0.CS         = T32Nx_BaseInitStruct->T32Nx_ClkS;     //����ʱ��Դѡ��
	T32Nx->CON0.SYNC       = T32Nx_BaseInitStruct->T32Nx_SYNC;     //�ⲿʱ��ͬ��ʹ��  Disable:��ͬ���ⲿʱ�ӣ�Ϊ�첽����ģʽ��Enable��ͨ��PCLK���ⲿʱ��ͬ����Ϊͬ������ģʽ���ⲿʱ�ӵĸߵ͵�ƽƽ�����ٱ���2��ʱ������
	T32Nx->CON0.EDGE       = T32Nx_BaseInitStruct->T32Nx_EDGE;     //�ⲿʱ�Ӽ�������ѡ��
	T32Nx->CON0.MOD        = T32Nx_BaseInitStruct->T32Nx_Mode;     //����ģʽѡ��
	T32Nx->PREMAT.PREMAT   = T32Nx_BaseInitStruct->T32Nx_PREMAT-1; //Ԥ��Ƶ�����ã���Χ��1-256
}



/***************************************************************
  ��������T32Nx_CapInit
  ��  ����T32Nx��׽��ʼ��
  ����ֵ��T32Nx��������T32N0�� T32Nx_CapInitStruct����ʼ�����ýṹ���ַ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_CapInit(T32N_TypeDef* T32Nx,T32Nx_CapInitStruType* T32Nx_CapInitStruct)
{

	T32Nx->CON1.CAPL0=T32Nx_CapInitStruct->T32Nx_CAPCAPL0;   //���ò�׽0���ؼ������Ƿ�ʹ��
	T32Nx->CON1.CAPL1=T32Nx_CapInitStruct->T32Nx_CAPCAPL1;   //���ò�׽1���ؼ������Ƿ�ʹ�� 
	T32Nx->CON1.CAPPE=T32Nx_CapInitStruct->T32Nx_CapRise;    //�������������벶׽�Ƿ�ʹ��
	T32Nx->CON1.CAPNE=T32Nx_CapInitStruct->T32Nx_CapFall;    //�����½������벶׽�Ƿ�ʹ��
	T32Nx->CON1.CAPIS0=T32Nx_CapInitStruct->T32Nx_CapIS0;    //���ò�׽����˿�T32NxIN0�Ƿ�ʹ��
	T32Nx->CON1.CAPIS1=T32Nx_CapInitStruct->T32Nx_CapIS1;    //���ò�׽����˿�T32NxIN1�Ƿ�ʹ��
	T32Nx->CON1.CAPT=T32Nx_CapInitStruct->T32Nx_CapTime;     //���ò�׽����
}

/***************************************************************
  ��������T32Nx_PMWOutInit
  ��  ����T32NxPWM�����ʼ��
  ����ֵ����T32Nx��������T32N0�� T32Nx_PWMInitStruct����ʼ�����ýṹ���ַ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_PMWOutInit(T32N_TypeDef* T32Nx,T32Nx_PWMInitStruType* T32Nx_PWMInitStruct)
{
	T32Nx->CON1.MOE0 = T32Nx_PWMInitStruct->T32Nx_MOE0;   				//��������˿�0�Ƿ�ʹ��
	T32Nx->CON1.MOE1 = T32Nx_PWMInitStruct->T32Nx_MOE1;           //��������˿�1�Ƿ�ʹ��

}


/***************************************************************
  ��������T32Nx_MATxITConfig
  ��  ����T32Nxƥ���Ĺ���ģʽ����
  ����ֵ��T32Nx��������T32N0�� Type��ƥ���Ĺ���ģʽ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_MAT0ITConfig(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATCON Type)
{  
	T32Nx->CON0.MAT0S=Type;
}
void T32Nx_MAT1ITConfig(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATCON Type)
{
	T32Nx->CON0.MAT1S=Type;
}
void T32Nx_MAT2ITConfig(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATCON Type)
{
	T32Nx->CON0.MAT2S=Type;
}
void T32Nx_MAT3ITConfig(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATCON Type)
{
	T32Nx->CON0.MAT3S=Type;
}


/***************************************************************
  ��������T32Nx_MATxOutxConfig
  ��  ����T32Nxƥ��������˿ڵ�ģʽ����
  ����ֵ��T32Nx��������T32N0/1/2/3 �� Type��ƥ���˿ڵĹ���ģʽ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_MAT0Out0Config(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATOUT Type)
{
	T32Nx->CON1.MOM0=Type;
}
void T32Nx_MAT1Out0Config(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATOUT Type)
{
	T32Nx->CON1.MOM1=Type;
}
void T32Nx_MAT2Out1Config(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATOUT Type)
{
	T32Nx->CON1.MOM2=Type;
}
void T32Nx_MAT3Out1Config(T32N_TypeDef* T32Nx,T32Nx_TYPE_MATOUT Type)
{
	T32Nx->CON1.MOM3=Type;
}


/***************************************************************
  ��������T32Nx_ITConfig
  ��  ����T32N�ж�����
  ����ֵ��T32Nx��������T32N0�� Type���ж����� �� NewState��ʹ��/ʧ��
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_ITConfig(T32N_TypeDef* T32Nx,T32Nx_TYPE_IT Type,TYPE_FUNCEN NewState)
{
	if (NewState != DISABLE)
	{
		T32Nx->IE.Word |= (uint32_t)Type;
	}
	else
	{
		T32Nx->IE.Word &= (~(uint32_t)Type);
	}
}


/***************************************************************
  ��������T32Nx_SetCNT0
  ��  ��������CNT0����ֵ
  ����ֵ��T16Nx��������T32N0/1/2/3�� Value��32λ��ֵ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_SetCNT(T32N_TypeDef* T32Nx,uint32_t Value)
{
	T32Nx->CON0.ASYNC_WREN = Enable;  
	T32Nx->CNT.CNT = Value;
	T32Nx->CON0.ASYNC_WREN = Disable;  
} 


/***************************************************************
  ��������T32Nx_SetPREMAT
  ��  ��������Ԥ��Ƶ��
  ����ֵ��T32Nx��������T32N0�� Value��1-256
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_SetPREMAT(T32N_TypeDef* T32Nx,uint8_t Value)
{
	T32Nx->PREMAT.PREMAT = Value-1;	 
}

/***************************************************************
  ��������T32Nx_SetPRECNT
  ��  ��������Ԥ��Ƶ������
  ����ֵ��T32Nx��������T32N0�� Value��1-256
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_SetPRECNT(T32N_TypeDef* T32Nx,uint8_t Value)
{
	T32Nx->CON0.ASYNC_WREN = Enable; 
	T32Nx->PRECNT.PRECNT = Value;	 
	T32Nx->CON0.ASYNC_WREN = Disable; 
}

/***************************************************************
  ��������T32Nx_SetMATx
  ��  ��������ƥ��Ĵ���
  ����ֵ��T16Nx��������T32N0�� MATx��������TIM_MAT0/1/2/3 �� Value��32λ��ֵ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_SetMAT0(T32N_TypeDef* T32Nx,uint32_t Value)
{

	T32Nx->MAT0.MAT0=Value;
}

void T32Nx_SetMAT1(T32N_TypeDef* T32Nx,uint32_t Value)
{

	T32Nx->MAT1.MAT1=Value;
}
void T32Nx_SetMAT2(T32N_TypeDef* T32Nx,uint32_t Value)
{

	T32Nx->MAT2.MAT2=Value;
}
void T32Nx_SetMAT3(T32N_TypeDef* T32Nx,uint32_t Value)
{

	T32Nx->MAT3.MAT3=Value;
}

/***************************************************************
  ��������T32Nx_GetMATx
  ��  ������ȡƥ��Ĵ���ֵ
  ����ֵ��T32Nx��������T32N0 MATx��������T32Nx_MAT0/1/2/3
  ���ֵ����
  ����ֵ��32λ��ֵ
 ***************************************************************/
uint32_t T32Nx_GetMAT0(T32N_TypeDef* T32Nx)
{
	return (T32Nx->MAT0.MAT0) ;

}

uint32_t T32Nx_GetMAT1(T32N_TypeDef* T32Nx)
{
	return (T32Nx->MAT1.MAT1) ;

}
uint32_t T32Nx_GetMAT2(T32N_TypeDef* T32Nx)
{
	return (T32Nx->MAT2.MAT2) ;

}
uint32_t T32Nx_GetMAT3(T32N_TypeDef* T32Nx)
{
	return (T32Nx->MAT3.MAT3) ;

}




/***************************************************************
  ��������T32Nx_GetCNT
  ��  ������ȡ�����Ĵ���ֵ
  ����ֵ��T32Nx��������T32N0/1/2/3��
  ����ֵ��32λ��ֵ
 ***************************************************************/
uint32_t T32Nx_GetCNT(T32N_TypeDef* T32Nx)
{
	return (T32Nx->CNT.CNT) ;
}

/***************************************************************
  ��������T32Nx_GetFlagStatus
  ��  ������ȡָ����־λ
  ����ֵ��T32Nx��������T32N0�� T32Nx_Flag���жϱ�־λ
  ���ֵ����
  ����ֵ��RESET/SET
 ***************************************************************/
FlagStatus T32Nx_GetFlagStatus(T32N_TypeDef* T32Nx,T32Nx_TYPE_IT T32Nx_Flag)
{
	FlagStatus bitstatus = RESET;

	if((T32Nx->IF.Word  & (uint32_t)T32Nx_Flag) != (uint32_t)RESET)
	{
		bitstatus = SET;
	}
	else   
	{
		bitstatus = RESET;
	}
	return  bitstatus;
}


/***************************************************************
  ��������T32Nx_ClearITPendingBit
  ��  �������ָ�����жϱ�־λ
  ����ֵ��T32Nx��������T16N0�� TIM_Flag���жϱ�־λ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_ClearITPendingBit(T32N_TypeDef* T32Nx,T32Nx_TYPE_IT TIM_Flag)
{
	T32Nx->IF.Word = (uint32_t)TIM_Flag;
}  


/***************************************************************
  ��������T32Nx_Enable
  ��  ����ʹ��T32Nx
  ����ֵ��T32Nx��������T32N0
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_Enable(T32N_TypeDef* T32Nx)
{
	T32Nx->CON0.EN = 1;
}  

/***************************************************************
  ��������T32Nx_Enable
  ��  ������ֹT32Nx
  ����ֵ��T32Nx��������T32N0
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void T32Nx_Disable(T32N_TypeDef* T32Nx)
{
	T32Nx->CON0.EN = 0;
}  

/***************************************************************
  ��������BUZC_Frequence
  ��  ����BUZʹ�ܺ�����BUZ�ź�Ƶ��
  ����ֵ��Frequence : BUZ�ź�Ƶ�ʣ�sys_buz ���Ƿ�ʹ��
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void BUZC_Frequence(uint32_t Frequence,TYPE_FUNCEN sys_buz)
{
	 float tmp;
	
	 if(sys_buz == Disable)  //���BUZC����Ϊ��ֹ����ֱ�ӽ�ֹBUZC��������
	 {
		 GPIO->BUZC.BUZEN = 0;
		 return;
	 }
	 
	 tmp = SystemCoreClock /(Frequence * 2) - 1;
	 GPIO->BUZC.BUZ_LOAD = (uint32_t)tmp;
   GPIO->BUZC.BUZEN = 1;	 
}	

