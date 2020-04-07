#ifndef PRIORITY_PROCESS_H_
#define PRIORITY_PROCESS_H_

#include <QString>
#include "process.h"

using namespace std;

class PriorityProcess : public Process
{
private:
    unsigned long long priority;

public:
    PriorityProcess(int id, QString name, double burstTime, double arrivalTime, unsigned long long priority);
    void setPriority(unsigned long long priority);
    unsigned long long getPriority();

    // Static Methods
    // less function
    static bool lessPriority(const PriorityProcess &l, const PriorityProcess &r);
    // compareTo function
    static bool compareToPriority(const PriorityProcess &l, const PriorityProcess &r);
};

#endif /* PRIORITY_PROCESS_H_ */
