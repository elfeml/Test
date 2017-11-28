#include "filereader.h"


FileReader::FileReader(QString filename)
{
    m_listTuple = new QList<dataTuple>();


    QFile file(filename);
    if ( file.open(QFile::ReadOnly | QFile::Text) ) {

        QTextStream in(&file);
        dataTuple tuple;


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


                      int count=stringList[2].toInt();
                      tuple.setCount(count);


                      float incidence= stringList[3].toFloat();
                      tuple.setIncidence(incidence);

                stringList.clear();
//              tuple.toString();

                bool in = false;
//               Qvector
                for(int j = 0; j < m_listTuple->size(); ++j)
                {
                     // Compare states in m_listTuple and tuple and find total count for each state
                    if (QString::compare((*m_listTuple)[j].stateName(), tuple.stateName(), Qt::CaseInsensitive) == 0)
                    {
                        (*m_listTuple)[j].setCount((*m_listTuple)[j].count() + tuple.count());
                        in = true;
                       (*m_listTuple)[j].toString();

                    }
                }

                if(!in)
                {
                     m_listTuple->append(tuple);// m_listTuple stores each item in StringList
                }
            }
         }
    }

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




