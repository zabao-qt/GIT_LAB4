/*
 * scheduler.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Admin
 */

#include "main.h"
#include "scheduler.h"

void SCH_Init(void) {
	unsigned char i;
    for (i = 0; i < SCH_MAX_TASKS; i++) {
        // Delete all tasks
        SCH_Delete_Task(i);
    }
}

void SCH_Update(void) {
    if (SCH_tasks_G[0].pTask) {
        if (SCH_tasks_G[0].Delay == 0) {
            SCH_tasks_G[0].RunMe += 1;
            if (SCH_tasks_G[0].Period) {
                SCH_tasks_G[0].Delay = SCH_tasks_G[0].Period;
            }
        } else {
            SCH_tasks_G[0].Delay -= 1;
        }
    }
}

int count = 0;
unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY,
                           unsigned int PERIOD) {
    unsigned char Index = 0;
    if (count == 0) {
        // Add task at the index = 0 if the scheduler is empty
        SCH_tasks_G[0].pTask = pFunction;
        SCH_tasks_G[0].Delay = DELAY;
        SCH_tasks_G[0].Period = PERIOD;
        SCH_tasks_G[0].RunMe = 0;
        count++;
    } else if (count > 0) {
        // Find satisfying locations to add new task
        while ((Index < count) && count < SCH_MAX_TASKS) {
            if (SCH_tasks_G[Index].Delay > DELAY) {
                for (int i = count; i > Index; i--) {
                    SCH_tasks_G[i] = SCH_tasks_G[i - 1];
                }
                SCH_tasks_G[Index].pTask = pFunction;
                SCH_tasks_G[Index].Delay = DELAY;
                SCH_tasks_G[Index].Period = PERIOD;
                SCH_tasks_G[Index].RunMe = 0;
                count++;
                for (int j = Index + 1; j < count; j++) {
                    SCH_tasks_G[j].Delay -= DELAY;
                }
                break;
            } else {
                DELAY -= SCH_tasks_G[Index].Delay;
            }
            Index++;
        }

        if (Index == count && (count + 1 < SCH_MAX_TASKS)) {
            SCH_tasks_G[Index].pTask = pFunction;
            SCH_tasks_G[Index].Delay = DELAY;
            SCH_tasks_G[Index].Period = PERIOD;
            SCH_tasks_G[Index].RunMe = 0;
            count++;
        }
    }
    return Index;
}

void SCH_Dispatch_Tasks(void) {
    if (SCH_tasks_G[0].RunMe > 0) {
        (*SCH_tasks_G[0].pTask)();  // Run the task
        SCH_tasks_G[0].RunMe -= 1;  // Reset || reduce RunMe flag
        if (SCH_tasks_G[0].Period == 0) {
            SCH_Delete_Task(0);
        } else {
            sTask temp = SCH_tasks_G[0];
            SCH_Delete_Task(0);
            SCH_Add_Task(temp.pTask, temp.Delay, temp.Period);
        }
    }
}

unsigned char SCH_Delete_Task(const int TASK_INDEX) {
    unsigned char Return_code;
    Return_code = 0;
    SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
    SCH_tasks_G[TASK_INDEX].Delay = 0;
    SCH_tasks_G[TASK_INDEX].Period = 0;
    SCH_tasks_G[TASK_INDEX].RunMe = 0;
    return Return_code;
}
