#ifndef CREATELEAGUEUI_H
#define CREATELEAGUEUI_H

#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QMessageBox>
#include <QCloseEvent>
#include "UImethods.h"
#include "League.h"

namespace Ui {
class CreateLeagueUI;
}

class CreateLeagueUI : public QDialog, public UImethods
{
    Q_OBJECT

public:
    explicit CreateLeagueUI(QWidget *parent = nullptr);
    ~CreateLeagueUI();
    void setup();
    void setCredits(int);
    int getCredits();
    void setnOfTeams(int);
    int getnOfTeams();
    League getLeague();

private:
    //Ui::CreateLeagueUI *ui;
    QLineEdit* leagueNameLE; // LE stands for Line Edit
    QSpinBox* nOfTeamsSB;
    QSpinBox* creditsSB;

    League* l;
    int credits, nOfTeams;

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // CREATELEAGUEUI_H
