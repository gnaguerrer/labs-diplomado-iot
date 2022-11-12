/*! @file : lightSensor.c
 * @author  Gina Paola Guerrero Martinez
 * @version 1.0.0
 * @date    12/11/2022
 * @brief   Driver para controlar el sensor de luz
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
#include "fsl_adc16.h"
#include "lightSensor.h"

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
uint32_t ADC_value;

/*******************************************************************************
 * Private Source Code
 ******************************************************************************/
void reading_sensor(void) {

}

/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
uint32_t read_adc_value(void) {
	ADC16_SetChannelConfig(ADC0_PERIPHERAL, ADC0_CH0_CONTROL_GROUP,
			&ADC0_channelsConfig[0]);
	while (0U
			== (kADC16_ChannelConversionDoneFlag
					& ADC16_GetChannelStatusFlags(ADC0_PERIPHERAL,
					ADC0_CH0_CONTROL_GROUP))) {
	};
	ADC_value = ADC16_GetChannelConversionValue(ADC0_PERIPHERAL,
	ADC0_CH0_CONTROL_GROUP);
	return ADC_value;
}
