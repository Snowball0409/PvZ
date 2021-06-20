#include "Plant.h"
#include <iostream>

int Plant::MAX_HP[4]={0,0,0,0};
int Plant::PRICE[4]={0,0,0,0};

Plant::~Plant(){
    
}

void Plant:: Healing(int healPoint){
    hp_ += healPoint;
    if( hp_ > MAX_HP[type_]){
        hp_ = MAX_HP[type_];
    }
}

void Plant:: Injured(int damage){
    hp_-= damage;
    if(hp_ < 0){
        hp_ = 0;
    }
}






