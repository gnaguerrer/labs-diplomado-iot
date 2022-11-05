/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define SOPT5_LPUART0RXSRC_LPUART_RX 0x00u /*!<@brief LPUART0 Receive Data Source Select: LPUART_RX pin */
#define SOPT5_LPUART0TXSRC_LPUART_TX 0x00u /*!<@brief LPUART0 Transmit Data Source Select: LPUART0_TX pin */

/*! @name PORTE31 (number 19), LED2
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_LED2_FGPIO FGPIOE              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED2_GPIO GPIOE                /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED2_GPIO_PIN_MASK (1U << 31U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_LED2_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_LED2_PIN 31U                   /*!<@brief PORT pin number */
#define BOARD_LED2_PIN_MASK (1U << 31U)      /*!<@brief PORT pin mask */
                                             /* @} */

/*! @name PORTD5 (number 62), LED1
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_LED1_FGPIO FGPIOD             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED1_GPIO GPIOD               /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED1_GPIO_PIN_MASK (1U << 5U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_LED1_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_LED1_PIN 5U                   /*!<@brief PORT pin number */
#define BOARD_LED1_PIN_MASK (1U << 5U)      /*!<@brief PORT pin mask */
                                            /* @} */

/*! @name PORTA1 (number 23), UART0_RX
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_DEBUG_UART0_RX_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_DEBUG_UART0_RX_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_DEBUG_UART0_RX_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                                      /* @} */

/*! @name PORTA2 (number 24), UART0_TX
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_DEBUG_UART0_TX_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_DEBUG_UART0_TX_PIN 2U                   /*!<@brief PORT pin number */
#define BOARD_DEBUG_UART0_TX_PIN_MASK (1U << 2U)      /*!<@brief PORT pin mask */
                                                      /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
