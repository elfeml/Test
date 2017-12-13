#include "statecalculator.h"

StateCalculator::StateCalculator()
{
}

void StateCalculator::identifyRegionRectangles(QList<dataTuple>* listofstates, QList<dataRegion>* regions)
{
    int total=0;

    for(int i=0; i< regions->size(); ++i)
    {
       total+=(*regions)[i].count();

       qDebug()<< (*regions)[i].getRegion()<<(*regions)[i].count();
    }

    double width, height, xValue, yValue;
    yValue =195;
    xValue = 1;
    int rows = 5;
    int currentRow=0;
    int multiplier = 100;

    for(int j=0; j < regions->size(); ++j)
    {
        if((double)(regions->at(j).count()*multiplier) / total == 0)
        {
            width = 10.1;
        }
        else
        {
            width =(double) (regions->at(j).count()*multiplier) / total;
        }

      height = 95;

       if(j % rows == 0) // if new row
      {
          yValue = yValue -height - 5;
          currentRow = -1;
      }
      currentRow++;

      if (currentRow == 0) // if it is first row
      {
          xValue = 1;
      }
      else
      {
          xValue = regions->at(j-1).getX()+regions->at(j-1).getWidth()+1;
      }

      (*regions)[j].setX(xValue);
      (*regions)[j].setY(yValue);
      (*regions)[j].setWidth(width);
      (*regions)[j].setHeight(height);

    }
}
//void StateCalculator::activate(int value)
//{
//    if(value==0)
//    void StateCalculator::identifyStateRectangles(QList<dataTuple>* listofstates, QList<dataRegion>* regions, QList<dataState> *states);
//    value=1;
//}

void StateCalculator::identifyStateRectangles(QList<dataTuple>* listofstates, QList<dataRegion>* regions, QList<dataState> *states)
{
       int total=0;

        for(int i=0; i< states->size(); ++i)
        {
            total+=(*states)[i].count();
            qDebug()<< (*states)[i].state()<<(*states)[i].count();
        }

        double width, height, xValue, yValue;
        yValue =95;
        xValue = 1;
        double multiplier;
        double gap=1.5;
        double regHeight=95;

        for(int j=0; j < regions->size(); ++j)
        {
            multiplier=(regHeight-((double)regions->at(j).getNumberofStates()*gap))/(double)regions->at(j).count();
            for(int k=0; k < states->size(); ++k)
            {

                if(QString::compare(states->at(k).getStateRegion(), regions->at(j).getRegion(), Qt::CaseInsensitive) == 0)
                {
                    if((double)(states->at(k).count() == 0))
                    {
                        height = 0.1;
                        if((double)regions->at(j).getNumberofStates()==1)
                            height=regions->at(j).getHeight();
                    }
                    else
                    {   //state rectangle height
                        height =((double)(states->at(k).count()*multiplier));
                    }

                    width=regions->at(j).getWidth();
                    xValue=regions->at(j).getX();
                    (*states)[k].setX(xValue);
                    (*states)[k].setY(yValue);
                    (*states)[k].setWidth(width);
                    (*states)[k].setHeight(height);
                    yValue-=height+gap;
                }
            }
            yValue=95;
       //}
    }
}
