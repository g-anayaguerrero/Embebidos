/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include "User.h"
#include "OperativeSystem.h"

void TASK_A(void);
void TASK_B(void);
void TASK_C(void);
TASK task_a, task_b, task_c;
int main(void){
	//Pointer
	//void (*task_a_pointer)(void) = &TASK_A;
	//void (*task_b_pointer)(void) = &TASK_B;
	//void (*task_c_pointer)(void) = &TASK_C;

	//TASK A
	task_a.priority = 0;
	task_a.autostart = 1;
	task_a.return_direction = 255;
	task_a.state = 0;
	task_a.ID=0;
	task_a.ap_task_init = &TASK_A;
	//TASK B
	task_b.priority = 1;
	task_b.autostart = 0;
	task_b.return_direction = 255;
	task_b.state = 0;
	task_b.ID=1;
	task_b.ap_task_init = &TASK_B;
	//TASK_C
	task_c.priority = 2;
	task_c.autostart = 0;
	task_c.return_direction = 255;
	task_c.state = 0;
	task_c.ID=2;
	task_c.ap_task_init = &TASK_C;
	//Array
	TASK task_arr[10];
	task_arr[0] = task_a;
	task_arr[1] = task_b;
	task_arr[2] = task_c;
	OS_init(task_arr, 3);
	return 0;
}

void TASK_A(void){
	ActivateTask(task_b);
	SIM_SCGC5 |= (1 << 10);
	PORTB_PCR21 = (1 << 8);
	GPIOB_PDDR |= (1 << 21);
	GPIOB_PDOR = ~(1 << 21);
	TerminateTask();
}

void TASK_B(void){
	SIM_SCGC5 |= (1 << 10);
	PORTB_PCR22 = (1 << 8);
	GPIOB_PDOR &= ~(1 << 21);
	GPIOB_PDDR |= (1 << 22);
	GPIOB_PDOR = ~(1 << 22);
	ChainTask(task_c);

}

void TASK_C(void){
	SIM_SCGC5 |= (1 << 10);
	PORTB_PCR22 = (1 << 8);
	GPIOB_PDDR |= (1 << 22);
	GPIOB_PDOR &= ~(1 << 21);
	GPIOB_PDOR &= ~(1 << 22);

	SIM_SCGC5 |= (1 << 13);
	PORTE_PCR26 = (1 << 8);
	GPIOE_PDDR |= (1 << 26);
	GPIOE_PDOR = ~(1 << 26);

	TerminateTask();
}
