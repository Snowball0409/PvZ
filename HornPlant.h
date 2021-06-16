#pragma once

#include <iostream>
#include "Plant.h"
#include "HornPlant.h"

class HornPlant: public Plant{
    friend std::ostream &operator<<(std::ostream &os, const HornPlant &rhs);
    private:
        int damage_ = 10;
    public:
        int Damage()const{return damage_;}
        HornPlant();
        HornPlant(int price, int hp, int damage) : Plant(price, hp), damage_(damage){}
        ~HornPlant();
};


