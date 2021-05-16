#ifndef ASSIGN2_GameBoard_H
#define ASSIGN2_GameBoard_H

#include <iostream>
#include "LinkedList.h"
#include <vector>

#define MAXIMUM_BOARD_SIZE      26
class GameBoard{
    
    public:
    GameBoard();
    // ~GameBoard();
    void TileInsert(char position[2], Tile* tile );
    bool isLegal(int ROW, int COLUMN, Tile* tile);
    friend std::ostream& operator << (std::ostream& os, const GameBoard g);
    private:
    std::vector<Tile*> gameRow;
    std::vector<std::vector<Tile*>> gameBoard;
    

};

#endif // ASSIGN2_GameBoard_H;