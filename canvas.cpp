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

    float maxX2 = 105;
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

QVector4D Canvas::colorScaleRegion(int a){
    int z=100; int m=200; int n =300; int o=400; int l=500; int s=600; int p =700;

       QVector4D stateColor;

       if(a<z){
                       stateColor.setX(( (0.96f)) );
                       stateColor.setY(( (0.98f)) );
                       stateColor.setZ(( (1.0f)) ); }
       else if (a<m){
                       stateColor.setX(( (0.87f)) );
                       stateColor.setY(( (0.92f)) );
                       stateColor.setZ(( (0.96f)) );}
       else if (a<n){
                       stateColor.setX(( (0.77f)) );
                       stateColor.setY(( (0.85f)) );
                       stateColor.setZ(( (0.93f)) );}
      else if (a<o){
                       stateColor.setX(( (0.61f)) );
                       stateColor.setY(( (0.79f)) );
                       stateColor.setZ(( (0.88f)) );}
       else if (a<l){
                       stateColor.setX(( (0.41f)) );
                       stateColor.setY(( (0.68f)) );
                       stateColor.setZ(( (0.83f)) );}
       else if (a<s){
                       stateColor.setX(( (0.25f)) );
                       stateColor.setY(( (0.57f)) );
                       stateColor.setZ(( (0.77f)) );}
       else if (a<p){
                       stateColor.setX(( (0.12f)) );
                       stateColor.setY(( (0.44f)) );
                       stateColor.setZ(( (0.70f)) );}
       else{
                       stateColor.setX(( (0.03f)) );
                       stateColor.setY(( (0.27f)) );
                       stateColor.setZ(( (0.68f)) );}

       return stateColor;

}

QVector4D Canvas::colorScaleState(int a){

  int b =10; int c=25; int d=55; int e=100; int f=160; int g=180; int h=210;
       QVector4D stateColor;

       if(a<b){
                       stateColor.setX(( (1.0f)) );
                       stateColor.setY(( (1.0f)) );
                       stateColor.setZ(( (0.8f)) ); }
       else if (a<c){
                       stateColor.setX(( (1.0f)) );
                       stateColor.setY(( (0.92f)) );
                       stateColor.setZ(( (0.62f)) );}
       else if (a<d){
                       stateColor.setX(( (0.99f)) );
                       stateColor.setY(( (0.85f)) );
                       stateColor.setZ(( (0.46f)) );}
      else if (a<e){
                       stateColor.setX(( (0.99f)) );
                       stateColor.setY(( (0.69f)) );
                       stateColor.setZ(( (0.29f)) );}
       else if (a<f){
                       stateColor.setX(( (0.99f)) );
                       stateColor.setY(( (0.55f)) );
                       stateColor.setZ(( (0.23f)) );}
       else if (a<g){
                       stateColor.setX(( (0.98f)) );
                       stateColor.setY(( (0.30f)) );
                       stateColor.setZ(( (0.16f)) );}
       else if (a<h){
                       stateColor.setX(( (0.89f)) );
                       stateColor.setY(( (0.10f)) );
                       stateColor.setZ(( (0.10f)) );}
       else{
                       stateColor.setX(( (0.69f)) );
                       stateColor.setY(( (0.00f)) );
                       stateColor.setZ(( (0.14f)) );}

       return stateColor;

}
// Color Legend
void Canvas::DrawLegend(){

   double lRange =50; // Height of Color Legend
   double slices = 7; // Total amount of colors
   double slice = ( lRange / slices );

   glLineWidth( 25 );

   glBegin( GL_LINE_STRIP );

   QList<QVector4D> colorListS;
   QList<QVector4D> colorListR;

        colorListS.append(QVector4D(1.0f, 1.0f, 0.8f, 1.0f));
        colorListS.append(QVector4D(1.0f, 0.92f, 0.62f, 1.0f));
        colorListS.append(QVector4D(0.99f, 0.85f, 0.46f, 1.0f));
        colorListS.append(QVector4D(0.99f, 0.69f, 0.29f, 1.0f));
        colorListS.append(QVector4D(0.99f, 0.25f, 0.53f, 1.0f));
        colorListS.append(QVector4D(0.98f, 0.30f, 0.10f, 1.0f));
        colorListS.append(QVector4D(0.89f, 0.10f, 0.10f, 1.0f));
        colorListS.append(QVector4D(0.69f, 0.00f, 0.14f, 1.0f));

        colorListR.append(QVector4D(0.96f, 0.98f, 1.0f, 1.0f));
        colorListR.append(QVector4D(0.87f, 0.92f, 0.96f, 1.0f));
        colorListR.append(QVector4D(0.77f, 0.85f, 0.93f, 1.0f));
        colorListR.append(QVector4D(0.61f, 0.79f, 0.88f, 1.0f));
        colorListR.append(QVector4D(0.41f, 0.68f, 0.83f, 1.0f));
        colorListR.append(QVector4D(0.25f, 0.57f, 0.77f, 1.0f));
        colorListR.append(QVector4D(0.12f, 0.44f, 0.70f, 1.0f));
        colorListR.append(QVector4D(0.03f, 0.27f, 0.68f, 1.0f));

   for ( int i = 0; i < slices; ++i )
   {
    if(m_activate)
    {
     QVector4D colorS = colorListS.at(i);//Get next color
     glColor4f( colorS.x(), colorS.y(),colorS.z(),1.0f);
    }
    else
    {
      QVector4D colorR = colorListR.at(i);//Get next color
      glColor4f( colorR.x(), colorR.y(),colorR.z(),1.0f);
    }

     //glColor4f( 0, 0, 0, 1.0f ); //black
     glVertex2f( 105, 25 + ( slice * ( i + 1.0 ) ) );
   }
   glEnd();
}


void Canvas::redraw()
{
    prepareDraw();
    DrawLegend();
    glColor3f(0,0,0);

    int a=1; int k=0.5;
    int drawState=0;


  for(int i =0; i<regions->size(); ++i)
  {
      QVector4D stateColor = colorScaleRegion(regions->at(i).count());

   if(m_StepCount>i)
       { 

      renderRectangle((*regions)[i].getX(), (*regions)[i].getY(), (*regions)[i].getWidth(),
                      (*regions)[i].getHeight(), true,stateColor);

      std::string name= ((*regions)[i].getRegion().toStdString());
           glPrintString((*regions)[i].getX(),(*regions)[i].getY()+a, name);
        }


   if(m_activate)
   {
      for (int j =0; j<states->size(); ++j)
      {
       QString stateName=(*states)[j].getStateRegion();
       QString regionName=(*regions)[i].getRegion();

        if(stateName==regionName)
        {
         QVector4D stateColor = colorScaleState(states->at(j).count());

          if(m_StepCountState>drawState)
           {
          renderRectangle((*states)[j].getX()+0.5, (*states)[j].getY(), (*states)[j].getWidth()-1,
                          (*states)[j].getHeight(), true,stateColor);
          std::string name= ((*states)[j].state().toStdString());
               glPrintString((*states)[j].getX(),(*states)[j].getY(), name);
               drawState++;
           }
        }
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

void Canvas::renderRectangle(float x, float y, float width, double height, bool boundary,QVector4D color)
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

void Canvas::StepActivate(bool stepActivate)
{
    m_stepActivate=stepActivate;
}

void Canvas::full(bool full)
{
    m_full=full;
}

// Mouse Over
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
