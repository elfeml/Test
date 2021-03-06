#-------------------------------------------------
#
# Project created by QtCreator 2017-11-07T14:55:31
#
#-------------------------------------------------

QT       += core gui charts opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        maininterfacewindow.cpp \
    filereader.cpp \
    datatuple.cpp \
    barchartview.cpp \
    treemapifier.cpp \
    canvas.cpp \
    painter.cpp \
    rectangle.cpp \
    statecalculator.cpp \
    dataregion.cpp \
    datastate.cpp \
    coordinate.cpp

HEADERS += \
        maininterfacewindow.h \
    filereader.h \
    datatuple.h \
    barchartview.h \
    canvas.h \
    painter.h \
    rectangle.h \
    statecalculator.h \
    global.h \
    dataregion.h \
    datastate.h \
    dialog.h \
    coordinate.h

FORMS += \
        maininterfacewindow.ui

DISTFILES += \
    tycho.csv \
    mumps.csv \
    mumps.csv

RESOURCES += \
    data.qrc


win32 {
    LIBS += -lOpengl32 -lglut32
}
