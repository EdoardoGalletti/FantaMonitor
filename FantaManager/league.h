#ifndef LEAGUE_H
#define LEAGUE_H

#include <QString>
#include <vector>
#include "Team.h"

class League
{
private:
    QString LeagueName = "";
    std::vector<Team> LeagueTeams;
    int numTeams = 0;

public:
    // Constructor
    League();
    void setLeagueName(QString);
    void setLeagueTeamsNumber(int);
    void addTeam(QString);
    QString getLeagueName();
    int getLeagueTeamsNumber();
    std::vector<Team> getLeagueTeams();
protected:
};

#endif // LEAGUE_H
