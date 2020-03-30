#ifndef PRIORITY_PROCESS_H_
#define PRIORITY_PROCESS_H_

#include<QString>
#include "process.h"

using namespace std;

class PriorityProcess : public Process{
private:
    unsigned long long priority;

public:
    PriorityProcess(QString name, long long burstTime, unsigned long long arrivalTime, unsigned long long priority = 0);
    void setPriority(unsigned long long priority);
    unsigned long long getPriority();
};

#endif /* PRIORITY_PROCESS_H_ */
