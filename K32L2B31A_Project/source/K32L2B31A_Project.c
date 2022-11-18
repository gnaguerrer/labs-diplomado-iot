/*!@file : K32L2B31A_Project.c
 * @author  Gina Paola Guerrero Martínez
 * @version 0.00
 * @date    17/10/2022
 * @brief   Funcion principal main
 * @details
 *
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdio.h>
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

/*******************************************************************************
 * Definitions
 ******************************************************************************/

enum STATES {
	FSM_STATE_START = 0,
	FSM_STATE_AWAIT_NEW_DATA_UART,
	FSM_STATE_CHECK_DATA_UART,
	FSM_STATE_SEND_COMD_ATI,
	FSM_STATE_SEND_COMD_GMI,
	FSM_STATE_SEND_COMD_GMM,
	FSM_STATE_SEND_COMD_GMR,
	FSM_STATE_SEND_COMD_CGMI,
	FSM_STATE_CHECK_COMD_ATI,
	FSM_STATE_CHECK_COMD_GMI,
	FSM_STATE_CHECK_COMD_GMM,
	FSM_STATE_CHECK_COMD_GMR,
	FSM_STATE_CHECK_COMD_CGMI,
	FSM_STATE_READ_ADC,
};

enum CMD_AT {
	CMD_AT_ATI_Display_Product_Identification_Information = 0,
	CMD_AT_AT_GMI_Request_Manufacturer_Identification,
	CMD_AT_AT_GMM_Request_TA_Model_Identification,
	CMD_AT_AT_GMR_Request_TA_Revision_Identification_of_Software_Release,
	CMD_AT_AT_CGMI_Request_Manufacturer_Identification,
	ERROR,
};

typedef struct _iot_nodo_data {
	uint16_t data_sensor_luz_adc;
	uint16_t data_sensor_luz_lux;
	//------------------------------------
	uint8_t data_sensor_luz_voltaje;
	uint8_t data_sensor_temperatura;
	uint16_t data_sensor_humedad;
	//------------------------------------
	uint16_t data_sensor_presion_atmosferica;
	uint16_t reservado;
//------------------------------------
} iot_nodo_data_t;

typedef struct _sigfox_frame {
	uint32_t preamble;
	uint16_t frame_sync;
	uint32_t end_point_id;
	uint8_t payload[12];
	uint16_t auth;
	uint16_t fcs;
} sigfox_frame_t;

/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Local vars
 ******************************************************************************/
uint8_t fst_current_state = FSM_STATE_START;
iot_nodo_data_t local_data;
uint8_t *data, p_ok_message;
char response_msg[LPUART0_BUFFER_SIZE_MAX];

const char *cmd_at[5] = {
		"ATI\r\n",		//c
		"AT+GMI\r\n",	//d
		"AT+GMM\r\n",	//e
		"AT+GMR\r\n",	//f
		"AT+CGMI\r\n",	//g
		};

char *ec25_responses_at[] = {
		"EC25EFAR02A09M4G",		//ATI
		"OK",					//AT+GMI
		"EC2x",					//AT+GMM
		"EC25EFAR02A09",	    //AT+GMR
		"READY",				//AT+CGMI
		"ERROR",				//ERROR
		};

/*******************************************************************************
 * Private Source Code
 ******************************************************************************/

void write_response_msg(uint8_t *response, char *success_msg, char *error_msg) {
	for (uint8_t i = 1; i < LPUART0_BUFFER_SIZE_MAX; i++) {
		response_msg[i - 1] = *(response + i);
	}

	if (strstr(response_msg, success_msg)) {
		PRINTF("Response: OK");
	} else if (strstr(response_msg, error_msg)) {
		PRINTF("Error found");
	} else {
		PRINTF("Not specified");
	}
	reset_buffer();
	set_data_uart0(0);

	for (uint8_t i = 0; i < LPUART0_BUFFER_SIZE_MAX; i++) {
		response_msg[i] = 0;
	}
}

