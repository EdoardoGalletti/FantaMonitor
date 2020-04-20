#ifndef CREATELEAGUEUI_H
#define CREATELEAGUEUI_H

#include <QDialog>

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
    Ui::CreateLeagueUI *ui;
};

#endif // CREATELEAGUEUI_H
