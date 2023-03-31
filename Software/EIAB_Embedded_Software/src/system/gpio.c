/*
  *****************************************************************************
  * @file           : gpio.c
  * @author         : Brian J Hoskins
  * @date           : 2023-03-30
  * @brief          : GPIO setup and functions
  *****************************************************************************
  * @attention
  *
  * Copyright (c) 2023 Brian Hoskins.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  *
  *****************************************************************************
*/

/* INCLUDES ---------------------------------------------------------------- */
#include "gpio.h"
#include "stm32g4xx.h"
#include "stm32g4xx_ll_gpio.h"
#include "stm32g4xx_ll_exti.h"
#include "stm32g4xx_ll_bus.h"
/* TYPEDEFS ---------------------------------------------------------------- */

/* DEFINES ----------------------------------------------------------------- */

/* FUNCTION PROTOTYPES ----------------------------------------------------- */




void GPIO_Init(void)
{
    /* GPIO PORTS CLOCK ENABLE */
    LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);

    /* BLINKY LED */
    LL_GPIO_ResetOutputPin(DO_BLINK_LED_PRT, DO_BLINK_LED_PIN);
    LL_GPIO_SetPinPull(DO_BLINK_LED_PRT, DO_BLINK_LED_PIN, LL_GPIO_PULL_NO);
    LL_GPIO_SetPinOutputType(DO_BLINK_LED_PRT, DO_BLINK_LED_PIN, LL_GPIO_OUTPUT_PUSHPULL);
    LL_GPIO_SetPinSpeed(DO_BLINK_LED_PRT, DO_BLINK_LED_PIN, LL_GPIO_SPEED_FREQ_LOW);
    LL_GPIO_SetPinMode(DO_BLINK_LED_PRT, DO_BLINK_LED_PIN, LL_GPIO_MODE_OUTPUT);

}
