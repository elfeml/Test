#include "painter.h"


Painter::Painter(QWidget *parent) : QWidget(parent)
{

}

void Painter::MyWidget()
{
    QPalette palette(Painter::palette());
    palette.setColor(backgroundRole(), Qt::white);
    setPalette(palette);
}

void Painter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::red);

    int x = 300;
    int y = 80;
    int width = 150;
    int height = 700;
    int seperator = 30;

    QBrush brush(Qt::SolidLine);

    for(int i =0; i < 5; ++i)
    {
       painter.drawRect(x+(i*width)+(i*seperator),
                        y, width, height);

       painter.fillRect(x+(i*width)+(i*seperator),
                        y, width, height,brush );


    }

    //painter.setPen(Qt::darkGray);
   // painter.drawLine(2, 8, 6, 2);
}
