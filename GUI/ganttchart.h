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
    QList<QColor> colors = {QColor(23,126,137), QColor(8,76,97), QColor(219,58,52),
                            QColor(255,200,87), QColor(50,48,49), QColor(0,0,0),};


};

#endif // GANTTCHART_H
