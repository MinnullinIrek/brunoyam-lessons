#include "mainwindow.h"

#include <QApplication>
#include "untitled10lib.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Untitled10lib l;

    int i = l.sum(1, 2);
    qDebug() << i;

    MainWindow w;
    w.show();
    return a.exec();
}
