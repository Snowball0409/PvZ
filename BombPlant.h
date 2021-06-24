#ifndef BOMBPLANT_H
#define BOMBPLANT_H

#include <iostream>
#include "Plant.h"

class BombPlant: public Plant{
    private:
        int damage_;
    public:
        virtual int Damage()const override{return damage_;}
        BombPlant() : damage_(50){}
        BombPlant(int price, int hp, int damage) : Plant(price, hp, BOMB_PLANT, plantName[BOMB_PLANT]), damage_(damage){}
        BombPlant(int price, int hp, int damage, std::string name) : Plant(price, hp, BOMB_PLANT, name), damage_(damage){}
        ~BombPlant();
        void Show() override;
};

#endif