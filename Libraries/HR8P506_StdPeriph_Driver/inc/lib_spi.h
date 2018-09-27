/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_spi.h
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  SPIģ��⺯��ͷ�ļ�
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#ifndef __LIBSPI_H__
#define __LIBSPI_H__

#include "HR8P506.h"
#include "type.h"

/* ���ݷ��ͽ��շ�ʽ */
typedef enum {
	SPI_RiseSendFallRec = 0x0,	//�����ط��ͣ��½��ؽ���
	SPI_FallSendRiseRec = 0x1,	//�½��ط��ͣ������ؽ���
	SPI_RiseRecFallSend = 0x2,	//�����ؽ��գ��½��ط���
	SPI_FallRecRiseSend = 0x3,	//�½��ؽ��գ������ط���
} SPI_TYPE_DFS;

/* ����ģʽ */
typedef enum {
	SPI_Mode_Master = 0x0,	//����ģʽ
	SPI_Mode_Slave  = 0x1,	//�Ӷ�ģʽ
} SPI_TYPE_MODE;

/* ��ʼ���ṹ�� */
typedef struct {
	uint32_t SPI_Freq;			//SPIƵ��
	SPI_TYPE_DFS SPI_Df;		//���ݸ�ʽ
	SPI_TYPE_MODE SPI_Mode;		//ͨѶģʽ
	uint8_t SPI_DW;				//����֡λ��
	TYPE_FUNCEN SPI_DelayRec;	//�ӳٽ���ʹ��
	TYPE_FUNCEN SPI_DelaySend;	//���ͼ��ʹ��
	uint8_t SPI_SendDelayPeroid;//���ͼ������
} SPI_InitStruType;

/* �ж�״̬��־λ */
typedef enum {
	SPI_Flag_TB    = (1 << 0),	//���ͻ��������жϱ�־
	SPI_Flag_RB    = (1 << 1),	//���ջ��������жϱ�־
	SPI_Flag_TE    = (1 << 2),	//���ʹ����жϱ�־�����Ӷ�ģʽ
	SPI_Flag_RO    = (1 << 3),	//���մ�������жϱ�־
	SPI_Flag_ID    = (1 << 4),	//����״̬�жϱ�־
	SPI_Flag_NSSIF = (1 << 5),	//Ƭѡ�仯�жϱ�־
	SPI_Flag_TBWE  = (1 << 6),	//��������д�����жϱ�־
	SPI_Flag_NSS   = (1 << 7),	//Ƭѡ��־λ
	SPI_Flag_TBEF0 = (1 << 8),	//TB0�ձ�־λ
	SPI_Flag_TBEF1 = (1 << 9),	//TB1�ձ�־λ
	SPI_Flag_TBEF2 = (1 << 10),	//TB2�ձ�־λ
	SPI_Flag_TBEF3 = (1 << 11),	//TB3�ձ�־λ
	SPI_Flag_RBFF0 = (1 << 12),	//RB0����־λ
	SPI_Flag_RBFF1 = (1 << 13),	//RB1����־λ
	SPI_Flag_RBFF2 = (1 << 14),	//RB2����־λ
	SPI_Flag_RBFF3 = (1 << 15),	//RB3����־λ
	SPI_Flag_IDLE  = (1 << 16),	//���б�־λ
	SPI_Flag_TMS   = (1 << 17),	//֡���ͼ��״̬��־λ
}SPI_TYPE_FLAG;

/* ���ͻ�������/���ջ��������ж����� */
typedef enum {
	SPI_IType_BYTE     = 0x0,	//�ֽ��ж�
	SPI_IType_HALFWORD = 0x1,	//�����ж�
	SPI_IType_WORD     = 0x2,	//���ж�
} SPI_TYPE_TRBIM;

/* �ж�ʹ�ܱ�־λ */
typedef enum {
	SPI_IT_TB   = (1 << 0),		//���ͻ��������ж�
	SPI_IT_RB   = (1 << 1),		//���ջ��������ж�
	SPI_IT_TE   = (1 << 2),		//�������ݴ����ж�
	SPI_IT_RO   = (1 << 3),		//���մ�������ж�
	SPI_IT_ID   = (1 << 4),		//����״̬�ж�
	SPI_IT_NSS  = (1 << 5),		//Ƭѡ�仯�ж�
	SPI_IT_TBWE = (1 << 6),		//��������д�����ж�
} SPI_TYPE_IT;

