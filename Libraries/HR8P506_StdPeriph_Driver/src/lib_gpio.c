/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_gpio.c
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  GPIOģ��⺯��
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#include <stdint.h>
#include "lib_gpio.h"

/***************************************************************
  ��������GPIO_SetFuncxRegFromPin
  ��  ��������GPIO���ŵĹ��ܸ���
  ����ֵ��Pin��Ŀ������
  Func�����ܸ��ñ��
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_SetFuncxRegFromPin(GPIO_Pin Pin, GPIO_Reuse_Func Func)
{
	uint32_t value;

	switch (Func) {
		case GPIO_Reuse_Func0:
			value = 0;
			break;
		case GPIO_Reuse_Func1:
			value = 1;
			break;
		case GPIO_Reuse_Func2:
			value = 2;
			break;
		case GPIO_Reuse_Func3:
			value = 3;
			break;
		default:
			value = 0;
			break;
	}

	/* ���Ź������� */
	switch (Pin) {
		case GPIO_Pin_B0:
			GPIO->PBFUNC0.PB0 = value;
			break;
		case GPIO_Pin_B1:
			GPIO->PBFUNC0.PB1 = value;
			break;
		case GPIO_Pin_B2:
			GPIO->PBFUNC0.PB2 = value;
			break;
		case GPIO_Pin_B3:
			GPIO->PBFUNC0.PB3 = value;
			break;
		case GPIO_Pin_B4:
			GPIO->PBFUNC0.PB4 = value;
			break;
		case GPIO_Pin_B5:
			GPIO->PBFUNC0.PB5 = value;
			break;
		case GPIO_Pin_B6:
			GPIO->PBFUNC0.PB6 = value;
			break;
		case GPIO_Pin_B7:
			GPIO->PBFUNC0.PB7 = value;
			break;
		case GPIO_Pin_B8:
			GPIO->PBFUNC1.PB8 = value;
			break;
		case GPIO_Pin_B9:
			GPIO->PBFUNC1.PB9 = value;
			break;
		case GPIO_Pin_B10:
			GPIO->PBFUNC1.PB10 = value;
			break;
		case GPIO_Pin_B11:
			GPIO->PBFUNC1.PB11 = value;
			break;
		case GPIO_Pin_B12:
			GPIO->PBFUNC1.PB12 = value;
			break;
		case GPIO_Pin_B13:
			GPIO->PBFUNC1.PB13 = value;
			break;
		case GPIO_Pin_A0:
			GPIO->PAFUNC0.PA0 = value;
			break;
		case GPIO_Pin_A1:
			GPIO->PAFUNC0.PA1 = value;
			break;
		case GPIO_Pin_A2:
			GPIO->PAFUNC0.PA2 = value;
			break;
		case GPIO_Pin_A3:
			GPIO->PAFUNC0.PA3 = value;
			break;
		case GPIO_Pin_A4:
			GPIO->PAFUNC0.PA4 = value;
			break;
		case GPIO_Pin_A5:
			GPIO->PAFUNC0.PA5 = value;
			break;
		case GPIO_Pin_A6:
			GPIO->PAFUNC0.PA6 = value;
			break;
		case GPIO_Pin_A7:
			GPIO->PAFUNC0.PA7 = value;
			break;
		case GPIO_Pin_A8:
			GPIO->PAFUNC1.PA8 = value;
			break;
		case GPIO_Pin_A9:
			GPIO->PAFUNC1.PA9 = value;
			break;
		case GPIO_Pin_A10:
			GPIO->PAFUNC1.PA10 = value;
			break;
		case GPIO_Pin_A11:
			GPIO->PAFUNC1.PA11 = value;
			break;
		case GPIO_Pin_A12:
			GPIO->PAFUNC1.PA12 = value;
			break;
		case GPIO_Pin_A13:
			GPIO->PAFUNC1.PA13 = value;
			break;
		case GPIO_Pin_A14:
			GPIO->PAFUNC1.PA14 = value;
			break;
		case GPIO_Pin_A15:
			GPIO->PAFUNC1.PA15 = value;
			break;
		case GPIO_Pin_A16:
			GPIO->PAFUNC2.PA16 = value;
			break;
		case GPIO_Pin_A17:
			GPIO->PAFUNC2.PA17 = value;
			break;
		case GPIO_Pin_A18:
			GPIO->PAFUNC2.PA18 = value;
			break;
		case GPIO_Pin_A19:
			GPIO->PAFUNC2.PA19 = value;
			break;
		case GPIO_Pin_A20:
			GPIO->PAFUNC2.PA20 = value;
			break;
		case GPIO_Pin_A21:
			GPIO->PAFUNC2.PA21 = value;
			break;
		case GPIO_Pin_A22:
			GPIO->PAFUNC2.PA22 = value;
			break;
		case GPIO_Pin_A23:
			GPIO->PAFUNC2.PA23 = value;
			break;
		case GPIO_Pin_A24:
			GPIO->PAFUNC3.PA24 = value;
			break;
		case GPIO_Pin_A25:
			GPIO->PAFUNC3.PA25 = value;
			break;
		case GPIO_Pin_A26:
			GPIO->PAFUNC3.PA26 = value;
			break;
		case GPIO_Pin_A27:
			GPIO->PAFUNC3.PA27 = value;
			break;
		case GPIO_Pin_A28:
			GPIO->PAFUNC3.PA28 = value;
			break;
		case GPIO_Pin_A29:
			GPIO->PAFUNC3.PA29 = value;
			break;
		case GPIO_Pin_A30:
			GPIO->PAFUNC3.PA30 = value;
			break;
		case GPIO_Pin_A31:
			GPIO->PAFUNC3.PA31 = value;
			break;
		default:
			break;
	}

	return;
}

