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
   void calculateX(dataTuple *data);
   void calculateY(dataTuple *data);
      void calculateWidth(dataTuple *data);
        void calculateHeigth(dataTuple *data);




};

#endif // STATECALCULATOR_H
