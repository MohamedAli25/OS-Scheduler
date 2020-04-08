#ifndef PRIORITY_NONPREEMPTIVE_H_
#define PRIORITY_NONPREEMPTIVE_H_

#include "scheduler.h"
#include "../Process/priority_process.h"

class PriorityNonpreemptive : public Scheduler
{
private:
    vector<PriorityProcess> processes;
    int currentProcessIndex = -1;

public:
    virtual void addProcess(PriorityProcess *process);
    virtual Process *next();
    virtual ProcessEnum getProcessType();
    virtual ~PriorityNonpreemptive();
};

#endif /* PRIORITY_NONPREEMPTIVE_H_ */