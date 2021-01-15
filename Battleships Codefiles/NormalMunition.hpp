#pragma once
#ifndef _NORMALMUNITION_
#define _NORMALMUNITION_

#include "Munition.hpp"

class NormalMunition : Munition
{
public:
	void fireMunition(Player& player, GameMap& gameMap, std::vector<Ship*>& ships, const int coordinate,
		std::string& attackResult) override;
	inline NormalMunition() { ; }
	inline ~NormalMunition() { ; }
private:
	// Copy constructor
	NormalMunition(const NormalMunition& other) = delete;
	// Overloaded assignment operator
	NormalMunition& operator=(const NormalMunition& other) = delete;
};


#endif // !_NORMALMUNITION_


