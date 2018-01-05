#include "mouse.h"

mouse::mouse()
{
}

void mouse::mouseMoveEvent(QMouseEvent *ev)
{
    this->x=ev->x();
    this->y=ev->y();
    emit MousePos();
}

void mouse::mousePressEvent(QMouseEvent *ev)
{
    emit mousePressed();
}

void mouse::leaveEvent(QEvent *)
{
    emit MouseLeft();
}
