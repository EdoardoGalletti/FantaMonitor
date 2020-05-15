#include "CreateLeagueUI.h"

CreateLeagueUI::CreateLeagueUI(QWidget *parent) :
    QDialog(parent)
{
    l = new League();
    setup();
}

CreateLeagueUI::~CreateLeagueUI()
{
    delete l;
}

void CreateLeagueUI::setup(){
    /*****************************************************/
    /************** LEAGUE CREATION WINDOW ***************/
    /*****************************************************/
    this->setGeometry(0, 0, 320, 200);
    AlignToCenter(this);
    // Set Main Window title
    this->setWindowTitle("Create a new League");

    /*****************************************************/
    /**************** QWIDGETS CREATION ******************/
    /*****************************************************/
    leagueNameLE = new QLineEdit("My League");
    nOfTeamsSB = new QSpinBox();
    nOfTeamsSB->setRange(2, 100);
    nOfTeamsSB->setValue(8);
    creditsSB = new QSpinBox();
    creditsSB->setRange(0, 10000);
    creditsSB->setValue(1000);

    /*****************************************************/
    /**************** QWIDGETS LAYOUT ********************/
    /*****************************************************/

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(tr("&League Name:"), leagueNameLE);
    formLayout->addRow(tr("&Number of Teams:"), nOfTeamsSB);
    formLayout->addRow(tr("&Credits:"), creditsSB);

    setLayout(formLayout);


    /*****************************************************/
    /**************** this STYLESHEET ********************/
    /*****************************************************/

    this->setStyleSheet(QString("QDialog     {background-color: #000000;}"
                                "QLineEdit   {border: 2px solid gray; border-radius: 10px; padding: 0 8px; background: yellow; selection-background-color: darkgray;}"
                                "QSpinBox    {padding-right: 15px; border: 2px solid gray; border-radius: 2px; border-width: 3; background: yellow}"));

}

void CreateLeagueUI::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QPushButton         {color: #ffffff; background-color: #000000; border: 2px solid #808080; padding: 10px; font: 12px}"
                         "QPushButton:hover   {color: #ffffff; background-color: #000000; border: 2px solid #eeeeee; padding: 10px; font: 12px}"
                         "QPushButton:pressed {color: #ffffff; background-color: #000000; border: 2px solid #808080; padding: 10px; font: 12px}");

    msgBox.setText("Your league is going to be created.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Yes:
          l->setLeagueName(this->leagueNameLE->text());
          l->setLeagueTeamsNumber(this->nOfTeamsSB->value());
          l->setLeagueCredits(this->creditsSB->value());
          event->accept();
          break;
      case QMessageBox::No:
          event->accept();
          break;
      case QMessageBox::Cancel:
          event->ignore();
          break;
      default:
          // should never be reached
          break;
    }
}

void CreateLeagueUI::setCredits(int credits){
    this->credits = credits;
    return;
}

int CreateLeagueUI::getCredits(){
    return this->credits;
}

void CreateLeagueUI::setnOfTeams(int nOfTeams){
    this->nOfTeams = nOfTeams;
    return;
}

int CreateLeagueUI::getnOfTeams(){
    return this->nOfTeams;
}

League CreateLeagueUI::getLeague(){
    return *l;
}

