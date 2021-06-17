#pragma once

#include <iostream>
#include "Plant.h"
#include "HealPlant.h"

class HealPlant: public Plant{
    friend std::ostream &operator<<(std::ostream &os, const HealPlant &rhs);
    private:
        int healPoint_;
    public:
        int HealPoint()const{return healPoint_;}
        HealPlant() : healPoint_(20){}
        HealPlant(int price, int hp, int healPoint) : Plant(price, hp, "HealPlant"), healPoint_(healPoint_){}
        ~HealPlant();
};