/***************************************************************
  ��������GPIO_GetNormalBitOffsetFromPin
  ��  �����������ŵ�λƫ����
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ�����ŵ�λƫ����
 ***************************************************************/
uint8_t GPIO_GetNormalBitOffsetFromPin(GPIO_Pin Pin)
{
	uint8_t result;

	switch (Pin) {
		case GPIO_Pin_B0:
			result = 0;
			break;
		case GPIO_Pin_B1:
			result = 1;
			break;
		case GPIO_Pin_B2:
			result = 2;
			break;
		case GPIO_Pin_B3:
			result = 3;
			break;
		case GPIO_Pin_B4:
			result = 4;
			break;
		case GPIO_Pin_B5:
			result = 5;
			break;
		case GPIO_Pin_B6:
			result = 6;
			break;
		case GPIO_Pin_B7:
			result = 7;
			break;
		case GPIO_Pin_B8:
			result = 8;
			break;
		case GPIO_Pin_B9:
			result = 9;
			break;
		case GPIO_Pin_B10:
			result = 10;
			break;
		case GPIO_Pin_B11:
			result = 11;
			break;
		case GPIO_Pin_B12:
			result = 12;
			break;
		case GPIO_Pin_B13:
			result = 13;
			break;
		case GPIO_Pin_A0:
			result = 0;
			break;
		case GPIO_Pin_A1:
			result = 1;
			break;
		case GPIO_Pin_A2:
			result = 2;
			break;
		case GPIO_Pin_A3:
			result = 3;
			break;
		case GPIO_Pin_A4:
			result = 4;
			break;
		case GPIO_Pin_A5:
			result = 5;
			break;
		case GPIO_Pin_A6:
			result = 6;
			break;
		case GPIO_Pin_A7:
			result = 7;
			break;
		case GPIO_Pin_A8:
			result = 8;
			break;
		case GPIO_Pin_A9:
			result = 9;
			break;
		case GPIO_Pin_A10:
			result = 10;
			break;
		case GPIO_Pin_A11:
			result = 11;
			break;
		case GPIO_Pin_A12:
			result = 12;
			break;
		case GPIO_Pin_A13:
			result = 13;
			break;
		case GPIO_Pin_A14:
			result = 14;
			break;
		case GPIO_Pin_A15:
			result = 15;
			break;
		case GPIO_Pin_A16:
			result = 16;
			break;
		case GPIO_Pin_A17:
			result = 17;
			break;
		case GPIO_Pin_A18:
			result = 18;
			break;
		case GPIO_Pin_A19:
			result = 19;
			break;
		case GPIO_Pin_A20:
			result = 20;
			break;
		case GPIO_Pin_A21:
			result = 21;
			break;
		case GPIO_Pin_A22:
			result = 22;
			break;
		case GPIO_Pin_A23:
			result = 23;
			break;
		case GPIO_Pin_A24:
			result = 24;
			break;
		case GPIO_Pin_A25:
			result = 25;
			break;
		case GPIO_Pin_A26:
			result = 26;
			break;
		case GPIO_Pin_A27:
			result = 27;
			break;
		case GPIO_Pin_A28:
			result = 28;
			break;
		case GPIO_Pin_A29:
			result = 29;
			break;
		case GPIO_Pin_A30:
			result = 30;
			break;
		case GPIO_Pin_A31:
			result = 31;
			break;
		default:
			result = 0;
			break;
	}

	return result;
}

/***************************************************************
  ��������GPIO_SetDirRegFromPin
  ��  �����������ŵ�������������
  ����ֵ��Pin: Ŀ������
  Dir�����ŷ���
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_SetDirRegFromPin(GPIO_Pin Pin, GPIO_Direction Dir)
{
	uint8_t StartBit;

	StartBit = GPIO_GetNormalBitOffsetFromPin(Pin);

	if (Pin <= GPIO_Pin_B13) {
		if (Dir == GPIO_Direction_Input)
			GPIO->PBDIRBSR.Word = (1 << StartBit);
		else
			GPIO->PBDIRBCR.Word = (1 << StartBit);
	} 
	else {
		if (Dir == GPIO_Direction_Input)
			GPIO->PADIRBSR.Word = (1 << StartBit);
		else
			GPIO->PADIRBCR.Word = (1 << StartBit);
	}

	return;
}

/***************************************************************
  ��������GPIO_SetODERegFromPin
  ��  �����������ŵ������©��ʽ
  ����ֵ��Pin: Ŀ������
ODE: �����©��ʽ
���ֵ����
����ֵ����
 ***************************************************************/
