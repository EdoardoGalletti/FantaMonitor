#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED
#include <QString>
#include <QJsonObject>
#include <QJsonArray>

class Team
{
private:
    QString TeamName = "";
    int TeamCredits = 1000;

public:
    // Constructors
	Team();

    // Setters & Getters
    void setTeamName(QString);
    void setTeamCredits(int);
    QString getTeamName();
    int getTeamCredits();

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

protected:
};

#endif
