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
    TileBag();
    TileBag(LinkedList *list);
    ~TileBag();

    // returns a copy of the tile object
    Tile *get(int i);
    Tile* getFront();

    LinkedList* getList();
    void setList(LinkedList* list);

    void add(Tile* t);
    void remove(int i);
    void removeFront();

    bool isEmpty();

    int size();
    friend ofstream& operator << (ofstream& of, TileBag& tileBag);
    friend ifstream& operator >> (ifstream& in, TileBag* bag);

private:
    LinkedList *list;

    void shuffle();
};

#endif
