#ifndef GANTTCHART_H
#define GANTTCHART_H

#include <QtCharts/QChartView>
#include <QWidget>
#include <QChart>
#include <QHorizontalStackedBarSeries>
#include <QBarSet>
#include <QLegendMarker>
#include <QMap>
#include <QDebug>
#include <QBarCategoryAxis>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>

using namespace  QtCharts;

class GanttChart : public QWidget{
    Q_OBJECT
public:
    GanttChart();
    void addValue(QString setName, int value);
    void beautify();
    void reset();

private:
    QChartView *chartView;
    QChart *chart;
    QHorizontalStackedBarSeries *series;
    QMap<QString, QColor> setMap;
    QVector<int> setToBeRemoved;
    QBarCategoryAxis *axis;
    QGraphicsView *gView;
    QGraphicsScene *gScene;
    int counter = 0;
    int colorCounter = 0;
    QList<QColor> colors = {QColor(23,126,137), QColor(8,76,97), QColor(219,58,52),
                            QColor(255,200,87), QColor(50,48,49), QColor(22,186,197),
                            QColor(239,233,244), QColor(88,99,248), QColor(174,197,235),
                            QColor(249,222,201), QColor(233,175,163), QColor(104,80,68),};
    QVector<QPair<QString, int>> timeLine;
    bool beautified = false;


};

#endif // GANTTCHART_H
