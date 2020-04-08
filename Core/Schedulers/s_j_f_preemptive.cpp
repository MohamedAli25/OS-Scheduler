#include "s_j_f_preemptive.h"

SJFPreemptive::SJFPreemptive() : processes(Process::lessRemainingBurstTime)
{
}

void SJFPreemptive::addProcess(PriorityProcess *process)
{
    processes.insert(*process);
}

Process *SJFPreemptive::next(double currentTime, double timeSlice)
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
    }
}

ProcessEnum SJFPreemptive::getProcessType()
{
    return ProcessEnum::NORMAL;
}

SJFPreemptive::~SJFPreemptive()
{
    this->Scheduler::~Scheduler();
}
