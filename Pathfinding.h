#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include <iostream>
#include <vector>
#include <fstream>

/*
	==========
	== READ ==
	==========

	After starting the program, a maze will appear. 
	Click on any part of the maze to reveal the path leading to the green exit point.

	==========
*/

class Pathfinding
{
private:
	// Window
	sf::RenderWindow* window;

	// Events
	sf::Event event;

	// Mouse positions
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	// Resources

	// Logic
	bool selecting;
	bool changes;

	// Pathfinding algorithm
	int row;
	int col;
	int currRow;
	int currCol;

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

	bool path(int, int, int);
	void mark(int, int);

	// Functions
	void pollEvents();

	void updateMousePositions();
	void updateSelecting();
	void updateMaze();
	void update();

	void renderMaze();
	void render();

	void run();
};