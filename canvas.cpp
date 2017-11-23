#include "canvas.h"
#include "canvas.h"

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
    if(listofStates != nullptr)
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


void Canvas::redraw()
{
    prepareDraw();
    glColor3f(0,0,0);
//   renderRectangle(0,0,10,10);
    int x = 18;
    int y = 10;
    int width = 10;
    int height = 80;
    int seperator = 3;

//    for(int i =0; i < 5; ++i)
//    {
//        renderRectangle(x+(i*width)+(i*seperator),
//                        y, width, height, true);

//    }



   for(int i =0; i < listofStates->size(); ++i)
    {
       QVector4D color;
       color.setX(((double) rand() / (RAND_MAX)) );
       color.setY(((double) rand() / (RAND_MAX)) );
       color.setZ(((double) rand() / (RAND_MAX)) );

       renderRectangle((*listofStates)[i].getX(), (*listofStates)[i].getY(), (*listofStates)[i].getWidth(),
                        (*listofStates)[i].getHeight(), true, color);

    }
}


void Canvas::renderRectangle(int x, int y, int width, int height, bool boundary,
                             QVector4D color)
{
//    glColor4f(1,0,0,1); //255/255
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
        glColor3f(0,0,0);
        glBegin(GL_LINE_STRIP);
        glVertex2f(x,y);
        glVertex2f(x+width,y);
        glVertex2f(x+width,y-height);
        glVertex2f(x,y-height);
        glVertex2f(x,y);
        glEnd();
    }
}
