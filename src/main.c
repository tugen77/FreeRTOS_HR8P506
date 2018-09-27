#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "leds.h"
#include "uart.h"

void blinky_task1()
{
	while(1)
	{
		ledsAct(LED_RED, ACT_ON);
		vTaskDelay(200);
		ledsAct(LED_RED, ACT_OFF);
		vTaskDelay(500);
	}
}

void blinky_task2()
{
	while(1)
	{
		ledsAct(LED_GREEN, ACT_ON);
		vTaskDelay(100);
		ledsAct(LED_GREEN, ACT_OFF);
		vTaskDelay(300);
	}
}

int main(void)
{
	ledsInit();
	Uart0Init(9600);  

    xTaskCreate(blinky_task1,
                (const char *)"blinky_task1",
                configMINIMAL_STACK_SIZE,
                NULL,                 /* pvParameters */
                tskIDLE_PRIORITY + 1, /* uxPriority */
                NULL                  /* pvCreatedTask */);

    xTaskCreate(blinky_task2,
                (const char *)"blinky_task2",
                configMINIMAL_STACK_SIZE,
                NULL,                 /* pvParameters */
                tskIDLE_PRIORITY + 1, /* uxPriority */
                NULL                  /* pvCreatedTask */);

    vTaskStartScheduler();
    while(1);
}

/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
	/* vApplicationMallocFailedHook() will only be called if
	configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
	function that will get called if a call to pvPortMalloc() fails.
	pvPortMalloc() is called internally by the kernel whenever a task, queue,
	timer or semaphore is created.  It is also called by various parts of the
	demo application.  If heap_1.c or heap_2.c are used, then the size of the
	heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
	FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
	to query the size of free heap space that remains (although it does not
	provide information on how the remaining heap might be fragmented). */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}

/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}

/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{
	/* This function will be called by each tick interrupt if
	configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
	added here, but the tick hook is called from an interrupt context, so
	code must not attempt to block, and only the interrupt safe FreeRTOS API
	functions can be used (those that end in FromISR()). */
}



