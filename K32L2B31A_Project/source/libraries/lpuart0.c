/*! @file : lpuart0.c
 * @author  Gina Paola Guerrero Martinez
 * @version 1.0.0
 * @date    12/11/2022
 * @brief   Driver para controlar el puerto UART0
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
#include "fsl_lpuart.h"
#include "lpuart0.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Local vars
 ******************************************************************************/
static uint8_t data_lpUART0[LPUART0_BUFFER_SIZE_MAX];
static uint8_t flag_new_data = 0;
static uint8_t data_index = 0;
static uint16_t delay_control = 0;
/*******************************************************************************
 * Private Source Code
 ******************************************************************************/
/* LPUART0_IRQn interrupt handler */
void LPUART0_SERIAL_RX_TX_IRQHANDLER(void) {
	uint32_t intStatus;

	intStatus = LPUART_GetStatusFlags(LPUART0_PERIPHERAL);

	if ((kLPUART_RxDataRegFullFlag) & intStatus) {
		data_lpUART0[data_index] = LPUART_ReadByte(LPUART0);
		data_index++;
		if (data_index > LPUART0_BUFFER_SIZE_MAX) {
			data_index = 0;
		}
		flag_new_data = 1;
	}

#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}

/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
uint8_t read_data_from_uart0(void) {
	if (data_index != 0) {
		return (data_lpUART0[data_index - 1]);
	} else {
		return (0x00);
	}
}

uint8_t* read_buffer(void) {
	delay(10000);
	return data_lpUART0;
}

uint8_t has_new_data(void) {
	return (flag_new_data);
}

void set_data_uart0(uint8_t new_data) {
	flag_new_data = new_data;
}

void reset_buffer(void) {
	for (uint8_t i; i < LPUART0_BUFFER_SIZE_MAX; i++) {
		data_lpUART0[i] = 0x00;
	}
	data_index = 0;
}

void delay(uint16_t delay_ms) {
	delay_ms = delay_ms ? delay_ms : 10000;
	while (delay_control < delay_ms) {
		delay_control++;
	}
	delay_control=0;
}

