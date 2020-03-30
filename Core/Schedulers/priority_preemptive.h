#ifndef PRIORITY_PREEMPTIVE_H_
#define PRIORITY_PREEMPTIVE_H_

#include "scheduler.h"

class PriorityPreemptive : public Scheduler{

public:
    virtual void addProcess(Process process);
    virtual Process *next();
};

#endif /* PRIORITY_PREEMPTIVE_H_ */
