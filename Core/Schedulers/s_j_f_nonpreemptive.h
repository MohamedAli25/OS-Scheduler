#ifndef S_J_F_NONPREEMPTIVE
#define S_J_F_NONPREEMPTIVE

#include "scheduler.h"
#include <vector>

class SJFNonpreemptive : public Scheduler
{
private:
    vector<Process> processes;

public:
    virtual void addProcess(Process process);
    virtual Process *next();
};

#endif /* S_J_F_NONPREEMPTIVE */