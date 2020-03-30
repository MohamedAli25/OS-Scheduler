#include "scheduler_factory.h"

Scheduler *SchedulerFactory::schedulerFactoryMethod(SchedulerEnum scheduler, unsigned long long quantum)
{
    if (scheduler == f_c_f_s)
        return new FCFS;
    else if (scheduler == priority_nonpreemptive)
        return new PriorityNonpreemptive;
    else if (scheduler == priority_preemptive)
        return new PriorityPreemptive;
    else if (scheduler == round_robin)
        return new RoundRobin(quantum);
    else if (scheduler == s_j_f_nonpreemptive)
        return new SJFNonpreemptive;
    else if (scheduler == s_j_f_preemptive)
        return new SJFPreemptive;
}
