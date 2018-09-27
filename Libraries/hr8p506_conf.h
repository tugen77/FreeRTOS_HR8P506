/**
  ******************************************************************************
  * @file    stm32F0xx_conf.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    23-March-2012
  * @brief   Library configuration file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HR8P506_CONF_H
#define __HR8P506_CONF_H

/* Includes ------------------------------------------------------------------*/
/* Comment the line below to disable peripheral header file inclusion */
/* #include "stm32f0xx_adc.h" */
#include "hr8p506_iap_table.h" 
#include "lib_adc.h" 
#include "lib_config.h"
#include "lib_euart.h"
#include "lib_gpio.h" 
#include "lib_iic.h" 
#include "lib_lcd.h"
#include "lib_led.h" 
#include "lib_printf.h" 
#include "lib_rtc.h"
#include "lib_scs.h" 
#include "lib_scu.h" 
#include "lib_spi.h"
#include "lib_timer.h"
#include "lib_uart.h" 
#include "lib_wdt.h" 
#include "type.h" 

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Uncomment the line below to expanse the "assert_param" macro in the 
   Standard Peripheral Library drivers code */
/* #define USE_FULL_ASSERT    1 */
/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports 
  *         the name of the source file and the source line number of the call 
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

#endif /* __HR8P506_CONF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
