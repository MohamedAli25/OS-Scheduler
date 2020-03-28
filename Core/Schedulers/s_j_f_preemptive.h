#ifndef S_J_F_PREEMPTIVE
#define S_J_F_PREEMPTIVE

#include "scheduler.h"

class SJFPreemptive : public Scheduler
{
public:
    virtual void addProcess(Process process);
    virtual vector<pair<string, unsigned long long>> generateTimeline();
};

#endif /* S_J_F_PREEMPTIVE */