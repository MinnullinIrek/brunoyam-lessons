#include <QCoreApplication>
#include <qthread.h>
#include "log.h"
#include <messagesender.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.


    QVector<QString> container = {
        "meassage1",
        "meassage2",
        "meassage3",
        "meassage4",
        "meassage5",
        "meassage6",
        "meassage7",
        "meassage8",
    };


    Log log;
    MessageSender sender;
    QObject::connect(&sender, &MessageSender::sendMessage, &log, &Log::putMessage, Qt::QueuedConnection);

    QThread thr;
    log.moveToThread(&thr);
    thr.start();

    auto it = container.begin();
    while (it != container.end()) {

        qDebug() << "thread id =" << QThread::currentThreadId() << " message :" << *it;

        emit sender.sendMessage(*it); //log.putMessage(*it);
        ++it;
        QThread::currentThread()->sleep(1);
    }


    return a.exec();
}
