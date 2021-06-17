
#pragma once

#include <iostream>
#include "Plant.h"

class BombPlant: public Plant{
    friend std::ostream &operator<<(std::ostream &os, const BombPlant &rhs);
    private:
        int damage_;
    public:
        int Damage()const{return damage_;}
        BombPlant() : damage_(50){}
        BombPlant(int price, int hp, int damage) : Plant(price, hp, "BombPlant"), damage_(damage){}
        ~BombPlant();

};