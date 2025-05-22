#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <QString>
#include <QDate>
#include <QVector>
#include "player.h"

class Tournament {
public:
    Tournament(const QString& name, const QString& type, const QDate& date, double buyIn, double prizePool, double factor);

    void addPlayer(Player* player);
    QVector<Player*> getPlayers() const;

    QString getName() const;
    QString getType() const;
    QDate getDate() const;

    void updatePlacement(Player* player, int placement);
    void updateOnTime(Player* player, bool onTime);
    void calculatePoints();

    double getBuyIn() const;
    double getPrizePool() const;
    double getFactor() const;

private:
    QString name, type;
    QDate date;
    double buyIn, prizePool, factor;
    QVector<Player*> players;
};

#endif // TOURNAMENT_H
