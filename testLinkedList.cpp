#include "LinkedList.h"

#include <iostream>
#include <string>

void testAddFront();
void testAddBack();

void testSize();
void testClear();

int main(void) {
    testAddFront();
    testAddBack();
}

void testAddFront() {
    // test adding to an empty list
    std::string msg = "";
    LinkedList* test = new LinkedList();
    Tile* t = new Tile();

    test->addFront(t);


    msg += test->size() == 0 ? "ADD FRONT TEST: FAILED\n" : 
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


    msg += test->size() > 1 ? "ADD BACK TEST: FAILED\n" : 
    "ADD BACK TEST: PASSED";

    delete test;

    std::cout << msg << std::endl;
}

