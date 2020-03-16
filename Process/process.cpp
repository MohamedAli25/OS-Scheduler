#include "process.h"

Process::Process(string name, unsigned long long burstTime, unsigned long long arrivalTime) : name{name}, burstTime{burstTime}, arrivalTime{arrivalTime}
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

void Process::setBurstTime(unsigned long long burstTime)
{
    this->burstTime = burstTime;
}

unsigned long long Process::getBurstTime()
{
    return burstTime;
}

void Process::setArrivalTime(unsigned long long arrivalTime)
{
    this->arrivalTime = arrivalTime;
}

unsigned long long Process::getArrivalTime()
{
    return this->arrivalTime;
}