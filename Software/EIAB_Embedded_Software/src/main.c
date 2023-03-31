/*
  *****************************************************************************
  * @file           : main.c
  * @author         : Brian J Hoskins
  * @date           : 2023-03-30
  * @brief          : The application entry point
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
#include "main.h"
#include "bsp.h"
#include "stm32g4xx_hal.h"
/* TYPEDEFS ---------------------------------------------------------------- */

/* DEFINES ----------------------------------------------------------------- */

/* FUNCTION PROTOTYPES ----------------------------------------------------- */











/*
 ******************************************************************************
 * @brief  main - The application entry point
 ******************************************************************************
*/
int main(void)
{
    BSP_Init();
    while (1)
    {
        HAL_Delay(500);
        BSP_SetBlinkyLED(ON);
        HAL_Delay(500);
        BSP_SetBlinkyLED(OFF);
    }
}

