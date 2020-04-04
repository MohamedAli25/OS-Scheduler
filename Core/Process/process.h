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
    int id;

public:
    Process(int id, QString name, double burstTime, double arrivalTime);
    void setName(QString name);
    QString getName();
    void setBurstTime(double burstTime);
    double getBurstTime();
    void setArrivalTime(double arrivalTime);
    double getArrivalTime();
    void setRemainingBurstTime(double arrivalTime);
    double getRemainingBurstTime();
    void setID(int id);
    int getID();
};

#endif /* PROCESS_H_ */
