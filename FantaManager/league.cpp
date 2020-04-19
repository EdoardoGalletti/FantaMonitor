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
