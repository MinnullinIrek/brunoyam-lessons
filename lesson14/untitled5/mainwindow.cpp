#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    QObject::connect(ui->summ, &QPushButton::clicked, this, &MainWindow::calculateSumm);
    QObject::connect(this, &MainWindow::moreThan100, this, &MainWindow::moreThan100Slot);


}


void MainWindow::calculateSumm() {

    auto l = ui->left->text().toInt();
    auto r = ui->right->text().toInt();
    ui->result->setText(QString("%0").arg(l+r));

    if(l+r > 100) {
        emit moreThan100(l+r);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::moreThan100Slot(int res) {
    ui->label->setText(QString("больше 100 [%0]").arg(res));


}
