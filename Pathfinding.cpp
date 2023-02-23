#include "Pathfinding.h"

// Initializer functions
void Pathfinding::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1024, 1024), "Pathfinding");
	this->window->setFramerateLimit(60);
}

void Pathfinding::loadMaze()
{
	std::string s;
	this->in.open("map.txt");

	for (size_t i = 0; i < this->N; i++)
	{
		this->in >> s;
		for (size_t j = 0; j < this->N; j++)
		{
			if (s[j] == '#')
				this->Maze[i][j] = -1;
			else
				this->Maze[i][j] = 0;
		}
	}

	this->in.close();
}

Pathfinding::Pathfinding()
{
	this->initWindow();
	this->loadMaze();
}

Pathfinding::~Pathfinding()
{
	delete this->window;
}

void Pathfinding::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Pathfinding::update()
{
	this->pollEvents();
}

void Pathfinding::render()
{
	this->window->clear();

	// Render stuff

	this->window->display();
}

void Pathfinding::run()
{
	// Game loop
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
