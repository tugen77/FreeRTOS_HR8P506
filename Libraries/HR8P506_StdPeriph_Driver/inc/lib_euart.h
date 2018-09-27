/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_euart.h
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  EUARTģ��⺯��ͷ�ļ�
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#ifndef __LIBEUART_H__
#define __LIBEUART_H__

#include "HR8P506.h"
#include "lib_uart.h"
#include "type.h"

/* ֹͣλ */
typedef enum {
	EUART_StopBits_1 = 0x0,			// 1λֹͣλ
	EUART_StopBits_2 = 0x1,			// 2λֹͣλ
} EUART_TYPE_TXFS;

/* ���ݸ�ʽ */
typedef enum {
	EUART_DataMode_8     = 0x0,		//8λ����
	EUART_DataMode_9     = 0x2,		//9λ����
	EUART_DataMode_7     = 0x4,		//7λ����
	EUART_DataMode_8Even = 0x8,		//8λ����+żУ��
	EUART_DataMode_8Odd  = 0x9,		//8λ����+��У��
	EUART_DataMode_8Add0 = 0xa,		//8λ����+�̶�0
	EUART_DataMode_8Add1 = 0xb,		//8λ����+�̶�1
	EUART_DataMode_7Even = 0xc,		//7λ����+żУ��
	EUART_DataMode_7Odd  = 0xd,		//7λ����+��У��
	EUART_DataMode_7Add0 = 0xe,		//7λ����+�̶�0
	EUART_DataMode_7Add1 = 0xf,		//7λ����+�̶�1
} EUART_TYPE_DATAMOD;

/* �˿ڼ���ѡ�� */
typedef enum {
	EUART_Polar_Normal   = 0x0,		//������
	EUART_Polar_Opposite = 0x01,	//������
} EUART_TYPE_RTXP;

/* ʱ��ѡ�� */
typedef enum {
	EUART_Clock_1 = 0x1,	// PCLK / 1
	EUART_Clock_2 = 0x2,	// PCLK / 2
	EUART_Clock_3 = 0x3,	// PCLK / 4
	EUART_Clock_4 = 0x4,	// PCLK / 8
} EUART_TYPE_BCS;

/* ��ʼ���ṹ�� */
typedef struct {
	EUART_TYPE_TXFS    EUART_StopBits;	//ֹͣλѡ��
	EUART_TYPE_DATAMOD EUART_TxMode;	//�������ݸ�ʽ
	EUART_TYPE_RTXP    EUART_TxPolar;	//���Ͷ˿ڼ���
	EUART_TYPE_DATAMOD EUART_RxMode;	//�������ݸ�ʽ
	EUART_TYPE_RTXP    EUART_RxPolar;	//���ն˿ڼ���
	uint32_t           EUART_BaudRate;	//������
	EUART_TYPE_BCS     EUART_ClockSet;	//EUARTʱ��ѡ��
} EUART_InitStruType;

/* �ж�ʹ�ܱ�־λ */
typedef enum {
	EUART_IT_TB   = (1 << 0),	//���ͻ��������ж�
	EUART_IT_TC   = (1 << 1),	//��������ж�
	EUART_IT_TBWE = (1 << 8),	//д���ͻ�������ж�
	EUART_IT_ARTE = (1 << 12),	//�Զ��ط�ʧ���ж�
	EUART_IT_RNA  = (1 << 13),	//���յ������ź��ж�
	EUART_IT_RB   = (1 << 16),	//���ջ��������ж�
	EUART_IT_RO   = (1 << 24),	//���ջ���������ж�
	EUART_IT_FE   = (1 << 25),	//����֡�����ж�
	EUART_IT_PE   = (1 << 26),	//����У������ж�
	EUART_IT_RBRE = (1 << 28),	//�����ջ�������ж�
} EUART_TYPE_IT;

/* �ж�״̬��־λ */
typedef enum {
	EUART_FLAG_TB   = (1 << 0),		//���ͻ��������жϱ�־
	EUART_FLAG_TC   = (1 << 1),		//��������жϱ�־
	EUART_FLAG_TBWE = (1 << 8),		//д���ͻ�������жϱ�־
	EUART_FLAG_ARTE = (1 << 12),	//�Զ��ط�ʧ���жϱ�־
	EUART_FLAG_RNA  = (1 << 13),	//���յ������ź��жϱ�־
	EUART_FLAG_RB   = (1 << 16),	//���ջ��������жϱ�־
	EUART_FLAG_RO   = (1 << 24),	//���ջ���������жϱ�־
	EUART_FLAG_FE   = (1 << 25),	//����֡�жϱ�־
	EUART_FLAG_PE   = (1 << 26),	//����У���жϱ�־
	EUART_FLAG_RBRE = (1 << 28),	//�����ջ�������жϱ�־
} EUART_TYPE_FLAG;

/* ����ж�״̬��־λ */
typedef enum {
	EUART_CLR_TC   = (1 << 1),		//��������жϱ�־
	EUART_CLR_TBWE = (1 << 8),		//д���ͻ�������жϱ�־
	EUART_CLR_ARTE = (1 << 12),		//�Զ��ط�ʧ���жϱ�־
	EUART_CLR_RNA  = (1 << 13),		//���յ������ź��жϱ�־
	EUART_CLR_RO   = (1 << 24),		//���ջ���������жϱ�־
	EUART_CLR_FE   = (1 << 25),		//����֡�жϱ�־
	EUART_CLR_PE   = (1 << 26),		//����У���жϱ�־
	EUART_CLR_RBRE = (1 << 28),		//�����ջ�������жϱ�־
} EUART_CLR_IF;

