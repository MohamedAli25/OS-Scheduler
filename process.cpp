#include "process.h"

Process::Process(string name, long long burstTime, long long arrivalTime) : name{name}, burstTime{burstTime}, arrivalTime{arrivalTime}
{
}

void Process::setName(string name)
{
    this->name = name;
}

string Process::getName()
{
    return name;
}

void Process::setBurstTime(long long burstTime)
{
    this->burstTime = burstTime;
}

long long Process::getBurstTime()
{
    return burstTime;
}

void Process::setArrivalTime(long long arrivalTime)
{
    this->arrivalTime = arrivalTime;
}

long long Process::getArrivalTime()
{
    return this->arrivalTime;
}