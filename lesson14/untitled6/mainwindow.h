#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QSpacerItem>
#include <string.h>

struct A {
    std::string text = "sdsfds";
};

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void moreThan100(QString);
    void sendA(A);
public slots:
    void moreThan100Slot(QString) ;
    void getA(A);

    void calculateSum();

private:
    QPushButton *summ;
    QLineEdit *left;
    QLineEdit *right;
    QLineEdit *result;
    QLabel *info;
};
#endif // MAINWINDOW_H
