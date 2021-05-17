#ifndef ASSIGN2_GameBoard_H
#define ASSIGN2_GameBoard_H

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>
#include "LinkedList.h"
#include <vector>

using std::ofstream;
using std::ifstream;
using std::vector;
using std::string;

#define MAXIMUM_BOARD_SIZE      26
class GameBoard{
    
    public:
    GameBoard();
    // ~GameBoard();
    void TileInsert(const char* position, Tile* tile );
    bool isLegal(int ROW, int COLUMN, Tile* tile);

    std::vector<std::vector<Tile*>> getGameBoard();

    void placeTile(Tile* tile, string location);

    friend std::ostream& operator << (std::ostream& os, const GameBoard& g);
    friend ofstream& operator << (ofstream& of, GameBoard& g);
    friend ifstream& operator >> (ifstream& in, GameBoard* g);

    private:
    std::vector<Tile*> gameRow;
    std::vector<std::vector<Tile*>> gameBoard;
    

};

#endif // ASSIGN2_GameBoard_H;