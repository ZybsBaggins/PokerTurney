#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <QString>
#include <QDate>
#include <QVector>
#include <map>
#include "player.h"

struct TournamentParticipant {
    Player* player;
    int placement = -1;
    bool onTime = false;
};

class Tournament {
public:
    Tournament(const QString& name, const QString& type, const QDate& date, double buyIn, double prizePool);

    void addPlayer(Player* player);
    QVector<Player*> getPlayers() const;
    QVector<TournamentParticipant> getParticipants() const;

    QString getName() const;
    QString getType() const;
    QDate getDate() const;

    void updatePlacement(Player* player, int placement);
    void updateOnTime(Player* player, bool onTime);
    std::map<Player*, int> calculatePoints() const;

    void setParticipants(const QVector<TournamentParticipant>& list);


    double getBuyIn() const;
    double getPrizePool() const;

private:
    QString name, type;
    QDate date;
    double buyIn, prizePool;
    QVector<TournamentParticipant> participants;
    bool pointsCalculated = false;
};

#endif // TOURNAMENT_H
