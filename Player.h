
#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "Tile.h"
#include "LinkedList.h"
#include <string>
using namespace std;

class Player
{
public:
    Player(string name, int Score, LinkedList *TilesInHand);

    int getScore();
    void setScore(int Score);

    LinkedList *getTilesInHand();
    void setTilesInHand(LinkedList *TilesInHand);

    string getName();
    void setName(string name);

private:
    string name;
    int Score;
    LinkedList *TilesInHand;
};

#endif // ASSIGN2_NODE_H
