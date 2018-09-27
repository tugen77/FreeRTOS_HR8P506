/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_uart.h
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  UARTģ��⺯��ͷ�ļ�
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#ifndef __LIBUART_H__
#define __LIBUART_H__

#include "HR8P506.h"
#include "type.h"

/* ֹͣλ */
typedef enum {
	UART_StopBits_1 = 0x0,		//1λֹͣλ
	UART_StopBits_2 = 0x1,		//2λֹͣλ
} UART_TYPE_TXFS;

/* ���ݸ�ʽ */
typedef enum {
	UART_DataMode_7     = 0x4,	//7λ����
	UART_DataMode_8     = 0x0,	//8λ����
	UART_DataMode_9     = 0x2,	//9λ����
	UART_DataMode_7Odd  = 0xD,	//7λ���ݣ���У��
	UART_DataMode_7Even = 0xC,	//7λ���ݣ�żУ��
	UART_DataMode_7Add0 = 0xE,	//7λ���ݣ��̶�0
	UART_DataMode_7Add1 = 0xF,	//7λ���ݣ��̶�1 
	UART_DataMode_8Odd  = 0x9,	//8λ���ݣ���У��
	UART_DataMode_8Even = 0x8,	//8λ���ݣ�żУ��
	UART_DataMode_8Add0 = 0xA,	//8λ���ݣ��̶�0
	UART_DataMode_8Add1 = 0xB,	//8λ���ݣ��̶�1
} UART_TYPE_DATAMOD;

/* �˿ڼ��� */
typedef enum {
	UART_Polar_Normal   = 0x0,	//������
	UART_Polar_Opposite = 0x1,	//������
} UART_TYPE_RTXP;

/* ʱ��ѡ�� */
typedef enum {
	UART_Clock_1 = 0x1,			//PCLK
	UART_Clock_2 = 0x2,			//PCLK / 2
	UART_Clock_3 = 0x3,			//PCLK / 4
	UART_Clock_4 = 0x4,			//PCLK / 8
} UART_TYPE_BCS;

/* ��ʼ���ṹ�� */
typedef struct {
	UART_TYPE_TXFS    UART_StopBits;	//ֹͣλѡ��
	UART_TYPE_DATAMOD UART_TxMode;		//�������ݸ�ʽ
	UART_TYPE_RTXP    UART_TxPolar;		//���Ͷ˿ڼ���
	UART_TYPE_DATAMOD UART_RxMode;		//�������ݸ�ʽ
	UART_TYPE_RTXP    UART_RxPolar;		//���ն˿ڼ���
	uint32_t          UART_BaudRate;	//������
	UART_TYPE_BCS     UART_ClockSet;	//UARTʱ��ѡ��
} UART_InitStruType;

/*�Զ������ʼ��ģʽ*/
typedef enum {
	UART_AUTO_BAUD_MODE1 = 0x00,	//�Զ������ʼ��ģʽ1,�����������Զ�����1��ʼ
	UART_AUTO_BAUD_MODE2 = 0x01,	//�Զ������ʼ��ģʽ1,�����������Զ�����10��ʼ
	UART_AUTO_BAUD_MODE3 = 0x02,	//�Զ������ʼ��ģʽ1,�����������Զ�����1111_1110��ʼ
	UART_AUTO_BAUD_MODE4 = 0x03,	//�Զ������ʼ��ģʽ1,�����������Զ�����1010_1010��ʼ
} UART_AUTO_BAUD_MODE;

/*���м��ģʽ*/
typedef enum {
	UART_AUTO_BAUD_FREE_MODE1 = 0x00,	//��������� 10 ������λ����
	UART_AUTO_BAUD_FREE_MODE2 = 0x01,	//��������� 11 ������λ����
	UART_AUTO_BAUD_FREE_MODE3 = 0x02,	//��������� 12 ������λ����
    UART_AUTO_BAUD_FREE_MODE4 = 0x03,	//��������� 13 ������λ����
} UART_AUTO_BAUD_FREE_MODE;

/* Interrupt */
typedef enum {
	UART_IT_TB   = (1 << 0),		//���ͻ��������ж�
	UART_IT_TC   = (1 << 1),		//��������ж�
	UART_IT_TBWE = (1 << 8),		//���ͻ�������ж�
	UART_IT_TBWO = (1 << 9),		//���ͻ�������ж�
	UART_IT_RB   = (1 << 16),		//���ջ��������ж�
	UART_IT_ID   = (1 << 17),		//���տ���֡�ж�
	UART_IT_RO   = (1 << 24),		//������������ж�
	UART_IT_FE   = (1 << 25),		//����֡�����ж�
	UART_IT_PE   = (1 << 26),		//����У������ж�
	UART_IT_BDE  = (1 << 27),		//�����ʼ������ж�
	UART_IT_RBRE = (1 << 28),		//�����ջ�������ж�
	UART_IT_RBRO = (1 << 29),		//�����ջ�������ж�
} UART_TYPE_IT;

/* Interrupt Flag */
typedef enum {
	UART_FLAG_TB   = (1 << 0),		//���ͻ��������ж�
	UART_FLAG_TC   = (1 << 1),		//��������ж�
	UART_FLAG_TBWE = (1 << 8),		//���ͻ�������ж�
	UART_FLAG_TBWO = (1 << 9),		//���ͻ�������ж�
	UART_FLAG_RB   = (1 << 16),		//���ջ��������ж�
	UART_FLAG_ID   = (1 << 17),		//���տ���֡�ж�
	UART_FLAG_RO   = (1 << 24),		//������������ж�
	UART_FLAG_FE   = (1 << 25),		//����֡�����ж�
	UART_FLAG_PE   = (1 << 26),		//����У������ж�
	UART_FLAG_BDE  = (1 << 27),		//�����ʼ������ж�
	UART_FLAG_RBRE = (1 << 28),		//�����ջ�������ж�
	UART_FLAG_RBRO = (1 << 29),		//�����ջ�������ж�
} UART_TYPE_FLAG;