/* ���ͻ�������/���ջ��������ж����� */
typedef enum {
	EUART_TRBIM_Byte     = 0x0,		//�ֽڿ��ж�
	EUART_TRBIM_HalfWord = 0x1,		//���ֿ��ж�
	EUART_TRBIM_Word     = 0x2,		//�ֿ��ж�
} EUART_TYPE_TRBIM;

/* U7816 Module */
/* EUARTģʽѡ�� */
typedef enum {
	EUART_Mode_Uart  = 0x0,		//ͨ��UARTģʽ
	EUART_Mode_U7816 = 0x1,		//7816ͨѶģʽ
} EUART_TYPE_MODE;

/* EIO�˿�ѡ�� */
typedef enum {
	U7816_CHS_EIO0 = 0x0,		//EIO�˿�0
	U7816_CHS_EIO1 = 0x1,		//EIO�˿�1
} U7816_TYPE_CHS;

/* EIO����ѡ�� */
typedef enum {
	U7816_EIODir_In  = 0x0,		//��������
	U7816_EIODir_Out = 0x1,		//��������
} U7816_TYPE_IOC;

/* ���ݸ�ʽ */
typedef enum {
	U7816_DataForm_Normal   = 0x0,	//����
	U7816_DataForm_Contrary = 0x1,	//����
} U7816_TYPE_DAS;

/* У��ѡ�� */
typedef enum {
	U7816_Verify_Odd  = 0x0,	//��У��
	U7816_Verify_Even = 0x1,	//żУ��
} U7816_TYPE_PS;

/* NACK��� */
typedef enum {
	U7816_NACKWidth_1ETU   = 0x0,	//1��ETU
	U7816_NACKWidth_1P5ETU = 0x1,	//1.5��ETU
	U7816_NACKWidth_2ETU   = 0x2,	//2��ETU
} U7816_TYPE_TNAS;

/* �ط����� */
typedef enum {
	U7816_RetryTime_1 = 0x0,	//�ط�1��
	U7816_RetryTime_2 = 0x1,	//�ط�2��
	U7816_RetryTime_3 = 0x2,	//�ط�3��
	U7816_RetryTime_N = 0x3,	//�ط����޴Σ�ֱ�����ͳɹ�
} U7816_TYPE_ARTS;

/* ʱ��ѡ�� */
typedef enum {
	U7816_PCLK_1 = 0x0,		//PCLK
	U7816_PCLK_2 = 0x1,		//PCLK / 2
	U7816_PCLK_4 = 0x2,		//PCLK / 4
	U7816_PCLK_8 = 0x3,		//PCLK / 8
} U7816_TYPE_CKS;

/* 7816��ʼ���ṹ�� */
typedef struct {
	EUART_TYPE_BCS  U7816_ClockSet;		//ʱ��ѡ��
	uint32_t        U7816_BaudRate;		//������
	TYPE_FUNCEN     U7816_ECK0;			//ECK0ʹ��
	TYPE_FUNCEN     U7816_ECK1;			//ECK1ʹ��
	U7816_TYPE_CHS  U7816_EIOCh;		//EIOͨѶͨ��ѡ��λ
	U7816_TYPE_IOC  U7816_EIODir;		//EIO�˿ڷ���
	U7816_TYPE_DAS  U7816_DataForm;		//���ݸ�ʽ
	U7816_TYPE_PS   U7816_DataVerify;	//��żУ��
	TYPE_FUNCEN     U7816_AutoRetryTx;	//�Զ��ط�
	TYPE_FUNCEN     U7816_AutoRetryRx;	//�Զ�����
	U7816_TYPE_TNAS U7816_NACK_Width;	//NACK�źſ��
	U7816_TYPE_ARTS U7816_RetryTimes;	//�Զ�����
	U7816_TYPE_CKS  U7816_CLKS;			//ʱ��Դѡ��
	uint8_t         U7816_ETUTime;		//ETU����ʱ��
} U7816_InitStruType;


#define EUART_TxEnable()	(EUART0->CON0.TXEN = 1)
#define EUART_TxDisable()	(EUART0->CON0.TXEN = 0)
#define EUART_RxEnable()	(EUART0->CON0.RXEN = 1)
#define EUART_RxDisable()	(EUART0->CON0.RXEN = 0)

#define EUART_TxRst()		(EUART0->CON0.TRST = 1)
#define EUART_RxRst()		(EUART0->CON0.RRST = 1)
#define EUART_U7816_REST()	(EUART0->CON2.ERST = 1)

void EUART_ModeConfig(EUART_TYPE_MODE Mode);
void EUART_Init(EUART_InitStruType *EUART_InitStruct);
void EUART_BaudConfig(uint32_t BaudRate, EUART_TYPE_BCS ClockSet);
void EUART_ITConfig(EUART_TYPE_IT EUART_IT, TYPE_FUNCEN NewState);
void EUART_TBIMConfig(EUART_TYPE_TRBIM Type);
void EUART_RBIMConfig(EUART_TYPE_TRBIM Type);
FlagStatus EUART_GetFlagStatus(EUART_TYPE_FLAG EUART_Flag);
ITStatus EUART_GetITStatus(EUART_TYPE_IT EUART_Flag);
void EUART_ClearITPendingBit(EUART_CLR_IF EUART_Flag);

void U7816_Init(U7816_InitStruType *U7816_InitStruct);
void EUART_EIOChConfig(U7816_TYPE_CHS U7816_IO);
void EUART_EIODirection(U7816_TYPE_IOC Dir);
void EUART_SendByte(uint8_t ByteData);
void EUART_SendHalfWord(uint16_t HalfWordData);
void EUART_SendWord(uint32_t WordData);
uint8_t EUART_RecByte(void);
uint16_t EUART_RecHalfWord(void);
uint32_t EUART_RecWord(void);

#endif
