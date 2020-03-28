#ifndef PRIORITY_PROCESS_H_
#define PRIORITY_PROCESS_H_

#include "process.h"

using namespace std;

class PriorityProcess : public Process
{
private:
    unsigned long long priority;

public:
    PriorityProcess(string name, long long burstTime, unsigned long long arrivalTime, unsigned long long priority);
    void setPriority(unsigned long long priority);
    unsigned long long getPriority();
};

#endif /* PRIORITY_PROCESS_H_ */