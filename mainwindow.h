#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"dialog.h"
#include <QMainWindow>
#include "dialog.h"
#include "ui_dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Dialog *dialog=new Dialog;
public slots:
    void choice();
    void choice1();
    void con();
    //void choice2();
};

#endif // MAINWINDOW_H
