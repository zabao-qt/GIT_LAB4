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
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0
sTask SCH_tasks_G[SCH_MAX_TASKS];

//***** An initialization function.
void SCH_Init(void);
//***** A single interrupt service routine (ISR), used to update the scheduler at regular time intervals.
void SCH_Update(void);
//***** A function for adding tasks to the scheduler.
unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY,
                           unsigned int PERIOD);
//***** A dispatcher function that causes tasks to be executed when they are due to run.
void SCH_Dispatch_Tasks(void);
//***** A function for removing tasks from the scheduler (not required in all applications).
unsigned char SCH_Delete_Task(const int TASK_INDEX);
void SCH_Shift_Task(const int TASK_INDEX);

#endif /* INC_SCHEDULER_H_ */
