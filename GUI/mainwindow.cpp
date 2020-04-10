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
    pauseBtn = new QPushButton("Pause");
    contBtn = new QPushButton("Continue");
    stopBtn = new QPushButton("Stop");
    progressBarScrollArea = new QScrollArea();
    progressLayout = new QFormLayout();
    rightBottomLayout = new QHBoxLayout();
    infoLayout = new QFormLayout;
    timeLbl = new QLabel("Time : 0");
    ganttChart = new GanttChart;
    simulationTimer = new QTimer();
    runTimeQueue = new MinPriorityQueue<Process>(Process::lessArrivalTime);
    s = SchedulerFactory::createScheduler(SchedulerFactory::SupportedSchedulers[0]);

    pidLbl = new QLabel();
    arrivalTimeLbl = new QLabel();
    burstTimeLbl = new QLabel();
    remainigBurstTimeLbl = new QLabel();
    waitingTimeLbl = new QLabel();
    endTimeLbl = new QLabel();

    draw();

    schedularType->addItems(SchedulerFactory::SupportedSchedulers);
    runBtn->setEnabled(false);
    pauseBtn->setEnabled(false);
    contBtn->setEnabled(false);
    stopBtn->setEnabled(false);
    unitTimeSlider->setValue(20);
    unitTimeSliderValueChanged(20);

    connect(newBtn, &QPushButton::clicked, this, &MainWindow::addNewProcess);
    connect(processesTable, &QTableWidget::itemChanged, this, &MainWindow::processesTableItemChanged);
    connect(clearBtn,  &QPushButton::clicked, this, &MainWindow::clearProcess);
    connect(unitTimeSlider, &QSlider::valueChanged, this, &MainWindow::unitTimeSliderValueChanged);
    connect(simulationTimer, &QTimer::timeout, this, &MainWindow::simulationCallback);
    connect(runBtn, &QPushButton::clicked, this, &MainWindow::runSimulation);
    connect(processesTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::onProcessesTableDoubleClick);
    connect(schedularType,&QComboBox::currentTextChanged,this, &MainWindow::schedularTypeChanged);
    connect(pauseBtn, &QPushButton::clicked, this, &MainWindow::pauseSimulation);
    connect(stopBtn, &QPushButton::clicked, this, &MainWindow::stopSimulation);
    connect(contBtn, &QPushButton::clicked, this, &MainWindow::contineSimulation);

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
    botLeftLayout->addWidget(stopBtn);
    botLeftLayout->addWidget(pauseBtn);
    botLeftLayout->addWidget(contBtn);
    rightLayout->addWidget(progressBarScrollArea);
    progressBarScrollArea->setLayout(progressLayout);
    progressLayout->setSpacing(10);

    rightLayout->addLayout(rightBottomLayout);
    rightBottomLayout->addLayout(infoLayout);
    rightBottomLayout->addWidget(timeLbl);

    schedularType->setMinimumWidth(200);

    timeLbl->setStyleSheet("font-size : 20px; font-weight : bold");

    processesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    initSchedularTable(WITHOUT_PRIORITY);

    ganttChart->setMaximumHeight(200);

    infoLayout->addRow("PID : ", pidLbl);
    infoLayout->addRow("Arrival Time : ", arrivalTimeLbl);
    infoLayout->addRow("Burst Time : ", burstTimeLbl);
    infoLayout->addRow("Remaining Burst Time : ", remainigBurstTimeLbl);
    infoLayout->addRow("Waiting Time : ", waitingTimeLbl);
    infoLayout->addRow("End Time : ", endTimeLbl);
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

void MainWindow::schedularTypeChanged(const QString &type){
    s = SchedulerFactory::createScheduler(type);
}

void MainWindow::addNewProcess(){
    processesTable->insertRow(processesTable->rowCount());
    for(int c = 0; c < processesTable->columnCount(); c++){
        processesTable->setItem(processesTable->rowCount()-1,c,new QTableWidgetItem);
    }
    if(!simulationStarted)runBtn->setEnabled(true);
}

void MainWindow::processesTableItemChanged(QTableWidgetItem *item){
    int activeRow = item->row();
    int burstTime = 0;
    int arrivalTime = 0;
    QString name = "";
    if(processesTable->item(activeRow,2) != nullptr) burstTime = processesTable->item(activeRow,2)->text().toInt();
    if(processesTable->item(activeRow,1) != nullptr) arrivalTime = processesTable->item(activeRow,1)->text().toInt();
    if(processesTable->item(activeRow,0) != nullptr) name = processesTable->item(activeRow,0)->text();
    if(name.compare("")){
        if(!progressBarMap.contains(activeRow)){
            QProgressBar *bar = new QProgressBar();
            QLabel *pidLabel = new QLabel(name + " : ");
            progressLayout->addRow(pidLabel, bar);
            progressBarMap.insert(activeRow, QPair<QLabel*, QProgressBar*>(pidLabel, bar));
            Process *p = ProcessFactory::createProcess(s->getProcessType(),activeRow,name,burstTime,arrivalTime);
            processesMap.insert(item->row(),p);
        }else{
            progressBarMap[item->row()].first->setText(name + " : ");
            Process *p = processesMap[item->row()];
            p->setName(name);
            p->setBurstTime(burstTime);
            p->setArrivalTime(arrivalTime);
        }
    }
}

