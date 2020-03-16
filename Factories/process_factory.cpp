#include "process_factory.h"
#include <string>

using namespace std;

Process *ProcessFactory::processFactoryMethod(ProcessEnum process, string name, long long burstTime, unsigned long long arrivalTime, unsigned long long priority = 0)
{
    if (process == ProcessEnum::normal)
        return new Process(name, burstTime, arrivalTime);
    else if (process == ProcessEnum::priority)
        return new PriorityProcess(name, burstTime, arrivalTime, priority);
}