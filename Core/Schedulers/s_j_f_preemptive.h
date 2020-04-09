#ifndef S_J_F_PREEMPTIVE
#define S_J_F_PREEMPTIVE

#include "scheduler.h"
#include "../Data_Structures/Min_Priority_Queue/min_priority_queue.h"

class SJFPreemptive : public Scheduler
{
private:
    MinPriorityQueue<Process> processes;

public:
    SJFPreemptive();
    virtual void addProcess(Process *process);
    virtual Process *next(double currentTime, double timeSlice);
    virtual ProcessEnum getProcessType();
    virtual ~SJFPreemptive();
};

#endif /* S_J_F_PREEMPTIVE */
