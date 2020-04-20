#include "CreateLeagueUI.h"
#include "mainwindow.h"

CreateLeagueUI::CreateLeagueUI(QWidget *parent) :
    QDialog(parent)
{
    setup();
}

CreateLeagueUI::~CreateLeagueUI()
{
}

void CreateLeagueUI::setup(){
    this->setGeometry(0, 0, 100, 100);
    MainWindow::AlignToCenter(this);

    // Set Main Window title
    this->setWindowTitle("Create a new League");
}
