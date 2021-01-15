#include "UltraMunition.hpp"

using namespace std;

void UltraMunition::fireMunition(Player& player, GameMap& gameMap, vector<Ship*>& ships, const int coordinate,
	std::string& attackResult)
{


	//Takes the coordinate aimed at and converts this in a vector holding the 9 coordinates the ultra munition will strike;
	vector<int> ultraCoords;
	int bShipsHit = 0;
	int bShipsSunk = 0;
	int cShipsHit = 0; 
	int cShipsSunk = 0; 
	int dShipsHit = 0; 
	int dShipsSunk = 0;

	ultraCoords.push_back(coordinate);
	ultraCoords.push_back(coordinate + 10);
	ultraCoords.push_back(coordinate - 10);
	
	
	//if statements preventing leak from ultramunitions at edges targeting positions they shouldn't
	if (coordinate != 0 && coordinate != 10 && coordinate != 20 && coordinate != 30 && coordinate != 40 && 
		coordinate != 50 && coordinate != 60 && coordinate != 70 && coordinate != 80 && coordinate != 90) {

		ultraCoords.push_back(coordinate + 11);
		ultraCoords.push_back(coordinate - 1);
		ultraCoords.push_back(coordinate + 9);
	}

	if (coordinate != 9 && coordinate != 19 && coordinate != 29 && coordinate != 39 && coordinate != 49 && 
		coordinate != 59 && coordinate != 69 && coordinate != 79 && coordinate != 89 && coordinate != 99) {

		ultraCoords.push_back(coordinate - 11);
		ultraCoords.push_back(coordinate + 1);
		ultraCoords.push_back(coordinate - 9);

	}

	for (vector<int>::iterator iterCoord = ultraCoords.begin(); iterCoord != ultraCoords.end(); iterCoord++) {
		int UltraCoordinate = (*iterCoord);

		for (vector<Ship*>::iterator iter = ships.begin(); iter != ships.end(); iter++) {

			Ship* pShip = (*iter);

			if (pShip->hitsTaken == pShip->size) {
				// This ship has been sunk (hits taken equal to size of ship) so ignore it and move on in the
				// ships array
				continue;
			}
			for (vector<int>::iterator i = pShip->coordinates.begin(); i != pShip->coordinates.end(); i++) {
				int shipCoord = (*i);
				bool isHit = false;
				if (shipCoord == UltraCoordinate) {

					pShip->hitsTaken++;
					*i = 255;

					gameMap.updateMap(UltraCoordinate, pShip->code);

					if (pShip->hitsTaken == pShip->size) {

						player.setScore(pShip->pointsPerHit);
						player.setScore(pShip->pointsWhenSunk);
						if (pShip->code == GameConstants::CODE_FOR_BATTLESHIP) {
							bShipsHit++;
							bShipsSunk++;
						}
						else if (pShip->code == GameConstants::CODE_FOR_CRUISER) {
							cShipsHit++;
							cShipsSunk++;
						}
						else if (pShip->code == GameConstants::CODE_FOR_DESTROYER) {
							dShipsHit++;
							dShipsSunk++;
						}
					}
					else {

						player.setScore(pShip->pointsPerHit);
						if (pShip->code == GameConstants::CODE_FOR_BATTLESHIP) {
							bShipsHit++;
						}
						else if (pShip->code == GameConstants::CODE_FOR_CRUISER) {
							cShipsHit++;
						}
						else if (pShip->code == GameConstants::CODE_FOR_DESTROYER) {
							dShipsHit++;
						}

					}


					// A hit was made on this ship
					isHit = true;
				}
				if (isHit)
				{
					// A hit was made on this ship so no need to continue checking other ships
					break;
				}
			}
		}
	}


	


	if ((bShipsHit == 0) && (cShipsHit == 0) && (dShipsHit == 0))
	{
		attackResult = "All misses!";
	}
	else
	{
		// Need to convert the integer values to strings using std::to_string() function so they can be formed
		// into the attack result string using concatination + operator
		attackResult = "Battleships hit/sunk " + to_string(bShipsHit) + "/" + to_string(bShipsSunk) +
			"\n  Cruisers hit/sunk " + to_string(cShipsHit) + "/" + to_string(cShipsSunk) +
			"\n  Destroyers hit/sunk " + to_string(dShipsHit) + "/" + to_string(dShipsSunk);
	}
}