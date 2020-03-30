#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Process/process.h"
#include <algorithm>
#include <vector>
#include <utility>
#include <QString>

using namespace std;

class Scheduler
{
protected:
    double arrivalTimeSum = 0;
    double burstTimeSum = 0;
    double finishTimeSum = 0;
    double numberOfProcesses = 0;

public:
    double getArrivalTimeSum();
    double getBurstTimeSum();
    double getFinishTimeSum();
    double getNumberOfProcesses();
    double getAverageWaitingTime();
    virtual void addProcess(Process process) = 0;
    virtual Process *next(double currentTime, double timeSlice) = 0;
};

#endif /* SCHEDULER_H_ */
