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

    int getHeight() const;
    void setHeight(int value);

    QString getRegion() const;
    void setRegion(const QString &region);

private:
    QString m_region;
    int m_count;

    int x;
    int y;
    int width;
    int height;
};

#endif // DATAREGION_H
