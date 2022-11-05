/*
 * Author: Gina Guerrero
 * Activity 1.
 * Module 2 - IoT Course
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "board.h"

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LED_GPIO_1     BOARD_LED_GREEN_GPIO
#define BOARD_LED_GPIO_PIN_1 BOARD_LED_GREEN_GPIO_PIN

#define BOARD_LED_GPIO_2     BOARD_LED_RED_GPIO
#define BOARD_LED_GPIO_PIN_2 BOARD_LED_RED_GPIO_PIN

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile uint32_t g_systickCounter;

/*******************************************************************************
 * Code
 ******************************************************************************/
void SysTick_Handler(void)
{
    if (g_systickCounter != 0U)
    {
        g_systickCounter--;
    }
}

void SysTick_DelayTicks(uint32_t n)
{
    g_systickCounter = n;
    while (g_systickCounter != 0U)
    {
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* Board pin init */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    PRINTF("Hello, I'm Gina. \r\n");
    PRINTF("This is a led blinking example. \r\n");

    /* Set systick reload value to generate 1ms interrupt */
    if (SysTick_Config(SystemCoreClock / 1000U))
    {
        while (1)
        {
        }
    }


    while (1)
    {
        /* Delay 1000 ms */
        GPIO_PortToggle(BOARD_LED_GPIO_1, 1u << BOARD_LED_GPIO_PIN_1);
        SysTick_DelayTicks(1000U);
        GPIO_PortToggle(BOARD_LED_GPIO_2, 1u << BOARD_LED_GPIO_PIN_2);
    }
}
