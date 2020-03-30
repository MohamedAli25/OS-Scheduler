#include "s_j_f_nonpreemptive.h"

void SJFNonpreemptive::addProcess(Process process)
{
    processes.push_back(process);
}

Process *SJFNonpreemptive::next()
{
}