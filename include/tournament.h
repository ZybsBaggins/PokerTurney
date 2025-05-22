#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <string>
#include <vector>
#include "player.h"

struct TournamentPlayer {
    Player* player;
    int placement = -1;
    bool onTime = false;
};

class Tournament {
public:
    Tournament(const std::string& name, const std::string& type, const std::string& date,
               double buyIn, double prizePool, double factor);

    void addPlayer(Player* player);
    void updatePlacement(Player* player, int placement);
    void updateOnTime(Player* player, bool ontime);
    void calculatePoints();

    std::string getName() const;
    std::string getType() const;
    std::string getDate() const;
    double getBuyIn() const;
    double getPrizePool() const;
    double getFactor() const;
    const std::vector<TournamentPlayer>& getParticipants() const;

private:
    std::string name, type, date;
    double buyIn, prizePool, factor;
    std::vector<TournamentPlayer> participants;
};

#endif // TOURNAMENT_H