void GPIO_SetODERegFromPin(GPIO_Pin Pin, GPIO_ODE_Output ODE)
{
	uint8_t StartBit;

	StartBit = GPIO_GetNormalBitOffsetFromPin(Pin);

	if (Pin <= GPIO_Pin_B13) {
		if (ODE == GPIO_ODE_Output_Disable)
			GPIO->PBODE.Word &= (~(1 << StartBit));
		else
			GPIO->PBODE.Word |= (1 << StartBit);
	} 
	else {
		if (ODE == GPIO_ODE_Output_Disable)
			GPIO->PAODE.Word &= (~(1 << StartBit));
		else
			GPIO->PAODE.Word |= (1 << StartBit);
	}

	return;
}

/***************************************************************
  ��������GPIO_SetDSRegFromPin
  ��  �����������ŵ������������
  ����ֵ��Pin: Ŀ������
DS: ����������ʽ
���ֵ����
����ֵ����
 ***************************************************************/
void GPIO_SetDSRegFromPin(GPIO_Pin Pin, GPIO_DS_Output DS)
{
	uint8_t Start_Bit;

	Start_Bit = GPIO_GetNormalBitOffsetFromPin(Pin);

	if (Pin <= GPIO_Pin_B13) {
		if (DS == GPIO_DS_Output_Normal)
			GPIO->PBDS.Word &= (~(1 << Start_Bit));
		else
			GPIO->PBDS.Word |= (1 << Start_Bit);
	} 
	else {
		if (DS == GPIO_DS_Output_Normal)
			GPIO->PADS.Word &= (~(1 << Start_Bit));
		else
			GPIO->PADS.Word |= (1 << Start_Bit);
	}

	return;
}

/***************************************************************
  ��������GPIO_SetPUERegFromPin
  ��  �����������ŵ���������ʽ
  ����ֵ��Pin: Ŀ������
PUE: ��������ʽ
���ֵ����
����ֵ����
 ***************************************************************/
void GPIO_SetPUERegFromPin(GPIO_Pin Pin, GPIO_PUE_Input PUE)
{
	uint8_t Start_Bit;

	Start_Bit = GPIO_GetNormalBitOffsetFromPin(Pin);

	if (Pin <= GPIO_Pin_B13) {
		if (PUE == GPIO_PUE_Input_Disable)
			GPIO->PBPUE.Word &= (~(1 << Start_Bit));
		else
			GPIO->PBPUE.Word |= (1 << Start_Bit);
	} 
	else {
		if (PUE == GPIO_PUE_Input_Disable)
			GPIO->PAPUE.Word &= (~(1 << Start_Bit));
		else
			GPIO->PAPUE.Word |= (1 << Start_Bit);
	}
}

/***************************************************************
  ��������GPIO_SetPDERegFromPin
  ��  �����������ŵ���������ʽ
  ����ֵ��Pin: Ŀ������
  PDE����������ʽ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_SetPDERegFromPin(GPIO_Pin Pin, GPIO_PDE_Input PDE)
{
	uint8_t Start_Bit;

	Start_Bit = GPIO_GetNormalBitOffsetFromPin(Pin);

	if (Pin <= GPIO_Pin_B13) {
		if (PDE == GPIO_PDE_Input_Disable)
			GPIO->PBPDE.Word &= (~(1 << Start_Bit));
		else
			GPIO->PBPDE.Word |= (1 << Start_Bit);
	} 
	else {
		if (PDE == GPIO_PDE_Input_Disable)
			GPIO->PAPDE.Word &= (~(1 << Start_Bit));
		else
			GPIO->PAPDE.Word |= (1 << Start_Bit);
	}

	return;
}

/***************************************************************
  ��������GPIO_SetSingalTypeFromPin
  ��  �����������ŵ��ź�����
  ����ֵ��Pin: Ŀ������
Signal: ���ŵ��ź�����
���ֵ����
����ֵ����
 ***************************************************************/
void GPIO_SetSingalTypeFromPin(GPIO_Pin Pin, GPIO_Pin_Signal Signal)
{
	uint8_t Start_Bit;

	Start_Bit = GPIO_GetNormalBitOffsetFromPin(Pin);

	if (Pin <= GPIO_Pin_B13) {
		if (Signal == GPIO_Pin_Signal_Digital)
			GPIO->PBINEB.Word &= (~(1 << Start_Bit));
		else
			GPIO->PBINEB.Word |= (1 << Start_Bit);
	} 
	else{
		if (Signal == GPIO_Pin_Signal_Digital)
			GPIO->PAINEB.Word &= (~(1 << Start_Bit));
		else
			GPIO->PAINEB.Word |= (1 << Start_Bit);
	}

	return;
}

