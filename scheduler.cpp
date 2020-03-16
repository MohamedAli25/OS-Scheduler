#include "scheduler.h"

unsigned long long Scheduler::getArrivalTimeSum()
{
    return arrivalTimeSum;
}

unsigned long long Scheduler::getBurstTimeSum()
{
    return burstTimeSum;
}

unsigned long long Scheduler::getFinishTimeSum()
{
    return finishTimeSum;
}

unsigned long long Scheduler::getNumberOfProcesses()
{
    return numberOfProcesses;
}

double Scheduler::getAverageWaitingTime()
{
    return (static_cast<double>(finishTimeSum - arrivalTimeSum - burstTimeSum) / numberOfProcesses);
}