void MainWindow::clearProcess(){
    if(processesTable->selectedItems().size() == 0)
        return;
    int activeRow = processesTable->selectedItems()[0]->row();
    progressLayout->takeRow(progressBarMap[activeRow].second);
    delete progressBarMap[activeRow].second;
    delete progressBarMap[activeRow].first;
    progressBarMap.remove(activeRow);
    delete processesMap[activeRow];
    processesMap.remove(activeRow);
    processesTable->removeRow(activeRow);
    int counter = activeRow;
    for(; counter < processesTable->rowCount(); counter++){
        progressBarMap[counter] =  progressBarMap[counter+1];
        processesMap[counter] = processesMap[counter+1];
        processesMap[counter]->setID(counter);
    }
    progressBarMap.remove(counter);
    processesMap.remove(counter);
    if(!processesTable->rowCount()) runBtn->setEnabled(false);
}

void MainWindow::unitTimeSliderValueChanged(int value){
    unitTimelbl->setText("Time uint (ms) " + QString::number(value * 10) + " : ");
    simulationTimer->setInterval(value*10);
}

void MainWindow::runSimulation(){
    if(checkProcessesMissingData()) return;
    for(Process *p : processesMap) runTimeQueue->insert(*p);
    qDebug() << runTimeQueue->size();

    // Reseting GUI stuff
    ganttChart->reset();
    for(auto a : progressBarMap.keys()){
        progressBarMap[a].second->setValue(0);
    }
    simulationStarted = true;
    simulationEnded = false;
    simulationTimer->start();
    time = 0;
    pauseBtn->setEnabled(true);
    contBtn->setEnabled(false);
    stopBtn->setEnabled(true);
    runBtn->setEnabled(false);
}

void MainWindow::simulationCallback(){
    timeLbl->setText("Time : " + QString::number(time));
    while(runTimeQueue->size()){
        if(runTimeQueue->extractMin().getArrivalTime() == time){
            s->addProcess(processesMap[runTimeQueue->extractMin().getID()]);
            runTimeQueue->deleteMin();
        }else{
            break;
        }
    }
    Process *p = s->next(time,1);
    if (p != nullptr){
        progressBarMap[p->getID()].second->setValue(100-(p->getRemainingBurstTime()/p->getBurstTime())*100);
        processesMap[p->getID()]->setRemainingBurstTime(p->getRemainingBurstTime());
        processesMap[p->getID()]->setEndTime(p->getEndTime());
        processesMap[p->getID()]->setStartTime(p->getStartTime());
        ganttChart->addValue(p->getName(),1);
        showProcessInfo(p);
    }else{
        ganttChart->addValue("GAP",1);
    }
    time++;
}

void MainWindow::showProcessInfo(Process *p){
    pidLbl->setText(p->getName());
    arrivalTimeLbl->setText(QString::number(p->getArrivalTime()));
    burstTimeLbl->setText(QString::number(p->getBurstTime()));
    remainigBurstTimeLbl->setText(QString::number(p->getRemainingBurstTime()));
    waitingTimeLbl->setText(p->getStartTime() > 0 ?
                                QString::number(p->getStartTime() - p->getArrivalTime()) : "Not Started");
    endTimeLbl->setText(p->getEndTime() > 0 ? QString::number(p->getEndTime()) : "Not Finished");
}

void MainWindow::onProcessesTableDoubleClick(int row, int){
    if(simulationStarted && simulationEnded && processesMap.keys().contains(row)){
        showProcessInfo(processesMap[row]);
    }
}

bool MainWindow::checkProcessesMissingData(){
    bool err = false;
    for(int counter = 0; counter < processesTable->rowCount(); counter++){
        err = checkProcessMissingData(counter);
    }
    return err;
}

bool MainWindow::checkProcessMissingData(int row, bool checkForArrival){
    bool err = false;
    int burstTime = 0;
    int arrivalTime = 0;
    QString name = "";
    if(processesTable->item(row,2) != nullptr) burstTime = processesTable->item(row,2)->text().toInt();
    if(processesTable->item(row,1) != nullptr) arrivalTime = processesTable->item(row,1)->text().toInt();
    if(processesTable->item(row,0) != nullptr) name = processesTable->item(row,0)->text();
    QColor c;
    if((burstTime == 0 || !name.compare("")) || (checkForArrival && arrivalTime < time)){
        c = Qt::red;
        err = true;
        qDebug() << "ERROR";
    }else{
        c = Qt::white;
    }
    for(int a = 0; a < processesTable->columnCount(); a++){
        processesTable->item(row, a)->setBackground(c);
    }
    return err;
}

void MainWindow::pauseSimulation(){
    simulationTimer->stop();
    pauseBtn->setEnabled(false);
    contBtn->setEnabled(true);
    simulationEnded = true;
    processesCount = processesTable->rowCount();
}

void MainWindow::stopSimulation(){
    simulationTimer->stop();
    time = 0;
    ganttChart->reset();
    for(auto a : progressBarMap.keys()){
        progressBarMap[a].second->setValue(0);
    }
    for(Process *p : processesMap){
        p->setRemainingBurstTime(p->getBurstTime());
        p->setEndTime(0);
    }
    delete s;
    s = SchedulerFactory::createScheduler(schedularType->currentText());
    stopBtn->setEnabled(false);
    pauseBtn->setEnabled(false);
    contBtn->setEnabled(false);
    runBtn->setEnabled(true);
    simulationEnded = false;
    simulationStarted = false;
    timeLbl->setText("Time : 0");
}

void MainWindow::contineSimulation(){
    for(int a = processesCount; a < processesTable->rowCount();a++){
       if(checkProcessMissingData(a,true)) return;
    }
    for(int a = processesCount; a < processesTable->rowCount();a++){
       runTimeQueue->insert(*processesMap[a]);
    }
    simulationTimer->start();
    simulationEnded = false;
    pauseBtn->setEnabled(true);
    contBtn->setEnabled(false);
}

MainWindow::~MainWindow(){
}
