#ifndef PROCESS_H_
#define PROCESS_H_

#include <QString>

using namespace std;

class Process
{
private:
    QString name;
    double burstTime;
    double arrivalTime;
    double remainingBurstTime;

public:
    Process(QString name, double burstTime, double arrivalTime);
    void setName(QString name);
    QString getName();
    void setBurstTime(double burstTime);
    double getBurstTime();
    void setArrivalTime(double arrivalTime);
    double getArrivalTime();
    void setRemainingBurstTime(double arrivalTime);
    double getRemainingBurstTime();
};

#endif /* PROCESS_H_ */
