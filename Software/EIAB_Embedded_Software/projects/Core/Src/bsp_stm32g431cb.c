/*
  *****************************************************************************
  * @file           : bsp_stm32g431cb.h
  * @author         : Brian J Hoskins
  * @date           : 2023-03-30
  * @brief          : The hardware abstraction layer for STM32G431CB.  Allows
  *                   the Active objects to interface with an abstracted
  *                   interface.
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

/** INCLUDES -------------------------------------------------------------- **/
#include "bsp.h"

/** TYPEDEFS -------------------------------------------------------------- **/

/** DEFINES --------------------------------------------------------------- **/

/** PRIVATE FUNCTION PROTOTYPES ------------------------------------------- **/
void SystemClock_Config(void);
void BSP_Error_Handler(void);






/*
 ******************************************************************************
 * @brief  BSP_Init - BSP & System Initialise
 * @retval None - errors here are intolerable & will call Error_Handler()
 ******************************************************************************
*/
void BSP_Init(void)
{
    // Initialise HAL
    if(HAL_Init() != HAL_OK)
    {
        BSP_Error_Handler();
    }
}

/*
 ******************************************************************************
 * @brief  SystemClock_Config - System clock configuration
 * @retval None - errors here are intolerable & will call Error_Handler()
 ******************************************************************************
*/
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Configure the main internal regulator output voltage **/
    HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

    /** Initializes the RCC Oscillators according to the specified parameters
      in the RCC_OscInitTypeDef structure. **/
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
    RCC_OscInitStruct.PLL.PLLN = 85;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
    RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        BSP_Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks **/
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
    {
        BSP_Error_Handler();
    }
}

/*
 ******************************************************************************
 * @brief  BSP_Error_Handler - handles errors in BSP activities
 * @retval None
 ******************************************************************************
*/
void BSP_Error_Handler(void)
{
    while (1)
    {
        //TODO: Implement error handler
    }
}
