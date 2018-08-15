/*
 * OperativeSystem.c
 *
 *  Created on: Aug 10, 2018
 *      Author: Elias g
 */
#include "derivative.h"
#include "User.h"
#include "OperativeSystem.h"

TASK readyTasks[20];
TASK runningTask;

void runTask(TASK task){
	task.state = RUNNING;
	runningTask = task;
	runningTask.ap_task_init();
	while(1);
}

void ActivateTask(TASK task){
	readyTasks[19]=task;
	int i;
	for (i = 0; i < 20; i++){
		readyTasks[i].state = READY;
	}
	
	sort(readyTasks, 20);

	runTask(readyTasks[0]);

}

void ChainTask(TASK task){
	TerminateTask();
	ActivateTask(task);
}

void TerminateTask(){
	int i;
	for(i = 0; i < 20; i++){
		if(readyTasks[i].ID == runningTask.ID){
			readyTasks[i].state = IDLE;
			//readyTasks[i].pop();
			break;
		}
	}

	//runningTask = nullptr;

}


void sort(TASK task[20], int n){
	TASK reflect[20];
	int i;
	for(i = 1; i < n; i++) {
		int key = task[i].priority;
		int j = i - 1;

		while(j >= 0 && task[i].priority > key) {
			task[j + 1].priority = task[j].priority;
			j = j - 1;
		}

		task[j + 1].priority = key;

	}

	for(i = 0; i < n; i++){
		reflect[i] = task[n - 1 - i];
		reflect[n - 1 - i] = task[i];
	}
	for (i = 0; i < 20; i++){
		readyTasks[i]=reflect[i];
	}
	//return reflect;
}

void OS_init(TASK *tasks, int size){

	//TASK sorted[] = sort(tasks, size);
	int i;
	for(i = 0; i < size; i++){
		if(tasks[i].autostart == 1){
			ActivateTask(tasks[i]);
		}
	}
	
}
