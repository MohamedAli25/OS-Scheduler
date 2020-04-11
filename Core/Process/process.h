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
    double endTime = -1;
    double startTime = -1;
    int id;
    int priority;

public:
    Process(int id, QString name, double burstTime, double arrivalTime, int priority = -1);
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
    void setEndTime(double endTime);
    double getEndTime();
    void setStartTime(double startTime);
    double getStartTime();
    void setPriority(int priority);
    int getPriority();


    // Static Methods
    // less functions
    static bool lessArrivalTime(const Process &l, const Process &r);
    static bool lessBurstTime(const Process &l, const Process &r);
    static bool lessRemainingBurstTime(const Process &l, const Process &r);
    static bool lessPriority(const Process &l, const Process &r);
    // compareTo functions
    static bool compareToArrivalTime(const Process &l, const Process &r);
    static bool compareToBurstTime(const Process &l, const Process &r);
    static bool compareToRemainingBurstTime(const Process &l, const Process &r);
    static bool compareToPriority(const Process &l, const Process &r);
};

#endif /* PROCESS_H_ */
