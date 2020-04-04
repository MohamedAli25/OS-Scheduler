#include "f_c_f_s.h"

void FCFS::addProcess(Process *process)
{
    processes.push(*process);
    arrivalTimeSum += process->getArrivalTime();
    burstTimeSum += process->getBurstTime();
    numberOfProcesses += 1;
}

Process *FCFS::next(double currentTime, double timeSlice)
{
    Process *process_ptr = nullptr;

    if (!processes.empty())
    {
        if (processes.front().getRemainingBurstTime() <= 0)
        {
            finishTimeSum += currentTime;
            processes.pop();
        }
        if (!processes.empty())
        {
            process_ptr = &processes.front();
            process_ptr->setRemainingBurstTime(process_ptr->getRemainingBurstTime() - timeSlice);
        }
    }
    return process_ptr;
}

ProcessEnum FCFS::getProcessType()
{
    return ProcessEnum::NORMAL;
}

FCFS::~FCFS()
{
}