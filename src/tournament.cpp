#include "tournament.h"

Tournament::Tournament(const QString& name, const QString& type, const QDate& date, double buyIn, double prizePool)
    : name(name), type(type), date(date), buyIn(buyIn), prizePool(prizePool) {}

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

std::map<Player*, int> Tournament::calculatePoints() const {
    std::map<Player*, int> results;
    int totalPlayers = participants.size();
    if (totalPlayers == 0) return results;
    double sqrtPrize = std::sqrt(prizePool);

    for (const auto& tp : participants) {
        double placementPoints = 0;
        if (tp.placement != -1) {
            placementPoints = ((double)(totalPlayers - tp.placement + 1) / totalPlayers) * sqrtPrize * 10;
        }

        int bonus = 0;
        if (tp.onTime) bonus += 10;
        // Tilføj evt. early-signup logik her

        int total = static_cast<int>(placementPoints + bonus);
        results[tp.player] = total;
    }

    return results;
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

void Tournament::setParticipants(const QVector<TournamentParticipant>& list) {
    participants = list;
}
