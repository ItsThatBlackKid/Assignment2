#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H

#include "LinkedList.h"

class TileBag {
    public:
    TileBag(LinkedList* list);

    private: 
    LinkedList* list;
    
    void shuffle();
};

#endif 