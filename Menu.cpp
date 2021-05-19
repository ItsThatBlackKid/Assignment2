#include "Menu.h"
#include "QwirkleIO.h"
#define numofPlayers = 2

Menu::Menu()
{
    LinkedList *list = new LinkedList();
    delete list;
}
//Runs the Game + Takes Players Input
void Menu::runGame()
{
    while (!cin.eof())
    {
        string playerInput = "";
        cout << "Welcome to Qwirkle!" << std::endl;
        cout << "-------------------" << std::endl;
        //Prints out Menu
        displayMenu();
        cin >> playerInput;
        cin.ignore();
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
        default:
            cout << "Goodbye" << endl;
            exit(0);
            break;
        }
    }
}

//Start the New Game
void Menu::startNewGame()
{
    //Define 2 Player Game

    cout << "\nStarting a New Game" << std::endl;

    Player *p1 = new Player();
    Player *p2 = new Player();

    cout << "Player 1 enter name: ";
    string name;
    std::cin >> name;
    p1->setName(name);
    cout << "Player 2 enter name: ";
    name = "";
    std::cin >> name;
    p2->setName(name);
    std::array<Player *, 2> players = {p1, p2};
    cin.ignore();

    GameBoard *board = new GameBoard();
    LinkedList *tilesUnsorted = new LinkedList();

    std::array<Colour, 6> colours = {'R', 'O', 'Y', 'G', 'B', 'P'};

    for (int i = 0; i < MAX_TILES; i++)
    {
        int val = (i % 6);
        char c = colours[val];

        int shape = val + 1;

        Tile *t = new Tile(c, shape);

        tilesUnsorted->addBack(t);
    }

    TileBag *tilebag = new TileBag(tilesUnsorted);
    cout << "Tile Bag created" << endl;

    for (Player *p : players)
    {
        p->setTilesInHand(tilebag);
    }

    playGame(players, board, tilebag);
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
    Player *p = new Player();
    Player *p2 = new Player();
    std::array<Player *, 2> players = {p, p2};
    GameBoard *board = new GameBoard();
    TileBag *bag = new TileBag();

    string filename;
    string currName;

    cout << "Enter file name: ";
    getline(cin, filename);

    currName = loadGameState(players, board, bag, filename);

    if (currName == players[1]->getName())
    {
        Player *tmp = players[0];
        players[0] = players[1];
        players[1] = tmp;
    }

    playGame(players, board, bag);
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
void Menu::playGame(std::array<Player *, 2> players, GameBoard *gameBoard, TileBag *tileBag)
{
    std::cout << "Let's Play!" << std::endl;
    bool gameEnd = false;
    while (!gameEnd)
    {
        int pCount = 0;
        for (Player *p : players)
        {
            if (!gameEnd)
            {
                pCount++;
                cout << p->getName() << ", it is your turn" << endl;
                for (Player *pl : players)
                {
                    cout << "Score for " << pl->getName() << ": " << pl->getScore() << endl;
                }

                cout << *gameBoard;
                cout << "Your hand is" << endl;
                std::cout << *p->getHand() << endl;

                string playerInstruction = " ";
                bool turnEnd = false;

                while (!turnEnd)
                {
                    cout << "> ";
                    getline(cin, playerInstruction);
                    cout << "player input: " << playerInstruction << endl;
                    regex e("[A-Z][0-9]");

                    if (playerInstruction.compare(0, 6, "place ") == 0 && playerInstruction.compare(9, 3, "at ") == 0)
                    {
                        string tile = playerInstruction.substr(6, 2);
                        std::transform(tile.begin(), tile.end(), tile.begin(), ::toupper);
                        string loc = playerInstruction.substr(12, 2);
                        std::transform(loc.begin(), loc.end(), loc.begin(), ::toupper);

                        // check that the play was successful, otherwise print an error message
                        if (regex_match(tile, e) && regex_match(loc, e))
                        {
                            int playVal = p->playTile(gameBoard, loc, tile);
                            switch (playVal)
                            {
                            case 0:
                                p->setScore(p->getScore() + 1);
                                turnEnd = true;
                                break;
                            case 1:
                                cout << "QWIRKLE!!" << endl;
                                p->setScore(p->getScore() + 6);
                                turnEnd = true;

                            default:
                                cout << "Sorry, invalid move" << endl;
                                break;
                            }
                        }
                        else
                        {
                            cout << "Sorry, unable to make that move" << endl;
                        }
                    }
                    else if (playerInstruction.compare(0, 8, "replace ") == 0)
                    {
                        string tile = playerInstruction.substr(8, 2);
                        if (regex_match(tile, e))
                        {
                            p->replaceTile(tileBag, tile);
                        }
                        else
                        {
                            cout << "Sorry,  unable to make that move";
                        }
                    }
                    else if (playerInstruction.compare(0, 5, "save ") == 0)
                    {
                        string filename;
                        cout << "Enter filename: " << endl;
                        std::getline(cin, filename);
                        saveGameState(players, gameBoard, tileBag, filename, (bool)(pCount % 2));
                    }
                    else if (playerInstruction.compare(0, 5, "quit ") == 0)
                    {
                        gameEnd = true;
                    }
                    else
                    {
                        std::cout << "Invalid command" << std::endl;
                    }

                    // set the exit condition
                    if (tileBag->isEmpty() && !gameEnd)
                    {
                        {
                            if (p->getHand()->isEmpty())
                            {
                                gameEnd = true;
                            }
                        }
                    }

                    if (p->getHand()->getSize() < 6)
                    {
                        p->getTile(tileBag);
                    }
                }
            }
        }
    }
}