#include "Tile.h"
#include <iostream>

int main(void) {
    Tile* t = new Tile('R', 2);

    std::cout << *t << std::endl;
}