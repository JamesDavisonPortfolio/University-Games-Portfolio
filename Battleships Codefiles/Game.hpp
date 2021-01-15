#ifndef _GAME_
#define _GAME_

#include <iostream>
#include "GameConstants.hpp"

// Abstract class that can be inherited from and the polymorphic member functions
// overridden to provide actual functionality for a concrete game class, use the
// run() member function of the concrete game class to get the main loop of the
// game executing
class Game
{
public:
    // Constructor
    inline Game() :
        finished(false)
    {
        ;
    }

    // Destructor
    inline virtual ~Game() { ; }

    // Accessors
    inline bool isFinished() const { return finished; } // Check if game is finished
    inline void finish() { finished = true; } // Finish the game
    inline void printFinishStatus() {
        if (finished == true) {
            std::cout << "its over" << std::endl;
        }
        else {
            std::cout << "Still on" << std::endl;
        }
    }
    virtual void startUp() = 0;
    virtual void update() = 0; // Override to update game each iteration of the main loop
    virtual void display() = 0; // Override to display the game each iteration of the main loop
    virtual void shutdown() = 0;  // Override to perform end game functions shutdown down
                                  // relevant game elements

    inline void run()
    {
        startUp();

        while (!finished)
        {
            update();
            display();
        }

        shutdown();
    }

protected:
private:
    bool finished;
};

#endif // _GAME_
