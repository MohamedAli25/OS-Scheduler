#ifndef PRIORITY_PROCESS_H_
#define PRIORITY_PROCESS_H_

#include <QString>
#include "process.h"

using namespace std;

class PriorityProcess : public Process
{
private:
    unsigned long long priority;

public:
    PriorityProcess(QString name, double burstTime, double arrivalTime, unsigned long long priority);
    void setPriority(unsigned long long priority);
    unsigned long long getPriority();
};

#endif /* PRIORITY_PROCESS_H_ */
