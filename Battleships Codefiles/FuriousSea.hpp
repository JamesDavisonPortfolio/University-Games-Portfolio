#pragma once
#ifndef _FURIOUSSEA_
#define _FURIOUSSEA_

#include "Game.hpp"
#include "Battleship.hpp"
#include "Cruiser.hpp"
#include "Destroyer.hpp"
#include "GameConstants.hpp"
#include "NormalMunition.hpp"
#include "Player.hpp"
#include "Ship.hpp"
#include "UltraMunition.hpp"
#include "Game.hpp"

#include<vector>
#include<string>
#include<iostream>

class FuriousSea :
	public Game
{
public:
	inline FuriousSea() {
	}
	
	void initiliseOtherItems();
	void initiliseShips();
	void initialisePlayers();

	bool parseCommand(const std::string& command, std::string& munition, int& coordinate);
	bool allShipsSunk();
	void displayPlayerUI(const Player& player);
	bool playerTurn(Player& player);
	void endGameUI();


	void startUp() override;
	void update() override;
	void display() override;
	void shutdown() override;
	inline ~FuriousSea() { ; }
private:
	// Copy constructor
	FuriousSea(const FuriousSea& other) = delete;
	// Overloaded assignment operator
	FuriousSea& operator=(const FuriousSea& other) = delete;

	Player* pPlayerOne;
	Player* pPlayerTwo;
	std::vector<Ship*>* pShips;
	GameMap* gameMap;
	NormalMunition* nMunition;
	UltraMunition* uMunition;
	int gameState;
};


#endif // !_FURIOUSSEA_


