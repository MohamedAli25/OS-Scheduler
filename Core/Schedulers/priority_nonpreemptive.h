#ifndef PRIORITY_NONPREEMPTIVE_H_
#define PRIORITY_NONPREEMPTIVE_H_

#include "scheduler.h"
#include "../Process/priority_process.h"

class PriorityNonpreemptive : public Scheduler
{
private:
    vector<Process> processes;
    int currentProcessIndex = -1;

public:
    virtual void addProcess(Process *process);
    virtual Process *next(double currentTime, double timeSlice);
    virtual ProcessEnum getProcessType();
    virtual ~PriorityNonpreemptive();
};

#endif /* PRIORITY_NONPREEMPTIVE_H_ */
