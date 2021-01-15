#pragma once
#ifndef _BATTLESHIP_
#define _BATTLESHIP_

#include "Ship.hpp"

class Battleship :
    public Ship
{
public:
    inline Battleship(int coordinateA, int coordinateB, int coordinateC, int coordinateD, int coordinateE) :
        Ship(GameConstants::CODE_FOR_BATTLESHIP, "Battleship", GameConstants::SIZE_OF_BATTLESHIP,
            GameConstants::POINTS_PER_BATTLESHIP_HIT, GameConstants::POINTS_PER_BATTLESHIP_SUNK)
    {
        coordinates.push_back(coordinateA);
        coordinates.push_back(coordinateB);
        coordinates.push_back(coordinateC);
        coordinates.push_back(coordinateD);
        coordinates.push_back(coordinateE);
        ;

    }
    inline ~Battleship() { ; }
private:
    // Copy constructor
    Battleship(const Battleship& other) = delete;
    // Overloaded assignment operator
    Battleship& operator=(const Battleship& other) = delete;
};

#endif // !_BATTLESHIP_






