#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include<QVector>

class DataConfig : public QObject
{
    Q_OBJECT
public:
    explicit DataConfig(QObject *parent = nullptr);
signals:

public slots:
public:
    QVector<int> mdata;
};

#endif // DATACONFIG_H
