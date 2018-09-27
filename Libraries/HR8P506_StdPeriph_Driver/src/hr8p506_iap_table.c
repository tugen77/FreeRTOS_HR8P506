/**
 ******************************************************************************
 * @file    hr8p506_iap_table.c
 * @author  
 * @version V1.0.0
 * @date    22-JAN-2014
 * @brief   This file provides all the IAP_TABLE firmware functions.
 ******************************************************************************
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, ICHAIER SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2014 ICHaier</center></h2>
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "hr8p506_iap_table.h"

/** @addtogroup HR8P506_HrPeriph_Driver
 * @{
 */

/** @defgroup IAP_TABLE 
 * @brief IAP_TABLE driver modules
 * @{
 */

/** @defgroup IAP_TABLE_Private_TypesDefinitions
 * @{
 */

/**
 * @}
 */

/** @defgroup IAP_TABLE_Private_Defines
 * @{
 */

/**
 * @}
 */

/** @defgroup IAP_TABLE_Private_Macros
 * @{
 */

/**
 * @}
 */

/** @defgroup IAP_TABLE_Private_Variables
 * @{
 */

/**
 * @}
 */

/** @defgroup IAP_TABLE_Private_FunctionPrototypes
 * @{
 */

/**
 * @}
 */

/** @defgroup IAP_TABLE_Private_Functions
 * @{
 */



/**
 * @brief  IAP ҳ�������.�ص��̻���ROM�еĳ���
 * @param  address: ҳ�׵�ַ
 * @retval None
 */
ErrorStatus IAP_PageErase(uint32_t address)
{
	IAP_PE IAPPageErase   = (IAP_PE)(*(uint32_t *)IAP_PageErase_addr);
		ErrorStatus result;
		__ASM("CPSID i");
		result = (*IAPPageErase)(address);
		__ASM("CPSIE i");
		return	result;
}

/**
 * @brief  IAP �����Ա��.�ص��̻���ROM�еĳ���
 * @param  address: ����׵�ַ
 * @param  data: �������
 * @retval None
 */
ErrorStatus IAP_WordProgram(uint32_t address, uint32_t data)
{
	IAP_WP IAPWordProgram = (IAP_WP)(*(uint32_t *)IAP_WordProgram_addr);
		ErrorStatus result;
		__ASM("CPSID i");
		result = (*IAPWordProgram)( address,  data);
		__ASM("CPSIE i");
		return  result;
}

/**
 * @brief  IAP �����Ա��.�ص��̻���ROM�еĳ���
 * @param  address: ����׵�ַ
 * @param  data[]: �������
 * @param  length: ������ݳ��ȣ��ֽڣ�
 * @param  address: ���ҳ�Ƿ��Ȳ���
 *     @arg 0: ������
 *     @arg 1: ����
 * @retval None
 */
ErrorStatus IAP_PageProgram(uint32_t address, uint32_t data[], uint32_t length, uint32_t erase)  //@0x100001c5
{
	IAP_PP IAPPageProgram = (IAP_PP)(*(uint32_t *)IAP_PageProgram_addr);
		ErrorStatus result;
		__ASM("CPSID i");
		result = (*IAPPageProgram)(address,data,length,erase);
		__ASM("CPSIE i");
		return  result;
}
/*************************************
  ��������IARead
  ��  ����Flash��
  ����ֵ���ڴ��ַ--��ȡ���ݵĴ�ŵ�ַ
  Flash��ַ
  ��ȡ���ݵĳ��ȣ���λΪ�֣�4�ֽڣ�
  ����ֵ���ɹ�/ʧ��
 **************************************/
ErrorStatus IAPRead(uint32_t *Ram_Addr, uint32_t Flash_Addr, uint8_t Len)
{
	uint8_t i;
	uint32_t *ram_addr;
	const uint32_t *flash_addr;

	ram_addr = Ram_Addr;
	flash_addr = (const uint32_t *)Flash_Addr;

	if (Len == 0)
		return ERROR;

	for (i = 0; i < Len; ++i) {
		*ram_addr = *flash_addr;
		++ram_addr;
		++flash_addr;
	}

	return SUCCESS;
}

/******************* (C) COPYRIGHT 2014 ICHaier *****END OF FILE****/

