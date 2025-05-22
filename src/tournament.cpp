#include "tournament.h"
#include <cmath>
#include <algorithm>
#include <iostream>

Tournament::Tournament(const std::string& name, const std::string& type, const std::string& date,
                       double buyIn, double prizePool, double factor)
    : name(name), type(type), date(date), buyIn(buyIn), prizePool(prizePool), factor(factor) {}

void Tournament::addPlayer(Player* player) {
    for (const auto& tp : participants) {
        if (tp.player == player) return; // undgå duplikat
    }
    std::cerr << "DEBUG: Tilføjer spiller: " << player->getName() << "\n";
    participants.push_back({player, -1, false});
}

void Tournament::updatePlacement(Player* player, int placement) {
    for (auto& tp : participants) {
        if (tp.player == player) {
            tp.placement = placement;
            return;
        }
    }
}

void Tournament::updateOnTime(Player* player, bool ontime) {
    for (auto& tp : participants) {
        if (tp.player == player) {
            tp.onTime = ontime;
            return;
        }
    }
}

void Tournament::calculatePoints() {
    int N = participants.size();
    std::cerr << "DEBUG: Beregner point for " << N << " deltagere\n";
    if (N == 0) return;

    // Beskyt mod spillere uden placering
    for (const auto& tp : participants) {
        if (!tp.player) {
            std::cerr << "ERROR: Null player i participants\n";
            return;
        }
    }

    std::sort(participants.begin(), participants.end(), [](const TournamentPlayer& a, const TournamentPlayer& b) {
        return a.placement < b.placement;
    });

    for (const auto& tp : participants) {
        if (!tp.player) continue;

        std::cerr << "DEBUG: Beregner point for spiller: " << tp.player->getName()
                  << ", placement: " << tp.placement << ", onTime: " << tp.onTime << "\n";

        if (tp.placement <= 0) {
            std::cerr << "WARNING: Placering <= 0 for spiller: " << tp.player->getName() << "\n";
            continue;
        }

        double basePoints = 0.0;
        if (tp.placement == 1) {
            basePoints = 100.0;
        } else {
            basePoints = 100.0 * std::pow(((double)(N - tp.placement) / (N - 1)), 1.3);
        }

        if (tp.onTime) {
            basePoints += 10.0;
        }

        int finalPoints = static_cast<int>(basePoints * factor);
        std::cerr << "DEBUG: Giver " << finalPoints << " point til " << tp.player->getName() << "\n";
        tp.player->addPoints(finalPoints);
    }
}


std::string Tournament::getName() const {
    return name;
}

std::string Tournament::getType() const {
    return type;
}

std::string Tournament::getDate() const {
    return date;
}

double Tournament::getBuyIn() const {
    return buyIn;
}

double Tournament::getPrizePool() const {
    return prizePool;
}

double Tournament::getFactor() const {
    return factor;
}

const std::vector<TournamentPlayer>& Tournament::getParticipants() const {
    return participants;
}
