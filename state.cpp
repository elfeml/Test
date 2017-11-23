#include "state.h"

state::state()
{

}

double state::time() const
{
    return m_time;
}

void state::setTime(double time)
{
    m_time = time;
}

QString state::stateName() const
{
    return m_stateName;
}

void state::setStateName(const QString &stateName)
{
    m_stateName = stateName;
}

int state::count() const
{
    return m_count;
}

void state::setCount(int count)
{
    m_count = count;
}

float state::incidence() const
{
    return m_incidence;
}

void state::setIncidence(float incidence)
{
    m_incidence = incidence;
}
void state::toString()
{
    qDebug() <<  m_time << m_stateName << m_count << m_incidence;

}
