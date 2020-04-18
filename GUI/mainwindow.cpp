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
    infoTabWidget = new QTabWidget;
    processesTab = new QWidget;
    newBtn = new QPushButton("New");
    runBtn = new QPushButton("Run");
    clearBtn = new QPushButton("Clear");
    pauseBtn = new QPushButton("Pause");
    contBtn = new QPushButton("Continue");
    stopBtn = new QPushButton("Stop");
    resetBtn = new QPushButton("Reset");
    progressBarScrollArea = new QScrollArea();
    progressLayout = new QFormLayout();
    rightBottomLayout = new QHBoxLayout();
    infoLayout = new QFormLayout;
    timeLbl = new QLabel("Time : 0");
    ganttChart = new GanttChart;
    simulationTimer = new QTimer();
    progressBarsContainerWidget = new QWidget;
    runTimeQueue = new MinPriorityQueue<Process>(Process::lessArrivalTime);
    s = SchedulerFactory::createScheduler(SchedulerFactory::SupportedSchedulers[0]);

    pidLbl = new QLabel();
    arrivalTimeLbl = new QLabel();
    burstTimeLbl = new QLabel();
    remainigBurstTimeLbl = new QLabel();
    waitingTimeLbl = new QLabel();
    endExeLbl = new QLabel();
    startExeLbl = new QLabel();
    turnaroundTimeLbl = new QLabel();
    exeTimeLbl = new QLabel();

    schedularTab = new QWidget;
    schedularInfoLayout = new QFormLayout;
    schedularAverageWaitingTime = new QLabel;
    schedularEndSimulationTime = new QLabel;

    quantumTxtBox = new QLineEdit;

    beautifyChartBtn = new QPushButton("Beautify Gantt Chart");
    beautifyChartBtn->setVisible(false);

    draw();

    quantumTxtBox->setVisible(false);
    quantumTxtBox->setPlaceholderText("Quantum");
    schedularType->addItems(SchedulerFactory::SupportedSchedulers);
    runBtn->setEnabled(false);
    pauseBtn->setEnabled(false);
    contBtn->setEnabled(false);
    stopBtn->setEnabled(false);
    resetBtn->setEnabled(false);
    unitTimeSlider->setValue(90);
    unitTimeSliderValueChanged(90);

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
    connect(resetBtn, &QPushButton::clicked, this, &MainWindow::resetSimulation);
    connect(beautifyChartBtn, &QPushButton::clicked, this, &MainWindow::beautifyGanttChart);

}

void MainWindow::draw(){
    this->setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);
    mainLayout->addLayout(topLayout);
    topLayout->addLayout(leftLayout);
    topLayout->addLayout(rightLayout);
    leftLayout->addLayout(topLeftLayout);
    mainLayout->addWidget(ganttChart);
    leftLayout->addLayout(botLeftLayout);
    leftLayout->addWidget(processesTable);
    mainLayout->addWidget(beautifyChartBtn);


    topLeftLayout->addWidget(unitTimelbl);
    topLeftLayout->addWidget(unitTimeSlider);
    topLeftLayout->addWidget(schedularType);
    topLeftLayout->addWidget(quantumTxtBox);

    botLeftLayout->addWidget(newBtn);
    botLeftLayout->addWidget(clearBtn);
    botLeftLayout->addWidget(runBtn);
    botLeftLayout->addWidget(stopBtn);
    botLeftLayout->addWidget(pauseBtn);
    botLeftLayout->addWidget(contBtn);
    botLeftLayout->addWidget(resetBtn);
    rightLayout->addWidget(progressBarScrollArea);

    progressBarsContainerWidget->setLayout(progressLayout);
    progressBarScrollArea->setWidgetResizable(true);
    progressBarScrollArea->setWidget(progressBarsContainerWidget);

    progressLayout->setSpacing(10);

    rightLayout->addLayout(rightBottomLayout);
    rightBottomLayout->addWidget(infoTabWidget);
    infoTabWidget->addTab(processesTab, "Procsses Info");
    infoTabWidget->addTab(schedularTab, "Scheduling Info");
    processesTab->setLayout(infoLayout);
    schedularTab->setLayout(schedularInfoLayout);

    schedularType->setMinimumWidth(200);

    timeLbl->setStyleSheet("font-size : 20px; font-weight : bold");

    processesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    initSchedularTable(NORMAL);

    ganttChart->setMaximumHeight(200);

    infoLayout->addRow("PID : ", pidLbl);
    infoLayout->addRow("Arrival Time : ", arrivalTimeLbl);
    infoLayout->addRow("Burst Time : ", burstTimeLbl);
    infoLayout->addRow("Remaining Burst Time : ", remainigBurstTimeLbl);
    infoLayout->addRow("Waiting Time : ", waitingTimeLbl);
    infoLayout->addRow("Start Execution : ", startExeLbl);
    infoLayout->addRow("End Execution : ", endExeLbl);
    infoLayout->addRow("Execution Time : ", exeTimeLbl);
    infoLayout->addRow("Turnaround Time : ", turnaroundTimeLbl);

    schedularInfoLayout->addRow("End Simulation Time : ", schedularEndSimulationTime);
    schedularInfoLayout->addRow("Average Waiting Time :  ", schedularAverageWaitingTime);
}

