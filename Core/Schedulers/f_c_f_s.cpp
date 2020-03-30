#include "f_c_f_s.h"

bool FCFS::compare(Process p1, Process p2){
    return (p1.getArrivalTime() < p2.getArrivalTime());
}

void FCFS::addProcess(Process *process){
    processes.push(*process);
    arrivalTimeSum += process->getArrivalTime();
    burstTimeSum += process->getBurstTime();
    numberOfProcesses += 1;
}

Process *FCFS::next(double currentTime, double timeSlice){
//    if (processes.front().getRemainingBurstTime() <= 0){
//        finishTimeSum += currentTime;
//        processes.pop();
//    }
}
