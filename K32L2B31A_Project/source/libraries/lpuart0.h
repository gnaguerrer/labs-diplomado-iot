/*! @file : lpuart0.h
 * @author  Gina Paola Guerrero Martinez
 * @version 1.0.0
 * @date    12/11/2022
 * @brief   Driver para controlar el puerto UART0
 * @details
 *
 */
#ifndef LIBRARIES_LPUART0_H_
#define LIBRARIES_LPUART0_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_common.h"
#include "lpuart0.h"

/*!
 * @addtogroup X
 * @{
 */
/*!
 * @addtogroup X
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/
#define LPUART0_BUFFER_SIZE_MAX	100
/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/
//uint8_t read_data_from_uart0(void);
uint8_t read_data_from_uart0(void);
uint8_t * read_buffer(void);
uint8_t has_new_data(void);
void set_data_uart0(uint8_t new_data);
void reset_buffer(void);
void delay(uint16_t delay_ms);
/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/

/** @} */ // end of X group
/** @} */// end of X group
#endif /* LIBRARIES_LPUART0_H_ */
