#include "Pathfinding.h"

// Initializer functions
void Pathfinding::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1024, 1024), "Pathfinding");
	this->window->setFramerateLimit(60);
}

Pathfinding::Pathfinding()
{
	this->initWindow();
}

Pathfinding::~Pathfinding()
{
	delete this->window;
}

void Pathfinding::run()
{

}
