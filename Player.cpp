#include "Player.h"

Player::Player(int landN):money_(150)
{
    //random init locate
    loc_ = rand()%landN;
}

Player::Player(int money, int loc):money_(money),loc_(loc){}

Player::~Player()
{

}

bool Player::Planting(const Plant &plant)
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
    if(loc_ >= max) loc_ %= max;
}

void Player::Reward(const int &money)
{
    money_ += money;
}

int Player::Locate() const
{
    return loc_;
}

int Player::Money() const
{
    return money_;
}
