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
#include "qpc.h"    // QP/C framework API
#include "qmodel.h"
#include "main.h"
#include "bsp.h"

Q_DEFINE_THIS_FILE
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
    /* AO EVENT QUEUES */
    static QEvt const *blinky_queueSto[10];        // event queue buffer for Blinky

    /* QF EVENT POOLS */
    static QF_MPOOL_EL(QEvt) stdEvtPool[10];          // standard size event pool

    /* QF EVENT SUBSCRIPTION LIST */
    static QSubscrList subscrSto[MAX_PUB_SIG];

    /* INITIALISE BOARD SUPPORT PACKAGE */
    BSP_Init();

    /* INSTANTIATE ACTIVE OBJECTS */
    QTicker_ctor(&ticker0_10ms, 0U); // active object for tick rate 0
    //QTicker_ctor(&ticker1_10us, 1U); // active object for tick rate 1

    Blinky_ctor_call();              // Blinky constructor

    /* INITIALISE QF */
    QF_init();                       // initialize the framework

    /* INIT PUB/SUBSCRIBE */
    QF_psInit(subscrSto, Q_DIM(subscrSto));

    /* INIT EVENT POOLS */
    QF_poolInit(stdEvtPool, sizeof(stdEvtPool), sizeof(stdEvtPool[0]));


    /* START ACTIVE OBJECTS */
    QACTIVE_START(&ticker0_10ms.super,
            1U, //QP priority
            0, 0, 0, 0, 0); //no queue, no stack , no init. event

    QACTIVE_START(AO_Blinky, /* active object to start */
                2U, /* priority of the active object */
                blinky_queueSto, /* event queue buffer */
                Q_DIM(blinky_queueSto), /* the length of the buffer */
                (void *)0, 0U, /* private stack (not used) */
                (QEvt *)0); /* initialization event (not used) */

    /* HANDOVER TO THE FRAMEWORK */
    return QF_run(); /* let the framework run the application */
}

