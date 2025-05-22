#include "tournament.h"

Tournament::Tournament(const QString& name, const QString& type, const QDate& date, double buyIn, double prizePool, double factor)
    : name(name), type(type), date(date), buyIn(buyIn), prizePool(prizePool), factor(factor) {}

void Tournament::addPlayer(Player* player) {
    players.append(player);
}

QString Tournament::getName() const { return name; }
QString Tournament::getType() const { return type; }
QDate Tournament::getDate() const { return date; }

void Tournament::updatePlacement(Player* player, int placement) {
    player->setPlacement(placement);
}

void Tournament::updateOnTime(Player* player, bool onTime) {
    player->setOnTime(onTime);
}

void Tournament::calculatePoints() {
    for (Player* p : players) {
        if (p->getPlacement() != -1)
            p->addPoints(100 - p->getPlacement() * 5); // eksempel
    }
}

double Tournament::getBuyIn() const { return buyIn; }
double Tournament::getPrizePool() const { return prizePool; }
double Tournament::getFactor() const { return factor; }

QVector<Player*> Tournament::getPlayers() const {
    return players;
}
