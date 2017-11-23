#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H

#include <QWidget>
#include "datatuple.h"
#include <QGridLayout>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE


class BarChartView : public QWidget
{
    Q_OBJECT
public:
    explicit BarChartView(QWidget *parent = nullptr);
    void display(QList<dataTuple>* data);

signals:

public slots:
};


#endif // BARCHARTVIEW_H
