#include "barchartview.h"

BarChartView::BarChartView(QWidget *parent) : QWidget(parent)
{

}

BarChartView::display(QList<dataTuple> *data)
{
    QBarSet *set0 = new QBarSet("State");

    for (int i =0; i < data->size(); i++)
    {
        set0->append(data->at(i).count());
    }

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple barchart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    for (int i =0; i < data->size(); i++)
    {
        categories.append(data->at(i).stateName());
    }


    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->addWidget(chartView, 1, 1);
    setLayout(mainLayout);

}

