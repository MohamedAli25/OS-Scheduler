#include "ganttchart.h"

GanttChart::GanttChart(){
    this->setLayout(new QVBoxLayout);

    chart = new QChart;
    series = new QHorizontalStackedBarSeries;
    chartView = new QChartView(chart);
    this->layout()->addWidget(chartView);
    chart->setTitle("Processes Gantt Chart");
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->addSeries(series);
    axis = new QBarCategoryAxis();

    setMap.insert("GAP",Qt::white);
}

void GanttChart::addValue(QString setName, int value){
    QBarSet *set = new QBarSet(setName, this);
    *set << value;
    if(setMap.contains(setName)){
        setToBeRemoved << counter;
        set->setColor(setMap[setName]);
    }else{
        set->setColor(colors[colorCounter]);
        colorCounter ++;
        if(colorCounter > colors.size()-1) colorCounter = 0;
    }
    series->append(set);
    chart->removeSeries(series);
    chart->addSeries(series);
//    chart->createDefaultAxes();
    for(int a : setToBeRemoved) chart->legend()->markers()[a]->setVisible(false);
    setMap.insert(setName, chart->legend()->markers()[counter]->brush().color());
    counter ++;
    if(timeLine.size() && !timeLine[timeLine.size()-1].first.compare(setName)){
        timeLine[timeLine.size()-1].second++;
    }else{
        timeLine.append(QPair<QString, int>(setName,1));
    }
}

void GanttChart::reset(){
    colorCounter = 0;
    counter = 0;
    setMap.clear();
    setToBeRemoved.clear();
    timeLine.clear();
    setMap.insert("GAP",Qt::gray);
    if(!beautified){
        series->clear();
    }else{
        delete gScene;
        delete gView;
        chart = new QChart;
        series = new QHorizontalStackedBarSeries;
        chartView = new QChartView(chart);
        this->layout()->addWidget(chartView);
        chart->setTitle("Processes Gantt Chart");
        chart->legend()->setAlignment(Qt::AlignBottom);
        chart->addSeries(series);
        axis = new QBarCategoryAxis();
    }
    beautified = false;
}

void GanttChart::beautify(){
    delete chartView;
    beautified = true;
    gScene = new QGraphicsScene();
    gView = new QGraphicsView(gScene);
    gView->setMinimumWidth(800);
    this->layout()->addWidget(gView);
    int x = 0;
    int screenW = this->size().rwidth() - 20;
    int ganttWidth = 0;
    double time = 0;
    for(auto a : timeLine){
        ganttWidth += a.second;
    }
    QGraphicsTextItem *s = gScene->addText("0");
    s->setPos(x+10,80);
    s->setFont(QFont("",7));
    for(auto a : timeLine){
        QGraphicsRectItem *rect = new QGraphicsRectItem(x+10,40,(screenW/ganttWidth)*a.second,30);
        rect->setBrush(setMap[a.first]);
        gScene->addItem(rect);
        s = gScene->addText(QString::number(time*0.1));
        s->setPos(x+10,80);
        s->setFont(QFont("",7));
        x += (screenW/ganttWidth)*a.second;
        time += a.second;
    }
    s = gScene->addText(QString::number(x/(10*(screenW/ganttWidth))));
    s->setPos(x+10,80);
    s->setFont(QFont("",7));
    s = gScene->addText("Beautified Gantt Chart");
    s->setPos((screenW/2)-120,0);
    s->setFont(QFont("",12));

    x = 20;
    for(auto key : setMap.keys()){
        QGraphicsRectItem *rect = new QGraphicsRectItem(x+10,120,10,10);
        rect->setBrush(setMap[key]);
        gScene->addItem(rect);
        s = gScene->addText(key);
        s->setPos(x+20,112);
        x+= 100;
    }

}
