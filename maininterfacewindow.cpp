#include "maininterfacewindow.h"
#include "ui_maininterfacewindow.h"


MainInterfaceWindow::MainInterfaceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainInterfaceWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    //setMouseTracking(true); //pressed
    //this->setAttribute(WA_HOVER, true);
    ui->openGLWidget->setFocusPolicy(Qt::StrongFocus);
    ui->openGLWidget->setAttribute(Qt::WA_Hover, true);
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
//        ui->comboBox->addItem("Region");
//        ui->comboBox->addItem("State");
                real.clear();
 }

    setUpCharts(m_dataTuple); // show m_datatuple on Chart Widget

    StateCalculator::identifyRegionRectangles(m_dataTuple, m_dataRegion);
    StateCalculator::identifyStateRectangles(m_dataTuple, m_dataRegion,m_dataState);

    ui->openGLWidget->regions =m_dataRegion;
    ui->openGLWidget->states =m_dataState;
    //QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)),StateCalculator,SLOT(activate(int)));
    ui->openGLWidget->update();
    ui->openGLWidget->full(true);
}

void MainInterfaceWindow::setUpCharts(QList<dataTuple> *data)
{
   ui->chartWidget->display(data); // m_dataTuple as data,display method is defined to be applied example
}

void MainInterfaceWindow::on_checkBox_2_clicked(bool checked)
{
 ui->openGLWidget->drawActivate(checked);
 ui->openGLWidget->update();
}


void MainInterfaceWindow::on_stepFunction_clicked()
{
    ui->openGLWidget->m_StepCount++;
    ui->openGLWidget->StepActivate(true);
    ui->openGLWidget->m_StepCountState++;
    ui->openGLWidget->update();

}

void MainInterfaceWindow::on_finishLayout_clicked()
{
    ui->openGLWidget->m_StepCount=5;
    ui->openGLWidget->m_StepCountState=50;
    ui->openGLWidget->update();
}

void MainInterfaceWindow::on_reset_clicked()
{
    ui->openGLWidget->m_StepCount=0;
    ui->openGLWidget->m_StepCountState=-5;
    ui->openGLWidget->update();
}