/***************************************************************
  ��������GPIO_Init
  ��  �������ŵĳ�ʼ��
  ����ֵ��Pin: Ŀ������
InitSet: ��ʼ�����ݽṹ
���ֵ����
����ֵ����
 ***************************************************************/
void GPIO_Init(GPIO_Pin Pin, GPIO_InitSettingType *InitSet)
{
	if (InitSet->Signal == GPIO_Pin_Signal_Analog) {
		GPIO_SetSingalTypeFromPin(Pin, GPIO_Pin_Signal_Analog);
		GPIO_SetDirRegFromPin(Pin, GPIO_Direction_Input);
		GPIO_SetFuncxRegFromPin(Pin, GPIO_Reuse_Func0);
	} 
	else {
		GPIO_SetSingalTypeFromPin(Pin, GPIO_Pin_Signal_Digital);
		GPIO_SetDirRegFromPin(Pin, InitSet->Dir);
		GPIO_SetFuncxRegFromPin(Pin, InitSet->Func);

		if (InitSet->Dir == GPIO_Direction_Output) {
			GPIO_SetODERegFromPin(Pin, InitSet->ODE);
			GPIO_SetDSRegFromPin(Pin, InitSet->DS);
		} 
	  GPIO_SetPUERegFromPin(Pin, InitSet->PUE);
	  GPIO_SetPDERegFromPin(Pin, InitSet->PDE);
	}
}

/***************************************************************
  ��������GPIO_ReadBit
  ��  ������ȡ���ŵ�ֵ
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ�����ŵĵ�ƽֵ
 ***************************************************************/
uint32_t GPIO_ReadBit(GPIO_Pin Pin)
{
	uint8_t Start_Bit;
	uint32_t value;

	Start_Bit = GPIO_GetNormalBitOffsetFromPin(Pin);

	if (Pin <= GPIO_Pin_B13) {
		value = GPIO->PBPORT.Word;
	} 
	else {
		value = GPIO->PAPORT.Word;
	}

	value >>= Start_Bit;
	value &= 0x01;
	return value;
}

/***************************************************************
  ��������GPIO_WriteBit
  ��  �������������ָ����ƽ
  ����ֵ��Pin: Ŀ������
bit: ���ŵĵ�ƽֵ
���ֵ����
����ֵ����
 ***************************************************************/
void GPIO_WriteBit(GPIO_Pin Pin, uint32_t bit)
{
	uint8_t StartBit;

	StartBit = GPIO_GetNormalBitOffsetFromPin(Pin);

	if (Pin <= GPIO_Pin_B13) {
		if (bit == 1)
			GPIO->PBDATABSR.Word = (1 << StartBit);
		else
			GPIO->PBDATABCR.Word = (1 << StartBit);		
	} 
	else {
		if (bit == 1)
			GPIO->PADATABSR.Word = (1 << StartBit);
		else
			GPIO->PADATABCR.Word = (1 << StartBit);		
	}

	return;
}


/***************************************************************
  ��������GPIO_SetBit
  ��  �������������ָ����ƽ
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_SetBit(GPIO_Pin Pin)
{

	uint8_t StartBit;

	StartBit = GPIO_GetNormalBitOffsetFromPin(Pin);

	if (Pin <= GPIO_Pin_B13) {
		GPIO->PBDATABSR.Word = (1 << StartBit);	
	} 
	else {
		GPIO->PADATABSR.Word = (1 << StartBit);	
	}

	return;

}


/***************************************************************
  ��������GPIO_ResetBit
  ��  �������������ָ����ƽ
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_ResetBit(GPIO_Pin Pin)
{

	uint8_t StartBit;

	StartBit = GPIO_GetNormalBitOffsetFromPin(Pin);

	if (Pin <= GPIO_Pin_B13) {
		GPIO->PBDATABCR.Word = (1 << StartBit);		
	} 
	else {
		GPIO->PADATABCR.Word = (1 << StartBit);		
	}

	return;

}

/***************************************************************
  ��������GPIO_ToggleBit
  ��  �������������ָ����ƽ
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_ToggleBit(GPIO_Pin Pin)
{

	uint8_t StartBit;

	StartBit = GPIO_GetNormalBitOffsetFromPin(Pin);

	if (Pin <= GPIO_Pin_B13) {
		GPIO->PBDATABRR.Word = (1 << StartBit);		
	} 
	else {
		GPIO->PADATABRR.Word = (1 << StartBit);		
	}

	return;

}


/***************************************************************
  ��������PINT_GetPINTxIndexFromPin
  ��  �����������ŵ�����������
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ��Ŀ�����ŵ�����������
 ***************************************************************/
