#ifndef MAININTERFACEWINDOW_H
#define MAININTERFACEWINDOW_H

#include <QMainWindow>
#include <QList>
#include "datatuple.h"
#include "dataregion.h"
#include "datastate.h"
#include "filereader.h"
#include "statecalculator.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

#include<QMouseEvent>
#include<QEvent>
#include<QDebug>
#include<QHoverEvent>


QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainInterfaceWindow;
}

class MainInterfaceWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainInterfaceWindow(QWidget *parent = 0);
    ~MainInterfaceWindow();


private slots:
    void on_actionOpen_CSV_triggered();
    void on_checkBox_2_clicked(bool checked);
    void on_stepFunction_clicked();

    void on_finishLayout_clicked();

    void on_reset_clicked();

private:
    Ui::MainInterfaceWindow *ui;
    QList<dataTuple> *m_dataTuple;
    QList<dataState> *m_dataState;
    QList<dataRegion> *m_dataRegion;
    //bool m_full= false;

   // QList<dataState>* states = nullptr;

    void setUpCharts(QList<dataTuple>* data);


};

#endif // MAININTERFACEWINDOW_H
