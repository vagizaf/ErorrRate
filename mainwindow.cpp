#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//    errRate.setItem(0, 1000, 1);
//    errRate.setItem(1, 2000, 501);
//    errRate.setItem(2, 3000, 1001);
//    errRate.setItem(3, 4000, 1501);
//    errRate.setItem(4, 5000, 2001);
//    errRate.setItem(24, 25000, 2101);
//    errRate.setItem(44, 45000, 2201);

//    qDebug() << errRate.getER(5, 5);
//    qDebug() << errRate.getER(24, 24);
//    qDebug() << errRate.getER(45, 45);
//    qDebug() << errRate.getER(44, 20);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_SetItems_clicked()
{
    ui->pushButton_GetER->setEnabled(true);
    ui->pushButton_SetItems->setEnabled(false);
    QString text = ui->textEdit_Items->toPlainText();
    QStringList listItems = text.split('\n');
    foreach (QString item, listItems) {
        QStringList str = item.split(' ');

        if(str.size() == 3)
        {
            errRate.setItem(str.at(0).toInt(), str.at(1).toDouble(), str.at(2).toDouble());
        }
    }
}

void MainWindow::on_textEdit_Items_textChanged()
{
    ui->pushButton_SetItems->setEnabled(true);
}

void MainWindow::on_pushButton_GetER_clicked()
{
    double er = errRate.getER(ui->lineEdit_CurrentTime->text().toInt(), ui->lineEdit_Period->text().toInt());
    ui->label_ErrorRate->setText(QString::number(er, 'f', 4));
}
