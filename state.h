#ifndef STATE_H
#define STATE_H

#include <QString>
#include <QDebug>


class state
{
public:
    state();
    double time() const;
    void setTime(double time);

    QString stateName() const;
    void setStateName(const QString &stateName);

    int count() const;
    void setCount(int count);

    float incidence() const;
    void setIncidence(float incidence);

    void toString();
private:
    double m_time;
    QString m_stateName;
    int m_count;
    float m_incidence;
};

#endif // STATE_H
