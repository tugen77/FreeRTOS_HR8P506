/**
  ******************************************************************************
  * @file      startup_HR8P506.s
  * @author    Eric Qiu <jmqiu@icwiser.com>
  * @version   V1.0.0
  * @date      25-March-2018
  * @brief     HR8P506 Devices vector table for Atollic toolchain.
  ******************************************************************************
  */

  .syntax unified
  .cpu cortex-m0
  .fpu softvfp
  .thumb

.global g_pfnVectors
.global Default_Handler

/* start address for the initialization values of the .data section.
defined in linker script */
.word _sidata
/* start address for the .data section. defined in linker script */
.word _sdata
/* end address for the .data section. defined in linker script */
.word _edata
/* start address for the .bss section. defined in linker script */
.word _sbss
/* end address for the .bss section. defined in linker script */
.word _ebss

/**
 * @brief  This is the code that gets called when the processor first
 *          starts execution following a reset event. Only the absolutely
 *          necessary set is performed, after which the application
 *          supplied main() routine is called.
 * @param  None
 * @retval : None
*/

  .section .text.Reset_Handler
  .weak Reset_Handler
  .type Reset_Handler, %function
Reset_Handler:
  ldr   r0, =_estack
  mov   sp, r0          /* set stack pointer */

/* Copy the data segment initializers from flash to SRAM */
  movs r1, #0
  b LoopCopyDataInit

CopyDataInit:
  ldr r3, =_sidata
  ldr r3, [r3, r1]
  str r3, [r0, r1]
  adds r1, r1, #4

LoopCopyDataInit:
  ldr r0, =_sdata
  ldr r3, =_edata
  adds r2, r0, r1
  cmp r2, r3
  bcc CopyDataInit
  ldr r2, =_sbss
  b LoopFillZerobss
/* Zero fill the bss segment. */
FillZerobss:
  movs r3, #0
  str  r3, [r2]
  adds r2, r2, #4


LoopFillZerobss:
  ldr r3, = _ebss
  cmp r2, r3
  bcc FillZerobss
  
  bl  RegInit

/* Call the clock system intitialization function.*/
    bl  SystemInit
/* Call static constructors */
    bl __libc_init_array
/* Call the application's entry point.*/
  bl main
  
LoopForever:
    b LoopForever
    
RegInit://   		PROC
				PUSH	{LR}
				NOP
				NOP
				NOP
				NOP
				NOP
				
				LDR     R0, =0x40000080  
				LDR     R1, =0xAA559669
				STR     R1, [R0]

				LDR     R0, =0x00100124   
				LDR     R7, =0x400000A4   
				BL      IP_CAL_LOAD

				LDR     R0, =0x00100128   
				LDR     R7, =0x400000A8  
				BL      IP_CAL_LOAD

				LDR     R0, =0x0010012C   
				LDR     R7, =0x4000009C   
				BL      IP_CAL_LOAD

				LDR     R0, =0x00100130  
				LDR     R7, =0x400000A0  
				BL      IP_CAL_LOAD

				LDR     R0, =0x40000080  
				LDR     R1, =0x00000000
				STR     R1, [R0]

				POP     {PC}


IP_CAL_LOAD
				PUSH    {LR}
				LDR     R2, =0xFFFFFFFF
				LDR     R1, [R0]
				CMP     R1, R2
				BNE     IP_CAL_VERIFY    
				LDR     R1, [R0]         
				CMP     R1, R2
				BNE     IP_CAL_VERIFY    

				B       IP_CAL_EMPTY     

IP_CAL_VERIFY
				LDR      R5, =0x00000003    
				LDR      R4, =0x000000FF
IP_CAL_VERIFY_LOOP
				MOVS     R2, R1
				ANDS     R2, R4         

				LSRS     R3, R1, #8
				ANDS     R3, R4
				ADDS     R2, R3        

				LSRS     R3, R1, #16
				ANDS     R3, R4
				ADDS     R2, R3        
				ANDS     R2, R4

				LSRS     R3, R1, #24   

				CMP      R2, R3        
				BEQ      IP_LOAD_OK
				SUBS     R5, #1
				BEQ      IP_CAL_EMPTY    
				LDR      R1, [R0]         
				B        IP_CAL_VERIFY_LOOP

IP_LOAD_OK
				STR      R1, [R7]

IP_CAL_EMPTY
				POP      {PC}

				ALIGN
				LTORG
				ENDP


.size Reset_Handler, .-Reset_Handler

/**
 * @brief  This is the code that gets called when the processor receives an
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 *
 * @param  None
 * @retval : None
*/
    .section .text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
  b Infinite_Loop
  .size Default_Handler, .-Default_Handler
/******************************************************************************
*
* The minimal vector table for a Cortex M0.  Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
*
******************************************************************************/
   .section .isr_vector,"a",%progbits
  .type g_pfnVectors, %object
  .size g_pfnVectors, .-g_pfnVectors


