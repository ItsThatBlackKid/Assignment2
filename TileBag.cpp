#include "TileBag.h"

TileBag::TileBag()
{
    this->list = nullptr;
}

TileBag::TileBag(LinkedList *list)
{
    this->list = list;
    shuffle();
}

TileBag::~TileBag()
{
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

Tile *TileBag::get(int i)
{
    if (i >= size() || i < 0)
    {
        throw std::out_of_range("Error: index is out of range");
    }

    return list->get(i)->tile;
}

int TileBag::size()
{
    return list->getSize();
}

LinkedList *TileBag::getList()
{
    return list;
}

void TileBag::setList(LinkedList* list) {
    this->list = list;
} 

void TileBag::add(Tile* t) {
    list->addBack(t);
}

void TileBag::remove(int i) {
    list->remove(i);
}

bool TileBag::isEmpty() {
    return list->isEmpty();
}

ofstream &operator<<(ofstream &of, TileBag &tileBag)
{
    LinkedList &list = *tileBag.getList();

    of << list;
    return of;
}

ifstream &operator>>(ifstream &in, TileBag *bag)
{
    LinkedList *list = new LinkedList();
    in >> list;
    bag->setList(list);
    return in;
}