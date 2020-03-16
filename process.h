#ifndef PROCESS_H_
#define PROCESS_H_

#include <string>

using namespace std;

class Process
{
private:
    string name;
    long long burstTime;
    long long arrivalTime;

public:
    Process(string name, long long burstTime, long long arrivalTime);
    void setName(string name);
    string getName();
    void setBurstTime(long long burstTime);
    long long getBurstTime();
    void setArrivalTime(long long arrivalTime);
    long long getArrivalTime();
};

#endif /* PROCESS_H_ */