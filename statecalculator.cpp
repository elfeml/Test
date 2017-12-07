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
       qDebug()<<(*regions)[i].getRegion()<< total;
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

void StateCalculator::identifyStateRectangles(QList<dataTuple>* listofstates, QList<dataRegion>* regions, QList<dataState> *states)
{
//NOT FINISHED
    int total=0;
    for(int i=0; i< states->size(); ++i)
    {
       total+=(*states)[i].count();

    }
    double width, height, xValue, yValue;
    yValue =195;
    xValue = 1;
    int rows = 5;
    int currentRow=0;
    int multiplier = 10;

    for(int j=0; j < states->size(); ++j)
    {

        if((double)(states->at(j).count()*multiplier) / total == 0)
        {
            height = 0.1;
        }
        else
        {
            height =(double) (states->at(j).count()*multiplier) / total;

        }

        for(int k=0; k < regions->size(); ++k)
        {
       // control the regions names to draw state rectangle inside its region rectangle
         if(QString::compare(states->at(k).getStateRegion(), regions->at(k).getRegion(), Qt::CaseInsensitive) == 0)
          {
            width=regions->at(k).getWidth()-10;
            xValue=regions->at(k).getX()+5;
          }
        }

//       if(j % rows == 0) // if new row
//      {
//          yValue = yValue -width;  //
//          currentRow = -1;
//      }
//      currentRow++;

//      if (currentRow == 0) // if it is first row
//      {
//          yValue = 1;
//      }
//      else
//      {
//          yValue = states->at(j-1).getY()+states->at(j-1).getHeight()+1;
//      }

      (*states)[j].setX(xValue);
      (*states)[j].setY(yValue);
      (*states)[j].setWidth(width);
      (*states)[j].setHeight(height);

        yValue-=height-5;
    }

}


// These methods arent used
int StateCalculator::calculateX(dataRegion data)
{
    int xValue;

//  data->setX(xValue);
    return xValue;
}

void StateCalculator::calculateY(dataRegion data)
{
    int yValue;

//    data->setY(yValue);
}
void StateCalculator::calculateWidth(dataRegion data)
{
    int width;

//    data->setWidth(width);
}

void StateCalculator::calculateHeigth(dataRegion data)
  {
    int height;

//  data->setHeight(height);
  }
