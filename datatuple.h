#ifndef DATATUPLE_H
#define DATATUPLE_H

#include <QWidget>
#include <QDebug>
#include "rectangle.h"

class dataTuple
{
public:
    dataTuple();
    static const int columnCount = 4;

    double time() const;
    void setTime(double time);

    int count() const;
    void setCount(int count);

    float incidence() const;
    void setIncidence(float incidence);

    void toString();

    QString stateName() const;
    void setStateName(const QString &stateName);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

    QString getRegionName() const;
    void setRegionName(const QString &regionName);

private:
    double m_time;
    QString m_stateName;
    QString m_regionName;

    int m_count;
    float m_incidence;

    int x;
    int y;
    int width;
    int height;

};

#endif // DATATUPLE_H
