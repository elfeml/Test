#ifndef COORDINATE_H
#define COORDINATE_H

#include <QWidget>
#include <QDebug>

class coordinate
{
public:
    coordinate();
    int xAxis() const;
    void setXAxis(int xAxis);

    int yAxis() const;
    void setYAxis(int yAxis);

    QString stateName() const;
    void setStateName(const QString &stateName);

    QString abName() const;
    void setAbName(const QString &abName);

    int count() const;
    void setCount(int count);

private:
    int m_xAxis;
    int m_yAxis;
    int m_count;
    QString m_stateName;
    QString m_abName;
    // arraye eklemelisin


};

#endif // COORDINATE_H
