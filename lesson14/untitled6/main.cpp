#include "mainwindow.h"

#include <QApplication>

#include <QVector> // std::vector
#include <QList>   // std::list / std::vector
#include <QMap>    // std::map
#include <QHash>   //std::unordered_map

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    // QList<int> list;
    // list.reserve(100);
    // list.push_back(13);
    // list.append(23);
    // list.emplace_back(32);

    // QList<int> list2 = list;


    // QList<int> * p1 = &list;
    // QList<int> * p2 = &list2;





    w.show();

    return a.exec();
}