uint8_t PINT_GetPINTxIndexFromPin(GPIO_Pin Pin)
{
	uint8_t index;

	switch (Pin) {
		case GPIO_Pin_A0:
		case GPIO_Pin_A8:
		case GPIO_Pin_A16:
		case GPIO_Pin_A24:
		case GPIO_Pin_B0:
		case GPIO_Pin_B8:
			index = 0;
			break;
		case GPIO_Pin_A1:
		case GPIO_Pin_A9:
		case GPIO_Pin_A17:
		case GPIO_Pin_A25:
		case GPIO_Pin_B1:
		case GPIO_Pin_B9:
			index = 1;
			break;
		case GPIO_Pin_A2:
		case GPIO_Pin_A10:
		case GPIO_Pin_A18:
		case GPIO_Pin_A26:
		case GPIO_Pin_B2:
		case GPIO_Pin_B10:
			index = 2;
			break;
		case GPIO_Pin_A3:
		case GPIO_Pin_A11:
		case GPIO_Pin_A19:
		case GPIO_Pin_A27:
		case GPIO_Pin_B3:
		case GPIO_Pin_B11:
			index = 3;
			break;
		case GPIO_Pin_A4:
		case GPIO_Pin_A12:
		case GPIO_Pin_A20:
		case GPIO_Pin_A28:
		case GPIO_Pin_B4:
		case GPIO_Pin_B12:
			index = 4;
			break;
		case GPIO_Pin_A5:
		case GPIO_Pin_A13:
		case GPIO_Pin_A21:
		case GPIO_Pin_A29:
		case GPIO_Pin_B5:
		case GPIO_Pin_B13:
			index = 5;
			break;
		case GPIO_Pin_A6:
		case GPIO_Pin_A14:
		case GPIO_Pin_A22:
		case GPIO_Pin_A30:
		case GPIO_Pin_B6:
			index = 6;
			break;
		case GPIO_Pin_A7:
		case GPIO_Pin_A15:
		case GPIO_Pin_A23:
		case GPIO_Pin_A31:
		case GPIO_Pin_B7:
			index = 7;
			break;
		default:
			index = 0;
			break;
	}

	return index;
}

/***************************************************************
  ��������PINT_SetTriggerStyleFromPin
  ��  �����������ŵ��ⲿ�˿��жϴ�����ʽ
  ����ֵ��Pin: Ŀ������
Style: �жϴ�����ʽ
���ֵ����
����ֵ����
 ***************************************************************/
void PINT_SetTriggerStyleFromPin(GPIO_Pin Pin, PINT_Trigger_Style Style)
{
	uint32_t value;
	uint8_t index;

	index = PINT_GetPINTxIndexFromPin(Pin);

	value = GPIO->PINTCFG.Word;
	value &= (~(7 << (index * 4)));
	switch (Style) {
		case PINT_Trigger_Rising_Edge:
			value |= (0 << (index * 4));
			break;
		case PINT_Trigger_Trailing_Edge:
			value |= (1 << (index * 4));
			break;
		case PINT_Trigger_High_Level:
			value |= (2 << (index * 4));
			break;
		case PINT_Trigger_Low_Level:
			value |= (3 << (index * 4));
			break;
		case PINT_Trigger_Both_Edge:
			value |= (4 << (index * 4));
			break;
		default:
			break;
	}
	GPIO->PINTCFG.Word = value;

	return;
}

/***************************************************************
  ��������PINT_GetSELxIndexFromPin
  ��  �����������ŵĶ˿�ѡ��ֵ
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ�����ŵĶ˿�ѡ��ֵ
 ***************************************************************/
uint8_t PINT_GetSELxIndexFromPin(GPIO_Pin Pin)
{
	uint8_t index;

	switch (Pin) {
		case GPIO_Pin_A0:
		case GPIO_Pin_A1:
		case GPIO_Pin_A2:
		case GPIO_Pin_A3:
		case GPIO_Pin_A4:
		case GPIO_Pin_A5:
		case GPIO_Pin_A6:
		case GPIO_Pin_A7:
			index = 0;
			break;
		case GPIO_Pin_A8:
		case GPIO_Pin_A9:
		case GPIO_Pin_A10:
		case GPIO_Pin_A11:
		case GPIO_Pin_A12:
		case GPIO_Pin_A13:
		case GPIO_Pin_A14:
		case GPIO_Pin_A15:
			index = 1;
			break;
		case GPIO_Pin_A16:
		case GPIO_Pin_A17:
		case GPIO_Pin_A18:
		case GPIO_Pin_A19:
		case GPIO_Pin_A20:
		case GPIO_Pin_A21:
		case GPIO_Pin_A22:
		case GPIO_Pin_A23:
			index = 2;
			break;
		case GPIO_Pin_A24:
		case GPIO_Pin_A25:
		case GPIO_Pin_A26:
		case GPIO_Pin_A27:
		case GPIO_Pin_A28:
		case GPIO_Pin_A29:
		case GPIO_Pin_A30:
		case GPIO_Pin_A31:
			index = 3;
			break;
		case GPIO_Pin_B0:
		case GPIO_Pin_B1:
		case GPIO_Pin_B2:
		case GPIO_Pin_B3:
		case GPIO_Pin_B4:
		case GPIO_Pin_B5:
		case GPIO_Pin_B6:
		case GPIO_Pin_B7:
			index = 4;
			break;
		case GPIO_Pin_B8:
		case GPIO_Pin_B9:
		case GPIO_Pin_B10:
		case GPIO_Pin_B11:
		case GPIO_Pin_B12:
		case GPIO_Pin_B13:
			index = 5;
			break;
		default:
			index = 0;
			break;
	}

	return index;
}

