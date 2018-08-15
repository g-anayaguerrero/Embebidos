/*
 * OperativeSystem.h
 *
 *  Created on: Aug 10, 2018
 *      Author: Elias g
 */

#ifndef OPERATIVESYSTEM_H_
#define OPERATIVESYSTEM_H_


#include "derivative.h"
#include "User.h"

#define IDLE 0
#define READY 1
#define RUNNING 2
#define WAITING 3

void runTask(TASK task);
void ActivateTask(TASK task);
void ChainTask(TASK task);
void TerminateTask();
void OS_init(TASK *tasks, int size);
void sort(TASK tasks[20], int size);
// TASK checkHighestPriority(TASK *tasks, int size);




#endif /* OPERATIVESYSTEM_H_ */
