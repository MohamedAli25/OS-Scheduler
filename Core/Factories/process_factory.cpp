#include "process_factory.h"
#include <QString>

using namespace std;

Process *ProcessFactory::createProcess(ProcessEnum process,
                                       QString name,
                                       long long burstTime,
                                       unsigned long long arrivalTime,
                                       unsigned long long priority){
    if (process == ProcessEnum::NORMAL)
        return new Process(name, burstTime, arrivalTime);
    else
        return new PriorityProcess(name, burstTime, arrivalTime, priority);
}
