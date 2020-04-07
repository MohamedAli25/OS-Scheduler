#ifndef ROUND_ROBIN_H_
#define ROUND_ROBIN_H_

#include "scheduler.h"
#include "../Data_Structures/Circular_Linked_List/circular_linked_list.h"

class RoundRobin : public Scheduler
{
private:
    double quantum;
    CircularLinkedList<Process> processes;
    CLLNode<Process>* currentProcess = nullptr;

public:
    RoundRobin(double quantum);
    virtual void addProcess(Process *process);
    virtual Process *next(double currentTime, double timeSlice);
    virtual ProcessEnum getProcessType();
    virtual ~RoundRobin();
};

#endif /* ROUND_ROBIN_H_ */
