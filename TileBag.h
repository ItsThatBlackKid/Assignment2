#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H

#include <random>
#include <stdexcept>

#include "LinkedList.h"

class TileBag
{
public:
    TileBag(LinkedList *list);
    ~TileBag();

    // returns a copy of the tile object
    Tile *get(int i);


    int size();

private:
    LinkedList *list;

    void shuffle();
};

#endif