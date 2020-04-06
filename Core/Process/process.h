#ifndef PROCESS_H_
#define PROCESS_H_

#include <QString>

using namespace std;

typedef enum ProcessEnum
{
    NORMAL,
    PRIORITY
} ProcessEnum;

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

    // Static Methods
    // less functions
    static bool lessArrivalTime(const Process &l, const Process &r);
    static bool lessBurstTime(const Process &l, const Process &r);
    static bool lessRemainingBurstTime(const Process &l, const Process &r);
    // compareTo functions
    static bool compareToArrivalTime(const Process &l, const Process &r);
    static bool compareToBurstTime(const Process &l, const Process &r);
    static bool compareToRemainingBurstTime(const Process &l, const Process &r);
};

#endif /* PROCESS_H_ */
