#ifndef PROCESS_FACTORY_H_
#define PROCESS_FACTORY_H_

#include <QString>
#include "../Process/process.h"
#include "../Process/priority_process.h"

using namespace std;

typedef enum ProcessEnum{
    NORMAL,
    PRIORITY
} ProcessEnum;

class ProcessFactory{
public:
    static Process *createProcess(ProcessEnum process,
                                  QString name,
                                  long long burstTime,
                                  unsigned long long arrivalTime,
                                  unsigned long long priority = 0);
};

#endif /* PROCESS_FACTORY_H_ */
