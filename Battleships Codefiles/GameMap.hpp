#pragma once
#ifndef _GAMEMAP_
#define _GAMEMAP_

#include<iostream>
#include <string>
#include <vector>

class GameMap
{
public:
	void drawMap();
	void updateMap(int location, char newFigure);
	inline GameMap() :
		rows(0),
		columns(0),
		name("")
	{ ; }
	inline GameMap(std::string name, int rows, int columns):
		rows(rows),
		columns(columns),
		name(name)
	{
		for (int i = 0; i < rows * columns; i++) {
			locations.push_back(126);
		}
		;
	}
	inline ~GameMap() { ; }
private:
	// Copy constructor
	GameMap(const GameMap& other) = delete;
	// Overloaded assignment operator
	GameMap& operator=(const GameMap& other) = delete;
	std::vector<char> locations;
	std::string name;
	int rows;
	int columns;
};


#endif // !_GAMEMAP_



