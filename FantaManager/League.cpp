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

void League::setLeagueTeams(QVector<Team> LeagueTeams){
    this->LeagueTeams = LeagueTeams;
}

int League::getLeagueTeamsNumber(){
    return LeagueTeams.size();
}

int League::getLeagueCredits(){
    return credits;
}

void League::addTeam(QString teamName){
    if (teamName != "")
    {
        Team temp;
        temp.setTeamName(teamName);
        temp.setTeamCredits(this->getLeagueCredits());
        LeagueTeams.append(temp);
    }
}

void League::read(const QJsonObject &json)
{
    if (json.contains("name") && json["name"].isString())
            LeagueName = json["name"].toString();
    if (json.contains("credits") && json["credits"].isDouble())
            credits = json["credits"].toInt();

    if (json.contains("teams") && json["teams"].isArray()) {
        QJsonArray teamArray = json["teams"].toArray();
        LeagueTeams.clear();
        LeagueTeams.reserve(teamArray.size());
        for (int levelIndex = 0; levelIndex < teamArray.size(); ++levelIndex) {
            QJsonObject levelObject = teamArray[levelIndex].toObject();
            Team team;
            team.read(levelObject);
            LeagueTeams.append(team);
        }
    }
}

void League::write(QJsonObject &json) const
{
    json["name"] = LeagueName;
    json["credits"] = credits;
    QJsonArray teamArray;
    for (const Team &team : LeagueTeams) {
        QJsonObject teamObject;
        team.write(teamObject);
        teamArray.append(teamObject);
    }
    json["teams"] = teamArray;
}
