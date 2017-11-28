#ifndef STATECALCULATOR_H
#define STATECALCULATOR_H

#include "global.h"
#include "datatuple.h"

class StateCalculator
{
public:
    StateCalculator();
     static void identifyRectangles(QList<dataTuple>* listofstates);
private:
   static int calculateX(dataTuple data);
   static void calculateY(dataTuple data);
    static void calculateWidth(dataTuple data);
    static void calculateHeigth(dataTuple data);




};

#endif // STATECALCULATOR_H
