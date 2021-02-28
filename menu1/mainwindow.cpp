#include "mainwindow.h"
#include <QFileDialog>
#include <QProcess>
#include "ui_mainwindow.h"

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
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open file"), "/Users/Mac/Desktop/FDF/project/test", tr("Image Files (*.fdf)"));
    QProcess::execute ("/Users/Mac/Desktop/FDF/project/fdf", (QStringList)fileName);
//    exit(0);
}   

void MainWindow::on_pushButton_2_pressed()
{
     QProcess::execute ("/Users/Mac/Desktop/FDF/project/fdf", (QStringList)"/Users/Mac/Desktop/FDF/project/test/42.fdf");
}
