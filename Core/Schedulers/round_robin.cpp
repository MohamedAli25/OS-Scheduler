#include "round_robin.h"

RoundRobin::RoundRobin(double quantum) : quantum{quantum}
{
}

void RoundRobin::addProcess(Process *process){
    processesQueue.enqueue(process);
}

Process *RoundRobin::next(double currentTime, double timeSlice){
    if(tempP != nullptr) processesQueue.enqueue(tempP);
    tempP = nullptr;
    if(processesQueue.size() == 0) return nullptr;
    Process *p = processesQueue.front();
    if(p->getRemainingBurstTime() == p->getBurstTime()) p->setStartTime(currentTime);
    p->setRemainingBurstTime(p->getRemainingBurstTime() - timeSlice);
    if(p->getRemainingBurstTime() == 0) p->setEndTime(currentTime);
    if(++count == quantum){
        if(p->getRemainingBurstTime() <= 0) processesQueue.dequeue();
        else if(processesQueue.size() > 0) tempP = processesQueue.dequeue();
        count = 0;
    }else if(p->getRemainingBurstTime() == 0){
        processesQueue.dequeue();
        count = 0;
    }
    return p;
}

ProcessEnum RoundRobin::getProcessType()
{
    return ProcessEnum::NORMAL;
}

RoundRobin::~RoundRobin() {}
