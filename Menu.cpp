#include "Menu.h"
#include "QwirleIO.h"
#define numofPlayers = 2

Menu::Menu()
{
    LinkedList *list = new LinkedList();
    delete list;
}
//Runs the Game + Takes Players Input
void Menu::runGame()
{
    string playerInput = "";
    cout << "Welcome to Qwirkle!" << std::endl;
    cout << "-------------------" << std::endl;
    //Prints out Menu
    displayMenu();
    cin >> playerInput;
    int input = stoi(playerInput);
    switch (input)
    {
    //Player Input's "1" - Starts New Game
    case 1:
        startNewGame();
        break;
    //Player Input's "2" - Load Game
    case 2:
        loadGame();
        break;
    //Player Input's "4" - Quit Game
    case 3:
        loadCredits();
        break;
    case 4:

        exit(0);
    default:
        break;
    }
    
}

//Start the New Game
void Menu::startNewGame()
{
    //Define 2 Player Game

    
    cout << "\nStarting a New Game" << std::endl;

    Player* p1 = new Player();
    Player* p2 = new Player();

    cout << "Player 1 enter name: " << endl;
    string name;
    std::getline(cin, name);
    p1->setName(name);
    cout << "Player 1 enter name: " << endl;
    name = "";
    std::getline(cin, name);
    p2->setName(name);

    GameBoard* board = new GameBoard();

    LinkedList* tilesUnsorted = new LinkedList();
    std::array<Colour, 6> colours = {'R', 'O', 'Y', 'G', 'B', 'P'};

    for(int i = 0; i < MAX_TILES; i++) {
        int val = (i %6);
        char c = colours[val];

        int shape = val + 1;

        Tile* t = new Tile(c, shape);

        tilesUnsorted->addBack(t);
    }

    TileBag* bag = new TileBag(tilesUnsorted);

    std::array<Player*,2> players = {p1, p2};

    playGame(players, board, bag);
}



//Displays the Menu
void Menu::displayMenu()
{
    cout << "Menu" << std::endl;
    cout << "----" << std::endl;
    cout << "1. New Game" << std::endl;
    cout << "2. Load Game" << std::endl;
    cout << "3. Credits (Show student information)" << std::endl;
    cout << "4. Quit" << std::endl;
    cout << "> " << std::flush;
}

//Load Game
void Menu::loadGame()
{

}

//Show Credits
void Menu::loadCredits()
{
    cout << "----------------------------------" << std::endl;
    cout << "Name: Patrick La" << std::endl;
    cout << "Student Number: S3508768" << std::endl;
    cout << "Email: S3508768@student.rmit.edu.au \n\n"
         << std::endl;

    cout << "Name: Kejie Wang" << std::endl;
    cout << "Student Number: S3716098" << std::endl;
    cout << "Email: S3716098@student.rmit.edu.au \n\n"
         << std::endl;

    cout << "Name: Muhammed Khodr" << std::endl;
    cout << "Student Number: S3779580" << std::endl;
    cout << "Email: S3779580@student.rmit.edu.au \n\n"
         << std::endl;

    cout << "Name: Sao Kanneh" << std::endl;
    cout << "Student Number: S3788996" << std::endl;
    cout << "Email: S3788996@student.rmit.edu.au \n\n"
         << std::endl;
    cout << "----------------------------------" << std::endl;
}
