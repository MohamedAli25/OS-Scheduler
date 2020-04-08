#include "priority_preemptive.h"

PriorityPreemptive::PriorityPreemptive() : processes(PriorityProcess::lessPriority)
{
}

void PriorityPreemptive::addProcess(PriorityProcess *process)
{
    processes.insert(*process);
}

Process *PriorityPreemptive::next(double currentTime, double timeSlice)
{
    if (processes.extractMin().getRemainingBurstTime() <= 0)
    {
        processes.deleteMin();
    }
    if (processes.extractMin() == null)
    {
        return nullptr;
    }
    else
    {
        processes.extractMin().setRemainingBurstTime(processes.extractMin().getRemainingBurstTime() - timeSlice);
        if (processes.extractMin().getRemainingBurstTime() < 0)
        {
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
