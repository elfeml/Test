#include "datatuple.h"



dataTuple::dataTuple()
{

}

double dataTuple::time() const
{
    return m_time;
}

void dataTuple::setTime(double time)
{
    m_time = time;
}

int dataTuple::count() const
{
    return m_count;
}

void dataTuple::setCount(int count)
{
    m_count = count;
}

float dataTuple::incidence() const
{
    return m_incidence;
}

void dataTuple::setIncidence(float incidence)
{
    m_incidence = incidence;
}

void dataTuple::toString()
{
    qDebug() <<  m_time << m_stateName << m_count << m_incidence;

}

QString dataTuple::stateName() const
{
    return m_stateName;
}

void dataTuple::setStateName(const QString &stateName)
{
    m_stateName = stateName;
}

int dataTuple::getX() const
{
    return x;
}

void dataTuple::setX(int value)
{
    x = value;
}

int dataTuple::getY() const
{
    return y;
}

void dataTuple::setY(int value)
{
    y = value;
}

int dataTuple::getWidth() const
{
    return width;
}

void dataTuple::setWidth(int value)
{
    width = value;
}

int dataTuple::getHeight() const
{
    return height;
}

void dataTuple::setHeight(int value)
{
    height = value;
}

QString dataTuple::getRegionName() const
{
    return m_regionName;
}

void dataTuple::setRegionName(const QString &regionName)
{
    m_regionName = regionName;
}