/***************************************************************
  ��������PINT_SetEnableOrNotFromPin
  ��  ����ʹ�ܻ�������ŵ��ⲿ�˿��ж�
  ����ֵ��Pin: Ŀ������
IE: �ж�ʹ�ܷ�ʽ
���ֵ����
����ֵ����
 ***************************************************************/
void PINT_SetEnableOrNotFromPin(GPIO_Pin Pin, PINT_IE_Set IE)
{
	uint8_t Pintx;
	uint8_t Selx;
	uint32_t value;

	/* ѡ���ж�Դ */
	Pintx = PINT_GetPINTxIndexFromPin(Pin);
	Selx = PINT_GetSELxIndexFromPin(Pin);

	value = GPIO->PINTSEL.Word;
	value &= (~(7 << (Pintx * 4)));
	value |= (Selx << (Pintx * 4));
	GPIO->PINTSEL.Word = value;

	/* ����жϱ�־ */
	GPIO->PINTIF.Word = (1 << Pintx);

	/* ʹ��PINT�ж� */
	value = GPIO->PINTIE.Word;
	if (IE == PINT_IE_Set_Disable) {
		value &= (~(1 << Pintx));		/* �ر�ʹ��λ */
		value |= (1 << (Pintx + 8));		/* �����ж� */
		GPIO->PINTIE.Word = value;
		NVIC->ICER[0] = (1 << Pintx);
	} 
	else {
		value |= (1 << Pintx);			/* ��ʹ��λ */
		value &= (~(1 << (Pintx + 8)));		/* �������ж� */
		GPIO->PINTIE.Word = value;
		NVIC->ISER[0] = (1 << Pintx);
	}
	return;
}

/***************************************************************
  ��������PINT_Init
  ��  �����ⲿ�˿ڳ�ʼ��
  ����ֵ��Pin: Ŀ������
InitSet: ��ʼ���ṹ��
���ֵ����
����ֵ����
 ***************************************************************/
void PINT_Init(GPIO_Pin Pin, PINT_InitSettingType *InitSet)
{
	PINT_SetTriggerStyleFromPin(Pin, InitSet->Trigger_Style);
	PINT_SetEnableOrNotFromPin(Pin, InitSet->IE_Set);
}

/***************************************************************
  ��������PINT_ClearITFlag
  ��  ����������ŵ��ⲿ�˿��жϱ�־
  ����ֵ��Pin��Ŀ������
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void PINT_ClearITFlag(GPIO_Pin Pin)
{
	uint8_t Pintx;
	uint32_t value;

	Pintx = PINT_GetPINTxIndexFromPin(Pin);

	value = GPIO->PINTIF.Word;
	value |= (1 << Pintx);
	GPIO->PINTIF.Word = value;
	return;
}

/***************************************************************
  ��������PINT_GetITFlag
  ��  ������ȡ���ŵ��ⲿ�˿��жϱ�־
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ��Ŀ�����ŵ��ⲿ�˿��жϱ�־
 ***************************************************************/
uint32_t PINT_GetITFlag(GPIO_Pin Pin)
{
	uint8_t Pintx;
	uint32_t value;

	Pintx = PINT_GetPINTxIndexFromPin(Pin);

	value = GPIO->PINTIF.Word;
	value >>= Pintx;
	value &= 0x01;
	return value;
}

/***************************************************************
  ��������KINT_GetKINTxIndexFromPin
  ��  �����������ŵİ�������
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ�����ŵİ�������
 ***************************************************************/
uint8_t KINT_GetKINTxIndexFromPin(GPIO_Pin Pin)
{
	uint8_t index;

	switch (Pin) {
		case GPIO_Pin_A0:
		case GPIO_Pin_A8:
		case GPIO_Pin_A16:
		case GPIO_Pin_A24:
		case GPIO_Pin_B0:
		case GPIO_Pin_B8:
			index = 0;
			break;
		case GPIO_Pin_A1:
		case GPIO_Pin_A9:
		case GPIO_Pin_A17:
		case GPIO_Pin_A25:
		case GPIO_Pin_B1:
		case GPIO_Pin_B9:
			index = 1;
			break;
		case GPIO_Pin_A2:
		case GPIO_Pin_A10:
		case GPIO_Pin_A18:
		case GPIO_Pin_A26:
		case GPIO_Pin_B2:
		case GPIO_Pin_B10:
			index = 2;
			break;
		case GPIO_Pin_A3:
		case GPIO_Pin_A11:
		case GPIO_Pin_A19:
		case GPIO_Pin_A27:
		case GPIO_Pin_B3:
		case GPIO_Pin_B11:
			index = 3;
			break;
		case GPIO_Pin_A4:
		case GPIO_Pin_A12:
		case GPIO_Pin_A20:
		case GPIO_Pin_A28:
		case GPIO_Pin_B4:
		case GPIO_Pin_B12:
			index = 4;
			break;
		case GPIO_Pin_A5:
		case GPIO_Pin_A13:
		case GPIO_Pin_A21:
		case GPIO_Pin_A29:
		case GPIO_Pin_B5:
		case GPIO_Pin_B13:
			index = 5;
			break;
		case GPIO_Pin_A6:
		case GPIO_Pin_A14:
		case GPIO_Pin_A22:
		case GPIO_Pin_A30:
		case GPIO_Pin_B6:
			index = 6;
			break;
		case GPIO_Pin_A7:
		case GPIO_Pin_A15:
		case GPIO_Pin_A23:
		case GPIO_Pin_A31:
		case GPIO_Pin_B7:
			index = 7;
			break;
		default:
			index = 0;
			break;
	}

	return index;
}

