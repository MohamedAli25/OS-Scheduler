#ifndef PRIORITY_PREEMPTIVE_H_
#define PRIORITY_PREEMPTIVE_H_

#include "../scheduler.h"
#include "../Process/priority_process.h"

class PriorityPreemptive : public Scheduler
{
protected:
    virtual void removeProcess(PriorityProcess *process);

public:
    virtual void addProcess(PriorityProcess process);
    virtual vector<pair<string, unsigned long long>> generateTimeline();
};

#endif /* PRIORITY_PREEMPTIVE_H_ */