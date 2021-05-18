#include "Player.h"

Player::Player()
{
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

void Player::getTile(TileBag *bag) {
    hand->addBack(bag->get(0));
}
void Player::setTilesInHand(TileBag *bag)
{

    for (int i = 0; i < 6; i++)
    {
        this->hand->addBack(bag->getFront());
        bag->removeFront();
    }
}

int Player::playTile(GameBoard *board, string loc, string tile)
{
    int played = -1;

    Tile *toPlay = hand->getTile(tile);
    hand->removeFront();

    std::cout << "error happens in board" << std::endl;

    if (toPlay == nullptr)
    {
        played = -1;
    }
    else
    {
        played = board->TileInsert(loc.c_str(), toPlay);
    }

    return played;
}

bool Player::replaceTile(TileBag *bag, string tile)
{
    bool replaced = false;
    Node *n = nullptr;
    Tile *toReplace = nullptr;
    int pos = 0;

    for (int i = 0; i < hand->getSize(); i++)
    {
        n = hand->get(i);

        Tile *t = n->tile;
        if (t->colour == tile[0] && t->shape == tile[1])
        {
            toReplace = t;
            pos = i;
            replaced = true;
        }
    }

    if (replaced)
    {
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

ofstream &operator<<(ofstream &of, const Player &p)
{
    of << p.name << endl;
    of << p.score << endl;
    of << p.hand;
    return of;
}

ifstream &operator>>(ifstream &in, Player *player)
{
    getline(in, player->name);
    in >> player->score;
    in.ignore();
    in >> player->hand;
    return in;
}