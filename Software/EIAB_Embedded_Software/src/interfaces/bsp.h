/*
  ******************************************************************************
  * @file           : bsp.h
  * @brief          : Header for bsp.c file.
  *                   This file contains the common defines of the application.
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

#ifndef BSP_H
#define BSP_H

/** INCLUDES -------------------------------------------------------------- **/
#include "core.h"
#include "qpc.h"

/** TYPEDEFS -------------------------------------------------------------- **/
extern QTicker ticker0_10ms; /* ticker active object for tick rate 0 1ms*/
extern QTicker ticker1_10us; /* ticker active object for tick rate 1 1us*/
/** DEFINES --------------------------------------------------------------- **/
#define BSP_TICKS_PER_SEC 100
/** PUBLIC FUNCTION PROTOTYPES -------------------------------------------- **/
void BSP_Init(void);
void BSP_SetBlinkyLED(ON_OFF_STATUS status);





#endif
