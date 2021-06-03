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

bool Player::Plant(const Land land)
{
    //plant if money is enough
    if(money_ < land.Plant(loc_).Price()) 
        return false;
    money_ -= land.Plant(loc_).Price();
    return true;
}

void Player::Move(const int loc)
{
    //move
    loc_ = loc;
}
