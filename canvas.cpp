 #include "canvas.h"
#include "canvas.h"
#include <QPainter>
#include <QPen>
#include <QFont>
#include <QPointF>
#include <QColor>
#include <QList>
#include <QVector4D>


Canvas::Canvas(QWidget *parent) : QOpenGLWidget(parent)
{
    qDebug() << "test";
    setMouseTracking(true);
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
   glOrtho(0,105,0,100,1,0);
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
    pen.setColor(Qt::black);
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

void Canvas::DrawLegend(){

   double lRange =50; // Height of Color Legend
   double slices = 7; // Total amount of colors
   double slice = ( lRange / slices );

   glLineWidth( 25 );

   glBegin( GL_LINE_STRIP );

   QList<QVector4D> colorList;

        colorList.append(QVector4D(1.0f, 1.0f, 0.8f, 1.0f));
        colorList.append(QVector4D(1.0f, 0.92f, 0.62f, 1.0f));
        colorList.append(QVector4D(0.99f, 0.85f, 0.46f, 1.0f));
        colorList.append(QVector4D(0.99f, 0.69f, 0.29f, 1.0f));
        colorList.append(QVector4D(0.99f, 0.25f, 0.53f, 1.0f));
        colorList.append(QVector4D(0.98f, 0.30f, 0.10f, 1.0f));
        colorList.append(QVector4D(0.89f, 0.10f, 0.10f, 1.0f));
        colorList.append(QVector4D(0.69f, 0.00f, 0.14f, 1.0f));

   for ( int i = 0; i < slices; ++i )
   {

     QVector4D color = colorList.at(i);//Get next color

     //glColor4f( 0, 0, 0, 1.0f );

      glColor4f( color.x(), color.y(),color.z(),1.0f);

      glVertex2f( 105, 25 + ( slice * ( i + 1.0 ) ) );
   }
   glEnd();
}

void Canvas::redraw()
{
    prepareDraw();
    DrawLegend();
    glColor3f(0,0,0);


//  renderRectangle(0,10,10,10,true);
//    int x = 18;
//    int y = 10;
//    int width = 10;
//    int height = 80;
//    int seperator = 3;
    int a=1;


  for(int i =0; i<regions->size(); ++i)
  {
      QVector4D stateColor;
// Random Colors
//        color.setX(((double) rand() / (RAND_MAX)) );
//        color.setY(((double) rand() / (RAND_MAX)) );
//        color.setZ(((double) rand() / (RAND_MAX)) );

      if(regions->at(i).count()<100){
                      stateColor.setX(( (1.0f)) );
                      stateColor.setY(( (1.0f)) );
                      stateColor.setZ(( (0.8f)) ); }
      else if (regions->at(i).count()<200){
                      stateColor.setX(( (1.0f)) );
                      stateColor.setY(( (0.92f)) );
                      stateColor.setZ(( (0.62f)) );}
      else if (regions->at(i).count()<300){
                      stateColor.setX(( (0.99f)) );
                      stateColor.setY(( (0.85f)) );
                      stateColor.setZ(( (0.46f)) );}
      else if(regions->at(i).count()<400){
                      stateColor.setX(( (0.99f)) );
                      stateColor.setY(( (0.69f)) );
                      stateColor.setZ(( (0.29f)) );}
      else if(regions->at(i).count()<500){
                      stateColor.setX(( (0.99f)) );
                      stateColor.setY(( (0.55f)) );
                      stateColor.setZ(( (0.23f)) );}
      else if(regions->at(i).count()<600){
                      stateColor.setX(( (0.98f)) );
                      stateColor.setY(( (0.30f)) );
                      stateColor.setZ(( (0.16f)) );}
      else if(regions->at(i).count()<700){
                      stateColor.setX(( (0.89f)) );
                      stateColor.setY(( (0.10f)) );
                      stateColor.setZ(( (0.10f)) );}
      else{
                      stateColor.setX(( (0.69f)) );
                      stateColor.setY(( (0.00f)) );
                      stateColor.setZ(( (0.14f)) );}

      renderRectangle((*regions)[i].getX(), (*regions)[i].getY(), (*regions)[i].getWidth(),
                      (*regions)[i].getHeight(), true,stateColor);
      std::string name= ((*regions)[i].getRegion().toStdString());
           glPrintString((*regions)[i].getX(),(*regions)[i].getY()+a, name);


   if(m_activate){

     for (int j =0; j<states->size(); ++j)
      {
          QVector4D stateColor;
// Random Colors
//          color.setX(((double) rand() / (RAND_MAX)) );
//          color.setY(((double) rand() / (RAND_MAX)) );
//          color.setZ(((double) rand() / (RAND_MAX)) );

          if(states->at(j).count()<10){
                          stateColor.setX(( (1.0f)) );
                          stateColor.setY(( (1.0f)) );
                          stateColor.setZ(( (0.8f)) );
                          }
          else if (states->at(j).count()<25){
                          stateColor.setX(( (1.0f)) );
                          stateColor.setY(( (0.92f)) );
                          stateColor.setZ(( (0.62f)) );}
          else if (states->at(j).count()<55){
                          stateColor.setX(( (0.99f)) );
                          stateColor.setY(( (0.85f)) );
                          stateColor.setZ(( (0.46f)) );}
          else if(states->at(j).count()<100){
                          stateColor.setX(( (0.99f)) );
                          stateColor.setY(( (0.69f)) );
                          stateColor.setZ(( (0.29f)) );}
          else if(states->at(j).count()<160){
                          stateColor.setX(( (0.99f)) );
                          stateColor.setY(( (0.55f)) );
                          stateColor.setZ(( (0.23f)) );}
          else if(states->at(j).count()<180){
                          stateColor.setX(( (0.98f)) );
                          stateColor.setY(( (0.30f)) );
                          stateColor.setZ(( (0.16f)) );}
          else if(states->at(j).count()<210){
                          stateColor.setX(( (0.89f)) );
                          stateColor.setY(( (0.10f)) );
                          stateColor.setZ(( (0.10f)) );}
          else{
                          stateColor.setX(( (0.69f)) );
                          stateColor.setY(( (0.00f)) );
                          stateColor.setZ(( (0.14f)) );}

          renderRectangle((*states)[j].getX(), (*states)[j].getY(), (*states)[j].getWidth(),
                          (*states)[j].getHeight()+5, true,stateColor);
          std::string name= ((*states)[j].state().toStdString());
               glPrintString((*states)[j].getX(),(*states)[j].getY(), name);

      }
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

void Canvas::renderRectangle(int x, int y, int width, double height, bool boundary,QVector4D color)
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

void Canvas::drawActivate(bool activate)
{
    m_activate=activate;
}

void Canvas::full(bool full)
{
    m_full=full;
}

//void Canvas::mouseMoveEvent(QMouseEvent *event)
//{
//    qDebug() << event->pos();
//}
bool Canvas::event(QEvent * e)
{
    switch(e->type())
    {
    case QEvent::HoverEnter:
        hoverEnter(static_cast<QHoverEvent*>(e));
        return true;
        break;
    case QEvent::HoverLeave:
        hoverLeave(static_cast<QHoverEvent*>(e));
        return true;
        break;
    case QEvent::HoverMove:
        hoverMove(static_cast<QHoverEvent*>(e));
        return true;
        break;
    default:
        break;
    }
    return QWidget::event(e);
}

void Canvas::hoverEnter(QHoverEvent * event)
{
    //qDebug() << Q_FUNC_INFO << event->type();
}

void Canvas::hoverLeave(QHoverEvent * event)
{
    //m_count = 0;
    //qDebug() << Q_FUNC_INFO << event->type();
   // this->setText(QString::number(m_count));
}

void Canvas::hoverMove(QHoverEvent * event)
{

    float posX=event->pos().x();
    float posY=event->pos().y();

  if(m_full){
  if(m_activate){
  for (int i = 0; i <states->size(); i++)
   {
       QPointF p = ConvertScreen(QPointF((*states)[i].getX(),(*states)[i].getY()));
       QPointF plus = ConvertScreen(QPointF((*states)[i].getX()+(*states)[i].getWidth(),(*states)[i].getY()-(*states)[i].getHeight()));

    if((p.x()<posX &&
        p.y()<posY &&
        plus.y()>posY&&
        plus.x()>posX))
    {
        QString info= QString::number((*states)[i].count());
        QString infoS="\n"+(*states)[i].state()+"\n";
        QString dis="DIPHTHERIA";
        infoS.append(dis);
        info.append(infoS);

        QPoint mousepos = QPoint(event->pos().x(), event->pos().y());
        QToolTip::showText(this->mapToGlobal(mousepos),info);

    }
    //qDebug() << (event->pos().x())<<","<<(event->pos().y());
   }
  }
  else{
      for (int i = 0; i <regions->size(); i++)
       {
           QPointF p = ConvertScreen(QPointF((*regions)[i].getX(),(*regions)[i].getY()));
           QPointF plus = ConvertScreen(QPointF((*regions)[i].getX()+(*regions)[i].getWidth(),(*regions)[i].getY()-(*regions)[i].getHeight()));

        if((p.x()<posX &&
            p.y()<posY &&
            plus.y()>posY&&
            plus.x()>posX))
        {
            QString info= QString::number((*regions)[i].count());
            QString infoS="\n"+(*regions)[i].getRegion()+"\n";
            QString dis="DIPHTHERIA";
            infoS.append(dis);
            info.append(infoS);

            QPoint mousepos = QPoint(event->pos().x(), event->pos().y());
            QToolTip::showText(this->mapToGlobal(mousepos),info);

        }
        //qDebug() << (event->pos().x())<<","<<(event->pos().y());
       }


  }
  }
}
