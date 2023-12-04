/*
 * scheduler.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Admin
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

//***** The scheduler data structure.
typedef struct {
    // Pointer to the task (must be a 'void (void)' function).
    void (*pTask)(void);
    // Delay (ticks) until the function will (next) be run.
    uint32_t Delay;
    // Interval (ticks) between subsequent runs.
    uint32_t Period;
    // Incremented (by scheduler) when task is due to execute.
    uint8_t RunMe;
    // This is a hint to solve the question below.
    uint32_t TaskID;
} sTask;

// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS	40
#define TICK			10
#define NO_TASK_ID 		0
typedef struct {
	sTask TASK_QUEUE[SCH_MAX_TASKS];
	int numofTask;
} taskList;

taskList SCH_tasks_G;

//***** An initialization function.
void SCH_Init(void);
//***** A single interrupt service routine (ISR), used to update the scheduler at regular time intervals.
void SCH_Update(void);
//***** A function for adding tasks to the scheduler.
void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
//***** A dispatcher function that causes tasks to be executed when they are due to run.
void SCH_Dispatch_Tasks(void);
//***** A function for removing tasks from the scheduler (not required in all applications).
void SCH_Delete_Task(void);
void insert_to_list(sTask task);


#endif /* INC_SCHEDULER_H_ */
