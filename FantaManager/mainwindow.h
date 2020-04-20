#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QAction>
#include <QPushButton>
#include <QGroupBox>
#include <QTextEdit>
#include <QTableWidget>
#include <QComboBox>
#include <QCheckBox>
#include <QWidget>
#include <QLabel>
#include <QObject>
#include <QHeaderView>
#include <QStatusBar>
#include <QMenuBar>
#include <vector>
#include "Team.h"
#include "League.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructors
    MainWindow(QWidget *parent = nullptr);

    // Destructors
    ~MainWindow();

    std::vector<League> Leagues;
    int numLeagues = 0, LeagueID = 0;

public slots:
    // Push Buttons Slots
    void on_addTeamPb_clicked();

private slots:

private:
    Ui::MainWindow *ui;
    void setup();
    void createMenus();
    void createActions();
    void newLeague();

    // Status Bar & Menu Bar
    QStatusBar* statusBar;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
//    QActionGroup *alignmentGroup;
    QAction *newAct;
//    QAction *openAct;
//    QAction *saveAct;
//    QAction *printAct;
//    QAction *exitAct;
//    QAction *undoAct;
//    QAction *redoAct;
//    QAction *cutAct;
//    QAction *copyAct;
//    QAction *pasteAct;
//    QAction *boldAct;
//    QAction *italicAct;
//    QAction *leftAlignAct;
//    QAction *rightAlignAct;
//    QAction *justifyAct;
//    QAction *centerAct;
//    QAction *setLineSpacingAct;
//    QAction *setParagraphSpacingAct;
//    QAction *aboutAct;
//    QAction *aboutQtAct;
//    QLabel *infoLabel;

    // Create Teams Management Panel
    QGroupBox* teamsManagementPanel;
    // Create Teams Management SubWidgets
    QPushButton* rmTeamPb;
    QPushButton* addTeamPb;
    QPushButton* expTeamPb;
    QPushButton* modTeamPb;
    QTextEdit* teamsNameEdit;
    QTableWidget* teamTable;
    QStringList teamTableHeader;
    QTableWidget* teamTab;

    // Create Players Management Panel
    QGroupBox* playersManagementPanel;
    // Create Player Management Pushbuttons
    QPushButton* addPlayerPb;
    QPushButton* rmPlayerPb;
    QPushButton* refreshPlayersPb;
    QTableWidget* freeTab;
    QTextEdit* searchBox;
    QComboBox* rolePopup;

    // Create Player Info Panel
    QGroupBox* playerInfoPanel;
    // Create Player Info Widgets
    QTableWidget* playerInfoTab;
    QCheckBox* graphsCb;
    QWidget* playedGamesAx;
    QWidget* bonusAx;
    QLabel* playerNameLabel;

    // Create Timer Panel
    QGroupBox* TimerPanel;
    // Create Timer Widgets
    QTextEdit* timerEb;
    QPushButton* startPb;
    QPushButton* stopPb;
    QPushButton* resetPb;
};
#endif // MAINWINDOW_H
