 #include "canvas.h"
#include "canvas.h"
#include <QPainter>
#include <QPen>
#include <QFont>
#include <QPointF>


Canvas::Canvas(QWidget *parent) : QOpenGLWidget(parent)
{
    qDebug() << "test";
}

//set up
void Canvas::initializeGL()
{
    initializeOpenGLFunctions();
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_BLEND ); // Required Blending for alpha blending
    glEnable( GL_ALPHA ); // Lets you add alpha values
//    glEnable( GL_LINE_STIPPLE ); // Enables Dotted Line for use
//    glEnable( GL_STENCIL ); //Rendering using stencil buffer (used to render concave polygons)
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    glClearColor( 1, 1, 1, 1.0 ); // BACKGROUND COLOR
}

void Canvas::paintGL()
{
    if(regions != nullptr)

        redraw();
}

void Canvas::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,w,0,h,0,0);
}
//Set up
bool Canvas::prepareDraw()
{
   glPointSize( 1 );
   glOrtho(0,100,0,100,1,0);
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   return true;
}

//Printing Labels
void Canvas::glPrintString( float x, float y, std::string str )
{
//   glRasterPos2f( x, y );
//   glPrint( GLUT_BITMAP_HELVETICA_12, str.c_str());

    //Greate the painting object
    QPainter painter(this);

    //Get the current font
    QFont font = painter.font() ;
    //Increase the current text size
    font.setPointSize(font.pointSize() * 1.0f);
    //Assigns the painter the modified font
    painter.setFont(font);
    //Assigns the window the correct viewport.
    painter.setViewport(0,0,width(),height());

    //Create a Pen to draw with - and assign a line width.
    QPen pen;
    pen.setWidth(100);
    //Change pen colour
    pen.setColor(Qt::red);
    //Assign painter the new pen.
    painter.setPen(pen);


    //Draw some text
    QPointF p = ConvertScreen(QPointF(x,y));
    //QPointF p = QPointF(x,y);
    //qDebug() << height() << width() << p.x() << p.y();
    painter.drawText(p,QString::fromStdString(str));

}

//Convert screen size from opengl to painter
QPointF Canvas::ConvertScreen(QPointF p)
{
    QPointF returnVal;
    float maxX = width();
    float maxY = height();

    float maxX2 = 100;
    float maxY2 = 100;

    float xRatio = p.x()/maxX2;
    float yRatio = p.y()/maxY2;

    float newX = maxX*xRatio;
    float newY = maxY*yRatio;

   // qDebug() << newX << newY;

    returnVal.setX(newX);
    returnVal.setY(height()-newY);

    return returnVal;
}


void Canvas::redraw()
{
    prepareDraw();
    glColor3f(0,0,0);

  //  renderRectangle(0,10,10,10,true);
    int x = 18;
    int y = 10;
    int width = 10;
    int height = 80;
    int seperator = 3;

  for(int i =0; i<regions->size(); ++i)
  {
      QVector4D color;
      color.setX(((double) rand() / (RAND_MAX)) );
      color.setY(((double) rand() / (RAND_MAX)) );
      color.setZ(((double) rand() / (RAND_MAX)) );

      renderRectangle((*regions)[i].getX(), (*regions)[i].getY(), (*regions)[i].getWidth(),
                      (*regions)[i].getHeight(), true,color);

     for (int j =0; j<states->size(); ++j)
      {
            QVector4D stateColor;
          stateColor.setX(0.0f );
          stateColor.setY(0.0f);
          stateColor.setZ(0.0f);
          stateColor.setW(1.0f);
          renderRectangle((*states)[j].getX(), (*states)[j].getY(), (*states)[j].getWidth(),
                          (*states)[j].getHeight(), true,stateColor);

    }
  }

//Drawing 50 rectangles with printing labels
//   for(int i =0; i < listofStates->size(); ++i)
//    {
//       QVector4D color;
//       color.setX(((double) rand() / (RAND_MAX)) );
//       color.setY(((double) rand() / (RAND_MAX)) );
//       color.setZ(((double) rand() / (RAND_MAX)) );
//
//       renderRectangle((*listofStates)[i].getX(), (*listofStates)[i].getY(), (*listofStates)[i].getWidth(),
//                        (*listofStates)[i].getHeight(), true, color);
//
//       std::string stateName= ((*listofStates)[i].stateName().toStdString());
//       glPrintString((*listofStates)[i].getX(),(*listofStates)[i].getY(), stateName);
//
//    }

}


void Canvas::renderRectangle(int x, int y, int width, int height, bool boundary,QVector4D color)
{
    glColor4f(1,0,0,1); //255/255
    glColor4f(color.x(),color.y(),color.z(),1);
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x+width,y);
    glVertex2f(x+width,y-height);
    glVertex2f(x,y-height);
    glEnd();

    if(boundary)
    {
        glLineWidth(3);
        //glColor3f(0,0,0);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x,y);
        glVertex2f(x+width,y);
        glVertex2f(x+width,y-height);
        glVertex2f(x,y-height);
        glVertex2f(x,y);
        glEnd();
    }
}
