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

bool Player::Planting(const Plant plant)
{
    //plant if money is enough
    if(money_ < plant.Price()) 
        return false;
    money_ -= plant.Price();
    return true;
}

void Player::Move(const int offset, const int max)
{
    //move
    loc_ += offset;
    if(loc_ > max) loc_ %= max;
}

const int Player::Locate()
{
    return loc_;
}

const int Player::Money()
{
    return money_;
}
