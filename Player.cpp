#include "Player.h"

Player::Player()
{
    money_ = 150;
    loc_ = 0;
}

Player::~Player()
{
    //dtor
}

bool Player::Plant(const Plant plant)
{
    //plant if money is enough
    if(money_ < plant.Price()) 
        return false;
    money_ -= plant.Price();
    return true;
}

void Player::Move(const int loc)
{
    //move
    loc_ = loc;
}
