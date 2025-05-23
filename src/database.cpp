#include "database.h"
#include "player.h"
#include "tournament.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Database::addPlayer(const std::string& name) {
    addPlayer(name, 0); // standard chips = 0
}

void Database::addPlayer(const std::string& name, int chips) {
    if (!findPlayer(name))
        players.emplace_back(QString::fromStdString(name), chips);
}
void Database::createTournament(const std::string& name, const std::string& type, const std::string& date,
                                double buyIn, double prizePool) {
    tournaments.emplace_back(
        QString::fromStdString(name),
        QString::fromStdString(type),
        QDate::fromString(QString::fromStdString(date), "yyyy-MM-dd"),
        buyIn, prizePool
    );
}

void Database::assignPlayerToTournament(const std::string& tournamentName, const std::string& playerName) {
    Player* player = findPlayer(playerName);
    Tournament* tournament = findTournament(tournamentName);

    if (player && tournament) {
        std::cerr << "DEBUG: Tilføjer " << player->getName().toStdString()
                  << " til " << tournament->getName().toStdString() << "\n";
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
    for (auto& player : players) {
        player.setTotalPoints(0);
    }

    for (auto& tournament : tournaments) {
        auto results = tournament.calculatePoints();
        for (const auto& [player, points] : results) {
            player->addPoints(points);
        }
    }
}


Player* Database::findPlayer(const std::string& name) {
    for (auto& p : players) {
        if (p.getName().toStdString() == name)
            return &p;
    }
    return nullptr;
}

Tournament* Database::findTournament(const std::string& name) {
    for (auto& t : tournaments) {
        if (t.getName().toStdString() == name)
            return &t;
    }
    return nullptr;
}

std::vector<Player>& Database::getPlayers() {
    return players;
}

const std::vector<Tournament>& Database::getTournaments() const {
    return tournaments;
}


void Database::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    for (const auto& t : tournaments) {
        for (const auto& tp : t.getParticipants()) {
            out << t.getName().toStdString() << ','
                << t.getType().toStdString() << ','
                << t.getDate().toString("yyyy-MM-dd").toStdString() << ','
                << t.getBuyIn() << ',' << t.getPrizePool() << ',' 
                << tp.player->getName().toStdString() << ','  // spiller
                << tp.placement << ','                        // placering
                << (tp.onTime ? 1 : 0) << '\n';               // onTime
        }
    }
}

void Database::loadFromFile(const std::string& filename) {
    tournaments.clear();

    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string name, type, dateStr, playerName;
        double buyIn, prizePool;
        int placement;
        int onTime;

        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, dateStr, ',');
        ss >> buyIn; ss.ignore();
        ss >> prizePool; ss.ignore();
        //ss >> factor; ss.ignore();
        std::getline(ss, playerName, ',');
        ss >> placement; ss.ignore();
        ss >> onTime;

        QDate date = QDate::fromString(QString::fromStdString(dateStr), "yyyy-MM-dd");

        if (!findTournament(name)) {
            tournaments.emplace_back(
                QString::fromStdString(name),
                QString::fromStdString(type),
                date,
                buyIn, prizePool
            );
        }

        Tournament* t = findTournament(name);
        addPlayer(playerName);
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
        out << p.getName().toStdString() << ',' << p.getTotalPoints() << '\n';
    }
}


void Database::loadPlayersFromFile(const std::string& filename) {
    players.clear();
    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string name;
        int points;

        std::getline(ss, name, ',');
        ss >> points;

        players.emplace_back(QString::fromStdString(name), 0);
        players.back().addPoints(points);
    }
}
