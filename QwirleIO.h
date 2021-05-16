#ifndef ASSIGN2_QWIRKLEIO_H
#define ASSIGN2_QWIRKLEIO_H

#include <fstream>
#include <iostream>
#include <string>

#include "Player.h"
#include "GameBoard.h"
#include "TileBag.h"

void saveGameState(Player** players,GameBoard gameBoard, TileBag tileBag, std::string filename);
#endif