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
uint8_t static data_lpUART0;

/*******************************************************************************
 * Private Source Code
 ******************************************************************************/
/* LPUART0_IRQn interrupt handler */
void LPUART0_SERIAL_RX_TX_IRQHANDLER(void) {
	uint32_t intStatus;

	intStatus = LPUART_GetStatusFlags(LPUART0_PERIPHERAL);

	if ((kLPUART_RxDataRegFullFlag) & intStatus) {
		data_lpUART0 = LPUART_ReadByte(LPUART0);
	}

#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
  #endif
}


/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
 uint8_t read_data_from_uart0(void){
	 return data_lpUART0;
 }

void set_data_uart0(uint8_t new_data){
	 data_lpUART0= new_data;
 }







 
