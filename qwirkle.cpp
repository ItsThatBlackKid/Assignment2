#include "GameBoard.h"
#include "LinkedList.h"
#include "Menu.h"
#include <time.h>
#include <iostream>

#define EXIT_SUCCESS 0

int main(void)
{
   srand(425687931);
   Menu *menu = new Menu();
   menu->runGame();
}
