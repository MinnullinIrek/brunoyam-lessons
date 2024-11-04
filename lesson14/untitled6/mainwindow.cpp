#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(QSize(330, 100));

    QGridLayout *layout = new QGridLayout(this);


    summ = new QPushButton("посчитать сумму");


    left = new QLineEdit();

    right = new QLineEdit(this);
    result = new QLineEdit(this);;
    info = new QLabel(this);

    layout->addWidget(left, 0, 1);
    layout->addWidget(right, 0, 2, Qt::AlignHCenter);
    layout->addWidget(summ, 1, 0);
    layout->addWidget(result, 1, 1, Qt::AlignHCenter);
    layout->addWidget(info, 1, 2, Qt::AlignHCenter);

    QObject::connect(summ, &QPushButton::clicked, this, &MainWindow::calculateSum);
    QObject::connect(this, &MainWindow::moreThan100, this, &MainWindow::moreThan100Slot);
    QObject::connect(this, &MainWindow::sendA, this, &MainWindow::getA);




}

MainWindow::~MainWindow() {}


void MainWindow::moreThan100Slot(QString res) {
    info->setText(QString("больше 100 ") + res);
}

void MainWindow::calculateSum() {
    emit sendA(A());
    auto l = left->text().toInt();
    auto r = right->text().toInt();
    result->setText(QString("%0").arg(l+r));

    if(l+r > 100) {
        emit moreThan100( QString("%0").arg(l+r)) ;
    }
}

void MainWindow::getA(A a) {
     info->setText(a.text.c_str());

}

