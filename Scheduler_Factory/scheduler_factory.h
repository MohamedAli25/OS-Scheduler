#ifndef SCHEDULER_FACTORY_H_
#define SCHEDULER_FACTORY_H_

#include "../scheduler.h"
#include "../Schedulers/f_c_f_s.h"
#include "../Schedulers/priority_nonpreemptive.h"
#include "../Schedulers/priority_preemprive.h"
#include "../Schedulers/round_robin.h"
#include "../Schedulers/s_j_f_nonpreemptive.h"
#include "../Schedulers/s_j_f_preemptive.h"

typedef enum SchedulerEnum
{
    f_c_f_s,
    priority_nonpreemptive,
    priority_preemptive,
    round_robin,
    s_j_f_nonpreemptive,
    s_j_f_preemptive
} SchedulerEnum;

class SchedulerFactory
{
public:
    Scheduler *schedulerFactoryMethod(SchedulerEnum scheduler, unsigned long long quantum);
};

#endif /* SCHEDULER_FACTORY_H_ */