/********************************************************************************
** Form generated from reading UI file 'maininterfacewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAININTERFACEWINDOW_H
#define UI_MAININTERFACEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <barchartview.h>
#include <canvas.h>
#include "painter.h"

QT_BEGIN_NAMESPACE

class Ui_MainInterfaceWindow
{
public:
    QAction *actionOpen_CSV;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QPushButton *stepFunction;
    QPushButton *finishLayout;
    QPushButton *reset;
    QCheckBox *checkBox_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    BarChartView *chartWidget;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout;
    Canvas *openGLWidget;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_4;
    Painter *paintingWidget;
    QWidget *tab_4;
    QOpenGLWidget *openGLWidget_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainInterfaceWindow)
    {
        if (MainInterfaceWindow->objectName().isEmpty())
            MainInterfaceWindow->setObjectName(QStringLiteral("MainInterfaceWindow"));
        MainInterfaceWindow->resize(1084, 751);
        MainInterfaceWindow->setMinimumSize(QSize(1080, 720));
        actionOpen_CSV = new QAction(MainInterfaceWindow);
        actionOpen_CSV->setObjectName(QStringLiteral("actionOpen_CSV"));
        centralWidget = new QWidget(MainInterfaceWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView = new QTableView(frame);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setMinimumSize(QSize(400, 700));

        verticalLayout_2->addWidget(tableView);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stepFunction = new QPushButton(frame_2);
        stepFunction->setObjectName(QStringLiteral("stepFunction"));

        verticalLayout->addWidget(stepFunction);

        finishLayout = new QPushButton(frame_2);
        finishLayout->setObjectName(QStringLiteral("finishLayout"));

        verticalLayout->addWidget(finishLayout);

        reset = new QPushButton(frame_2);
        reset->setObjectName(QStringLiteral("reset"));

        verticalLayout->addWidget(reset);

        checkBox_2 = new QCheckBox(frame_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);


        verticalLayout_2->addWidget(frame_2);


        horizontalLayout_3->addWidget(frame);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        chartWidget = new BarChartView(tab);
        chartWidget->setObjectName(QStringLiteral("chartWidget"));

        horizontalLayout_2->addWidget(chartWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout = new QHBoxLayout(tab_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        openGLWidget = new Canvas(tab_2);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy1);
        openGLWidget->setMinimumSize(QSize(200, 200));
        openGLWidget->setMouseTracking(true);

        horizontalLayout->addWidget(openGLWidget);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_4 = new QHBoxLayout(tab_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        paintingWidget = new Painter(tab_3);
        paintingWidget->setObjectName(QStringLiteral("paintingWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(paintingWidget->sizePolicy().hasHeightForWidth());
        paintingWidget->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(paintingWidget);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        openGLWidget_2 = new QOpenGLWidget(tab_4);
        openGLWidget_2->setObjectName(QStringLiteral("openGLWidget_2"));
        openGLWidget_2->setGeometry(QRect(0, 0, 641, 621));
        tabWidget->addTab(tab_4, QString());

        horizontalLayout_3->addWidget(tabWidget);

        MainInterfaceWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainInterfaceWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1084, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainInterfaceWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainInterfaceWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainInterfaceWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainInterfaceWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainInterfaceWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_CSV);

        retranslateUi(MainInterfaceWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainInterfaceWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainInterfaceWindow)
    {
        MainInterfaceWindow->setWindowTitle(QApplication::translate("MainInterfaceWindow", "MainInterfaceWindow", Q_NULLPTR));
        actionOpen_CSV->setText(QApplication::translate("MainInterfaceWindow", "Open CSV", Q_NULLPTR));
        stepFunction->setText(QApplication::translate("MainInterfaceWindow", "Step Function", Q_NULLPTR));
        finishLayout->setText(QApplication::translate("MainInterfaceWindow", "Finish Layout", Q_NULLPTR));
        reset->setText(QApplication::translate("MainInterfaceWindow", "Reset", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainInterfaceWindow", "Draw States", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainInterfaceWindow", "Chart", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainInterfaceWindow", "OpenGL", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainInterfaceWindow", "QTPaint", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainInterfaceWindow", "State", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainInterfaceWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainInterfaceWindow: public Ui_MainInterfaceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAININTERFACEWINDOW_H
