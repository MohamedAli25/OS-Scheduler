#include "round_robin.h"

bool RoundRobin::compare(Process p1, Process p2)
{
    return (p1.getArrivalTime() < p2.getArrivalTime());
}

RoundRobin::RoundRobin(unsigned long long quantum) : quantum{quantum}
{
}

void RoundRobin::addProcess(Process process)
{
    processes.push_back(process);
}

Process *RoundRobin::next()
{
}