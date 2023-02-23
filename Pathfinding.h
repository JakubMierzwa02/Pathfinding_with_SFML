#pragma once

#include "SFML/Graphics.hpp"

class Pathfinding
{
private:
	// Window
	sf::RenderWindow* window;

	// Events
	sf::Event event;

	// Resources


	// Initializer functions
	void initWindow();

public:

	// Constructors / Destructors
	Pathfinding();
	virtual ~Pathfinding();

	// Functions
	void pollEvents();

	void update();
	void render();

	void run();

};

