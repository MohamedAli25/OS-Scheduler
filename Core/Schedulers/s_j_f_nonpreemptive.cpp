#include "s_j_f_nonpreemptive.h"

void SJFNonpreemptive::addProcess(Process *process)
{
    processes.push_back(*process);
    arrivalTimeSum += process->getArrivalTime();
    burstTimeSum += process->getBurstTime();
    numberOfProcesses++;
}

Process *SJFNonpreemptive::next(double currentTime, double timeSlice)
{
    if (currentProcessIndex == -1)
    {
        if (processes.empty())
        {
            return nullptr;
        }
        currentProcessIndex = 0;
        for (int i = 1; i < processes.size(); i++)
        {
            if (processes[i].getRemainingBurstTime() < processes[currentProcessIndex].getRemainingBurstTime())
            {
                currentProcessIndex = i;
            }
        }
        processes[currentProcessIndex].setRemainingBurstTime(processes[currentProcessIndex].getRemainingBurstTime() - timeSlice);
        if (processes[currentProcessIndex].getRemainingBurstTime() < 0)
        {
            finishTimeSum += currentTime;
            processes[currentProcessIndex].setRemainingBurstTime(0);
        }
        return &processes[currentProcessIndex];
    }
    else if (processes[currentProcessIndex].getRemainingBurstTime() <= 0)
    {
        processes.erase(processes.begin() + currentProcessIndex);
        currentProcessIndex = -1;
        if (processes.empty())
        {
            return nullptr;
        }
        currentProcessIndex = 0;
        for (int i = 1; i < processes.size(); i++)
        {
            if (processes[i].getRemainingBurstTime() < processes[currentProcessIndex].getRemainingBurstTime())
            {
                currentProcessIndex = i;
            }
        }
        processes[currentProcessIndex].setRemainingBurstTime(processes[currentProcessIndex].getRemainingBurstTime() - timeSlice);
        if (processes[currentProcessIndex].getRemainingBurstTime() < 0)
        {
            finishTimeSum += currentTime;
            processes[currentProcessIndex].setRemainingBurstTime(0);
        }
        return &processes[currentProcessIndex];
    }
    else
    {
        processes[currentProcessIndex].setRemainingBurstTime(processes[currentProcessIndex].getRemainingBurstTime() - timeSlice);
        if (processes[currentProcessIndex].getRemainingBurstTime() < 0)
        {
            finishTimeSum += currentTime;
            processes[currentProcessIndex].setRemainingBurstTime(0);
        }
        return &processes[currentProcessIndex];
    }
}

ProcessEnum SJFNonpreemptive::getProcessType()
{
    return ProcessEnum::NORMAL;
}

SJFNonpreemptive::~SJFNonpreemptive()
{
    this->Scheduler::~Scheduler();
}
