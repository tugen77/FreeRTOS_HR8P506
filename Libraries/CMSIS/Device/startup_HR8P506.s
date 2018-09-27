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
    
RegInit:
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


IP_CAL_LOAD:
				PUSH    {LR}
				LDR     R2, =0xFFFFFFFF
				LDR     R1, [R0]
				CMP     R1, R2
				BNE     IP_CAL_VERIFY    
				LDR     R1, [R0]         
				CMP     R1, R2
				BNE     IP_CAL_VERIFY    

				B       IP_CAL_EMPTY     

IP_CAL_VERIFY:
				LDR      R5, =0x00000003    
				LDR      R4, =0x000000FF
IP_CAL_VERIFY_LOOP:
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

IP_LOAD_OK:
				STR      R1, [R7]

IP_CAL_EMPTY:
				POP      {PC}


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
  
  /* External Interrupts */
  .word PINT0_IRQHandler          /* 16, PINT0 IRQHandler */
  .word PINT1_IRQHandler          /* 17, PINT1 IRQHandler */
  .word PINT2_IRQHandler          /* 18, PINT2 IRQHandler */
  .word PINT3_IRQHandler          /* 19, PINT3 IRQHandler */
  .word PINT4_IRQHandler          /* 20, PINT4 IRQHandler */
  .word PINT5_IRQHandler          /* 21, PINT5 IRQHandler */
  .word PINT6_IRQHandler          /* 22, PINT6 IRQHandler */
  .word PINT7_IRQHandler          /* 23, PINT7 IRQHandler */
  .word T16N0_IRQHandler          /* 24, T16N0 IRQHandler */
  .word T16N1_IRQHandler          /* 25, T16N1 IRQHandler */
  .word T16N2_IRQHandler          /* 26, T16N2 IRQHandler */
  .word T16N3_IRQHandler          /* 27, T16N3 IRQHandler */
  .word T32N0_IRQHandler          /* 28, T32N0 IRQHandler */ 
  .word 0
  .word 0
  .word 0
  .word WDT_IRQHandler            /* 32, WDT IRQHandler    */
  .word RTC_IRQHandler            /* 33, RTC IRQHandler    */
  .word KINT_IRQHandler           /* 34, KINT IRQHandler   */
  .word ADC_IRQHandler            /* 35, ADC IRQHandler    */
  .word 0 
  .word LVD_IRQHandler            /* 37, LVD IRQHandler    */
  .word PLLLK_IRQHandler          /* 38, PLLLK IRQHandler  */
  .word UART0_IRQHandler          /* 39, UART0 IRQHandler  */
  .word UART1_IRQHandler          /* 40, UART1 IRQHandler  */
  .word EUART0_IRQHandler         /* 41, EUART0 IRQHandler */
  .word 0 
  .word SPI0_IRQHandler           /* 43, SPI0 IRQHandler   */
  .word SPI1_IRQHandler           /* 44, SPI1 IRQHandler   */
  .word I2C0_IRQHandler           /* 45, I2C0 IRQHandler   */
  .word 0
  .word CCM_IRQHandler            /* 47, CCM IRQHandler    */

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

  .weak PINT0_IRQHandler
  .thumb_set PINT0_IRQHandler,Default_Handler

  .weak PINT1_IRQHandler
  .thumb_set PINT1_IRQHandler,Default_Handler
  
  .weak PINT2_IRQHandler
  .thumb_set PINT2_IRQHandler,Default_Handler
  
  .weak PINT3_IRQHandler
  .thumb_set PINT3_IRQHandler,Default_Handler
  
  .weak PINT4_IRQHandler
  .thumb_set PINT4_IRQHandler,Default_Handler
  
  .weak PINT5_IRQHandler
  .thumb_set PINT5_IRQHandler,Default_Handler
  
  .weak PINT6_IRQHandler
  .thumb_set PINT6_IRQHandler,Default_Handler
  
  .weak PINT7_IRQHandler
  .thumb_set PINT7_IRQHandler,Default_Handler
  
  .weak T16N0_IRQHandler
  .thumb_set T16N0_IRQHandler,Default_Handler
  
  .weak T16N1_IRQHandler
  .thumb_set T16N1_IRQHandler,Default_Handler
  
  .weak T16N2_IRQHandler
  .thumb_set T16N2_IRQHandler,Default_Handler
  
  .weak T16N3_IRQHandler
  .thumb_set T16N3_IRQHandler,Default_Handler
  
  .weak T32N0_IRQHandler
  .thumb_set T32N0_IRQHandler,Default_Handler
   
  .weak WDT_IRQHandler
  .thumb_set WDT_IRQHandler,Default_Handler
  
  .weak RTC_IRQHandler
  .thumb_set RTC_IRQHandler,Default_Handler
  
  .weak KINT_IRQHandler
  .thumb_set KINT_IRQHandler,Default_Handler
  
  .weak ADC_IRQHandler
  .thumb_set ADC_IRQHandler,Default_Handler
  
  .weak LVD_IRQHandler
  .thumb_set LVD_IRQHandler,Default_Handler
  
  .weak PLLLK_IRQHandler
  .thumb_set PLLLK_IRQHandler,Default_Handler
  
  .weak UART0_IRQHandler
  .thumb_set UART0_IRQHandler,Default_Handler
  
  .weak UART1_IRQHandler
  .thumb_set UART1_IRQHandler,Default_Handler
  
  .weak EUART0_IRQHandler
  .thumb_set EUART0_IRQHandler,Default_Handler
  
  .weak SPI0_IRQHandler
  .thumb_set SPI0_IRQHandler,Default_Handler
  
  .weak SPI1_IRQHandler
  .thumb_set SPI1_IRQHandler,Default_Handler
  
  .weak I2C0_IRQHandler
  .thumb_set SPI1_IRQHandler,Default_Handler
  
  .weak CCM_IRQHandler
  .thumb_set CCM_IRQHandler,Default_Handler

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

