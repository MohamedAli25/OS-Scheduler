#include "scheduler_factory.h"

QStringList SchedulerFactory::SupportedSchedulers = {
    "First Come First Serve (FCFS)",
    "Priority (Non Preemptive)",
    "Priority (Preemptive)",
    "Round Robin",
    "Shortest Job First (Non Preemptive)",
    "Shortest Job First (Preemptive)",
};

Scheduler *SchedulerFactory::createScheduler(QString schedulerName, unsigned long long quantum){
    if (!schedulerName.compare(SupportedSchedulers[0]))
        return new FCFS;
    else if (!schedulerName.compare(SupportedSchedulers[1]))
        return new PriorityNonpreemptive;
    else if (!schedulerName.compare(SupportedSchedulers[2]))
        return new PriorityPreemptive;
    else if (!schedulerName.compare(SupportedSchedulers[3]))
        return new RoundRobin(quantum);
    else if (!schedulerName.compare(SupportedSchedulers[4]))
        return new SJFNonpreemptive;
    else if (!schedulerName.compare(SupportedSchedulers[5]))
        return new SJFPreemptive;
}


