#include "Team.h"


// Costruttori
Team::Team() {};

void Team::setTeamName(QString TeamName) {
	this->TeamName = TeamName;
	return;
}

QString Team::getTeamName() {
	return TeamName;
}