int main(void) {

	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
	BOARD_InitDebugConsole();
#endif

	while (1) {
		switch (fst_current_state) {
		case FSM_STATE_START:
			fst_current_state = FSM_STATE_AWAIT_NEW_DATA_UART;
			break;

		case FSM_STATE_AWAIT_NEW_DATA_UART:
			if (has_new_data() != 0) {
				set_data_uart0(0);
				fst_current_state = FSM_STATE_CHECK_DATA_UART;
			}
			break;

		case FSM_STATE_CHECK_DATA_UART:
			switch (read_data_from_uart0()) {
			case 'l':
				fst_current_state = FSM_STATE_READ_ADC;
				break;
			case 'c':
				fst_current_state = FSM_STATE_SEND_COMD_ATI;
				break;
			case 'd':
				fst_current_state = FSM_STATE_SEND_COMD_GMI;
				break;
			case 'e':
				fst_current_state = FSM_STATE_SEND_COMD_GMM;
				break;
			case 'f':
				fst_current_state = FSM_STATE_SEND_COMD_GMR;
				break;
			case 'g':
				fst_current_state = FSM_STATE_SEND_COMD_CGMI;
				break;
			default:
				fst_current_state = FSM_STATE_START;
				break;
			}
			break;

		case FSM_STATE_SEND_COMD_ATI:
			PRINTF("%s",
					cmd_at[CMD_AT_ATI_Display_Product_Identification_Information]);
			fst_current_state = FSM_STATE_CHECK_COMD_ATI;
			break;

		case FSM_STATE_CHECK_COMD_ATI:
			if (has_new_data() != 0) {
				data = read_buffer();
				write_response_msg(data,
						ec25_responses_at[CMD_AT_ATI_Display_Product_Identification_Information],
						ec25_responses_at[ERROR]);
				fst_current_state = FSM_STATE_START;
			}
			break;

		case FSM_STATE_SEND_COMD_GMI:
			PRINTF("%s",
					cmd_at[CMD_AT_AT_GMI_Request_Manufacturer_Identification]);
			fst_current_state = FSM_STATE_CHECK_COMD_GMI;
			break;

		case FSM_STATE_CHECK_COMD_GMI:
			if (has_new_data() != 0) {
				data = read_buffer();
				write_response_msg(data,
						ec25_responses_at[CMD_AT_AT_GMI_Request_Manufacturer_Identification],
						ec25_responses_at[ERROR]);
				fst_current_state = FSM_STATE_START;
			}
			break;

		case FSM_STATE_SEND_COMD_GMM:
			PRINTF("%s", cmd_at[CMD_AT_AT_GMM_Request_TA_Model_Identification]);
			fst_current_state = FSM_STATE_CHECK_COMD_GMM;
			break;

		case FSM_STATE_CHECK_COMD_GMM:
			if (has_new_data() != 0) {
				data = read_buffer();
				write_response_msg(data,
						ec25_responses_at[CMD_AT_AT_GMM_Request_TA_Model_Identification],
						ec25_responses_at[ERROR]);
				fst_current_state = FSM_STATE_START;
			}
			break;

		case FSM_STATE_SEND_COMD_GMR:
			PRINTF("%s",
					cmd_at[CMD_AT_AT_GMR_Request_TA_Revision_Identification_of_Software_Release]);
			fst_current_state = FSM_STATE_CHECK_COMD_GMR;
			break;

		case FSM_STATE_CHECK_COMD_GMR:
			if (has_new_data() != 0) {
				data = read_buffer();
				write_response_msg(data,
						ec25_responses_at[CMD_AT_AT_GMR_Request_TA_Revision_Identification_of_Software_Release],
						ec25_responses_at[ERROR]);
				fst_current_state = FSM_STATE_START;
			}
			break;

		case FSM_STATE_SEND_COMD_CGMI:
			PRINTF("%s",
					cmd_at[CMD_AT_AT_CGMI_Request_Manufacturer_Identification]);
			fst_current_state = FSM_STATE_CHECK_COMD_CGMI;
			break;

		case FSM_STATE_CHECK_COMD_CGMI:
			if (has_new_data() != 0) {
				data = read_buffer();
				write_response_msg(data,
						ec25_responses_at[CMD_AT_AT_CGMI_Request_Manufacturer_Identification],
						ec25_responses_at[ERROR]);
				fst_current_state = FSM_STATE_START;
			}
			break;

		case FSM_STATE_READ_ADC:
			local_data.data_sensor_luz_adc = read_adc_value();
			PRINTF("data_sensor_luz_adc: %d\r\n",
					local_data.data_sensor_luz_adc);
			fst_current_state = FSM_STATE_START;
			break;

		default:
			fst_current_state = FSM_STATE_START;
			break;
		}
	}
	return 0;

	/*
	 local_data.data_sensor_luz_adc = 1;
	 local_data.data_sensor_luz_lux = 1;
	 local_data.data_sensor_luz_voltaje = 1;
	 local_data.data_sensor_temperatura = 1;
	 local_data.data_sensor_humedad = 1;
	 local_data.data_sensor_presion_atmosferica = 1;
	 local_data.reservado = 1;

	 while (1) {

	 if (read_data_from_uart0() != 0) {
	 switch (read_data_from_uart0()) {
	 case 82:
	 PRINTF("Turn on red \r\n");

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
	 local_data.data_sensor_luz_adc = read_adc_value();
	 break;
	 case 115:
	 sigfox_frame.preamble = 0x0001;
	 sigfox_frame.frame_sync = 0x0001;
	 sigfox_frame.end_point_id = 0x0001;
	 memcpy(&sigfox_frame.payload[0], (uint8_t*) (&local_data),
	 sizeof(local_data));
	 sigfox_frame.auth = 0x0001;
	 sigfox_frame.fcs = 0x0001;
	 ec25_print_data_raw((uint8_t*) (&sigfox_frame),
	 sizeof(sigfox_frame));
	 break;
	 default:
	 break;
	 }
	 set_data_uart0(0);
	 }
	 } */
}
