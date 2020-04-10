#include "f_c_f_s.h"


FCFS::FCFS() {
}

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
            if(process_ptr->getRemainingBurstTime() == process_ptr->getBurstTime())
                process_ptr->setStartTime(currentTime);
            process_ptr->setRemainingBurstTime(process_ptr->getRemainingBurstTime() - timeSlice);
            if (process_ptr->getRemainingBurstTime() == 0)
            {
                process_ptr->setRemainingBurstTime(0);
                process_ptr->setEndTime(currentTime);
            }
        }
    }
    return process_ptr;
}

ProcessEnum FCFS::getProcessType()
{
    return ProcessEnum::NORMAL;
}


FCFS::~FCFS() {
    this->Scheduler::~Scheduler();
}
