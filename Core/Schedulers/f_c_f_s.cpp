#include "f_c_f_s.h"
#include <queue>

bool FCFS::compare(Process p1, Process p2){
    return (p1.getArrivalTime() < p2.getArrivalTime());
}

void FCFS::addProcess(Process process){
    processes.push_back(process);
}

vector<pair<QString, unsigned long long>> FCFS::generateTimeline(){
    vector<pair<QString, unsigned long long>> timeline;
    sort(processes.begin(), processes.end(), compare);
    unsigned long long time = 0;
    for (Process p : processes)    {
        this->arrivalTimeSum += p.getArrivalTime();
        this->burstTimeSum += p.getBurstTime();
        this->numberOfProcesses++;
        if (time < p.getArrivalTime())        {
            pair<QString, unsigned long long> emptyInterval = {"None", p.getArrivalTime() - time};
            timeline.push_back(emptyInterval);
            pair<QString, unsigned long long> busyInterval = {p.getName(), p.getBurstTime()};
            timeline.push_back(busyInterval);
            time = p.getArrivalTime() + p.getBurstTime();
        }else{
            pair<QString, unsigned long long> busyInterval = {p.getName(), p.getBurstTime()};
            timeline.push_back(busyInterval);
            time += p.getBurstTime();
        }
        this->finishTimeSum += time;
    }
    return timeline;
}
