#include "Plant.h"
#include <iostream>

Plant::Plant(){

}

Plant::~Plant(){
    
}

void Plant::Setup(int price, int hp){
    price_ = price;
    hp_ = hp;
}

BombPlant::BombPlant(){
    damage_ = 50;
    Setup(100, 50);
}

BombPlant::~BombPlant(){

}

CoinPlant::CoinPlant(){
    visit_ = 2;
    reward_ = 100;
    Setup(50, 75);
}

CoinPlant::~CoinPlant(){

}

HornPlant::HornPlant(){
    damage_ = 10;
    Setup(50, 50);
}

HornPlant::~HornPlant(){

}

HealPlant::HealPlant(){
    healPoint_ = 20;
    Setup(50, 50);
}

HealPlant::~HealPlant(){

}