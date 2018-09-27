/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  lib_scu.c
 *��  ��:  ESM Application Team 
 *��  ��:  V1.01
 *��  ��:  2016/11/01
 *��  ��:  SCUģ��⺯��
 *��  ע:  ������HRSDK-GDB-8P506
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
#include "lib_scu.h"

/***************************************************************
  ��������SCU_NMISelect
  ��  ��������NMI���������ж�
  ����ֵ�����������ж�
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void SCU_NMISelect(SCU_TYPE_NMICS NMI_Type)
{
	SCU_RegUnLock();
	SCU->NMICON.NMICS = NMI_Type;
	SCU_RegLock() ;
	return;
}

/***************************************************************
  ��������SCU_GetPWRCFlagStatus
  ��  ������ȡPWRC��λ״̬�Ĵ�����־λ״̬
  ����ֵ��PWRC�Ĵ�����־λ
  ���ֵ����
  ����ֵ��RESET/SET
 ***************************************************************/
FlagStatus  SCU_GetPWRCFlagStatus(SCU_TYPE_PWRC PWRC_Flag)
{
	FlagStatus bitstatus = RESET;
	SCU_RegUnLock();
	if((SCU->PWRC.Word & (uint32_t)PWRC_Flag) != (uint32_t)RESET)
		bitstatus = SET;
	SCU_RegLock() ;
	return  bitstatus;
}

/***************************************************************
  ��������SCU_ClearPWRCFlagBit
  ��  �������PWRC��λ״̬�Ĵ�����־λ
  ����ֵ��PWRC�Ĵ�����־λ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void SCU_ClearPWRCFlagBit(SCU_TYPE_PWRC PWRC_Flag)
{
	SCU_RegUnLock() ;
	SCU->PWRC.Word &= ~((uint32_t)PWRC_Flag);
	SCU_RegLock() ;
	return;
}

/***************************************************************
  ��������SCU_GetLVDFlagStatus
  ��  ������ȡLVDD�Ĵ�����־λ״̬
  ����ֵ��LVD�Ĵ�����־λ
  ���ֵ����
  ����ֵ��RESET/SET
 ***************************************************************/
FlagStatus  SCU_GetLVDFlagStatus(SCU_TYPE_LVDCON LVD_Flag)
{
	FlagStatus bitstatus = RESET;
	SCU_RegLock() ;
	if((SCU->LVDCON.Word & (uint32_t)LVD_Flag) != (uint32_t)RESET)
		bitstatus = SET;

	return  bitstatus;
}

/***************************************************************
  ��������SCU_SysClkSelect
  ��  ����ѡ��ϵͳʱ��
  ����ֵ��ʱ��Դ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void SCU_SysClkSelect(SCU_TYPE_SYSCLK Sysclk)
{
	SCU_RegUnLock() ;
	SCU->SCLKEN0.CLK_SEL = Sysclk;
	SCU_RegLock() ;
	return;
}

/***************************************************************
  ��������SCU_GetSysClk
  ��  ������ȡϵͳʱ��Դ
  ����ֵ����
  ���ֵ����
  ����ֵ��ϵͳʱ��Դ
 ***************************************************************/
SCU_TYPE_SYSCLK SCU_GetSysClk(void)
{
	return (SCU_TYPE_SYSCLK)(SCU->SCLKEN0.CLK_SEL);
}

/***************************************************************
  ��������SCU_OpenXTAL
  ��  ��: �����ⲿʱ��
  ����ֵ����
  ���ֵ����
  ����ֵ��ϵͳʱ��Դ
 ***************************************************************/
void SCU_OpenXTAL(void)
{
	SCU_RegUnLock();
	SCU->SCLKEN1.XTAL_EN = 1;
	SCU->SCLKEN0.XTAL_LP = 0;
	while(SCU->SCLKEN1.XTAL_RDY == 0); //�ȴ��ⲿʱ���ȶ�
	SCU_RegLock() ;
}

