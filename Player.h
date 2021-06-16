#ifndef PLAYER_H
#define PLAYER_H

#include <random>
#include "Plant.h"

class Player
{
    public:
        Player();
        virtual ~Player();
        bool Planting(const Plant plant);
        void Move(const int offset, const int max);

        int Locate() const;
        int Money() const;

    protected:

    private:
        int money_;
        int loc_;

};

#endif // PLAYER_H
