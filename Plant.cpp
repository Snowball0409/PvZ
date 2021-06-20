#include "Plant.h"
#include <iostream>

enum plantName{
    HEAL_PLANT,
    COIN_PLANT,
    BOMB_PLANT,
    HORN_PLANT,
    EMPTY
};

Plant::~Plant(){
    
}

Plant::Plant(int price, int hp, enum plantName name){
    price_ = price;
    hp_ = hp;
    name_ = name;
}

void Plant:: Healing(int healPoint){
    hp_ += healPoint;
    if( hp_ > MAX_HP[name_]){
        hp_ = MAX_HP[name_];
    }
}

void Plant:: Injured(int damage){
    hp_-= damage;
    if(hp_ < 0){
        hp_ = 0;
    }
}






