#ifndef PRIORITY_PREEMPTIVE_H_
#define PRIORITY_PREEMPTIVE_H_

#include "scheduler.h"
#include "../Process/priority_process.h"
#include "../Data_Structures/Min_Priority_Queue/min_priority_queue.h"

class PriorityPreemptive : public Scheduler
{
private:
    MinPriorityQueue<PriorityProcess> processes;

public:
    PriorityPreemptive();
    virtual void addProcess(PriorityProcess *process);
    virtual Process *next(double currentTime, double timeSlice);
    virtual ProcessEnum getProcessType();
    virtual ~PriorityPreemptive();
};

#endif /* PRIORITY_PREEMPTIVE_H_ */
