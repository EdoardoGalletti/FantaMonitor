#ifndef LEAGUE_H
#define LEAGUE_H
#include <QString>

class League
{
private:
    QString LeagueName = "";

public:
    // Constructor
    League();
    void setLeagueName(QString);
    QString getLeagueName();
protected:
};

#endif // LEAGUE_H
