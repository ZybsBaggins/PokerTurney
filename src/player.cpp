#include "player.h"

Player::Player(const QString& name, int chips) : name(name), chips(chips) {}

QString Player::getName() const { return name; }
int Player::getChips() const { return chips; }

void Player::setPlacement(int p) { placement = p; }
int Player::getPlacement() const { return placement; }

void Player::setOnTime(bool on) { onTime = on; }
bool Player::getOnTime() const { return onTime; }

void Player::addPoints(int p) { totalPoints += p; }
int Player::getTotalPoints() const { return totalPoints; }
void Player::setTotalPoints(int points) {
    totalPoints = points;
}




void Player::clearPoints() {
    totalPoints = 0;
}
