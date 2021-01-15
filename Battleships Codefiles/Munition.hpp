#pragma once
#ifndef _MUNITION_
#define _MUNITION_

#include"Ship.hpp"
#include "Player.hpp"
#include "GameMap.hpp"
#include <string>
#include <vector>

class Munition
{
public:
	virtual void fireMunition(Player& player, GameMap& gameMap, std::vector<Ship*>& ships, const int coordinate,
		std::string& attackResult) = 0;
	inline Munition() { ; }
	inline virtual ~Munition() { ; }
private:
	

};

#endif // !_MUNITION_
