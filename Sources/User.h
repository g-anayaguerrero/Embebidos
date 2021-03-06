/*
 * User.h
 *
 *  Created on: Aug 10, 2018
 *      Author: Elias g
 */
#include "derivative.h"

#ifndef USER_H_
#define USER_H_

typedef struct {
    volatile uint8_t priority;
    volatile uint8_t autostart;
    volatile uint32_t return_direction;
    volatile uint32_t ap_task_init;
    volatile uint8_t state; //STATE 0:IDLE 1:READY 2:RUNNING 3:WAIT
    volatile uint8_t ID;
} TASK;

#endif /* USER_H_ */
