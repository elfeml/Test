#ifndef DATAREGION_H
#define DATAREGION_H

#include <QWidget>
#include <QDebug>
#include "rectangle.h"

class dataRegion
{
public:
    dataRegion();

    int count() const;
    void setCount(int count);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    int getWidth() const;
    void setWidth(int value);

    float getHeight() const;
    void setHeight(float value);

    QString getRegion() const;
    void setRegion(const QString &region);

    int getNumberofStates() const;
    void addState();

private:
    QString m_region;
    int m_count=0;
    int m_numberofStates=0;

    int x;
    int y;
    int width;
    float height;

};

#endif // DATAREGION_H
