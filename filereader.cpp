#include "filereader.h"


FileReader::FileReader(QString filename)
{
    m_listTuple = new QList<dataTuple>();
    m_listRegion= new QList<dataRegion>();
    m_listState= new QList<dataState>();

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
                for (QString item : line.split(",")) {
                    stringList.append(QString(item));
                }

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
//              tuple.toString();
                bool in = false;
                bool uniqueRegion = true;
                bool uniqueState = true;
                bool uniqueTuple = true;

//TUPLE LIST
                for(int k = 0; k < m_listRegion->size(); ++k)
                {
                    int value = QString::compare(tuple.getRegionName(), (*m_listRegion)[k].getRegion(), Qt::CaseInsensitive);
                   // qDebug() << tuple.getRegionName() << (*m_listRegion)[k].getRegion() << value;

                    if (value == 0)
                    {
                        uniqueTuple = false;
                        //update count
                        (*m_listRegion)[k].setCount((*m_listRegion)[k].count() + regionobj.count());
                    }
                }
                if (uniqueTuple)
                {
                    m_listRegion->append(regionobj);
                }


//STATE LIST
                //uniqueState = true;

                for(int j = 0; j < m_listTuple->size(); ++j)
                {
                      //Compare states in m_listTuple and tuple and find total count for each state
                      if (QString::compare((*m_listState)[j].state(), tuple.stateName(), Qt::CaseInsensitive) == 0)
                      {
                         (*m_listState)[j].setCount((*m_listState)[j].count() + stateobj.count());
                          uniqueState = false;
                      }
                      qDebug() << (*m_listState)[j].state() << (*m_listState)[j].count() ;
               }


                if (uniqueState)
                {
                   m_listState->append(stateobj);
                }


//REGION LIST
               // uniqueRegion = true;

                for(int k = 0; k < m_listRegion->size(); ++k)
                {
                    int value = QString::compare(tuple.getRegionName(), (*m_listRegion)[k].getRegion(), Qt::CaseInsensitive);
                   // qDebug() << tuple.getRegionName() << (*m_listRegion)[k].getRegion() << value;

                    if (value == 0)
                    {
                        uniqueRegion = false;
                        //update count
                        (*m_listRegion)[k].setCount((*m_listRegion)[k].count() + regionobj.count());
                    }
                }
                if (uniqueRegion)
                {
                    m_listRegion->append(regionobj);
                }

//End

                if(!in)
                {
                     m_listTuple->append(tuple);// m_listTuple stores each item in StringList
                }
            }
         }
    }

//    for(int k = 0; k < m_listState->size(); ++k)
//    {
//        qDebug() << m_listState->at(k);
//    }

//    for(int k = 0; k < m_listRegion->size(); ++k)
//    {
//        qDebug() << m_listRegion->at(k);
//    }
//    qDebug() << "Close";

    file.close();
}

//FileReader::~FileReader()
//{
//    delete m_listTuple;
//}

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




