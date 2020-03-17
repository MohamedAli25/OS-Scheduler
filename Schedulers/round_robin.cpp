#include "round_robin.h"

bool RoundRobin::compare(Process p1, Process p2)
{
    return (p1.getArrivalTime() < p2.getArrivalTime());
}

RoundRobin::RoundRobin(unsigned long long quantum) : quantum{quantum}
{
}

void RoundRobin::addProcess(Process process)
{
    processes.push_back(process);
}

vector<pair<string, unsigned long long>> RoundRobin::generateTimeline()
{
    vector<pair<string, unsigned long long>> timeline;
    sort(processes.begin(), processes.end(), compare);
    unsigned long long time = 0;
    for (Process p : processes)
    {
        arrivalTimeSum += p.getArrivalTime();
        burstTimeSum += p.getBurstTime();
        numberOfProcesses++;
    }
    while (1)
    {
        bool remainingWork = false;
        for (Process p : processes)
        {
            if (time < p.getArrivalTime())
            {
                remainingWork = true;
                continue;
            }
            else
            {
                if (p.getBurstTime() == 0)
                    continue;
                else if (p.getBurstTime() < quantum)
                {
                    time += p.getBurstTime();
                    finishTimeSum += time;
                    pair<string, unsigned long long> interval = {p.getName(), p.getBurstTime()};
                    timeline.push_back(interval);
                    p.setBurstTime(0);
                }
                else
                {
                    remainingWork = true;
                    time += quantum;
                    p.setBurstTime(p.getBurstTime() - quantum);
                    pair<string, unsigned long long> interval = {p.getName(), quantum};
                    timeline.push_back(interval);
                }
            }
        }
        if (!remainingWork)
            break;
    }
    return timeline;
}