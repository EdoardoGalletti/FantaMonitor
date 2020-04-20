#include "mainwindow.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
  //, ui(new Ui::MainWindow)
{
    setup();
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setup()
{
    // Main Window setup
    this->setGeometry(0, 0, 1201, 801);
    AlignToCenter(this);

    statusBar = new QStatusBar(this);
    statusBar->setGeometry(0, this->height() - 20, this->width(), 20);

    /*****************************************************/
    /**************** QWIDGETS CREATION ******************/
    /*****************************************************/

    // Create Teams Management Panel
    teamsManagementPanel = new QGroupBox(this);
    // Create Teams Management SubWidgets
    rmTeamPb = new QPushButton(teamsManagementPanel);
    addTeamPb = new QPushButton(teamsManagementPanel);
    expTeamPb = new QPushButton(teamsManagementPanel);
    modTeamPb = new QPushButton(teamsManagementPanel);
    teamsNameEdit = new QTextEdit(teamsManagementPanel);
    teamTable = new QTableWidget(teamsManagementPanel);
    teamTable->setRowCount(8);
    teamTable->setColumnCount(2);
    teamTableHeader<<"Name"<<"Credits";
    teamTable->setHorizontalHeaderLabels(teamTableHeader);
    teamTable->verticalHeader()->setVisible(false); // disattiva i numeri delle righe a sinistra
    teamTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    teamTable->setSelectionBehavior(QAbstractItemView::SelectRows); // Quando selezioni una cella seleziona tutta la riga
    teamTable->setSelectionMode(QAbstractItemView::SingleSelection); // selezione singola
    teamTable->setShowGrid(false); // non mostra la griglia
    teamTable->setStyleSheet("QTableView {selection-background-color: red;}"); // sfondo rosso della selezione
    teamTab = new QTableWidget(teamsManagementPanel);
    // Set geometry
    teamsManagementPanel->setGeometry(290, 101, 900, 250);
    teamsManagementPanel->setTitle("Teams Management");
    addTeamPb->setGeometry(33, 45, 45, 45);
    rmTeamPb->setGeometry(96, 45, 45, 45);
    expTeamPb->setGeometry(33, 138, 45, 45);
    modTeamPb->setGeometry(96, 138, 45, 45);
    teamsNameEdit->setGeometry(33, 98, 107, 30);
    teamTable->setGeometry(152, 37, 202, 183);
    teamTab->setGeometry(371, 38, 503, 182);
    // Set icons
    rmTeamPb->setIcon(QIcon(":/new/img/Resources/BtnImages/RemoveTeam.png"));
    addTeamPb->setIcon(QIcon(":/new/img/Resources/BtnImages/AddTeam.png"));
    expTeamPb->setIcon(QIcon(":/new/img/Resources/BtnImages/ExcelExport.png"));
    modTeamPb->setIcon(QIcon(":/new/img/Resources/BtnImages/ModifyTeam.png"));
    rmTeamPb->setIconSize(QSize(32, 32));
    addTeamPb->setIconSize(QSize(32, 32));
    expTeamPb->setIconSize(QSize(32, 32));
    modTeamPb->setIconSize(QSize(32, 32));
    // Signals and Slots
    QObject::connect(addTeamPb, SIGNAL(clicked()), this, SLOT(on_addTeamPb_clicked()));

    // Create Players Management Panel
    playersManagementPanel = new QGroupBox(this);
    // Create Player Management Pushbuttons
    addPlayerPb = new QPushButton(playersManagementPanel);
    rmPlayerPb = new QPushButton(playersManagementPanel);
    refreshPlayersPb = new QPushButton(playersManagementPanel);
    freeTab = new QTableWidget(playersManagementPanel);
    searchBox = new QTextEdit(playersManagementPanel);
    rolePopup = new QComboBox(playersManagementPanel);
    // Set geometry
    playersManagementPanel->setGeometry(50, 396, 375, 355);
    playersManagementPanel->setTitle("Players Management");
    addPlayerPb->setGeometry(300, 68, 45, 45);
    rmPlayerPb->setGeometry(300, 129, 45, 45);
    refreshPlayersPb->setGeometry(300, 195, 45, 45);
    freeTab->setGeometry(28, 70, 253, 255);
    searchBox->setGeometry(29, 38, 101, 23);
    rolePopup->setGeometry(142, 36, 70, 27);
    // Set icons
    addPlayerPb->setIcon(QIcon(":/new/img/Resources/BtnImages/AddPlayer.png"));
    rmPlayerPb->setIcon(QIcon(":/new/img/Resources/BtnImages/RemovePlayer.png"));
    refreshPlayersPb->setIcon(QIcon(":/new/img/Resources/BtnImages/Refresh.png"));
    addPlayerPb->setIconSize(QSize(32, 32));
    rmPlayerPb->setIconSize(QSize(32, 32));
    refreshPlayersPb->setIconSize(QSize(32, 32));

    // Create Player Info Panel
    playerInfoPanel = new QGroupBox(this);
    // Create Player Info Widgets
    playerInfoTab = new QTableWidget(playerInfoPanel);
    graphsCb = new QCheckBox(playerInfoPanel);
    playedGamesAx = new QWidget(playerInfoPanel);
    bonusAx = new QWidget(playerInfoPanel);
    playerNameLabel = new QLabel(playerInfoPanel);
    // Set geometry
    playerInfoPanel->setGeometry(740, 397, 450, 354);
    playerInfoPanel->setTitle("Player Info");
    playerInfoTab->setGeometry(20, 59, 202, 275);
    graphsCb->setGeometry(359, 15, 75, 23);
    playedGamesAx->setGeometry(258, 52, 140, 140);
    bonusAx->setGeometry(258, 197, 140, 140);
    playerNameLabel->setGeometry(20, 19, 200, 25);

    // Create Timer Panel
    TimerPanel = new QGroupBox(this);
    // Create Timer Widgets
    timerEb = new QTextEdit(TimerPanel);
    startPb = new QPushButton(TimerPanel);
    stopPb = new QPushButton(TimerPanel);
    resetPb = new QPushButton(TimerPanel);
    // Set geometry
    TimerPanel->setGeometry(482, 396, 200, 150);
    TimerPanel->setTitle("Timer Panel");
    timerEb->setGeometry(78, 21, 45, 45);
    startPb->setGeometry(16, 88, 45, 45);
    stopPb->setGeometry(78, 88, 45, 45);
    resetPb->setGeometry(140, 88, 45, 45);
    // Set icons
    startPb->setIcon(QIcon(":/new/img/Resources/BtnImages/Start.png"));
    stopPb->setIcon(QIcon(":/new/img/Resources/BtnImages/Stop.png"));
    resetPb->setIcon(QIcon(":/new/img/Resources/BtnImages/Reset.png"));
    startPb->setIconSize(QSize(32, 32));
    stopPb->setIconSize(QSize(32, 32));
    resetPb->setIconSize(QSize(32, 32));

    /*****************************************************/
    /**************** qApp STYLESHEET ********************/
    /*****************************************************/

    qApp->setStyleSheet(QString("QPushButton         {color: #333333; background-color: #000000; border: 2px solid #808080; border-style: outset; border-radius: 5px;} "
                                "QPushButton:hover   {color: #ffffff; border: 2px solid #e6e6e6;} "
                                "QPushButton:pressed {color: #ffffff; border: 2px solid #808080;}"
                                "QGroupBox           {color: #ffffff;}"
                                "QTextEdit           {color: #000000; background-color: #ffffff}"
                                "QComboBox           {color: #000000; background-color: #ffffff}"
                                "QMainWindow         {background-color: #000000}"
                                "QMenuBar            {background-color: #000000}"
                                "QLabel              {color: #ffffff; background-color: #000000}"
                                "QStatusBar          {color: #ffffff; background-color: #808080}"
                                "QMenuBar            {color: #ffffff; background-color: #000000}"
                                "QMessageBox         {background-color: #000000}"
                                "QMessageBox QPushButton {}"));

    // Set Main Window title
    this->setWindowTitle("Fanta Manager v0.01");
}

void MainWindow::createActions()
{
    newAct = new QAction(tr("&New League"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new league"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newLeague);
    //    ...
    //    alignmentGroup = new QActionGroup(this);
    //    alignmentGroup->addAction(leftAlignAct);
    //    alignmentGroup->addAction(rightAlignAct);
    //    alignmentGroup->addAction(justifyAct);
    //    alignmentGroup->addAction(centerAct);
    //    leftAlignAct->setChecked(true);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    //    fileMenu->addAction(openAct);
    //    fileMenu->addAction(saveAct);
    //    fileMenu->addAction(printAct);
    //    fileMenu->addSeparator();
    //    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    //    editMenu->addAction(undoAct);
    //    editMenu->addAction(redoAct);
    //    editMenu->addSeparator();
    //    editMenu->addAction(cutAct);
    //    editMenu->addAction(copyAct);
    //    editMenu->addAction(pasteAct);
    //    editMenu->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    //    helpMenu->addAction(aboutAct);
    //    helpMenu->addAction(aboutQtAct);
}

void MainWindow::newLeague()
{
    CreateLeagueUI cl;
    cl.setModal(true);
    cl.exec();

    LeagueID = numLeagues;
    numLeagues += 1;
    Leagues.resize(numLeagues);
    Leagues[LeagueID].setLeagueName(QString("Lega di prova"));
    this->statusBar->showMessage("League successfully created!");
}

void MainWindow::on_addTeamPb_clicked()
{
    if (numLeagues == 0){
        QMessageBox noLeagueErrorBox;
        noLeagueErrorBox.setIcon(QMessageBox::Critical);
        noLeagueErrorBox.setText("No League Available! Please, create one!");
        noLeagueErrorBox.exec();
    }
    else {
        // this->statusBar->showMessage("Button Pressed!"); // --> per provare la status bar
        QString teamName = teamsNameEdit->toPlainText();
        Leagues[LeagueID].addTeam(teamName);
        //insert data
        for (int i = 0; i < Leagues[LeagueID].getLeagueTeamsNumber(); i++) {
            teamTable->setItem(i, 0, new QTableWidgetItem( Leagues[LeagueID].getLeagueTeams()[i].getTeamName() ) );
            teamTable->setItem(i, 1, new QTableWidgetItem( QString::number(Leagues[LeagueID].getLeagueTeams()[i].getTeamCredits()) ) );
        }
    };

}


void MainWindow::AlignToCenter(QWidget* window){
    QList<QScreen *> AvailableScreens;
    AvailableScreens = QGuiApplication::screens();
    QScreen* screen = AvailableScreens.first();
    window->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    window->size(),
                    screen->availableGeometry()
                    )
                );
}
