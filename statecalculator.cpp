#include "statecalculator.h"



StateCalculator::StateCalculator()
{

}

void StateCalculator::identifyRectangles(QList<dataTuple>* listofstates)
{

    int total=0;
    for(int i=0; i< listofstates->size(); ++i)
    {
       total+=(*listofstates)[i].count();

    }
    double width, height, xValue, yValue;
    yValue =110;
    xValue = 1;
    int rows = 5;
    int currentRow=0;
    int multiplier = 400;

    for(int j=0; j < listofstates->size(); ++j)
    {
        if((double)(listofstates->at(j).count()*multiplier) / total == 0)
        {
            width = 1;
        }
        else
        {
            width =(double) (listofstates->at(j).count()*multiplier) / total;
        }

      height = 5;

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
          xValue = listofstates->at(j-1).getX()+listofstates->at(j-1).getWidth()+1;
      }

      (*listofstates)[j].setX(xValue);
      (*listofstates)[j].setY(yValue);
      (*listofstates)[j].setWidth(width);
      (*listofstates)[j].setHeight(height);

//     calculateX(&listofstates->value(j));
//     calculateY((listofstates)[j]);
//     calculateWidth((listofstates)[j]);
//     calculateHeigth((listofstates)[j]);

    }

}

void StateCalculator::calculateX(dataTuple* data)
{
    int xValue;

    data->setX(xValue);
}

void StateCalculator::calculateY(dataTuple* data)
{
    int yValue;

    data->setY(yValue);
}
void StateCalculator::calculateWidth(dataTuple* data)
{
    int width;

    data->setWidth(width);
}

void StateCalculator::calculateHeigth(dataTuple* data)
  {
    int height;

    data->setHeight(height);
  }
