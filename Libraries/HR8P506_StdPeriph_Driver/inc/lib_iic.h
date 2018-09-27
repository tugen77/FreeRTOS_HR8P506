/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_iic.h
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  IICģ��⺯��ͷ�ļ�
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/

#ifndef __LIBIIC_H__
#define __LIBIIC_H__

#include "HR8P506.h"
#include "type.h"


/* �������ģʽ */
typedef enum {
	IIC_PinMode_PP = 0x0,	//����
	IIC_PinMode_OD = 0x1,	//��©
} IIC_TYPE_PINOD;

/* ����ģʽ */
typedef enum {
	IIC_Mode_Master = 0x0,	//����ģʽ
	IIC_Mode_Slave  = 0x1,	//�Ӷ�ģʽ
} IIC_TYPE_MODE;

/* �ӳ�ʱ�� */
typedef enum {
	IIC_AckDelay_0P5 = 0x0,	//0.5��ʱ������
	IIC_AckDelay_1   = 0x1,	//1��ʱ������
	IIC_AckDelay_1P5 = 0x2,	//1.5��ʱ������
	IIC_AckDelay_2   = 0x3,	//2��ʱ������
	IIC_AckDelay_2P5 = 0x4,	//2.5��ʱ������
	IIC_AckDelay_3   = 0x5,	//3��ʱ������
	IIC_AckDelay_3P5 = 0x6,	//3.5��ʱ������
	IIC_AckDelay_4   = 0x7,	//4��ʱ������
} IIC_TYPE_ADLY;

/* ����ģʽ */
typedef enum {
	IIC_RecMode_0 = 0x0,	//����1���ֽڣ�����ACK
	IIC_RecMode_1 = 0x1,	//����1���ֽڣ�����NACK
	IIC_RecMode_2 = 0x2,	//����2���ֽڣ�����ACK 
	IIC_RecMode_3 = 0x3,	//����2���ֽڣ�ǰ����ACK������NACK 
	IIC_RecMode_4 = 0x4,	//����4���ֽڣ�ÿ�ֽڷ���ACK 
	IIC_RecMode_5 = 0x5,	//����4���ֽڣ�ǰ3�ֽڷ���ACK����NACK
} IIC_TYPE_RECMODE;

/* ������ */
typedef enum {
	IIC_TIS_Disable = 0x0,	//������0
	IIC_TIS_1       = 0x1,	//������1
	IIC_TIS_2       = 0x2,	//������2	
	IIC_TIS_3       = 0x3,	//������3
	IIC_TIS_4       = 0x4,	//������4
	IIC_TIS_5       = 0x5,	//������5
	IIC_TIS_6       = 0x6,	//������6
	IIC_TIS_7       = 0x7,	//������7
	IIC_TIS_8       = 0x8,	//������8
	IIC_TIS_9       = 0x9,	//������9
	IIC_TIS_A       = 0xA,	//������10
	IIC_TIS_B       = 0xB,	//������11
	IIC_TIS_C       = 0xC,	//������12
	IIC_TIS_D       = 0xD,	//������13
	IIC_TIS_E       = 0xE,	//������14
	IIC_TIS_F       = 0xF,	//������15
} IIC_TYPE_TIS;

/* ��ʼ���ṹ�� */
typedef struct {
	IIC_TYPE_PINOD IIC_SckOd;		//SCK���ģʽ
	IIC_TYPE_PINOD IIC_SdaOd;		//SDA���ģʽ
	TYPE_FUNCEN    IIC_16XSamp;		//16������ʹ��λ
	uint32_t       IIC_Clk;			//IICƵ��
	IIC_TYPE_MODE  IIC_Mode;		//IIC����ģʽ	
	TYPE_FUNCEN    IIC_AutoStop;	//�Զ�ֹͣ
	TYPE_FUNCEN    IIC_AutoCall;	//�Զ�Ѱ��
} IIC_InitStruType;

