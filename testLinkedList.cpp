#include "LinkedList.h"

#include <iostream>
#include <string>

void testAddFront();
void testAddBack();
void testGet();

void testSize();
void testClear();

void testRemove();

int main(void) {
    // testAddFront();
    // testAddBack();
    // testGet();

    testRemove();
}

void testAddFront() {
    // test adding to an empty list
    std::string msg = "";
    LinkedList* test = new LinkedList();
    Tile* t = new Tile();

    test->addFront(t);


    msg += test->getSize() == 0 ? "ADD FRONT TEST: FAILED\n" : 
    "ADD FRONT TEST: PASSED";

    delete test;

    std::cout << msg << std::endl;
}

void testAddBack() {
    std::string msg = "";
    LinkedList* test = new LinkedList();
    Tile* t = new Tile();

    test->addFront(t);
    test->addBack(t);


    msg += test->getSize() > 1 ? "ADD BACK TEST: FAILED\n" : 
    "ADD BACK TEST: PASSED";

    delete test;

    std::cout << msg << std::endl;
 
}


void testGet() {
    std::string msg = "";
    LinkedList* list = new LinkedList();

    // list should be: [1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,1,2]
    for(int i = 0; i < 20; i++) {
        Tile* t = new Tile();
        t->shape = (i %6) +1;
        list->addBack(t);
    }
    std::cout << "LIST SIZE: " << list->getSize() << std::endl;

    //testing with getHead, should return 1
    Node* n = list->getHead();
    Tile* t = n->tile;
    int shape = t->getShape();
    
    msg += "COLOUR RETRIEVED: " + std::to_string(shape);

    std::cout << msg << std::endl;
    msg = "";

    // testing with get(5), should should return 6
    n = list->get(5);
    msg = "COLOUR RETRIEVED: " + std::to_string(shape);
    std::cout << msg << std::endl;
}

void testRemove() {
    LinkedList* list = new LinkedList();

    for(int i = 0; i < 3; i++) {
        Tile* t = new Tile();

        //A, B, C
        t->colour = (char) i + 65;
        //0, 1, 2
        t->shape = (Shape) i;
        list->addBack(t);
    }

    std::cout << "before remove: " << std::endl;
    std::cout << *list << std::endl;
    // delete "B";
    list->remove(1);
    std::cout << *list << std::endl;


}
