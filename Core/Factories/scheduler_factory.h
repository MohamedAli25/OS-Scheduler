#ifndef SCHEDULER_FACTORY_H_
#define SCHEDULER_FACTORY_H_

#include <QStringList>
#include <QString>
#include "../Schedulers/scheduler.h"
#include "../Schedulers/f_c_f_s.h"
#include "../Schedulers/priority_nonpreemptive.h"
#include "../Schedulers/priority_preemptive.h"
#include "../Schedulers/round_robin.h"
#include "../Schedulers/s_j_f_nonpreemptive.h"
#include "../Schedulers/s_j_f_preemptive.h"

class SchedulerFactory{
public:
    static Scheduler *createScheduler(QString scheduler, unsigned long long quantum = 1);
    static QStringList SupportedSchedulers;
};

#endif /* SCHEDULER_FACTORY_H_ */
