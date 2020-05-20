#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    bool json = true;
    w.loadSession(json ? MainWindow::Json : MainWindow::Binary);
    w.refreshMainWindow();
    w.show();
    return a.exec();
}
