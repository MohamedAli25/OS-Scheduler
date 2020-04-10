#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QProgressBar>
#include <QTableWidget>
#include <QSlider>
#include <QLabel>
#include <QScrollArea>
#include <QFormLayout>
#include <QHeaderView>
#include <QMap>
#include <QPair>
#include <QDebug>
#include <QTimer>

#include <algorithm>

#include "ganttchart.h"
#include "../Core/Factories/process_factory.h"
#include "../Core/Factories/scheduler_factory.h"
#include "../Core/Process/process.h"
#include "../Core/Data_Structures/Min_Priority_Queue/min_priority_queue.h"
using namespace QtCharts;
class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QMap<QString, QObject> Children;
    ~MainWindow();

private:
    QWidget *mainWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout;
    QVBoxLayout *rightLayout;
    QVBoxLayout *leftLayout;
    QHBoxLayout *topLeftLayout;
    QHBoxLayout *botLeftLayout;

    QSlider *unitTimeSlider;
    QLabel *unitTimelbl;
    QComboBox *schedularType;
    QTableWidget *processesTable;
    QPushButton *newBtn;
    QPushButton *runBtn;
    QPushButton *clearBtn;
    QPushButton *pauseBtn;
    QPushButton *contBtn;
    QPushButton *stopBtn;

    QLabel *pidLbl;
    QLabel *arrivalTimeLbl;
    QLabel *burstTimeLbl;
    QLabel *remainigBurstTimeLbl;
    QLabel *waitingTimeLbl;
    QLabel *endTimeLbl;

    QScrollArea *progressBarScrollArea;
    QHBoxLayout *rightBottomLayout;
    QFormLayout *progressLayout;
    QLabel *timeLbl;

    QFormLayout *infoLayout;

    GanttChart *ganttChart;

    enum SchedularTable{
        PRIORITY,
        WITHOUT_PRIORITY
    };

    QMap<int, QPair<QLabel*, QProgressBar*>> progressBarMap;
    QMap<int, Process*> processesMap;
    MinPriorityQueue<Process> *runTimeQueue;

    QTimer *simulationTimer;
    Scheduler *s;

    bool simulationStarted = false;
    bool simulationEnded = false;
    int processesCount = 0;

    int time = 0;

    void draw();
    void initSchedularTable(SchedularTable type);
    void addNewProcess();
    void clearProcess();
    void processesTableItemChanged(QTableWidgetItem* item);
    void unitTimeSliderValueChanged(int value);
    void runSimulation();
    void simulationCallback();
    void onProcessesTableDoubleClick(int row, int col);
    void showProcessInfo(Process *p);
    bool checkProcessesMissingData();
    bool checkProcessMissingData(int row, bool checkForArrival = false);
    void schedularTypeChanged(const QString &);
    void pauseSimulation();
    void contineSimulation();
    void stopSimulation();

};
#endif // MAINWINDOW_H
