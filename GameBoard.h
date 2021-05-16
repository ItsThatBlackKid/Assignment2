#ifndef ASSIGN2_GameBoard_H
#define ASSIGN2_GameBoard_H

#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include <vector>

using std::ofstream;

#define MAXIMUM_BOARD_SIZE      26
class GameBoard{
    
    public:
    GameBoard();
    // ~GameBoard();
<<<<<<< HEAD
    void TileInsert(char position[2], Tile* tile );
    bool isLegal(int ROW, int COLUMN, Tile* tile);
=======
    // void TileInsert(char position[2], Tile tile );

    std::vector<std::vector<Tile*>> getGameBoard();

>>>>>>> fe2cca5566845b9a4812925d05eac61e94108dd8
    friend std::ostream& operator << (std::ostream& os, const GameBoard g);
    friend std::ofstream& operator << (ofstream& of, GameBoard& g);
    private:
    std::vector<Tile*> gameRow;
    std::vector<std::vector<Tile*>> gameBoard;
    

};

#endif // ASSIGN2_GameBoard_H;