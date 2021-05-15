#include "TileBag.h"

#include <iostream>

void testTileBag();

int main(void) {
    testTileBag();
}

void testTileBag() {
    LinkedList* list = new LinkedList();

    
    for(int i = 0; i < 20; i++) {
        int shape = (i % 6) +1;
        Tile* t = new Tile();
        t->shape = shape;
        list->addBack(t); 
    }


    TileBag* tBag = new TileBag(list);
    std::cout << "Shapes IN TILEBAG: " << std::endl;

    for(int i = 0; i < 20; i++) {
        std::cout << (i +1) << ": " << tBag->get(i)->shape << std::endl;
    }


}