#ifndef ASSIGN2_QWIRKLEIO_H
#define ASSIGN2_QWIRKLEIO_H


#include <fstream>
#include <iostream>
#include <string>
#include <array>

#include "Player.h"
#include "GameBoard.h"
#include "TileBag.h"

#endif

void saveGameState(std::array<Player*,2> players,GameBoard* gameBoard, TileBag* tileBag, std::string filename, bool isPlayerOne);
string loadGameState(std::array<Player*,2> players, GameBoard* gameBoard, TileBag* tileBag, std::string filename);