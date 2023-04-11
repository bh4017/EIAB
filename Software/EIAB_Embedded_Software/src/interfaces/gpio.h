/*
  ******************************************************************************
  * @file           : gpio.h
  * @brief          : Header for gpio.c file.
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) Brian J Hoskins
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
*/

#ifndef GPIO_H
#define GPIO_H

/** INCLUDES -------------------------------------------------------------- **/
#include "stm32g4xx_ll_gpio.h"
/** TYPEDEFS -------------------------------------------------------------- **/

/** DEFINES --------------------------------------------------------------- **/

    /* DEBUG PINS
     * Note that these pins are mapped by default and therefore no explicit setup
     * is required.  I define them here mainly to document that these pins are
     * being used for the debugger connection.
     */
    #define T_SWDIO_PIN LL_GPIO_PIN_13
    #define T_SWDIO_PRT GPIOA
    #define T_SWCLK_PIN LL_GPIO_PIN_14
    #define T_SWCLK_PRT GPIOA

    /* BLINK LED OUTPUT
     * This provides for PA5 to be used as a debug aid.  It's used on the NUCLEO
     * boards so it means I can load my software on there and use the LED on it.
     */
    #define DO_BLINK_LED_PIN LL_GPIO_PIN_5
    #define DO_BLINK_LED_PRT GPIOA

    /* USART 1
     * PA9  --> USART1_TX
     * PA10 --> USART1_RX
     */
    #define USART1_PORT   GPIOA
    #define USART1_AFMODE LL_GPIO_AF_7
    #define USART1_TX_PIN LL_GPIO_PIN_9
    #define USART1_RX_PIN LL_GPIO_PIN_10




/** PUBLIC FUNCTION PROTOTYPES -------------------------------------------- **/
    void GPIO_Init(void);






#endif
