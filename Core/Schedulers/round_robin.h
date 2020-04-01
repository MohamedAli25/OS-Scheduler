#ifndef ROUND_ROBIN_H_
#define ROUND_ROBIN_H_

#include "scheduler.h"

class RoundRobin : public Scheduler
{
private:
    double quantum;
    vector<Process> processes;
    unsigned long long currentIndex = 0;

public:
    RoundRobin(double quantum);
    virtual void addProcess(Process *process);
    virtual Process *next(double currentTime, double timeSlice);
};

#endif /* ROUND_ROBIN_H_ */