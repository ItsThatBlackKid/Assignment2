#include "Player.h"


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

void Player::setTilesInHand(LinkedList *hand)
{
    this->hand = hand;
}

void Player::setName(string name)
{
    this->name = name;
}

ofstream& operator << (ofstream& of, const Player& p) {
    of << pname << endl;
    of << p.score << endl;
    of << p.hand;
}

ifstream& operator >> (ifstream& in, Player* player) {
    in >> player->name;
    in >> player->score;
    in >> p->hand;
    return in;
}