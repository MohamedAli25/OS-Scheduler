#include "process.h"

Process::Process(int id, QString name, double burstTime, double arrivalTime, int priority) :
    name{name}, burstTime{burstTime}, arrivalTime{arrivalTime}, remainingBurstTime{burstTime}, id{id}, priority{priority}
{
}

void Process::setName(QString name)
{
    this->name = name;
}

QString Process::getName()
{
    return name;
}

void Process::setBurstTime(double burstTime)
{
    this->burstTime = burstTime;
    this->remainingBurstTime = burstTime;
}

double Process::getBurstTime()
{
    return burstTime;
}

void Process::setArrivalTime(double arrivalTime)
{
    this->arrivalTime = arrivalTime;
}

double Process::getArrivalTime()
{
    return this->arrivalTime;
}

void Process::setRemainingBurstTime(double remainingBurstTime)
{
    this->remainingBurstTime = remainingBurstTime;
}

double Process::getRemainingBurstTime()
{
    return this->remainingBurstTime;
}

void Process::setID(int id)
{
    this->id = id;
}

int Process::getID()
{
    return this->id;
}

void Process::setEndTime(double t)
{
    this->endTime = t;
}

double Process::getEndTime()
{
    return this->endTime;
}

void Process::setStartTime(double t)
{
    this->startTime = t;
}

double Process::getStartTime()
{
    return this->startTime;
}

void Process::setPriority(int priority)
{
    this->priority = priority;
}

int Process::getPriority()
{
    return priority;
}


bool Process::lessArrivalTime(const Process &l, const Process &r)
{
    return (l.arrivalTime < r.arrivalTime);
}

bool Process::lessBurstTime(const Process &l, const Process &r)
{
    return (l.burstTime < r.burstTime);
}

bool Process::lessRemainingBurstTime(const Process &l, const Process &r)
{
    return (l.remainingBurstTime < r.remainingBurstTime);
}

bool Process::lessPriority(const Process &l, const Process &r)
{
    return (l.priority < r.priority);
}

bool Process::compareToPriority(const Process &l, const Process &r)
{
    if (l.priority < r.priority)
        return -1;
    else if (l.priority > r.priority)
        return 1;
    return 0;
}


bool Process::compareToArrivalTime(const Process &l, const Process &r)
{
    if (l.arrivalTime < r.arrivalTime)
        return -1;
    else if (l.arrivalTime > r.arrivalTime)
        return 1;
    return 0;
}

bool Process::compareToBurstTime(const Process &l, const Process &r)
{
    if (l.burstTime < r.burstTime)
        return -1;
    else if (l.burstTime > r.burstTime)
        return 1;
    return 0;
}

bool Process::compareToRemainingBurstTime(const Process &l, const Process &r)
{
    if (l.remainingBurstTime < r.remainingBurstTime)
        return -1;
    else if (l.remainingBurstTime > r.remainingBurstTime)
        return 1;
    return 0;
}
