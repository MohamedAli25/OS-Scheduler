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
        process = &processes.front();
        process->setRemainingBurstTime(process->getRemainingBurstTime() - timeSlice);
        if (process->getRemainingBurstTime() <= 0)
        {
            finishTimeSum += currentTime;
            processes.pop();
        }
    }
    return process_ptr;
}
