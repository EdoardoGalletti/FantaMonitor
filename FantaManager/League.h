#ifndef LEAGUE_H
#define LEAGUE_H

#include <QString>
#include <QVector>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextStream>
#include <QFile>
#include "Team.h"

class League
{
private:
    QString LeagueName = "";
    QVector<Team> LeagueTeams;
    int numTeams = 0, credits;

public:
    enum SaveFormat {
            Json, Binary
        };
    // Constructor
    League();
    void setLeagueName(QString);
    void setLeagueTeamsNumber(int);
    void setLeagueCredits(int);
    void addTeam(QString);
    QString getLeagueName();
    int getLeagueTeamsNumber();
    int getLeagueCredits();
    QVector<Team> getLeagueTeams();
    void setLeagueTeams(QVector<Team>);
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
protected:
};

#endif // LEAGUE_H
