#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard()
{
    gameRow.assign(MAXIMUM_BOARD_SIZE, nullptr);
    gameBoard.assign(MAXIMUM_BOARD_SIZE, gameRow);
}

bool GameBoard::isValid(int row, int col, Tile *t)
{
    bool isValid = false;
    vector<Tile *> tileVec;
    tileVec.assign(4, nullptr);
    if (tiles > 0)
    {
        if (row - 1 >= 0)
        {
            tileVec[0] = gameBoard[row - 1][col];
        }

        if (row + 1 < MAXIMUM_BOARD_SIZE)
        {
            tileVec[2] = gameBoard[row + 1][col];
        }

        if (col - 1 < MAXIMUM_BOARD_SIZE) {
            tileVec[1] = gameBoard[row][col-1];
        }

        if(col + 1 < MAXIMUM_BOARD_SIZE) {
            tileVec[3] = gameBoard[row][col+1];
        }

        for(Tile* check : tileVec) {
            if(check != nullptr) {
                if(check->colour == t->colour || check->shape == t->shape ) {
                    // isValid is true if and only if colour OR shape match.
                    isValid = !(check->colour == t->colour && check->shape == t->shape);
                } 
            }
        }
    } else {
        isValid = true;
    }

    return isValid;
}

int GameBoard::TileInsert(const char *position, Tile *tile)
{
    int ROW = int(position[0] - 65);
    int COLUMN = int(position[1] - '0');

    int UP = ROW - 1;
    int DOWN = ROW + 1;

    int LEFT = COLUMN - 1;
    int RIGHT = COLUMN + 1;

    bool qwirkle = false;

    int playVal = -1;

    if (gameBoard[ROW][COLUMN] == nullptr)
    {
        if (isValid(ROW, COLUMN, tile))
        {
            gameBoard[ROW][COLUMN] = tile;
            std::cout << "error happens in qwirkle" << std::endl;
            playVal = 0;
            qwirkle = isQwirkle(UP, COLUMN, 0, tile);
            qwirkle = qwirkle || isQwirkle(ROW, RIGHT, 1, tile);
            qwirkle = qwirkle || isQwirkle(DOWN, COLUMN, 2, tile);
            qwirkle = qwirkle || isQwirkle(COLUMN, LEFT, 3, tile);
            this->tiles++;
        }
    }

    if (qwirkle)
    {
        playVal = 1;
    }

    return playVal;
}

std::ostream &operator<<(std::ostream &os, const GameBoard &g)
{
    Colour colour;
    char shape;
    // draw the columns
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

    // draw each row
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

void GameBoard::placeTile(Tile *t, string location)
{
    int row = location[0] - 65;
    int col = location[1] - '0';

    gameBoard.at(row).at(col) = t;
}

bool GameBoard::isQwirkle(int row, int column, int direction, Tile *t)
{
    bool qwirkle = false;
    switch (direction)
    {

    // UP
    case 0:
    {
        int seqCount = 1;
        for (int i = seqCount; i < 5; i++)
        {
            row -= 1;
            if (row >= 0)
            {
                if (gameBoard[row][column] != nullptr)
                {
                    if (doesMatch(row, column, t))
                    {
                        seqCount++;
                    }
                }
            }
        }

        // remember this column if we have qwirkle
        if (seqCount >= 6)
        {
            qwirkle = true;
            qwirkleCols.push_back(column);
        }
        break;
    }
    case 1:
    {
        int seqCount = 1;
        for (int i = seqCount; i < 5; i++)
        {
            column += 1;
            if (column < MAXIMUM_BOARD_SIZE)
            {
                if (gameBoard[row][column] != nullptr)
                {
                    if (doesMatch(row, column, t))
                    {
                        seqCount++;
                    }
                }
            }
        }
        if (seqCount >= 6)
        {
            qwirkle = true;
            qwirkleRows.push_back(row);
        }
        break;
    }
    case 2:
    {
        int seqCount = 1;
        for (int i = seqCount; i < 5; i++)
        {
            row += 1;
            if (row < MAXIMUM_BOARD_SIZE)
            {
                if (gameBoard[row][column] != nullptr)
                {
                    if (doesMatch(row, column, t))
                    {
                        seqCount++;
                    }
                }
            }
        }

        if (seqCount >= 6)
        {
            qwirkle = true;
            qwirkleCols.push_back(column);
        }
        break;
    }
    case 3:
    {
        int seqCount = 1;
        for (int i = 0; i < seqCount; i++)
        {
            column -= 1;
            if (column >= 0)
            {
                if (gameBoard[row][column] != nullptr)
                {
                    if (doesMatch(row, column, t))
                    {
                        seqCount++;
                    }
                }
            }
        }

        if (seqCount >= 6)
        {
            qwirkle = true;
            qwirkleRows.push_back(row);
        }
        break;
    }
    default:
        break;
    }

    return qwirkle;
}

bool GameBoard::doesMatch(int row, int column, Tile *t)
{
    return gameBoard[row][column]->shape == t->shape && gameBoard[row][column]->colour == t->colour;
}

ofstream &operator<<(ofstream &of, GameBoard &g)
{
    of << "26,26" << std::endl;

    std::vector<std::vector<Tile *>> gb = g.getGameBoard();
    bool checked = false;

    for (size_t i = 0; i < g.getGameBoard().size(); i++)
    {
        char row = (i + 65);
        for (size_t j = 0; j < gb.at(i).size(); j++)
        {
            Tile *t = gb.at(i).at(j);
            if (t != nullptr)
            {
                if (checked)
                {
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

ifstream &operator>>(ifstream &in, GameBoard *g)
{
    // no need to read the shape here
    char c;
    in >> c;

    string boardLine = "";
    std::getline(in, boardLine);

    std::stringstream ss(boardLine);

    vector<string> tiles;

    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        tiles.push_back(substr);
    }

    for (string s : tiles)
    {
        string t = s.substr(0, s.find('@'));
        string loc = s.substr(s.find('@') + 1);

        Tile *tile = new Tile();
        tile->colour = t[0];
        tile->shape = t[1] - '0';
        g->placeTile(tile, loc);
    }

    return in;
}

vector<vector<Tile *>> GameBoard::getGameBoard()
{
    return this->gameBoard;
}