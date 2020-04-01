#include "priority_process.h"

PriorityProcess::PriorityProcess(QString name, double burstTime, double arrivalTime, unsigned long long priority) : Process(name, burstTime, arrivalTime), priority{priority}
{
}

void PriorityProcess::setPriority(unsigned long long priority)
{
    this->priority = priority;
}

unsigned long long PriorityProcess::getPriority()
{
    return priority;
}
