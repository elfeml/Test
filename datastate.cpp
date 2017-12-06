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
    m_count = count;
}

int dataState::getX() const
{
    return x;
}

void dataState::setX(int value)
{
    x = value;
}

int dataState::getY() const
{
    return y;
}

void dataState::setY(int value)
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

int dataState::getHeight() const
{
    return height;
}

void dataState::setHeight(int value)
{
    height = value;
}

QString dataState::getStateRegion() const
{
    return m_stateRegion;
}

void dataState::setStateRegion(const QString &stateRegion)
{
    m_stateRegion = stateRegion;
}
