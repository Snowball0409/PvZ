#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include "Plant.h"

class Player
{
    public:
        Player(int landN);
        Player(int money, int loc);
        virtual ~Player();
        bool Planting(const Plant &plant);
        void Move(const int offset, const int max);
        void Reward(const int &money);

        int Locate() const;
        int Money() const;

    protected:

    private:
        int money_;
        int loc_;
};

#endif // PLAYER_H
