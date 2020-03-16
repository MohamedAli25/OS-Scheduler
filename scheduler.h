#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Process/process.h"
#include <vector>
#include <utility>
#include <string>

using namespace std;

class Scheduler
{
protected:
    unsigned long long arrivalTimeSum = 0;
    unsigned long long burstTimeSum = 0;
    unsigned long long finishTimeSum = 0;
    unsigned long long numberOfProcesses = 0;

public:
    unsigned long long getArrivalTimeSum();
    unsigned long long getBurstTimeSum();
    unsigned long long getFinishTimeSum();
    unsigned long long getNumberOfProcesses();
    double getAverageWaitingTime();
    virtual void addProcess(Process process) = 0;
    virtual vector<pair<string, unsigned long long>> generateTimeline() = 0;
};

#endif /* SCHEDULER_H_ */