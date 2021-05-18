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
    // 0 for insert but no qwirkle, -1 for fail, 1 for insert and qwirkle
    int TileInsert(const char* position, Tile* tile );

    std::vector<std::vector<Tile*>> getGameBoard();

    void placeTile(Tile* tile, string location);

    friend std::ostream& operator << (std::ostream& os, const GameBoard& g);
    friend ofstream& operator << (ofstream& of, GameBoard& g);
    friend ifstream& operator >> (ifstream& in, GameBoard* g);

    private:
    std::vector<Tile*> gameRow;
    std::vector<std::vector<Tile*>> gameBoard;
    vector<char> qwirkleRows;
    vector<int> qwirkleCols; 

    // 0 for up, 1 for right, 2 for down, 3 for left
    bool isQwirkle(int row, int column, int direction, Tile* t);
    bool doesMatch(int row,int column, Tile* t);
    

};

#endif // ASSIGN2_GameBoard_H