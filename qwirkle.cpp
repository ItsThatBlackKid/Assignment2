#include "GameBoard.h"
#include "LinkedList.h"

#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;
   GameBoard* Game = new GameBoard();
   std::cout<<*Game;
   return EXIT_SUCCESS;
}
