#include "priority_preemptive.h"

PriorityPreemptive::PriorityPreemptive() : processes(PriorityProcess::lessPriority)
{
}

void PriorityPreemptive::addProcess(PriorityProcess *process)
{
    processes.insert(*process);
    arrivalTimeSum += process->getArrivalTime();
    burstTimeSum += process->getBurstTime();
    numberOfProcesses++;
}

Process *PriorityPreemptive::next(double currentTime, double timeSlice)
{
    if (processes.size() == 0)
    {
        return nullptr;
    }
    if (processes.extractMin().getRemainingBurstTime() <= 0)
    {
        processes.deleteMin();
    }
    else
    {
        processes.extractMin().setRemainingBurstTime(processes.extractMin().getRemainingBurstTime() - timeSlice);
        if (processes.extractMin().getRemainingBurstTime() < 0)
        {
            finishTimeSum += currentTime;
            processes.extractMin().setRemainingBurstTime(0);
        }
        return &processes.extractMin();
    }
}

ProcessEnum PriorityPreemptive::getProcessType()
{
    return ProcessEnum::PRIORITY;
}

PriorityPreemptive::~PriorityPreemptive()
{
    this->Scheduler::~Scheduler();
}
