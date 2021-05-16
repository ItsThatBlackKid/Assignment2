#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H

#include <random>
#include <stdexcept>
#include <fstream>

#include "LinkedList.h"

#define MAX_TILES 108

class TileBag
{
public:
    TileBag(LinkedList *list);
    ~TileBag();

    // returns a copy of the tile object
    Tile *get(int i);

    LinkedList* getList();

    int size();
    friend ofstream& operator << (ofstream& of, TileBag& tileBag);

private:
    LinkedList *list;

    void shuffle();
};

#endif
