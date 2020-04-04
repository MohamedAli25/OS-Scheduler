#ifndef PRIORITY_NONPREEMPTIVE_H_
#define PRIORITY_NONPREEMPTIVE_H_

#include "scheduler.h"
#include "../Process/priority_process.h"

class PriorityNonpreemptive : public Scheduler
{

public:
    virtual void addProcess(Process process);
    virtual Process *next();
    virtual ProcessEnum getProcessType() = 0;
};

#endif /* PRIORITY_NONPREEMPTIVE_H_ */