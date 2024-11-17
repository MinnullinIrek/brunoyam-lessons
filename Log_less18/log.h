#ifndef LOG_H
#define LOG_H

#include <qfile.h>
#include <QObject>
#include <QVector>
#include <QString>
#include <qthread.h>
#include <QDebug>


class Log : public QObject
{
    Q_OBJECT
public:
    explicit Log(QObject *parent = nullptr);

public slots:
    void putMessage(QString mes) {
        qDebug() <<"                           message from thread " << QThread::currentThreadId() << " " << mes;
    }


};

#endif // LOG_H
