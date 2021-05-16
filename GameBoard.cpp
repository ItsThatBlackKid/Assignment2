#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard()
{
    gameRow.assign(MAXIMUM_BOARD_SIZE, nullptr);
    gameBoard.assign(MAXIMUM_BOARD_SIZE, gameRow);
}

<<<<<<< HEAD
void GameBoard::TileInsert(char position[2], Tile* tile){

    int ROW = int(position[0]-65);
    int COLUMN = int(position[1]-30);

    int UP = ROW-1;
    int DOWN = ROW+1;
    
    int LEFT = COLUMN-1;
    int RIGHT = COLUMN+1;

    if(gameBoard[UP][COLUMN]!=nullptr){
        if(!isLegal(UP,COLUMN, tile)){
            return;
        }
    }
    if(gameBoard[DOWN][COLUMN]!=nullptr){
        if(!isLegal(DOWN,COLUMN, tile)){
            return;
        }
    }
    if(gameBoard[ROW][LEFT]!=nullptr){
        if(!isLegal(ROW,LEFT, tile)){
            return;
        }
    }
    if(gameBoard[ROW][RIGHT]!=nullptr){
        if(!isLegal(ROW,RIGHT, tile)){
            return;
        }
    }
    else{
        gameBoard[ROW][COLUMN] = tile;
    }
}

bool GameBoard::isLegal(int ROW, int COLUMN, Tile* tile){
    if(gameBoard[ROW][COLUMN]->colour == tile->colour){
        return true;
    }else if(gameBoard[ROW][COLUMN]->shape == tile->shape){
        return true;
    }
    else return false;
}

std::ostream& operator << (std::ostream& os, const GameBoard g){
=======
std::vector<std::vector<Tile*>> GameBoard::getGameBoard() {
    return gameBoard;
}

std::ostream &operator<<(std::ostream &os, const GameBoard g)
{
>>>>>>> fe2cca5566845b9a4812925d05eac61e94108dd8
    Colour colour;
    char shape;
    for (int i = 0; i < MAXIMUM_BOARD_SIZE; i++)
    {

        if (i < 10)
        {
            os << "  " << i;
        }
        else
        {
            os << " " << i;
        }
    }
    os << std::endl;
    os << "  ";
    for (int i = 0; i < MAXIMUM_BOARD_SIZE; i++)
    {
        os << "---";
    }
    os << std::endl;
    for (size_t i = 0; i < g.gameBoard.size(); i++)
    {
        os << char(i + 65);
        for (size_t j = 0; j < g.gameBoard[i].size(); j++)
        {
            if (g.gameBoard[i][j] == nullptr)
            {
                os << "|  ";
            }
            else
            {
                colour = g.gameBoard[i][j]->colour;
                shape = g.gameBoard[i][j]->shape;
                os << "|" << colour << shape;
            }
        }
        os << "|" << std::endl;
    }
    return os;
}

ofstream& operator<<(ofstream& of, GameBoard g) {
    of << "26,26" << std::endl;

    std::vector<std::vector<Tile*>> gb = g.getGameBoard();
    bool checked = false;

    for(size_t i = 0; i < g.getGameBoard().size(); i++) {
        char row = (i + 65);
        for(size_t j = 0; j < gb.at(i).size(); j++) {
            Tile* t = gb.at(i).at(j);
            if( t != nullptr) {
                if(checked) {
                    of << ", ";
                }
                of << t << "@" << row << j << "";
                checked = true;
            }
        }
    }

    of << std::endl;
    return of;
}