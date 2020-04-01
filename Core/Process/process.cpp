#include "process.h"

Process::Process(QString name, double burstTime, double arrivalTime) : name{name}, burstTime{burstTime}, arrivalTime{arrivalTime}, remainingBurstTime{burstTime}
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