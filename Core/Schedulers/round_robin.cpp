#include "round_robin.h"

RoundRobin::RoundRobin(double quantum) : quantum{quantum}
{
}

void RoundRobin::addProcess(Process *process){
    CLLNode<Process> *node = new CLLNode<Process>(*process);
    processes.add(*process);
    if (processes.size() == 1)
    {
        currentProcess = processes.getRoot();
    }
    burstTimeSum += process->getBurstTime();
    arrivalTimeSum += process->getArrivalTime();
    numberOfProcesses++;
}

Process *RoundRobin::next(double currentTime, double timeSlice){
    if (processes.getRoot() == nullptr){
        return nullptr;
    }else{
        if(count == quantum){
            currentProcess = currentProcess->getNext();
            count = 0;
        }
        while(currentProcess->getValue().getRemainingBurstTime() <= 0){
            if (processes.getRoot() == nullptr)
                return nullptr;
            currentProcess = processes.removePtr(currentProcess);
            if(currentProcess == nullptr) return nullptr;
        }
        if (processes.getRoot() == nullptr){
            return nullptr;
        }else{
            if (currentProcess->getValue().getRemainingBurstTime() == currentProcess->getValue().getBurstTime())
                currentProcess->getValue().setStartTime(currentTime);
            currentProcess->getValue().setRemainingBurstTime(currentProcess->getValue().getRemainingBurstTime() - timeSlice);
            if(currentProcess->getValue().getRemainingBurstTime() <= 0)
                currentProcess->getValue().setEndTime(currentTime);
            if (currentProcess->getValue().getRemainingBurstTime() <= 0){
                currentProcess->getValue().setRemainingBurstTime(0);
                count = quantum - 1;
            }
            count++;
            return &(currentProcess->getValue());
        }
    }
}

ProcessEnum RoundRobin::getProcessType()
{
    return ProcessEnum::NORMAL;
}

RoundRobin::~RoundRobin() {}
