#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard()
{
    rows = 6;
    cols = 6;
    gameRow.assign(6, nullptr);
    gameBoard.assign(6, gameRow);
}

bool GameBoard::isValid(int row, int col, Tile *t)
{
    std::cout << "validating" << std::endl;
    bool isValid = false;

    if (tiles > 0)
    {
        for (int i = 0; i < 4; i++)
        {
            // we want to check the next direction if the move is valid.
            // here we assume the move is valid, and the gameboard must prove it is not
            // NORTH.
            Tile *tmp;
            for (int j = 1; j < 6; j++)
            {
                switch (i)
                {
                case 0:
                {
                    if (row - j >= 0)
                    {
                        tmp = gameBoard.at(row - j).at(col);
                        if (tmp)
                            isValid = t->canPlace(tmp);
                        else
                            j = 6;
                    }

                    break;
                }
                case 1:
                {
                    if (col + j < cols)
                    {
                        tmp = gameBoard.at(row).at(col + j);
                        if (tmp)
                            isValid = t->canPlace(tmp);
                        else
                            j = 6;
                    }

                    break;
                }
                break;
                case 2:
                {
                    if (row + j < rows)
                    {
                        tmp = gameBoard.at(row + j).at(col);
                        if (tmp) {
                            isValid = t->canPlace(tmp);
                            std::cout << "is valid: " << isValid << std::endl;
                        }
                        else
                            j = 6;
                    }

                    break;
                }
                case 3:
                {
                    if (col - j >= 0)
                    {
                        tmp = gameBoard.at(row).at(col - j);
                        if (tmp)
                            isValid = t->canPlace(tmp);
                        else
                            j = 6;
                    }

                    break;
                }
                default:
                    break;
                }
              /*   if (!isValid)
                {
                    i = 4;
                    j = 6;
                } */
            }
        }
    }

    return isValid;
}

int GameBoard::TileInsert(const char *position, Tile *tile, bool gameStart)
{
    int ROW = int(position[0] - 65);
    int COLUMN = int(position[1] - '0');

    int UP = ROW - 1;
    int DOWN = ROW + 1;

    int LEFT = COLUMN - 1;
    int RIGHT = COLUMN + 1;

    bool qwirkle = false;

    int playVal = -1;

    if ((size_t)ROW >= gameBoard.size())
    {
        vector<Tile *> row;
        row.assign(6, nullptr);
        gameBoard.push_back(row);
        rows = ROW;
    }

    // add an extra column to each row
    if ((size_t)COLUMN >= gameBoard.at(rows - 1).size())
    {
        int diff = COLUMN - gameBoard.at(rows -1).size();
        for (size_t i = 0; i < gameBoard.size(); i++)
        {
            if(diff == 0) {
                gameBoard.at(i).push_back(nullptr);
            } else {
                for(int j = 0; j < diff; j++) {
                    gameBoard.at(i).push_back(nullptr);
                }
            } 
        }
        vector<Tile *> row;
        row.assign(6, nullptr);
        gameBoard.push_back(row);
        rows = COLUMN;
        cols = COLUMN;
    }


    if (gameBoard.at(ROW).at(COLUMN) == nullptr)
    {
        // add a new row of tiles

        if (gameStart || isValid(ROW, COLUMN, tile))
        {
            gameBoard.at(ROW).at(COLUMN) = tile;
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
    for (size_t i = 0; i < g.gameBoard.size(); i++)
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
    for (size_t i = 0; i < g.gameBoard.size(); i++)
    {
        os << "---";
    }
    os << std::endl;

    // draw each row
    for (size_t i = 0; i < g.gameBoard.size(); i++)
    {
        os << char(i + 65);
        
        for (size_t j = 0; j < g.gameBoard.at(i).size(); j++)
        {
            if (g.gameBoard[i][j] == nullptr)
            {
                os << "|  ";
            }
            else
            {
                colour = g.gameBoard[i][j]->colour;
                shape = g.gameBoard[i][j]->shape;
                os << "|" << colour;
                os << (int)shape;
            }
        }
        os << "|" << std::endl;
    }
    return os;
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
                if (gameBoard.at(row).at(column) != nullptr)
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
            if (column < cols)
            {
                if (gameBoard.at(row).at(column) != nullptr)
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
            if (row < rows)
            {
                if (gameBoard.at(row).at(column) != nullptr)
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
                if (gameBoard.at(row).at(column) != nullptr)
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
    bool doesMatch = false;
    if (!gameBoard[row][column])
    {
        // do nothing
    }
    else
    {
        doesMatch = (gameBoard.at(row).at(column)->shape == t->shape || gameBoard.at(row).at(column)->colour == t->colour);
    }
    return doesMatch;
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
    string shape;
    std::getline(in, shape);
    string boardLine = "";
    std::getline(in, boardLine);

    std::stringstream ss(boardLine);

    vector<string> tiles;

    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        if (substr[0] == ' ')
        {
            string tmp = substr;
            substr = "";
            for (char c : tmp)
            {
                if (c != ' ')
                {
                    substr += c;
                }
            }
        }
        tiles.push_back(substr);
    }

    for (string s : tiles)
    {
        string t = s.substr(0, s.find('@'));
        string loc = s.substr(s.find('@') + 1);

        Tile *tile = new Tile();
        tile->colour = t[0];
        tile->shape = t[1] - '0';
        g->TileInsert(loc.c_str(), tile, true);
    }

    return in;
}

vector<vector<Tile *>> GameBoard::getGameBoard()
{
    return this->gameBoard;
}