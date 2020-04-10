#include "GUI/mainwindow.h"
#include "Core/Data_Structures/Min_Priority_Queue/min_priority_queue.h"
#include "Core/Process/process.h"

#include "Core/Factories/scheduler_factory.h"
#include "Core/Factories/process_factory.h"
#include "Core/Data_Structures/Min_Priority_Queue/min_priority_queue.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QFile styleFile ("://css//style.css");
//    styleFile.open(QIODevice::ReadOnly);
//    QString style = styleFile.readAll();
//    a.setStyleSheet(style);
    MainWindow w;
    w.show();
//    MinPriorityQueue<Process> min(Process::lessArrivalTime);
//    Scheduler *s = SchedulerFactory::createScheduler("Round Robin");
//    Process *p1 = ProcessFactory::createProcess(s->getProcessType(),0,"p1",3,0);
//    Process *p2 = ProcessFactory::createProcess(s->getProcessType(),0,"p2",5,0);
//    s->addProcess(p1);
//    s->addProcess(p2);
//    qDebug() << s->next(1,1)->getName();
//    qDebug() << s->next(1,1)->getName();
//    qDebug() << s->next(1,1)->getName();
//    qDebug() << s->next(1,1)->getName();
    qDebug("Finished");

    return a.exec();
}
