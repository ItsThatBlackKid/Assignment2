#include "Menu.h"
#define numofPlayers = 2

Menu::Menu() {
LinkedList* list = new LinkedList();
delete list;
}
//Runs the Game + Takes Players Input
void Menu::runGame() {
string playerInput = "";  
cout << "Welcome to Qwirkle!" << std::endl;
cout << "-------------------" << std::endl;
//Prints out Menu 
displayMenu();
cin >> playerInput;
//Player Input's "1" - Starts New Game
if (std::stoi(playerInput) == 1) {
startNewGame();
}
//Player Input's "2" - Load Game
else 
{
    if (std::stoi(playerInput) == 2) {
    loadGame();
}
//Player Input's "3" - Credits (Show's Student Information)
else if (std::stoi(playerInput) ==  3) {
    loadCredits();
    }
//Player Input's "4" - Quit Game
if (std::stoi(playerInput) == 4) {


    std::cout << "Goodbye" << std::flush;
}
}
}

//Start the New Game
void Menu::startNewGame() {
//Define 2 Player Game
string playerName [numofPlayers];
cout << "\nStarting a New Game" << std::endl;

playerName[0] = inputPlayerName(1);
playerName[1] = inputPlayerName(2);

std::cout << "Let's Play!" << std::endl;
}

//Check if Player Name is valid via regex
bool Menu:: checkValidName(std::string player) {
bool outcome = false;
//Regex for Uppercase Characters
std::regex name("[A-Z]");
if (std::regex_match(player,name)) 
{
    outcome = true;
}
    return outcome;
}

//Inputting Player Name
string Menu::inputPlayerName(string player) {
string player = "";
bool check = true;
do {
    if (check){
    cout <<"\nEnter a name for player 1 (uppercase characters only)"<< player << std::endl;
    cout <<"> " << std::flush;
    std::getline(std::cin,player);
    check = false;
}
else if (!checkValidName(player)) {
    cout <<"Please use Uppercase Characters only" <<std::endl;
    cout <<"> " << std::flush;
    std::getline(std::cin, player);
    }
}
    while (!checkValidName(player));
    return player;
}

//Displays the Menu 
void Menu::displayMenu() {
cout << "Menu" << std::endl;
   cout << "----" << std::endl;
   cout << "1. New Game" << std::endl;
   cout << "2. Load Game" << std::endl;
   cout << "3. Credits (Show student information)" << std::endl;
   cout << "4. Quit" << std::endl;
   cout <<"> " << std::flush;
}

//Load Game
void Menu::loadGame() {



}

//Show Credits
void Menu::loadCredits() {
cout << "----------------------------------" << std::endl;
      cout << "Name: Patrick La"  << std::endl;
      cout << "Student Number: S3508768" << std::endl;
      cout << "Email: S3508768@student.rmit.edu.au \n\n" << std::endl;

      cout << "Name: Kejie Wang"  << std::endl;
      cout << "Student Number: S3716098" << std::endl;
      cout << "Email: S3716098@student.rmit.edu.au \n\n" << std::endl;

      cout << "Name: Muhammed Khodr"  << std::endl;
      cout << "Student Number: S3779580" << std::endl;
      cout << "Email: S3779580@student.rmit.edu.au \n\n" << std::endl;

      cout << "Name: Sao Kanneh"  << std::endl;
      cout << "Student Number: S3788996" << std::endl;
      cout << "Email: S3788996@student.rmit.edu.au \n\n" << std::endl;
      cout << "----------------------------------" << std::endl;
}

