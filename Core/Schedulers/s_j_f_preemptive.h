#ifndef S_J_F_PREEMPTIVE
#define S_J_F_PREEMPTIVE

#include "scheduler.h"

class SJFPreemptive : public Scheduler
{
public:
    virtual void addProcess(Process process);
    virtual Process *next();
};

#endif /* S_J_F_PREEMPTIVE */