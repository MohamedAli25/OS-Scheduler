#ifndef S_J_F_NONPREEMPTIVE
#define S_J_F_NONPREEMPTIVE

#include "scheduler.h"
#include <vector>

class SJFNonpreemptive : public Scheduler
{
private:
    vector<Process> processes;
    int currentProcessIndex = -1;

public:
    virtual void addProcess(Process *process);
    virtual Process *next(double currentTime, double timeSlice);
    virtual ProcessEnum getProcessType();
    virtual ~SJFNonpreemptive();
};

#endif /* S_J_F_NONPREEMPTIVE */
