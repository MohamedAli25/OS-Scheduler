#include "process_factory.h"
#include <QString>

using namespace std;

Process *ProcessFactory::createProcess(ProcessEnum process,
                                       QString name,
                                       double burstTime,
                                       double arrivalTime,
                                       double priority){
    if (process == ProcessEnum::NORMAL)
        return new Process(name, burstTime, arrivalTime);
    else
        return new PriorityProcess(name, burstTime, arrivalTime, priority);
}
