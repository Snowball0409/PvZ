#ifndef PLAYER_H
#define PLAYER_H

#include <random>
//#include "Plant.h"

class Player
{
    public:
        Player();
        virtual ~Player();
        bool Planting(const Plant plant);
        void Move(const int loc);

    protected:

    private:
        int money_;
        int loc_;

};

#endif // PLAYER_H
