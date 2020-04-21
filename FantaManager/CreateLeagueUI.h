#ifndef CREATELEAGUEUI_H
#define CREATELEAGUEUI_H

#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>

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

private:
    //Ui::CreateLeagueUI *ui;
    QLineEdit* leagueNameLE; // LE stands for Line Edit
    QLineEdit* nOfTeamsLE;
    QSpinBox* creditsLE;
};

#endif // CREATELEAGUEUI_H
