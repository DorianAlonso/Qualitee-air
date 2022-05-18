#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qualite_air.h"
#include <QtNetwork>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_get_aqi_clicked()
{
    Qualite_air q1(0);
    q1.cville=ui->lineEdit->text();
    ui->doubleSpinBox->setValue(q1.get_aqi());
    ui->progressBar->setValue(q1.get_aqi());
    ui->label->setText(q1.ville);


    if (q1.get_aqi()<=50){
    ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color:green}");
}
    if (q1.get_aqi()>=51&&q1.get_aqi()<=100){
    ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color:yellow}");
}
    if (q1.get_aqi()>=101&&q1.get_aqi()<=150){
    ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color:orange}");
}
    if (q1.get_aqi()>=151&&q1.get_aqi()<=200){
    ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color:red}");
}
    if (q1.get_aqi()>=201&&q1.get_aqi()<=300){
    ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color:purple}");
}
    if (q1.get_aqi()>300){
    ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color:brown}");
}


}




