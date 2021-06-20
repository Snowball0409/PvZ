#ifndef HORNPLANT_H
#define HORNPLANT_H

#include <iostream>
#include "Plant.h"
#include "HornPlant.h"

class HornPlant: public Plant{
    friend std::ostream &operator<<(std::ostream &os, const HornPlant &rhs);
    private:
        int damage_;                                          
    public:
        int Damage()const{return damage_;}
        HornPlant() : damage_(10){}
        HornPlant(int price, int hp, int damage) : Plant(price, hp, HORN_PLANT, plantName[HORN_PLANT]), damage_(damage){}
        HornPlant(int price, int hp, int damage, std::string name) : Plant(price, hp, HORN_PLANT, name), damage_(damage){}
        ~HornPlant();
};

#endif
