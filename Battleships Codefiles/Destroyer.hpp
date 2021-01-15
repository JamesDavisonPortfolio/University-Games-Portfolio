#pragma once
#ifndef _DESTROYER_
#define _DESTROYER_

#include "Ship.hpp"

class Destroyer :
    public Ship
{
public:
    inline Destroyer(int coordinateA, int coordinateB, int coordinateC) :
        Ship(GameConstants::CODE_FOR_DESTROYER, "Destroyer", GameConstants::SIZE_OF_DESTROYER,
            GameConstants::POINTS_PER_DESTROYER_HIT, GameConstants::POINTS_PER_DESTROYER_SUNK)
    {
        coordinates.push_back(coordinateA);
        coordinates.push_back(coordinateB);
        coordinates.push_back(coordinateC);
        ;
    }
    inline ~Destroyer() { ; }
private:
    // Copy constructor
    Destroyer(const Destroyer& other) = delete;
    // Overloaded assignment operator
    Destroyer& operator=(const Destroyer& other) = delete;
};

#endif // !_DESTROYER_





