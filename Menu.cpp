#include "Menu.h"
#include "QwirkleIO.h"
#include "util.h"
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

    for (Player *p : players)
    {
        p->setTilesInHand(tilebag);
    }

    array<Player *, 2> newPlayers;
    vector<int> ind;
    vector<int> ind2;
    int s1 = 0;
    int s2 = 0;

    for (int i = 0; (size_t)i < players.size(); i++)
    {
        Player *p = players[i];
        LinkedList *list = p->getHand();
        int count = 0;
        for (Node *h = list->getHead(); h != nullptr; h = h->next)
        {
            Tile *t = h->tile;
            int count2 = count;
            for (Node *j = h->next; j != nullptr; j = j->next)
            {
                Tile *t2 = j->tile;
                // check for similarities
                if (t->shape == t2->shape || t->colour == t2->colour)
                {
                    if (i == 0)
                    {
                        s1++;
                        if (!std::count(ind.begin(), ind.end(), count))
                        {
                            ind.push_back(count);
                        }
                        if (!std::count(ind.begin(), ind.end(), count2))
                        {
                            ind.push_back(count2);
                        }
                    }
                    else
                    {
                        if (!std::count(ind2.begin(), ind2.end(), count))
                        {
                            ind2.push_back(count);
                        }
                        if (!std::count(ind2.begin(), ind2.end(), count2))
                        {
                            ind2.push_back(count2);
                        }
                        s2++;
                    }
                }
                count2++;
            }
            count++;
        }
    }

    if (s1 >= s2)
    {
        // do smomething
        Player *p = players[0];
        playInitialTiles(p, ind, board, tilebag);
        newPlayers.at(1) = p;
        newPlayers.at(0) = players[1];
    }
    else
    {
        Player *p = players[1];
        newPlayers.at(1) = p;
        newPlayers.at(0) = players[0];
        playInitialTiles(p, ind2, board, tilebag);
    }

    /* board->TileInsert("D3", tilebag->getFront(), true);
    tilebag->removeFront(); */
    playGame(newPlayers, board, tilebag);
}

void Menu::playInitialTiles(Player *p, vector<int> ind, GameBoard *board, TileBag* bag)
{
    cout << p->getName() << " starts first, choose which row or column to place tiles (A/0)" << endl;
    cout << *p->getHand() << endl;
    bool tilePlayed = false;

    while (!tilePlayed)
    {
        cout << "(ROW x/ COLUMN y)> ";
        string input = "";
        getline(cin, input);
        vector<string> tokens = tokenise(input, ' ');
        string axis = tokens.at(0);
        string opto = tokens.at(1);
        char opt = opto[0];
        cout << "ind size; " << ind.size() << endl;
        for (int i = 0; (size_t)i < ind.size(); i++)
        {
            string opto = tokens.at(1);
            int id = ind.at(i);
            if (axis == "column")
            {
                char row = (char)i + 65;
                int col = opt - '0';
                string pos(1, row);
                pos += std::to_string(col);
                board->TileInsert(pos.c_str(), p->getHand()->get(id)->tile, true);
                board->getGameBoard().at(i).at(col) = p->getHand()->get(id)->tile;
                p->getHand()->remove(id);
                tilePlayed = true;
            }
            else if (axis == "row")
            {
                int row = opt - 65;

                board->TileInsert(opto.c_str(), p->getHand()->get(id)->tile, true);
                // board->getGameBoard().at(row).at(i) = p->getHand()->get(id)->tile;
                p->getHand()->remove(id);
                p->getTile(bag);
                tilePlayed = true;
            }
            else
            {
                cout << "Sorry, invalid input" << endl;
                i = ind.size();
            }
        }
    }
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

                while (!turnEnd && !gameEnd)
                {
                    cout << "> ";
                    getline(cin, playerInstruction);

                    vector<string> tokens = tokenise(playerInstruction, ' ');

                    regex e("[A-Z][0-9]");

                    string command = tokens[0];
                    if (command == "place")
                    {
                        //  should be "at"
                        string atToken = tokens[2];
                        if (atToken == "at")
                        {
                            string tile = tokens[1];
                            string loc = tokens[3];

                            std::transform(tile.begin(), tile.end(), tile.begin(), ::toupper);
                            std::transform(loc.begin(), loc.end(), loc.begin(), ::toupper);

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
                                    break;
                                default:
                                    break;
                                }
                            }
                        }
                    }
                    else if (command == "replace")
                    {
                        string tile = tokens[1];
                        std::transform(tile.begin(), tile.end(), tile.begin(), ::toupper);
                        if (regex_match(tile, e))
                        {
                            p->replaceTile(tileBag, tile);
                            turnEnd = true;
                        }
                    }
                    else if (command == "save")
                    {
                        cout << "Enter filename: ";
                        string filename;
                        getline(cin, filename);
                        saveGameState(players, gameBoard, tileBag, filename, (bool)(pCount % 2));
                    }
                    else if (command == "quit")
                    {
                        gameEnd = true;
                        turnEnd = true;
                    }

                    if (!turnEnd)
                    {
                        cout << "Sorry, invalid move" << endl;
                    }

                    // set the exit condition
                    if (tileBag->isEmpty() && !gameEnd)
                    {
                        for (auto p : players)
                        {
                            if (p->getHand()->isEmpty())
                            {
                                gameEnd = true;
                                turnEnd = true;
                            }
                        }
                    }

                    if (!gameEnd)
                    {
                        if (p->getHand()->getSize() < 6)
                        {
                            p->getTile(tileBag);
                        }
                    }
                }
            }
        }
    }

    for (Player *p : players)
    {
        delete p;
    }

    delete gameBoard;
    delete tileBag;
}