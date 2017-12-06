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

    int getHeight() const;
    void setHeight(int value);

    QString getStateRegion() const;
    void setStateRegion(const QString &stateRegion);

private:
    QString m_state;
    int m_count;
    QString m_stateRegion;

    int x;
    int y;
    int width;
    int height;
};

#endif // DATASTATE_H
