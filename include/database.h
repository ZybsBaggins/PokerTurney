#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include "player.h"
#include "tournament.h"

class Database {
public:
    void addPlayer(const std::string& name);
    void addPlayer(const std::string& name, int chips);
    void createTournament(const std::string& name, const std::string& type, const std::string& date,
                          double buyIn, double prizePool, double factor);
    void assignPlayerToTournament(const std::string& tournamentName, const std::string& playerName);
    void updatePlayerPlacement(const std::string& tournamentName, const std::string& playerName, int placement);
    void updatePlayerOnTime(const std::string& tournamentName, const std::string& playerName, bool onTime);

    void calculateAllPoints();

    const std::vector<Player>& getPlayers() const;
    const std::vector<Tournament>& getTournaments() const;

    Player* findPlayer(const std::string& name);
    Tournament* findTournament(const std::string& name);

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    void savePlayersToFile(const std::string& filename) const;
    void loadPlayersFromFile(const std::string& filename);

private:
    std::vector<Player> players;
    std::vector<Tournament> tournaments;
};

#endif // DATABASE_H
