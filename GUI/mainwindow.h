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
#include <QTabWidget>
#include <QLineEdit>

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
    QPushButton *resetBtn;

    QTabWidget *infoTabWidget;
    QWidget *processesTab;
    QFormLayout *infoLayout;
    QLabel *pidLbl;
    QLabel *arrivalTimeLbl;
    QLabel *burstTimeLbl;
    QLabel *remainigBurstTimeLbl;
    QLabel *waitingTimeLbl;
    QLabel *startExeLbl;
    QLabel *endExeLbl;
    QLabel *exeTimeLbl;
    QLabel *turnaroundTimeLbl;

    QWidget *schedularTab;
    QFormLayout *schedularInfoLayout;
    QLabel *schedularAverageWaitingTime;
    QLabel *schedularEndSimulationTime;

    QScrollArea *progressBarScrollArea;
    QHBoxLayout *rightBottomLayout;
    QFormLayout *progressLayout;
    QLabel *timeLbl;
    QWidget *progressBarsContainerWidget;

    GanttChart *ganttChart;

    QMap<int, QPair<QLabel*, QProgressBar*>> progressBarMap;
    QMap<int, Process*> processesMap;
    MinPriorityQueue<Process> *runTimeQueue;

    QTimer *simulationTimer;
    Scheduler *s;

    QPushButton *beautifyChartBtn;
    QLineEdit *quantumTxtBox;

    bool simulationStarted = false;
    bool simulationEnded = false;
    int processesCount = 0;

    int time = 0;

    void draw();
    void initSchedularTable(ProcessEnum type);
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
    void resetSimulation();
    void beautifyGanttChart();

};
#endif // MAINWINDOW_H
