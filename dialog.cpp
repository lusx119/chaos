#include "dialog.h"
#include "ui_dialog.h"
#include"mainwindow.h"
extern int year;
extern double i,l,k,p;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}
