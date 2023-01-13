#include "Player.h"

Player::Player(){
    points = 0;
}

int Player::getPoints() const{
    return points;
}

void Player::increasePoints(){
    points++;
}