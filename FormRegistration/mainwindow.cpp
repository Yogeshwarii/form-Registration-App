#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<qdebug.h>
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


void MainWindow::on_pushButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
       if(QString::compare(filename,QString())!=0)
       {
           QImage image;
           bool valid = image.load(filename);
           if(valid)
           {
               image = image.scaledToWidth(ui->label_2->width(),Qt::SmoothTransformation);
               ui->label_2->setPixmap(QPixmap::fromImage(image));
           }
           else
           {

           }
       }
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this,"Yogeshwari","Do you want to submit the form?",QMessageBox::Ok|QMessageBox::Cancel);
            if(reply==QMessageBox::Ok)
            {
                QMessageBox::information(this,"Yogeshwari","Submitted successfully!");
            }
            if(reply==QMessageBox::Cancel)
            {
                qDebug()<<"No Submission is Made ";
            }
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this,"yogeshwari","Do you want to cancel the form?",QMessageBox::Ok|QMessageBox::Cancel);
   if(reply==QMessageBox::Ok)
   {
       qDebug()<<"You cancelled the form ";
   }
   if(reply==QMessageBox::Cancel)
   {
       qDebug()<<"Returned with no Information... ";
   }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString picpath=QFileDialog::getOpenFileName(this,tr("Open file"),"C://","PDF File(*.pdf)");
}
