
#pragma once

#include <iostream>
#include "Plant.h"

class BombPlant: public Plant{
    private:
        int damage_ = 50;
    public:
        int Damage()const{return damage_;}
        BombPlant();
        BombPlant(int price, int hp, int damage) : Plant(price, hp), damage_(damage){}
        ~BombPlant();

};