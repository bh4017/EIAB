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
#include "gpio.h"
#include "stm32g4xx_hal.h"
#include "qpc.h"

Q_DEFINE_THIS_FILE

/** TYPEDEFS -------------------------------------------------------------- **/

/** DEFINES --------------------------------------------------------------- **/

/** QSPY ------------------------------------------------------------------ **/
#ifdef Q_SPY
    QSTimeCtr QS_tickTime_;
    QSTimeCtr QS_tickPeriod_;

    /* QSpy source IDs */
    static QSpyId const l_SysTick_Handler = { 0U };

    enum AppRecords
    {
        /* application-specific trace records */
        MY_STAT = QS_USER
    };

#endif

/** VARS ------------------------------------------------------------------ **/
QTicker ticker0_10ms; // ticker active object for tick rate 0 10ms
//QTicker ticker1_10us; // ticker active object for tick rate 1 10us

/** PRIVATE FUNCTION PROTOTYPES ------------------------------------------- **/
void SystemClock_Config(void);
void BSP_Error_Handler(void);
void SysTick_Handler(void);
void USART2_IRQHandler(void);




void BSP_SetBlinkyLED(ON_OFF_STATUS status)
{
    if(status == ON)
    {
        LL_GPIO_SetOutputPin(DO_BLINK_LED_PRT, DO_BLINK_LED_PIN);
    }
    else
    {
        LL_GPIO_ResetOutputPin(DO_BLINK_LED_PRT, DO_BLINK_LED_PIN);
    }
}


/*
 ******************************************************************************
 * @brief  BSP_Init - BSP & System Initialise
 * @retval None - errors here are intolerable & will call Error_Handler()
 ******************************************************************************
*/
void BSP_Init(void)
{
    /* INIT HAL */
    if(HAL_Init() != HAL_OK)
    {
        BSP_Error_Handler();
    }

    /* CONFIGURE SYSTEM CLOCK */
    SystemClock_Config();

    /* INITIALISE PERIPHERALS */
    GPIO_Init();

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

    /** Configure the main internal regulator output voltage
    */
    HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

    /** Initializes the RCC Oscillators according to the specified parameters
    * in the RCC_OscInitTypeDef structure.
    */
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

    /** Initializes the CPU, AHB and APB buses clocks
    */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
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


/*
 ******************************************************************************
 * @brief  QF_onStartup - executes once, on startup of QF
 * @retval None
 ******************************************************************************
*/
void QF_onStartup(void)
{
    /* set up the SysTick timer to fire at BSP_TICKS_PER_SEC rate */
    SysTick_Config(SystemCoreClock / BSP_TICKS_PER_SEC);

    /* set priorities of ALL ISRs used in the system, see NOTE00
    *
    * !!!!!!!!!!!!!!!!!!!!!!!!!!!! CAUTION !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    * Assign a priority to EVERY ISR explicitly by calling NVIC_SetPriority().
    * DO NOT LEAVE THE ISR PRIORITIES AT THE DEFAULT VALUE!
    */
    NVIC_SetPriority(USART2_IRQn,    0U); /* kernel UNAWARE interrupt */
    NVIC_SetPriority(SysTick_IRQn,   QF_AWARE_ISR_CMSIS_PRI + 1U);
    /* ... */

    /* enable IRQs... */
    //NVIC_EnableIRQ(EXTI0_1_IRQn);
#ifdef Q_SPY
    NVIC_EnableIRQ(USART2_IRQn); /* UART2 interrupt used for QS-RX */
#endif
}

/*
 ******************************************************************************
 * @brief  QV_onIdle - executes during QV idle time
 * @retval None
 ******************************************************************************
*/
void QV_onIdle(void)
{
    /* called with interrupts disabled, see NOTE01 */


#ifdef Q_SPY
    QF_INT_ENABLE();
    QS_rxParse();  /* parse all the received bytes */

    if ((USART2->ISR & (1U << 7)) != 0) {  /* is TXE empty? */
        uint16_t b;

        QF_INT_DISABLE();
        b = QS_getByte();
        QF_INT_ENABLE();

        if (b != QS_EOD) {  /* not End-Of-Data? */
            USART2->TDR = (b & 0xFFU);  /* put into the DR register */
        }
    }

#else
    QF_INT_ENABLE(); /* just enable interrupts */
#endif
}

Q_NORETURN Q_onAssert(char const * const module, int_t const loc)
{

    (void)module;
    (void)loc;
    QS_ASSERTION(module, loc, 10000U); /* report assertion to QS */

    while(1); //TODO: Add an assertion handler here
    //NVIC_SystemReset();
}


/*
 ******************************************************************************
 * @brief  QF_onCleanup - QP Framework cleanup
 * @retval None
 ******************************************************************************
*/
void QF_onCleanup(void)
{
}

/*
 ******************************************************************************
 * @brief  SysTick_Handler - handles the Systick
 * @retval None
 ******************************************************************************
*/
void SysTick_Handler(void)
{
    /* system clock tick ISR */
    HAL_IncTick();

#ifdef Q_SPY
    {
        tmp = SysTick->CTRL; /* clear CTRL_COUNTFLAG */
        QS_tickTime_ += QS_tickPeriod_; /* account for the clock rollover */
    }
#endif

    QF_TICK_X(0U, &l_SysTick_Handler); /* process time events for rate 0 */
    QACTIVE_POST(&ticker0_10ms.super, 0, &l_SysTick_Handler); /* post to Ticker0 */


    QV_ARM_ERRATUM_838869();
}
