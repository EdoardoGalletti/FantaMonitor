#include "Team.h"


// Constructors
Team::Team() {};


// Setter & Getters
void Team::setTeamName(QString TeamName) {
	this->TeamName = TeamName;
	return;
}

void Team::setTeamCredits(int TeamCredits) {
    this->TeamCredits = TeamCredits;
    return;
}

QString Team::getTeamName() {
	return TeamName;
}

int Team::getTeamCredits() {
    return TeamCredits;
}
