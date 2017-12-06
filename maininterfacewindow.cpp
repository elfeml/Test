#include "maininterfacewindow.h"
#include "ui_maininterfacewindow.h"

MainInterfaceWindow::MainInterfaceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainInterfaceWindow)
{
    ui->setupUi(this);
    this->showMaximized();
}

MainInterfaceWindow::~MainInterfaceWindow()
{
    delete ui;
}

void MainInterfaceWindow::on_actionOpen_CSV_triggered()
{
    FileReader fileData(":/tycho.csv");
    m_dataTuple = fileData.getData();// brings m_listTuple from fileReader
    m_dataState = fileData.getDataState();
    m_dataRegion = fileData.getDataRegion();


    QStandardItemModel* csvModel = new QStandardItemModel();
    QList<QStandardItem*> real;

    for (int i = 0; i < m_dataTuple->size(); i++) // read all item of m_datatuple
    {
        real.append(new QStandardItem(QString::number(m_dataTuple->at(i).time())));
        real.append(new QStandardItem(m_dataTuple->at(i).stateName()));
        real.append(new QStandardItem(QString::number(m_dataTuple->at(i).count())));
        real.append(new QStandardItem(QString::number((m_dataTuple->at(i).incidence()))));
        real.append(new QStandardItem(m_dataTuple->at(i).getRegionName()));

        csvModel->insertRow(csvModel->rowCount(),real);
        ui->tableView->setModel(csvModel);
        real.clear();

     }

    setUpCharts(m_dataTuple); // show m_datatuple on Chart Widget

    StateCalculator::identifyRegionRectangles(m_dataTuple, m_dataRegion);
    StateCalculator::identifyStateRectangles(m_dataTuple, m_dataRegion,m_dataState);


    ui->openGLWidget->regions =m_dataRegion;
    ui->openGLWidget->states =m_dataState;

    ui->openGLWidget->update();
}

void MainInterfaceWindow::setUpCharts(QList<dataTuple> *data)
{
   ui->chartWidget->display(data); // m_dataTuple as data,display method is defined to be applied example
}


