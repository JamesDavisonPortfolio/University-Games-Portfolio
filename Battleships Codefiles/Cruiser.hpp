#pragma once
#ifndef _CRUISER_
#define _CRUISER_


#include "Ship.hpp"

class Cruiser :
    public Ship
{
public:
    inline Cruiser(int coordinateA, int coordinateB, int coordinateC, int coordinateD) :
        Ship(GameConstants::CODE_FOR_CRUISER, "Cruiser", GameConstants::SIZE_OF_CRUISER,
            GameConstants::POINTS_PER_CRUISER_HIT, GameConstants::POINTS_PER_CRUISER_SUNK)
    {
        coordinates.push_back(coordinateA);
        coordinates.push_back(coordinateB);
        coordinates.push_back(coordinateC);
        coordinates.push_back(coordinateD);
        ;
    }
    ~Cruiser() { ; }
private:
    // Copy constructor
    Cruiser(const Cruiser& other) = delete;
    // Overloaded assignment operator
    Cruiser& operator=(const Cruiser& other) = delete;
};


#endif // !_CRUISER_
