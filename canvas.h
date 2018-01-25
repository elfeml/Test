#ifndef CANVAS_H
#define CANVAS_H
//#include "GL/freeglut.h"
#include <QOpenGLWidget>
#include <QtOpenGL>
#include <QOpenGLFunctions>
#include "global.h"
#include "datatuple.h"
#include <math.h>
#include "dataregion.h"
#include "datastate.h"
#include "QPointF"



class Canvas : public QOpenGLWidget, protected QOpenGLFunctions
{
//    Q_OBJECT
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);


public:
    Canvas(QWidget *parent = 0);
//  void updateGL();
    void renderRectangle(float x, float y, float width, double height, bool boundary, QVector4D color);
       //QList<dataTuple>* listofStates = nullptr;
         QList<dataRegion>* regions = nullptr;
         QList<dataState>* states = nullptr;
         void drawActivate(bool activate);
         void StepActivate(bool stepActivate);
         void full(bool full);
         void DrawLegend();
         QList<QVector4D>*colorList;
         int m_StepCount=0;
         int m_StepCountState=-5;


protected:
    bool event(QEvent * e);
    void hoverEnter(QHoverEvent * event);
    void hoverLeave(QHoverEvent * event);
    void hoverMove(QHoverEvent * event);
private:
    void redraw();
    bool prepareDraw();
    void glPrint( void* font, const char* str );
    void glPrintString( float x, float y, std::string str );
    QVector4D colorScaleRegion(int a);
    QVector4D colorScaleState(int a);
    QPointF ConvertScreen(QPointF p);
    bool m_activate =false;
    bool m_full=false;
    bool m_stepActivate=false;


};

#endif // CANVAS_H
