/*.$file${..\src\aos::blinky.c} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: qmodel.qm
* File:  ${..\src\aos::blinky.c}
*
* This code has been generated by QM 5.1.4 <www.state-machine.com/qm/>.
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*/
/*.$endhead${..\src\aos::blinky.c} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#include "qpc.h"    // QP/C framework API
#include "bsp.h"    // Board Support Package interface
#include "core.h"
#include "qmodel.h"

Q_DEFINE_THIS_FILE

/* local objects -----------------------------------------------------------*/
/*.$declare${AOs::Blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${AOs::Blinky} ..........................................................*/
typedef struct Blinky {
/* protected: */
    QActive super;

/* public: */

/* private: */
    QTimeEvt timeEvt;
} Blinky;

/* public: */
static void Blinky_ctor(Blinky * const me);
extern Blinky Blinky_inst;

/* protected: */
static QState Blinky_initial(Blinky * const me, void const * const par);
static QState Blinky_active(Blinky * const me, QEvt const * const e);
static QState Blinky_off(Blinky * const me, QEvt const * const e);
static QState Blinky_on(Blinky * const me, QEvt const * const e);
/*.$enddecl${AOs::Blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/* Public-scope objects ----------------------------------------------------*/
/*.$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*. Check for the minimum required QP version */
#if (QP_VERSION < 690U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpc version 6.9.0 or higher required
#endif
/*.$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*.$define${Shared::AO_Blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

/* opaque AO pointer */
/*.${Shared::AO_Blinky} ....................................................*/
QActive* const AO_Blinky = &Blinky_inst.super;
/*.$enddef${Shared::AO_Blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

/* Active object definition ================================================*/
/*.$define${Shared::Blinky_ctor_call} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${Shared::Blinky_ctor_call} .............................................*/
void Blinky_ctor_call(void) {
    Blinky_ctor(&Blinky_inst);
}
/*.$enddef${Shared::Blinky_ctor_call} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*.$define${AOs::Blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${AOs::Blinky} ..........................................................*/
Blinky Blinky_inst;
/*.${AOs::Blinky::ctor} ....................................................*/
static void Blinky_ctor(Blinky * const me) {
    QActive_ctor(&me->super, Q_STATE_CAST(&Blinky_initial));
    QTimeEvt_ctorX(&me->timeEvt, &me->super, TIMEOUT_SIG, 0U);
}

/*.${AOs::Blinky::SM} ......................................................*/
static QState Blinky_initial(Blinky * const me, void const * const par) {
    /*.${AOs::Blinky::SM::initial} */
    return Q_TRAN(&Blinky_active);
}
/*.${AOs::Blinky::SM::active} ..............................................*/
static QState Blinky_active(Blinky * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*.${AOs::Blinky::SM::active} */
        case Q_ENTRY_SIG: {
            QTimeEvt_armX(&me->timeEvt,
                BSP_TICKS_PER_SEC,
                BSP_TICKS_PER_SEC);
            status_ = Q_HANDLED();
            break;
        }
        /*.${AOs::Blinky::SM::active::initial} */
        case Q_INIT_SIG: {
            status_ = Q_TRAN(&Blinky_off);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*.${AOs::Blinky::SM::active::off} .........................................*/
static QState Blinky_off(Blinky * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*.${AOs::Blinky::SM::active::off} */
        case Q_ENTRY_SIG: {
            BSP_SetBlinkyLED(OFF);
            status_ = Q_HANDLED();
            break;
        }
        /*.${AOs::Blinky::SM::active::off::TIMEOUT} */
        case TIMEOUT_SIG: {
            status_ = Q_TRAN(&Blinky_on);
            break;
        }
        default: {
            status_ = Q_SUPER(&Blinky_active);
            break;
        }
    }
    return status_;
}
/*.${AOs::Blinky::SM::active::on} ..........................................*/
static QState Blinky_on(Blinky * const me, QEvt const * const e) {
    QState status_;
    switch (e->sig) {
        /*.${AOs::Blinky::SM::active::on} */
        case Q_ENTRY_SIG: {
            BSP_SetBlinkyLED(ON);
            status_ = Q_HANDLED();
            break;
        }
        /*.${AOs::Blinky::SM::active::on::TIMEOUT} */
        case TIMEOUT_SIG: {
            status_ = Q_TRAN(&Blinky_off);
            break;
        }
        default: {
            status_ = Q_SUPER(&Blinky_active);
            break;
        }
    }
    return status_;
}
/*.$enddef${AOs::Blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
