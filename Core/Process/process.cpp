#include "process.h"

Process::Process(int id, QString name, double burstTime, double arrivalTime) :
    name{name}, burstTime{burstTime}, arrivalTime{arrivalTime}, remainingBurstTime{burstTime}, id{id}
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

void Process::setID(int id){
    this->id = id;
}

int Process::getID(){
    return this->id;
}
