#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    qApp->setStyleSheet(QString("QPushButton         {color: #333333; border: 2px solid #808080; border-style: outset; border-radius: 5px;} "
                                "QPushButton:hover   {color: #ffffff; border: 2px solid #e6e6e6;} "
                                "QPushButton:pressed {color: #ffffff; border: 2px solid #808080;}"));

    // Set icon for push buttons
    ui->rmTeamPb->setIcon(QIcon(":/new/img/Resources/BtnImages/RemoveTeam.png"));
    ui->addTeamPb->setIcon(QIcon(":/new/img/Resources/BtnImages/AddTeam.png"));
    ui->expTeamPb->setIcon(QIcon(":/new/img/Resources/BtnImages/ExcelExport.png"));
    ui->modTeamPb->setIcon(QIcon(":/new/img/Resources/BtnImages/ModifyTeam.png"));
    ui->rmTeamPb->setIconSize(QSize(32, 32));
    ui->addTeamPb->setIconSize(QSize(32, 32));
    ui->expTeamPb->setIconSize(QSize(32, 32));
    ui->modTeamPb->setIconSize(QSize(32, 32));

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