/* Interrupt Clear Flag */
typedef enum {
	UART_CLR_TC   = (1 << 1),		//��������ж�
	UART_CLR_TBWE = (1 << 8),		//���ͻ�������ж�
	UART_CLR_TBWO = (1 << 9),		//���ͻ�������ж�
	UART_CLR_ID   = (1 << 17),		//���տ���֡�ж�
	UART_CLR_RO   = (1 << 24),		//������������ж�
	UART_CLR_FE   = (1 << 25),		//����֡�����ж�
	UART_CLR_PE   = (1 << 26),		//����У������ж�
	UART_CLR_BDE  = (1 << 27),		//�����ʼ������ж�
	UART_CLR_RBRE = (1 << 28),		//�����ջ�������ж�
	UART_CLR_RBRO = (1 << 29),		//�����ջ�������ж�
} UART_CLR_IF;

/* Interrupt Mode */
typedef enum {
	UART_TBIM_Byte     = 0x0,		//�ֽ��ж�
	UART_TBIM_HalfWord = 0x1,		//�����ж�
	UART_TBIM_Word     = 0x2,		//���ж�
	UART_TBIM_Full     = 0x3,		//ȫ�ж�
} UART_TYPE_TRBIM;

/* Status */
typedef enum {
	UART_STA_TBOV   = (1 << 4),		//���ͻ��������״̬λ
	UART_STA_TXBUSY = (1 << 5),		//����״̬λ
	UART_STA_RBOV   = (1 << 12),	//���ջ��������״̬λ
	UART_STA_RXBUSY = (1 << 13),	//����״̬λ
	UART_STA_FER0   = (1 << 16),	//��ǰ��ȡBYTE0֡��ʽ����λ
	UART_STA_PER0   = (1 << 17),	//��ǰ��ȡBYTE0У�����λ
	UART_STA_FER1   = (1 << 18),	//��ǰ��ȡBYTE1֡��ʽ����λ
	UART_STA_PER1   = (1 << 19),	//��ǰ��ȡBYTE1У�����λ
	UART_STA_FER2   = (1 << 20),	//��ǰ��ȡBYTE2֡��ʽ����λ
	UART_STA_PER2   = (1 << 21),	//��ǰ��ȡBYTE2У�����λ
	UART_STA_FER3   = (1 << 22),	//��ǰ��ȡBYTE3֡��ʽ����λ
	UART_STA_PER3   = (1 << 23),	//��ǰ��ȡBYTE3У�����λ
} UART_TYPE_STA;


#define UART0_TxEnable()	(UART0->CON0.TXEN = 1)
#define UART1_TxEnable()	(UART1->CON0.TXEN = 1)
#define UART0_TxDisable()	(UART0->CON0.TXEN = 0)
#define UART1_TxDisable()	(UART1->CON0.TXEN = 0)
#define UART0_RxEnable()	(UART0->CON0.RXEN = 1)
#define UART1_RxEnable()	(UART1->CON0.RXEN = 1)
#define UART0_RxDisable()	(UART0->CON0.RXEN = 0)
#define UART1_RxDisable()	(UART1->CON0.RXEN = 0)

#define UART0_TxRst()		(UART0->CON0.TRST = 1)
#define UART1_TxRst()		(UART1->CON0.TRST = 1)
#define UART0_RxRst()		(UART0->CON0.RRST = 1)
#define UART1_RxRst()		(UART1->CON0.RRST = 1)


/*  Function */
void UART_Init(UART_TypeDef *UARTx, UART_InitStruType *UART_InitStruct);
void UART_AutoBaudConfig(UART_TypeDef *UARTx,UART_AUTO_BAUD_MODE mode);
void UART_BaudFreeConfig(UART_TypeDef *UARTx,UART_AUTO_BAUD_FREE_MODE mode);
void UART_ITConfig(UART_TypeDef *UARTx, UART_TYPE_IT UART_IT, TYPE_FUNCEN NewState);
void UART_TBIMConfig(UART_TypeDef *UARTx, UART_TYPE_TRBIM Type);
void UART_RBIMConfig(UART_TypeDef *UARTx, UART_TYPE_TRBIM Type);
void UART_SendByte(UART_TypeDef *UARTx, uint8_t data08);
void UART_SendHalfWord(UART_TypeDef *UARTx, uint16_t data16);
void UART_SendWord(UART_TypeDef *UARTx, uint32_t data32);
uint8_t UART_RecByte(UART_TypeDef *UARTx);
uint16_t UART_RecHalfWord(UART_TypeDef *UARTx);
uint32_t UART_RecWord(UART_TypeDef *UARTx);
FlagStatus UART_GetStatus(UART_TypeDef *UARTx, UART_TYPE_STA UART_Flag);
FlagStatus UART_GetFlagStatus(UART_TypeDef *UARTx, UART_TYPE_FLAG UART_Flag);
ITStatus UART_GetITStatus(UART_TypeDef *UARTx, UART_TYPE_IT UART_Flag);
void UART_ClearITPendingBit(UART_TypeDef *UARTx, UART_CLR_IF UART_Flag);

#endif