/* ���ͻ�������/���ջ��������ж����� */
typedef enum {
	IIC_TRBIM_Byte     = 0x0,	//�ֽ��ж�
	IIC_TRBIM_HalfWord = 0x1,	//�����ж�
	IIC_TRBIM_Word     = 0x2,	//���ж�
} IIC_TYPE_TRBIM;

/* ����ģʽ */
typedef enum {
	IIC_Mode_Write = 0x0,	//д
	IIC_Mode_Read  = 0x1,	//��
} IIC_TYPE_RWMODE;

/* �ж�ʹ�ܱ�־λ */
typedef enum {
	IIC_IT_SR    = (1 << 0),	//��ʼλ�ж�
	IIC_IT_SP    = (1 << 1),	//ֹͣλ�ж�
	IIC_IT_TB    = (1 << 2),	//���ͻ�����ж�
	IIC_IT_RB    = (1 << 3),	//���ջ������ж�
	IIC_IT_TE    = (1 << 4),	//�������ݴ����ж�
	IIC_IT_RO    = (1 << 5),	//������������ж�
	IIC_IT_NA    = (1 << 6),	//δӦ��NACK�ж�
	IIC_IT_TBWE  = (1 << 7),	//��������д�����ж�
	IIC_IT_TIDLE = (1 << 12),	//�����ж��ж�
} IIC_TYPE_IT;

/* �жϱ�־λ */
typedef enum {
	IIC_IF_SR    = (1 << 0),	//��ʼλ�ж�
	IIC_IF_SP    = (1 << 1),	//ֹͣλ�ж�
	IIC_IF_TB    = (1 << 2),	//���ͻ�������λ�ж�
	IIC_IF_RB    = (1 << 3),	//���ջ��������ж�
	IIC_IF_TE    = (1 << 4),	//�������ݴ����ж�
	IIC_IF_RO    = (1 << 5),	//������������ж�
	IIC_IF_NA    = (1 << 6),	//δӦ��NACK�ж�
	IIC_IF_TBWE  = (1 << 7),	//��������д�����ж�
	IIC_IF_TIDLE = (1 << 12),	//�����ж�
} IIC_TYPE_IF;

/* ����жϱ�־λ���� */
typedef enum {
	IIC_CLR_SR    = (1 << 0),	//��ʼλ�ж�
	IIC_CLR_SP    = (1 << 1),	//ֹͣλ�ж�
	IIC_CLR_TE    = (1 << 4),	//�������ݴ����ж�
	IIC_CLR_RO    = (1 << 5),	//������������ж�
	IIC_CLR_NA    = (1 << 6),	//δӦ��NACK�ж�
	IIC_CLR_TBWE  = (1 << 7),	//��������д�����ж�
	IIC_CLR_TIDLE = (1 << 12),	//�����ж�
} IIC_CLR_IF;


#define IIC0_Enable()		(I2C0->CON.EN = 1)
#define IIC1_Enable()		(I2C1->CON.EN = 1)
#define IIC0_Disable()		(I2C0->CON.EN = 0)
#define IIC1_Disable()		(I2C1->CON.EN = 0)

#define IIC0_Reset()		(I2C0->CON.RST = 1)
#define IIC1_Reset()		(I2C1->CON.RST = 1)

#define IIC0_TJEnable()		(I2C0->CON.TJE = 1)
#define IIC1_TJEnable()		(I2C1->CON.TJE = 1)
#define IIC0_TJDisable()	(I2C0->CON.TJE = 0)
#define IIC1_TJDisable()	(I2C1->CON.TJE = 0)

#define IIC0_Read()		(I2C0->CON.RW = 1)
#define IIC1_Read()		(I2C1->CON.RW = 1)
#define IIC0_Write()		(I2C0->CON.RW = 0)
#define IIC1_Write()		(I2C1->CON.RW = 0)

#define IIC0_CSEnable()		(I2C0->MOD.CSE = 1)
#define IIC1_CSEnable()		(I2C1->MOD.CSE = 1)
#define IIC0_CSDisable()	(I2C0->MOD.CSE = 0)
#define IIC1_CSDisable()	(I2C1->MOD.CSE = 0)

