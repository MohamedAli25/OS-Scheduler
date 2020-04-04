#ifndef S_J_F_PREEMPTIVE
#define S_J_F_PREEMPTIVE

#include "scheduler.h"

class SJFPreemptive : public Scheduler
{
public:
    virtual void addProcess(Process process);
    virtual Process *next();
    virtual ProcessEnum getProcessType() = 0;
};

#endif /* S_J_F_PREEMPTIVE */