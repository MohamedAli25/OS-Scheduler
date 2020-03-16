#ifndef F_C_F_S_H_
#define F_C_F_S_H_

#include "../scheduler.h"

class FCFS : public Scheduler
{
protected:
    virtual void removeProcess(Process *process);

public:
    virtual void addProcess(Process process);
    virtual vector<pair<string, unsigned long long>> generateTimeline();
};

#endif /* F_C_F_S_H_ */