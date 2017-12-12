#include "dataregion.h"

dataRegion::dataRegion()
{

}

int dataRegion::count() const
{
    return m_count;
}

void dataRegion::setCount(int count)
{
    m_count = count;
}

int dataRegion::getX() const
{
    return x;
}

void dataRegion::setX(int value)
{
    x = value;
}

int dataRegion::getY() const
{
    return y;
}

void dataRegion::setY(int value)
{
    y = value;
}

int dataRegion::getWidth() const
{
    return width;
}

void dataRegion::setWidth(int value)
{
    width = value;
}

int dataRegion::getHeight() const
{
    return height;
}

void dataRegion::setHeight(int value)
{
    height = value;
}

QString dataRegion::getRegion() const
{
    return m_region;
}

void dataRegion::setRegion(const QString &region)
{
    m_region = region;
}

int dataRegion::getNumberofStates() const
{
    return m_numberofStates;
}

void dataRegion::addState()
{
    m_numberofStates++;
}



