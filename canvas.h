#ifndef CANVAS_H
#define CANVAS_H

#include <QOpenGLWidget>
#include <QtOpenGL>
#include <QOpenGLFunctions>
#include "global.h"
#include "datatuple.h"
#include <math.h>



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
        QList<dataTuple>* listofStates;

private:
    void redraw();
    bool prepareDraw();
signals:


};

#endif // CANVAS_H
