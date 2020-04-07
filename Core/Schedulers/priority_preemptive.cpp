#include "priority_preemptive.h"


PriorityPreemptive::PriorityPreemptive() : processes(PriorityProcess::lessPriority)
{

}

void PriorityPreemptive::addProcess(PriorityProcess* process)
{
    processes.insert(*process);
}

Process *PriorityPreemptive::next(double currentTime, double timeSlice)
{
}

ProcessEnum PriorityPreemptive::getProcessType()
{
    return ProcessEnum::PRIORITY;
}

PriorityPreemptive::~PriorityPreemptive()
{
    this->Scheduler::~Scheduler();
}
