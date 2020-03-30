#include "scheduler.h"

double Scheduler::getArrivalTimeSum()
{
    return arrivalTimeSum;
}

double Scheduler::getBurstTimeSum()
{
    return burstTimeSum;
}

double Scheduler::getFinishTimeSum()
{
    return finishTimeSum;
}

double Scheduler::getNumberOfProcesses()
{
    return numberOfProcesses;
}

double Scheduler::getAverageWaitingTime()
{
    return ((finishTimeSum - arrivalTimeSum - burstTimeSum) / numberOfProcesses);
}