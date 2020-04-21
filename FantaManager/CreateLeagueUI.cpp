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
    /*****************************************************/
    /************** LEAGUE CREATION WINDOW ***************/
    /*****************************************************/
    this->setGeometry(0, 0, 320, 200);
    MainWindow::AlignToCenter(this);
    // Set Main Window title
    this->setWindowTitle("Create a new League");

    /*****************************************************/
    /**************** QWIDGETS CREATION ******************/
    /*****************************************************/
    leagueNameLE = new QLineEdit();
    nOfTeamsLE = new QLineEdit();
    creditsLE = new QSpinBox();
    creditsLE->setRange(0, 10000);
    creditsLE->setValue(1000);

    /*****************************************************/
    /**************** QWIDGETS LAYOUT ********************/
    /*****************************************************/

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(tr("&League Name:"), leagueNameLE);
    formLayout->addRow(tr("&Number of Teams:"), nOfTeamsLE);
    formLayout->addRow(tr("&Credits:"), creditsLE);

    setLayout(formLayout);


    /*****************************************************/
    /**************** qApp STYLESHEET ********************/
    /*****************************************************/

    this->setStyleSheet(QString("QDialog   {background-color: black;}"
                                "QLineEdit {border: 2px solid gray; border-radius: 10px; padding: 0 8px; background: yellow; selection-background-color: darkgray;}"
                                "QSpinBox  {padding-right: 15px; border: 2px solid gray; border-radius: 2px; border-width: 3; background: yellow}"));

}
