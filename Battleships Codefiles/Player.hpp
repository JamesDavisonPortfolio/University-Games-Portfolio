#ifndef _PLAYER_
#define _PLAYER_

#include <string>

class Player
{
public:
	// Default constructor
	inline Player() :
		name(""),
		ultraMunitionsCount(0),
		score(0)
	{
		;
	}

	// Constructor
	inline Player(const std::string& name, const int ultraMunitionsCount) :
		name(name),
		ultraMunitionsCount(ultraMunitionsCount),
		score(0)
	{
		;
	}

	// Destructor
	inline ~Player() { ; }

	// Accessors (getters and setters
	inline std::string getName() const { return name; }
	inline int getScore() const { return score; }
	inline int getUltra() const { return ultraMunitionsCount; }
	inline void setScore(const int score) { this->score += score; }
	inline void deductUltraMunition() { ultraMunitionsCount--; }

	// Check for and use Ultra munitions, munitions are used by decrementing the
	// ultraMunitionsCount member variable
	inline bool hasUltraMunitions() const { return (ultraMunitionsCount > 0); }
	//inline void useUltraMunition() { if (hasUltraMunitions) { ultraMunitionsCount--; } }

protected:
private:
	// Copy constructor
	Player(const Player& other) = delete;
	// Overloaded assignment operator
	Player& operator=(const Player& other) = delete;

	std::string name;
	int ultraMunitionsCount;
	int score;
};

#endif // _PLAYER_
