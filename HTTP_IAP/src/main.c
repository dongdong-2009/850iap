
// ----------------------------------------------------------------------------

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

#include "stm32f4xx.h"

/* Priorities for the demo application tasks. */
#define mainFLASH_TASK_PRIORITY				( tskIDLE_PRIORITY + 1UL )
#define ledSTACK_SIZE						configMINIMAL_STACK_SIZE

static 	portTASK_FUNCTION_PROTO( vLEDFlashTask, pvParameters );

volatile unsigned long ulFPUInterruptNesting = 0UL, ulMaxFPUInterruptNesting = 0UL;

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
int	main()
{
  SystemInit();

  xTaskCreate( vLEDFlashTask, "LEDx", ledSTACK_SIZE, NULL, mainFLASH_TASK_PRIORITY, ( TaskHandle_t * ) NULL );

  vTaskStartScheduler();

  for( ;; );

}
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

static portTASK_FUNCTION( vLEDFlashTask, pvParameters )
{
	if(pvParameters) {}

	  while (1)
	    {
	    }

}

/*-----------------------------------------------------------*/

void vApplicationTickHook( void )
{

}
/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{

}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;


	taskDISABLE_INTERRUPTS();
	for( ;; );
}
/*-----------------------------------------------------------*/

// ----------------------------------------------------------------------------
