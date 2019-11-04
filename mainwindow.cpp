#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "errorrate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cErrorRate errRate;
    errRate.setItem(0, 10, 1);  //0.1
    errRate.setItem(2, 100, 3); //0.022
    errRate.setItem(4, 200, 10);    //0.07

    qDebug() << errRate.getER(10, 9);
    qDebug() << errRate.getER(10, 8);
    qDebug() << errRate.getER(10, 7);
    qDebug() << errRate.getER(10, 6);

}

MainWindow::~MainWindow()
{
    delete ui;
}

