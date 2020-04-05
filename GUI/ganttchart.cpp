#include "ganttchart.h"

GanttChart::GanttChart(){
    chart = new QChart;
    series = new QHorizontalStackedBarSeries;

    this->setChart(chart);
    chart->setTitle("Processes Gantt Chart");
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->addSeries(series);
    chart->createDefaultAxes();
    axis = new QBarCategoryAxis();
    chart->setAxisY(axis, series);
    chart->axisX()->setRange(0,1);
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
    chart->createDefaultAxes();
    for(int a : setToBeRemoved) chart->legend()->markers()[a]->setVisible(false);
    setMap.insert(setName, chart->legend()->markers()[counter]->brush().color());
    counter ++;
}

void GanttChart::reset(){
    series->clear();
    counter = 0;
    setMap.clear();
    setToBeRemoved.clear();
}
