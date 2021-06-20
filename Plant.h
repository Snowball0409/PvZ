#pragma once

#include <iostream>
#include <string>

constexpr int PLANT_NUMBER = 4;

enum plantName{
    HEAL_PLANT,
    COIN_PLANT,
    BOMB_PLANT,
    HORN_PLANT,
    EMPTY
};

class Plant{
    private:
        int price_;
        int hp_;
        enum plantName name_ = EMPTY;
    public:
        int Price()const{return price_;}
        int Hp()const{return hp_;}
        Plant() : price_(0), hp_(0){}
        ~Plant();
        Plant(int price, int hp, enum plantName name);
        void Healing(int healPoint);
        void Injured(int damage);
        static int PRICE[PLANT_NUMBER];
        static int MAX_HP[PLANT_NUMBER];
      
};

