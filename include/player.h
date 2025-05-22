#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(const std::string& name);

    std::string getName() const;
    int getTotalPoints() const;
    void addPoints(int points);
    void resetPoints();

private:
    std::string name;
    int totalPoints;
};

#endif // PLAYER_H
