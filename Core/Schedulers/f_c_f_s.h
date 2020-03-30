#ifndef F_C_F_S_H_
#define F_C_F_S_H_

#include "scheduler.h"
#include <QString>
#include <vector>
#include <algorithm>

class FCFS : public Scheduler
{
private:
    vector<Process> processes;
    bool static compare(Process p1, Process p2);

public:
    virtual void addProcess(Process process);
    virtual vector<pair<QString, unsigned long long>> generateTimeline();
};

#endif /* F_C_F_S_H_ */
