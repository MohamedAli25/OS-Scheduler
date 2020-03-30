#ifndef PROCESS_H_
#define PROCESS_H_

#include <QString>

using namespace std;

class Process{
private:
    QString name;
    unsigned long long burstTime;
    unsigned long long arrivalTime;

public:
    Process(QString name, unsigned long long burstTime, unsigned long long arrivalTime);
    void setName(QString name);
    QString getName();
    void setBurstTime(unsigned long long burstTime);
    unsigned long long getBurstTime();
    void setArrivalTime(unsigned long long arrivalTime);
    unsigned long long getArrivalTime();
};

#endif /* PROCESS_H_ */
