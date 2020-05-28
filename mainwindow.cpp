#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <math.h>
#include<QDebug>
#include "dialog.h"
int year;
double l,i,k;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(choice()));
    connect(ui->comboBox1,SIGNAL(currentIndexChanged(QString)),this,SLOT(choice1()));
    connect(ui->pushButton,&QPushButton::released,this,&MainWindow::con);
    connect(ui->pushButton_2,&QPushButton::released,this,[=](){
        dialog1->exec();
    });
    connect(dialog1->ui->pushButton,&QPushButton::released,this,&MainWindow::clear);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::choice()
{
    if(ui->comboBox->currentIndex()==0) {ui->doubleSpinBox->setValue(4.75);ui->stackedWidget_2->setCurrentIndex(0);}
    else if(ui->comboBox->currentIndex()==1) {ui->doubleSpinBox->setValue(3.25);ui->stackedWidget_2->setCurrentIndex(0);}
    else if(ui->comboBox->currentIndex()==2) ui->stackedWidget_2->setCurrentIndex(1);

}
void MainWindow::choice1()
{
    if(ui->comboBox1->currentIndex()==0) ui->stackedWidget->setCurrentIndex(0);
    else if(ui->comboBox1->currentIndex()==1) ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::con()
{

    QString a,b,c,q;
    l=ui->doubleSpinBox->value()/1200;
    if(ui->comboBox3->currentIndex()==0) year=1;
    else if(ui->comboBox3->currentIndex()==1) year=2;
    else if(ui->comboBox3->currentIndex()==2) year=3;
    else if(ui->comboBox3->currentIndex()==3) year=4;
    else if(ui->comboBox3->currentIndex()==4) year=5;
    else if(ui->comboBox3->currentIndex()==5) year=6;
    else if(ui->comboBox3->currentIndex()==6) year=7;
    else if(ui->comboBox3->currentIndex()==7) year=8;
    else if(ui->comboBox3->currentIndex()==8) year=9;
    else if(ui->comboBox3->currentIndex()==9) year=10;
    else if(ui->comboBox3->currentIndex()==10) year=11;
    else if(ui->comboBox3->currentIndex()==11) year=12;
    else if(ui->comboBox3->currentIndex()==12) year=13;
    else if(ui->comboBox3->currentIndex()==13) year=14;
    else if(ui->comboBox3->currentIndex()==14) year=15;
    else if(ui->comboBox3->currentIndex()==15) year=16;
    else if(ui->comboBox3->currentIndex()==16) year=17;
    else if(ui->comboBox3->currentIndex()==17) year=18;
    else if(ui->comboBox3->currentIndex()==18) year=19;
    else if(ui->comboBox3->currentIndex()==19) year=20;
    else if(ui->comboBox3->currentIndex()==20) year=21;
    else if(ui->comboBox3->currentIndex()==21) year=22;
    else if(ui->comboBox3->currentIndex()==22) year=23;
    else if(ui->comboBox3->currentIndex()==23) year=24;
    else if(ui->comboBox3->currentIndex()==24) year=25;
    if(ui->comboBox->currentIndex()!=2&&ui->comboBox1->currentIndex()==0)
    {
        a=ui->lineEdit->text();
        b=ui->lineEdit_2->text();

        double x=a.toDouble();
        double y=b.toDouble();
        double z;
        dialog->ui->label_9->show();
        dialog->ui->label_10->show();
        if(ui->comboBox2->currentIndex()==0) z=0.2;
        else if(ui->comboBox2->currentIndex()==1) z=0.25;
        else if(ui->comboBox2->currentIndex()==2) z=0.3;
        else if(ui->comboBox2->currentIndex()==3) z=0.35;
        else if(ui->comboBox2->currentIndex()==4) z=0.4;
        else if(ui->comboBox2->currentIndex()==5) z=0.45;
        else if(ui->comboBox2->currentIndex()==6) z=0.5;
        else if(ui->comboBox2->currentIndex()==7) z=0.55;
        else if(ui->comboBox2->currentIndex()==8) z=0.6;
        else if(ui->comboBox2->currentIndex()==9) z=0.65;
        else if(ui->comboBox2->currentIndex()==10) z=0.7;
        else if(ui->comboBox2->currentIndex()==11) z=0.75;
        else if(ui->comboBox2->currentIndex()==12) z=0.8;
        else if(ui->comboBox2->currentIndex()==13) z=0.85;
        k=x*y*z;
        QString h=QString::number((int)(x*y*(1-z)),10);
        dialog->ui->label_9->setText("首付（元）");
        dialog->ui->label_10->setText(h);

        if(ui->radioButton->isChecked())
        {
            i=k*l*pow((1+l),year*12)/(pow((1+l),year*12)-1)*year*12;
            dialog->ui->label_3->setText("每月月供（元）");
            QString j=QString::number((int)(i/year/12),10);
            dialog->ui->label2->setText(j);
            dialog->ui->label_15->hide();
            dialog->ui->label_16->hide();
        }
        else if(ui->radioButton_2->isChecked())
        {
            i=(year*12+1)*k*l/2+k;
            dialog->ui->label_15->show();
            dialog->ui->label_16->show();
            dialog->ui->label_16->setText("每月递减（元）");
            dialog->ui->label_3->setText("首月月供（元）");
            QString m=QString::number((int)(k*l+k/year/12),10);
            dialog->ui->label2->setText(m);
            QString n=QString::number((int)(k/year/12*l),10);
            dialog->ui->label_15->setText(n);
        }
    }
    if(ui->comboBox->currentIndex()!=2&&ui->comboBox1->currentIndex()==1)
    {
        a=ui->lineEdit_4->text();
        k=a.toDouble()*10000;
        if(ui->radioButton->isChecked())
        {
            i=k*l*pow((1+l),year*12)/(pow((1+l),year*12)-1)*year*12;
            dialog->ui->label_3->setText("每月月供（元）");
            QString j=QString::number((int)(i/year/12),10);
            dialog->ui->label2->setText(j);
            dialog->ui->label_15->hide();
            dialog->ui->label_16->hide();

        }
        else if(ui->radioButton_2->isChecked())
        {
            i=(year*12+1)*k*l/2+k;
            dialog->ui->label_15->show();
            dialog->ui->label_16->show();
            dialog->ui->label_16->setText("每月递减（元）");
            dialog->ui->label_3->setText("首月月供（元）");
            QString m=QString::number((int)(k*l+k/year/12),10);
            dialog->ui->label2->setText(m);
            QString n=QString::number((int)(k/year/12*l),10);
            dialog->ui->label_15->setText(n);
        }
    }
    if(ui->comboBox->currentIndex()==2)
    {
        dialog->ui->label_9->hide();
        dialog->ui->label_10->hide();
        a=ui->lineEdit_7->text();
        c=ui->lineEdit_3->text();
        double x=a.toDouble()*10000.0;
        double y=ui->doubleSpinBox_2->value()/1200.0;
        double t=c.toDouble()*10000.0;
        double v=ui->doubleSpinBox_3->value()/1200.0;
        k=x+t;
        if(ui->radioButton->isChecked())
        {
            i=x*y*pow((1+y),year*12)/(pow((1+y),year*12)-1)*year*12+t*v*pow((1+v),year*12)/(pow((1+v),year*12)-1)*year*12;
            dialog->ui->label_3->setText("每月月供（元）");
            QString j=QString::number((int)(i/year/12),10);
            dialog->ui->label2->setText(j);
            dialog->ui->label_15->hide();
            dialog->ui->label_16->hide();

        }
        else if(ui->radioButton_2->isChecked())
        {
            i=(year*12+1)*x*y/2+(year*12+1)*t*v/2+k;
            dialog->ui->label_15->show();
            dialog->ui->label_16->show();
            dialog->ui->label_16->setText("每月递减（元）");
            dialog->ui->label_3->setText("首月月供（元）");
            QString m=QString::number((int)(x*y+t*v+k/year/12),10);
            dialog->ui->label2->setText(m);
            QString n=QString::number((int)(x/year/12*y+t/year/12*v),10);
            dialog->ui->label_15->setText(n);
        }
    }
    QString d=QString::number((int)i,10);
    QString e=QString::number((int)k,10);
    QString f=QString::number(year*12,10);
    QString g=QString::number((int)(i-k),10);
    dialog->ui->label4->setText(e);
    dialog->ui->label3->setText(d);
    dialog->ui->label5->setText(f);
    dialog->ui->label1->setText(g);
    qDebug()<<i;
    dialog->show();
}
void MainWindow::clear()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_7->clear();
    ui->doubleSpinBox->clear();
    ui->doubleSpinBox_3->clear();
    ui->doubleSpinBox_2->clear();
    dialog1->close();
}
