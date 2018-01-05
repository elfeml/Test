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

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

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

    int x;
    int y;
    int width;
    double height;
};

#endif // DATASTATE_H
