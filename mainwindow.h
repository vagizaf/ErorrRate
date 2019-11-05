#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "errorrate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_SetItems_clicked();

    void on_textEdit_Items_textChanged();

    void on_pushButton_GetER_clicked();

    void on_spinBox_CurrentTime_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    cErrorRate errRate;
};
#endif // MAINWINDOW_H
