/*! @file : leds.c
 * @author  Gina Paola Guerrero Martinez
 * @version 1.0.0
 * @date    12/11/2022
 * @brief   Driver para 
 * @details
 *
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_device_registers.h"
#include "fsl_common.h"

#include "leds.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_GPIO_1     BOARD_LED_GREEN_GPIO
#define BOARD_LED_GPIO_PIN_1 BOARD_LED_GREEN_GPIO_PIN

#define BOARD_LED_GPIO_2     BOARD_LED_RED_GPIO
#define BOARD_LED_GPIO_PIN_2 BOARD_LED_RED_GPIO_PIN

/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Local vars
 ******************************************************************************/
volatile uint32_t g_systickCounter;

/*******************************************************************************
 * Private Source Code
 ******************************************************************************/
void SysTick_Handler(void) {
	if (g_systickCounter != 0U) {
		g_systickCounter--;
	}
}

void SysTick_DelayTicks(uint32_t n) {
	g_systickCounter = n;
	while (g_systickCounter != 0U) {
	}
}

/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
/* Set systick reload value to generate 1ms interrupt */
void systick_reload(void) {
	if (SysTick_Config(SystemCoreClock / 1000U)) {
		while (1) {
		}
	}
}
