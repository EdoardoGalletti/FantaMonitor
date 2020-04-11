#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

#include <QPushButton>

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

void MainWindow::on_testButton_clicked()
{
//    QMessageBox::information( this, "Dummy Button Msg",
//                                "Test msg ;)", QMessageBox::Ok );
//    QMessageBox msg;
//    msg.setText("Messaggiazzo");
//    msg.exec();
}
