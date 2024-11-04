#include <QCoreApplication>


#include <QDebug>
#include <QVector> // std::vector
#include <QList>   // std::list / std::vector
#include <QMap>    // std::map
#include <QHash>   //std::unordered_map
#include <vector>
#include <string>
#include <qstring.h>


void f1(QString a) {

}

void f2(std::string a) {

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString a = "asdadd";
    std::string a2 = "asdadd";


    f1(a);
    f2(a2);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.


    QList<int> list = {1,2,4,6,78,9,5,3,2,6,7,8};
    list.reserve(100);
    list.push_back(13);
    list.append(23);
    list.emplace_back(32);

    for (auto it = list.begin(); it != list.end(); ++it ) {
        qDebug() << *it;
    }


    std::vector<float> v;
    QVector<float> f;

    for(auto& el : v) {
        f.append(el);
    }



    return a.exec();
}
