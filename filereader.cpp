#include "filereader.h"
//QList<dataState> FileReader::m_listState;
FileReader::FileReader(QString filename)
{
    m_listTuple = new QList<dataTuple>();
    m_listRegion= new QList<dataRegion>();
    m_listState= new QList<dataState>();
    dataRegion initRegion;
    initRegion.setRegion("West");
     m_listRegion->append(initRegion);
     initRegion.setRegion("Southwest");
      m_listRegion->append(initRegion);
     initRegion.setRegion("Midwest");
      m_listRegion->append(initRegion);
     initRegion.setRegion("Southeast");
      m_listRegion->append(initRegion);
     initRegion.setRegion("Northeast");
      m_listRegion->append(initRegion);

    QFile file(filename);
    if ( file.open(QFile::ReadOnly | QFile::Text) ) {
        QTextStream in(&file);
        dataTuple tuple;
        dataState stateobj;
        dataRegion regionobj;

        while (!in.atEnd())
        {
            QString line = in.readLine();
            QList<QString> stringList;
            if(!line.isEmpty())
            {
                for (QString item : line.split(","))
                      stringList.append(QString(item));

                      double time= stringList[0].toDouble();
                      tuple.setTime(time);

                      QString state=stringList[1];
                      tuple.setStateName(state);
                      stateobj.setState(state);

                      int count=stringList[2].toInt();
                      tuple.setCount(count);
                      regionobj.setCount(count);
                      stateobj.setCount(count);

                      float incidence= stringList[3].toFloat();
                      tuple.setIncidence(incidence);

                      QString region=stringList[4];
                      tuple.setRegionName(region);
                      regionobj.setRegion(region);
                      stateobj.setStateRegion(region);

                      stringList.clear();
                      bool in = false;
                      bool uniqueRegion = true;
                      bool uniqueState = true;

//STATE LIST
                for(int j = 0; j < m_listTuple->size(); ++j)
                {
                   if (QString::compare((*m_listState)[j].state(), tuple.stateName(), Qt::CaseInsensitive) == 0)
                      {
                         (*m_listState)[j].setCount((*m_listState)[j].count() + stateobj.count());
                          uniqueState = false;
                      }
                }
                if (uniqueState)
                {
                   m_listState->append(stateobj);
                }
//REGION LIST
                for(int k = 0; k < m_listRegion->size(); ++k)
                   {
                    int value = QString::compare(tuple.getRegionName(), (*m_listRegion)[k].getRegion(), Qt::CaseInsensitive);
                       if (value == 0)
                       {
                           uniqueRegion = false;
                           (*m_listRegion)[k].setCount((*m_listRegion)[k].count() + regionobj.count());//update count
                           (*m_listRegion)[k].addState();
                       }
                   }
                   if (uniqueRegion)
                   {
                      m_listRegion->append(regionobj);
                   }
    /*end*/     if(!in)
                   {
                     m_listTuple->append(tuple);// m_listTuple stores each item in StringList
                }
            }
         }
    }
  file.close();
}

QList<dataTuple> *FileReader::getData()
{
    return m_listTuple;// getData is called by mainInterface
}
QList<dataState> *FileReader::getDataState()
{
    return m_listState;// getData is called by mainInterface
}
QList<dataRegion> *FileReader::getDataRegion()
{
    return m_listRegion;// getData is called by mainInterface
}




