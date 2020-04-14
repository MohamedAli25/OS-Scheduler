#ifndef ROUND_ROBIN_H_
#define ROUND_ROBIN_H_

#include "scheduler.h"
#include <QQueue>


class RoundRobin : public Scheduler
{
private:
    double quantum;
    int count = 0;
    QQueue<Process*> processesQueue;
    Process *tempP = nullptr;

public:
    RoundRobin(double quantum);
    virtual void addProcess(Process *process);
    virtual Process *next(double currentTime, double timeSlice);
    virtual ProcessEnum getProcessType();
    virtual ~RoundRobin();
};

#endif /* ROUND_ROBIN_H_ */
