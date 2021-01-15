#pragma once
#ifndef _GAMECONSTANTS_
#define _GAMECONSTANTS_

#include <string>


class GameConstants final
{
public:
	// Relevant constants for the intialisation of the game data to be used for this prototype
	const static char CODE_FOR_BATTLESHIP = 'B';
	const static int POINTS_PER_BATTLESHIP_HIT = 3;
	const static int POINTS_PER_BATTLESHIP_SUNK = 5; // Total 20 points for destroying this ship type
	const static int SIZE_OF_BATTLESHIP = 5;
	const static int NUMBER_OF_BATTLESHIPS = 1;

	const static char CODE_FOR_CRUISER = 'C';
	const static int POINTS_PER_CRUISER_HIT = 2;
	const static int POINTS_PER_CRUISER_SUNK = 4; // Total 12 points for destroying this ship type
	const static int SIZE_OF_CRUISER = 4;
	const static int NUMBER_OF_CRUISERS = 2;

	const static char CODE_FOR_DESTROYER = 'D';
	const static int POINTS_PER_DESTROYER_HIT = 1;
	const static int POINTS_PER_DESTROYER_SUNK = 1; // Total 4 points for destroying this ship type
	const static int SIZE_OF_DESTROYER = 3;
	const static int NUMBER_OF_DESTROYERS = 3;

	const static int LARGEST_SHIP_SIZE = SIZE_OF_BATTLESHIP;
	const static int NUMBER_OF_SHIPS = NUMBER_OF_BATTLESHIPS + NUMBER_OF_CRUISERS + NUMBER_OF_DESTROYERS;

	const static int GAME_MAP_ROWS = 10;
	const static int GAME_MAP_COLS = 10;

	const static int ULTRA_MUNITIONS_AMOUNT = 2;

	// Game state constants
	const static int STARTUP_GAME_STATE = 0;
	const static int PLAYER_ONE_ACTIVE_STATE = 1;
	const static int PLAYER_TWO_ACTIVE_STATE = 2;
	const static int FINISHED_GAME_STATE = 3;
private:
	inline GameConstants() { ; }
	~GameConstants() { ; }

};

#endif // !_GAMECONSTANTS_
