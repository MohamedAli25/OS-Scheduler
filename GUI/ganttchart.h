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
    void reset();

private:
    QChart *chart;
    QHorizontalStackedBarSeries *series;
    QMap<QString, QColor> setMap;
    QVector<int> setToBeRemoved;
    QBarCategoryAxis *axis;
    int counter = 0;
    int colorCounter = 0;
    QList<QColor> colors = {Qt::red, Qt::blue, Qt::black, Qt::yellow, Qt::green, Qt::gray, Qt::magenta, Qt::cyan,
                            Qt::lightGray, Qt::darkRed, Qt::darkGreen};

};

#endif // GANTTCHART_H
