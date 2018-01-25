#ifndef DATASTATE_H
#define DATASTATE_H

#include <QWidget>
#include <QDebug>
#include "rectangle.h"

class dataState
{
public:
    dataState();
    QString state() const;
    void setState(const QString &state);

    int count() const;
    void setCount(int count);

    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

    int getWidth() const;
    void setWidth(int value);


    QString getStateRegion() const;
    void setStateRegion(const QString &stateRegion);

    double getHeight() const;
    void setHeight(double value);

    QString getAbb() const;
    void setAbb(const QString &abb);

private:
    QString m_state;
    int m_count;
    QString m_stateRegion;
    QString m_abb;

    float x;
    float y;
    int width;
    double height;
};

#endif // DATASTATE_H
