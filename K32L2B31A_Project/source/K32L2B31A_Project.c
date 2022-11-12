#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"

#include "fsl_common.h"
#include "lpuart0.h"
#include "leds.h"
#include "lightSensor.h"

int main(void) {

	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
				LED_RED_ON();
				break;
			case 114:
				PRINTF("Turn off red \r\n");
				LED_RED_OFF();
				break;
			case 86:
				PRINTF("Turn on green \r\n");
				LED_GREEN_ON();
				break;
			case 118:
				PRINTF("Turn off green \r\n");
				LED_GREEN_OFF();
				break;
			case 108:
				PRINTF("Reading light sensor \r\n");
				PRINTF("ADC Value: %d \r\n", read_adc_value());
				break;
			default:
				break;
			}
			set_data_uart0(0);
		}

	}
}
