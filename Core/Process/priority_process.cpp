#include "priority_process.h"

PriorityProcess::PriorityProcess(int id, QString name, double burstTime, double arrivalTime, unsigned long long priority) : Process(id, name, burstTime, arrivalTime), priority{priority}
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

bool PriorityProcess::lessPriority(const PriorityProcess &l, const PriorityProcess &r)
{
    return (l.priority < r.priority);
}

bool PriorityProcess::compareToPriority(const PriorityProcess &l, const PriorityProcess &r)
{
    if (l.priority < r.priority)
        return -1;
    else if (l.priority > r.priority)
        return 1;
    return 0;
}
