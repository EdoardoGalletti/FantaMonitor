#ifndef CREATELEAGUEUI_H
#define CREATELEAGUEUI_H

#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
class CreateLeagueUI;
}

class CreateLeagueUI : public QDialog
{
    Q_OBJECT

public:
    explicit CreateLeagueUI(QWidget *parent = nullptr);
    ~CreateLeagueUI();
    void setup();
    void createLeague();
    void setCredits(int);
    int getCredits();
    void setnOfTeams(int);
    int getnOfTeams();

private:
    //Ui::CreateLeagueUI *ui;
    QLineEdit* leagueNameLE; // LE stands for Line Edit
    QSpinBox* nOfTeamsSB;
    QSpinBox* creditsSB;

    int credits, nOfTeams;

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // CREATELEAGUEUI_H
