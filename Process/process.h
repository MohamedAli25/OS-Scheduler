#ifndef PROCESS_H_
#define PROCESS_H_

#include <string>

using namespace std;

class Process
{
private:
    unsigned long long id;
    string name;
    unsigned long long burstTime;
    unsigned long long arrivalTime;

public:
    Process(unsigned long long id, string name, unsigned long long burstTime, unsigned long long arrivalTime);
    void setId(unsigned long long id);
    unsigned long long getId();
    void setName(string name);
    string getName();
    void setBurstTime(unsigned long long burstTime);
    unsigned long long getBurstTime();
    void setArrivalTime(unsigned long long arrivalTime);
    unsigned long long getArrivalTime();
};

#endif /* PROCESS_H_ */