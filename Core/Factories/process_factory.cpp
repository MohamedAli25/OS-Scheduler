#include "process_factory.h"
#include <QString>

using namespace std;

Process *ProcessFactory::createProcess(ProcessEnum process,
                                       int id,
                                       QString name,
                                       double burstTime,
                                       double arrivalTime,
                                       double priority){
    if (process == ProcessEnum::NORMAL)
        return new Process(id, name, burstTime, arrivalTime);
    else
        return new Process(id, name, burstTime, arrivalTime, priority);
}
