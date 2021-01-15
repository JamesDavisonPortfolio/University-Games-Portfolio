#include "NormalMunition.hpp"

using namespace std;

void NormalMunition::fireMunition(Player& player, GameMap& gameMap, vector<Ship*>& ships, const int coordinate,
	std::string& attackResult)
{
	// Normal munition will attempt to hit any ship coordinate at the supplied attack coordinates

	// Initially assume the attack is a miss
	attackResult = "Miss!";

	// First convert the rcoord and ccoord into a single attack coordinate and then check if this attack
	// coordinate is within the coordinates array of any unsunk ships, if it is then process the attack
	// on that ship (by changing the ship's coordinates and hits taken), updating the points score of
	// the supplied player and then returning an appropriate attack result string
	for (vector<Ship*>::iterator iter = ships.begin(); iter!= ships.end(); iter++ ){

		Ship* pShip = (*iter);

		if (pShip->hitsTaken == pShip->size) {
			// This ship has been sunk (hits taken equal to size of ship) so ignore it and move on in the
			// ships array
			continue;
		}
		for (vector<int>::iterator i = pShip->coordinates.begin(); i != pShip->coordinates.end(); i++) {
			int shipCoord = (*i);
			bool isHit = false;
			if (shipCoord == coordinate) {

				pShip->hitsTaken++;
				*i = 255;

				gameMap.updateMap(coordinate, pShip->code);

				if (pShip->hitsTaken == pShip->size) {

					player.setScore(pShip->pointsPerHit);
					player.setScore(pShip->pointsWhenSunk);

					attackResult = "Hit a " + pShip->name + " and Sunk it!";
				}
				else {

					player.setScore(pShip->pointsPerHit);
					attackResult = "Hit a " + pShip->name + "!";
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