/***************************************************************
  ��������KINT_SetTriggerStyleFromPin
  ��  �����������ŵİ���������ʽ
  ����ֵ��Pin: Ŀ������
Style: �жϴ�����ʽ
���ֵ����
����ֵ����
 ***************************************************************/
void KINT_SetTriggerStyleFromPin(GPIO_Pin Pin, KINT_Trigger_Style Style)
{
	uint8_t Kintx;
	uint32_t value;

	Kintx = KINT_GetKINTxIndexFromPin(Pin);

	value = GPIO->KINTCFG.Word;
	value &= (~(7 << (Kintx * 4)));
	switch (Style) {
		case KINT_Trigger_Rising_Edge:
			value |= (0 << (Kintx * 4));
			break;
		case KINT_Trigger_Trailing_Edge:
			value |= (1 << (Kintx * 4));
			break;
		case KINT_Trigger_High_Level:
			value |= (2 << (Kintx * 4));
			break;
		case KINT_Trigger_Low_Level:
			value |= (3 << (Kintx * 4));
			break;
		case KINT_Trigger_Both_Edge:
			value |= (4 << (Kintx * 4));
			break;
		default:
			break;
	}
	GPIO->KINTCFG.Word = value;

	return;
}

/***************************************************************
  ��������KINT_GetSelxIndexFromPin
  ��  �����������ŵĶ˿�ѡ������
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ��Ŀ�����ŵĶ˿�ѡ������
 ***************************************************************/
uint8_t KINT_GetSelxIndexFromPin(GPIO_Pin Pin)
{
	uint8_t index;

	switch (Pin) {
		case GPIO_Pin_A0:
		case GPIO_Pin_A1:
		case GPIO_Pin_A2:
		case GPIO_Pin_A3:
		case GPIO_Pin_A4:
		case GPIO_Pin_A5:
		case GPIO_Pin_A6:
		case GPIO_Pin_A7:
			index = 0;
			break;
		case GPIO_Pin_A8:
		case GPIO_Pin_A9:
		case GPIO_Pin_A10:
		case GPIO_Pin_A11:
		case GPIO_Pin_A12:
		case GPIO_Pin_A13:
		case GPIO_Pin_A14:
		case GPIO_Pin_A15:
			index = 1;
			break;
		case GPIO_Pin_A16:
		case GPIO_Pin_A17:
		case GPIO_Pin_A18:
		case GPIO_Pin_A19:
		case GPIO_Pin_A20:
		case GPIO_Pin_A21:
		case GPIO_Pin_A22:
		case GPIO_Pin_A23:
			index = 2;
			break;
		case GPIO_Pin_A24:
		case GPIO_Pin_A25:
		case GPIO_Pin_A26:
		case GPIO_Pin_A27:
		case GPIO_Pin_A28:
		case GPIO_Pin_A29:
		case GPIO_Pin_A30:
		case GPIO_Pin_A31:
			index = 3;
			break;
		case GPIO_Pin_B0:
		case GPIO_Pin_B1:
		case GPIO_Pin_B2:
		case GPIO_Pin_B3:
		case GPIO_Pin_B4:
		case GPIO_Pin_B5:
		case GPIO_Pin_B6:
		case GPIO_Pin_B7:
			index = 4;
			break;
		case GPIO_Pin_B8:
		case GPIO_Pin_B9:
		case GPIO_Pin_B10:
		case GPIO_Pin_B11:
		case GPIO_Pin_B12:
		case GPIO_Pin_B13:
			index = 5;
			break;
		default:
			index = 0;
			break;
	}

	return index;
}

/***************************************************************
  ��������KINT_SetEnableOrNotFromPin
  ��  ����ʹ�ܻ�������ŵİ����ж�
  ����ֵ��Pin: Ŀ������
IE: �����ж�ʹ�ܷ�ʽ
���ֵ����
����ֵ����
 ***************************************************************/
