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

QVector<Team> League::getLeagueTeams(){
    return LeagueTeams;
}

void League::setLeagueTeamsNumber(int numTeams){
   this->numTeams = numTeams;
}

void League::setLeagueCredits(int credits){
   this->credits = credits;
}

int League::getLeagueTeamsNumber(){
    return LeagueTeams.size();
}

int League::getLeagueCredits(){
    return credits;
}

void League::addTeam(QString teamName){
    numTeams += 1;
    Team temp;
    temp.setTeamName(teamName);
    temp.setTeamCredits(this->getLeagueCredits());
    LeagueTeams.append(temp);
}
