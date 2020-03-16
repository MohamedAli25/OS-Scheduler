#ifndef PRIORITY_NONPREEMPTIVE_H_
#define PRIORITY_NONPREEMPTIVE_H_

#include "../scheduler.h"
#include "../Process/priority_process.h"

class PriorityNonpreemptive : public Scheduler
{

public:
    virtual void addProcess(Process process);
    virtual vector<pair<string, unsigned long long>> generateTimeline();
};

#endif /* PRIORITY_NONPREEMPTIVE_H_ */