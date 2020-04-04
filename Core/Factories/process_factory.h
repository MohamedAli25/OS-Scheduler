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
                                  int id,
                                  QString name,
                                  double burstTime,
                                  double arrivalTime,
                                  double priority = 0);
};

#endif /* PROCESS_FACTORY_H_ */
