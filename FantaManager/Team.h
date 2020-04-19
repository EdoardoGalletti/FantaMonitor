#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED
#include <QString>

class Team
{
private:
    QString TeamName = "";

public:
	Team();
    void setTeamName(QString);
    QString getTeamName();
protected:
};

#endif
