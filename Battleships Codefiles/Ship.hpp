#pragma once
#ifndef _SHIP_
#define _SHIP_

#include "GameConstants.hpp"

#include <vector>
#include <string>

class Ship
{public:
	char code;
	std::string name;
	int size;
	int pointsPerHit;
	int pointsWhenSunk;
	int hitsTaken;
	std::vector<int> coordinates;
	inline Ship() {
		code = char("");
		name = "";
		size = 0;
		pointsPerHit = 0;
		pointsWhenSunk = 0;
	}
	inline Ship(char code, const std::string name, int size, int pointsPerHit, int pointsWhenSunk):
		code(code),
		name(name),
		size(size),
		pointsPerHit(pointsPerHit),
		pointsWhenSunk(pointsWhenSunk),
		hitsTaken(0)
	{
		;
	}
private:

};

#endif // !_SHIP_


