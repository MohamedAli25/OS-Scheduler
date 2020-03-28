#ifndef GANTTCHART_H
#define GANTTCHART_H

#include <QtCharts/QChartView>
#include <QChart>
#include <QHorizontalStackedBarSeries>
#include <QBarSet>
#include <QLegendMarker>
#include <QMap>
#include <QDebug>
#include <QBarCategoryAxis>

using namespace  QtCharts;

class GanttChart : public QChartView{
    Q_OBJECT
public:
    GanttChart();
    void addValue(QString setName, int value);

private:
    QChart *chart;
    QHorizontalStackedBarSeries *series;
    QMap<QString, QColor> setMap;
    QVector<int> setToBeRemoved;
    QBarCategoryAxis *axis;
    int counter = 0;

};

#endif // GANTTCHART_H
