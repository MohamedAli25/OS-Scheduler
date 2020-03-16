#ifndef PRIORITY_PREEMPTIVE_H_
#define PRIORITY_PREEMPTIVE_H_

#include "../scheduler.h"

class PriorityPreemptive : public Scheduler
{

public:
    virtual void addProcess(Process process);
    virtual vector<pair<string, unsigned long long>> generateTimeline();
};

#endif /* PRIORITY_PREEMPTIVE_H_ */