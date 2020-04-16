#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGroupBox>
#include <QTextEdit>
#include <QTableView>
#include <QComboBox>
#include <QCheckBox>
#include <QWidget>
#include <QLabel>
#include <QObject>

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

public slots:
    // Push Buttons Slots
    void on_addTeamPb_clicked();

private slots:

private:
    Ui::MainWindow *ui;
    void setup();

    // Status Bar
    QStatusBar* statusBar;

    // Create Teams Management Panel
    QGroupBox* teamsManagementPanel;
    // Create Teams Management SubWidgets
    QPushButton* rmTeamPb;
    QPushButton* addTeamPb;
    QPushButton* expTeamPb;
    QPushButton* modTeamPb;
    QTextEdit* teamsNameEdit;
    QTableView* teamTable;
    QTableView* teamTab;

    // Create Players Management Panel
    QGroupBox* playersManagementPanel;
    // Create Player Management Pushbuttons
    QPushButton* addPlayerPb;
    QPushButton* rmPlayerPb;
    QPushButton* refreshPlayersPb;
    QTableView* freeTab;
    QTextEdit* searchBox;
    QComboBox* rolePopup;

    // Create Player Info Panel
    QGroupBox* playerInfoPanel;
    // Create Player Info Widgets
    QTableView* playerInfoTab;
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
