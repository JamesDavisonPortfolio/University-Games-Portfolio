#pragma once
#include "Munition.hpp"

class UltraMunition : public Munition
{
public:
	void fireMunition(Player& player, GameMap& gameMap, std::vector<Ship*>& ships, const int coordinate,
		std::string& attackResult) override;
	inline UltraMunition() { ; }
	inline ~UltraMunition() { ; }
private:
	// Copy constructor
	UltraMunition(const UltraMunition& other) = delete;
	// Overloaded assignment operator
	UltraMunition& operator=(const UltraMunition& other) = delete;
};

