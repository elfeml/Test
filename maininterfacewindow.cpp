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

//Pressed
//void MainInterfaceWindow::mouseMoveEvent(QMouseEvent *event)
//{
//    if (event->button() == Qt::LeftButton)
//        {
//            // handle left mouse button here
//        } else {
//            // pass on other buttons to base class
//            MainInterfaceWindow::mousePressEvent(event);
//        }

//    qDebug() << "inside move";
//    qDebug() << (event->pos().x())<<","<<(event->pos().y());
//}


//bool MainInterfaceWindow::event(QEvent * e)
//{
//    switch(e->type())
//    {
//    case QEvent::HoverEnter:
//        hoverEnter(static_cast<QHoverEvent*>(e));
//        return true;
//        break;
//    case QEvent::HoverLeave:
//        hoverLeave(static_cast<QHoverEvent*>(e));
//        return true;
//        break;
//    case QEvent::HoverMove:
//        hoverMove(static_cast<QHoverEvent*>(e));
//        return true;
//        break;
//    default:
//        break;
//    }
//    return QWidget::event(e);
//}

//void MainInterfaceWindow::hoverEnter(QHoverEvent * event)
//{
//    //qDebug() << Q_FUNC_INFO << event->type();
//}

//void MainInterfaceWindow::hoverLeave(QHoverEvent * event)
//{
//    //m_count = 0;
//    //qDebug() << Q_FUNC_INFO << event->type();
//   // this->setText(QString::number(m_count));
//}

//void MainInterfaceWindow::hoverMove(QHoverEvent * event)
//{
//    float posX=event->pos().x();
//    float posY=event->pos().y();




//    if(m_full){
//    for (int i = 0; i <m_dataState->size(); i++)
//   {
//    if(((*m_dataState)[i].getX()<posX &&
//        (*m_dataState)[i].getY()<posY &&
//        (*m_dataState)[i].getY()+(*m_dataState)[i].getHeight()>posY&&
//        (*m_dataState)[i].getX()+(*m_dataState)[i].getWidth()>posX))
//    {

//       QToolTip::showText(event->pos(),(*m_dataState)[i].state());

//    }
////    else
////    {
////        //QToolTip::hideText();
////    }

//    //qDebug() << (event->pos().x())<<","<<(event->pos().y());
//   }
//  }
//}
