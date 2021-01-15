#include "FuriousSea.hpp"

#include<vector>

using namespace std;

void FuriousSea::startUp() {
	initialisePlayers();
	initiliseShips();
	initiliseOtherItems();
	gameMap->drawMap();
	gameState = GameConstants::PLAYER_ONE_ACTIVE_STATE;
}



void FuriousSea::update() {
	if (gameState == GameConstants::PLAYER_ONE_ACTIVE_STATE) {
		if (playerTurn(*pPlayerOne)) {
			this->finish();
		}
		else {
			gameState = GameConstants::PLAYER_TWO_ACTIVE_STATE;
		}
	}
	else if (gameState == GameConstants::PLAYER_TWO_ACTIVE_STATE) {
		if (playerTurn(*pPlayerTwo)) {
			this->finish();
		}
		else {
			gameState = GameConstants::PLAYER_ONE_ACTIVE_STATE;
		}
	}
	if (this->allShipsSunk()) {
		this->finish();
	}
}

void FuriousSea::display() {
	system("cls");
	gameMap->drawMap();
}

//runs code for when the game is over
void FuriousSea::shutdown() {
	endGameUI();
	system("pause");
}
//sets up the two players for the game
void FuriousSea::initialisePlayers() {
	pPlayerOne = new Player("James", GameConstants::ULTRA_MUNITIONS_AMOUNT);
	pPlayerTwo = new Player("Sarah", GameConstants::ULTRA_MUNITIONS_AMOUNT);
}
//intialises any ships for the game
void FuriousSea::initiliseShips() {
	pShips = new vector<Ship*>;
	Destroyer* pDestroyer = new Destroyer(00, 01, 02);
	pShips->push_back(pDestroyer);
	pDestroyer = new Destroyer(33, 43, 53);
	pShips->push_back(pDestroyer);
	pDestroyer = new Destroyer(92, 93, 94);
	pShips->push_back(pDestroyer);
	Cruiser* pCruiser = new Cruiser(9, 19, 29, 39);
	pShips->push_back(pCruiser);
	pCruiser = new Cruiser(46, 47, 48, 49);
	pShips->push_back(pCruiser);
	Battleship* pBattleship = new Battleship(20, 21, 22, 23, 24);
	pShips->push_back(pBattleship);
}
//initialises the other items of the game
void FuriousSea::initiliseOtherItems() {
	gameMap = new GameMap("Furious Sea", 10, 10);
	nMunition = new NormalMunition;
	uMunition = new UltraMunition;
}

//runs through the code to implement the current players turn;
bool FuriousSea::playerTurn(Player& player)
{
	string command;
	string munition;
	int coords;

	// Keep asking for a command until a valid one is entered
	bool validCommand = false;
	while (!validCommand)
	{
		displayPlayerUI(player);

		cin >> command;

		// If command is "quit" then abort and return true to indicate that the game should immediately finish
		if ((command == "QUIT") || (command == "quit"))
		{
			return true;
		}

		// Parse the command to get the munition type and the coordinates of the map location to attack, if
		// this parse returns false then it indicates that an invalid command was provided
		validCommand = parseCommand(command, munition, coords);

		// A valid command can now be processed
		if (validCommand)
		{
			// Break from asking to enter a valid command
			break;
		}

		// Keep asking for a valid commnd, display the UI again with an added message stating that the
		// command was invalid
		system("cls");
		gameMap->drawMap();
		cout << endl;
		cout << "  " << command << " is not a valid command!";
	}

	// A valid command has been entered and has been parsed in the munition, xcoord and ycoord variables, these
	// can be now used to attack the location (hitting any ship at that location) using the requested munition
	//
	// Note - if an invalid munition is supplied (either wrong munition type or that the player has none of the
	// munition remaining) then the player has wasted their turn and a miss is indicated
	//
	// This attackResult string variable is used to record any hit or miss after the attack has taken place and
	// also is the supplied munition is not available
	string attackResult;
	if (munition == "N")
	{
		// Action the effect of the normal munition type as an attack by the player on the selected coordinates
		nMunition->fireMunition(player, *gameMap, *pShips, coords, attackResult);
	}
	else if (munition == "U" && player.hasUltraMunitions())
	{
		// Action the effect of the ultra munition type as an attack by the player on the selected coordinates
		player.deductUltraMunition();
		uMunition->fireMunition(player, *gameMap, *pShips, coords, attackResult);
	}
	else
	{
		// Unknown munition type in the command so abort without checking for ship hits (ie. player turn wasted)
		cout << "  No munitions of type " << munition << ", wasted attack attempt!";
		cout << endl << endl;
		cout << "  ";
		system("pause");
		return false;
	}

	// Display the result of the player attack and await player to progress the game
	cout << endl;
	cout << "  " << attackResult;
	cout << endl << endl;
	cout << "  ";
	system("pause");

	// Return false to indicate that the game should continue
	return false;
}
//outputs the current players details including score and ultra munitions left over
void FuriousSea::displayPlayerUI(const Player& player) {
	cout << endl;

	cout << "  Your turn ";
	cout << player.getName();
	cout << endl;

	cout << "  You have ";
	cout << player.getUltra() << " Ultra munition" << ((player.getUltra() == 1) ? "" : "s") << " remaining ";
	cout << endl;

	cout << "  Your score is " << player.getScore() << " point" << ((player.getScore() == 1) ? "" : "s");
	cout << endl;

	cout << "  Enter your command: ";
}

bool FuriousSea::parseCommand(const string& command, string& munition, int& coordinate) {
	// Command must be a string of exactly 3 characters in length, if not then abort and return false
	if (command.length() != 3)
	{
		return false;
	}
	// Type of munition is the first character in the command string
	munition = toupper(command[0]);
	coordinate = stoi(command.substr(1, 2));
	if (coordinate >= 0 && coordinate <= 99)
	{
		return true;
	}
	else {
		return false;
	}
}
//displays details on score and winner based on game results

void FuriousSea::endGameUI() {
	cout << "  Game has Ended";
	cout << endl << endl;

	cout << "  " << pPlayerOne->getName() << " has " << pPlayerOne->getScore() << " point" << ((pPlayerOne->getScore() == 1) ? "" : "s");
	cout << endl;
	cout << "  " << pPlayerTwo->getName() << " has " << pPlayerTwo->getScore() << " point" << ((pPlayerTwo->getScore() == 1) ? "" : "s");
	cout << endl << endl;

	if (pPlayerOne->getScore() > pPlayerTwo->getScore())
	{
		cout << "  " << pPlayerOne->getName() << " has won!" << endl;
	}
	else if (pPlayerOne->getScore() < pPlayerTwo->getScore())
	{
		cout << "  " << pPlayerTwo->getName() << " has won!" << endl;
	}
	else
	{
		cout << "  Game is a draw. Why not have a rematch?" << endl;
	}
}

bool FuriousSea::allShipsSunk()
{
	// Check each ship to see if it has taken hits that will sink it (ie. hitsTaken equal to ship size), if any
	// ships are still afloat then return false, otherwise return true (all ships have been sunk)
	bool foundShipAfloat = false;
	for (vector<Ship*>::iterator iter = pShips->begin(); iter != pShips->end(); iter++)
	{
		Ship* pCurrentShip = (*iter);
		if (pCurrentShip->hitsTaken != pCurrentShip->size)
		{
			// Not enough hits to sink ship, so it is still afloat
			foundShipAfloat = true;
			break;
		}
	}
	// Return true if no ship found to be afloat (all ships are sunk), return false otherwise
	return !foundShipAfloat;
}