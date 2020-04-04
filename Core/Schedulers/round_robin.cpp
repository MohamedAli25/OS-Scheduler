#include "round_robin.h"

RoundRobin::RoundRobin(unsigned long long quantum) : quantum{quantum}
{
}

void RoundRobin::addProcess(Process *process)
{
    if (processes.getRoot() == nullptr)
    {
        currentProcess = Process;
    }
    processes.add(*Process);
    burstTimeSum += process->getBurstTime();
    arrivalTimeSum += process->getArrivalTime();
    numberOfProcesses++;
}

// TODO : finish the function
Process *RoundRobin::next(double currentTime, double timeSlice)
{
    if (processes.getRoot() == nullptr)
    {
        return nullptr;
    }
    else
    {
        Process *result = currentProcess;
        // currentProcess->setRemainingBurstTime(currentProcess->getRemainingBurstTime() - timeSlice);
        if (currentProcess->getRemainingBurstTime() <= 0)
        {
            finishTimeSum += currentTime;
            processes.removePtr(currentProcess);
        }
        if (processes.getRoot() == nullptr)
        {
            return nullptr;
        }
        else
        {
        }

        if (currentProcess->getRemainingBurstTime() <= 0)
        {
            finishTimeSum += currentTime;
            processes.removePtr(currentProcess);
        }
        if (!processes.empty())
        {
            process_ptr = &processes.front();
            process_ptr->setRemainingBurstTime(process->getRemainingBurstTime() - timeSlice);
        }
    }
}