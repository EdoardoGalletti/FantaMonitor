#include "League.h"

League::League()
{
}

void League::setLeagueName(QString LeagueName) {
    this->LeagueName = LeagueName;
    return;
}

QString League::getLeagueName() {
    return LeagueName;
}

std::vector<Team> League::getLeagueTeams(){
    return LeagueTeams;
}

void League::setLeagueTeamsNumber(int numTeams){
   this->numTeams = numTeams;
}
int League::getLeagueTeamsNumber(){
    return numTeams;
}

void League::addTeam(QString teamName){
    numTeams += 1;
    LeagueTeams.resize(numTeams);
    LeagueTeams[numTeams - 1].setTeamName(teamName);
    LeagueTeams[numTeams - 1].setTeamCredits(1000);
}
