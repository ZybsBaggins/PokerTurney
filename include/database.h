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
                          double buyIn, double prizePool);

    void assignPlayerToTournament(const std::string& tournamentName, const std::string& playerName);
    void updatePlayerPlacement(const std::string& tournamentName, const std::string& playerName, int placement);
    void updatePlayerOnTime(const std::string& tournamentName, const std::string& playerName, bool onTime);

    void calculateAllPoints();

    std::vector<Player>& getPlayers();
    const std::vector<Tournament>& getTournaments() const;

    Player* findPlayer(const std::string& name);
    Tournament* findTournament(const std::string& name);

    void saveToFile(const std::string& filename) const;       // Gem turneringer inkl. deltagere
    void loadFromFile(const std::string& filename);           // Indlæs turneringer inkl. deltagere

    void savePlayersToFile(const std::string& filename) const; // Gem globale spillerdata
    void loadPlayersFromFile(const std::string& filename);     // Indlæs globale spillerdata

private:
    std::vector<Player> players;
    std::vector<Tournament> tournaments;
};

#endif // DATABASE_H
