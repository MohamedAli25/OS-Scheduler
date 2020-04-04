#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){

    mainWidget = new QWidget;
    mainLayout = new QVBoxLayout;
    topLayout = new QHBoxLayout;
    rightLayout = new QVBoxLayout;
    leftLayout = new QVBoxLayout;
    topLeftLayout = new QHBoxLayout;
    botLeftLayout = new QHBoxLayout;
    unitTimeSlider = new QSlider(Qt::Horizontal);
    unitTimelbl = new QLabel("Time unit (ms) ");
    schedularType = new QComboBox();
    processesTable = new QTableWidget;
    newBtn = new QPushButton("New");
    runBtn = new QPushButton("Run");
    clearBtn = new QPushButton("Clear");
    progressBarScrollArea = new QScrollArea();
    progressLayout = new QFormLayout();
    infoLayout = new QFormLayout;
    ganttChart = new GanttChart;
    simulationTimer = new QTimer();

    draw();

    schedularType->addItems(SchedulerFactory::SupportedSchedulers);

    connect(newBtn, &QPushButton::clicked, this, &MainWindow::addNewProcess);
    connect(processesTable, &QTableWidget::itemChanged, this, &MainWindow::processesTableItemChanged);
    connect(clearBtn,  &QPushButton::clicked, this, &MainWindow::clearProcess);
    connect(unitTimeSlider, &QSlider::valueChanged, this, &MainWindow::unitTimeSliderValueChanged);
    connect(simulationTimer, &QTimer::timeout, this, &MainWindow::simulationCallback);
    connect(runBtn, &QPushButton::clicked, this, &MainWindow::runSimulation);
}

void MainWindow::draw(){
    this->setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);
    mainLayout->addLayout(topLayout);
    topLayout->addLayout(leftLayout);
    topLayout->addLayout(rightLayout);
    leftLayout->addLayout(topLeftLayout);
    mainLayout->addWidget(ganttChart);
    topLeftLayout->addWidget(unitTimelbl);
    topLeftLayout->addWidget(unitTimeSlider);
    topLeftLayout->addWidget(schedularType);
    leftLayout->addWidget(processesTable);
    leftLayout->addLayout(botLeftLayout);
    botLeftLayout->addWidget(newBtn);
    botLeftLayout->addWidget(clearBtn);
    botLeftLayout->addWidget(runBtn);
    rightLayout->addWidget(progressBarScrollArea);
    progressBarScrollArea->setLayout(progressLayout);
    progressLayout->setSpacing(10);

    rightLayout->addLayout(infoLayout);
    infoLayout->addRow("PID : ", new QLabel(""));
    infoLayout->addRow("Process Name : ", new QLabel(""));
    infoLayout->addRow("Exe time : ", new QLabel(""));

    schedularType->setMinimumWidth(200);

    processesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    initSchedularTable(WITHOUT_PRIORITY);

    ganttChart->setMaximumHeight(200);
}

void MainWindow::initSchedularTable(SchedularTable type){
    if(type == SchedularTable::PRIORITY){
        processesTable->setColumnCount(4);
        processesTable->setHorizontalHeaderLabels({"PID", "Arrival Time", "Burst Time", "Priority"});
    }else{
        processesTable->setColumnCount(3);
        processesTable->setHorizontalHeaderLabels({"PID", "Arrival Time", "Burst Time"});
    }
}

void MainWindow::addNewProcess(){
    processesTable->insertRow(processesTable->rowCount());
}

void MainWindow::processesTableItemChanged(QTableWidgetItem *item){
    QString name = processesTable->item(item->row(),0)->text();
    if(!progressBarMap.contains(item->row())){
        QProgressBar *bar = new QProgressBar();
        QLabel *pidLabel = new QLabel(name + " : ");
        progressLayout->addRow(pidLabel, bar);
        progressBarMap.insert(item->row(), QPair<QLabel*, QProgressBar*>(pidLabel, bar));
    }else{
        progressBarMap[item->row()].first->setText(name + " : ");
    }
}

void MainWindow::clearProcess(){
    int activeRow = processesTable->selectedItems()[0]->row();
    progressLayout->takeRow(progressBarMap[activeRow].second);
    delete progressBarMap[activeRow].second;
    delete progressBarMap[activeRow].first;
    progressBarMap.remove(activeRow);
    processesTable->removeRow(activeRow);
    int counter = activeRow;
    for(; counter < processesTable->rowCount(); counter++)
        progressBarMap[counter] =  progressBarMap[counter+1];
    progressBarMap.remove(counter);
}

void MainWindow::unitTimeSliderValueChanged(int value){
    unitTimelbl->setText("Time uint (ms) " + QString::number(value * 50) + " : ");
}

void MainWindow::runSimulation(){
    QString type = schedularType->itemText(schedularType->currentIndex());
    s = SchedulerFactory::createScheduler(type);

//    for(int counter = 0; counter < processesTable->rowCount(); counter++){
//        int burstTime = processesTable->item(counter,2)->text().toInt();
//        int arrivalTime = processesTable->item(counter,1)->text().toInt();
//        QString name = processesTable->item(counter,0)->text();
//        s->addProcess(ProcessFactory::createProcess(NORMAL,counter,name,burstTime,arrivalTime));
//    }
    simulationTimer->start(100);
}

void MainWindow::simulationCallback(){
    Process *p = s->next(0,1);
    if (p == nullptr){
        simulationTimer->stop();
        return;
    }
    progressBarMap[p->getID()].second->setValue(100-(p->getRemainingBurstTime()/p->getBurstTime())*100);
}

MainWindow::~MainWindow(){
}
