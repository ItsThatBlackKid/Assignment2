#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H
#include <iostream>

#include "Menu.h"
#include "LinkedList.h"
#include "Player.h"
#include "TileBag.h"
#include "GameBoard.h"
#include "Tile.h"
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


    private:
    void playGame(std::array<Player*,2> players, GameBoard* gameBoard, TileBag* tileBag);
};
#endif //ASSIGN_MENU_H