g_pfnVectors:
  .word _estack
  .word Reset_Handler
  .word NMI_Handler
  .word HardFault_Handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word SVC_Handler
  .word 0
  .word 0
  .word PendSV_Handler
  .word SysTick_Handler
  .word WWDG_IRQHandler
  .word PVD_IRQHandler
  .word RTC_IRQHandler
  .word FLASH_IRQHandler
  .word RCC_IRQHandler
  .word EXTI0_1_IRQHandler
  .word EXTI2_3_IRQHandler
  .word EXTI4_15_IRQHandler
  .word TS_IRQHandler
  .word DMA1_Channel1_IRQHandler
  .word DMA1_Channel2_3_IRQHandler
  .word DMA1_Channel4_5_IRQHandler
  .word ADC1_COMP_IRQHandler 
  .word TIM1_BRK_UP_TRG_COM_IRQHandler
  .word TIM1_CC_IRQHandler
  .word TIM2_IRQHandler
  .word TIM3_IRQHandler
  .word TIM6_DAC_IRQHandler
  .word 0  
  .word TIM14_IRQHandler
  .word TIM15_IRQHandler
  .word TIM16_IRQHandler
  .word TIM17_IRQHandler
  .word I2C1_IRQHandler
  .word I2C2_IRQHandler
  .word SPI1_IRQHandler
  .word SPI2_IRQHandler
  .word USART1_IRQHandler
  .word USART2_IRQHandler
  .word 0
  .word CEC_IRQHandler
  .word 0

/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************/

  .weak NMI_Handler
  .thumb_set NMI_Handler,Default_Handler

  .weak HardFault_Handler
  .thumb_set HardFault_Handler,Default_Handler

  .weak SVC_Handler
  .thumb_set SVC_Handler,Default_Handler

  .weak PendSV_Handler
  .thumb_set PendSV_Handler,Default_Handler

  .weak SysTick_Handler
  .thumb_set SysTick_Handler,Default_Handler

  .weak WWDG_IRQHandler
  .thumb_set WWDG_IRQHandler,Default_Handler

  .weak PVD_IRQHandler
  .thumb_set PVD_IRQHandler,Default_Handler
  
  .weak RTC_IRQHandler
  .thumb_set RTC_IRQHandler,Default_Handler
  
  .weak FLASH_IRQHandler
  .thumb_set FLASH_IRQHandler,Default_Handler
  
  .weak RCC_IRQHandler
  .thumb_set RCC_IRQHandler,Default_Handler
  
  .weak EXTI0_1_IRQHandler
  .thumb_set EXTI0_1_IRQHandler,Default_Handler
  
  .weak EXTI2_3_IRQHandler
  .thumb_set EXTI2_3_IRQHandler,Default_Handler
  
  .weak EXTI4_15_IRQHandler
  .thumb_set EXTI4_15_IRQHandler,Default_Handler
  
  .weak TS_IRQHandler
  .thumb_set TS_IRQHandler,Default_Handler
  
  .weak DMA1_Channel1_IRQHandler
  .thumb_set DMA1_Channel1_IRQHandler,Default_Handler
  
  .weak DMA1_Channel2_3_IRQHandler
  .thumb_set DMA1_Channel2_3_IRQHandler,Default_Handler
  
  .weak DMA1_Channel4_5_IRQHandler
  .thumb_set DMA1_Channel4_5_IRQHandler,Default_Handler
  
  .weak ADC1_COMP_IRQHandler
  .thumb_set ADC1_COMP_IRQHandler,Default_Handler
   
  .weak TIM1_BRK_UP_TRG_COM_IRQHandler
  .thumb_set TIM1_BRK_UP_TRG_COM_IRQHandler,Default_Handler
  
  .weak TIM1_CC_IRQHandler
  .thumb_set TIM1_CC_IRQHandler,Default_Handler
  
  .weak TIM2_IRQHandler
  .thumb_set TIM2_IRQHandler,Default_Handler
  
  .weak TIM3_IRQHandler
  .thumb_set TIM3_IRQHandler,Default_Handler
  
  .weak TIM6_DAC_IRQHandler
  .thumb_set TIM6_DAC_IRQHandler,Default_Handler
  
  .weak TIM14_IRQHandler
  .thumb_set TIM14_IRQHandler,Default_Handler
  
  .weak TIM15_IRQHandler
  .thumb_set TIM15_IRQHandler,Default_Handler
  
  .weak TIM16_IRQHandler
  .thumb_set TIM16_IRQHandler,Default_Handler
  
  .weak TIM17_IRQHandler
  .thumb_set TIM17_IRQHandler,Default_Handler
  
  .weak I2C1_IRQHandler
  .thumb_set I2C1_IRQHandler,Default_Handler
  
  .weak I2C2_IRQHandler
  .thumb_set I2C2_IRQHandler,Default_Handler
  
  .weak SPI1_IRQHandler
  .thumb_set SPI1_IRQHandler,Default_Handler
  
  .weak SPI2_IRQHandler
  .thumb_set SPI2_IRQHandler,Default_Handler
  
  .weak USART1_IRQHandler
  .thumb_set USART1_IRQHandler,Default_Handler
  
  .weak USART2_IRQHandler
  .thumb_set USART2_IRQHandler,Default_Handler
  
  .weak CEC_IRQHandler
  .thumb_set CEC_IRQHandler,Default_Handler

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

