#ifndef PROCESS_FACTORY_H_
#define PROCESS_FACTORY_H_

#include <string>
#include "../Process/process.h"
#include "../Process/priority_process.h"

using namespace std;

typedef enum ProcessEnum
{
    normal,
    priority
} ProcessEnum;

class ProcessFactory
{
public:
    Process *processFactoryMethod(ProcessEnum process, string name, long long burstTime, unsigned long long arrivalTime, unsigned long long priority = 0);
};

#endif /* PROCESS_FACTORY_H_ */