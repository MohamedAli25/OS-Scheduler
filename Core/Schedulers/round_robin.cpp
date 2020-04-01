#include "round_robin.h"

RoundRobin::RoundRobin(unsigned long long quantum) : quantum{quantum}
{
}

void RoundRobin::addProcess(Process *process)
{
    processes.push_back(*process);
}

Process *RoundRobin::next()
{
}