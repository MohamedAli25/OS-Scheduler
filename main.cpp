#include "GUI/mainwindow.h"
#include "Core/Data_Structures/Min_Priority_Queue/min_priority_queue.h"
#include "Core/Process/process.h"

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
    return a.exec();
}
