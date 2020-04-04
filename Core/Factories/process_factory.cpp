#include "process_factory.h"
#include <QString>

using namespace std;

Process *ProcessFactory::createProcess(ProcessEnum process,
                                       int id,
                                       QString name,
                                       long long burstTime,
                                       unsigned long long arrivalTime,
                                       unsigned long long priority){
    if (process == ProcessEnum::NORMAL)
        return new Process(id, name, burstTime, arrivalTime);
    else
        return new PriorityProcess(id, name, burstTime, arrivalTime, priority);
}
