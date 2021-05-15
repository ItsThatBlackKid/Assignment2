#include "TileBag.h"

TileBag::TileBag(LinkedList *list)
{
    this->list = list;
    shuffle();
}

void TileBag::shuffle()
{
    LinkedList *newList = new LinkedList();
    int size = list->getSize();

    for (int i = 0; i < size; i++)
    {
        int ind = rand() % size;
        Tile *temp = list->get(ind)->tile;
        newList->addBack(temp);
    }

    this->list = newList;
}

Tile* TileBag::get(int i) {
    if(i >= size() || i < 0) {
        throw std::out_of_range("Error: index is out of range");
    }

    return list->get(i)->tile;
}

int TileBag::size() {
    return list->getSize();
}