#ifndef F_C_F_S_H_
#define F_C_F_S_H_

#include "scheduler.h"
#include <queue>
#include <algorithm>

class FCFS : public Scheduler
{
private:
    queue<Process> processes;

public:
    virtual void addProcess(Process *process);
    virtual Process *next(double currentTime, double timeSlice);
    virtual ProcessEnum getProcessType();
    virtual ~FCFS();
};

#endif /* F_C_F_S_H_ */