void MainWindow::initSchedularTable(ProcessEnum type){
    if(type == ProcessEnum::PRIORITY){
        processesTable->setColumnCount(4);
        processesTable->setHorizontalHeaderLabels({"PID", "Arrival Time", "Burst Time", "Priority"});
    }else{
        processesTable->setColumnCount(3);
        processesTable->setHorizontalHeaderLabels({"PID", "Arrival Time", "Burst Time"});
    }
}

void MainWindow::schedularTypeChanged(const QString &type){
    s = SchedulerFactory::createScheduler(type);
    quantumTxtBox->setVisible(!type.compare(SchedulerFactory::SupportedSchedulers[3]));
    initSchedularTable(s->getProcessType());
}

void MainWindow::addNewProcess(){
    processesTable->insertRow(processesTable->rowCount());
    for(int c = 0; c < processesTable->columnCount(); c++){
        processesTable->setItem(processesTable->rowCount()-1,c,new QTableWidgetItem);
    }
    if(!simulationStarted)runBtn->setEnabled(true);
}

void MainWindow::processesTableItemChanged(QTableWidgetItem *item){
    double activeRow = item->row();
    double burstTime = 0;
    double arrivalTime = 0;
    QString name = "";
    int priority = -1;
    if(processesTable->item(activeRow,2) != nullptr) burstTime = processesTable->item(activeRow,2)->text().toFloat()*10;
    if(processesTable->item(activeRow,1) != nullptr) arrivalTime = processesTable->item(activeRow,1)->text().toFloat()*10;
    if(processesTable->item(activeRow,0) != nullptr) name = processesTable->item(activeRow,0)->text();
    if(processesTable->item(activeRow,3) != nullptr && s->getProcessType() == PRIORITY){
        priority = processesTable->item(activeRow,3)->text().toInt();
    }
    if(name.compare("")){
        if(!progressBarMap.contains(activeRow)){
            QProgressBar *bar = new QProgressBar();
            QLabel *pidLabel = new QLabel(name + " : ");
            progressLayout->addRow(pidLabel, bar);
            progressBarMap.insert(activeRow, QPair<QLabel*, QProgressBar*>(pidLabel, bar));
            Process *p = ProcessFactory::createProcess(s->getProcessType(),activeRow,name,burstTime,arrivalTime,priority);
            processesMap.insert(item->row(),p);
        }else{
            progressBarMap[item->row()].first->setText(name + " : ");
            Process *p = processesMap[item->row()];
            p->setName(name);
            p->setBurstTime(burstTime);
            p->setArrivalTime(arrivalTime);
            if(s->getProcessType() == PRIORITY) p->setPriority(priority);
        }
    }
}

void MainWindow::clearProcess(){
    if(processesTable->selectedItems().size() == 0)
        return;
    int activeRow = processesTable->selectedItems()[0]->row();
    processesTable->removeRow(activeRow);
    if(progressBarMap.contains(activeRow)){
        progressLayout->takeRow(progressBarMap[activeRow].second);
        delete progressBarMap[activeRow].second;
        delete progressBarMap[activeRow].first;
        progressBarMap.remove(activeRow);
        delete processesMap[activeRow];
        processesMap.remove(activeRow);
        int counter = activeRow;
        for(; counter < processesTable->rowCount(); counter++){
            progressBarMap[counter] =  progressBarMap[counter+1];
            processesMap[counter] = processesMap[counter+1];
            processesMap[counter]->setID(counter);
        }
        progressBarMap.remove(counter);
        processesMap.remove(counter);
    }
    if(!processesTable->rowCount()) runBtn->setEnabled(false);
}

void MainWindow::unitTimeSliderValueChanged(int value){
    unitTimelbl->setText("Simulation Speed " + QString::number(value) + " : ");
    simulationTimer->setInterval(100 - value);
}

void MainWindow::runSimulation(){
    delete s;
    QString quantum = quantumTxtBox->text();
    if(!quantum.compare("")) quantum = "1";
    s = SchedulerFactory::createScheduler(schedularType->currentText(), quantum.toInt()*10);
    if(checkProcessesMissingData()) return;
    for(Process *p : processesMap){
        runTimeQueue->insert(*p);
    }

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
    setWindowTitle("Schedular - Simulating [Running] time : " + QString::number(time/10));
    time++;
}

