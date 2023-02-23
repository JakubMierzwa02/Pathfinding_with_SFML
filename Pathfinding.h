#pragma once

#include "SFML/Graphics.hpp"

class Pathfinding
{
private:
	// Window
	sf::RenderWindow* window;

	// Initializer functions
	void initWindow();

public:

	// Constructors / Destructors
	Pathfinding();
	virtual ~Pathfinding();

	// Functions
	void run();

};

