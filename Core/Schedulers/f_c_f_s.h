#ifndef F_C_F_S_H_
#define F_C_F_S_H_

#include "scheduler.h"
#include <queue>
#include <algorithm>

class FCFS : public Scheduler
{
private:
    queue<Process> processes;
    bool static compare(Process p1, Process p2);

public:
    virtual void addProcess(Process *process);
    virtual Process *next(double currentTime, double timeSlice);
};

#endif /* F_C_F_S_H_ */
