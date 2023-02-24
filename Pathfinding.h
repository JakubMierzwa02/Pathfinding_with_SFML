#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include <vector>
#include <fstream>

class Pathfinding
{
private:
	// Window
	sf::RenderWindow* window;

	// Events
	sf::Event event;

	// Resources

	// Components
	static const int N = 32;	// Maze size
	const float gridSize = 32.f;

	sf::RectangleShape block;
	std::vector<sf::RectangleShape> blocks;

	int Maze[N][N];

	// File handling
	std::ifstream in;

	// Initializer functions
	void initVariables();
	void initWindow();
	void loadMaze();

public:

	// Constructors / Destructors
	Pathfinding();
	virtual ~Pathfinding();

	// Functions
	void pollEvents();

	void updateMaze();
	void update();

	void renderMaze();
	void render();

	void run();

};

