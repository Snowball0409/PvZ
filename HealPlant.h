#ifndef HEALPLANT_H
#define HEALPLANT_H

#include <iostream>
#include "Plant.h"
#include "HealPlant.h"

class HealPlant: public Plant{
    private:
        int healPoint_;
    public:
        virtual int HealPoint()const{return healPoint_;}
        HealPlant() : healPoint_(20){}
        HealPlant(int price, int hp, int healPoint) : Plant(price, hp, HEAL_PLANT, plantName[HEAL_PLANT]), healPoint_(healPoint){}
        HealPlant(int price, int hp, int healPoint, std::string name) : Plant(price, hp, HEAL_PLANT, name), healPoint_(healPoint){}
        ~HealPlant();
        void Show();
};


#endif