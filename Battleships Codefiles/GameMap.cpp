#include "GameMap.hpp"

using namespace std;

void GameMap::drawMap() {
	// Display a game title using the game map name
	cout << endl;
	cout << "   " << name;
	cout << endl;
	cout << "   ============";
	cout << endl;

	// Display the characetrs held in the current game map locations along with x and y coordinates
	// for the game map grid 
	cout << endl;
	cout << "     0 1 2 3 4 5 6 7 8 9";
	cout << endl;
	cout << "   +--------------------";
	cout << endl;

	for (int r = 0; r < rows; r++)
	{
		cout << "  " << r << "| ";

		for (int c = 0; c < columns; c++)
		{
			cout << locations.at((r * columns) + c) << " ";
		}

		cout << endl;
	}
	cout << endl << endl;
}
void GameMap::updateMap(int location, char newFigure) {
	locations.at(location) = newFigure;
}