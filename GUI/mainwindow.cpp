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
    //------------------------------------------ Drawing Section --------------------------------------------------------------//
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

    // TODO
    rightLayout->addLayout(infoLayout);
    infoLayout->addRow("PID : ", new QLabel(""));
    infoLayout->addRow("Process Name : ", new QLabel(""));
    infoLayout->addRow("Exe time : ", new QLabel(""));

    schedularType->setMinimumWidth(200);
    schedularType->addItems(SchedulerFactory::SupportedSchedulers);

    processesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    initSchedularTable(WITHOUT_PRIORITY);

    ganttChart->setMaximumHeight(200);

    simulationTimer->start(1000);

    connect(newBtn, &QPushButton::clicked, this, &MainWindow::addNewProcess);
    connect(processesTable, &QTableWidget::itemChanged, this, &MainWindow::processesTableItemChanged);
    connect(clearBtn,  &QPushButton::clicked, this, &MainWindow::clearProcess);
    connect(unitTimeSlider, &QSlider::valueChanged, this, &MainWindow::unitTimeSliderValueChanged);
    connect(simulationTimer, &QTimer::timeout, this, &MainWindow::callback);
    connect(runBtn, &QPushButton::clicked, this, &MainWindow::runSimulation);
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
    int burstTime = 0;
    int arrivalTime = 0;
    QString name = "";
    if(processesTable->item(item->row(),2) != nullptr) burstTime = processesTable->item(item->row(),2)->text().toInt();
    if(processesTable->item(item->row(),1) != nullptr) arrivalTime = processesTable->item(item->row(),1)->text().toInt();
    if(processesTable->item(item->row(),0) != nullptr) name = processesTable->item(item->row(),0)->text();
    if(!progressBarMap.contains(item->row())){
        QProgressBar *bar = new QProgressBar();
        QLabel *pidLabel = new QLabel(name + " : ");
        progressLayout->addRow(pidLabel, bar);
        progressBarMap.insert(item->row(), QPair<QLabel*, QProgressBar*>(pidLabel, bar));
        Process *p = ProcessFactory::createProcess(NORMAL, name,burstTime, arrivalTime);
        processesMap.insert(item->row(), p);
    }else{
        progressBarMap[item->row()].first->setText(name + " : ");
        Process *p = processesMap[item->row()];
        p->setName(name);
        p->setBurstTime(burstTime);
        p->setArrivalTime(arrivalTime);
    }
}

void MainWindow::clearProcess(){
    int activeRow = processesTable->selectedItems()[0]->row();
    progressLayout->takeRow(progressBarMap[activeRow].second);
    delete progressBarMap[activeRow].second;
    delete progressBarMap[activeRow].first;
    progressBarMap.remove(activeRow);
    processesTable->removeRow(activeRow);
    delete processesMap[activeRow];
    processesMap.remove(activeRow);
}

void MainWindow::unitTimeSliderValueChanged(int value){
    unitTimelbl->setText("Time uint (ms) " + QString::number(value * 50) + " : ");
}

void MainWindow::runSimulation(){
    QString type = schedularType->itemText(schedularType->currentIndex());
    Scheduler *s = SchedulerFactory::createScheduler(type);
    for(int key : processesMap.keys()){
        Process *p = processesMap[key];
        s->addProcess(p);
        qDebug() << "Name : " << p->getName() << "Arrival Time : " << p->getArrivalTime() << "Burst time : " << p->getBurstTime();
    }
    Process *p;
    do{
        p = s->next(0,5);
        if (p != nullptr) qDebug() << p->getBurstTime();
        qDebug("h");
    }while(p != nullptr);
}

void MainWindow::callback(){
}

MainWindow::~MainWindow(){
}
