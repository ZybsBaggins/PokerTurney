#include "database.h"
#include "player.h"
#include "tournament.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Database::addPlayer(const std::string& name) {
    if (!findPlayer(name))
        players.emplace_back(name);
}

void Database::createTournament(const std::string& name, const std::string& type, const std::string& date,
                                double buyIn, double prizePool, double factor) {
    tournaments.emplace_back(name, type, date, buyIn, prizePool, factor);
}

void Database::assignPlayerToTournament(const std::string& tournamentName, const std::string& playerName) {
    Player* player = findPlayer(playerName);
    Tournament* tournament = findTournament(tournamentName);

    if (player && tournament) {
        std::cerr << "DEBUG: Tilføjer " << player->getName() << " til " << tournament->getName() << "\n";
        tournament->addPlayer(player);
    } else {
        std::cerr << "ERROR: Mangler ";
        if (!player) std::cerr << "spiller '" << playerName << "'";
        if (!player && !tournament) std::cerr << " og ";
        if (!tournament) std::cerr << "turnering '" << tournamentName << "'";
        std::cerr << "\n";
    }
}

void Database::updatePlayerPlacement(const std::string& tournamentName, const std::string& playerName, int placement) {
    Player* player = findPlayer(playerName);
    Tournament* tournament = findTournament(tournamentName);
    if (player && tournament) {
        tournament->updatePlacement(player, placement);
    }
}

void Database::updatePlayerOnTime(const std::string& tournamentName, const std::string& playerName, bool onTime) {
    Player* player = findPlayer(playerName);
    Tournament* tournament = findTournament(tournamentName);
    if (player && tournament) {
        tournament->updateOnTime(player, onTime);
    }
}

void Database::calculateAllPoints() {
    for (auto& t : tournaments) {
        t.calculatePoints();
    }
}

Player* Database::findPlayer(const std::string& name) {
    for (auto& p : players) {
        if (p.getName() == name)
            return &p;
    }
    return nullptr;
}

Tournament* Database::findTournament(const std::string& name) {
    for (auto& t : tournaments) {
        if (t.getName() == name)
            return &t;
    }
    return nullptr;
}

const std::vector<Player>& Database::getPlayers() const {
    return players;
}

const std::vector<Tournament>& Database::getTournaments() const {
    return tournaments;
}

void Database::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    for (const auto& t : tournaments) {
        for (const auto& tp : t.getParticipants()) {
            out << t.getName() << ',' << t.getType() << ',' << t.getDate() << ','
                << t.getBuyIn() << ',' << t.getPrizePool() << ',' << t.getFactor() << ','
                << tp.player->getName() << ',' << tp.placement << ',' << tp.onTime << '\n';
        }
    }
}

void Database::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string name, type, date, playerName;
        double buyIn, prizePool, factor;
        int placement;
        bool onTime;

        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, date, ',');
        ss >> buyIn; ss.ignore();
        ss >> prizePool; ss.ignore();
        ss >> factor; ss.ignore();
        std::getline(ss, playerName, ',');
        ss >> placement; ss.ignore();
        ss >> onTime;

        addPlayer(playerName);
        if (!findTournament(name))
            createTournament(name, type, date, buyIn, prizePool, factor);

        Tournament* t = findTournament(name);
        Player* p = findPlayer(playerName);
        if (t && p) {
            t->addPlayer(p);
            t->updatePlacement(p, placement);
            t->updateOnTime(p, onTime);
        }
    }
}

void Database::savePlayersToFile(const std::string& filename) const {
    std::ofstream out(filename);
    for (const auto& p : players) {
        out << p.getName() << "," << p.getTotalPoints() << "\n";
    }
}

void Database::loadPlayersFromFile(const std::string& filename) {
    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string name;
        int points;

        std::getline(ss, name, ',');
        ss >> points;

        if (!findPlayer(name)) {
            players.emplace_back(name);
            players.back().addPoints(points);
        }
    }
}
