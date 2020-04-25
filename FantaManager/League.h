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
    int numTeams = 0, credits;

public:
    // Constructor
    League();
    void setLeagueName(QString);
    void setLeagueTeamsNumber(int);
    void setLeagueCredits(int);
    void addTeam(QString);
    QString getLeagueName();
    int getLeagueTeamsNumber();
    int getLeagueCredits();
    std::vector<Team> getLeagueTeams();
protected:
};

#endif // LEAGUE_H
