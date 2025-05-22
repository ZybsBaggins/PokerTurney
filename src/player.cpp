#include "player.h"

Player::Player(const std::string& name) : name(name), totalPoints(0) {
    // Constructor implementation
}

std::string Player::getName() const {
    return name;
}

int Player::getTotalPoints() const {
    return totalPoints;
}

void Player::addPoints(int points) {
    totalPoints += points;
}