void MainWindow::showProcessInfo(Process *p){
    pidLbl->setText(p->getName());
    arrivalTimeLbl->setText(QString::number(p->getArrivalTime()*0.1));
    burstTimeLbl->setText(QString::number(p->getBurstTime()*0.1));
    remainigBurstTimeLbl->setText(QString::number(p->getRemainingBurstTime()*0.1));
    waitingTimeLbl->setText(p->getStartTime() > -1 ?
                                QString::number((p->getStartTime() - p->getArrivalTime())*0.1) : "Not Started");
    startExeLbl->setText(p->getStartTime() > - 1 ? QString::number(p->getStartTime()*0.1) : "Not Started");
    endExeLbl->setText(p->getEndTime() > 0 ? QString::number((p->getEndTime()+1)*0.1) : "Not Finished");
    exeTimeLbl->setText(p->getEndTime() > 0 ? QString::number((p->getEndTime()+1 - p->getStartTime())*0.1) : "Not Finished");
    turnaroundTimeLbl->setText(p->getEndTime() > 0 ? QString::number((p->getEndTime()+1 - p->getArrivalTime())*0.1) : "Not Finished");
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
    int priority = -1;
    if(processesTable->item(row,2) != nullptr) burstTime = processesTable->item(row,2)->text().toInt();
    if(processesTable->item(row,1) != nullptr) arrivalTime = processesTable->item(row,1)->text().toInt()*10;
    if(processesTable->item(row,0) != nullptr) name = processesTable->item(row,0)->text();
    if(processesTable->item(row,3) != nullptr && s->getProcessType() == PRIORITY){
        if(processesTable->item(row,3)->text().compare(""))
            priority = processesTable->item(row,3)->text().toInt();
    }
    QColor c;
    qDebug() << burstTime << name << checkForArrival << arrivalTime;
    if(burstTime == 0 || !name.compare("") || (checkForArrival && arrivalTime < time) ||
            (s->getProcessType() == PRIORITY && priority == -1)){
        c = Qt::red;
        err = true;
    }else{
        c = Qt::white;
    }
    int colCount = s->getProcessType() == PRIORITY ? 4 : 3;
    for(int a = 0; a < colCount; a++){
        if(processesTable->item(row, a) == nullptr) processesTable->setItem(row, a, new QTableWidgetItem);
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
    setWindowTitle("Schedular - Simulating [Paused] time : " + QString::number(time/10));
}

void MainWindow::stopSimulation(){
    simulationTimer->stop();
    stopBtn->setEnabled(false);
    pauseBtn->setEnabled(false);
    contBtn->setEnabled(false);
    runBtn->setEnabled(false);
    resetBtn->setEnabled(true);

    schedularEndSimulationTime->setText(QString::number(time*0.1));
    int sum = 0;
    int processCount = 0;
    for(Process *p : processesMap){
        processCount++;
        sum += p->getEndTime() + 1 - p->getBurstTime() - p->getArrivalTime();
    }
    schedularAverageWaitingTime->setText(QString::number(sum/(processCount)*0.1));
    timeLbl->setText("Time : 0");
    setWindowTitle("Schedular - Simualting [Stopped] time : " + QString::number(time/10));
    beautifyChartBtn->setVisible(true);

    simulationEnded = true;
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

void MainWindow::resetSimulation(){
    time = 0;
    ganttChart->reset();
    for(auto a : progressBarMap.keys()){
        progressBarMap[a].second->setValue(0);
    }
    for(Process *p : processesMap){
        p->setRemainingBurstTime(p->getBurstTime());
        p->setEndTime(0);
    }
    stopBtn->setEnabled(false);
    pauseBtn->setEnabled(false);
    contBtn->setEnabled(false);
    runBtn->setEnabled(true);
    resetBtn->setEnabled(false);
    simulationEnded = false;
    simulationStarted = false;
    timeLbl->setText("Time : 0");
    setWindowTitle("Schedular");

    pidLbl->setText("");
    arrivalTimeLbl->setText("");
    burstTimeLbl->setText("");
    remainigBurstTimeLbl->setText("");
    waitingTimeLbl->setText("");
    startExeLbl->setText("");
    endExeLbl->setText("");
    exeTimeLbl->setText("");
    turnaroundTimeLbl->setText("");
    schedularAverageWaitingTime->setText("");
    schedularEndSimulationTime->setText("");
    beautifyChartBtn->setVisible(false);
}

void MainWindow::beautifyGanttChart(){
    beautifyChartBtn->setVisible(false);
    ganttChart->beautify();
}

MainWindow::~MainWindow(){
}
