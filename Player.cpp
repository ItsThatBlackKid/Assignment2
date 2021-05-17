#include "Player.h"


Player::Player(){
    hand = new LinkedList();
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

LinkedList* Player::getHand()
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

void Player::setTilesInHand(TileBag *bag)
{

    for(int i=0; i<6; i++){
        this->hand->addBack(bag->get(i));
    }

    
}

bool Player::playTile(GameBoard* board, string loc, string tile) {
    bool played;
    
    Node* n = nullptr;
    Tile* toPlay = nullptr;

    for(int i = 0; i < hand->getSize(); i++) {
        n = hand->get(i);

        Tile* t = n->tile;
        if(t->colour == tile[0] && t->shape == tile[1]) {
            toPlay = t;
            played = true;
        }
    }


    board->TileInsert(loc.c_str(), toPlay);
    return played;
}

bool Player::replaceTile(TileBag* bag, string tile) {
    bool replaced = false;
    Node* n = nullptr;
    Tile* toReplace = nullptr;
    int pos = 0;

    for(int i = 0; i < hand->getSize(); i++) {
        n = hand->get(i);

        Tile* t = n->tile;
        if(t->colour == tile[0] && t->shape ==  tile[1]) {
            toReplace = t;
            pos = i;
            replaced = true;
        }
    }

    if(replaced) {
        bag->add(toReplace);
        hand->remove(pos);
        hand->addBack(bag->get(0));
    }

    return replaced;
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

ifstream& operator >> (ifstream& in, Player* player) {
    in >> player->name;
    in >> player->score;
    in >> player->hand;
    return in;
}