#define IIC0_ANAEnable()	(I2C0->MOD.ANAE = 1)
#define IIC1_ANAEnable()	(I2C1->MOD.ANAE = 1)
#define IIC0_ANADisable()	(I2C0->MOD.ANAE = 0)
#define IIC1_ANADisable()	(I2C1->MOD.ANAE = 0)

#define IIC0_SRAEnable()	(I2C0->MOD.SRAE = 1)
#define IIC1_SRAEnable()	(I2C1->MOD.SRAE = 1)
#define IIC0_SRADisable()	(I2C0->MOD.SRAE = 0)
#define IIC1_SRADisable()	(I2C1->MOD.SRAE = 0)

#define IIC0_SPAEnable()	(I2C0->MOD.SPAE = 1)
#define IIC1_SPAEnable()	(I2C1->MOD.SPAE = 1)
#define IIC0_SPADisable()	(I2C0->MOD.SPAE = 0)
#define IIC1_SPADisable()	(I2C1->MOD.SPAE = 0)

#define IIC0_SRTrigger()	(I2C0->MOD.SRT = 1)
#define IIC1_SRTrigger()	(I2C1->MOD.SRT = 1)

#define IIC0_SPTrigger()	(I2C0->MOD.SPT = 1)
#define IIC1_SPTrigger()	(I2C1->MOD.SPT = 1)

#define IIC0_RDTrigger()	(I2C0->MOD.RDT = 1)
#define IIC1_RDTrigger()	(I2C1->MOD.RDT = 1)

#define IIC0_Release()		(I2C0->MOD.BLD = 1)
#define IIC1_Release()		(I2C1->MOD.BLD = 1)

#define IIC0_TACK()		(I2C0->MOD.TAS = 1)
#define IIC1_TACK()		(I2C1->MOD.TAS = 1)
#define IIC0_TNACK()		(I2C0->MOD.TAS = 0)
#define IIC1_TNACK()		(I2C1->MOD.TAS = 0)


void IIC_Init(I2C_TypeDef *IICx, IIC_InitStruType *IIC_InitStruct);
void IIC_ITConfig(I2C_TypeDef *IICx, IIC_TYPE_IT IIC_IT, TYPE_FUNCEN NewState);
void IIC_SendAddress(I2C_TypeDef *IICx, uint8_t IIC_Address, IIC_TYPE_RWMODE Mode);
void IIC_SetAddress(I2C_TypeDef *IICx, uint8_t IIC_Address);
void IIC_RecModeConfig(I2C_TypeDef *IICx, IIC_TYPE_RECMODE RecType);
void IIC_TBIMConfig(I2C_TypeDef *IICx, IIC_TYPE_TRBIM Type);
void IIC_RBIMConfig(I2C_TypeDef *IICx, IIC_TYPE_TRBIM Type);
void IIC_AckDelay(I2C_TypeDef *IICx, IIC_TYPE_ADLY Type, TYPE_FUNCEN NewStatus);
void IIC_TISConfig(I2C_TypeDef *IICx, IIC_TYPE_TIS Time);
void IIC_SendByte(I2C_TypeDef *IICx, uint8_t Byte);
void IIC_SendHalfWord(I2C_TypeDef *IICx, uint16_t HalfWord);
void IIC_SendWord(I2C_TypeDef *IICx, uint32_t Word);
uint8_t IIC_RecByte(I2C_TypeDef *IICx);
uint16_t IIC_RecHalfWord(I2C_TypeDef *IICx);
uint32_t IIC_RecWord(I2C_TypeDef *IICx);
IIC_TYPE_RWMODE IIC_GetRWMode(I2C_TypeDef *IICx);
FlagStatus IIC_GetTBStatus(I2C_TypeDef *IICx);
FlagStatus IIC_GetFlagStatus(I2C_TypeDef *IICx, IIC_TYPE_IF IIC_Flag);
FlagStatus IIC_GetITStatus(I2C_TypeDef *IICx, IIC_TYPE_IT IIC_Flag);
void IIC_ClearITPendingBit(I2C_TypeDef *IICx, IIC_CLR_IF IIC_IT);

#endif