/***************************************************************
  ��������DeviceClockAllEnable
  ��  ��������������ʱ��
  ����ֵ����
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void DeviceClockAllEnable(void)
{
	uint32_t prot_tmp;

	prot_tmp = SCU->PROT.PROT;
	if(prot_tmp != 0)   	//д������
		SCU_RegUnLock();  	//����

	SCU->PCLKEN.Word = 0xFFFFFFFF;     //����������ʱ��

	if(prot_tmp != 0)   	//д������
		SCU_RegLock();   	//��д����

	return;
}

/***************************************************************
  ��������DeviceClockAllDisable
  ��  �����ر���������ʱ��
  ����ֵ����
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void DeviceClockAllDisable(void)
{
	uint32_t prot_temp;

	prot_temp = SCU->PROT.PROT;
	if(prot_temp != 0)   //д������
		SCU_RegUnLock();  //����

	SCU->PCLKEN.Word = 0x00000000;     //�ر���������ʱ�ӣ�scu�޷��ر�

	if(prot_temp != 0)   //д������
		SCU_RegLock();   //��д����

	return;
}

/***************************************************************
  ��������DeviceClock_Config
  ��  �������������Ƿ�ʹ��
  ����ֵ��tppe_periph ��ѡ����������� ��NewState ��Disable��Enable
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void DeviceClock_Config(SUC_TYPE_Periph tppe_periph ,TYPE_FUNCEN NewState )
{
	SCU_RegUnLock();
	if(NewState != Disable)
	{
		SCU->PCLKEN.Word |= tppe_periph;
	}
	else
	{
		SCU->PCLKEN.Word &= ~tppe_periph;
	}
	SCU_RegLock(); 
	return;
}


/***************************************************************
  ��������PLLClock_Config
  ��  ����PLLʱ������,������PLLʱ��Ϊϵͳʱ��
  ����ֵ��pll_en:�Ƿ���PLL��pll_origin��pllʱ��Դѡ��pll_out��pll���Ƶ��ѡ��sys_pll��ϵͳʱ���Ƿ�ʹ��PLLʱ��
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void PLLClock_Config(TYPE_FUNCEN pll_en , SCU_PLL_Origin  pll_origin ,SCU_PLL_Out pll_out,TYPE_FUNCEN sys_pll )
{
	if(pll_en == Disable)  //���PLL����Ϊ��ֹ����ֱ�ӽ�ֹPLL��������
	{
		SCU->SCLKEN1.PLL_EN = 0;
		return;
	}

	SCU_RegUnLock();
	if((pll_origin==SCU_PLL_IN4M )|| (pll_origin==SCU_PLL_IN16M)) //���ʹ���ڲ�����ʱ�ӣ��迪���ڲ�����ʱ��
	{
		if(SCU->SCLKEN1.HRC_RDY == 0)
		{
			SCU->SCLKEN1.HRC_EN =1;
			while(SCU->SCLKEN1.HRC_RDY == 0);  //�ȴ�HRC����
		}			

	}
	if((pll_origin==SCU_PLL_OUT4M )|| (pll_origin==SCU_PLL_OUT8M) ||(pll_origin==SCU_PLL_OUT16M )|| (pll_origin==SCU_PLL_OUT32K) )//���ʹ���ⲿʱ�ӣ��迪���ⲿʱ��
	{
		if(SCU->SCLKEN1.XTAL_RDY == 0)
		{
			SCU->SCLKEN1.XTAL_EN =1;
			SCU->SCLKEN0.XTAL_LP = 0;
			while(SCU->SCLKEN1.XTAL_RDY == 0);  //�ȴ�XTAL����
		}			
	}

	switch(pll_origin)
	{
		case SCU_PLL_IN4M:
			SCU->SCLKEN1.PLL_REF_SEL= 0x00;
			break;
		case SCU_PLL_IN16M:
			SCU->SCLKEN1.PLL_REF_SEL= 0x02;
			break;
		case SCU_PLL_IN32K:
			SCU->SCLKEN1.PLL_REF_SEL= 0x03;
			break;
		case SCU_PLL_OUT4M:
			SCU->SCLKEN1.PLL_REF_SEL= 0x04;
			break;
		case SCU_PLL_OUT8M:
			SCU->SCLKEN1.PLL_REF_SEL= 0x05;
			break;
		case SCU_PLL_OUT16M:
			SCU->SCLKEN1.PLL_REF_SEL= 0x06;
			break;
		case SCU_PLL_OUT32K:
			SCU->SCLKEN1.PLL_REF_SEL= 0x07;
			break;
		default:
			break;
	}
	SCU->SCLKEN1.PLL_48M_SEL = pll_out;   //����PLL���Ϊ32��48Mhz
	SCU->SCLKEN1.PLL_BYLOCK = 0;

	SCU->SCLKEN1.PLL_EN = 1;
	while(SCU->SCLKEN1.PLL_RDY == 0);
	if(sys_pll == Enable)
	{
		SCU->SCLKEN0.PLL_MUX = 1;
	}
	else
	{
		SCU->SCLKEN0.PLL_MUX = 0;
	}


	SCU_RegLock(); 
}


/***************************************************************
  ��������SCU_MultTimerEnable
  ��  �������ʱ��ͬʱ����(T16N0/1/2/3,P32N0)
  ����ֵ��SCU_TimerMask��������T16N0/1/2/3��T32N0���������
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void SCU_MultTimerEnable(SCU_TIMEREN_Typedef SCU_TimerMask)
{
	SCU_RegUnLock();
	SCU->TIMEREN.Word = SCU_TimerMask.Word;
	SCU_RegLock();
}


/***************************************************************
  ��������SCU_MultTimerDisable
  ��  �������ʱ��ͬʱ�ر�(T16N0/1/2/3,P32N0)
  ����ֵ��SCU_TimerMask��������T16N0/1/2/3��T32N0���������
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void SCU_MultTimerDisable(SCU_TIMERDIS_Typedef SCU_TimerMask)
{
	SCU_RegUnLock();
	SCU->TIMERDIS.Word = SCU_TimerMask.Word;
	SCU_RegLock();
}



