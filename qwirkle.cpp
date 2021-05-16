#include "GameBoard.h"
#include "LinkedList.h"
#include "Menu.h"
#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   Menu* menu = new Menu();
   while(true){
      menu->runGame();
   }

}
