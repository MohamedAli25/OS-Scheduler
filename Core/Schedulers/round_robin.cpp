#include "round_robin.h"

RoundRobin::RoundRobin(double quantum) : quantum{quantum}
{
}

void RoundRobin::addProcess(Process *process)
{
    CLLNode<Process> *node = new CLLNode<Process>(*process);
    if (processes.getRoot() == nullptr)
    {
        currentProcess = node;
    }
    processes.add(*process);
    burstTimeSum += process->getBurstTime();
    arrivalTimeSum += process->getArrivalTime();
    numberOfProcesses++;
}

Process *RoundRobin::next(double currentTime, double timeSlice)
{
    if (processes.getRoot() == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (currentProcess->getValue().getRemainingBurstTime() <= 0)
        {
            finishTimeSum += currentTime;
            currentProcess = processes.removePtr(currentProcess);
        }
        if (processes.getRoot() == nullptr)
        {
            return nullptr;
        }
        else
        {
            currentProcess->getValue().setRemainingBurstTime(currentProcess->getValue().getRemainingBurstTime() - timeSlice);
            if (currentProcess->getValue().getRemainingBurstTime() < 0)
            {
                currentProcess->getValue().setRemainingBurstTime(0);
            }
            return &(currentProcess->getValue());
        }
    }
}

ProcessEnum RoundRobin::getProcessType()
{
    return ProcessEnum::NORMAL;
}
