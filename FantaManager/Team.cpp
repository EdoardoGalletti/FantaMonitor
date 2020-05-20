#include "Team.h"


// Constructors
Team::Team() {
};


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

void Team::read(const QJsonObject &json)
{
    if (json.contains("name") && json["name"].isString())
        TeamName = json["name"].toString();

//    if (json.contains("npcs") && json["npcs"].isArray()) {
//        QJsonArray npcArray = json["npcs"].toArray();
//        mNpcs.clear();
//        mNpcs.reserve(npcArray.size());
//        for (int npcIndex = 0; npcIndex < npcArray.size(); ++npcIndex) {
//            QJsonObject npcObject = npcArray[npcIndex].toObject();
//            Character npc;
//            npc.read(npcObject);
//            mNpcs.append(npc);
//        }
//    }
}

void Team::write(QJsonObject &json) const
{
    json["name"] = TeamName;
//    QJsonArray npcArray;
//    for (const Character &npc : mNpcs) {
//        QJsonObject npcObject;
//        npc.write(npcObject);
//        npcArray.append(npcObject);
//    }
//    json["npcs"] = npcArray;
}
