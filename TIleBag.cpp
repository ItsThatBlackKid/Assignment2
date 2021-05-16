#include "TileBag.h"

TileBag::TileBag(LinkedList* list) {
    this->list = list;
}

void TileBag::shuffle() {
    LinkedList* temp = new LinkedList();
    LinkedList* temp2 = new LinkedList();
    while(!this->list->isEmpty()) {
        Node* h = list->getHead();
        temp->addFront(h->tile);
        list->removeFront();
        if(!this->list->isEmpty()) {
            
        }
    }
}