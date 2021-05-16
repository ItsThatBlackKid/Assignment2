#include "Player.h"


Player::Player(){
    
}
Player::Player(string name, LinkedList *tilesInHand)
{
    this->name = name;
    this->score = 0;
    this->hand = tilesInHand;
}

int Player::getScore()
{
    return score;
}

LinkedList *Player::getHand()
{
    return hand;
}

string Player::getName()
{
    return name;
}
void Player::setScore(int score)
{
    this->score = score;
}

void Player::setTilesInHand(TileBag *hand)
{
    for(int i=0;i<6;i++){
    this->hand->addFront(hand->get(i));
    }
}

void Player::setName(string name)
{
    this->name = name;
}

ofstream& operator << (ofstream& of, const Player& p) {
    of << p.name << endl;
    of << p.score << endl;
    of << p.hand;
    return of;
}