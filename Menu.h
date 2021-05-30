#ifndef ASSIGN2_MENU_H
#define ASSIGN2_MENU_H
#include <iostream>

#include "LinkedList.h"
#include "Player.h"
#include "TileBag.h"
#include "GameBoard.h"
#include "Tile.h"
#include "Node.h"
#include "util.h"
#include <regex>

using std::cout;
using std::cin;
using std::string;
using std::regex;
using std::regex_match;

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
    void playInitialTiles(Player* p, vector<int> ind, GameBoard* board, TileBag * bag);
};
#endif //ASSIGN_MENU_H