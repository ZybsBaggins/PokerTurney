#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player {
    public:
        Player(const QString& name, int chips);
    
        QString getName() const;
        int getChips() const;
    
        void setPlacement(int p);
        int getPlacement() const;
    
        void setOnTime(bool onTime);
        bool getOnTime() const;
    
        void addPoints(int p);
        int getTotalPoints() const;
    
    private:
        QString name;
        int chips;
        int placement = -1;
        bool onTime = false;
        int totalPoints = 0;
    };
    

#endif // PLAYER_H
