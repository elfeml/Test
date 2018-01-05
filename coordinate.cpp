#include "coordinate.h"

coordinate::coordinate()
{

}

int coordinate::xAxis() const
{
    return m_xAxis;
}

void coordinate::setXAxis(int xAxis)
{
    m_xAxis = xAxis;
}

int coordinate::yAxis() const
{
    return m_yAxis;
}

void coordinate::setYAxis(int yAxis)
{
    m_yAxis = yAxis;
}

QString coordinate::stateName() const
{
    return m_stateName;
}

void coordinate::setStateName(const QString &stateName)
{
    m_stateName = stateName;
}

QString coordinate::abName() const
{
    return m_abName;
}

void coordinate::setAbName(const QString &abName)
{
    m_abName = abName;
}

int coordinate::count() const
{
    return m_count;
}

void coordinate::setCount(int count)
{
    m_count = count;
}
