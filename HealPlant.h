#pragma once

#include <iostream>
#include "Plant.h"
#include "HealPlant.h"

class HealPlant: public Plant{
    private:
        int healPoint_ = 20;
    public:
        int HealPoint()const{return healPoint_;}
        HealPlant();
        HealPlant(int price, int hp, int healPoint) : Plant(price, hp), healPoint_(healPoint_){}
        ~HealPlant();
};