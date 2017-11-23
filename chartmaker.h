#ifndef CHARTMAKER_H
#define CHARTMAKER_H
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE

class ChartMaker
{
public:
    ChartMaker();
    ChartMaker(QWindow *widget);
};

#endif // CHARTMAKER_H
