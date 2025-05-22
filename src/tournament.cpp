#include "tournament.h"

Tournament::Tournament(const QString& name, const QString& type, const QDate& date, double buyIn, double prizePool, double factor)
    : name(name), type(type), date(date), buyIn(buyIn), prizePool(prizePool), factor(factor) {}

void Tournament::addPlayer(Player* player) {
    for (const auto& tp : participants) {
        if (tp.player == player)
            return; // already added
    }
    participants.append({player, -1, false});
}

QString Tournament::getName() const { return name; }
QString Tournament::getType() const { return type; }
QDate Tournament::getDate() const { return date; }

double Tournament::getBuyIn() const { return buyIn; }
double Tournament::getPrizePool() const { return prizePool; }
double Tournament::getFactor() const { return factor; }

void Tournament::updatePlacement(Player* player, int placement) {
    for (auto& tp : participants) {
        if (tp.player == player) {
            tp.placement = placement;
            return;
        }
    }
}

void Tournament::updateOnTime(Player* player, bool onTime) {
    for (auto& tp : participants) {
        if (tp.player == player) {
            tp.onTime = onTime;
            return;
        }
    }
}

void Tournament::calculatePoints() {
    for (auto& tp : participants) {
        if (tp.placement != -1)
            tp.player->addPoints(100 - tp.placement * 5); // example
    }
}

QVector<Player*> Tournament::getPlayers() const {
    QVector<Player*> result;
    for (const auto& tp : participants) {
        result.append(tp.player);
    }
    return result;
}

QVector<TournamentParticipant> Tournament::getParticipants() const {
    return participants;
}
