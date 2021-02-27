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
        tr("Open file"), "/Users/a19034290/Desktop/FDF/project/test", tr("Image Files (*.fdf)"));
    QProcess::execute ("/Users/a19034290/Desktop/FDF/project/fdf", (QStringList)fileName);
//    exit(0);
}
