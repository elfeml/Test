#ifndef FILEREADER_H
#define FILEREADER_H

#include "datatuple.h"
#include "dataregion.h"
#include "datastate.h"

#include <QFile>


class FileReader
{
public:
    FileReader(QString filename);
//    ~FileReader();

    QList<dataTuple> *m_listTuple;
    QList<dataTuple>* getData();
    QList<dataRegion> *getDataRegion();
    QList<dataRegion> *m_listRegion;
    QList<dataState> *getDataState();
    QList<dataState> *m_listState;
};

#endif // FILEREADER_H
