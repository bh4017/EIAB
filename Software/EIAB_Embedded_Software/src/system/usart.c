/*
  *****************************************************************************
  * @file           : usart.c
  * @author         : Brian J Hoskins
  * @date           : 2023-03-30
  * @brief          : USART setup and functions
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
#include "usart.h"
#include "stm32g4xx_ll_usart.h"
#include "stm32g4xx_ll_rcc.h"
#include "stm32g4xx_ll_bus.h"
#include "stm32g4xx_ll_gpio.h"


/* TYPEDEFS ---------------------------------------------------------------- */

/* DEFINES ----------------------------------------------------------------- */

/* FUNCTION PROTOTYPES ----------------------------------------------------- */



void USART1_Init(void)
{
    /* USER CODE BEGIN USART1_Init 0 */

     /* USER CODE END USART1_Init 0 */

     LL_USART_InitTypeDef USART_InitStruct = {0};

     LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

     LL_RCC_SetUSARTClockSource(LL_RCC_USART1_CLKSOURCE_PCLK2);

     /* Peripheral clock enable */
     LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1);

     LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
     /**USART1 GPIO Configuration
     PA9   ------> USART1_TX
     PA10   ------> USART1_RX
     */
     GPIO_InitStruct.Pin = LL_GPIO_PIN_9;
     GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
     GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
     GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
     GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
     GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
     LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

     GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
     GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
     GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
     GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
     GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
     GPIO_InitStruct.Alternate = LL_GPIO_AF_7;
     LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

     /* USER CODE BEGIN USART1_Init 1 */

     /* USER CODE END USART1_Init 1 */
     USART_InitStruct.PrescalerValue = LL_USART_PRESCALER_DIV1;
     USART_InitStruct.BaudRate = 115200;
     USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
     USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
     USART_InitStruct.Parity = LL_USART_PARITY_NONE;
     USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
     USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
     USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
     LL_USART_Init(USART1, &USART_InitStruct);
     LL_USART_SetTXFIFOThreshold(USART1, LL_USART_FIFOTHRESHOLD_1_8);
     LL_USART_SetRXFIFOThreshold(USART1, LL_USART_FIFOTHRESHOLD_1_8);
     LL_USART_DisableFIFO(USART1);
     LL_USART_ConfigAsyncMode(USART1);

     /* USER CODE BEGIN WKUPType USART1 */

     /* USER CODE END WKUPType USART1 */

     LL_USART_Enable(USART1);

     /* Polling USART1 initialisation */
     while((!(LL_USART_IsActiveFlag_TEACK(USART1))) || (!(LL_USART_IsActiveFlag_REACK(USART1))))
     {
     }
     /* USER CODE BEGIN USART1_Init 2 */

     /* USER CODE END USART1_Init 2 */
}

void _USART1_Init(void)
{
    LL_USART_InitTypeDef USART_InitStruct = {0};

    /* INITIALISE PERIPHERAL CLOCK */
    LL_RCC_SetUSARTClockSource(LL_RCC_USART1_CLKSOURCE_PCLK2);
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1);

    /* USART CONFIGURATION */
    USART_InitStruct.PrescalerValue = LL_USART_PRESCALER_DIV1;
    USART_InitStruct.BaudRate = USART1_BAUD;
    USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
    USART_InitStruct.Parity = LL_USART_PARITY_NONE;
    USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
    LL_USART_Init(USART1, &USART_InitStruct);
    LL_USART_SetTXFIFOThreshold(USART1, LL_USART_FIFOTHRESHOLD_1_8);
    LL_USART_SetRXFIFOThreshold(USART1, LL_USART_FIFOTHRESHOLD_1_8);
    LL_USART_DisableFIFO(USART1);
    LL_USART_ConfigAsyncMode(USART1);

    LL_USART_Enable(USART1);

    // Polling USART1 initialisation
    while((!(LL_USART_IsActiveFlag_TEACK(USART1))) || (!(LL_USART_IsActiveFlag_REACK(USART1))))
    {
        //TODO: Timeout and then assert after and we can have an error if there's a problem
    }
}
