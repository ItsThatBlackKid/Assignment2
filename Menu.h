#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H
#include <iostream>
#include "Menu.h"
#include "LinkedList.h"
#include "Node.h"
#include <regex>

using std::cout;
using std::cin;
using std::string;
class Menu
{

public:
    Menu();
    void runGame();
    void startNewGame();
    void loadGame();

    void displayMenu();
    void loadCredits();

    bool checkValidName(std::string player1);
    std::string inputPlayerName(string player);
};
#endif //ASSIGN_MENU_H