void KINT_SetEnableOrNotFromPin(GPIO_Pin Pin, KINT_IE_Set IE)
{
	uint8_t Kintx;
	uint8_t Selx;
	uint32_t value;

	/* �ж���������ѡ�� */
	Kintx = KINT_GetKINTxIndexFromPin(Pin);
	Selx = KINT_GetSelxIndexFromPin(Pin);

	value = GPIO->KINTSEL.Word;
	value &= (~(7 << (Kintx * 4)));
	value |= (Selx << (Kintx * 4));
	GPIO->KINTSEL.Word = value;

	/* ����жϱ�־ */
	value = (1 << Kintx);
	GPIO->KINTIF.Word = value;

	/* ʹ��PINT�ж� */
	value = GPIO->KINTIE.Word;
	if (IE == KINT_IE_Set_Disable) {
		value &= (~(1 << Kintx));	/* ���ʹ��λ */
		value |= (1 << (Kintx + 8));	/* �����ж� */
		GPIO->KINTIE.Word = value;
		NVIC->ICER[0] = (1 << 18);
	} 
	else {
		value |= (1 << Kintx);		/* ����ʹ��λ */
		value &= (~(1 << (Kintx + 8)));	/* �������ж� */
		GPIO->KINTIE.Word = value;
		NVIC->ISER[0] = (1 << 18);
	}

	return;
}

/***************************************************************
  ��������KINT_Init
  ��  �����������ų�ʼ��
  ����ֵ��Pin: Ŀ������
InitSet: ��ʼ���ṹ��
���ֵ����
����ֵ����
 ***************************************************************/
void KINT_Init(GPIO_Pin Pin, KINT_InitSettingType *InitSet)
{
	KINT_SetTriggerStyleFromPin(Pin, InitSet->Trigger_Style);
	KINT_SetEnableOrNotFromPin(Pin, InitSet->IE_Set);
}

/***************************************************************
  ��������KINT_ClearITFlag
  ��  ����������ŵİ����жϱ�־
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void KINT_ClearITFlag(GPIO_Pin Pin)
{
	uint8_t Kintx;
	uint32_t value;

	Kintx = KINT_GetKINTxIndexFromPin(Pin);

	value = (1 << Kintx);
	GPIO->KINTIF.Word = value;
	return;
}

/***************************************************************
  ��������KINT_GetITFlag
  ��  ������ȡ���ŵİ����жϱ�־
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ��Ŀ�����ŵİ����жϱ�־
 ***************************************************************/
uint32_t KINT_GetITFlag(GPIO_Pin Pin)
{
	uint8_t Kintx;
	uint32_t value;

	Kintx = KINT_GetKINTxIndexFromPin(Pin);

	value = GPIO->KINTIF.Word;
	value >>= Kintx;
	value &= 0x01;
	return value;
}


/***************************************************************
��������UART_TXxConfig
��  ����TXx��������������
����ֵ��Plv�����Ƶ�ƽѡ�� �� Ps������PWM����ѡ�� ��TxSx: ���Ʋ�������ܽ�ѡ��NewState ��Disable��Enable
���ֵ����
����ֵ����
***************************************************************/
void GPIO_TX0Config(UART_TYPE_TXPLV Plv,UART_TYPE_TX0PS Ps,UART_TYPE_TX0Sx TX0Sx,TYPE_FUNCEN NewState)
{
	 GPIO->TXPWM.TX0PS = Ps;
	 GPIO->TXPWM.TX0PLV = Plv;
	 if(Ps == UART_TX0PS_NO)
	   return;
	  switch(TX0Sx)
	  {
	    case UART_TYPE_TXD0:
				GPIO->TXPWM.TX0_S0 = NewState;
	      break;
	    case UART_TYPE_T16N0OUT0:
			  GPIO->TXPWM.TX0_S1 = NewState;
	      break;
		  case UART_TYPE_T16N0OUT1:
			  GPIO->TXPWM.TX0_S2 = NewState;
	      break;
		  case UART_TYPE_TX0BUZ:
			  GPIO->TXPWM.TX0_S3 = NewState;
	      break;
	 }
}

void GPIO_TX1Config(UART_TYPE_TXPLV Plv,UART_TYPE_TX1PS Ps,UART_TYPE_TX1Sx TX1Sx,TYPE_FUNCEN NewState)
{
	 GPIO->TXPWM.TX1PLV = Plv;
	 GPIO->TXPWM.TX1PS = Ps;
	 if(Ps == UART_TX1PS_NO)
	   return;
	  switch(TX1Sx)
	  {
	    case UART_TYPE_E0TX0:
				GPIO->TXPWM.TX1_S0 = NewState;
	      break;
	    case UART_TYPE_T16N1OUT0:
			  GPIO->TXPWM.TX1_S1 = NewState;
	      break;
		  case UART_TYPE_T16N1OUT1:
			  GPIO->TXPWM.TX1_S2 = NewState;
	      break;
		  case UART_TYPE_TX1BUZ:
			  GPIO->TXPWM.TX1_S3 = NewState;
	      break;
	 }
}

