#ifndef STATECALCULATOR_H
#define STATECALCULATOR_H

#include "global.h"
#include "datatuple.h"
#include "dataregion.h"
#include "dataState.h"


class StateCalculator
{
public:
    StateCalculator();
     static void identifyRegionRectangles(QList<dataTuple>* listofstates,QList<dataRegion>* regions);
     static void identifyStateRectangles(QList<dataTuple>* listofstates, QList<dataRegion>* regions, QList<dataState>* states);
     static void activate(int value);

private:
   static int calculateX(dataRegion data);
   static void calculateY(dataRegion data);
   static void calculateWidth(dataRegion data);
   static void calculateHeigth(dataRegion data);
};

#endif // STATECALCULATOR_H
