#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include <QPushButton>
#include <QGroupBox>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    /*****************************************************/
    /**************** QWIDGETS CREATION ******************/
    /*****************************************************/

    // Create Teams Management Panel
    QGroupBox* teamsManagementPanel = new QGroupBox(this);
    // Create Teams Management SubWidgets
    QPushButton* rmTeamPb = new QPushButton(teamsManagementPanel);
    QPushButton* addTeamPb = new QPushButton(teamsManagementPanel);
    QPushButton* expTeamPb = new QPushButton(teamsManagementPanel);
    QPushButton* modTeamPb = new QPushButton(teamsManagementPanel);
    QTextEdit* teamsNameEdit = new QTextEdit(teamsManagementPanel);
    // Set geometry
    teamsManagementPanel->setGeometry(290, 101, 900, 250);
    teamsManagementPanel->setTitle("Teams Management");
    addTeamPb->setGeometry(33, 45, 45, 45);
    rmTeamPb->setGeometry(96, 45, 45, 45);
    expTeamPb->setGeometry(33, 138, 45, 45);
    modTeamPb->setGeometry(96, 138, 45, 45);
    teamsNameEdit->setGeometry(33, 98, 107, 30);
    // Set icons
    rmTeamPb->setIcon(QIcon(":/new/img/Resources/BtnImages/RemoveTeam.png"));
    addTeamPb->setIcon(QIcon(":/new/img/Resources/BtnImages/AddTeam.png"));
    expTeamPb->setIcon(QIcon(":/new/img/Resources/BtnImages/ExcelExport.png"));
    modTeamPb->setIcon(QIcon(":/new/img/Resources/BtnImages/ModifyTeam.png"));
    rmTeamPb->setIconSize(QSize(32, 32));
    addTeamPb->setIconSize(QSize(32, 32));
    expTeamPb->setIconSize(QSize(32, 32));
    modTeamPb->setIconSize(QSize(32, 32));

    // Create Players Management Panel
    QGroupBox* playersManagementPanel = new QGroupBox(this);
    // Create Player Management Pushbuttons
    QPushButton* addPlayerPb = new QPushButton(playersManagementPanel);
    QPushButton* rmPlayerPb = new QPushButton(playersManagementPanel);
    QPushButton* refreshPlayersPb = new QPushButton(playersManagementPanel);
    // Set geometry
    playersManagementPanel->setGeometry(50, 396, 375, 355);
    playersManagementPanel->setTitle("Players Management");
    addPlayerPb->setGeometry(300, 68, 45, 45);
    rmPlayerPb->setGeometry(300, 129, 45, 45);
    refreshPlayersPb->setGeometry(300, 195, 45, 45);
    // Set icons
    addPlayerPb->setIcon(QIcon(":/new/img/Resources/BtnImages/AddPlayer.png"));
    rmPlayerPb->setIcon(QIcon(":/new/img/Resources/BtnImages/RemovePlayer.png"));
    refreshPlayersPb->setIcon(QIcon(":/new/img/Resources/BtnImages/Refresh.png"));
    addPlayerPb->setIconSize(QSize(32, 32));
    rmPlayerPb->setIconSize(QSize(32, 32));
    refreshPlayersPb->setIconSize(QSize(32, 32));


    /*****************************************************/
    /**************** qApp STYLESHEET ********************/
    /*****************************************************/

    qApp->setStyleSheet(QString("QPushButton         {color: #333333; border: 2px solid #808080; border-style: outset; border-radius: 5px;} "
                                "QPushButton:hover   {color: #ffffff; border: 2px solid #e6e6e6;} "
                                "QPushButton:pressed {color: #ffffff; border: 2px solid #808080;}"
                                "QGroupBox           {color: #ffffff;}"
                                "QTextEdit           {color: #000000;}"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
