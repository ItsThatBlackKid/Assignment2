#include "QwirkleIO.h"

void saveGameState(std::array<Player*,2> players, GameBoard* gameBoard, TileBag *tileBag, std::string filename, bool isPlayerOne) {
    ofstream file;
    file.open(filename);
    file << *players[0];
    file << *players[1];
    file << *gameBoard;
    file << *tileBag;

    file << (isPlayerOne ? players[0]->getName() : players[1]->getName());
    file.close();
}

// returns current user's name
string loadGameState(std::array<Player*, 2> players, GameBoard* gameBoard, TileBag* tileBag, string filename) {
    ifstream file;
    file.open(filename);

    for(Player* p: players) {
        file >> p;
    } 

    file >> gameBoard;
    file >> tileBag;
    string currName;
    getline(file, currName);
    return currName;
    file.close();
}