#ifndef FILEREADER_H
#define FILEREADER_H

#include "datatuple.h"
#include <QFile>


class FileReader
{
public:
    FileReader(QString filename);

    QList<dataTuple> *m_listTuple;
    QList<dataTuple>* getData();
};

#endif // FILEREADER_H