/* ����жϱ�־λ */
typedef enum {
	SPI_CLR_TE   = (1 << 2),	//���ʹ����жϱ�־�����Ӷ�ģʽ
	SPI_CLR_RO   = (1 << 3),	//���մ�������жϱ�־
	SPI_CLR_ID   = (1 << 4),	//����״̬�жϱ�־
	SPI_CLR_NSS  = (1 << 5),	//Ƭѡ�仯�жϱ�־
	SPI_CLR_TBWE = (1 << 6),	//��������д�����жϱ�־
} SPI_CLR_IF;

/* SPI״̬��־λ */
typedef enum {
	SPI_STA_NSS   = (1 << 7),	//Ƭѡ��־λ
	SPI_STA_TBEF0 = (1 << 8),	//TB0�ձ�־λ
	SPI_STA_TBEF1 = (1 << 9),	//TB1�ձ�־λ
	SPI_STA_TBEF2 = (1 << 10),	//TB2�ձ�־λ
	SPI_STA_TBEF3 = (1 << 11),	//TB3�ձ�־λ
	SPI_STA_RBFF0 = (1 << 12),	//RB0����־λ
	SPI_STA_RBFF1 = (1 << 13),	//RB1����־λ
	SPI_STA_RBFF2 = (1 << 14),	//RB2����־λ
	SPI_STA_RBFF3 = (1 << 15),	//RB3����־λ
	SPI_STA_IDLE  = (1 << 16),	//����״̬��־λ
} SPI_TYPE_STA;


/* SPI0 */
#define SPI0_Enable()		(SPI0->CON.EN  = 1)
#define SPI0_Disable()		(SPI0->CON.EN  = 0)
#define SPI0_RecEnable()	(SPI0->CON.REN = 1)
#define SPI0_RecDisable()	(SPI0->CON.REN = 0)
#define SPI0_Rst()		(SPI0->CON.RST = 1)

/* SPI1 */
#define SPI1_Enable()		(SPI1->CON.EN  = 1)
#define SPI1_Disable()		(SPI1->CON.EN  = 0)
#define SPI1_RecEnable()	(SPI1->CON.REN = 1)
#define SPI1_RecDisable()	(SPI1->CON.REN = 0)
#define SPI1_Rst()		(SPI1->CON.RST = 1)


/* SPI function */
void SPI_Init(SPI_TypeDef *SPIx, SPI_InitStruType *SPI_InitStruct);
void SPI_ITConfig(SPI_TypeDef *SPIx, SPI_TYPE_IT SPI_IE, TYPE_FUNCEN NewState);
void SPI_DataFormatConfig(SPI_TypeDef *SPIx, SPI_TYPE_DFS Type);
void SPI_SendByte(SPI_TypeDef *SPIx, uint8_t Temp);
void SPI_SendHalfWord(SPI_TypeDef *SPIx, uint16_t Temp);
void SPI_SendWord(SPI_TypeDef *SPIx, uint32_t Temp);
uint8_t SPI_RecByte(SPI_TypeDef *SPIx);
uint16_t SPI_RecHalfWord(SPI_TypeDef *SPIx);
uint32_t SPI_RecWord(SPI_TypeDef *SPIx);
void SPI_TBIMConfig(SPI_TypeDef *SPIx, SPI_TYPE_TRBIM Type);
void SPI_RBIMConfig(SPI_TypeDef *SPIx, SPI_TYPE_TRBIM Type);
FlagStatus SPI_GetFlagStatus(SPI_TypeDef *SPIx, SPI_TYPE_FLAG Flag);
ITStatus SPI_GetITStatus(SPI_TypeDef *SPIx, SPI_TYPE_IT Flag);
FlagStatus SPI_GetStatus(SPI_TypeDef *SPIx, SPI_TYPE_STA Flag);
void SPI_ClearITPendingBit(SPI_TypeDef *SPIx, SPI_CLR_IF Flag);
void Clear_TBW(SPI_TypeDef *SPIx);
void Clear_RBR(SPI_TypeDef *SPIx);

#endif	/* end of file */
