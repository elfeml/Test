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
#include "dataState.h"
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
    void renderRectangle(int x, int y, int width, int height, bool boundary, QVector4D color);
       //QList<dataTuple>* listofStates = nullptr;
         QList<dataRegion>* regions = nullptr;
         QList<dataState>* states = nullptr;

private:
    void redraw();
    bool prepareDraw();
    void glPrint( void* font, const char* str );
    void glPrintString( float x, float y, std::string str );
    QPointF ConvertScreen(QPointF p);

};

#endif // CANVAS_H
