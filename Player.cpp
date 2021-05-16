#include "LinkedList.h"
#include "Player.h"
#include <string>

Player::Player(string name, int Score, LinkedList *TilesInHand)
{
    this->name = name;
    this->Score = Score;
    this->TilesInHand = TilesInHand;
}

int Player::getScore()
{
    return Score;
}

LinkedList *Player::getTilesInHand()
{
    return TilesInHand;
}

string Player::getName()
{
    return name;
}
void Player::setScore(int Score)
{
    this->Score = Score;
}

void Player::setTilesInHand(LinkedList *TilesInHand)
{
    this->TilesInHand = TilesInHand;
}

void Player::setName(string name)
{
    this->name = name;
}