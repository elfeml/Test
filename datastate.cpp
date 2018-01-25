#include "datastate.h"

dataState::dataState()
{

}

QString dataState::state() const
{
    return m_state;
}

void dataState::setState(const QString &state)
{
    m_state = state;
}

int dataState::count() const
{
    return m_count;
}

void dataState::setCount(int count)
{
    if(count==0)
        {
            count=0.5;
        }
    m_count = count;
}

float dataState::getX() const
{
    return x;
}

void dataState::setX(float value)
{
    x = value;
}

float dataState::getY() const
{
    return y;
}

void dataState::setY(float value)
{
    y = value;
}

int dataState::getWidth() const
{
    return width;
}

void dataState::setWidth(int value)
{
    width = value;
}

QString dataState::getStateRegion() const
{
    return m_stateRegion;
}

void dataState::setStateRegion(const QString &stateRegion)
{
    m_stateRegion = stateRegion;
}

double dataState::getHeight() const
{
    return height;
}

void dataState::setHeight(double value)
{
    height = value;
}

QString dataState::getAbb() const
{
    return m_abb;
}

void dataState::setAbb(const QString &abb)
{
    m_abb = abb;
}
