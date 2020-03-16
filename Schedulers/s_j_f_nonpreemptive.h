#ifndef S_J_F_NONPREEMPTIVE
#define S_J_F_NONPREEMPTIVE

#include "../scheduler.h"

class SJFNonpreemptive : public Scheduler
{
protected:
    virtual void removeProcess(Process *process);

public:
    virtual void addProcess(Process process);
    virtual vector<pair<string, unsigned long long>> generateTimeline();
};

#endif /* S_J_F_NONPREEMPTIVE */